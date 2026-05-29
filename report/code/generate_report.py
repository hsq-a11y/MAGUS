#!/usr/bin/env python3
from __future__ import annotations

import argparse
import hashlib
import json
import sys
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, List


REPORT_JSONL_NAME = "verification.report.jsonl"
REPORT_MD_NAME = "verification.report.md"
REPO_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_D_OUTPUT_DIR = REPO_ROOT / "d/memberD_verifier/02_run_with_C/output"
DEFAULT_REPORT_DIR = REPO_ROOT / "report"


def utc_now() -> str:
    return datetime.now(timezone.utc).replace(microsecond=0).isoformat().replace("+00:00", "Z")


def read_jsonl(path: Path) -> List[Dict[str, Any]]:
    if not path.exists():
        raise FileNotFoundError(f"required input is missing: {path}")

    text = path.read_text(encoding="utf-8-sig").strip()
    if not text:
        return []

    try:
        data = json.loads(text)
        if isinstance(data, list):
            for index, row in enumerate(data, 1):
                if not isinstance(row, dict):
                    raise ValueError(f"{path}:{index}: expected a JSON object")
            return data
        if isinstance(data, dict):
            return [data]
    except json.JSONDecodeError:
        pass

    rows: List[Dict[str, Any]] = []
    for line_number, line in enumerate(text.splitlines(), 1):
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


