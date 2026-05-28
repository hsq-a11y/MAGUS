#!/usr/bin/env python3
import importlib.util
import io
import json
import sys
import types
import unittest
from pathlib import Path


class _OpenAIStub:
    def __init__(self, *args, **kwargs):
        pass


def _load_agent1():
    sys.modules.setdefault("openai", types.SimpleNamespace(OpenAI=_OpenAIStub))
    module_path = Path(__file__).with_name("agent1.py")
    spec = importlib.util.spec_from_file_location("agent1_for_routing_tests", module_path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


agent1 = _load_agent1()


def _candidate(
    sample_id="s",
    route="file.c::target",
    file="file.c",
    line=10,
    evidence_slice="call:sink",
    static_supported=True,
):
    return {
        "project_id": "p",
        "sample_id": sample_id,
        "route": route,
        "file": file,
        "line": line,
        "evidence_slice": evidence_slice,
        "stage_b": {
            "static_confirmation_support": {
                "supported": static_supported,
                "reason": "high_risk_sink",
                "guidance": "allow_p0_if_a_evidence_proves_source_sink_route",
            }
        },
    }


def _vuln(confidence=0.8, evidence_complete=True):
    return {
        "claim": "externally controlled data reaches a configuration sink",
        "cwe_candidates": ["CWE-15"],
        "trigger_path": [{"step": 1, "loc": "file.c:10", "code": "sink(data);"}],
        "confidence": confidence,
        "evidence_complete": evidence_complete,
    }


def _no_vuln(**extra):
    resp = {
        "claim": "NO_VULNERABILITY_FOUND",
        "cwe_candidates": [],
        "trigger_path": [],
        "confidence": 0.0,
        "evidence_complete": True,
    }
    resp.update(extra)
    return resp


def _llm_error():
    return {
        "claim": "LLM_CALL_FAILED",
        "confidence": 0.0,
        "llm_error": "api_error",
        "llm_error_detail": "test failure",
    }


class RouteRecordTests(unittest.TestCase):
    def test_all_no_vulnerability_routes_to_p3(self):
        _, priority, verdict, reason, _ = agent1.route_record(
            _candidate(), [_no_vuln(), _no_vuln(), _no_vuln()]
        )
        self.assertEqual((priority, verdict, reason), ("P3", "audit_only", "multi_agent_no_vulnerability"))

    def test_llm_errors_do_not_count_as_no_vulnerability_consensus(self):
        _, priority, verdict, reason, _ = agent1.route_record(
            _candidate(), [_llm_error(), _llm_error(), _llm_error()]
        )
        self.assertEqual((priority, verdict, reason), ("P3", "audit_only", "stage_c_llm_error"))

    def test_disputed_vulnerability_does_not_route_to_p3(self):
        _, priority, verdict, reason, contradictions = agent1.route_record(
            _candidate(),
            [
                _vuln(),
                _no_vuln(hard_contradictions=["sink not shown"]),
                _no_vuln(stability="hard_contradiction"),
            ],
        )
        self.assertEqual((priority, verdict, reason), ("P2", "candidate_for_d", "multi_agent_vulnerability_once"))
        self.assertIn("sink not shown", contradictions)

    def test_final_rejection_after_vulnerability_routes_to_p2(self):
        _, priority, verdict, reason, _ = agent1.route_record(
            _candidate(), [_vuln(evidence_complete=False), _vuln(evidence_complete=False), _no_vuln()]
        )
        self.assertEqual((priority, verdict, reason), ("P2", "candidate_for_d", "multi_agent_vulnerability_once"))

    def test_partial_llm_error_with_vulnerability_routes_to_p2(self):
        _, priority, verdict, reason, _ = agent1.route_record(
            _candidate(), [_vuln(), _llm_error(), _vuln()]
        )
        self.assertEqual((priority, verdict, reason), ("P2", "candidate_for_d", "stage_c_partial_llm_error"))

    def test_corrected_vulnerability_routes_to_p1_when_final_two_rounds_agree(self):
        _, priority, verdict, reason, _ = agent1.route_record(
            _candidate(), [_no_vuln(), _vuln(), _vuln()]
        )
        self.assertEqual((priority, verdict, reason), ("P1", "candidate_for_d", "corrected_to_vulnerability"))

    def test_final_vulnerability_after_rebuttal_routes_to_p1(self):
        _, priority, verdict, reason, _ = agent1.route_record(
            _candidate(), [_vuln(), _no_vuln(), _vuln()]
        )
        self.assertEqual(
            (priority, verdict, reason),
            ("P1", "candidate_for_d", "red_rebuttal_after_blue_challenge"),
        )

    def test_complete_consensus_vulnerability_can_route_to_p0(self):
        _, priority, verdict, reason, _ = agent1.route_record(
            _candidate(), [_vuln(0.95), _vuln(0.95), _vuln(0.95)]
        )
        self.assertEqual((priority, verdict, reason), ("P0", "static_confirmed", "multi_agent_static_strong"))

    def test_stage_b_static_confirmation_block_routes_to_d_candidate(self):
        cand = _candidate()
        cand["stage_b"]["static_confirmation_support"]["supported"] = False
        cand["stage_b"]["static_confirmation_support"]["reason"] = "no_missing_feature_no_deviation_low_sink"
        _, priority, verdict, reason, _ = agent1.route_record(
            cand, [_vuln(0.95), _vuln(0.95), _vuln(0.95)]
        )
        self.assertEqual(
            (priority, verdict, reason),
            ("P1", "candidate_for_d", "stage_b_static_confirmation_unsupported"),
        )

    def test_source_api_safety_net_routes_unguarded_impersonation_to_d(self):
        cand = _candidate(
            evidence_slice='\n'.join(
                [
                    "ImpersonateNamedPipeClient(hPipe);",
                    'printLine("Impersonated");',
                    "if (!RevertToSelf())",
                    "{",
                    "    exit(1);",
                    "}",
                ]
            )
        )

        selected, priority, verdict, reason, _ = agent1.route_record(
            cand, [_no_vuln(), _no_vuln(), _no_vuln()]
        )

        self.assertEqual((priority, verdict, reason), ("P1", "candidate_for_d", "source_api_semantic_safety_net"))
        self.assertIn("ImpersonateNamedPipeClient", selected["claim"])
        self.assertEqual(selected["cwe_candidates"], [])

    def test_source_api_safety_net_does_not_route_guarded_impersonation(self):
        cand = _candidate(
            evidence_slice='\n'.join(
                [
                    "if (!ImpersonateNamedPipeClient(hPipe))",
                    "{",
                    '    printLine("Failed to impersonate");',
                    "}",
                    "else",
                    "{",
                    '    printLine("Impersonated");',
                    "    if (!RevertToSelf())",
                    "    {",
                    "        exit(1);",
                    "    }",
                    "}",
                ]
            )
        )

        _, priority, verdict, reason, _ = agent1.route_record(
            cand, [_no_vuln(), _no_vuln(), _no_vuln()]
        )

        self.assertEqual((priority, verdict, reason), ("P3", "audit_only", "multi_agent_no_vulnerability"))

    def test_source_api_safety_net_routes_rpc_without_cwe_label(self):
        cand = _candidate(
            evidence_slice="RpcImpersonateClient(0); /* unchecked failure return */"
        )

        selected, priority, verdict, reason, _ = agent1.route_record(
            cand, [_no_vuln(), _no_vuln(), _no_vuln()]
        )

        self.assertEqual((priority, verdict, reason), ("P1", "candidate_for_d", "source_api_semantic_safety_net"))
        self.assertIn("RpcImpersonateClient", selected["claim"])
        self.assertEqual(selected["cwe_candidates"], [])


class OutputRoutingTests(unittest.TestCase):
    def _p0_record(self):
        return {
            "project_id": "p",
            "sample_id": "s",
            "hypothesis_id": "hyp_s",
            "priority": "P0",
            "agent_verdict": "static_confirmed",
            "routing_decision": "static_confirmed",
            "route": "file.c::target",
            "file": "file.c",
            "line": 10,
            "evidence_slice": "call:sink",
            "status": "static_confirmed",
            "d_verification": "pending_routing_decision",
        }

    def test_p0_goes_to_d(self):
        d_file, audit_file = io.StringIO(), io.StringIO()
        bucket, usage_events = agent1.process_completed_future(
            agent1.CompletedFuture(self._p0_record()),
            _candidate(),
            d_file,
            audit_file,
        )
        self.assertEqual(bucket, "p0_d")
        self.assertEqual(usage_events, [])
        self.assertEqual(audit_file.getvalue(), "")
        row = json.loads(d_file.getvalue())
        self.assertEqual(row["status"], "pending_dynamic_verification")
        self.assertEqual(row["d_verification"], "pending")
        self.assertEqual(row["stage_c_p0_routing"], "sent_to_d")

    def test_p3_goes_to_audit(self):
        record = self._p0_record()
        record["priority"] = "P3"
        record["agent_verdict"] = "audit_only"
        record["routing_decision"] = "audit_only"
        d_file, audit_file = io.StringIO(), io.StringIO()
        bucket, usage_events = agent1.process_completed_future(
            agent1.CompletedFuture(record),
            _candidate(),
            d_file,
            audit_file,
        )
        self.assertEqual(bucket, "audit")
        self.assertEqual(usage_events, [])
        self.assertEqual(d_file.getvalue(), "")
        row = json.loads(audit_file.getvalue())
        self.assertEqual(row["priority"], "P3")
        self.assertEqual(row["routing_decision"], "audit_only")

    def test_llm_usage_event_records_cache_counters(self):
        events = []
        response = types.SimpleNamespace(
            usage={
                "prompt_tokens": 100,
                "completion_tokens": 10,
                "total_tokens": 110,
                "prompt_cache_hit_tokens": 80,
                "prompt_cache_miss_tokens": 20,
            }
        )
        context = agent1.llm_usage_context(
            _candidate(),
            1,
            "red",
            "red_proposer",
            "PROPOSER_PROMPT",
            agent1.PROPOSER_PROMPT,
        )

        agent1.record_llm_usage_event(events, context, "static prefix\ncandidate evidence", 0, "success", response)

        self.assertEqual(len(events), 1)
        self.assertEqual(events[0]["prompt_cache_hit_tokens"], 80)
        self.assertEqual(events[0]["prompt_cache_miss_tokens"], 20)
        self.assertEqual(events[0]["prompt_cache_hit_rate"], 0.8)
        summary = agent1.usage_summary(events)
        self.assertEqual(summary["calls"], 1)
        self.assertEqual(summary["prompt_cache_hit_tokens"], 80)
        self.assertEqual(summary["prompt_cache_miss_tokens"], 20)
        self.assertEqual(summary["prompt_cache_hit_rate"], 0.8)

    def test_prompt_static_prefix_is_before_dynamic_inputs(self):
        cases = [
            (
                agent1.PROPOSER_PROMPT,
                {"evidence_brief": "route A evidence"},
                {"evidence_brief": "route B evidence"},
            ),
            (
                agent1.BLUE_CHALLENGER_PROMPT,
                {"evidence_brief": "route A evidence", "proposer_json": '{"claim":"A"}'},
                {"evidence_brief": "route B evidence", "proposer_json": '{"claim":"B"}'},
            ),
            (
                agent1.RED_REBUTTAL_PROMPT,
                {
                    "evidence_brief": "route A evidence",
                    "proposer_json": '{"claim":"A"}',
                    "challenger_json": '{"challenge":"A"}',
                },
                {
                    "evidence_brief": "route B evidence",
                    "proposer_json": '{"claim":"B"}',
                    "challenger_json": '{"challenge":"B"}',
                },
            ),
        ]
        for template, first_values, second_values in cases:
            with self.subTest(template=template.splitlines()[0]):
                static_prefix = agent1.template_static_prefix(template)
                self.assertGreater(len(static_prefix), 1000)
                first_prompt = template.format(**first_values)
                second_prompt = template.format(**second_values)
                self.assertTrue(first_prompt.startswith(static_prefix))
                self.assertTrue(second_prompt.startswith(static_prefix))
                self.assertEqual(first_prompt[: len(static_prefix)], second_prompt[: len(static_prefix)])
                self.assertNotIn("route A evidence", static_prefix)
                self.assertNotIn("route B evidence", static_prefix)


if __name__ == "__main__":
    unittest.main()
