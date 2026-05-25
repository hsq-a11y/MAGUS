#!/usr/bin/env python3
# agent1.py - C阶段：双Agent对抗审计，输出给D阶段验证的漏洞假设和路由
# 优化点：并发处理、流式写入、证据精简、结果缓存

import argparse
import json
import multiprocessing as mp
import os
import queue
import re
import time
from json import JSONDecodeError
from datetime import datetime, timezone
from pathlib import Path

from openai import OpenAI

# ==================== 配置（可根据实际情况调整）====================
MODEL_NAME = os.environ.get("DEEPSEEK_MODEL", "deepseek-v4-flash")
BASE_URL = os.environ.get("DEEPSEEK_BASE_URL", "https://api.deepseek.com/v1")
API_KEY_ENV_VARS = ("DEEPSEEK_API_KEY", "OPENAI_API_KEY")
CONFIDENCE_THRESHOLD = 0.60               # 放宽到0.60，让更多假设进入D阶段（原0.65）
STATIC_CONFIDENCE_THRESHOLD = 0.90        # P0：静态强确认；已完成结果进入D做route-bound验证
MAX_WORKERS = 5                           # 并发线程数，平衡速度与稳定性
LLM_MAX_OUTPUT_TOKENS = 4096              # max_tokens只限制模型输出长度，不扩大输入上下文
LLM_REQUEST_TIMEOUT_SECONDS = 60.0        # 单次LLM请求上限，会被全局deadline进一步收紧
LLM_JSON_RETRY_ATTEMPTS = 1               # JSON解析失败后额外重试次数
POST_DEADLINE_GRACE_SECONDS = 5.0         # 到达提交预算后等待已完成结果的宽限时间
WORKER_RESULT_DRAIN_GRACE_SECONDS = 0.2   # worker刚退出时等待Queue结果刷新的边界窗口
EVIDENCE_TEXT_MAX_CHARS = 1200            # 单段证据文本最多保留字符数
MAX_CALL_CHAIN = 12                       # 调用序列最多保留个数
MAX_SINK_SOURCE = 5                       # source/sink、trace、代码片段最多保留个数
MAX_INTERNAL_SUMMARIES = 3                # 内部函数摘要最多保留个数
C_READY_SCHEMA_VERSION = "stageb.c_ready_candidates.v3"

_client = None


def configured_api_key():
    for name in API_KEY_ENV_VARS:
        value = os.environ.get(name, "").strip()
        if value:
            return value
    raise RuntimeError("Stage C requires DEEPSEEK_API_KEY or OPENAI_API_KEY")


def llm_client():
    global _client
    if _client is None:
        _client = OpenAI(api_key=configured_api_key(), base_url=BASE_URL, timeout=60, max_retries=0)
    return _client


# ==================== 数据加载模块 ====================
def parse_args():
    parser = argparse.ArgumentParser(description="C阶段：基于B阶段C-ready候选执行双Agent审计")
    parser.add_argument("--candidates", default="data/candidates.for_c.jsonl", help="B阶段输出的 candidates.for_c.jsonl")
    parser.add_argument("--output", default="data/hypotheses.jsonl", help="C阶段输出给D验证的 hypotheses.jsonl")
    parser.add_argument("--audit-output", default="", help="P3和错误审计日志；默认从 --output 推导")
    parser.add_argument("--time-limit-seconds", type=float, default=None, help="C阶段提交候选的时间预算；默认不限制")
    return parser.parse_args()


def utc_now():
    return datetime.now(timezone.utc).replace(microsecond=0).isoformat().replace("+00:00", "Z")


def default_side_output(output_path: Path, subdir: str, filename: str) -> Path:
    if output_path.parent.name == "out":
        return output_path.parent.parent / subdir / filename
    return output_path.with_name(f"{output_path.stem}.{filename}")


def read_jsonl(path):
    records = []
    with open(path, encoding="utf-8") as f:
        for line_no, line in enumerate(f, 1):
            line = line.strip()
            if not line:
                continue
            try:
                records.append(json.loads(line))
            except json.JSONDecodeError as exc:
                raise ValueError(f"{path}:{line_no}: invalid JSON: {exc}") from exc
    return records


def require_candidate_field(cand, path, index, field):
    value = cand.get(field)
    if value in (None, "", []):
        raise ValueError(f"{path}: candidate #{index} missing required field {field}")
    return value


def require_candidate_key(cand, path, index, field):
    if field not in cand:
        raise ValueError(f"{path}: candidate #{index} missing required field {field}")
    return cand.get(field)


def validate_candidate(cand, path, index):
    if not isinstance(cand, dict):
        raise ValueError(f"{path}: candidate #{index} must be an object")
    schema = require_candidate_field(cand, path, index, "schema_version")
    if schema != C_READY_SCHEMA_VERSION:
        raise ValueError(f"{path}: candidate #{index} unsupported schema_version {schema!r}")
    for field in ("project_id", "sample_id", "llm_evidence", "stage_b"):
        require_candidate_field(cand, path, index, field)
    for field in ("route", "file", "evidence_slice"):
        value = require_candidate_key(cand, path, index, field)
        if not isinstance(value, str):
            raise ValueError(f"{path}: candidate #{index} {field} must be a string")
    if not isinstance(cand.get("line"), int):
        raise ValueError(f"{path}: candidate #{index} line must be an integer")
    llm = cand.get("llm_evidence")
    if not isinstance(llm, dict):
        raise ValueError(f"{path}: candidate #{index} llm_evidence must be an object")
    if llm.get("sample_id") != cand.get("sample_id"):
        raise ValueError(
            f"{path}: candidate #{index} llm_evidence sample_id does not match candidate sample_id"
        )
    if not isinstance(cand.get("stage_b"), dict):
        raise ValueError(f"{path}: candidate #{index} stage_b must be an object")
    if not isinstance(cand.get("c_priority_score"), (int, float)) or isinstance(cand.get("c_priority_score"), bool):
        raise ValueError(f"{path}: candidate #{index} c_priority_score must be a number")
    if not isinstance(cand.get("c_priority_components"), dict):
        raise ValueError(f"{path}: candidate #{index} c_priority_components must be an object")
    if not isinstance(cand["stage_b"].get("c_priority_score"), (int, float)) or isinstance(
        cand["stage_b"].get("c_priority_score"), bool
    ):
        raise ValueError(f"{path}: candidate #{index} stage_b.c_priority_score must be a number")
    if not isinstance(cand["stage_b"].get("c_priority_components"), dict):
        raise ValueError(f"{path}: candidate #{index} stage_b.c_priority_components must be an object")
    static_support = cand["stage_b"].get("static_confirmation_support")
    if not isinstance(static_support, dict):
        raise ValueError(f"{path}: candidate #{index} stage_b.static_confirmation_support must be an object")
    if not isinstance(static_support.get("supported"), bool):
        raise ValueError(
            f"{path}: candidate #{index} stage_b.static_confirmation_support.supported must be a boolean"
        )


def load_candidates(path):
    """加载B阶段已合并LLM证据并排序的候选队列。"""
    candidates = read_jsonl(path)
    for index, cand in enumerate(candidates, 1):
        validate_candidate(cand, path, index)
    return candidates


