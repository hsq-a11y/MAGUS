#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[2]
SHIM_DIR = REPO_ROOT / "tools" / "juliet_win_shim"
ORIGINAL_SOURCE_ROOT = REPO_ROOT / "srcs"
SANITIZED_SOURCE_ROOT = REPO_ROOT / "srcs_sanitized"
ORIGINAL_SRC_ROOT = ORIGINAL_SOURCE_ROOT / "juliet-api-misuse"
SANITIZED_SRC_ROOT = SANITIZED_SOURCE_ROOT / "juliet-api-misuse"
SANITIZATION_MAP = SANITIZED_SOURCE_ROOT / "juliet_sanitization_map.json"
STUBS = SHIM_DIR / "winapi_runtime_stubs.c"

ROUTE_EXECUTED_MARKER = "MAGUS_ROUTE_EXECUTED"
ROUTE_CONFIRMED_MARKER = "MAGUS_ROUTE_CONFIRMED"
NOT_ROUTE_BOUND_MARKER = "MAGUS_NOT_ROUTE_BOUND"
NOT_CONFIRMED_MARKER = "MAGUS_NOT_CONFIRMED"
ORACLE_UNSUPPORTED_MARKER = "MAGUS_ORACLE_UNSUPPORTED"
BUILD_FAILED_MARKER = "MAGUS_BUILD_FAILED"
RUNNER_ERROR_MARKER = "MAGUS_RUNNER_ERROR"
RPC_FORCED_FAILURE_MARKER = "MAGUS_JULIET_FLAW name=RpcImpersonateClient reason=forced_non_ok_return_for_privilege_drop_check"
RPC_NOT_PROPAGATED_MARKER = "MAGUS_ORACLE_FLAW name=RpcImpersonateClient reason=forced_non_ok_return_not_propagated value="
POSIX_FD_LIFECYCLE_PROFILE_ID = "resource.fd_lifecycle.user_posix"
STDIO_LIFECYCLE_PROFILE_ID = "resource.stream_lifecycle.c_stdio"
WIN32_HANDLE_LIFECYCLE_PROFILE_ID = "resource.handle_lifecycle.win32"
MEMORY_OOB_PROFILE_ID = "memory.out_of_bounds_write"
MEMORY_OOB_READ_PROFILE_ID = "memory.out_of_bounds_read"
MEMORY_UAF_PROFILE_ID = "memory.use_after_free"
INTEGER_OVERFLOW_PROFILE_ID = "integer.overflow"
LIFECYCLE_CAPABILITY_ENV = {
    POSIX_FD_LIFECYCLE_PROFILE_ID: "MAGUS_JULIET_REPORT_FD_LEAKS",
    STDIO_LIFECYCLE_PROFILE_ID: "MAGUS_JULIET_REPORT_STREAM_LEAKS",
    WIN32_HANDLE_LIFECYCLE_PROFILE_ID: "MAGUS_JULIET_REPORT_HANDLE_LEAKS",
}
SANITIZER_EVIDENCE_PATTERNS = (
    "AddressSanitizer",
    "UndefinedBehaviorSanitizer",
    "heap-buffer-overflow",
    "stack-buffer-overflow",
    "global-buffer-overflow",
    "dynamic-stack-buffer-overflow",
    "heap-use-after-free",
    "stack-use-after-return",
    "stack-use-after-scope",
    "runtime error: signed integer overflow",
    "runtime error: unsigned integer overflow",
)
SOURCE_SUFFIXES = (".c", ".cpp", ".cc", ".cxx")
SCENARIO_LABELS = {"bad": "case0", "good": "case1"}
COMPAT_HEADER = SHIM_DIR / "juliet_win_compat.h"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Build and run one Juliet Win32 testcase with Linux API shims")
    parser.add_argument("--source-file", required=True, help="C/C++ source file from the Stage C hypothesis")
    parser.add_argument("--entry-symbol", default="", help="Entry symbol from D target generation; kept for traceability")
    parser.add_argument("--route", default="", help="Full Stage C route; used to bind the dynamic run to bad/good scenario")
    parser.add_argument(
        "--payload",
        default=os.environ.get("MAGUS_D_RUNTIME_INPUT")
        or os.environ.get("MAGUS_D_PAYLOAD", "magus-juliet-controlled-input"),
        help="Payload returned by shimmed external sources",
    )
    parser.add_argument(
        "--oracle-profile-id",
        default=os.environ.get("MAGUS_D_ORACLE_PROFILE_ID", ""),
        help="D oracle profile selected for this hypothesis",
    )
    parser.add_argument(
        "--confirm-pattern",
        action="append",
        default=[],
        help="Route-bound semantic marker that can confirm this oracle profile",
    )
    parser.add_argument("--cc", default=os.environ.get("MAGUS_CC", "/usr/bin/clang-20"))
    parser.add_argument("--cxx", default=os.environ.get("MAGUS_CXX", "/usr/bin/clang++-20"))
    return parser.parse_args()


