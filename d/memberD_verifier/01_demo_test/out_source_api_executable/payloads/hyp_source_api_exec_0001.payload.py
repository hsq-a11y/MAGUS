#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

DEFAULT_FAILURE_PATTERNS = [
    "AddressSanitizer",
    "UndefinedBehaviorSanitizer",
    "runtime error:",
    "Segmentation fault",
    "null pointer",
    "heap-use-after-free",
    "stack-buffer-overflow",
    "heap-buffer-overflow",
    "use-after-free",
    "double-free",
]


def utc_now() -> str:
    return datetime.now(timezone.utc).replace(microsecond=0).isoformat().replace("+00:00", "Z")


def as_list(value: Any) -> list[Any]:
    if value in (None, "", []):
        return []
    if isinstance(value, list):
        return value
    return [value]


def pattern_list(value: Any) -> list[str]:
    if value in (None, "", []):
        return []
    if isinstance(value, list):
        return [str(item) for item in value if str(item)]
    return [str(value)]


def failure_code_patterns(oracle: dict[str, Any]) -> dict[str, list[str]]:
    raw = oracle.get("failure_code_patterns") or {}
    if not isinstance(raw, dict):
        return {}
    return {str(code): pattern_list(patterns) for code, patterns in raw.items()}


def parse_timeout(value: Any) -> float | None:
    if value in (None, "", []):
        return None
    return float(value)


def execution_env(plan: dict[str, Any]) -> dict[str, str]:
    env = os.environ.copy()
    evidence = plan.get("evidence") if isinstance(plan.get("evidence"), dict) else {}
    payload = plan.get("payload") if isinstance(plan.get("payload"), dict) else {}
    values = {
        "MAGUS_D_PROJECT_ID": plan.get("project_id"),
        "MAGUS_D_SAMPLE_ID": plan.get("sample_id"),
        "MAGUS_D_HYPOTHESIS_ID": plan.get("hypothesis_id"),
        "MAGUS_D_ROUTE": evidence.get("route"),
        "MAGUS_D_FILE": evidence.get("file") or plan.get("source_file"),
        "MAGUS_D_LINE": evidence.get("line"),
        "MAGUS_D_ENTRY_SYMBOL": plan.get("entry_symbol"),
        "MAGUS_D_ORACLE_PROFILE_ID": plan.get("oracle_profile_id"),
        "MAGUS_D_PAYLOAD": payload.get("marker"),
        "MAGUS_D_PAYLOAD_MARKER": payload.get("marker"),
    }
    for key, value in values.items():
        if value not in (None, "", []):
            env[key] = str(value)
    confirm_patterns = (plan.get("oracle") or {}).get("semantic_failure_patterns") or []
    if confirm_patterns:
        env["MAGUS_D_CONFIRM_PATTERNS_JSON"] = json.dumps(confirm_patterns, ensure_ascii=False)
    return env


def run_command(cmd: Any, cwd: Path, timeout: float | None, env: dict[str, str]) -> dict[str, Any]:
    started = time.perf_counter()
    if isinstance(cmd, str):
        cmd = cmd.replace("${PYTHON}", sys.executable)
    elif isinstance(cmd, list):
        cmd = [str(part).replace("${PYTHON}", sys.executable) for part in cmd]
    shell = isinstance(cmd, str)
    try:
        proc = subprocess.run(
            cmd,
            cwd=str(cwd),
            shell=shell,
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            timeout=timeout,
            env=env,
        )
        return {
            "cmd": cmd,
            "cwd": str(cwd),
            "exit_code": proc.returncode,
            "elapsed_ms": int((time.perf_counter() - started) * 1000),
            "stdout_tail": (proc.stdout or "")[-12000:],
            "stderr_tail": (proc.stderr or "")[-12000:],
            "timed_out": False,
        }
    except subprocess.TimeoutExpired as exc:
        return {
            "cmd": cmd,
            "cwd": str(cwd),
            "exit_code": None,
            "elapsed_ms": int((time.perf_counter() - started) * 1000),
            "stdout_tail": (exc.stdout or "")[-12000:] if isinstance(exc.stdout, str) else "",
            "stderr_tail": (exc.stderr or "")[-12000:] if isinstance(exc.stderr, str) else "",
            "timed_out": True,
        }