# ==================== 证据文本构建模块（精简版） ====================
def compact_text(value, max_chars=EVIDENCE_TEXT_MAX_CHARS):
    text = " ".join(str(value or "").split())
    if len(text) <= max_chars:
        return text
    return text[:max_chars] + "..."


def bool_text(value):
    return "true" if bool(value) else "false"


def format_missing_feature(feature):
    token = feature.get("token", "?")
    support = feature.get("support", 0.0)
    support_count = feature.get("support_count", 0)
    group_size = feature.get("group_size", 0)
    weight = feature.get("weight", 0.0)
    refs = ", ".join(str(item) for item in feature.get("reference_sample_ids", [])[:3])
    suffix = f" refs=[{refs}]" if refs else ""
    return f"{token} support={support:.2f} count={support_count}/{group_size} weight={weight:.2f}{suffix}"


def build_evidence_brief(cand):
    """
    为大模型构建精简但完整的审计证据。
    输入来自B阶段以LLM证据为主体、按route聚合增强的candidates.for_c.jsonl。
    """
    sample_id = cand.get("sample_id")
    llm = cand.get("llm_evidence", {})
    stage_b = cand.get("stage_b", {})

    lines = []
    lines.append(f"项目:{cand.get('project_id','?')} 样本:{sample_id}")
    lines.append(f"路由:{cand.get('route','?')}")

    ep = llm.get("entrypoint", {})
    entry_desc = []
    if ep.get("file"):
        entry_desc.append(str(ep.get("file")))
    if ep.get("function"):
        entry_desc.append(f"::{ep.get('function')}")
    if ep.get("line"):
        entry_desc.append(f":{ep.get('line')}")
    if entry_desc:
        lines.append(f"入口:{''.join(entry_desc)}")

    focus = llm.get("focus", {})
    focus_file = focus.get("file") or cand.get("file", "?")
    focus_line = focus.get("line") or cand.get("line", 0)
    lines.append(f"位置:{focus_file}:{focus_line}")
    if cand.get("evidence_slice"):
        lines.append(f"A阶段合并证据:{compact_text(cand.get('evidence_slice'))}")
    lines.append(
        "B阶段门禁:"
        f" threshold_pass={bool_text(cand.get('threshold_pass'))}"
        f" risk_threshold={float(cand.get('risk_threshold', 0.0)):.2f}"
        f" risk_score={float(cand.get('risk_score', 0.0)):.2f}"
        f" missing_feature_count={int(cand.get('missing_feature_count', 0) or 0)}"
        f" route_candidate_count={int(stage_b.get('candidate_count', 0) or 0)}"
    )
    lines.append(
        "B阶段排序:"
        f" rank={cand.get('processing_rank','?')}"
        f" basis={cand.get('priority_basis', {})}"
    )
    lines.append(
        f"B阶段分数: rarity={cand.get('rarity_score',0.0):.2f}"
        f" sink={cand.get('sink_score',0.0):.2f}"
        f" deviation={cand.get('pattern_deviation_score',0.0):.2f}"
    )
    static_support = stage_b.get("static_confirmation_support", {})
    if static_support:
        lines.append(
            "B阶段P0静态确认支持:"
            f" supported={bool_text(static_support.get('supported'))}"
            f" reason={static_support.get('reason','?')}"
            f" guidance={static_support.get('guidance','?')}"
        )
    seed_tokens = stage_b.get("seed_tokens", [])
    if seed_tokens:
        lines.append(f"B阶段route内API种子:{', '.join(str(item) for item in seed_tokens[:MAX_CALL_CHAIN])}")
    top_candidates = stage_b.get("top_candidates", [])
    for item in top_candidates[:MAX_SINK_SOURCE]:
        lines.append(
            "B阶段候选:"
            f" sample={item.get('sample_id','?')}"
            f" seed={item.get('seed_token','?')}"
            f" line={item.get('file','?')}:{item.get('line','?')}"
            f" risk={float(item.get('risk_score', 0.0)):.2f}"
        )
    missing_features = stage_b.get("missing_features", [])
    if missing_features:
        lines.append("B阶段缺失高频feature:")
        for feature in missing_features[:MAX_SINK_SOURCE]:
            lines.append(f"- {format_missing_feature(feature)}")
    refs = stage_b.get("reference_sample_ids", [])
    if refs:
        lines.append(f"B阶段参考样本:{', '.join(str(item) for item in refs[:5])}")

    # A阶段代表性source-sink流
    flows = llm.get("source_sink_flows", [])
    for flow in flows[:MAX_SINK_SOURCE]:
        source_token = flow.get("source_token", flow.get("source_id", ""))
        sink_token = flow.get("sink_token", flow.get("sink_id", ""))
        status = flow.get("status", "")
        flow_kind = flow.get("flow_kind", "")
        lines.append(f"流:{source_token}->{sink_token} status={status} kind={flow_kind}")

    # A阶段代表性trace
    traces = llm.get("representative_traces", [])
    for trace in traces[:MAX_SINK_SOURCE]:
        tokens = trace.get("tokens", [])
        if tokens:
            lines.append(f"Trace:{' -> '.join(tokens[:MAX_CALL_CHAIN])}")
        if trace.get("evidence_slice"):
            lines.append(f"Trace证据:{compact_text(trace.get('evidence_slice'))}")

    # A阶段代码片段
    code_slices = llm.get("code_slices", [])
    for item in code_slices[:MAX_SINK_SOURCE]:
        roles = ",".join(item.get("roles", []))
        loc = f"{item.get('file','?')}:{item.get('line_start','?')}-{item.get('line_end','?')}"
        lines.append(f"代码片段[{roles}] {loc}: {compact_text(item.get('text'))}")

    # A阶段内部函数摘要
    summaries = llm.get("internal_function_summaries", [])
    for item in summaries[:MAX_INTERNAL_SUMMARIES]:
        loc = f"{item.get('file','?')}:{item.get('line_start','?')}-{item.get('line_end','?')}"
        calls = " -> ".join(item.get("calls", [])[:MAX_CALL_CHAIN])
        lines.append(f"函数:{item.get('function','?')} {loc} 调用:{calls}")
        excerpt = (item.get("excerpt") or {}).get("text", "")
        if excerpt:
            lines.append(f"函数证据:{compact_text(excerpt)}")

    lines.append(f"标签:{', '.join(stage_b.get('reason_tags', cand.get('reason_tags', [])))}")

    return "\n".join(lines)


