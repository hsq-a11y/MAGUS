#!/usr/bin/env python3
from __future__ import annotations

import argparse
import csv
import json
import os
import re
import shlex
import subprocess
import sys
from dataclasses import dataclass, field
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable


REPO_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_LAZY_MD = REPO_ROOT / "test" / "lazy.md"
DEFAULT_OUT_ROOT = REPO_ROOT / "test" / "out" / "lazy_batch"
DEFAULT_MISMATCH_THRESHOLD = 0.10
RUN_LINE_RE = re.compile(r"run_juliet_folder\s+'([^']+)'\s+'([^']+)'")
ADAPTED_CWE_IDS = {
    "cwe78",
    "cwe90",
    "cwe319",
    "cwe404",
    "cwe672",
    "cwe675",
    "cwe775",
    "cwe426",
    "cwe427",
    "cwe252",
}
JSONL_NAMES = {
    "b_candidates": "candidates.for_c.jsonl",
    "c_hypotheses": "{cwe_id}.hypotheses.jsonl",
    "d_contexts": "verification_contexts.{cwe_id}.jsonl",
    "d_confirmed": "verification.jsonl",
    "d_failed": "verification.failed.jsonl",
}


@dataclass(frozen=True)
class JulietFolder:
    cwe_dir: str
    cwe_id: str


@dataclass
class CommandResult:
    returncode: int
    duration_seconds: float
    c_started_at: datetime | None = None
    c_finished_at: datetime | None = None
    c_stats: dict[str, int] = field(default_factory=dict)


@dataclass
class BatchPaths:
    root: Path
    logs: Path
    eval_root: Path


def utc_now() -> datetime:
    return datetime.now(timezone.utc)


def isoformat_z(value: datetime) -> str:
    return value.astimezone(timezone.utc).replace(microsecond=0).isoformat().replace("+00:00", "Z")


def run_id() -> str:
    return datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ")


def read_json(path: Path) -> Any:
    with path.open("r", encoding="utf-8-sig") as handle:
        return json.load(handle)


def write_json(path: Path, payload: Any) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def display_path(path: Path) -> str:
    try:
        return str(path.resolve().relative_to(REPO_ROOT))
    except ValueError:
        return str(path)