def decide(run_results: list[dict[str, Any]], oracle: dict[str, Any]) -> tuple[str, str, list[str]]:
    patterns = oracle.get("failure_patterns") or DEFAULT_FAILURE_PATTERNS
    required_patterns = pattern_list(oracle.get("required_patterns"))
    capability_patterns = pattern_list(oracle.get("capability_patterns"))
    unsupported_patterns = pattern_list(oracle.get("unsupported_patterns"))
    code_patterns = failure_code_patterns(oracle)
    expect_nonzero = bool(oracle.get("expect_nonzero_exit", True))
    observations: list[str] = []
    for result in run_results:
        output = f"{result.get('stdout_tail') or ''}\n{result.get('stderr_tail') or ''}"
        if result.get("timed_out"):
            observations.append(f"timeout while running {result.get('cmd')}")
            return "failed", "TIMEOUT", observations
        matched = [str(pattern) for pattern in patterns if str(pattern) and str(pattern) in output]
        missing_required = [pattern for pattern in required_patterns if pattern not in output]
        matched_unsupported = [pattern for pattern in unsupported_patterns if pattern and pattern in output]
        if matched_unsupported:
            if missing_required:
                observations.append(f"unsupported oracle marker observed without route-bound patterns: {', '.join(missing_required)}")
                return "failed", "NOT_ROUTE_BOUND", observations
            observations.append(f"unsupported oracle matched patterns: {', '.join(matched_unsupported)}")
            return "unsupported", "UNSUPPORTED_ORACLE", observations
        for code, code_pattern_values in code_patterns.items():
            matched_code_patterns = [pattern for pattern in code_pattern_values if pattern in output]
            if matched_code_patterns:
                if missing_required:
                    observations.append(f"{code} matched without route-bound patterns: {', '.join(missing_required)}")
                    return "failed", "NOT_ROUTE_BOUND", observations
                missing_capability = [pattern for pattern in capability_patterns if pattern not in output]
                if missing_capability:
                    observations.append(f"oracle capability patterns missing: {', '.join(missing_capability)}")
                    return "unsupported", "UNSUPPORTED_ORACLE", observations
                observations.append(f"{code} matched patterns: {', '.join(matched_code_patterns)}")
                return "failed", code, observations
        if matched:
            if missing_required:
                observations.append(f"oracle matched but route-bound patterns were missing: {', '.join(missing_required)}")
                return "failed", "NOT_ROUTE_BOUND", observations
            missing_capability = [pattern for pattern in capability_patterns if pattern not in output]
            if missing_capability:
                observations.append(f"oracle capability patterns missing: {', '.join(missing_capability)}")
                return "unsupported", "UNSUPPORTED_ORACLE", observations
            observations.append(f"oracle matched patterns: {', '.join(matched)}")
            return "confirmed", "ORACLE_MATCH", observations
        if expect_nonzero and result.get("exit_code") not in (0, None):
            if missing_required:
                observations.append(f"non-zero exit observed without route-bound patterns: {', '.join(missing_required)}")
                return "failed", "NOT_ROUTE_BOUND", observations
            missing_capability = [pattern for pattern in capability_patterns if pattern not in output]
            if missing_capability:
                observations.append(f"oracle capability patterns missing: {', '.join(missing_capability)}")
                return "unsupported", "UNSUPPORTED_ORACLE", observations
            observations.append(f"non-zero exit observed: {result.get('exit_code')}")
            return "confirmed", "NONZERO_EXIT", observations
        if missing_required:
            observations.append(f"route-bound patterns missing: {', '.join(missing_required)}")
            return "failed", "NOT_ROUTE_BOUND", observations
        missing_capability = [pattern for pattern in capability_patterns if pattern not in output]
        if missing_capability:
            observations.append(f"oracle capability patterns missing: {', '.join(missing_capability)}")
            return "unsupported", "UNSUPPORTED_ORACLE", observations
        observations.append(f"exit={result.get('exit_code')} for {result.get('cmd')}")
    return "failed", "NOT_EXPLOITABLE", observations