# ==================== 双Agent三轮对抗提示词 ====================
PROPOSER_PROMPT = """你是一位红队安全审计专家。基于以下代码证据，高召回判断是否存在安全漏洞。

**审计信息**：
{evidence_brief}

**任务**：
- 必须按两步判断：第一步判断代码是否违反 C/C++ API contract 或 CWE 定义；第二步单独判断可利用性、影响范围和风险高低。
- 如果存在 API contract/CWE 违反（例如返回值 sentinel 检查错误、失败返回未传播、成功/失败条件反了），即使影响较低或可利用性不确定，也必须输出漏洞假设；把影响不确定写进 claim、preconditions 或 confidence，不要输出 "NO_VULNERABILITY_FOUND"。
- 只有在确认既没有 API contract/CWE 违反、也没有其它安全问题时，才输出 "NO_VULNERABILITY_FOUND"。
- 如果存在安全漏洞或 API misuse（如缓冲区溢出、整数溢出、空指针解引用、权限缺失、SQL注入、错误返回值检查等），输出漏洞描述、CWE编号、**假设条件集合**、**触发路径**、攻击前提条件，以及对漏洞存在的置信度（0~1）。
- B阶段门禁和缺失feature是审计优先级/反幻觉约束，不是漏洞结论。必须用代码证据证明source、sink和可达路径；不得仅凭risk_score、threshold_pass或文件名推断漏洞。
- 对 source/sink 型漏洞，必须证明 source、sink 和可达路径；对 API contract misuse，必须证明同一路由上的 API 调用及其错误检查/处理语义，不能因为后续崩溃或攻击后果不明显就否定 contract violation。
- 如果threshold_pass=false或缺失feature为空，仍可报告漏洞，但必须有更强的A阶段代码证据；否则降低confidence或标记evidence_complete=false。
- 如果B阶段P0静态确认支持为supported=false，不要给出可触发P0静态强确认的高置信结论；除非A阶段代码证据直接闭合攻击者可控source到安全敏感sink的同一路由，否则应降低confidence或标记evidence_complete=false。

**输出格式（严格JSON）**：
{{
  "claim": "漏洞描述，无漏洞写'NO_VULNERABILITY_FOUND'",
  "cwe_candidates": ["CWE-XXX"],
  "hypothesis_conditions": [
    {{"id": "A1", "description": "假设条件"}}
  ],
  "trigger_path": [
    {{"step": 1, "loc": "L? 或 描述", "code": "关键代码行"}}
  ],
  "preconditions": ["攻击者能够控制某个输入或参数"],
  "confidence": 0.8,
  "hard_contradictions": [],
  "evidence_complete": true
}}

**注意**：即使代码中可能存在防御检查，你也必须输出假设条件和路径，不要提前过滤。影响较弱只能降低风险/置信度，不能把明确的 API contract violation 改判为无漏洞。"""

BLUE_CHALLENGER_PROMPT = """你是独立蓝队复审专家。请严格挑战红队第一轮判断，寻找误报、漏报和证据缺口。

**代码证据**：
{evidence_brief}

**第一轮判断**：
{proposer_json}

**任务**：
- 如果红队已发现漏洞，检查 source/sink 或 API misuse 路径是否真实、是否可达、是否引用了不存在的代码，且是否被防御检查、错误处理、常量输入或安全路径阻断。
- 如果红队判断为 NO_VULNERABILITY_FOUND，必须主动挑战这个结论；只要代码证据中存在具体可验证的漏洞路径或 source/API misuse 路径，就输出修正后的漏洞假设。
- 复审时必须先判断 API contract/CWE 定义是否被违反，再判断影响和可利用性。缓冲区已初始化、后续只打印、影响较低等事实只能影响风险等级和confidence，不能否定明确的错误返回值检查或其它 API contract violation。
- 只有发现硬矛盾（路径不可达、sink不存在、source和sink不连通、把安全路径当漏洞路径等）时，才列入 hard_contradictions。
- 使用B阶段门禁、缺失feature和参考样本约束红队判断：这些信号只能说明优先级或异常模式，不能替代真实代码路径。
- 如果B阶段P0静态确认支持为supported=false，必须检查红队是否把安全路径、固定字符串、错误处理或注释文字当成外部可控漏洞路径；代码证据不闭合时降低confidence或标记evidence_complete=false。

**输出格式（严格JSON）**：
{{
  "claim": "蓝队修正后的漏洞描述，无漏洞写'NO_VULNERABILITY_FOUND'",
  "cwe_candidates": ["CWE-XXX"],
  "trigger_path": [
    {{"step": 1, "loc": "L? 或 描述", "code": "关键代码行"}}
  ],
  "preconditions": ["攻击者能够控制某个输入或参数"],
  "confidence": 0.8,
  "condition_checks": [
    {{"condition_id": "A1", "status": "valid|contradicted|plausible", "reason": "依据"}}
  ],
  "guard_checks": [
    {{"target_step": 1, "guard_location": "L?", "guard_code": "防御代码或空字符串", "reason": "依据"}}
  ],
  "hard_contradictions": [],
  "evidence_complete": true,
  "challenge_notes": "蓝队审查结论"
}}"""

RED_REBUTTAL_PROMPT = """你是红队回应者。请回应蓝队挑战，输出可用于分流的最终漏洞假设。

**代码证据**：
{evidence_brief}

**第一轮判断**：
{proposer_json}

**第二轮蓝队挑战**：
{challenger_json}

**分流要求**：
- 如果存在可验证漏洞路径或 API contract/CWE violation，输出具体漏洞假设。
- 如果代码确实违反 API contract/CWE 定义，但可利用性或后果较弱，保留漏洞假设并在 claim/final_notes 中说明影响较低或需要 D 验证；不要输出 NO_VULNERABILITY_FOUND。
- 只有确认既不存在 contract violation，也不存在其它安全问题时，输出 NO_VULNERABILITY_FOUND。
- 如果发现硬矛盾，写入 hard_contradictions。
- 如果蓝队指出红队误报，必须用代码证据回应；无法回应时接受蓝队结论或降为证据不完整。
- 如果蓝队指出红队漏报，且代码证据支持该路径，必须采纳为最终漏洞假设。
- 不要输出 HTTP/base_url/token/*.http 等Web验证内容；这里的API指C/C++函数调用接口或调用序列。
- 最终结论必须说明得通A阶段代码证据和B阶段结构信号；当代码证据不闭合但仍有漏洞可能时，保留漏洞假设并标记 evidence_complete=false，不要把不确定性伪装成已确认无漏洞。
- 如果B阶段P0静态确认支持为supported=false，最终结果不得伪装成静态强确认；只有A阶段代码证据明确证明同一路由source到sink闭合时才可保持高置信，否则输出动态验证候选所需的不完整证据状态。

**输出格式（严格JSON）**：
{{
  "claim": "最终漏洞描述或NO_VULNERABILITY_FOUND",
  "cwe_candidates": ["CWE-XXX"],
  "trigger_path": [
    {{"step": 1, "loc": "L? 或 描述", "code": "关键代码行"}}
  ],
  "preconditions": ["攻击者能够控制某个输入或参数"],
  "confidence": 0.8,
  "hard_contradictions": [],
  "evidence_complete": true,
  "stability": "stable_vulnerability|corrected_to_vulnerability|reaffirmed_after_blue_challenge|unstable_vulnerability|no_vulnerability|hard_contradiction",
  "final_notes": "红队回应说明"
}}"""


# ==================== LLM调用与假设构建模块 ====================
def remaining_seconds(deadline):
    if deadline is None:
        return None
    return deadline - time.monotonic()


