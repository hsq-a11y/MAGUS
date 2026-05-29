#!/usr/bin/env python3
from __future__ import annotations

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, Iterable, List

sys.path.insert(0, str(Path(__file__).resolve().parent))

import generate_report  # noqa: E402


REPORT_REQUIRED_FIELDS = [
    "report_id",
    "project_id",
    "sample_id",
    "hypothesis_id",
    "verification_status",
    "location",
    "vulnerability_type",
    "risk_level",
    "trigger_condition",
]
REPORTABLE_VERIFICATION_STATUSES = {"confirmed", "stage_c_preserved"}
PRESERVED_REPORTABLE_RISK_LEVELS = {"P0", "P1"}


def missing(row: Dict[str, Any], fields: Iterable[str]) -> List[str]:
    return [field for field in fields if row.get(field) in (None, "", [])]


def validate_report(row: Dict[str, Any]) -> List[str]:
    errors = []
    errors.extend(f"missing {field}" for field in missing(row, REPORT_REQUIRED_FIELDS))
    location = row.get("location")
    if not isinstance(location, dict):
        errors.append("location must be an object")
    else:
        if location.get("file_path") in (None, "", []):
            errors.append("location.file_path is required")
        if location.get("line") in (None, "", []):
            errors.append("location.line is required")
    trigger = row.get("trigger_condition")
    if not isinstance(trigger, dict):
        errors.append("trigger_condition must be an object")
    else:
        has_trigger = any(
            trigger.get(field) not in (None, "", [])
            for field in ("preconditions", "attack_path", "route", "evidence_slice")
        )
        if not has_trigger:
            errors.append("trigger_condition must include preconditions, attack_path, route, or evidence_slice")
    if row.get("verification_status") not in REPORTABLE_VERIFICATION_STATUSES:
        errors.append("report record must be based on confirmed verification or preserved Stage C judgment")
    if (
        row.get("verification_status") == "stage_c_preserved"
        and row.get("risk_level") not in PRESERVED_REPORTABLE_RISK_LEVELS
    ):
        errors.append("preserved Stage C report record must have risk_level P0 or P1")
    if row.get("verification_status") == "stage_c_preserved":
        if row.get("semantic_family") in (None, "", []):
            errors.append("preserved Stage C report record must include semantic_family")
        if not isinstance(row.get("semantic_contract"), dict):
            errors.append("preserved Stage C report record must include structured semantic_contract")
    return errors


def parse_args(argv: List[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Validate MAGUS final vulnerability report files")
    parser.add_argument(
        "--confirmed",
        default=generate_report.DEFAULT_D_OUTPUT_DIR / "verification.jsonl",
        type=Path,
        help="Stage D reportable verification JSONL used as the report source",
    )
    parser.add_argument(
        "--report-dir",
        default=generate_report.DEFAULT_REPORT_DIR,
        type=Path,
        help="Final report output directory",
    )
    return parser.parse_args(argv)


def main(argv: List[str] | None = None) -> int:
    args = parse_args(argv)
    report_path = args.report_dir / generate_report.REPORT_JSONL_NAME
    report_md_path = args.report_dir / generate_report.REPORT_MD_NAME

    problems: List[str] = []
    try:
        confirmed = generate_report.read_jsonl(args.confirmed)
    except (OSError, ValueError) as exc:
        problems.append(str(exc))
        confirmed = []

    if report_path.exists():
        try:
            report = generate_report.read_jsonl(report_path)
        except (OSError, ValueError) as exc:
            problems.append(str(exc))
            report = []
    else:
        problems.append(f"{generate_report.REPORT_JSONL_NAME} is missing")
        report = []

    if not report_md_path.exists():
        problems.append(f"{generate_report.REPORT_MD_NAME} is missing")

    for idx, row in enumerate(report, 1):
        for err in validate_report(row):
            problems.append(f"{generate_report.REPORT_JSONL_NAME}:{idx}: {err}")

    if len(report) != len(confirmed):
        problems.append(
            f"{generate_report.REPORT_JSONL_NAME} must contain one report row per confirmed record: "
            f"report={len(report)} confirmed={len(confirmed)}"
        )

    if problems:
        print("INVALID")
        for item in problems:
            print("-", item)
        return 1

    print("VALID")
    print(f"reportable: {len(confirmed)}")
    print(f"reported:  {len(report)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
