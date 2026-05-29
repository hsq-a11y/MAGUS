#!/usr/bin/env python3
import json
import tempfile
import unittest
from pathlib import Path

import generate_report
import validate_report


def _confirmed_row():
    return {
        "verify_id": "ver_12345678",
        "project_id": "p",
        "sample_id": "s",
        "hypothesis_id": "hyp_s",
        "status": "confirmed",
        "severity": "P0",
        "target_type": "source_api",
        "attack_type": "buffer_overflow",
        "route": "file.c::target",
        "file": "file.c",
        "line": 42,
        "evidence_slice": "strcpy(dst, src);",
        "claim": "externally controlled input can overflow dst",
        "cwe_candidates": ["CWE-121"],
        "preconditions": ["attacker controls src"],
        "attack_path": ["read input", "strcpy(dst, src)"],
        "payload_ref": "payloads/hyp_s.payload.py",
        "plan_ref": "payloads/hyp_s.api-plan.json",
        "observations": ["oracle matched patterns: AddressSanitizer"],
    }


def _preserved_row():
    row = _confirmed_row()
    row.update(
        {
            "hypothesis_id": "hyp_preserved",
            "status": "stage_c_preserved",
            "severity": "P1",
            "oracle_status": "unsupported",
            "preservation_reason": "UNSUPPORTED_ORACLE",
            "failure_code": "UNSUPPORTED_ORACLE",
            "stage_c_verdict": {
                "priority": "P1",
                "routing_decision": "dynamic_verification",
                "agent_verdict": "vulnerability",
            },
            "semantic_family": "network.cleartext_sensitive_transmission",
            "semantic_contract": {
                "family": "network.cleartext_sensitive_transmission",
                "requires_route_bound_evidence": True,
            },
        }
    )
    return row


class FinalReportTests(unittest.TestCase):
    def test_final_report_row_contains_required_vulnerability_fields(self):
        row = generate_report.final_report_rows([_confirmed_row()])[0]

        self.assertEqual(row["location"], {"file_path": "file.c", "line": 42, "route": "file.c::target"})
        self.assertEqual(row["vulnerability_type"], "buffer_overflow")
        self.assertEqual(row["risk_level"], "P0")
        self.assertIn("attacker controls src", row["trigger_condition"]["preconditions"])
        self.assertNotIn("fix_recommendation", row)
        self.assertEqual(validate_report.validate_report(row), [])

    def test_write_final_report_files(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            out_dir = Path(temp_dir)
            generate_report.write_final_report(
                out_dir,
                [_confirmed_row()],
                [],
                Path("verification.jsonl"),
                Path("verification.failed.jsonl"),
            )

            report_jsonl = out_dir / generate_report.REPORT_JSONL_NAME
            report_md = out_dir / generate_report.REPORT_MD_NAME
            self.assertTrue(report_jsonl.exists())
            self.assertTrue(report_md.exists())
            report_rows = [json.loads(line) for line in report_jsonl.read_text(encoding="utf-8").splitlines()]
            self.assertEqual(len(report_rows), 1)
            report_text = report_md.read_text(encoding="utf-8")
            self.assertIn("漏洞位置: file.c:42", report_text)
            self.assertNotIn("修复意见", report_text)

    def test_preserved_stage_c_verdict_is_reportable(self):
        row = generate_report.final_report_rows([_preserved_row()])[0]

        self.assertEqual(row["verification_status"], "stage_c_preserved")
        self.assertEqual(row["risk_level"], "P1")
        self.assertEqual(row["evidence"]["preservation_reason"], "UNSUPPORTED_ORACLE")
        self.assertEqual(validate_report.validate_report(row), [])

    def test_p2_preserved_stage_c_verdict_is_not_valid_reportable(self):
        preserved = _preserved_row()
        preserved["severity"] = "P2"
        preserved["stage_c_verdict"]["priority"] = "P2"
        row = generate_report.final_report_rows([preserved])[0]

        self.assertIn(
            "preserved Stage C report record must have risk_level P0 or P1",
            validate_report.validate_report(row),
        )


if __name__ == "__main__":
    unittest.main()