def has_time_remaining(deadline, min_seconds=1.0):
    remaining = remaining_seconds(deadline)
    return remaining is None or remaining > min_seconds


def llm_failure(error_type, detail):
    return {
        "claim": "LLM_CALL_FAILED",
        "confidence": 0.0,
        "llm_error": error_type,
        "llm_error_detail": detail,
    }


def response_preview(content, limit=500):
    return " ".join(str(content or "").split())[:limit]


def parse_llm_json(content):
    if content is None:
        raise ValueError("empty_response")
    if not str(content).strip():
        raise ValueError("empty_response")
    return json.loads(content)


def call_llm(prompt, deadline=None):
    """调用大模型API，返回解析后的JSON字典。max_tokens限制输出长度，不控制输入长度。"""
    timeout = LLM_REQUEST_TIMEOUT_SECONDS
    remaining = remaining_seconds(deadline)
    if remaining is not None:
        if remaining <= 1.0:
            print("LLM调用跳过: time budget exhausted")
            return llm_failure("time_budget_exhausted_before_call", "remaining<=1s")
        timeout = max(1.0, min(timeout, remaining))

    last_failure = None
    for attempt in range(LLM_JSON_RETRY_ATTEMPTS + 1):
        if not has_time_remaining(deadline):
            return llm_failure("time_budget_exhausted_before_retry", f"attempt={attempt}")
        try:
            request_client = llm_client().with_options(timeout=timeout)
            r = request_client.chat.completions.create(
                model=MODEL_NAME,
                messages=[{"role": "user", "content": prompt}],
                response_format={"type": "json_object"},
                max_tokens=LLM_MAX_OUTPUT_TOKENS,
                temperature=0.0
            )
            content = r.choices[0].message.content
            try:
                return parse_llm_json(content)
            except JSONDecodeError as exc:
                last_failure = llm_failure(
                    "invalid_json_response",
                    f"{exc}; preview={response_preview(content)}",
                )
                print(f"LLM JSON解析失败 attempt={attempt}: {exc}")
            except ValueError as exc:
                last_failure = llm_failure(str(exc), f"attempt={attempt}")
                print(f"LLM返回为空 attempt={attempt}: {exc}")
        except Exception as exc:
            last_failure = llm_failure("api_error", str(exc))
            print(f"LLM调用失败 attempt={attempt}: {exc}")
            break
    return last_failure


def response_claim(resp):
    if not isinstance(resp, dict):
        return ""
    return str(resp.get("claim") or resp.get("final_claim") or "")


def response_confidence(resp, default=0.0):
    if not isinstance(resp, dict):
        return default
    for key in ("confidence", "final_confidence", "adjusted_confidence"):
        value = resp.get(key)
        if value in (None, ""):
            continue
        try:
            return float(value)
        except (TypeError, ValueError):
            continue
    return default


def response_cwes(resp):
    if not isinstance(resp, dict):
        return []
    value = resp.get("cwe_candidates") or resp.get("CWE_candidates") or resp.get("cwe_list") or []
    if isinstance(value, list):
        return value
    if value:
        return [value]
    return []


def has_llm_error(resp):
    return isinstance(resp, dict) and bool(resp.get("llm_error"))


def no_vulnerability_claim(claim):
    text = " ".join(str(claim or "").split()).lower()
    markers = [
        "no_vulnerability_found",
        "no vulnerability",
        "not a vulnerability",
        "无漏洞",
        "不存在漏洞",
        "没有漏洞",
    ]
    return not text or any(marker in text for marker in markers)


def is_vulnerability_response(resp):
    if has_llm_error(resp):
        return False
    claim = response_claim(resp)
    return bool(claim) and not no_vulnerability_claim(claim)


def hard_contradictions(resp):
    if not isinstance(resp, dict):
        return []
    result = []
    for key in ("hard_contradictions", "contradictions", "blocking_guards"):
        value = resp.get(key)
        if value in (None, "", []):
            continue
        if isinstance(value, list):
            result.extend(value)
        else:
            result.append(value)
    stability = str(resp.get("stability") or "").lower()
    if stability == "hard_contradiction" and not result:
        result.append("stability=hard_contradiction")
    return result


def trigger_path_items(resp):
    if not isinstance(resp, dict):
        return []
    value = resp.get("trigger_path") or resp.get("attack_path") or []
    if isinstance(value, list):
        return value
    if value:
        return [value]
    return []


def candidate_bound_trigger_path(cand):
    route = str(cand.get("route") or "").strip()
    file_path = str(cand.get("file") or "").strip()
    line = cand.get("line", 0)
    evidence = str(cand.get("evidence_slice") or "").strip()
    result = []
    if evidence or file_path or line:
        loc = file_path
        if line not in (None, "", 0):
            loc = f"{loc}:{line}" if loc else str(line)
        result.append(
            {
                "step": 1,
                "loc": loc or "unknown",
                "code": evidence or route or "candidate route evidence",
            }
        )
    if route:
        result.append({"step": 2, "loc": "route", "function": route})
    return result


def attack_path_strings(resp, cand):
    attack_path_strs = []
    for step in trigger_path_items(resp):
        if isinstance(step, dict):
            desc = str(step.get("code") or step.get("function") or step.get("loc") or "").strip()
            loc = str(step.get("loc") or "").strip()
            if desc and loc and loc != "unknown" and loc not in desc:
                attack_path_strs.append(f"{desc} @ {loc}")
            elif desc:
                attack_path_strs.append(desc)
        elif step not in (None, "", []):
            attack_path_strs.append(str(step))
    if not attack_path_strs and cand.get("route"):
        attack_path_strs = [cand["route"]]
    return attack_path_strs


def evidence_complete(resp, cand):
    required = ("project_id", "sample_id", "route", "file", "line", "evidence_slice")
    if any(cand.get(field) in (None, "", []) for field in required):
        return False
    if not attack_path_strings(resp, cand):
        return False
    if isinstance(resp, dict) and resp.get("evidence_complete") is False:
        return False
    return True


def selected_vulnerability_response(responses):
    for resp in reversed(responses):
        if is_vulnerability_response(resp):
            return resp
    for resp in reversed(responses):
        if not has_llm_error(resp):
            return resp
    return responses[-1] if responses else {}


def stage_b_static_confirmation_supported(cand):
    support = cand.get("stage_b", {}).get("static_confirmation_support", {})
    return bool(support.get("supported"))


def candidate_semantic_text(cand):
    llm = cand.get("llm_evidence", {}) if isinstance(cand.get("llm_evidence"), dict) else {}
    parts = [
        cand.get("route"),
        cand.get("file"),
        cand.get("evidence_slice"),
        llm.get("evidence_slice"),
    ]
    for item in llm.get("code_slices", []) if isinstance(llm.get("code_slices"), list) else []:
        if isinstance(item, dict):
            parts.append(item.get("text"))
    return "\n".join(str(part or "") for part in parts)


