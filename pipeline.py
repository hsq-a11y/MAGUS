#!/usr/bin/env python3

import argparse
import json
import os
import re
import shlex
import subprocess
import sys
import tempfile
import time
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent
STAGE_A_DIR = REPO_ROOT / "a"
STAGE_B_DIR = REPO_ROOT / "b"
STAGE_C_DIR = REPO_ROOT / "c"
STAGE_D_DIR = REPO_ROOT / "d/memberD_verifier"
STAGE_D_RUN_DIR = REPO_ROOT / "d/memberD_verifier/02_run_with_C"
STAGE_D_PYTHON = STAGE_D_DIR / ".venv/bin/python"
REPORT_DIR = REPO_ROOT / "report"
REPORT_GENERATOR = REPORT_DIR / "code/generate_report.py"
REPORT_VALIDATOR = REPORT_DIR / "code/validate_report.py"
DEFAULT_STAGE_D_OUTPUT_DIR = STAGE_D_RUN_DIR / "output"
DEFAULT_STAGE_A_INPUT = STAGE_A_DIR / "input/srcs.in.jsonl"
DEFAULT_STAGE_A_OUTPUT = STAGE_A_DIR / "out/samples.raw.jsonl"
DEFAULT_STAGE_A_GENERATED_INPUT = STAGE_A_DIR / "input/srcs.in.jsonl"
DEFAULT_SOURCE_ROOT = REPO_ROOT / "srcs_sanitized"
DEFAULT_STAGE_B_OUTPUT_DIR = STAGE_B_DIR / "b_output"
DEFAULT_STAGE_C_OUTPUT = STAGE_C_DIR / "out/hypotheses.jsonl"
DEFAULT_STAGE_C_WORKERS = 20
REPORT_RUN_NAME_PATTERN = re.compile(r"[^A-Za-z0-9._-]+")


def resolve_path(raw: str) -> Path:
    return Path(raw).expanduser().resolve()


def positive_int(raw: str) -> int:
    try:
        value = int(raw)
    except ValueError as exc:
        raise argparse.ArgumentTypeError("must be an integer") from exc
    if value <= 0:
        raise argparse.ArgumentTypeError("must be greater than 0")
    return value


def normalize_report_run_name(raw: str) -> str:
    name = raw.strip()
    if not name:
        raise ValueError("report run name is empty")
    if "/" in name or "\\" in name:
        raise ValueError(f"report run name must be a folder name, not a path: {raw}")
    normalized = REPORT_RUN_NAME_PATTERN.sub("_", name).strip("._-")
    if not normalized:
        raise ValueError(f"report run name has no filesystem-safe characters: {raw}")
    if normalized in {".", ".."}:
        raise ValueError(f"report run name is not allowed: {raw}")
    return normalized


def derived_stats_path(raw_output_path: Path) -> Path:
    return raw_output_path.with_suffix("").with_suffix(".stats.jsonl")


def derived_llm_path(raw_output_path: Path) -> Path:
    return raw_output_path.with_suffix("").with_suffix(".llm.jsonl")


def b_c_ready_path(output_dir: Path) -> Path:
    return output_dir / "candidates.for_c.jsonl"


def read_jsonl_objects(path: Path) -> list[dict]:
    if not path.exists():
        raise ValueError(f"required input is missing: {path}")
    rows: list[dict] = []
    with path.open("r", encoding="utf-8-sig") as handle:
        for line_number, line in enumerate(handle, 1):
            line = line.strip()
            if not line:
                continue
            try:
                row = json.loads(line)
            except json.JSONDecodeError as exc:
                raise ValueError(f"{path}:{line_number}: invalid json: {exc}") from exc
            if not isinstance(row, dict):
                raise ValueError(f"{path}:{line_number}: expected a JSON object")
            rows.append(row)
    return rows


