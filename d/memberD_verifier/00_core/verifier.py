#!/usr/bin/env python3
"""
MAGUS Stage D source/API verifier.

In this project, "API" means a C/C++ programming interface or function-call
sequence. Stage D does not generate or execute HTTP requests.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, Iterable, List, Optional, Tuple


FAILURE_CODES = {
    "NOT_EXPLOITABLE",
    "NOT_ROUTE_BOUND",
    "ENV_MISSING",
    "HYPOTHESIS_WRONG",
    "TIMEOUT",
    "NON_DETERMINISTIC",
    "UNSUPPORTED_ORACLE",
}
REPORTABLE_STATUSES = {"confirmed", "stage_c_preserved"}
STAGE_C_PRESERVABLE_PRIORITIES = {"P0", "P1"}

MIN_EVIDENCE_FIELDS = ["project_id", "sample_id", "hypothesis_id", "route", "file", "line", "evidence_slice"]
UNRESOLVED_VALUES = ("AUTO_DETECT_FAILED", "TODO", "replace with", "真实", "待填写")
PROJECT_ROOT = Path(__file__).resolve().parents[1]
WORKSPACE_ROOT = PROJECT_ROOT.parent.parent
P0_TIMEOUT_SECONDS = 10.0


SOURCE_API_PAYLOAD_RUNNER = r'''#!/usr/bin/env python3
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


def payload_runtime_inputs(payload: dict[str, Any]) -> list[str]:
    values: list[Any] = []
    raw_inputs = payload.get("runtime_inputs")
    if isinstance(raw_inputs, list):
        values.extend(raw_inputs)
    elif raw_inputs not in (None, "", []):
        values.append(raw_inputs)
    runtime_input = payload.get("runtime_input")
    if runtime_input not in (None, "", []):
        values.append(runtime_input)

    result: list[str] = []
    seen: set[str] = set()
    for value in values:
        text = str(value)
        if not text or text in seen:
            continue
        seen.add(text)
        result.append(text)
    return result


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
    runtime_inputs = payload_runtime_inputs(payload)
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
        "MAGUS_D_RUNTIME_INPUT": runtime_inputs[0] if runtime_inputs else payload.get("runtime_input"),
    }
    for key, value in values.items():
        if value not in (None, "", []):
            env[key] = str(value)
    if runtime_inputs:
        env["MAGUS_D_RUNTIME_INPUTS_JSON"] = json.dumps(runtime_inputs, ensure_ascii=False)
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
    parser.add_argument("--plan", default="__PLAN_NAME__")
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
'''


def utc_now() -> str:
    return datetime.now(timezone.utc).replace(microsecond=0).isoformat().replace("+00:00", "Z")


def timeout_for_hypothesis(hyp: Dict[str, Any]) -> float | None:
    return P0_TIMEOUT_SECONDS if str(hyp.get("priority") or "").upper() == "P0" else None


def scalar_list(value: Any) -> List[Any]:
    if value in (None, "", []):
        return []
    if isinstance(value, list):
        return value
    return [value]


def text_list(value: Any) -> List[str]:
    items: List[str] = []
    for item in scalar_list(value):
        if item in (None, "", []):
            continue
        if isinstance(item, (dict, list)):
            text = json.dumps(item, ensure_ascii=False, separators=(",", ":"))
        else:
            text = str(item)
        text = " ".join(text.split())
        if text:
            items.append(text)
    return items


def cwe_candidates(row: Dict[str, Any]) -> List[str]:
    values = row.get("cwe_candidates") or row.get("CWE_candidates") or row.get("cwe_list") or []
    return text_list(values)


def hypothesis_context_fields(hyp: Dict[str, Any]) -> Dict[str, Any]:
    fields: Dict[str, Any] = {}
    for key in ("claim", "preconditions", "attack_path", "confidence"):
        value = hyp.get(key)
        if value not in (None, "", []):
            fields[key] = value
    cwes = cwe_candidates(hyp)
    if cwes:
        fields["cwe_candidates"] = cwes
    return fields


def read_jsonl(path: Path) -> List[Dict[str, Any]]:
    text = path.read_text(encoding="utf-8-sig").strip()
    if not text:
        return []

    try:
        data = json.loads(text)
        if isinstance(data, list):
            if all(isinstance(item, dict) for item in data):
                return data
            raise ValueError(f"{path}: expected JSON objects in array")
        if isinstance(data, dict):
            return [data]
    except json.JSONDecodeError:
        pass

    rows: List[Dict[str, Any]] = []
    for n, line in enumerate(text.splitlines(), 1):
        line = line.strip()
        if not line:
            continue
        try:
            row = json.loads(line)
        except json.JSONDecodeError as exc:
            raise ValueError(f"Invalid JSON on {path}:{n}: {exc}") from exc
        if not isinstance(row, dict):
            raise ValueError(f"{path}:{n}: expected JSON object")
        rows.append(row)
    return rows


def hypothesis_files(path: Path) -> List[Path]:
    if path.is_dir():
        files = sorted(item for item in path.glob("*.jsonl") if item.is_file())
        if not files:
            raise ValueError(f"{path}: no Stage C *.jsonl files found")
        return files
    if path.is_file():
        return [path]
    raise ValueError(f"{path}: expected Stage C output directory or hypotheses JSONL file")


def read_hypotheses(path: Path) -> List[Dict[str, Any]]:
    rows: List[Dict[str, Any]] = []
    seen: Dict[Tuple[str, str], str] = {}
    for file_path in hypothesis_files(path):
        for row_no, row in enumerate(read_jsonl(file_path), 1):
            project_id = str(row.get("project_id", "")).strip()
            hypothesis_id = str(row.get("hypothesis_id", "")).strip()
            if project_id and hypothesis_id:
                key = (project_id, hypothesis_id)
                label = f"{file_path}:{row_no}"
                previous = seen.get(key)
                if previous:
                    raise ValueError(
                        f"duplicate hypothesis project_id={project_id!r} hypothesis_id={hypothesis_id!r}: "
                        f"{previous} and {label}"
                    )
                seen[key] = label
            rows.append(row)
    if not rows:
        raise ValueError(f"{path}: no Stage C hypothesis records found")
    return rows


def write_jsonl(path: Path, rows: Iterable[Dict[str, Any]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as f:
        for row in rows:
            f.write(json.dumps(row, ensure_ascii=False, separators=(",", ":")) + "\n")


def load_targets(path: Path) -> Dict[str, Dict[str, Any]]:
    data = json.loads(path.read_text(encoding="utf-8"))
    if isinstance(data, dict) and "targets" in data:
        targets = data["targets"]
    elif isinstance(data, list):
        targets = data
    elif isinstance(data, dict) and "project_id" in data:
        targets = [data]
    else:
        raise ValueError("targets.json must be {project_id,...}, a list, or {targets:[...]}.")

    result: Dict[str, Dict[str, Any]] = {}
    for target in targets:
        project_id = target.get("project_id")
        if not project_id:
            raise ValueError("Every target must contain project_id.")
        result[str(project_id)] = target
    return result


def stable_verify_id(hypothesis_id: str) -> str:
    digest = hashlib.sha1(hypothesis_id.encode("utf-8")).hexdigest()[:8]
    return f"ver_{digest}"


def missing_fields(hyp: Dict[str, Any]) -> List[str]:
    return [field for field in MIN_EVIDENCE_FIELDS if hyp.get(field) in (None, "", [])]


def evidence_fields(hyp: Dict[str, Any]) -> Dict[str, Any]:
    return {
        "route": hyp.get("route"),
        "file": hyp.get("file"),
        "line": hyp.get("line"),
        "evidence_slice": hyp.get("evidence_slice"),
    }


def routing_fields(hyp: Dict[str, Any]) -> Dict[str, Any]:
    fields: Dict[str, Any] = {}
    for key in ("priority", "routing_decision", "suspicion_reason", "agent_verdict"):
        if hyp.get(key) not in (None, "", []):
            fields[key] = hyp.get(key)
    return fields


def oracle_profile_fields(case: Dict[str, Any]) -> Dict[str, Any]:
    oracle = case.get("oracle") if isinstance(case.get("oracle"), dict) else {}
    profile_id = case.get("oracle_profile_id") or oracle.get("profile_id")
    fields: Dict[str, Any] = {}
    if profile_id not in (None, "", []):
        fields["oracle_profile_id"] = profile_id
    if oracle.get("profile_supported") not in (None, "", []):
        fields["oracle_profile_supported"] = bool(oracle.get("profile_supported"))
    return fields


def get_case(target: Dict[str, Any], hyp: Dict[str, Any]) -> Optional[Dict[str, Any]]:
    cases = target.get("cases") or {}
    hypothesis_id = hyp.get("hypothesis_id")
    route = hyp.get("route")
    if hypothesis_id in cases:
        return dict(cases[hypothesis_id])
    if route in cases:
        return dict(cases[route])
    return None


def failed_record(hyp: Dict[str, Any], code: str, note: str, suggested_action: str = "review hypothesis or target case") -> Dict[str, Any]:
    if code not in FAILURE_CODES:
        code = "HYPOTHESIS_WRONG"
    record = {
        "verify_id": stable_verify_id(str(hyp.get("hypothesis_id", "unknown"))),
        "project_id": hyp.get("project_id"),
        "sample_id": hyp.get("sample_id"),
        "hypothesis_id": hyp.get("hypothesis_id"),
        "status": "failed",
        "failure_code": code,
        "failure_note": note,
        "suggested_action": suggested_action,
        "timestamps": {"failed_at": utc_now()},
    }
    record.update(evidence_fields(hyp))
    record.update(hypothesis_context_fields(hyp))
    record.update(routing_fields(hyp))
    return record


def stage_c_verdict_fields(hyp: Dict[str, Any]) -> Dict[str, Any]:
    return {
        key: hyp.get(key)
        for key in ("priority", "routing_decision", "suspicion_reason", "agent_verdict")
        if hyp.get(key) not in (None, "", [])
    }


def stage_c_priority(hyp: Dict[str, Any]) -> str:
    return str(hyp.get("priority") or "").strip().upper()


def can_preserve_stage_c_verdict(hyp: Dict[str, Any]) -> bool:
    return stage_c_priority(hyp) in STAGE_C_PRESERVABLE_PRIORITIES


def preserved_record(
    hyp: Dict[str, Any],
    case: Dict[str, Any],
    result: Dict[str, Any],
    runner_rel: Path,
    plan_rel: Path,
) -> Dict[str, Any]:
    record = {
        "verify_id": stable_verify_id(str(hyp.get("hypothesis_id", "unknown"))),
        "project_id": hyp.get("project_id"),
        "sample_id": hyp.get("sample_id"),
        "hypothesis_id": hyp.get("hypothesis_id"),
        "status": "stage_c_preserved",
        "severity": stage_c_priority(hyp) or "P0",
        "target_type": "source_api",
        "attack_type": case.get("attack_type"),
        "payload_ref": runner_rel.as_posix(),
        "plan_ref": plan_rel.as_posix(),
        "oracle_status": "unsupported",
        "preservation_reason": "UNSUPPORTED_ORACLE",
        "failure_code": "UNSUPPORTED_ORACLE",
        "failure_note": result.get("failure_note")
        or "Stage D oracle cannot prove or disprove this route; preserving Stage C judgment",
        "stage_c_verdict": stage_c_verdict_fields(hyp),
        "repro_steps": [
            f"run generated payload runner {runner_rel.as_posix()}",
            "execute configured config/build commands if present",
            "preserve the Stage C vulnerability judgment because Stage D reported UNSUPPORTED_ORACLE",
        ],
        "observations": result.get("observations") or [],
        "runtime_trace": result.get("runtime_trace") or [],
        "timestamps": {"preserved_at": utc_now()},
    }
    record.update(oracle_profile_fields(case))
    record.update(evidence_fields(hyp))
    record.update(hypothesis_context_fields(hyp))
    record.update(routing_fields(hyp))
    return record


def unsupported_oracle_failed_record(
    hyp: Dict[str, Any],
    case: Dict[str, Any],
    result: Dict[str, Any],
    runner_rel: Path,
    plan_rel: Path,
) -> Dict[str, Any]:
    priority = stage_c_priority(hyp) or "missing"
    record = failed_record(
        hyp,
        "UNSUPPORTED_ORACLE",
        (
            "Stage D oracle cannot prove or disprove this route, and Stage C priority "
            f"{priority} is not eligible for reportable preservation"
        ),
        "review the Stage C hypothesis, improve the oracle profile, or rerun after priority is P0/P1",
    )
    record["payload_ref"] = runner_rel.as_posix()
    record["plan_ref"] = plan_rel.as_posix()
    record["target_type"] = "source_api"
    record["attack_type"] = case.get("attack_type")
    record["oracle_status"] = "unsupported"
    record["preservation_policy"] = "preserve_only_p0_p1"
    record["stage_c_verdict"] = stage_c_verdict_fields(hyp)
    record["observations"] = result.get("observations") or []
    record["runtime_trace"] = result.get("runtime_trace") or []
    record.update(oracle_profile_fields(case))
    return record


def has_unresolved_marker(value: Any) -> bool:
    if value in (None, "", []):
        return False
    text = json.dumps(value, ensure_ascii=False) if isinstance(value, (dict, list)) else str(value)
    return any(marker.lower() in text.lower() for marker in UNRESOLVED_VALUES)


def resolve_repo_path(raw_path: str) -> str:
    repo = Path(raw_path).expanduser()
    if repo.is_absolute():
        return str(repo)

    candidates = [
        Path.cwd() / repo,
        PROJECT_ROOT / repo,
        PROJECT_ROOT.parent / repo,
        WORKSPACE_ROOT / repo,
    ]
    for candidate in candidates:
        if candidate.exists():
            return str(candidate.resolve())
    return str((Path.cwd() / repo).resolve())


def source_execution_config(target: Dict[str, Any], case: Dict[str, Any]) -> Dict[str, Any]:
    config: Dict[str, Any] = {}
    for source in (
        target.get("verification_context") or {},
        case.get("verification_context") or {},
        target.get("execution") or {},
        case.get("execution") or {},
        target,
        case,
    ):
        if not isinstance(source, dict):
            continue
        for key in ("repo_path", "config_cmd", "build_cmd", "run_cmd", "poc_cmd", "test_cmd", "docker_image", "timeout_sec"):
            value = source.get(key)
            if value not in (None, "", []) and not has_unresolved_marker(value):
                config[key] = value
    return config


def source_execution_missing(config: Dict[str, Any]) -> List[str]:
    missing: List[str] = []
    if not config.get("repo_path"):
        missing.append("repo_path")
    if not (config.get("run_cmd") or config.get("poc_cmd") or config.get("test_cmd")):
        missing.append("run_cmd/poc_cmd/test_cmd")
    return missing


def write_source_api_plan(
    payload_path: Path,
    hyp: Dict[str, Any],
    case: Dict[str, Any],
    target: Dict[str, Any],
    command_timeout: float | None,
) -> None:
    payload_path.parent.mkdir(parents=True, exist_ok=True)
    execution = source_execution_config(target, case)
    repo_path = execution.get("repo_path")
    if repo_path:
        execution["repo_path"] = resolve_repo_path(str(repo_path))
    plan = {
        "kind": "source_api_misuse_plan",
        "project_id": hyp.get("project_id"),
        "sample_id": hyp.get("sample_id"),
        "hypothesis_id": hyp.get("hypothesis_id"),
        "claim": hyp.get("claim"),
        "cwe_candidates": hyp.get("cwe_candidates") or hyp.get("CWE_candidates") or hyp.get("cwe_list"),
        "source_file": case.get("source_file") or hyp.get("file"),
        "entry_symbol": case.get("entry_symbol"),
        "oracle_profile_id": case.get("oracle_profile_id") or (case.get("oracle") or {}).get("profile_id"),
        "oracle_profile": case.get("oracle_profile"),
        "api_sequence": case.get("api_sequence") or hyp.get("attack_path") or hyp.get("api_sequence"),
        "payload": case.get("payload"),
        "poc_plan": case.get("poc_plan"),
        "oracle": case.get("oracle"),
        "build": {
            "env_profile": target.get("env_profile"),
            "repo_path": execution.get("repo_path"),
            "config_cmd": execution.get("config_cmd"),
            "build_cmd": execution.get("build_cmd"),
            "run_cmd": execution.get("run_cmd"),
            "poc_cmd": execution.get("poc_cmd"),
            "test_cmd": execution.get("test_cmd"),
            "docker_image": execution.get("docker_image"),
            "timeout_sec": command_timeout,
        },
        "evidence": evidence_fields(hyp),
        "timestamps": {"generated_at": utc_now()},
    }
    payload_path.write_text(json.dumps(plan, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def write_source_payload_runner(runner_path: Path, plan_name: str) -> None:
    runner_path.parent.mkdir(parents=True, exist_ok=True)
    script = SOURCE_API_PAYLOAD_RUNNER.replace("__PLAN_NAME__", plan_name)
    runner_path.write_text(script + "\n", encoding="utf-8")


def execute_source_payload(runner_path: Path, timeout: float | None) -> Tuple[Optional[Dict[str, Any]], Optional[str]]:
    runner_path = runner_path.resolve()
    result_path = runner_path.with_suffix(".payload-result.json")
    cmd = [sys.executable, str(runner_path), "--result", str(result_path)]
    try:
        subprocess.run(
            cmd,
            cwd=str(runner_path.parent),
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            timeout=timeout,
            check=False,
        )
    except subprocess.TimeoutExpired as exc:
        return None, f"payload runner timed out: {exc}"

    if not result_path.exists():
        return None, "payload runner did not produce result json"
    try:
        return json.loads(result_path.read_text(encoding="utf-8")), None
    except json.JSONDecodeError as exc:
        return None, f"invalid payload runner result: {exc}"


def is_source_api_case(target: Dict[str, Any], case: Optional[Dict[str, Any]]) -> bool:
    return (
        (target.get("target_type") in {"source_api", "native"})
        or bool(case and case.get("target_type") in {"source_api", "native"})
        or bool(case and case.get("payload_kind") in {"api_misuse_plan", "native_plan"})
    )


def run_one(hyp: Dict[str, Any], target: Dict[str, Any], out_dir: Path, dry_run: bool) -> Tuple[Optional[Dict[str, Any]], Optional[Dict[str, Any]]]:
    missing = missing_fields(hyp)
    if missing:
        return None, failed_record(hyp, "HYPOTHESIS_WRONG", f"missing required fields: {', '.join(missing)}")

    case = get_case(target, hyp)
    if case is None:
        return None, failed_record(
            hyp,
            "HYPOTHESIS_WRONG",
            f"no source/API case for hypothesis_id={hyp.get('hypothesis_id')}",
            "regenerate targets.json from the same Stage C hypotheses input",
        )
    if not is_source_api_case(target, case):
        return None, failed_record(
            hyp,
            "HYPOTHESIS_WRONG",
            f"unsupported target_type={target.get('target_type')!r}; Stage D only verifies source/API cases",
            "remove HTTP/Web targets and provide source_api targets",
        )

    plan_rel = Path("payloads") / f"{hyp['hypothesis_id']}.api-plan.json"
    runner_rel = Path("payloads") / f"{hyp['hypothesis_id']}.payload.py"
    plan_abs = out_dir / plan_rel
    runner_abs = out_dir / runner_rel
    timeout = timeout_for_hypothesis(hyp)
    write_source_api_plan(plan_abs, hyp, case, target, timeout)
    write_source_payload_runner(runner_abs, plan_rel.name)

    execution = source_execution_config(target, case)
    missing_execution = source_execution_missing(execution)
    if missing_execution:
        record = failed_record(
            hyp,
            "ENV_MISSING",
            "executable source/API payload generated but execution config is incomplete: "
            + ", ".join(missing_execution),
            "provide repo_path plus run_cmd/poc_cmd/test_cmd; optional config_cmd/build_cmd can prepare the project",
        )
        record["payload_ref"] = runner_rel.as_posix()
        record["plan_ref"] = plan_rel.as_posix()
        record["target_type"] = "source_api"
        record["attack_type"] = case.get("attack_type")
        record.update(oracle_profile_fields(case))
        record["runtime_trace"] = [
            {
                "name": case.get("name") or "source_api_payload",
                "status": "payload_generated",
                "payload_ref": runner_rel.as_posix(),
                "plan_ref": plan_rel.as_posix(),
                "missing": missing_execution,
                "ts": utc_now(),
            }
        ]
        return None, record

    if dry_run:
        record = failed_record(
            hyp,
            "HYPOTHESIS_WRONG",
            "dry-run mode: source/API payload generated but not executed",
            f"inspect {plan_rel.as_posix()} and rerun without --dry-run",
        )
        record["payload_ref"] = runner_rel.as_posix()
        record["plan_ref"] = plan_rel.as_posix()
        record["target_type"] = "source_api"
        record["attack_type"] = case.get("attack_type")
        record.update(oracle_profile_fields(case))
        return None, record

    result, runner_error = execute_source_payload(runner_abs, timeout)
    if runner_error:
        failure_code = "TIMEOUT" if runner_error.startswith("payload runner timed out") else "ENV_MISSING"
        suggested_action = (
            "inspect payload runner runtime or route this hypothesis as P1/P2 when longer dynamic verification is required"
            if failure_code == "TIMEOUT"
            else "check that local Python can execute the generated payload runner"
        )
        record = failed_record(
            hyp,
            failure_code,
            runner_error,
            suggested_action,
        )
        record["payload_ref"] = runner_rel.as_posix()
        record["plan_ref"] = plan_rel.as_posix()
        record["target_type"] = "source_api"
        record["attack_type"] = case.get("attack_type")
        record.update(oracle_profile_fields(case))
        return None, record
    assert result is not None

    if result.get("status") == "confirmed":
        record = {
            "verify_id": stable_verify_id(str(hyp["hypothesis_id"])),
            "project_id": hyp["project_id"],
            "sample_id": hyp["sample_id"],
            "hypothesis_id": hyp["hypothesis_id"],
            "status": "confirmed",
            "severity": "P0",
            "target_type": "source_api",
            "attack_type": case.get("attack_type"),
            "payload_ref": runner_rel.as_posix(),
            "plan_ref": plan_rel.as_posix(),
            "repro_steps": [
                f"run generated payload runner {runner_rel.as_posix()}",
                "execute configured config/build commands if present",
                "execute configured run_cmd/poc_cmd/test_cmd against the source project",
                "mark confirmed only when the oracle matches runtime evidence",
            ],
            "observations": result.get("observations") or [],
            "runtime_trace": result.get("runtime_trace") or [],
            "timestamps": {"verified_at": utc_now()},
        }
        record.update(oracle_profile_fields(case))
        record.update(evidence_fields(hyp))
        record.update(hypothesis_context_fields(hyp))
        record.update(routing_fields(hyp))
        return record, None

    if result.get("status") == "unsupported":
        if can_preserve_stage_c_verdict(hyp):
            return preserved_record(hyp, case, result, runner_rel, plan_rel), None
        return None, unsupported_oracle_failed_record(hyp, case, result, runner_rel, plan_rel)

    record = failed_record(
        hyp,
        result.get("failure_code") or "NOT_EXPLOITABLE",
        result.get("failure_note") or "source/API payload executed but oracle did not confirm exploitability",
        "inspect payload result, adjust run_cmd/poc_cmd/test_cmd, or refine oracle patterns",
    )
    record["payload_ref"] = runner_rel.as_posix()
    record["plan_ref"] = plan_rel.as_posix()
    record["target_type"] = "source_api"
    record["attack_type"] = case.get("attack_type")
    record.update(oracle_profile_fields(case))
    record.update(hypothesis_context_fields(hyp))
    record["observations"] = result.get("observations") or []
    record["runtime_trace"] = result.get("runtime_trace") or []
    return None, record


def write_summary(out_dir: Path, success_rows: List[Dict[str, Any]], failed_rows: List[Dict[str, Any]]) -> None:
    confirmed_rows = [row for row in success_rows if row.get("status") == "confirmed"]
    preserved_rows = [row for row in success_rows if row.get("status") == "stage_c_preserved"]
    lines = [
        "# Member D Verification Summary",
        "",
        f"- generated_at: {utc_now()}",
        f"- target_type: source_api",
        f"- reportable: {len(success_rows)}",
        f"- confirmed: {len(confirmed_rows)}",
        f"- stage_c_preserved: {len(preserved_rows)}",
        f"- failed: {len(failed_rows)}",
        "",
    ]
    if confirmed_rows:
        lines.extend(["## Confirmed P0", ""])
        for row in confirmed_rows:
            lines.append(
                f"- {row.get('hypothesis_id')} | {row.get('project_id')} | {row.get('route')} | "
                f"payload: {row.get('payload_ref')}"
            )
    if preserved_rows:
        lines.extend(["", "## Stage C Preserved / D Unsupported", ""])
        for row in preserved_rows:
            lines.append(
                f"- {row.get('hypothesis_id')} | {row.get('project_id')} | {row.get('route')} | "
                f"reason: {row.get('preservation_reason')}"
            )
    if failed_rows:
        lines.extend(["", "## Failed / 回流", ""])
        for row in failed_rows:
            lines.append(
                f"- {row.get('hypothesis_id')} | {row.get('failure_code')} | "
                f"{row.get('failure_note')} | action: {row.get('suggested_action')}"
            )
    (out_dir / "verification.summary.md").write_text("\n".join(lines) + "\n", encoding="utf-8")


def main(argv: Optional[List[str]] = None) -> int:
    parser = argparse.ArgumentParser(description="Source/API hypothesis verifier")
    parser.add_argument("--hypotheses", required=True, type=Path, help="Path to C output directory or hypotheses JSONL file")
    parser.add_argument("--targets", required=True, type=Path, help="Path to source/API targets.json")
    parser.add_argument("--out-dir", required=True, type=Path, help="Output directory")
    parser.add_argument("--dry-run", action="store_true", help="Generate payloads and plans without executing run_cmd")
    args = parser.parse_args(argv)

    args.out_dir.mkdir(parents=True, exist_ok=True)
    targets = load_targets(args.targets)
    hypotheses = read_hypotheses(args.hypotheses)

    success_rows: List[Dict[str, Any]] = []
    failed_rows: List[Dict[str, Any]] = []

    for hyp in hypotheses:
        target = targets.get(str(hyp.get("project_id")))
        if not target:
            failed_rows.append(
                failed_record(
                    hyp,
                    "ENV_MISSING",
                    f"no source/API target for project_id={hyp.get('project_id')}",
                    "regenerate targets.json from the same Stage C hypotheses input",
                )
            )
            continue
        success, failed = run_one(hyp, target, args.out_dir, args.dry_run)
        if success:
            success_rows.append(success)
        if failed:
            failed_rows.append(failed)

    write_jsonl(args.out_dir / "verification.jsonl", success_rows)
    write_jsonl(args.out_dir / "verification.failed.jsonl", failed_rows)
    write_summary(args.out_dir, success_rows, failed_rows)

    confirmed_count = sum(1 for row in success_rows if row.get("status") == "confirmed")
    preserved_count = sum(1 for row in success_rows if row.get("status") == "stage_c_preserved")
    print(f"reportable: {len(success_rows)}")
    print(f"confirmed:  {confirmed_count}")
    print(f"preserved:  {preserved_count}")
    print(f"failed:    {len(failed_rows)}")
    print(f"output:    {args.out_dir}")
    return 0 if success_rows or failed_rows else 1


if __name__ == "__main__":
    sys.exit(main())