def candidate_contract_text(cand):
    llm = cand.get("llm_evidence", {}) if isinstance(cand.get("llm_evidence"), dict) else {}
    parts = [cand.get("evidence_slice")]
    cand_line = cand.get("line")
    for item in llm.get("code_slices", []) if isinstance(llm.get("code_slices"), list) else []:
        if not isinstance(item, dict):
            continue
        roles = set(item.get("roles", []))
        line_start = item.get("line_start")
        line_end = item.get("line_end")
        anchor_line = item.get("anchor_line")
        line_matches = (
            isinstance(cand_line, int)
            and (
                anchor_line == cand_line
                or (
                    isinstance(line_start, int)
                    and isinstance(line_end, int)
                    and line_start <= cand_line <= line_end
                )
            )
        )
        if "focus" in roles or line_matches:
            parts.append(item.get("text"))
    return "\n".join(str(part or "") for part in parts if part)


def strip_c_comments(text):
    without_block = re.sub(r"/\*.*?\*/", " ", str(text or ""), flags=re.DOTALL)
    return re.sub(r"//.*", " ", without_block)


COMPARISON_LITERAL_PATTERN = r"(?:NULL|EOF|INVALID_HANDLE_VALUE|FALSE|TRUE|-?0|-?1)"
COMPARISON_OPERATORS = ("==", "!=", "<=", ">=", "<", ">")
INVERT_COMPARISON_OPERATOR = {
    "==": "==",
    "!=": "!=",
    "<": ">",
    ">": "<",
    "<=": ">=",
    ">=": "<=",
}

NULL_FAILURE_POINTER_APIS = ("fgets", "fgetws")
NEGATIVE_FAILURE_APIS = (
    "fprintf",
    "fwprintf",
    "printf",
    "wprintf",
    "snprintf",
    "_snprintf",
    "sprintf_s",
    "swprintf",
    "fputs",
    "fputws",
    "puts",
    "putws",
    "fputc",
    "fputwc",
    "putc",
    "putwc",
    "putchar",
    "putwchar",
    "remove",
    "_wremove",
    "rename",
    "_wrename",
)
SIZE_RETURN_APIS = ("fread", "fwrite")
SCANF_FAMILY_APIS = (
    "scanf",
    "fscanf",
    "sscanf",
    "wscanf",
    "fwscanf",
    "swscanf",
)
INVALID_HANDLE_FAILURE_APIS = ("CreateNamedPipeA", "CreateNamedPipeW")
BOOL_ZERO_FAILURE_APIS = ("ImpersonateNamedPipeClient", "ImpersonateSelf")


def normalize_comparison_literal(value):
    text = str(value or "").strip()
    if text in {"-0", "+0"}:
        return "0"
    upper = text.upper()
    if upper in {"NULL", "EOF", "INVALID_HANDLE_VALUE", "FALSE", "TRUE"}:
        return upper
    return text


def api_name_pattern(api_names):
    return "|".join(re.escape(name) for name in sorted(api_names, key=len, reverse=True))


def iter_direct_call_comparisons(text, api_names):
    if not text:
        return
    api_pattern = api_name_pattern(api_names)
    call_left = re.compile(
        rf"(?P<expr>\b(?P<api>{api_pattern})\s*\([^;{{}}]*\)\s*"
        rf"(?P<op>{'|'.join(re.escape(op) for op in COMPARISON_OPERATORS)})\s*"
        rf"(?P<literal>{COMPARISON_LITERAL_PATTERN}))",
        re.DOTALL,
    )
    literal_left = re.compile(
        rf"(?P<expr>(?P<literal>{COMPARISON_LITERAL_PATTERN})\s*"
        rf"(?P<op>{'|'.join(re.escape(op) for op in COMPARISON_OPERATORS)})\s*"
        rf"\b(?P<api>{api_pattern})\s*\([^;{{}}]*\))",
        re.DOTALL,
    )
    for match in call_left.finditer(text):
        yield {
            "api": match.group("api"),
            "op": match.group("op"),
            "literal": normalize_comparison_literal(match.group("literal")),
            "expr": " ".join(match.group("expr").split()),
            "start": match.start(),
            "end": match.end(),
        }
    for match in literal_left.finditer(text):
        yield {
            "api": match.group("api"),
            "op": INVERT_COMPARISON_OPERATOR[match.group("op")],
            "literal": normalize_comparison_literal(match.group("literal")),
            "expr": " ".join(match.group("expr").split()),
            "start": match.start(),
            "end": match.end(),
        }


def nearby_condition_fragment(text, start, end, radius=220):
    prefix_start = max(0, start - radius)
    suffix_end = min(len(text), end + radius)
    fragment = text[prefix_start:suffix_end]
    return " ".join(fragment.split())


def nearby_branch_indicates_failure(text, start, end):
    fragment = nearby_condition_fragment(text, start, end).lower()
    failure_markers = (
        "fail",
        "failed",
        "failure",
        "error",
        "unable",
        "invalid",
        "exit(1)",
        "abort(",
        "perror(",
        "return -1",
    )
    return any(marker in fragment for marker in failure_markers)


def contract_finding(api, expr, expected, reason, start=0, end=0, confidence=0.75):
    return {
        "api": api,
        "expr": expr,
        "expected": expected,
        "reason": reason,
        "start": start,
        "end": end,
        "confidence": confidence,
    }


def direct_return_contract_findings(text):
    findings = []
    for cmp in iter_direct_call_comparisons(
        text,
        NULL_FAILURE_POINTER_APIS
        + NEGATIVE_FAILURE_APIS
        + SIZE_RETURN_APIS
        + SCANF_FAMILY_APIS
        + BOOL_ZERO_FAILURE_APIS,
    ):
        api = cmp["api"]
        op = cmp["op"]
        literal = cmp["literal"]
        expr = cmp["expr"]
        start = cmp["start"]
        end = cmp["end"]

        if api in NULL_FAILURE_POINTER_APIS and (
            literal in {"EOF", "-1"} or (literal == "0" and op in {"<", "<="})
        ):
            findings.append(
                contract_finding(
                    api,
                    expr,
                    "check failure against NULL",
                    "pointer-return API is compared against a numeric failure sentinel",
                    start,
                    end,
                    0.82,
                )
            )
            continue

        if api in SIZE_RETURN_APIS and literal in {"0", "-1"} and op in {"<", "<="}:
            findings.append(
                contract_finding(
                    api,
                    expr,
                    "compare the returned item count with the requested item count or check ferror/feof",
                    "size_t-return API is checked for a negative failure value",
                    start,
                    end,
                    0.78,
                )
            )
            continue

        if api in NEGATIVE_FAILURE_APIS and literal == "0" and op in {"==", ">", ">="}:
            if nearby_branch_indicates_failure(text, start, end):
                findings.append(
                    contract_finding(
                        api,
                        expr,
                        "check failure as a negative return value",
                        "negative-on-failure API is treated as failed on a non-negative value",
                        start,
                        end,
                        0.76,
                    )
                )
            continue

        if api in SCANF_FAMILY_APIS and literal == "0" and op == "==":
            if nearby_branch_indicates_failure(text, start, end):
                findings.append(
                    contract_finding(
                        api,
                        expr,
                        "check the returned assignment count against the expected conversion count and handle EOF",
                        "scanf-family return value is checked against only one failure sentinel",
                        start,
                        end,
                        0.68,
                    )
                )
            continue

        if api in BOOL_ZERO_FAILURE_APIS and literal in {"0", "FALSE"} and op in {"!=", ">"}:
            if nearby_branch_indicates_failure(text, start, end):
                findings.append(
                    contract_finding(
                        api,
                        expr,
                        "check failure as zero/FALSE and success as nonzero",
                        "BOOL-return API success value is treated as the failure condition",
                        start,
                        end,
                        0.76,
                    )
                )
            continue
    return findings