def env_confirm_patterns() -> list[str]:
    raw = os.environ.get("MAGUS_D_CONFIRM_PATTERNS_JSON", "").strip()
    if not raw:
        return []
    try:
        payload = json.loads(raw)
    except json.JSONDecodeError:
        return []
    if isinstance(payload, list):
        return [str(item) for item in payload if str(item)]
    return []


def payload_candidates(default_payload: str) -> list[str]:
    values: list[object] = []
    raw = os.environ.get("MAGUS_D_RUNTIME_INPUTS_JSON", "").strip()
    if raw:
        try:
            decoded = json.loads(raw)
        except json.JSONDecodeError:
            decoded = []
        if isinstance(decoded, list):
            values.extend(decoded)
        elif decoded not in (None, "", []):
            values.append(decoded)
    values.append(default_payload)

    result: list[str] = []
    seen: set[str] = set()
    for value in values:
        text = str(value)
        if not text or text in seen:
            continue
        seen.add(text)
        result.append(text)
    return result


def load_sanitization_map() -> dict[str, object]:
    if not SANITIZATION_MAP.exists():
        return {}
    try:
        payload = json.loads(SANITIZATION_MAP.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return {}
    return payload if isinstance(payload, dict) else {}


def path_under(path: Path, root: Path) -> bool:
    try:
        path.resolve().relative_to(root.resolve())
        return True
    except ValueError:
        return False


def is_sanitized_source(source: Path) -> bool:
    return path_under(source, SANITIZED_SOURCE_ROOT)


def support_dir_for(source: Path) -> Path:
    return (SANITIZED_SRC_ROOT if is_sanitized_source(source) else ORIGINAL_SRC_ROOT) / "testcasesupport"


def require_sanitization_map_for(source: Path) -> None:
    if is_sanitized_source(source) and not SANITIZATION_MAP.exists():
        raise SystemExit(f"{RUNNER_ERROR_MARKER} sanitized Juliet source requires mapping: {SANITIZATION_MAP}")


def desanitize_text(text: str) -> str:
    mapping = load_sanitization_map()
    reverse = mapping.get("reverse_token_map") if isinstance(mapping.get("reverse_token_map"), dict) else {}
    replacements = reverse or {
        "OMITCASE0": "OMITBAD",
        "OMITCASE1": "OMITGOOD",
        "CASE0": "BAD",
        "Case0": "Bad",
        "case0": "bad",
        "CASE1": "GOOD",
        "Case1": "Good",
        "case1": "good",
    }
    result = text
    for sanitized, original in sorted(replacements.items(), key=lambda item: len(str(item[0])), reverse=True):
        result = result.replace(str(sanitized), str(original))
    return result


def resolve_source(source_file: str) -> Path:
    raw = Path(source_file)
    candidates = []
    if raw.is_absolute():
        candidates.append(raw)
    else:
        candidates.extend(
            [
                REPO_ROOT / raw,
                SANITIZED_SOURCE_ROOT / raw,
                SANITIZED_SRC_ROOT / raw,
                ORIGINAL_SOURCE_ROOT / raw,
                ORIGINAL_SRC_ROOT / raw,
                REPO_ROOT / "srcs" / raw,
            ]
        )

    for candidate in candidates:
        if candidate.exists():
            return candidate.resolve()
    raise SystemExit(f"{RUNNER_ERROR_MARKER} source file not found: {source_file}")


def compiler_for(path: Path, args: argparse.Namespace) -> str:
    if path.suffix.lower() in {".cpp", ".cc", ".cxx"}:
        return args.cxx
    return args.cc


def testcase_stem(source: Path) -> str | None:
    suffix = source.suffix.lower()
    if suffix not in SOURCE_SUFFIXES:
        return None
    stem = source.stem
    match = re.match(
        r"(.+_\d+)(?:[a-z]|_(?:bad|goodG2B|goodB2G|goodG2B1|goodG2B2|goodB2G1|goodB2G2|"
        r"case0|case1G2B|case1B2G|case1G2B1|case1G2B2|case1B2G1|case1B2G2|"
        r"case1V1|case1V2|case1V11|case1V12|case1V21|case1V22))?$",
        stem,
    )
    if match:
        return match.group(1)
    return stem


def companion_sources(source: Path) -> list[Path]:
    stem = testcase_stem(source)
    if not stem:
        return [source]
    companions: list[Path] = []
    for suffix in SOURCE_SUFFIXES:
        companions.extend(source.parent.glob(f"{stem}*{suffix}"))
    companions = sorted(path for path in companions if path.suffix.lower() in SOURCE_SUFFIXES)
    return companions or [source]


def main_source(companions: list[Path], source: Path) -> Path:
    stem = testcase_stem(source)
    if stem:
        for suffix in SOURCE_SUFFIXES:
            for name in (f"{stem}a{suffix}", f"{stem}{suffix}"):
                candidate = source.parent / name
                if candidate in companions:
                    return candidate

    for candidate in companions:
        try:
            if "INCLUDEMAIN" in candidate.read_text(encoding="utf-8", errors="ignore"):
                return candidate
        except OSError:
            continue
    return source if source in companions else companions[0]


def scenario_for(args: argparse.Namespace, source: Path) -> str:
    text = desanitize_text(f"{args.route} {args.entry_symbol}").lower()
    if "good" in text:
        return "good"
    if "bad" in text:
        return "bad"
    text = desanitize_text(source.name).lower()
    if "good" in text:
        return "good"
    if "bad" in text:
        return "bad"
    return "bad"


def omit_macro_for(source: Path, scenario: str) -> str:
    if is_sanitized_source(source):
        return "-DOMITCASE0" if scenario == "good" else "-DOMITCASE1"
    return "-DOMITBAD" if scenario == "good" else "-DOMITGOOD"


def scenario_label(source: Path, scenario: str) -> str:
    if is_sanitized_source(source):
        return SCENARIO_LABELS[scenario]
    return scenario


def link_compiler(companions: list[Path], args: argparse.Namespace) -> str:
    if any(path.suffix.lower() in {".cpp", ".cc", ".cxx"} for path in companions):
        return args.cxx
    return args.cc


def run_checked(
    cmd: list[str],
    cwd: Path,
    env: dict[str, str] | None = None,
    stdin_text: str | None = None,
) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        cmd,
        cwd=str(cwd),
        env=env,
        input=stdin_text,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=False,
    )


