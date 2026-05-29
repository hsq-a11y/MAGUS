#!/usr/bin/env python3
import json
import sys
import tempfile
import unittest
from pathlib import Path

import verifier


def _hyp(priority):
    return {
        "project_id": "p",
        "sample_id": "s",
        "hypothesis_id": f"hyp_{priority.lower()}",
        "priority": priority,
        "route": "file.c::target",
        "file": "file.c",
        "line": 1,
        "evidence_slice": "call:sink",
    }


def _semantic_hyp(priority):
    hyp = _hyp(priority)
    hyp.update(
        {
            "semantic_family": "network.cleartext_sensitive_transmission",
            "semantic_contract": {
                "family": "network.cleartext_sensitive_transmission",
                "requires_route_bound_evidence": True,
                "required_semantics": ["sensitive data crosses a network boundary in cleartext"],
            },
        }
    )
    return hyp


def _target_with_context_timeout():
    return {
        "target_type": "source_api",
        "verification_context": {
            "repo_path": ".",
            "run_cmd": "true",
            "timeout_sec": 123,
        },
    }


class TimeoutPolicyTests(unittest.TestCase):
    def _plan_for(self, hyp):
        with tempfile.TemporaryDirectory() as temp_dir:
            path = Path(temp_dir) / "plan.json"
            verifier.write_source_api_plan(
                path,
                hyp,
                {"oracle": {}},
                _target_with_context_timeout(),
                verifier.timeout_for_hypothesis(hyp),
            )
            return json.loads(path.read_text(encoding="utf-8"))

    def test_p0_has_fixed_timeout(self):
        hyp = _hyp("P0")
        self.assertEqual(verifier.timeout_for_hypothesis(hyp), 10.0)
        self.assertEqual(self._plan_for(hyp)["build"]["timeout_sec"], 10.0)

    def test_non_p0_has_no_d_timeout(self):
        for priority in ("P1", "P2", "P3"):
            with self.subTest(priority=priority):
                hyp = _hyp(priority)
                self.assertIsNone(verifier.timeout_for_hypothesis(hyp))
                self.assertIsNone(self._plan_for(hyp)["build"]["timeout_sec"])


