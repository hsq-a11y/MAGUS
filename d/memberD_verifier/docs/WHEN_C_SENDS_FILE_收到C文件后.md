# 收到 C 的 c/out/*.jsonl 后怎么做

正式接 C 的所有东西都在：

```text
02_run_with_C
```

## 自动模式

1. 确认 C 已经把需要动态验证的 `P1`/`P2` 候选，以及已完成的 `P0` 候选，输出为一个或多个 JSONL 文件：

```text
c/out/*.jsonl
```

D 信任 `c/out` 是 C 已经分流好的动态验证队列，会按文件名排序读取这些文件；如果不同文件里有重复的 `project_id + hypothesis_id`，会直接报错。

C 的 `P3` 审计记录在 `c/audit/audit.jsonl`，D 不读取。`c/out` 里的 P0 仍需 D 做 route-bound 动态验证；D 只对 P0 施加每条 10 秒执行 timeout，P1/P2 不受 D timeout 限制。

2. 运行：

```text
02_run_with_C/01_auto_attack_from_C_linux.sh
```

它会自动生成：

```text
02_run_with_C/targets.auto.json
02_run_with_C/targets.executable.json  # 如果存在 verification_contexts.jsonl
02_run_with_C/output/payloads/*.payload.py
02_run_with_C/output/payloads/*.api-plan.json
02_run_with_C/output/verification.jsonl
02_run_with_C/output/verification.failed.jsonl
02_run_with_C/output/verification.summary.md
report/<run-name>/verification.report.jsonl
report/<run-name>/verification.report.md
```

`report/<run-name>/verification.report.jsonl` / `report/<run-name>/verification.report.md` 是最终漏洞报告，汇总 D `verification.jsonl` 中的 reportable 记录：D `confirmed`，以及 D 明确返回 `UNSUPPORTED_ORACLE` 时保留的 `P0`/`P1` `stage_c_preserved`。`P2 + UNSUPPORTED_ORACLE` 留在 `verification.failed.jsonl`。`<run-name>` 优先来自 D 输出中的唯一 CWE 源码目录名，没有唯一 CWE 目录时取唯一 `project_id`；也可以用 `REPORT_RUN_NAME=<name>` 显式指定。每条报告包含漏洞位置（文件路径、行号、route）、漏洞类型、风险等级、触发条件、运行证据和 payload/plan 引用。

如果自动 target 没有可执行上下文，可以在同目录补一个显式 sidecar：

```text
02_run_with_C/verification_contexts.jsonl
```

它不会修改 C 输出，也不改 oracle profile。自动脚本会把 sidecar 绑定进 `targets.executable.json` 后交给原 verifier。
sidecar 必须能命中当前 targets；未匹配的 `project_id`、`route` 或 `hypothesis_id` 会直接报错。

## 能不能 confirmed

如果 D 侧显式 sidecar 或 target 提供了：

```text
repo_path
run_cmd 或 poc_cmd 或 test_cmd
oracle
```

D 会执行生成的 runner，并按 oracle 判定 reportable 或 failed。confirmed 需要能把证据归因到当前 `route` / source API 序列，并命中 D 选择的 `oracle_profile_id` 的语义证据；CWE 只是 profile 选择的辅助信号，不是必需输入。oracle profile 使用项目无关的 `MAGUS_ORACLE_*` 语义 marker，不包含测试集专用逻辑。资源生命周期 profile 还会携带 acquire/release/transfer/duplicate/sentinel 语义模型，并根据当前 route 的 acquire/duplicate API 在用户态 fd、C stdio、Win32 HANDLE、Linux kernel API family 中选择；kernel profile 不能复用用户态 `open`/`close` oracle，必须通过显式内核运行上下文验证。资源生命周期 profile 默认要求 `MAGUS_ORACLE_RAN profile=<oracle_profile_id>`，缺失时表示 harness 没有证明自己能观察该生命周期状态。memory/integer sanitizer profile 需要 sidecar 或 harness 证明当前 route 已执行，并把 ASan/UBSan 观察映射到当前 profile 的 `MAGUS_ORACLE_*` 语义 marker；无关路径上的 sanitizer 崩溃不能确认当前假设。如果只能证明同项目或同文件的其他路径触发，结果应进入 failed，通常是 `NOT_ROUTE_BOUND`。如果 route 已执行但 oracle 明确报告能力不支持，D 只对 `P0`/`P1` 写 `stage_c_preserved` 保留 C 判断；`P2` 写 failed，`failure_code=UNSUPPORTED_ORACLE`。

这些字段来自显式 target 或 `verification_contexts.jsonl` sidecar。项目/环境适配如果存在，也必须物化为显式 sidecar 或 target 字段，不进入 C 输出，也不让 D core 自动识别 benchmark；sidecar 支持按 `project_id`、`route`、`hypothesis_id` 绑定，优先级是 `hypothesis_id > route > project_id`。

sidecar oracle 可使用 `required_patterns` 作为 confirmed 前必须存在的 route-bound marker，也可以用 `failure_code_patterns` 把输出 marker 映射为 `NOT_ROUTE_BOUND` / `NOT_EXPLOITABLE` 等失败码；`unsupported_patterns` 用于把 D 能力缺口映射为 `UNSUPPORTED_ORACLE`，由 D 按 Stage C priority 决定是保留 `P0`/`P1` 还是把 `P2` 写入 failed。

如果缺少这些字段，D 仍会生成 payload 和 plan，但结果会进入 `verification.failed.jsonl`，用于回流缺失信息。

## 手动补强模式

如果自动模式没有确认漏洞，运行：

```text
02_run_with_C/02_generate_targets_from_C_linux.sh
```

然后编辑：

```text
02_run_with_C/targets.manual.json
```

补真实仓库路径、构建命令、运行命令、PoC harness 或 oracle 后，再运行：

```text
02_run_with_C/03_verify_manual_targets_linux.sh
```