def write_runtime_files(cwd: Path, payload: str) -> None:
    repeated = (payload + "\n") * 128
    binary_payload = (payload.encode("utf-8", errors="ignore") + b"\n") * 128
    for name in (
        r"C:\temp\file.txt",
        "BadSource_fopen.txt",
        "GoodSource_fopen.txt",
        "Case0Source_fopen.txt",
        "Case1Source_fopen.txt",
        "BadSink_fopen.txt",
        "GoodSink_fopen.txt",
        "Case0Sink_fopen.txt",
        "Case1Sink_fopen.txt",
        "file.txt",
        "log.txt",
    ):
        (cwd / name).write_text(repeated, encoding="utf-8")
    (cwd / "password.txt").write_text(("41 " * 256) + "\n", encoding="utf-8")
    (cwd / "encrypted.txt").write_bytes(binary_payload[:256].ljust(128, b"X"))


def configure_failure_environment(env: dict[str, str], source: Path, oracle_profile_id: str = "") -> None:
    source_text = str(source)
    source_name = source.name
    try:
        source_body = source.read_text(encoding="utf-8", errors="ignore")
    except OSError:
        source_body = ""
    source_hint = f"{source_text} {source_name} {source_body}"
    if "wchar_t" in source_name and ("connect_socket" in source_name or "listen_socket" in source_name):
        env["MAGUS_JULIET_SOCKET_WIDE"] = "1"
    if "CWE252_Unchecked_Return_Value" in source_text or "CWE253_Incorrect_Check_of_Function_Return_Value" in source_text:
        if "CreateMutex" in source_name:
            env["MAGUS_JULIET_FAIL_CREATE_MUTEX"] = "1"
        if "CreateNamedPipe" in source_name:
            env["MAGUS_JULIET_FAIL_CREATE_NAMED_PIPE"] = "1"
    if "ImpersonateNamedPipeClient" in source_hint:
        env["MAGUS_JULIET_FAIL_IMPERSONATE_NAMED_PIPE_CLIENT"] = "1"
    if "RpcImpersonateClient" in source_hint:
        env["MAGUS_JULIET_FAIL_RPC_IMPERSONATE_CLIENT"] = "1"
    if "CWE338_Weak_PRNG" in source_text:
        env["MAGUS_JULIET_MARK_RAND_FLAW"] = "1"
    if "CWE690_NULL_Deref_From_Return" in source_text and "w32_wfopen" in source_name:
        env["MAGUS_JULIET_FAIL_WFOPEN"] = "1"
    lifecycle_env = LIFECYCLE_CAPABILITY_ENV.get(oracle_profile_id)
    if lifecycle_env:
        env[lifecycle_env] = "1"


