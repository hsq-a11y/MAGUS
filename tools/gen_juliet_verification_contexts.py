#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import shlex
from pathlib import Path
from typing import Any


REPO_ROOT = Path(__file__).resolve().parents[1]


def shell_join(parts: list[Any]) -> str:
    return " ".join(shlex.quote(str(part)) for part in parts)


def read_json_or_jsonl(path: Path) -> list[dict[str, Any]]:
    text = path.read_text(encoding="utf-8-sig").strip()
    if not text:
        return []
    try:
        payload = json.loads(text)
        if isinstance(payload, dict):
            return [payload]
        if isinstance(payload, list) and all(isinstance(item, dict) for item in payload):
            return payload
        raise ValueError(f"{path}: expected JSON object or array of objects")
    except json.JSONDecodeError:
        rows: list[dict[str, Any]] = []
        for line_no, line in enumerate(text.splitlines(), 1):
            line = line.strip()
            if not line:
                continue
            try:
                row = json.loads(line)
            except json.JSONDecodeError as exc:
                raise ValueError(f"{path}:{line_no}: invalid JSON: {exc}") from exc
            if not isinstance(row, dict):
                raise ValueError(f"{path}:{line_no}: expected JSON object")
            rows.append(row)
        return rows


def hypothesis_files(path: Path) -> list[Path]:
    if path.is_dir():
        files = sorted(item for item in path.glob("*.jsonl") if item.is_file())
        if not files:
            raise ValueError(f"{path}: no Stage C *.jsonl files found")
        return files
    if path.is_file():
        return [path]
    raise ValueError(f"{path}: expected Stage C output directory or hypotheses JSONL file")


def project_ids_from_hypotheses(path: Path) -> list[str]:
    project_ids: set[str] = set()
    for file_path in hypothesis_files(path):
        for row in read_json_or_jsonl(file_path):
            project_id = str(row.get("project_id") or "").strip()
            if project_id:
                project_ids.add(project_id)
    if not project_ids:
        raise ValueError(f"{path}: no project_id values found")
    return sorted(project_ids)


def juliet_test_cmd() -> str:
    command: list[Any] = [
        "${PYTHON}",
        "tools/juliet_win_shim/run_juliet_win_case.py",
        "--source-file",
        "${source_file}",
        "--entry-symbol",
        "${entry_symbol}",
        "--route",
        "${route}",
    ]
    return shell_join(command)


def juliet_oracle() -> dict[str, Any]:
    return {
        "accepted_evidence": [
            "MAGUS_ROUTE_EXECUTED proves the selected dynamic route was reached",
            "MAGUS_ROUTE_CONFIRMED is emitted only when the selected oracle profile matches route-bound semantic evidence",
            "MAGUS_ORACLE_UNSUPPORTED means D reached the route but lacks an oracle for the hypothesis semantics",
        ],
        "failure_patterns": ["MAGUS_ROUTE_CONFIRMED"],
        "required_patterns": ["MAGUS_ROUTE_EXECUTED"],
        "unsupported_patterns": ["MAGUS_ORACLE_UNSUPPORTED"],
        "failure_code_patterns": {
            "NOT_ROUTE_BOUND": ["MAGUS_NOT_ROUTE_BOUND"],
            "ENV_MISSING": ["MAGUS_BUILD_FAILED", "MAGUS_RUNNER_ERROR"],
            "NOT_EXPLOITABLE": ["MAGUS_NOT_CONFIRMED"],
        },
        "expect_nonzero_exit": False,
    }


def context_rows(project_ids: list[str], repo_path: Path) -> list[dict[str, Any]]:
    return [
        {
            "project_id": project_id,
            "repo_path": repo_path.as_posix(),
            "test_cmd": juliet_test_cmd(),
            "oracle": juliet_oracle(),
        }
        for project_id in sorted(set(project_ids))
    ]


def write_jsonl(path: Path, rows: list[dict[str, Any]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as handle:
        for row in rows:
            handle.write(json.dumps(row, ensure_ascii=False, separators=(",", ":")) + "\n")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate D verification_contexts.jsonl for running Juliet Win32 samples on Linux."
    )
    parser.add_argument(
        "--project-id",
        action="append",
        default=[],
        help="Stage A/Stage C project_id to bind; repeatable",
    )
    parser.add_argument(
        "--hypotheses",
        type=Path,
        help="Optional Stage C JSONL file or directory to derive project_id values from",
    )
    parser.add_argument("--out", required=True, type=Path, help="Output verification_contexts.jsonl")
    parser.add_argument("--repo-path", default=REPO_ROOT, type=Path, help="Workspace root containing tools/juliet_win_shim")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    project_ids = [str(item).strip() for item in args.project_id if str(item).strip()]
    if args.hypotheses is not None:
        project_ids.extend(project_ids_from_hypotheses(args.hypotheses))
    if not project_ids:
        raise ValueError("pass --project-id or --hypotheses so the sidecar is explicitly scoped")
    rows = context_rows(project_ids, args.repo_path.expanduser().resolve())
    if not rows:
        raise ValueError("no Juliet contexts generated")
    write_jsonl(args.out, rows)
    print(f"wrote Juliet verification contexts: {args.out}")
    print(f"contexts: {len(rows)}")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, json.JSONDecodeError) as exc:
        raise SystemExit(f"error: {exc}") from exc