class UnsupportedOracleTests(unittest.TestCase):
    def test_run_one_preserves_stage_c_verdict_on_unsupported_oracle(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            hyp = _semantic_hyp("P1")
            hyp.update({"routing_decision": "dynamic_verification", "agent_verdict": "vulnerability"})
            target = {
                "project_id": "p",
                "target_type": "source_api",
                "cases": {
                    "hyp_p1": {
                        "target_type": "source_api",
                        "attack_type": "generic",
                        "execution": {
                            "repo_path": temp_dir,
                            "test_cmd": (
                                f"{sys.executable} -c "
                                "\"print('MAGUS_ROUTE_EXECUTED'); "
                                "print('MAGUS_ORACLE_UNSUPPORTED')\""
                            ),
                        },
                        "oracle": {
                            "required_patterns": ["MAGUS_ROUTE_EXECUTED"],
                            "unsupported_patterns": ["MAGUS_ORACLE_UNSUPPORTED"],
                            "failure_code_patterns": {"NOT_EXPLOITABLE": ["MAGUS_NOT_CONFIRMED"]},
                            "expect_nonzero_exit": False,
                        },
                    }
                },
            }

            success, failed = verifier.run_one(hyp, target, Path(temp_dir) / "out", dry_run=False)

        self.assertIsNone(failed)
        self.assertIsNotNone(success)
        assert success is not None
        self.assertEqual(success["status"], "stage_c_preserved")
        self.assertEqual(success["failure_code"], "UNSUPPORTED_ORACLE")
        self.assertEqual(success["stage_c_verdict"]["agent_verdict"], "vulnerability")

    def test_run_one_does_not_preserve_p2_on_unsupported_oracle(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            hyp = _hyp("P2")
            hyp.update({"routing_decision": "dynamic_verification", "agent_verdict": "vulnerability"})
            target = {
                "project_id": "p",
                "target_type": "source_api",
                "cases": {
                    "hyp_p2": {
                        "target_type": "source_api",
                        "attack_type": "generic",
                        "execution": {
                            "repo_path": temp_dir,
                            "test_cmd": (
                                f"{sys.executable} -c "
                                "\"print('MAGUS_ROUTE_EXECUTED'); "
                                "print('MAGUS_ORACLE_UNSUPPORTED')\""
                            ),
                        },
                        "oracle": {
                            "required_patterns": ["MAGUS_ROUTE_EXECUTED"],
                            "unsupported_patterns": ["MAGUS_ORACLE_UNSUPPORTED"],
                            "failure_code_patterns": {"NOT_EXPLOITABLE": ["MAGUS_NOT_CONFIRMED"]},
                            "expect_nonzero_exit": False,
                        },
                    }
                },
            }

            success, failed = verifier.run_one(hyp, target, Path(temp_dir) / "out", dry_run=False)

        self.assertIsNone(success)
        self.assertIsNotNone(failed)
        assert failed is not None
        self.assertEqual(failed["status"], "failed")
        self.assertEqual(failed["failure_code"], "UNSUPPORTED_ORACLE")
        self.assertEqual(failed["oracle_status"], "unsupported")
        self.assertEqual(failed["stage_c_verdict"]["priority"], "P2")

    def test_preserved_record_carries_stage_c_verdict(self):
        hyp = _semantic_hyp("P1")
        hyp.update({"routing_decision": "dynamic_verification", "agent_verdict": "vulnerability"})
        record = verifier.preserved_record(
            hyp,
            {"attack_type": "generic"},
            {"observations": ["unsupported oracle matched patterns: MAGUS_ORACLE_UNSUPPORTED"]},
            Path("payloads/hyp_p1.payload.py"),
            Path("payloads/hyp_p1.api-plan.json"),
        )

        self.assertEqual(record["status"], "stage_c_preserved")
        self.assertEqual(record["failure_code"], "UNSUPPORTED_ORACLE")
        self.assertEqual(record["severity"], "P1")
        self.assertEqual(record["stage_c_verdict"]["agent_verdict"], "vulnerability")
        self.assertEqual(record["semantic_family"], "network.cleartext_sensitive_transmission")

    def test_unstructured_unsupported_oracle_is_not_reportable(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            hyp = _hyp("P1")
            hyp.update({"routing_decision": "dynamic_verification", "agent_verdict": "vulnerability"})
            target = {
                "project_id": "p",
                "target_type": "source_api",
                "cases": {
                    "hyp_p1": {
                        "target_type": "source_api",
                        "attack_type": "generic",
                        "execution": {
                            "repo_path": temp_dir,
                            "test_cmd": (
                                f"{sys.executable} -c "
                                "\"print('MAGUS_ROUTE_EXECUTED'); "
                                "print('MAGUS_ORACLE_UNSUPPORTED')\""
                            ),
                        },
                        "oracle": {
                            "required_patterns": ["MAGUS_ROUTE_EXECUTED"],
                            "unsupported_patterns": ["MAGUS_ORACLE_UNSUPPORTED"],
                            "expect_nonzero_exit": False,
                        },
                    }
                },
            }

            success, failed = verifier.run_one(hyp, target, Path(temp_dir) / "out", dry_run=False)

        self.assertIsNone(success)
        self.assertIsNotNone(failed)
        assert failed is not None
        self.assertEqual(failed["failure_code"], "UNSUPPORTED_ORACLE")
        self.assertEqual(
            failed["preservation_policy"],
            "preserve_only_p0_p1_with_structured_semantic_contract",
        )


class GenericSourceApiRunnerTests(unittest.TestCase):
    def test_run_one_requires_route_marker_for_generic_oracle_match(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            hyp = _hyp("P1")
            target = {
                "project_id": "p",
                "target_type": "source_api",
                "cases": {
                    "hyp_p1": {
                        "target_type": "source_api",
                        "attack_type": "generic",
                        "execution": {
                            "repo_path": temp_dir,
                            "test_cmd": (
                                f"{sys.executable} -c "
                                "\"print('MAGUS_ORACLE_FLAW name=_putenv reason=tainted_search_path_environment')\""
                            ),
                        },
                        "oracle": {
                            "failure_patterns": [
                                "MAGUS_ORACLE_FLAW name=_putenv reason=tainted_search_path_environment"
                            ],
                            "required_patterns": ["MAGUS_ROUTE_EXECUTED"],
                            "expect_nonzero_exit": False,
                        },
                    }
                },
            }

            success, failed = verifier.run_one(hyp, target, Path(temp_dir) / "out", dry_run=False)

        self.assertIsNone(success)
        self.assertIsNotNone(failed)
        assert failed is not None
        self.assertEqual(failed["failure_code"], "NOT_ROUTE_BOUND")

    def test_run_one_confirms_generic_search_path_marker_when_route_bound(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            hyp = _hyp("P1")
            target = {
                "project_id": "p",
                "target_type": "source_api",
                "cases": {
                    "hyp_p1": {
                        "target_type": "source_api",
                        "attack_type": "generic",
                        "execution": {
                            "repo_path": temp_dir,
                            "test_cmd": (
                                f"{sys.executable} -c "
                                "\"import os; "
                                "print('MAGUS_ROUTE_EXECUTED route=' + os.environ['MAGUS_D_ROUTE']); "
                                "print('MAGUS_ORACLE_FLAW name=_putenv reason=tainted_search_path_environment')\""
                            ),
                        },
                        "oracle": {
                            "failure_patterns": [
                                "MAGUS_ORACLE_FLAW name=_putenv reason=tainted_search_path_environment"
                            ],
                            "required_patterns": ["MAGUS_ROUTE_EXECUTED"],
                            "expect_nonzero_exit": False,
                        },
                    }
                },
            }

            success, failed = verifier.run_one(hyp, target, Path(temp_dir) / "out", dry_run=False)

        self.assertIsNone(failed)
        self.assertIsNotNone(success)
        assert success is not None
        self.assertEqual(success["status"], "confirmed")

    def test_lifecycle_oracle_requires_capability_marker(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            hyp = _semantic_hyp("P1")
            hyp["semantic_family"] = "resource_lifecycle"
            hyp["semantic_contract"]["family"] = "resource_lifecycle"
            target = {
                "project_id": "p",
                "target_type": "source_api",
                "cases": {
                    "hyp_p1": {
                        "target_type": "source_api",
                        "attack_type": "generic",
                        "execution": {
                            "repo_path": temp_dir,
                            "test_cmd": (
                                f"{sys.executable} -c "
                                "\"print('MAGUS_ROUTE_EXECUTED'); "
                                "print('MAGUS_ORACLE_FLAW profile=resource.fd_lifecycle.user_posix reason=missing_release')\""
                            ),
                        },
                        "oracle": {
                            "failure_patterns": [
                                "MAGUS_ORACLE_FLAW profile=resource.fd_lifecycle.user_posix reason=missing_release"
                            ],
                            "required_patterns": ["MAGUS_ROUTE_EXECUTED"],
                            "capability_patterns": ["MAGUS_ORACLE_RAN profile=resource.fd_lifecycle.user_posix"],
                            "expect_nonzero_exit": False,
                        },
                    }
                },
            }

            success, failed = verifier.run_one(hyp, target, Path(temp_dir) / "out", dry_run=False)

        self.assertIsNone(failed)
        self.assertIsNotNone(success)
        assert success is not None
        self.assertEqual(success["status"], "stage_c_preserved")
        self.assertEqual(success["failure_code"], "UNSUPPORTED_ORACLE")

    def test_lifecycle_not_confirmed_marker_does_not_bypass_capability_marker(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            hyp = _semantic_hyp("P1")
            hyp["semantic_family"] = "resource_lifecycle"
            hyp["semantic_contract"]["family"] = "resource_lifecycle"
            target = {
                "project_id": "p",
                "target_type": "source_api",
                "cases": {
                    "hyp_p1": {
                        "target_type": "source_api",
                        "attack_type": "generic",
                        "execution": {
                            "repo_path": temp_dir,
                            "test_cmd": (
                                f"{sys.executable} -c "
                                "\"print('MAGUS_ROUTE_EXECUTED'); "
                                "print('MAGUS_NOT_CONFIRMED')\""
                            ),
                        },
                        "oracle": {
                            "failure_patterns": [
                                "MAGUS_ORACLE_FLAW profile=resource.fd_lifecycle.user_posix reason=missing_release"
                            ],
                            "required_patterns": ["MAGUS_ROUTE_EXECUTED"],
                            "capability_patterns": ["MAGUS_ORACLE_RAN profile=resource.fd_lifecycle.user_posix"],
                            "failure_code_patterns": {"NOT_EXPLOITABLE": ["MAGUS_NOT_CONFIRMED"]},
                            "expect_nonzero_exit": False,
                        },
                    }
                },
            }

            success, failed = verifier.run_one(hyp, target, Path(temp_dir) / "out", dry_run=False)

        self.assertIsNone(failed)
        self.assertIsNotNone(success)
        assert success is not None
        self.assertEqual(success["status"], "stage_c_preserved")
        self.assertEqual(success["failure_code"], "UNSUPPORTED_ORACLE")

    def test_lifecycle_oracle_confirms_when_capability_and_flaw_match(self):
        with tempfile.TemporaryDirectory() as temp_dir:
            hyp = _hyp("P1")
            target = {
                "project_id": "p",
                "target_type": "source_api",
                "cases": {
                    "hyp_p1": {
                        "target_type": "source_api",
                        "attack_type": "generic",
                        "execution": {
                            "repo_path": temp_dir,
                            "test_cmd": (
                                f"{sys.executable} -c "
                                "\"print('MAGUS_ROUTE_EXECUTED'); "
                                "print('MAGUS_ORACLE_RAN profile=resource.fd_lifecycle.user_posix'); "
                                "print('MAGUS_ORACLE_FLAW profile=resource.fd_lifecycle.user_posix reason=missing_release')\""
                            ),
                        },
                        "oracle": {
                            "failure_patterns": [
                                "MAGUS_ORACLE_FLAW profile=resource.fd_lifecycle.user_posix reason=missing_release"
                            ],
                            "required_patterns": ["MAGUS_ROUTE_EXECUTED"],
                            "capability_patterns": ["MAGUS_ORACLE_RAN profile=resource.fd_lifecycle.user_posix"],
                            "expect_nonzero_exit": False,
                        },
                    }
                },
            }

            success, failed = verifier.run_one(hyp, target, Path(temp_dir) / "out", dry_run=False)

        self.assertIsNone(failed)
        self.assertIsNotNone(success)
        assert success is not None
        self.assertEqual(success["status"], "confirmed")


if __name__ == "__main__":
    unittest.main()