def sanitizer_flags_for(profile_id: str) -> list[str]:
    if profile_id in {MEMORY_OOB_PROFILE_ID, MEMORY_OOB_READ_PROFILE_ID, MEMORY_UAF_PROFILE_ID}:
        return ["-fsanitize=address", "-fno-omit-frame-pointer", "-g"]
    if profile_id == INTEGER_OVERFLOW_PROFILE_ID:
        return ["-fsanitize=undefined,signed-integer-overflow", "-fno-omit-frame-pointer", "-g"]
    return []


def has_sanitizer_evidence(output: str) -> bool:
    return any(pattern in output for pattern in SANITIZER_EVIDENCE_PATTERNS)


def compile_unit(command: list[str], tmp_path: Path) -> bool:
    build = run_checked(command, REPO_ROOT)
    if build.returncode == 0:
        return True
    print(BUILD_FAILED_MARKER)
    print("command=" + " ".join(command))
    print(build.stdout, end="")
    print(build.stderr, end="", file=sys.stderr)
    return False


def compile_case(args: argparse.Namespace, source: Path, tmp_path: Path) -> tuple[Path | None, Path | None]:
    companions = companion_sources(source)
    entry_unit = main_source(companions, source)
    scenario = scenario_for(args, source)
    omit_macro = omit_macro_for(source, scenario)
    support_dir = support_dir_for(source)
    support_io = support_dir / "io.c"
    support_thread = support_dir / "std_thread.c"
    sanitizer_flags = sanitizer_flags_for(args.oracle_profile_id)

    objects: list[Path] = []
    for index, unit in enumerate(companions):
        unit_compiler = compiler_for(unit, args)
        obj = tmp_path / f"case_{index}.o"
        command = [
            unit_compiler,
            "-c",
            *sanitizer_flags,
            "-D_WIN32",
            "-DINCLUDEMAIN" if unit == entry_unit else "-DMAGUS_COMPANION_UNIT",
            omit_macro,
            "-I",
            str(SHIM_DIR),
            "-I",
            str(support_dir),
            "-include",
            str(COMPAT_HEADER),
            str(unit),
            "-o",
            str(obj),
        ]
        if not compile_unit(command, tmp_path):
            return None, entry_unit
        objects.append(obj)

    support_units = [
        (tmp_path / "io.o", support_io, args.cc, ["-DglobalReturnsTrueOrFalse=magus_unused_globalReturnsTrueOrFalse"]),
        (tmp_path / "std_thread.o", support_thread, args.cc, []),
        (tmp_path / "winapi_runtime_stubs.o", STUBS, args.cc, ["-DMAGUS_WINAPI_RUNTIME_STUBS"]),
    ]
    for obj, unit, compiler, extra_macros in support_units:
        command = [
            compiler,
            "-c",
            *sanitizer_flags,
            "-D_WIN32",
            *extra_macros,
            "-I",
            str(SHIM_DIR),
            "-I",
            str(support_dir),
            str(unit),
            "-o",
            str(obj),
        ]
        if not compile_unit(command, tmp_path):
            return None, entry_unit
        objects.append(obj)

    binary = tmp_path / "case_under_test"
    command = [link_compiler(companions, args), *sanitizer_flags, *[str(obj) for obj in objects], "-o", str(binary)]
    if not compile_unit(command, tmp_path):
        return None, entry_unit
    return binary, entry_unit


