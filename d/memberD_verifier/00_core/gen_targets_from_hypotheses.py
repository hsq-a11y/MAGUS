#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Generate source/API verification targets from Stage C hypotheses.

In MAGUS, "API" means a C/C++ programming interface or function-call sequence.
This generator does not create HTTP requests, base URLs, bearer tokens, or Web
endpoint cases.
"""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path
from typing import Any, Dict, Iterable, List, Tuple

from oracle_profiles import build_oracle_profile, compact_profile_for_json


DEFAULT_FAILURE_PATTERNS = [
    "AddressSanitizer",
    "UndefinedBehaviorSanitizer",
    "runtime error:",
    "Segmentation fault",
    "null pointer",
    "heap-use-after-free",
    "stack-buffer-overflow",
    "heap-buffer-overflow",
    "double-free",
]


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
            raise ValueError(f"Invalid JSON at {path}:{n}: {exc}") from exc
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


def dump_json(path: Path, obj: Any) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(obj, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def as_text(value: Any) -> str:
    if value is None:
        return ""
    if isinstance(value, list):
        return " ".join(as_text(v) for v in value)
    if isinstance(value, dict):
        return " ".join(f"{k} {as_text(v)}" for k, v in value.items())
    return str(value)


def classify_attack(hyp: Dict[str, Any]) -> str:
    text = as_text(
        [
            hyp.get("claim"),
            hyp.get("cwe_candidates") or hyp.get("CWE_candidates") or hyp.get("cwe_list"),
            hyp.get("preconditions"),
            hyp.get("attack_path"),
            hyp.get("rebuttal"),
        ]
    ).lower()

    if "cwe-476" in text or "null pointer" in text or "空指针" in text:
        return "null_deref"
    if "cwe-416" in text or "use after free" in text or "uaf" in text:
        return "use_after_free"
    if "cwe-401" in text or "memory leak" in text or "内存泄漏" in text:
        return "memory_leak"
    if "cwe-190" in text or "integer overflow" in text or "integer underflow" in text or "整数溢出" in text:
        return "integer_overflow"
    if "cwe-78" in text or "command injection" in text or "命令注入" in text:
        return "command_injection"
    if "cwe-22" in text or "path traversal" in text or "目录遍历" in text:
        return "path_traversal"
    if "cwe-89" in text or "sql injection" in text or "sql注入" in text:
        return "sql_injection"
    if (
        "cwe-120" in text
        or "cwe-121" in text
        or "cwe-122" in text
        or "cwe-125" in text
        or "cwe-126" in text
        or "cwe-787" in text
        or "buffer overflow" in text
        or "out-of-bounds read" in text
        or "out of bounds read" in text
        or "越界读" in text
        or "缓冲区溢出" in text
    ):
        return "buffer_overflow"
    return "generic"


def marker_for(hyp: Dict[str, Any]) -> str:
    return f"memberD_source_api_probe_{hyp.get('hypothesis_id', 'hyp')}"


def path_entry_text(value: Any) -> str:
    if isinstance(value, dict):
        for key in ("function", "entry_symbol", "name", "code", "loc"):
            raw = value.get(key)
            if raw not in (None, "", []):
                return str(raw)
        return ""
    return str(value or "")


def normalize_entry_symbol(raw: Any) -> str:
    symbol = " ".join(str(raw or "").split())
    if not symbol:
        return ""
    if " @ " in symbol:
        symbol = symbol.split(" @ ", 1)[0].strip()
    if "::" in symbol:
        symbol = symbol.rsplit("::", 1)[-1].strip()
    if "->" in symbol:
        symbol = symbol.split("->", 1)[0].strip()
    if symbol.startswith("call:"):
        symbol = symbol[len("call:") :].strip()
    if "(" in symbol:
        symbol = symbol.split("(", 1)[0].strip()
    symbol = symbol.strip(" .,:;")
    match = re.search(r"([A-Za-z_][A-Za-z0-9_]*)$", symbol)
    if match:
        return match.group(1)
    return symbol


def entry_symbol(hyp: Dict[str, Any]) -> str:
    for key in ("func_name", "entry_function", "entrypoint", "function", "api"):
        value = hyp.get(key)
        if isinstance(value, str) and value:
            return normalize_entry_symbol(value)
        if isinstance(value, dict):
            for subkey in ("handler", "function", "name"):
                if value.get(subkey):
                    return normalize_entry_symbol(value[subkey])

    route_symbol = normalize_entry_symbol(hyp.get("route"))
    if route_symbol:
        return route_symbol

    attack_path = hyp.get("attack_path")
    if isinstance(attack_path, list):
        for item in attack_path:
            candidate = normalize_entry_symbol(path_entry_text(item))
            if candidate:
                return candidate
    elif attack_path:
        candidate = normalize_entry_symbol(path_entry_text(attack_path))
        if candidate:
            return candidate

    return "unknown_entry"


def infer_poc_language(hyp: Dict[str, Any]) -> str:
    text = as_text([hyp.get("language"), hyp.get("file"), hyp.get("filepath")]).lower()
    if text.endswith(".c") or text.endswith(".h") or text == "c":
        return "c"
    if text.endswith(".cpp") or text.endswith(".cc") or text.endswith(".cxx") or "c++" in text or "cpp" in text:
        return "cpp"
    if text.endswith(".rs") or "rust" in text:
        return "rust"
    if text.endswith(".go") or "golang" in text or text == "go":
        return "go"
    if text.endswith(".java") or "java" in text:
        return "java"
    if text.endswith(".py") or "python" in text:
        return "python"
    return "unknown"


def seed_inputs_for_attack(attack_type: str) -> List[str]:
    if attack_type == "null_deref":
        return ["empty input", "malformed serialized bytes", "allocation failure path"]
    if attack_type == "integer_overflow":
        return ["-1", "0", "INT_MAX", "SIZE_MAX boundary value"]
    if attack_type == "use_after_free":
        return ["release-before-use API sequence", "double release sequence", "dangling handle reuse"]
    if attack_type == "buffer_overflow":
        return ["boundary-sized buffer", "oversized buffer", "unterminated byte string"]
    if attack_type == "path_traversal":
        return ["../ traversal path", "absolute path", "encoded traversal path"]
    if attack_type == "command_injection":
        return ["shell metacharacter payload", "argument separator payload", "environment-controlled command"]
    if attack_type == "sql_injection":
        return ["quote-breaking SQL string", "boolean tautology", "union-select probe"]
    return [
        "boundary-sized input",
        "null/zero/negative argument where type permits",
        "malformed serialized bytes",
        "state-transition sequence that violates inferred API pattern",
    ]


def dedupe_text(values: Iterable[str]) -> List[str]:
    result: List[str] = []
    seen: set[str] = set()
    for value in values:
        if value in seen:
            continue
        seen.add(value)
        result.append(value)
    return result


def runtime_inputs_for_attack(attack_type: str, hyp: Dict[str, Any]) -> List[str]:
    text = as_text(
        [
            hyp.get("file"),
            hyp.get("route"),
            hyp.get("claim"),
            hyp.get("evidence_slice"),
            hyp.get("cwe_candidates") or hyp.get("CWE_candidates") or hyp.get("cwe_list"),
        ]
    ).lower()
    if attack_type == "buffer_overflow":
        if (
            "cwe129" in text
            or "cwe-129" in text
            or "cwe125" in text
            or "cwe-125" in text
            or "cwe126" in text
            or "cwe-126" in text
            or "array index" in text
            or "index" in text
        ):
            return dedupe_text(["11", "10", "15", "100", "-1", "2147483647"])
        return ["A" * 512, "A" * 2048, "A" * 8192]
    if attack_type == "integer_overflow":
        return dedupe_text(["2147483647", "2147483646", "1073741824", "-2147483648", "-2147483647"])
    return []


def runtime_input_for_attack(attack_type: str, hyp: Dict[str, Any]) -> str | None:
    inputs = runtime_inputs_for_attack(attack_type, hyp)
    return inputs[0] if inputs else None


def make_source_api_case(hyp: Dict[str, Any], auto_fill: bool) -> Dict[str, Any]:
    attack_type = classify_attack(hyp)
    symbol = entry_symbol(hyp)
    language = infer_poc_language(hyp)
    source_file = hyp.get("file") or hyp.get("filepath")
    cwe = hyp.get("cwe_candidates") or hyp.get("CWE_candidates") or hyp.get("cwe_list") or []
    oracle_profile = compact_profile_for_json(build_oracle_profile(hyp))

    seed_inputs = seed_inputs_for_attack(attack_type)
    runtime_inputs = runtime_inputs_for_attack(attack_type, hyp)
    runtime_input = runtime_inputs[0] if runtime_inputs else None
    input_source = None

    case: Dict[str, Any] = {
        "name": f"auto_{attack_type}" if auto_fill else "source_api_misuse",
        "target_type": "source_api",
        "attack_type": attack_type,
        "auto_generated": auto_fill,
        "payload_kind": "api_misuse_plan",
        "poc_language": language,
        "source_file": source_file,
        "entry_symbol": symbol,
        "oracle_profile_id": oracle_profile.get("profile_id"),
        "oracle_profile": oracle_profile,
        "api_sequence": hyp.get("api_sequence") or hyp.get("attack_path") or [],
        "poc_plan": [
            f"Build or load project containing {source_file or 'the target source file'}",
            f"Construct or locate a harness that reaches {symbol}",
            f"Drive the API sequence with misuse-oriented inputs for {', '.join(cwe) if cwe else attack_type}",
            "Run under sanitizer/test oracle and collect crash, error-code, assertion, or differential evidence",
        ],
        "payload": {
            "marker": marker_for(hyp),
            "entry_symbol": symbol,
            "input_source": input_source,
            "seed_inputs": seed_inputs,
        },
        "oracle": {
            "profile_id": oracle_profile.get("profile_id"),
            "profile_supported": bool(oracle_profile.get("supported")),
            "accepted_evidence": [
                "MAGUS_ROUTE_EXECUTED proves the selected route or source/API sequence was reached",
                "ASan/UBSan crash",
                "non-zero test exit caused by crafted source/API input",
                "unexpected success on invalid API state",
                "differential behavior between vulnerable and fixed revision",
                *(oracle_profile.get("accepted_evidence") or []),
            ],
            "semantic_failure_patterns": oracle_profile.get("confirm_patterns") or [],
            "failure_patterns": sorted(set(DEFAULT_FAILURE_PATTERNS + (oracle_profile.get("confirm_patterns") or []))),
            "required_patterns": ["MAGUS_ROUTE_EXECUTED"],
            "capability_patterns": oracle_profile.get("capability_patterns") or [],
            "unsupported_patterns": ["MAGUS_ORACLE_UNSUPPORTED"],
            "failure_code_patterns": {
                "NOT_ROUTE_BOUND": ["MAGUS_NOT_ROUTE_BOUND"],
                "NOT_EXPLOITABLE": ["MAGUS_NOT_CONFIRMED"],
            },
            "expect_nonzero_exit": True,
        },
    }
    if runtime_input:
        case["payload"]["runtime_input"] = runtime_input
    if runtime_inputs:
        case["payload"]["runtime_inputs"] = runtime_inputs

    explicit_context = hyp.get("verification_context")
    if isinstance(explicit_context, dict) and explicit_context:
        case["verification_context"] = explicit_context

        explicit_oracle = explicit_context.get("oracle")
        if isinstance(explicit_oracle, dict) and explicit_oracle:
            case["oracle"] = dict(explicit_oracle)
            case["oracle"].setdefault("profile_id", oracle_profile.get("profile_id"))
            case["oracle"].setdefault("profile_supported", bool(oracle_profile.get("supported")))

    if hyp.get("poc_code") or hyp.get("harness_code"):
        case["harness_code"] = hyp.get("poc_code") or hyp.get("harness_code")
    return case


def make_native_case(hyp: Dict[str, Any], auto_fill: bool) -> Dict[str, Any]:
    return make_source_api_case(hyp, auto_fill)


def build_targets(hypotheses: Iterable[Dict[str, Any]], auto_fill: bool = False) -> Dict[str, Any]:
    targets_by_project: Dict[str, Dict[str, Any]] = {}

    for hyp in hypotheses:
        project_id = hyp.get("project_id")
        hypothesis_id = hyp.get("hypothesis_id")
        route = hyp.get("route")

        if not project_id or not hypothesis_id or not route:
            raise ValueError(
                f"hypothesis missing project_id/hypothesis_id/route: "
                f"project_id={project_id}, hypothesis_id={hypothesis_id}, route={route}"
            )

        target = targets_by_project.setdefault(
            str(project_id),
            {
                "project_id": str(project_id),
                "target_type": "source_api",
                "env_profile": "source_repository",
                "cases": {},
            },
        )
        target["cases"][str(hypothesis_id)] = make_source_api_case(hyp, auto_fill)

    return {"targets": list(targets_by_project.values())}


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate source/API targets.json from Stage C hypotheses")
    parser.add_argument("--hypotheses", required=True, type=Path, help="C stage output directory or hypotheses JSONL file")
    parser.add_argument("--out", default=Path("targets.json"), type=Path, help="Output targets.json")
    parser.add_argument("--auto-fill", action="store_true", help="Generate best-effort source/API payload plans")
    args = parser.parse_args()

    hypotheses = read_hypotheses(args.hypotheses)
    targets = build_targets(hypotheses=hypotheses, auto_fill=args.auto_fill)
    dump_json(args.out, targets)

    total_cases = sum(len(t["cases"]) for t in targets["targets"])
    print(f"generated: {args.out}")
    print(f"projects:  {len(targets['targets'])}")
    print(f"cases:     {total_cases}")
    print("next: explicit targets or verification_contexts JSON/JSONL must provide repo_path plus run_cmd/poc_cmd/test_cmd before verifier.py")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