def append_jsonl(path: Path, payload: dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a", encoding="utf-8") as handle:
        handle.write(json.dumps(payload, ensure_ascii=False, separators=(",", ":")) + "\n")


def count_jsonl(path: Path) -> int:
    if not path.exists():
        return 0
    count = 0
    with path.open("r", encoding="utf-8-sig") as handle:
        for line in handle:
            if line.strip():
                count += 1
    return count


def count_jsonl_status(path: Path, status: str) -> int:
    if not path.exists():
        return 0
    count = 0
    with path.open("r", encoding="utf-8-sig") as handle:
        for line in handle:
            line = line.strip()
            if not line:
                continue
            row = json.loads(line)
            if isinstance(row, dict) and row.get("status") == status:
                count += 1
    return count


def hms(seconds: float | None) -> str:
    if seconds is None:
        return ""
    rounded = int(round(seconds))
    hours, rem = divmod(rounded, 3600)
    minutes, secs = divmod(rem, 60)
    return f"{hours:02d}:{minutes:02d}:{secs:02d}"


def safe_div(numerator: float | int | None, denominator: float | int | None) -> float | None:
    if numerator is None or denominator in (None, 0):
        return None
    return float(numerator) / float(denominator)


def round_metric(value: float | None) -> float | None:
    if value is None:
        return None
    return round(value, 6)


def parse_lazy_folders(path: Path) -> list[JulietFolder]:
    folders: list[JulietFolder] = []
    text = path.read_text(encoding="utf-8")
    for match in RUN_LINE_RE.finditer(text):
        folders.append(JulietFolder(cwe_dir=match.group(1), cwe_id=match.group(2)))
    if not folders:
        raise ValueError(f"{path}: no run_juliet_folder entries found")
    unsupported = [folder.cwe_id for folder in folders if folder.cwe_id not in ADAPTED_CWE_IDS]
    if unsupported:
        joined = ", ".join(unsupported)
        raise ValueError(f"{path}: unadapted CWE folders in lazy queue: {joined}")
    return folders


def select_folders(
    folders: list[JulietFolder],
    only: list[str],
    start_at: str,
    max_folders: int | None,
) -> list[JulietFolder]:
    selected = folders
    if only:
        wanted = {item.lower() for item in only}
        selected = [
            folder
            for folder in selected
            if folder.cwe_id.lower() in wanted or folder.cwe_dir.lower() in wanted
        ]
        missing = sorted(wanted - {folder.cwe_id.lower() for folder in selected} - {folder.cwe_dir.lower() for folder in selected})
        if missing:
            raise ValueError(f"unknown --only entries: {', '.join(missing)}")
    if start_at:
        start_key = start_at.lower()
        for idx, folder in enumerate(selected):
            if folder.cwe_id.lower() == start_key or folder.cwe_dir.lower() == start_key:
                selected = selected[idx:]
                break
        else:
            raise ValueError(f"--start-at did not match any selected CWE: {start_at}")
    if max_folders is not None:
        selected = selected[:max_folders]
    if not selected:
        raise ValueError("no CWE folders selected")
    return selected


def source_globs(cwe_dir: str) -> list[str]:
    return [
        f"juliet-api-misuse/testcases/{cwe_dir}/**/*.c",
        f"juliet-api-misuse/testcases/{cwe_dir}/**/*.cc",
        f"juliet-api-misuse/testcases/{cwe_dir}/**/*.cpp",
        f"juliet-api-misuse/testcases/{cwe_dir}/**/*.cxx",
    ]


def command_to_text(command: list[str]) -> str:
    return shlex.join(command)


def parse_c_line(line: str, stats: dict[str, int]) -> None:
    match = re.search(r"\[C\] LLM-audited candidates:\s+(\d+)/(\d+)", line)
    if match:
        stats["c_llm_audited"] = int(match.group(1))
        stats["c_candidates_total"] = int(match.group(2))
        return
    match = re.search(r"\[C\] D candidates:\s+(\d+)", line)
    if match:
        stats["c_d_candidates"] = int(match.group(1))
        return
    match = re.search(r"\[C\] P0 routed to D:\s+(\d+)", line)
    if match:
        stats["c_p0_routed_to_d"] = int(match.group(1))
        return
    match = re.search(r"\[C\] audit only:\s+(\d+)", line)
    if match:
        stats["c_audit_only"] = int(match.group(1))


def run_logged(
    command: list[str],
    cwd: Path,
    log_path: Path,
    env: dict[str, str],
    dry_run: bool,
    observe_c: bool = False,
) -> CommandResult:
    log_path.parent.mkdir(parents=True, exist_ok=True)
    started = utc_now()
    c_started_at: datetime | None = None
    c_finished_at: datetime | None = None
    c_stats: dict[str, int] = {}
    with log_path.open("a", encoding="utf-8") as log:
        log.write(f"[{isoformat_z(started)}] cwd={cwd}\n")
        log.write(f"[{isoformat_z(started)}] cmd={command_to_text(command)}\n")
        log.flush()
        if dry_run:
            finished = utc_now()
            log.write(f"[{isoformat_z(finished)}] dry-run: command not executed\n")
            return CommandResult(returncode=0, duration_seconds=(finished - started).total_seconds())

        process = subprocess.Popen(
            command,
            cwd=cwd,
            env=env,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            bufsize=1,
        )
        assert process.stdout is not None
        for raw_line in process.stdout:
            now = utc_now()
            line = raw_line.rstrip("\n")
            if observe_c:
                if c_started_at is None and line.startswith("[pipeline] cmd=") and "agent1.py" in line:
                    c_started_at = now
                if line.startswith("[C]"):
                    c_finished_at = now
                    parse_c_line(line, c_stats)
            print(line, flush=True)
            log.write(f"[{isoformat_z(now)}] {line}\n")
            log.flush()
        returncode = process.wait()
        finished = utc_now()
        log.write(f"[{isoformat_z(finished)}] returncode={returncode}\n")
    return CommandResult(
        returncode=returncode,
        duration_seconds=(finished - started).total_seconds(),
        c_started_at=c_started_at,
        c_finished_at=c_finished_at,
        c_stats=c_stats,
    )


def build_env(args: argparse.Namespace) -> dict[str, str]:
    env = os.environ.copy()
    llvm_home = args.llvm_home or env.get("LLVM_HOME", "")
    if llvm_home:
        env["LLVM_HOME"] = llvm_home
        env["PATH"] = str(Path(llvm_home) / "bin") + os.pathsep + env.get("PATH", "")
    return env


def ensure_ready(args: argparse.Namespace) -> None:
    required = [
        REPO_ROOT / "srcs",
        REPO_ROOT / "tools" / "gen_srcs_compile_commands.py",
        REPO_ROOT / "pipeline.py",
        REPO_ROOT / "test" / "evaluate_juliet_report.py",
    ]
    for path in required:
        if not path.exists():
            raise FileNotFoundError(f"required path is missing: {path}")
    if args.prepare or args.dry_run:
        return
    if not (REPO_ROOT / "srcs_sanitized" / "juliet_sanitization_map.json").exists():
        raise FileNotFoundError("missing srcs_sanitized/juliet_sanitization_map.json; rerun with --prepare")
    if not (REPO_ROOT / "d" / "memberD_verifier" / ".venv" / "bin" / "python").exists():
        raise FileNotFoundError("missing Stage D Python environment; rerun with --prepare")


def prepare_once(args: argparse.Namespace, paths: BatchPaths, env: dict[str, str]) -> None:
    if not args.prepare:
        return
    commands = [
        [
            sys.executable,
            "tools/sanitize_juliet_tree.py",
            "--input",
            "srcs",
            "--output",
            "srcs_sanitized",
            "--force",
        ],
        ["./01_setup_linux.sh"],
    ]
    cwd_values = [REPO_ROOT, REPO_ROOT / "d" / "memberD_verifier" / "01_demo_test"]
    names = ["prepare.sanitize.log", "prepare.stage-d-setup.log"]
    for command, cwd, name in zip(commands, cwd_values, names):
        result = run_logged(command, cwd, paths.logs / name, env, args.dry_run)
        if result.returncode != 0:
            raise SystemExit(result.returncode)


def compile_commands_path(cwe_id: str) -> Path:
    return REPO_ROOT / "srcs_sanitized" / f"compile_commands.{cwe_id}.json"


def a_input_path(cwe_id: str) -> Path:
    return REPO_ROOT / "a" / "input" / f"srcs.{cwe_id}.in.jsonl"


def a_output_path(cwe_id: str) -> Path:
    return REPO_ROOT / "a" / "out" / f"srcs.{cwe_id}.raw.jsonl"


def b_output_dir(cwe_id: str) -> Path:
    return REPO_ROOT / "b" / f"b_output_{cwe_id}"


def c_output_path(cwe_id: str) -> Path:
    return REPO_ROOT / "c" / "out" / f"{cwe_id}.hypotheses.jsonl"


def d_contexts_path(cwe_id: str) -> Path:
    return REPO_ROOT / "d" / "memberD_verifier" / "02_run_with_C" / JSONL_NAMES["d_contexts"].format(cwe_id=cwe_id)


def d_output_dir(run_name: str) -> Path:
    return REPO_ROOT / "d" / "memberD_verifier" / "02_run_with_C" / "output" / run_name


def count_compile_sources(path: Path) -> tuple[int, int]:
    if not path.exists():
        return 0, 0
    rows = read_json(path)
    if not isinstance(rows, list):
        raise ValueError(f"{path}: expected compile_commands JSON array")
    files = {
        str(row.get("file", "")).strip()
        for row in rows
        if isinstance(row, dict) and str(row.get("file", "")).strip()
    }
    return len(rows), len(files)


def build_compile_command(folder: JulietFolder) -> list[str]:
    command = [
        sys.executable,
        "tools/gen_srcs_compile_commands.py",
        "--repo-path",
        "srcs_sanitized",
        "--output",
        str(compile_commands_path(folder.cwe_id).relative_to(REPO_ROOT)),
    ]
    for glob in source_globs(folder.cwe_dir):
        command.extend(["--source-glob", glob])
    command.extend(
        [
            "--include-dir",
            "../tools/juliet_win_shim",
            "--include-dir",
            "juliet-api-misuse/testcasesupport",
            "--force",
        ]
    )
    return command


def build_gen_input_command(folder: JulietFolder) -> list[str]:
    return [
        sys.executable,
        "pipeline.py",
        "gen-input",
        "--repo-path",
        "srcs_sanitized",
        "--compile-commands",
        str(compile_commands_path(folder.cwe_id).relative_to(REPO_ROOT)),
        "--output",
        str(a_input_path(folder.cwe_id).relative_to(REPO_ROOT)),
        "--project-id",
        folder.cwe_id,
        "--bc-dir",
        f"bc.{folder.cwe_id}",
        "--force",
    ]


def build_context_command(folder: JulietFolder) -> list[str]:
    return [
        sys.executable,
        "tools/gen_juliet_verification_contexts.py",
        "--project-id",
        folder.cwe_id,
        "--out",
        str(d_contexts_path(folder.cwe_id).relative_to(REPO_ROOT)),
    ]


def build_eval_command(folder: JulietFolder, args: argparse.Namespace, eval_dir: Path) -> list[str]:
    run_name = folder.cwe_dir
    abcd_command = [
        sys.executable,
        "pipeline.py",
        "abcd",
        "--a-input",
        str(a_input_path(folder.cwe_id).relative_to(REPO_ROOT)),
        "--a-output",
        str(a_output_path(folder.cwe_id).relative_to(REPO_ROOT)),
        "--b-output-dir",
        str(b_output_dir(folder.cwe_id).relative_to(REPO_ROOT)),
        "--c-output",
        str(c_output_path(folder.cwe_id).relative_to(REPO_ROOT)),
        "--report-run-name",
        run_name,
        "--d-contexts",
        str(d_contexts_path(folder.cwe_id).relative_to(REPO_ROOT)),
    ]
    return [
        sys.executable,
        "test/evaluate_juliet_report.py",
        "--run-command",
        command_to_text(abcd_command),
        "--d-output-dir",
        str(d_output_dir(run_name).relative_to(REPO_ROOT)),
        "--report-run-name",
        run_name,
        "--scope-compile-commands",
        str(compile_commands_path(folder.cwe_id).relative_to(REPO_ROOT)),
        "--out-dir",
        display_path(eval_dir),
    ]


def load_summary(summary_path: Path) -> dict[str, Any]:
    if not summary_path.exists():
        raise FileNotFoundError(f"missing evaluation summary: {summary_path}")
    summary = read_json(summary_path)
    if not isinstance(summary, dict):
        raise ValueError(f"{summary_path}: expected JSON object")
    return summary


def threshold_denominator(counts: dict[str, Any], mode: str) -> int:
    value = counts.get(mode)
    if value in (None, ""):
        raise ValueError(f"summary counts missing denominator field: {mode}")
    return int(value)


def row_from_summary(
    folder: JulietFolder,
    paths: BatchPaths,
    args: argparse.Namespace,
    compile_seconds: float,
    gen_input_seconds: float,
    eval_result: CommandResult,
) -> dict[str, Any]:
    eval_dir = paths.eval_root / folder.cwe_dir
    summary = load_summary(eval_dir / "summary.json")
    counts = summary.get("counts") or {}
    metrics = summary.get("metrics") or {}
    timing = summary.get("timing") or {}
    if not isinstance(counts, dict) or not isinstance(metrics, dict) or not isinstance(timing, dict):
        raise ValueError(f"{eval_dir / 'summary.json'}: invalid summary shape")

    compile_entries, source_files = count_compile_sources(compile_commands_path(folder.cwe_id))
    d_dir = d_output_dir(folder.cwe_dir)
    c_duration = None
    if eval_result.c_started_at is not None and eval_result.c_finished_at is not None:
        c_duration = (eval_result.c_finished_at - eval_result.c_started_at).total_seconds()

    mismatch_count = int(counts.get("fn_cases", 0)) + int(counts.get("fp_unique_units", 0))
    denominator = threshold_denominator(counts, args.threshold_denominator)
    mismatch_rate = safe_div(mismatch_count, denominator)
    c_minutes = safe_div(c_duration, 60.0)
    tp_unique = int(counts.get("tp_unique_cases", 0))
    d_reportable = count_jsonl(d_dir / JSONL_NAMES["d_confirmed"])
    d_confirmed = count_jsonl_status(d_dir / JSONL_NAMES["d_confirmed"], "confirmed")
    d_stage_c_preserved = count_jsonl_status(d_dir / JSONL_NAMES["d_confirmed"], "stage_c_preserved")
    d_failed = count_jsonl(d_dir / JSONL_NAMES["d_failed"])

    row: dict[str, Any] = {
        "run_name": folder.cwe_dir,
        "cwe_id": folder.cwe_id,
        "status": "completed",
        "compile_commands": str(compile_commands_path(folder.cwe_id).relative_to(REPO_ROOT)),
        "compile_entries": compile_entries,
        "source_files": source_files,
        "b_candidates": count_jsonl(b_output_dir(folder.cwe_id) / JSONL_NAMES["b_candidates"]),
        "c_hypotheses": count_jsonl(c_output_path(folder.cwe_id)),
        "d_reportable": d_reportable,
        "d_confirmed": d_confirmed,
        "d_stage_c_preserved": d_stage_c_preserved,
        "d_failed": d_failed,
        "truth_cases": int(counts.get("truth_cases", 0)),
        "truth_positive_cases": int(counts.get("truth_positive_cases", 0)),
        "truth_negative_cases": int(counts.get("truth_negative_cases", 0)),
        "tp_unique_cases": tp_unique,
        "fp_unique_units": int(counts.get("fp_unique_units", 0)),
        "fp_report_rows": int(counts.get("fp_report_rows", 0)),
        "fn_cases": int(counts.get("fn_cases", 0)),
        "mismatch_count": mismatch_count,
        "mismatch_denominator": denominator,
        "mismatch_rate": round_metric(mismatch_rate),
        "mismatch_threshold": args.mismatch_threshold,
        "threshold_exceeded": bool(mismatch_rate is not None and mismatch_rate > args.mismatch_threshold),
        "precision_report_rows": metrics.get("precision_report_rows"),
        "precision_unique_cases": metrics.get("precision_unique_cases"),
        "recall_unique_cases": metrics.get("recall_unique_cases"),
        "false_discovery_rate": metrics.get("false_discovery_rate"),
        "false_negative_rate": metrics.get("false_negative_rate"),
        "false_positive_rate_unique_negative_cases": metrics.get("false_positive_rate_unique_negative_cases"),
        "compile_seconds": round_metric(compile_seconds),
        "gen_input_seconds": round_metric(gen_input_seconds),
        "eval_command_seconds": round_metric(eval_result.duration_seconds),
        "abcd_elapsed_seconds": timing.get("elapsed_seconds"),
        "abcd_elapsed_hms": timing.get("elapsed_hms"),
        "c_started_at": isoformat_z(eval_result.c_started_at) if eval_result.c_started_at else "",
        "c_finished_at": isoformat_z(eval_result.c_finished_at) if eval_result.c_finished_at else "",
        "c_duration_seconds": round_metric(c_duration),
        "c_duration_hms": hms(c_duration),
        "source_files_per_c_min": round_metric(safe_div(source_files, c_minutes)),
        "b_candidates_per_c_min": round_metric(safe_div(count_jsonl(b_output_dir(folder.cwe_id) / JSONL_NAMES["b_candidates"]), c_minutes)),
        "c_hypotheses_per_c_min": round_metric(safe_div(count_jsonl(c_output_path(folder.cwe_id)), c_minutes)),
        "d_reportable_per_c_min": round_metric(safe_div(d_reportable, c_minutes)),
        "d_confirmed_per_c_min": round_metric(safe_div(d_confirmed, c_minutes)),
        "tp_unique_per_c_min": round_metric(safe_div(tp_unique, c_minutes)),
        "log": display_path(paths.logs / f"{folder.cwe_id}.eval.log"),
        "eval_dir": display_path(eval_dir),
        "d_output_dir": display_path(d_dir),
    }
    row.update(eval_result.c_stats)
    return row


CSV_FIELDS = [
    "run_name",
    "cwe_id",
    "status",
    "failure_code",
    "compile_entries",
    "source_files",
    "b_candidates",
    "c_candidates_total",
    "c_llm_audited",
    "c_hypotheses",
    "c_d_candidates",
    "c_p0_routed_to_d",
    "c_audit_only",
    "d_reportable",
    "d_confirmed",
    "d_stage_c_preserved",
    "d_failed",
    "truth_cases",
    "truth_positive_cases",
    "tp_unique_cases",
    "fp_unique_units",
    "fn_cases",
    "mismatch_count",
    "mismatch_denominator",
    "mismatch_rate",
    "mismatch_threshold",
    "threshold_exceeded",
    "precision_unique_cases",
    "recall_unique_cases",
    "false_discovery_rate",
    "false_negative_rate",
    "false_positive_rate_unique_negative_cases",
    "compile_seconds",
    "gen_input_seconds",
    "eval_command_seconds",
    "abcd_elapsed_seconds",
    "abcd_elapsed_hms",
    "c_duration_seconds",
    "c_duration_hms",
    "source_files_per_c_min",
    "b_candidates_per_c_min",
    "c_hypotheses_per_c_min",
    "d_reportable_per_c_min",
    "d_confirmed_per_c_min",
    "tp_unique_per_c_min",
    "log",
    "eval_dir",
    "d_output_dir",
]


def write_runs_csv(path: Path, rows: list[dict[str, Any]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=CSV_FIELDS, extrasaction="ignore")
        writer.writeheader()
        for row in rows:
            writer.writerow(row)


def best_row(rows: list[dict[str, Any]], key: str) -> dict[str, Any] | None:
    candidates = [row for row in rows if isinstance(row.get(key), (int, float))]
    if not candidates:
        return None
    return max(candidates, key=lambda row: float(row[key]))


def write_batch_summary(paths: BatchPaths, rows: list[dict[str, Any]], stop_reason: str) -> None:
    summary = {
        "generated_at": isoformat_z(utc_now()),
        "stop_reason": stop_reason,
        "completed_runs": len(rows),
        "threshold_exceeded_runs": [row["run_name"] for row in rows if row.get("threshold_exceeded")],
        "best_tp_unique_per_c_min": best_row(rows, "tp_unique_per_c_min"),
        "best_d_reportable_per_c_min": best_row(rows, "d_reportable_per_c_min"),
        "best_d_confirmed_per_c_min": best_row(rows, "d_confirmed_per_c_min"),
        "runs_csv": display_path(paths.root / "runs.csv"),
        "runs_jsonl": display_path(paths.root / "runs.jsonl"),
    }
    write_json(paths.root / "batch_summary.json", summary)


def persist_rows(paths: BatchPaths, rows: list[dict[str, Any]], stop_reason: str) -> None:
    write_runs_csv(paths.root / "runs.csv", rows)
    write_batch_summary(paths, rows, stop_reason)


def run_folder(
    folder: JulietFolder,
    args: argparse.Namespace,
    paths: BatchPaths,
    env: dict[str, str],
) -> dict[str, Any]:
    print(f"[lazy-batch] starting {folder.cwe_dir} ({folder.cwe_id})", flush=True)
    compile_result = run_logged(
        build_compile_command(folder),
        REPO_ROOT,
        paths.logs / f"{folder.cwe_id}.compile.log",
        env,
        args.dry_run,
    )
    if compile_result.returncode != 0:
        raise SystemExit(compile_result.returncode)

    gen_input_result = run_logged(
        build_gen_input_command(folder),
        REPO_ROOT,
        paths.logs / f"{folder.cwe_id}.gen-input.log",
        env,
        args.dry_run,
    )
    if gen_input_result.returncode != 0:
        raise SystemExit(gen_input_result.returncode)

    context_result = run_logged(
        build_context_command(folder),
        REPO_ROOT,
        paths.logs / f"{folder.cwe_id}.contexts.log",
        env,
        args.dry_run,
    )
    if context_result.returncode != 0:
        raise SystemExit(context_result.returncode)

    eval_dir = paths.eval_root / folder.cwe_dir
    eval_result = run_logged(
        build_eval_command(folder, args, eval_dir),
        REPO_ROOT,
        paths.logs / f"{folder.cwe_id}.eval.log",
        env,
        args.dry_run,
        observe_c=True,
    )
    if eval_result.returncode != 0:
        raise SystemExit(eval_result.returncode)

    if args.dry_run:
        return {
            "run_name": folder.cwe_dir,
            "cwe_id": folder.cwe_id,
            "status": "dry_run",
            "threshold_exceeded": False,
            "compile_seconds": round_metric(compile_result.duration_seconds),
            "gen_input_seconds": round_metric(gen_input_result.duration_seconds),
            "eval_command_seconds": round_metric(eval_result.duration_seconds),
        }

    row = row_from_summary(
        folder,
        paths,
        args,
        compile_result.duration_seconds,
        gen_input_result.duration_seconds,
        eval_result,
    )
    print(
        "[lazy-batch] completed "
        f"{folder.cwe_id}: mismatch={row['mismatch_count']}/{row['mismatch_denominator']} "
        f"({row['mismatch_rate']}) c={row['c_duration_hms']} tp/min={row['tp_unique_per_c_min']}",
        flush=True,
    )
    return row


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run lazy.md Juliet folders as a monitored batch.")
    parser.add_argument("--lazy-md", default=DEFAULT_LAZY_MD, type=Path, help="lazy.md file to parse for CWE order")
    parser.add_argument("--out-root", default=DEFAULT_OUT_ROOT, type=Path, help="Batch output root")
    parser.add_argument("--run-id", default="", help="Output run id; defaults to current UTC timestamp")
    parser.add_argument("--mismatch-threshold", default=DEFAULT_MISMATCH_THRESHOLD, type=float)
    parser.add_argument(
        "--threshold-denominator",
        default="truth_cases",
        choices=["truth_cases", "truth_positive_cases"],
        help="Denominator for (fn_cases + fp_unique_units) threshold",
    )
    parser.add_argument("--only", action="append", default=[], help="Run only the given CWE id or directory; repeatable")
    parser.add_argument("--start-at", default="", help="Start at the given CWE id or directory")
    parser.add_argument("--max-folders", type=int, help="Limit number of selected folders")
    parser.add_argument("--prepare", action="store_true", help="Run lazy.md one-time sanitization and Stage D setup first")
    parser.add_argument("--llvm-home", default="", help="Set LLVM_HOME and prepend LLVM_HOME/bin to PATH")
    parser.add_argument("--dry-run", action="store_true", help="Print and log commands without executing them")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    args.lazy_md = args.lazy_md.resolve()
    args.out_root = args.out_root.resolve()
    if args.mismatch_threshold < 0:
        raise ValueError("--mismatch-threshold must be non-negative")

    ensure_ready(args)
    folders = select_folders(
        parse_lazy_folders(args.lazy_md),
        args.only,
        args.start_at,
        args.max_folders,
    )
    current_run_id = args.run_id.strip() or run_id()
    paths = BatchPaths(
        root=args.out_root / current_run_id,
        logs=args.out_root / current_run_id / "logs",
        eval_root=args.out_root / current_run_id / "eval",
    )
    paths.root.mkdir(parents=True, exist_ok=True)
    env = build_env(args)
    write_json(
        paths.root / "config.json",
        {
            "lazy_md": str(args.lazy_md),
            "selected": [folder.__dict__ for folder in folders],
            "mismatch_threshold": args.mismatch_threshold,
            "threshold_denominator": args.threshold_denominator,
            "prepare": args.prepare,
            "dry_run": args.dry_run,
            "llvm_home": env.get("LLVM_HOME", ""),
        },
    )

    print(f"[lazy-batch] output: {paths.root}", flush=True)
    prepare_once(args, paths, env)

    rows: list[dict[str, Any]] = []
    stop_reason = "running"
    try:
        for folder in folders:
            try:
                row = run_folder(folder, args, paths, env)
            except SystemExit as exc:
                code = int(exc.code) if isinstance(exc.code, int) else 1
                stop_reason = f"command_failed:{folder.cwe_id}:{code}"
                row = {
                    "run_name": folder.cwe_dir,
                    "cwe_id": folder.cwe_id,
                    "status": "failed",
                    "failure_code": code,
                    "threshold_exceeded": False,
                    "log": display_path(paths.logs / f"{folder.cwe_id}.eval.log"),
                }
                rows.append(row)
                append_jsonl(paths.root / "runs.jsonl", row)
                persist_rows(paths, rows, stop_reason)
                return code if code else 1
            rows.append(row)
            append_jsonl(paths.root / "runs.jsonl", row)
            persist_rows(paths, rows, stop_reason)
            if row.get("threshold_exceeded"):
                print(
                    f"[lazy-batch] threshold exceeded for {folder.cwe_id}; continuing",
                    flush=True,
                )
        stop_reason = "completed"
    finally:
        persist_rows(paths, rows, stop_reason)

    print(f"[lazy-batch] finished {len(rows)} folder(s)", flush=True)
    print(f"[lazy-batch] summary: {paths.root / 'batch_summary.json'}", flush=True)
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, json.JSONDecodeError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        raise SystemExit(2)