def route_was_executed(stdout: str, source: Path, scenario: str, oracle_output: str = "") -> bool:
    label = scenario_label(source, scenario)
    other_label = scenario_label(source, "good" if scenario == "bad" else "bad")
    expected_call = f"Calling {label}()..."
    expected_finish = f"Finished {label}()"
    unexpected_call = f"Calling {other_label}()..."
    if expected_call in stdout and expected_finish in stdout and unexpected_call not in stdout:
        return True
    return expected_call in stdout and unexpected_call not in stdout and has_sanitizer_evidence(oracle_output)


def oracle_confirmed(stdout: str, confirm_patterns: list[str]) -> tuple[bool, list[str]]:
    matched = [pattern for pattern in confirm_patterns if pattern and pattern in stdout]
    return bool(matched), matched


def generic_oracle_output(stdout: str) -> str:
    return stdout.replace("MAGUS_JULIET_SINK", "MAGUS_ORACLE_SINK").replace(
        "MAGUS_JULIET_FLAW",
        "MAGUS_ORACLE_FLAW",
    )


def route_bound_semantic_markers(stdout: str, route_executed: bool) -> list[str]:
    if route_executed and RPC_FORCED_FAILURE_MARKER in stdout:
        return [RPC_NOT_PROPAGATED_MARKER]
    return []


def oracle_capability_markers(profile_id: str, env: dict[str, str]) -> list[str]:
    env_name = LIFECYCLE_CAPABILITY_ENV.get(profile_id)
    if env_name and env.get(env_name):
        return [f"MAGUS_ORACLE_RAN profile={profile_id}"]
    return []


def unsupported_oracle_reason(confirm_patterns: list[str], profile_id: str) -> str:
    if confirm_patterns:
        return ""
    if profile_id:
        return f"profile_has_no_confirm_patterns:{profile_id}"
    return "no_oracle_profile"