def report_run_name_from_rows(rows: list[dict], context: str) -> str:
    project_ids: set[str] = set()
    for row in rows:
        project_id = str(row.get("project_id") or "").strip()
        if project_id:
            project_ids.add(normalize_report_run_name(project_id))

    if len(project_ids) == 1:
        return next(iter(project_ids))
    if len(project_ids) > 1:
        joined = ", ".join(sorted(project_ids))
        raise ValueError(f"cannot derive one report run name from multiple project_id values in {context}: {joined}")
    raise ValueError(f"cannot derive report run name from {context}; pass --run-name or --report-run-name")


def report_run_name_from_stage_a_input(input_path: Path) -> str:
    rows = read_jsonl_objects(input_path)
    if not rows:
        raise ValueError(f"Stage A input has no project records: {input_path}")
    return report_run_name_from_rows(rows, str(input_path))


def report_run_name_from_stage_d_output(d_output_dir: Path, allow_empty: bool = False) -> str:
    rows: list[dict] = []
    rows.extend(read_jsonl_objects(d_output_dir / "verification.jsonl"))
    rows.extend(read_jsonl_objects(d_output_dir / "verification.failed.jsonl"))
    if not rows:
        if allow_empty:
            return ""
        raise ValueError(f"Stage D output has no verification records: {d_output_dir}")
    return report_run_name_from_rows(rows, str(d_output_dir))


def report_output_dir(report_root: Path, run_name: str) -> Path:
    return report_root / normalize_report_run_name(run_name)


def stage_d_output_dir_for_run(run_name: str) -> Path:
    return DEFAULT_STAGE_D_OUTPUT_DIR / normalize_report_run_name(run_name)


def run_command(command: list[str], cwd: Path) -> None:
    print(f"[pipeline] cwd={cwd}", flush=True)
    print(f"[pipeline] cmd={shlex.join(command)}", flush=True)
    completed = subprocess.run(command, cwd=cwd)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def build_analyzer() -> None:
    run_command(["make", "build-analyzer"], STAGE_A_DIR)


def run_stage_a_gen_input(
    repo_path: Path,
    compile_commands: Path | None,
    output_path: Path,
    project_id: str,
    language: str,
    framework: str,
    analyzer_jobs: int,
    analysis_timeout: int,
    clang: str,
    clangxx: str,
    bc_dir: str,
    source_globs: list[str],
    force: bool,
) -> None:
    command = [
        sys.executable,
        "cmd/gen_input.py",
        "--repo-path",
        str(repo_path),
        "--output",
        str(output_path),
        "--project-id",
        project_id,
        "--language",
        language,
        "--framework",
        framework,
        "--analyzer-jobs",
        str(analyzer_jobs),
        "--analysis-timeout",
        str(analysis_timeout),
        "--clang",
        clang,
        "--clangxx",
        clangxx,
        "--bc-dir",
        bc_dir,
    ]
    if compile_commands is not None:
        command.extend(["--compile-commands", str(compile_commands)])
    for source_glob in source_globs:
        command.extend(["--source-glob", source_glob])
    if force:
        command.append("--force")
    run_command(command, STAGE_A_DIR)


def run_stage_a(input_path: Path, output_path: Path) -> None:
    run_command(
        [
            sys.executable,
            "cmd/miner.py",
            "--input",
            str(input_path),
            "--output",
            str(output_path),
        ],
        STAGE_A_DIR,
    )
    llm_output = derived_llm_path(output_path)
    print(f"[pipeline] derived Stage A LLM output={llm_output}", flush=True)
    run_stage_a_llm(output_path, input_path, llm_output)


def run_stage_a_llm(raw_input_path: Path, projects_path: Path, output_path: Path) -> None:
    run_command(
        [
            sys.executable,
            "cmd/llm_export.py",
            "--input",
            str(raw_input_path),
            "--projects",
            str(projects_path),
            "--output",
            str(output_path),
        ],
        STAGE_A_DIR,
    )


def run_stage_b(input_path: Path, llm_input_path: Path, output_dir: Path, min_support: int) -> None:
    command = [
        sys.executable,
        "b_miner.py",
        "--input",
        str(input_path),
        "--llm-input",
        str(llm_input_path),
        "--output-dir",
        str(output_dir),
        "--min-support",
        str(min_support),
    ]
    run_command(
        command,
        STAGE_B_DIR,
    )