def main() -> int:
    parser = argparse.ArgumentParser(description="Executable source/API misuse payload runner")
    parser.add_argument("--plan", default="hyp_source_api_exec_0001.api-plan.json")
    parser.add_argument("--result", default="")
    args = parser.parse_args()

    plan_path = Path(args.plan)
    if not plan_path.is_absolute():
        plan_path = Path(__file__).resolve().parent / plan_path
    result_path = Path(args.result) if args.result else Path(__file__).with_suffix(".payload-result.json")

    plan = json.loads(plan_path.read_text(encoding="utf-8"))
    build = plan.get("build") or {}
    oracle = plan.get("oracle") or {}
    timeout = parse_timeout(build.get("timeout_sec"))
    repo_path = build.get("repo_path")

    if not repo_path:
        result = {
            "status": "failed",
            "failure_code": "ENV_MISSING",
            "failure_note": "repo_path is missing; cannot execute source/API payload",
            "observations": ["payload runner was generated but no source repository was configured"],
            "runtime_trace": [],
            "timestamps": {"finished_at": utc_now()},
        }
        result_path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        return 2

    cwd = Path(str(repo_path)).expanduser().resolve()
    if not cwd.exists():
        result = {
            "status": "failed",
            "failure_code": "ENV_MISSING",
            "failure_note": f"repo_path does not exist: {cwd}",
            "observations": ["payload runner could not find the configured source repository"],
            "runtime_trace": [],
            "timestamps": {"finished_at": utc_now()},
        }
        result_path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        return 2

    setup_cmds = as_list(build.get("config_cmd")) + as_list(build.get("build_cmd"))
    run_cmds = as_list(build.get("run_cmd")) or as_list(build.get("poc_cmd")) or as_list(build.get("test_cmd"))
    if not run_cmds:
        result = {
            "status": "failed",
            "failure_code": "ENV_MISSING",
            "failure_note": "run_cmd/poc_cmd/test_cmd is missing; cannot execute source/API payload",
            "observations": ["payload runner needs a concrete command that reaches the suspected API sequence"],
            "runtime_trace": [],
            "timestamps": {"finished_at": utc_now()},
        }
        result_path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
        return 2

    command_env = execution_env(plan)
    setup_results = [run_command(cmd, cwd, timeout, command_env) for cmd in setup_cmds]
    for item in setup_results:
        if item.get("timed_out") or item.get("exit_code") not in (0, None):
            result = {
                "status": "failed",
                "failure_code": "ENV_MISSING",
                "failure_note": "setup/build command failed before payload execution",
                "observations": [f"setup failed: {item.get('cmd')} exit={item.get('exit_code')}"],
                "runtime_trace": setup_results,
                "timestamps": {"finished_at": utc_now()},
            }
            result_path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
            return 2

    run_results = [run_command(cmd, cwd, timeout, command_env) for cmd in run_cmds]
    status, reason, observations = decide(run_results, oracle)
    result = {
        "status": status,
        "reason": reason,
        "failure_code": reason if status in {"failed", "unsupported"} else None,
        "failure_note": (
            "payload did not satisfy oracle"
            if status == "failed"
            else "Stage D oracle does not support this hypothesis; preserving Stage C verdict"
            if status == "unsupported"
            else None
        ),
        "observations": observations,
        "runtime_trace": setup_results + run_results,
        "timestamps": {"finished_at": utc_now()},
    }
    result_path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    return 0 if status in {"confirmed", "unsupported"} else 1


if __name__ == "__main__":
    raise SystemExit(main())