def main() -> int:
    args = parse_args()
    if not args.confirm_pattern:
        args.confirm_pattern = env_confirm_patterns()
    source = resolve_source(args.source_file)
    require_sanitization_map_for(source)
    scenario = scenario_for(args, source)

    for compiler in {args.cc, args.cxx}:
        if not Path(compiler).exists():
            print(f"{RUNNER_ERROR_MARKER} compiler not found: {compiler}")
            return 2

    with tempfile.TemporaryDirectory(prefix="magus-juliet-win-") as tmp:
        tmp_path = Path(tmp)
        binary, entry_unit = compile_case(args, source, tmp_path)
        if binary is None:
            return 2

        attempts = payload_candidates(args.payload)
        any_route_executed = False
        last_route_markers: list[str] = []
        for attempt_index, payload in enumerate(attempts, 1):
            print(
                f"MAGUS_PAYLOAD_ATTEMPT index={attempt_index} total={len(attempts)} "
                f"value={json.dumps(payload, ensure_ascii=False)}"
            )
            write_runtime_files(tmp_path, payload)
            env = os.environ.copy()
            env["MAGUS_JULIET_PAYLOAD"] = payload
            env["MAGUS_JULIET_PAYLOAD_INDEX"] = str(attempt_index)
            env["MAGUS_JULIET_PAYLOAD_COUNT"] = str(len(attempts))
            env["ADD"] = payload
            env.setdefault("WINDIR", r"C:\Windows")
            configure_failure_environment(env, source, args.oracle_profile_id)

            run = run_checked([str(binary)], tmp_path, env=env, stdin_text=payload + "\n")
            raw_stdout = run.stdout or ""
            raw_stderr = run.stderr or ""
            generic_stdout = generic_oracle_output(raw_stdout)
            oracle_output = generic_stdout + "\n" + raw_stderr
            print(generic_stdout, end="")
            print(raw_stderr, end="", file=sys.stderr)

            route_executed = route_was_executed(raw_stdout, source, scenario, oracle_output)
            if route_executed:
                any_route_executed = True
            semantic_markers = route_bound_semantic_markers(raw_stdout, route_executed)
            capability_markers = oracle_capability_markers(args.oracle_profile_id, env) if route_executed else []
            for marker in semantic_markers:
                print(marker)
            for marker in capability_markers:
                print(marker)
            route_bound_markers = [*semantic_markers, *capability_markers]
            if route_bound_markers:
                last_route_markers = route_bound_markers
            oracle_stdout = oracle_output + ("\n" + "\n".join(route_bound_markers) if route_bound_markers else "")
            confirmed, matched_patterns = oracle_confirmed(oracle_stdout, args.confirm_pattern)

            if route_executed and confirmed:
                print(
                    f"{ROUTE_EXECUTED_MARKER} scenario={scenario} "
                    f"entry_symbol={args.entry_symbol or '<unknown>'} source_file={source} "
                    f"payload_attempt={attempt_index}"
                )
                print(
                    f"{ROUTE_CONFIRMED_MARKER} scenario={scenario} "
                    f"oracle_profile_id={args.oracle_profile_id or '<unknown>'} "
                    f"matched_patterns={json.dumps(matched_patterns, ensure_ascii=False)} "
                    f"entry_symbol={args.entry_symbol or '<unknown>'} source_file={source} "
                    f"payload_attempt={attempt_index}"
                )
                return 0

        if any_route_executed:
            print(
                f"{ROUTE_EXECUTED_MARKER} scenario={scenario} "
                f"entry_symbol={args.entry_symbol or '<unknown>'} source_file={source} "
                f"payload_attempts={len(attempts)}"
            )
            reason = unsupported_oracle_reason(args.confirm_pattern, args.oracle_profile_id)
            if reason:
                print(
                    f"{ORACLE_UNSUPPORTED_MARKER} reason={reason} scenario={scenario} "
                    f"oracle_profile_id={args.oracle_profile_id or '<unknown>'} "
                    f"entry_symbol={args.entry_symbol or '<unknown>'} source_file={source}"
                )
                return 3
        else:
            print(
                f"{NOT_ROUTE_BOUND_MARKER} expected_scenario={scenario} "
                f"entry_symbol={args.entry_symbol or '<unknown>'} source_file={source} main_source={entry_unit}"
            )

        for marker in last_route_markers:
            print(marker)
        print(NOT_CONFIRMED_MARKER)
        print(f"entry_symbol={args.entry_symbol}")
        print(f"route={args.route}")
        print(f"source_file={source}")
        print(f"main_source={entry_unit}")
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