def assignment_return_contract_findings(text):
    findings = []
    if not text:
        return findings
    api_pattern = api_name_pattern(INVALID_HANDLE_FAILURE_APIS)
    assign_pattern = re.compile(
        rf"\b(?P<var>[A-Za-z_]\w*)\s*=\s*(?:\([^;{{}}]*\)\s*)?"
        rf"\b(?P<api>{api_pattern})\s*\(",
        re.DOTALL,
    )
    for match in assign_pattern.finditer(text):
        var = re.escape(match.group("var"))
        window = text[match.end() : match.end() + 1800]
        compare_pattern = re.compile(
            rf"(?P<expr>\b{var}\s*(?P<op>==|!=)\s*NULL|NULL\s*(?P<rop>==|!=)\s*\b{var})"
        )
        for compare in compare_pattern.finditer(window):
            expr = " ".join(compare.group("expr").split())
            fragment = nearby_condition_fragment(window, compare.start(), compare.end(), radius=120)
            if "INVALID_HANDLE_VALUE" in fragment:
                continue
            op = compare.group("op") or compare.group("rop")
            findings.append(
                contract_finding(
                    match.group("api"),
                    expr,
                    "compare the returned HANDLE against INVALID_HANDLE_VALUE",
                    f"HANDLE-return API result is compared against NULL with {op}",
                    match.start(),
                    match.end() + compare.end(),
                    0.86,
                )
            )
            break
    return findings


def return_contract_findings(cand):
    text = strip_c_comments(candidate_contract_text(cand))
    findings = direct_return_contract_findings(text) + assignment_return_contract_findings(text)
    deduped = []
    seen = set()
    for finding in findings:
        key = (finding.get("api"), finding.get("expr"), finding.get("expected"), finding.get("reason"))
        if key in seen:
            continue
        seen.add(key)
        deduped.append(finding)
    return deduped


def unguarded_call_offset(text, api_name):
    pattern = re.compile(rf"\b{re.escape(api_name)}\s*\(")
    for match in pattern.finditer(text):
        line_start = text.rfind("\n", 0, match.start()) + 1
        line_end = text.find("\n", match.start())
        if line_end < 0:
            line_end = len(text)
        line = text[line_start:line_end].strip()
        if not line or line.startswith("*") or line.startswith("//"):
            continue
        prefix = line[: max(0, match.start() - line_start)].strip()
        if re.search(r"\bif\s*\(?\s*!?$", prefix):
            continue
        if re.search(r"\bif\s*\([^)]*$", prefix):
            continue
        return match.start()
    return -1


def source_api_safety_net_response(cand):
    contract_findings = return_contract_findings(cand)
    if contract_findings:
        finding = sorted(contract_findings, key=lambda item: -float(item.get("confidence", 0.0)))[0]
        api = finding["api"]
        expr = finding["expr"]
        expected = finding["expected"]
        reason = finding["reason"]
        confidence = max(CONFIDENCE_THRESHOLD, float(finding.get("confidence", CONFIDENCE_THRESHOLD)))
        return {
            "claim": (
                f"{api} return value check violates the API contract: `{expr}`. "
                f"The route should {expected}; observed check indicates {reason}. "
                "This is a CWE-253 return-value contract violation even if runtime impact is "
                "route-dependent or low and must be verified separately."
            ),
            "cwe_candidates": ["CWE-253"],
            "trigger_path": candidate_bound_trigger_path(cand),
            "preconditions": [
                f"{api} can return its documented failure value on this route.",
                "The route depends on the check to distinguish success from failure.",
            ],
            "confidence": confidence,
            "evidence_complete": True,
            "stability": "source_api_contract_safety_net",
            "_routing_reason": "source_api_contract_violation",
        }

    text = candidate_semantic_text(cand)
    named_pipe_offset = unguarded_call_offset(text, "ImpersonateNamedPipeClient")
    if named_pipe_offset >= 0:
        after_call = text[named_pipe_offset:]
        if "RevertToSelf" in after_call or "Impersonated" in after_call:
            return {
                "claim": (
                    "ImpersonateNamedPipeClient return value appears unchecked before the route "
                    "continues into success-path privilege handling; D must verify the forced-failure behavior."
                ),
                "cwe_candidates": [],
                "trigger_path": candidate_bound_trigger_path(cand),
                "preconditions": [
                    "The impersonation API can fail on this route, and later code depends on impersonation success."
                ],
                "confidence": CONFIDENCE_THRESHOLD,
                "evidence_complete": True,
                "stability": "source_api_semantic_safety_net",
                "_routing_reason": "source_api_semantic_safety_net",
            }

    if unguarded_call_offset(text, "RpcImpersonateClient") >= 0:
        return {
            "claim": (
                "RpcImpersonateClient return value appears unchecked on this route; D must verify that "
                "a forced non-OK status is not propagated or handled."
            ),
            "cwe_candidates": [],
            "trigger_path": candidate_bound_trigger_path(cand),
            "preconditions": ["RpcImpersonateClient can return a non-OK status on this route."],
            "confidence": CONFIDENCE_THRESHOLD,
            "evidence_complete": True,
            "stability": "source_api_semantic_safety_net",
            "_routing_reason": "source_api_semantic_safety_net",
        }
    return None


def route_record(cand, responses):
    first_is_vuln = is_vulnerability_response(responses[0]) if responses else False
    vuln_flags = [is_vulnerability_response(resp) for resp in responses]
    vuln_count = sum(1 for flag in vuln_flags if flag)
    any_vuln = bool(vuln_count)
    final_is_vuln = vuln_flags[-1] if vuln_flags else False
    has_error = any(has_llm_error(resp) for resp in responses)
    selected = selected_vulnerability_response(responses)
    contradictions = []
    for resp in responses:
        contradictions.extend(hard_contradictions(resp))

    if not any_vuln:
        safety_net = source_api_safety_net_response(cand)
        if safety_net:
            reason = safety_net.get("_routing_reason", "source_api_semantic_safety_net")
            return safety_net, "P1", "candidate_for_d", reason, contradictions
        if has_error:
            return selected, "P3", "audit_only", "stage_c_llm_error", contradictions
        return selected, "P3", "audit_only", "multi_agent_no_vulnerability", contradictions

    if has_error:
        return selected, "P2", "candidate_for_d", "stage_c_partial_llm_error", contradictions

    confidence = response_confidence(selected)
    all_vuln = vuln_count == len(responses)
    has_cwe = bool(response_cwes(selected))
    selected_evidence_complete = evidence_complete(selected, cand)
    if all_vuln and selected_evidence_complete and confidence >= STATIC_CONFIDENCE_THRESHOLD and has_cwe:
        if not stage_b_static_confirmation_supported(cand):
            return selected, "P1", "candidate_for_d", "stage_b_static_confirmation_unsupported", contradictions
        return selected, "P0", "static_confirmed", "multi_agent_static_strong", contradictions

    if final_is_vuln and vuln_count >= 2:
        if not first_is_vuln:
            return selected, "P1", "candidate_for_d", "corrected_to_vulnerability", contradictions
        if len(vuln_flags) >= 2 and not vuln_flags[-2]:
            return selected, "P1", "candidate_for_d", "red_rebuttal_after_blue_challenge", contradictions
        return selected, "P1", "candidate_for_d", "multi_agent_stable_needs_dynamic_verification", contradictions
    return selected, "P2", "candidate_for_d", "multi_agent_vulnerability_once", contradictions