def stage_c_command(
    candidates_path: Path,
    output_path: Path,
    time_limit_seconds: float | None,
    workers: int,
) -> list[str]:
    command = [
        sys.executable,
        "agent1.py",
        "--candidates",
        str(candidates_path),
        "--output",
        str(output_path),
        "--workers",
        str(workers),
    ]
    if time_limit_seconds is not None:
        command.extend(["--time-limit-seconds", str(time_limit_seconds)])
    return command


def run_stage_c(candidates_path: Path, output_path: Path, time_limit_seconds: float | None, workers: int) -> None:
    run_command(stage_c_command(candidates_path, output_path, time_limit_seconds, workers), STAGE_C_DIR)


def run_stage_d(contexts_path: Path | None = None) -> None:
    command = ["./01_auto_attack_from_C_linux.sh"]
    if contexts_path is not None:
        command.append(str(contexts_path))
    run_command(command, STAGE_D_RUN_DIR)


def run_report(d_output_dir: Path, output_dir: Path) -> None:
    confirmed = d_output_dir / "verification.jsonl"
    failed = d_output_dir / "verification.failed.jsonl"
    run_command(
        [
            sys.executable,
            str(REPORT_GENERATOR),
            "--confirmed",
            str(confirmed),
            "--failed",
            str(failed),
            "--out-dir",
            str(output_dir),
        ],
        REPO_ROOT,
    )
    run_command(
        [
            sys.executable,
            str(REPORT_VALIDATOR),
            "--confirmed",
            str(confirmed),
            "--report-dir",
            str(output_dir),
        ],
        REPO_ROOT,
    )


def run_named_report(d_output_dir: Path, report_root: Path, run_name: str) -> None:
    output_dir = report_output_dir(report_root, run_name)
    print(f"[pipeline] final report output={output_dir}", flush=True)
    run_report(d_output_dir, output_dir)


def ensure_stage_d_python() -> None:
    if not STAGE_D_PYTHON.exists() or not os.access(STAGE_D_PYTHON, os.X_OK):
        raise SystemExit(
            f"error: Cannot find Stage D Python env: {STAGE_D_PYTHON}\n"
            "Run d/memberD_verifier/01_demo_test/01_setup_linux.sh first."
        )


def terminate_process(process: subprocess.Popen, label: str) -> None:
    if process.poll() is not None:
        return
    print(f"[pipeline] terminating {label}", flush=True)
    process.terminate()
    try:
        process.wait(timeout=10)
    except subprocess.TimeoutExpired:
        print(f"[pipeline] killing {label}", flush=True)
        process.kill()
        process.wait()


def run_stage_c_with_streaming_d(
    candidates_path: Path,
    output_path: Path,
    time_limit_seconds: float | None,
    workers: int,
    stage_d_output_dir: Path,
    report_root: Path,
    report_run_name: str,
    contexts_path: Path | None,
) -> None:
    ensure_stage_d_python()
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text("", encoding="utf-8")
    with tempfile.TemporaryDirectory(prefix="magus-stage-c-") as temp_dir:
        done_file = Path(temp_dir) / "stage_c.done"
        c_command = stage_c_command(candidates_path, output_path, time_limit_seconds, workers)
        d_command = [
            str(STAGE_D_PYTHON),
            "stream_from_C.py",
            "--hypotheses",
            str(output_path),
            "--done-file",
            str(done_file),
            "--out-dir",
            str(stage_d_output_dir),
        ]
        if contexts_path is not None:
            d_command.extend(["--contexts", str(contexts_path)])

        print("[pipeline] streaming Stage C output into Stage D", flush=True)
        print(f"[pipeline] cwd={STAGE_D_RUN_DIR}", flush=True)
        print(f"[pipeline] cmd={shlex.join(d_command)}", flush=True)
        d_process = subprocess.Popen(d_command, cwd=STAGE_D_RUN_DIR)
        time.sleep(0.2)
        if d_process.poll() is not None:
            raise SystemExit(d_process.returncode)

        print(f"[pipeline] cwd={STAGE_C_DIR}", flush=True)
        print(f"[pipeline] cmd={shlex.join(c_command)}", flush=True)
        c_process: subprocess.Popen | None = None
        c_returncode: int | None = None
        try:
            c_process = subprocess.Popen(c_command, cwd=STAGE_C_DIR)
            while True:
                c_returncode = c_process.poll()
                d_returncode = d_process.poll()
                if d_returncode is not None and c_returncode is None:
                    terminate_process(c_process, "Stage C")
                    raise SystemExit(d_returncode)
                if c_returncode is not None:
                    break
                time.sleep(0.5)
        except BaseException:
            if c_process is not None:
                terminate_process(c_process, "Stage C")
            terminate_process(d_process, "Stage D stream")
            raise
        finally:
            if c_returncode is None and c_process is not None:
                c_returncode = c_process.poll()
            done_file.write_text(
                json.dumps({"stage_c_returncode": c_returncode}, ensure_ascii=False) + "\n",
                encoding="utf-8",
            )

        d_returncode = d_process.wait()
        if c_returncode != 0:
            raise SystemExit(c_returncode)
        if d_returncode != 0:
            raise SystemExit(d_returncode)
        run_named_report(stage_d_output_dir, report_root, report_run_name)