def write_jsonl(path: Path, rows: List[Dict[str, Any]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as f:
        for row in rows:
            f.write(json.dumps(row, ensure_ascii=False, separators=(",", ":")) + "\n")


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


def vulnerability_type(row: Dict[str, Any]) -> str:
    attack_type = str(row.get("attack_type") or "").strip()
    if attack_type and attack_type != "generic":
        return attack_type
    cwes = cwe_candidates(row)
    if cwes:
        return ", ".join(cwes)
    claim = str(row.get("claim") or "").strip()
    return claim or "source_api_misuse"


def report_id_for(row: Dict[str, Any]) -> str:
    digest_input = "|".join(
        str(row.get(key) or "")
        for key in ("project_id", "sample_id", "hypothesis_id", "file", "line")
    )
    digest = hashlib.sha1(digest_input.encode("utf-8")).hexdigest()[:8]
    return f"report_{digest}"


def trigger_condition(row: Dict[str, Any]) -> Dict[str, Any]:
    preconditions = text_list(row.get("preconditions"))
    attack_path = text_list(row.get("attack_path") or row.get("api_sequence"))
    if not attack_path and row.get("route"):
        attack_path = [str(row.get("route"))]
    return {
        "preconditions": preconditions,
        "attack_path": attack_path,
        "route": row.get("route"),
        "evidence_slice": row.get("evidence_slice"),
    }


def final_report_record(row: Dict[str, Any]) -> Dict[str, Any]:
    return {
        "report_id": report_id_for(row),
        "project_id": row.get("project_id"),
        "sample_id": row.get("sample_id"),
        "hypothesis_id": row.get("hypothesis_id"),
        "verification_status": row.get("status"),
        "verify_id": row.get("verify_id"),
        "location": {
            "file_path": row.get("file"),
            "line": row.get("line"),
            "route": row.get("route"),
        },
        "vulnerability_type": vulnerability_type(row),
        "cwe_candidates": cwe_candidates(row),
        "semantic_family": row.get("semantic_family"),
        "semantic_contract": row.get("semantic_contract"),
        "risk_level": row.get("severity") or row.get("priority") or "P0",
        "trigger_condition": trigger_condition(row),
        "claim": row.get("claim"),
        "confidence": row.get("confidence"),
        "stage_c_verdict": row.get("stage_c_verdict"),
        "evidence": {
            "evidence_slice": row.get("evidence_slice"),
            "observations": row.get("observations") or [],
            "payload_ref": row.get("payload_ref"),
            "plan_ref": row.get("plan_ref"),
            "oracle_status": row.get("oracle_status"),
            "preservation_reason": row.get("preservation_reason"),
        },
    }


def final_report_rows(success_rows: List[Dict[str, Any]]) -> List[Dict[str, Any]]:
    return [final_report_record(row) for row in success_rows]


def format_report_text(value: Any) -> str:
    if value in (None, "", []):
        return "N/A"
    if isinstance(value, list):
        rendered = [format_report_text(item) for item in value if item not in (None, "", [])]
        return "; ".join(item for item in rendered if item and item != "N/A") or "N/A"
    if isinstance(value, dict):
        return json.dumps(value, ensure_ascii=False, separators=(",", ":"))
    return " ".join(str(value).split()) or "N/A"


def write_final_report(
    out_dir: Path,
    success_rows: List[Dict[str, Any]],
    failed_rows: List[Dict[str, Any]],
    confirmed_path: Path,
    failed_path: Path,
) -> None:
    report_rows = final_report_rows(success_rows)
    d_confirmed_rows = [row for row in success_rows if row.get("status") == "confirmed"]
    preserved_rows = [row for row in success_rows if row.get("status") == "stage_c_preserved"]
    out_dir.mkdir(parents=True, exist_ok=True)
    write_jsonl(out_dir / REPORT_JSONL_NAME, report_rows)

    lines = [
        "# MAGUS Final Vulnerability Report",
        "",
        f"- generated_at: {utc_now()}",
        f"- reportable_vulnerabilities: {len(report_rows)}",
        f"- d_confirmed_vulnerabilities: {len(d_confirmed_rows)}",
        f"- stage_c_preserved_vulnerabilities: {len(preserved_rows)}",
        f"- failed_verifications: {len(failed_rows)}",
        f"- source_confirmed: {confirmed_path}",
        f"- source_failed: {failed_path}",
        "",
    ]

    if not report_rows:
        lines.extend(
            [
                "## Confirmed Vulnerabilities",
                "",
                "No route-bound confirmed vulnerabilities were produced by Stage D.",
                "",
            ]
        )
    else:
        lines.extend(["## Confirmed Vulnerabilities", ""])
        for index, row in enumerate(report_rows, 1):
            location = row.get("location") or {}
            trigger = row.get("trigger_condition") or {}
            evidence = row.get("evidence") or {}
            lines.extend(
                [
                    f"### {index}. {row.get('hypothesis_id')}",
                    "",
                    f"- 漏洞位置: {location.get('file_path')}:{location.get('line')}",
                    f"- 漏洞类型: {format_report_text(row.get('vulnerability_type'))}",
                    f"- CWE: {format_report_text(row.get('cwe_candidates'))}",
                    f"- 风险等级: {format_report_text(row.get('risk_level'))}",
                    f"- 触发条件: {format_report_text(trigger.get('preconditions'))}",
                    f"- 触发路径: {format_report_text(trigger.get('attack_path'))}",
                    f"- 结论: {format_report_text(row.get('claim'))}",
                    f"- D验证: {format_report_text(row.get('verification_status'))} / {format_report_text(row.get('verify_id'))}",
                    f"- 运行证据: {format_report_text(evidence.get('observations'))}",
                    f"- 保留原因: {format_report_text(evidence.get('preservation_reason'))}",
                    "",
                ]
            )

    if failed_rows:
        lines.extend(
            [
                "## Unconfirmed / Failed Verification",
                "",
                "These records are not reported as confirmed vulnerabilities. See `verification.failed.jsonl` for full failure details.",
                "",
            ]
        )
        for row in failed_rows:
            lines.append(
                f"- {row.get('hypothesis_id')} | {row.get('file')}:{row.get('line')} | "
                f"{row.get('failure_code')} | {row.get('failure_note')}"
            )

    (out_dir / REPORT_MD_NAME).write_text("\n".join(lines) + "\n", encoding="utf-8")


def parse_args(argv: List[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Generate the MAGUS final vulnerability report from Stage D outputs")
    parser.add_argument(
        "--confirmed",
        default=DEFAULT_D_OUTPUT_DIR / "verification.jsonl",
        type=Path,
        help="Stage D reportable verification JSONL",
    )
    parser.add_argument(
        "--failed",
        default=DEFAULT_D_OUTPUT_DIR / "verification.failed.jsonl",
        type=Path,
        help="Stage D failed verification JSONL",
    )
    parser.add_argument("--out-dir", default=DEFAULT_REPORT_DIR, type=Path, help="Final report output directory")
    return parser.parse_args(argv)


def main(argv: List[str] | None = None) -> int:
    args = parse_args(argv)
    try:
        success_rows = read_jsonl(args.confirmed)
        failed_rows = read_jsonl(args.failed)
        write_final_report(args.out_dir, success_rows, failed_rows, args.confirmed, args.failed)
    except (OSError, ValueError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1

    print(f"reported: {len(success_rows)}")
    print(f"output:   {args.out_dir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