def build_hypothesis(cand, selected, priority, agent_verdict, routing_reason, contradictions, agent_rounds):
    attack_path = attack_path_strings(selected, cand)
    confidence = response_confidence(selected)
    record = {
        "project_id": cand["project_id"],
        "sample_id": cand["sample_id"],
        "hypothesis_id": f"hyp_{cand['sample_id']}",
        "claim": response_claim(selected) or "NO_VULNERABILITY_FOUND",
        "CWE_candidates": response_cwes(selected),
        "preconditions": selected.get("preconditions", []) if isinstance(selected, dict) else [],
        "attack_path": attack_path,
        "confidence": confidence,
        "priority": priority,
        "agent_verdict": agent_verdict,
        "routing_decision": agent_verdict,
        "suspicion_reason": routing_reason,
        "hard_contradictions": contradictions,
        "agent_rounds": agent_rounds,
        "route": cand.get("route", ""),
        "file": cand.get("file", ""),
        "line": cand.get("line", 0),
        "evidence_slice": cand.get("evidence_slice", ""),
        "timestamps": {"routed_at": utc_now()},
    }
    if priority == "P0":
        record["status"] = "static_confirmed"
        record["verification_stage"] = "C"
        record["d_verification"] = "pending_routing_decision"
    elif priority in {"P1", "P2"}:
        record["status"] = "pending_dynamic_verification"
        record["d_verification"] = "pending"
    else:
        record["status"] = "audit_only"
        record["d_verification"] = "not_applicable"
    return record


def audit_error_record(cand, exc):
    return {
        "project_id": cand.get("project_id"),
        "sample_id": cand.get("sample_id"),
        "hypothesis_id": f"hyp_{cand.get('sample_id', 'unknown')}",
        "priority": "P3",
        "agent_verdict": "audit_only",
        "routing_decision": "audit_only",
        "suspicion_reason": "stage_c_processing_error",
        "error": str(exc),
        "route": cand.get("route", ""),
        "file": cand.get("file", ""),
        "line": cand.get("line", 0),
        "evidence_slice": cand.get("evidence_slice", ""),
        "timestamps": {"routed_at": utc_now()},
    }


def audit_timeout_record(cand, completed_rounds):
    return {
        "project_id": cand.get("project_id"),
        "sample_id": cand.get("sample_id"),
        "hypothesis_id": f"hyp_{cand.get('sample_id', 'unknown')}",
        "claim": "NO_VULNERABILITY_FOUND",
        "CWE_candidates": [],
        "preconditions": [],
        "attack_path": [cand.get("route", "")] if cand.get("route") else [],
        "confidence": 0.0,
        "priority": "P3",
        "agent_verdict": "audit_only",
        "routing_decision": "audit_only",
        "suspicion_reason": "stage_c_time_budget_exhausted",
        "hard_contradictions": [],
        "agent_rounds": completed_rounds,
        "route": cand.get("route", ""),
        "file": cand.get("file", ""),
        "line": cand.get("line", 0),
        "evidence_slice": cand.get("evidence_slice", ""),
        "timestamps": {"routed_at": utc_now()},
        "status": "audit_only",
        "d_verification": "not_applicable",
    }


def audit_one(cand, deadline=None):
    """
    单个样本的双Agent三轮对抗审计流程：
    1. 红队提出高召回漏洞假设。
    2. 蓝队挑战红队判断，检查误报、漏报、防御和证据闭合。
    3. 红队回应蓝队挑战，按P0/P1/P2/P3分流。
    """
    sample_id = cand["sample_id"]
    brief = build_evidence_brief(cand)
    agent_rounds = []

    if not has_time_remaining(deadline):
        return audit_timeout_record(cand, agent_rounds)

    print(f"[C] red round 1 proposer {sample_id}")
    prop_resp = call_llm(PROPOSER_PROMPT.format(evidence_brief=brief), deadline)
    if not prop_resp:
        prop_resp = llm_failure("round_1_failed", "empty_llm_response")
    agent_rounds.append({"round": 1, "agent": "red", "role": "red_proposer", "response": prop_resp})

    if not has_time_remaining(deadline):
        return audit_timeout_record(cand, agent_rounds)

    print(f"[C] blue round 2 challenger {sample_id}")
    challenge_resp = call_llm(BLUE_CHALLENGER_PROMPT.format(
        evidence_brief=brief,
        proposer_json=json.dumps(prop_resp, ensure_ascii=False),
    ), deadline)
    if not challenge_resp:
        challenge_resp = llm_failure("round_2_failed", "empty_llm_response")
    agent_rounds.append({"round": 2, "agent": "blue", "role": "blue_challenger", "response": challenge_resp})

    if not has_time_remaining(deadline):
        return audit_timeout_record(cand, agent_rounds)

    print(f"[C] red round 3 rebuttal {sample_id}")
    final_resp = call_llm(RED_REBUTTAL_PROMPT.format(
        evidence_brief=brief,
        proposer_json=json.dumps(prop_resp, ensure_ascii=False),
        challenger_json=json.dumps(challenge_resp, ensure_ascii=False),
    ), deadline)
    if not final_resp:
        final_resp = llm_failure("round_3_failed", "empty_llm_response")
    agent_rounds.append({"round": 3, "agent": "red", "role": "red_rebuttal", "response": final_resp})
    responses = [prop_resp, challenge_resp, final_resp]
    selected, priority, decision, reason, contradictions = route_record(cand, responses)
    return build_hypothesis(cand, selected, priority, decision, reason, contradictions, agent_rounds)


# ==================== 主程序（并发 + 即时分流写入）====================
def truncate_jsonl(path):
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", encoding="utf-8"):
        pass


def append_jsonl(file_obj, row):
    file_obj.write(json.dumps(row, ensure_ascii=False) + "\n")
    file_obj.flush()


class CompletedFuture:
    def __init__(self, result):
        self._result = result

    def result(self):
        return self._result


def audit_worker(cand, deadline, result_queue):
    try:
        hyp = audit_one(cand, deadline)
    except Exception as exc:
        hyp = audit_error_record(cand, exc)
    result_queue.put({"pid": os.getpid(), "hyp": hyp})