def add_stage_a_args(parser: argparse.ArgumentParser, input_flag: str, output_flag: str) -> None:
    parser.add_argument(input_flag, default=str(DEFAULT_STAGE_A_INPUT), help="Stage A 输入 projects.in.jsonl")
    parser.add_argument(output_flag, default=str(DEFAULT_STAGE_A_OUTPUT), help="Stage A 输出 samples.raw.jsonl")


def main() -> None:
    parser = argparse.ArgumentParser(
        description="MAGUS pipeline runner. Supports separate Stage A, B, C, D, Report, or chained A->B->streamed C/D->Report execution."
    )
    subparsers = parser.add_subparsers(dest="command", required=True)

    subparsers.add_parser("build-analyzer", help="构建 Stage A LLVM analyzer")

    parser_gen_input = subparsers.add_parser(
        "gen-input",
        help="从 compile_commands.json 生成 Stage A projects.in.jsonl",
    )
    parser_gen_input.add_argument("--repo-path", default=str(DEFAULT_SOURCE_ROOT), help="源码项目根目录")
    parser_gen_input.add_argument(
        "--compile-commands",
        default="",
        help="compile_commands.json 路径；为空时使用 <repo-path>/compile_commands.json",
    )
    parser_gen_input.add_argument("--output", default=str(DEFAULT_STAGE_A_GENERATED_INPUT), help="输出 projects.in.jsonl")
    parser_gen_input.add_argument("--project-id", default="srcs_sanitized", help="Stage A project_id")
    parser_gen_input.add_argument("--language", default="c", help="Stage A language")
    parser_gen_input.add_argument("--framework", default="generic", help="Stage A framework")
    parser_gen_input.add_argument("--analyzer-jobs", type=int, default=2, help="Stage A analyzer_jobs")
    parser_gen_input.add_argument("--analysis-timeout", type=int, default=1800, help="Stage A analysis_timeout")
    parser_gen_input.add_argument("--clang", default="clang", help="C bitcode compiler")
    parser_gen_input.add_argument("--clangxx", default="clang++", help="C++ bitcode compiler")
    parser_gen_input.add_argument(
        "--bc-dir",
        default="",
        help="repo_path 下的 bitcode 输出目录；默认 bc.<project_id>",
    )
    parser_gen_input.add_argument(
        "--source-glob",
        action="append",
        default=[],
        help="Stage A source_globs 条目，可重复",
    )
    parser_gen_input.add_argument("--force", action="store_true", help="允许覆盖已存在输出")

    parser_stats = subparsers.add_parser("stats-path", help="根据 Stage A raw 输出推导 samples.stats.jsonl 路径")
    parser_stats.add_argument("--raw-output", default=str(DEFAULT_STAGE_A_OUTPUT), help="Stage A raw 输出路径")

    parser_llm = subparsers.add_parser("llm-path", help="根据 Stage A raw 输出推导 samples.llm.jsonl 路径")
    parser_llm.add_argument("--raw-output", default=str(DEFAULT_STAGE_A_OUTPUT), help="Stage A raw 输出路径")

    parser_a = subparsers.add_parser("a", help="只运行 Stage A（含 samples.llm.jsonl 导出）")
    add_stage_a_args(parser_a, "--input", "--output")

    parser_b = subparsers.add_parser("b", help="只运行 Stage B")
    parser_b.add_argument(
        "--input",
        default=str(derived_stats_path(DEFAULT_STAGE_A_OUTPUT)),
        help="Stage B 输入 samples.stats.jsonl",
    )
    parser_b.add_argument(
        "--llm-input",
        default=str(derived_llm_path(DEFAULT_STAGE_A_OUTPUT)),
        help="Stage B 输入 samples.llm.jsonl，用于生成 C-ready 队列",
    )
    parser_b.add_argument(
        "--output-dir",
        default=str(DEFAULT_STAGE_B_OUTPUT_DIR),
        help="Stage B 输出目录",
    )
    parser_b.add_argument(
        "--min-support",
        type=int,
        default=3,
        help="Stage B 频繁模式最低支持度",
    )
    parser_c = subparsers.add_parser("c", help="只运行 Stage C")
    parser_c.add_argument(
        "--candidates",
        default=str(b_c_ready_path(DEFAULT_STAGE_B_OUTPUT_DIR)),
        help="Stage C 输入 Stage B candidates.for_c.jsonl",
    )
    parser_c.add_argument(
        "--output",
        default=str(DEFAULT_STAGE_C_OUTPUT),
        help="Stage C 输出给 Stage D 的 P0/P1/P2 hypotheses.jsonl",
    )
    parser_c.add_argument(
        "--time-limit-seconds",
        type=float,
        default=None,
        help="Stage C 可选候选提交时间预算，默认不限制",
    )
    parser_c.add_argument(
        "--workers",
        type=positive_int,
        default=DEFAULT_STAGE_C_WORKERS,
        help=f"Stage C 并发 worker 进程数，默认 {DEFAULT_STAGE_C_WORKERS}",
    )
    parser_d = subparsers.add_parser("d", help="运行 Stage D，并在 D 完成后生成最终报告")
    parser_d.add_argument(
        "--contexts",
        default="",
        help="可选 D verification_contexts JSON/JSONL；未提供时不加载任何项目特定执行上下文",
    )

    parser_report = subparsers.add_parser("report", help="只从 Stage D 输出生成最终报告")
    parser_report.add_argument(
        "--d-output-dir",
        default=str(DEFAULT_STAGE_D_OUTPUT_DIR),
        help="Stage D verification 输出目录",
    )
    parser_report.add_argument(
        "--report-root",
        default=str(REPORT_DIR),
        help="最终报告根目录；报告写入 <report-root>/<run-name>/",
    )
    parser_report.add_argument(
        "--run-name",
        default="",
        help="报告运行目录名；为空时从 Stage D 输出中的唯一 project_id 推导",
    )

    parser_abcd = subparsers.add_parser("abcd", help="串联运行 Stage A、Stage B，并流式运行 Stage C -> Stage D -> Report")
    add_stage_a_args(parser_abcd, "--a-input", "--a-output")
    parser_abcd.add_argument(
        "--b-output-dir",
        default=str(DEFAULT_STAGE_B_OUTPUT_DIR),
        help="Stage B 输出目录",
    )
    parser_abcd.add_argument(
        "--c-output",
        default=str(DEFAULT_STAGE_C_OUTPUT),
        help="Stage C 输出给 Stage D 的 P0/P1/P2 hypotheses.jsonl",
    )
    parser_abcd.add_argument(
        "--min-support",
        type=int,
        default=3,
        help="Stage B 频繁模式最低支持度",
    )
    parser_abcd.add_argument(
        "--c-time-limit-seconds",
        type=float,
        default=None,
        help="Stage C 可选候选提交时间预算，默认不限制",
    )
    parser_abcd.add_argument(
        "--c-workers",
        type=positive_int,
        default=DEFAULT_STAGE_C_WORKERS,
        help=f"Stage C 并发 worker 进程数，默认 {DEFAULT_STAGE_C_WORKERS}",
    )
    parser_abcd.add_argument(
        "--report-root",
        default=str(REPORT_DIR),
        help="最终报告根目录；报告写入 <report-root>/<run-name>/",
    )
    parser_abcd.add_argument(
        "--report-run-name",
        default="",
        help="报告运行目录名，并用于 Stage D 输出子目录 output/<run-name>；为空时使用 Stage A 输入 project_id",
    )
    parser_abcd.add_argument(
        "--d-contexts",
        default="",
        help="可选 D verification_contexts JSON/JSONL；未提供时 Stage D 只生成通用 target，不加载项目特定执行上下文",
    )
    args = parser.parse_args()

    if args.command == "build-analyzer":
        build_analyzer()
        return

    if args.command == "gen-input":
        compile_commands = resolve_path(args.compile_commands) if args.compile_commands else None
        run_stage_a_gen_input(
            resolve_path(args.repo_path),
            compile_commands,
            resolve_path(args.output),
            args.project_id,
            args.language,
            args.framework,
            args.analyzer_jobs,
            args.analysis_timeout,
            args.clang,
            args.clangxx,
            args.bc_dir,
            args.source_glob,
            args.force,
        )
        return

    if args.command == "stats-path":
        print(derived_stats_path(resolve_path(args.raw_output)))
        return

    if args.command == "llm-path":
        print(derived_llm_path(resolve_path(args.raw_output)))
        return

    if args.command == "a":
        run_stage_a(resolve_path(args.input), resolve_path(args.output))
        return

    if args.command == "b":
        input_path = resolve_path(args.input)
        run_stage_b(input_path, resolve_path(args.llm_input), resolve_path(args.output_dir), args.min_support)
        return

    if args.command == "c":
        run_stage_c(
            resolve_path(args.candidates),
            resolve_path(args.output),
            args.time_limit_seconds,
            args.workers,
        )
        return

    if args.command == "d":
        run_stage_d(resolve_path(args.contexts) if args.contexts.strip() else None)
        return

    if args.command == "report":
        d_output_dir = resolve_path(args.d_output_dir)
        run_name = (
            normalize_report_run_name(args.run_name)
            if args.run_name.strip()
            else report_run_name_from_stage_d_output(d_output_dir)
        )
        run_named_report(d_output_dir, resolve_path(args.report_root), run_name)
        return

    if args.command == "abcd":
        a_input = resolve_path(args.a_input)
        a_output = resolve_path(args.a_output)
        b_output_dir = resolve_path(args.b_output_dir)
        c_output = resolve_path(args.c_output)
        report_root = resolve_path(args.report_root)
        explicit_report_run_name = normalize_report_run_name(args.report_run_name) if args.report_run_name.strip() else ""
        default_report_run_name = report_run_name_from_stage_a_input(a_input)
        report_run_name = explicit_report_run_name or default_report_run_name
        stage_d_output_dir = stage_d_output_dir_for_run(report_run_name)
        print(f"[pipeline] report run name={report_run_name}", flush=True)
        print(f"[pipeline] Stage D output dir={stage_d_output_dir}", flush=True)

        run_stage_a(a_input, a_output)

        llm_output = derived_llm_path(a_output)
        print(f"[pipeline] derived Stage C LLM input={llm_output}", flush=True)

        b_input = derived_stats_path(a_output)
        print(f"[pipeline] derived Stage B input={b_input}", flush=True)
        run_stage_b(b_input, llm_output, b_output_dir, args.min_support)

        candidates_path = b_c_ready_path(b_output_dir)
        print(f"[pipeline] derived Stage C candidates input={candidates_path}", flush=True)
        run_stage_c_with_streaming_d(
            candidates_path,
            c_output,
            args.c_time_limit_seconds,
            args.c_workers,
            stage_d_output_dir,
            report_root,
            report_run_name,
            resolve_path(args.d_contexts) if args.d_contexts.strip() else None,
        )
        return


if __name__ == "__main__":
    main()
