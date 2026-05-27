# 成员 D：职责边界

D 不负责 A/B/C 的挖掘和审计。D 只负责最后一段源码/API 动态验证：

```text
C 的源码/API 假设 -> payload / PoC runner -> 动态验证 -> reportable/failed 回流
Report 读取 D 输出 -> 最终漏洞报告
```

这里的 API 指 C/C++ 函数调用接口和调用序列，不是 HTTP API。

## 输入

C 写给 D 的正式动态验证队列位置：

```text
c/out/*.jsonl
```

D 信任这个目录只包含 C 分流出的动态验证候选：`P1`/`P2`，以及已完成的 `P0`。D 会按文件名排序批量读取这些文件，并拒绝重复的 `project_id + hypothesis_id`。里面应包含漏洞假设、CWE、前置条件、调用路径、代码证据和置信度等 C 侧证据；C 不负责输出 D verifier/oracle 配置或 `verification_context`。

`P3` 审计记录写到 `c/audit/audit.jsonl`，不是 D 的输入。Stage C 的时间预算只控制是否继续提交候选，以及未完成 worker 是否转成 P3 超时审计记录；D 只对 P0 施加每条 10 秒执行 timeout，P1/P2 不受 D timeout 限制。

需要可执行上下文时，D 在 `02_run_with_C/verification_contexts.jsonl` 里维护显式 sidecar，或使用显式 target 字段，再由外层脚本绑定到 generated targets；C 和 D core 都不需要改。

## D 自动做什么

1. 识别源码/API 误用类型，例如空指针、整数溢出、UAF、缓冲区溢出、命令注入、路径穿越。
2. 根据 `route`、`attack_path`、`file`、`evidence_slice` 生成 `*.api-plan.json`。
3. 生成可执行 `*.payload.py` runner。
4. 如果显式 sidecar 或 target 提供 `repo_path` 加 `run_cmd` / `poc_cmd` / `test_cmd`，执行 runner。
5. 按 oracle 判断 reportable 或 failed；confirmed 必须有 route-bound 动态证据，否则输出 failed，例如 `NOT_ROUTE_BOUND`。如果 route 已执行但 D 明确缺少 oracle 能力，只对 Stage C `P0`/`P1` 输出 `stage_c_preserved` 保留 C 判断；`P2` 输出 failed，`failure_code=UNSUPPORTED_ORACLE`，不能写成 `NOT_EXPLOITABLE`。
6. 输出 runtime trace、失败原因和回流建议。
7. 外层脚本在 D 结束后把 reportable/failed 结果交给 Report 阶段生成最终漏洞报告。

## 输出

```text
payloads/*.payload.py
payloads/*.api-plan.json
verification.jsonl
verification.failed.jsonl
verification.summary.md
```

最终漏洞报告由仓库根目录的 Report 阶段生成：

```text
report/<run-name>/verification.report.jsonl
report/<run-name>/verification.report.md
```

## 汇报说法

A/B/C 找疑似漏洞，D 将 C 的源码/API 假设转换为可执行 payload 或 PoC runner，在授权源码测试环境中动态验证，并生成 runtime trace、验证结果和失败回流。