def route_p0_to_d(hyp):
    hyp["status"] = "pending_dynamic_verification"
    hyp["verification_stage"] = "D"
    hyp["d_verification"] = "pending"
    hyp["stage_c_static_verdict"] = "static_confirmed"
    hyp["stage_c_p0_routing"] = "sent_to_d"
    return hyp


def process_completed_future(future, cand, d_file, audit_file):
    try:
        hyp = future.result()
    except Exception as e:
        hyp = audit_error_record(cand, e)

    if hyp.get("priority") == "P0":
        append_jsonl(d_file, route_p0_to_d(hyp))
        bucket = "p0_d"
    elif hyp.get("priority") in {"P1", "P2"}:
        append_jsonl(d_file, hyp)
        bucket = "d"
    else:
        append_jsonl(audit_file, hyp)
        bucket = "audit"
    print(
        f"[C] {cand['sample_id']} rank={cand.get('processing_rank')} "
        f"priority={hyp.get('priority')} decision={hyp.get('routing_decision')} "
        f"reason={hyp.get('suspicion_reason')}"
    )
    return bucket


def process_hypothesis_record(hyp, cand, d_file, audit_file):
    return process_completed_future(CompletedFuture(hyp), cand, d_file, audit_file)


def run_audit_queue(candidates, time_limit_seconds, d_file, audit_file):
    if time_limit_seconds is not None and time_limit_seconds <= 0:
        raise ValueError("--time-limit-seconds must be greater than 0")

    deadline = None if time_limit_seconds is None else time.monotonic() + time_limit_seconds
    grace_deadline = None if deadline is None else deadline + POST_DEADLINE_GRACE_SECONDS
    submitted_count = 0
    exhausted_reported = False
    counts = {"d": 0, "p0_d": 0, "audit": 0}
    next_index = 0

    def within_budget():
        return deadline is None or time.monotonic() < deadline

    def report_exhausted(pending_count):
        nonlocal exhausted_reported
        if deadline is None or exhausted_reported or next_index >= len(candidates):
            return
        exhausted_reported = True
        print(
            f"[C] time budget exhausted after submitting {submitted_count}/{len(candidates)} "
            f"candidates; waiting for {pending_count} in-flight task(s)"
        )

    start_method = "fork" if "fork" in mp.get_all_start_methods() else None
    ctx = mp.get_context(start_method) if start_method else mp.get_context()
    result_queue = ctx.Queue()
    running = {}

    def submit_available():
        nonlocal submitted_count, next_index
        while len(running) < MAX_WORKERS and next_index < len(candidates) and within_budget():
            cand = candidates[next_index]
            next_index += 1
            process = ctx.Process(target=audit_worker, args=(cand, deadline, result_queue))
            process.start()
            running[process.pid] = (process, cand)
            submitted_count += 1

    def handle_result(message):
        pid = message.get("pid")
        process, cand = running.pop(pid, (None, None))
        if process is not None:
            process.join(timeout=0)
        if cand is None:
            return
        hyp = message.get("hyp")
        bucket = process_completed_future(
            CompletedFuture(hyp),
            cand,
            d_file,
            audit_file,
        )
        counts[bucket] += 1

    def drain_results():
        drained = False
        while True:
            try:
                handle_result(result_queue.get_nowait())
                drained = True
            except queue.Empty:
                return drained

    def wait_for_worker_result(pid, timeout_seconds):
        deadline_at = time.monotonic() + timeout_seconds
        while pid in running:
            remaining = deadline_at - time.monotonic()
            if remaining <= 0:
                return False
            try:
                handle_result(result_queue.get(timeout=min(0.05, remaining)))
            except queue.Empty:
                continue
        return True

    def terminate_running():
        drain_results()
        for pid, (process, cand) in list(running.items()):
            if not process.is_alive():
                process.join(timeout=0)
                if wait_for_worker_result(pid, WORKER_RESULT_DRAIN_GRACE_SECONDS):
                    continue
            if process.is_alive():
                process.terminate()
                process.join(timeout=1)
            if process.is_alive():
                process.kill()
                process.join(timeout=1)
            drain_results()
            if pid not in running:
                continue
            bucket = process_completed_future(
                CompletedFuture(audit_timeout_record(cand, [])),
                cand,
                d_file,
                audit_file,
            )
            counts[bucket] += 1
            running.pop(pid, None)

    submit_available()
    if not running and next_index < len(candidates):
        report_exhausted(0)

    while running or (next_index < len(candidates) and within_budget()):
        submit_available()
        if drain_results():
            submit_available()
            continue
        if not running:
            break

        if deadline is not None and not within_budget():
            report_exhausted(len(running))
            if time.monotonic() >= grace_deadline:
                terminate_running()
                break
            poll_timeout = max(0.0, min(0.5, grace_deadline - time.monotonic()))
        elif deadline is None:
            poll_timeout = 0.5
        else:
            poll_timeout = max(0.0, min(0.5, deadline - time.monotonic()))

        try:
            handle_result(result_queue.get(timeout=poll_timeout))
            submit_available()
        except queue.Empty:
            for pid, (process, cand) in list(running.items()):
                if process.is_alive():
                    continue
                process.join(timeout=0)
                if wait_for_worker_result(pid, WORKER_RESULT_DRAIN_GRACE_SECONDS):
                    continue
                bucket = process_completed_future(
                    CompletedFuture(
                        audit_error_record(
                            cand,
                            RuntimeError(f"worker exited without result: exitcode={process.exitcode}"),
                        )
                    ),
                    cand,
                    d_file,
                    audit_file,
                )
                counts[bucket] += 1
                running.pop(pid, None)
            submit_available()

    skipped = len(candidates) - submitted_count
    return counts, submitted_count, skipped


def main():
    """主流程：加载数据，并发处理候选，并按P0/P1/P2/P3即时分流写入。"""
    args = parse_args()
    candidates_path = Path(args.candidates)
    output_path = Path(args.output)
    audit_output_path = Path(args.audit_output) if args.audit_output else default_side_output(
        output_path, "audit", "audit.jsonl"
    )

    candidates = load_candidates(candidates_path)

    truncate_jsonl(output_path)
    truncate_jsonl(audit_output_path)

    # 使用worker进程并发处理，提高整体吞吐量
    with (
        open(output_path, "a", encoding="utf-8", buffering=1) as d_file,
        open(audit_output_path, "a", encoding="utf-8", buffering=1) as audit_file,
    ):
        counts, submitted_count, skipped_count = run_audit_queue(
            candidates,
            args.time_limit_seconds,
            d_file,
            audit_file,
        )

    print(f"[C] LLM-audited candidates: {submitted_count}/{len(candidates)}")
    if skipped_count:
        print(f"[C] skipped by time budget: {skipped_count}")
    d_candidate_count = counts["d"] + counts["p0_d"]
    print(f"[C] D candidates: {d_candidate_count} -> {output_path}")
    print(f"[C] P0 routed to D: {counts['p0_d']} -> {output_path}")
    print(f"[C] audit only: {counts['audit']} -> {audit_output_path}")


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, json.JSONDecodeError) as exc:
        raise SystemExit(f"error: {exc}") from exc
