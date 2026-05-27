# 正式接 C 的流程

这个文件夹只放接 C 输出后真正运行的东西。D 只处理源码/API 误用假设，这里的 API 指 C/C++ 函数调用接口，不是 HTTP API。
本目录只保留 Ubuntu/Linux 脚本，不提供 Windows 路径。

## 1. C 输出位置

C 输出目录由 Stage C 写到：

```text
c/out/
```

D 的正式脚本直接读取这个目录下的所有 `*.jsonl` 文件，并按文件名排序合并。D 不直接接 A 的输出；A 的输出已经被 B/C 加工，D 只收 C 放入 `c/out/*.jsonl` 的动态验证候选。

根目录 `make run-abcd` 使用流式接入：`pipeline.py` 先启动本目录的 `stream_from_C.py`，让它监听当前 `C_OUTPUT` 文件；随后启动 C。C 每写入一条完整 JSONL 记录，D 就生成 target、绑定显式 sidecar、执行 verifier，并追加 reportable/failed 输出。reportable 包括 D confirmed，以及 D 明确返回 `UNSUPPORTED_ORACLE` 时保留的 Stage C `P0`/`P1` 判断；`P2 + UNSUPPORTED_ORACLE` 留在 failed 输出。C 结束后 pipeline 写 done 文件，D 读完剩余完整行再退出，然后 Report 从 D 输出生成最终报告。这个模式只消费本次 `C_OUTPUT` 文件，并把 D 输出写到 `output/<run-name>/`；`<run-name>` 来自 `REPORT_RUN_NAME` / `--report-run-name`，未提供时使用 Stage A 输入的 `project_id`。本目录的 `01_auto_attack_from_C_linux.sh` 仍是独立批处理入口，读取所有 `c/out/*.jsonl`，写入固定 `output/`，并在 D 校验通过后运行 Report。两种模式只有在显式传入 `--contexts` / `--d-contexts` 或 `D_CONTEXTS` 时才加载执行 sidecar。

C 的分流约定是：

```text
P0 -> c/out/*.jsonl                                # D 动态验证队列
P1/P2 -> c/out/*.jsonl                              # D 动态验证队列
P3 -> c/audit/audit.jsonl                           # 审计记录，不进入 D
```

Stage C 的时间预算只控制是否继续提交候选，以及未完成 worker 是否转成
`P3` 超时审计记录。已完成的 P0 不因 C deadline 改写到非 D 输出；
D 只对 P0 施加每条 10 秒执行 timeout；P1/P2 不受 D timeout 限制。

Stage C 固定执行三轮双 agent 审计：红队 `red_proposer`、蓝队 `blue_challenger`、红队 `red_rebuttal`，完成记录写入 `agent_rounds`。C 的判断分两步：先判断路由是否违反源/API contract 或 CWE 定义，再单独判断可利用性、影响和风险；影响较低或不确定只能降低置信度或保持动态验证，不能把明确的 API contract violation 改判为无漏洞。`P1` 表示最终红队回应仍认为有漏洞且至少两轮支持漏洞，包括第一轮无漏洞后由蓝队和红队纠正为漏洞，或第一轮有漏洞、蓝队挑战、第三轮仍确认漏洞；确定性的源/API contract safety net 也会把明确的错误返回值检查等语义假设路由为 `P1` 动态候选。`P2` 表示至少一轮报过漏洞但最终支持不稳定，例如第一轮报漏洞而后续两轮都否定。LLM/API 失败不算无漏洞票，会以 `stage_c_llm_error` 或 `stage_c_partial_llm_error` 保留在审计/候选原因里。

如果多个文件里出现相同的 `project_id + hypothesis_id`，脚本会直接失败，要求先消除重复输入。

`gen_targets_from_hypotheses.py` 生成 targets 时要求每条假设至少有：

```text
project_id
hypothesis_id
route
```

`verifier.py` 写 reportable/failed 记录时要求每条假设至少有：

```text
project_id
sample_id
hypothesis_id
route
file
line
evidence_slice
```

D 信任 `c/out` 的分流结果，不再根据 `agent_verdict` 或 `priority` 做准入判断；CWE 字段可以是 Stage C 当前的 `CWE_candidates`，也可以是 `cwe_candidates`。CWE 只作为 D oracle profile 选择的辅助信号；没有 CWE 时，D 会从 API 名、`route`、`attack_path`、`evidence_slice` 和 `claim` 中选择 profile。Stage C 只输出漏洞假设、代码位置和 `route`，不输出 D verifier/oracle 配置；这些由 Stage D 生成，执行上下文由显式 sidecar 或显式 target 提供。

## 2. 执行上下文

需要执行动态验证时，不要改 C 核心逻辑。执行上下文通过 D 侧 sidecar 或显式 target 提供：

```text
verification_contexts.<run>.jsonl
```

格式支持 project、route、hypothesis 三级绑定，优先级为：

```text
hypothesis_id > route > project_id
```

示例：

```json
{"project_id":"custom_source_api","repo_path":"/datasets/custom-source-api","test_cmd":"./repros/run_case.sh ${file} ${entry_symbol}","oracle":{"failure_patterns":["AddressSanitizer","Segmentation fault"],"expect_nonzero_exit":false}}
```

D 的 target generator 先生成项目无关的 source/API target 和 oracle profile，不自动附加 benchmark 或项目专用执行配置。真正的仓库路径、构建命令、运行命令、route marker、失败 marker、unsupported marker 来自显式 sidecar 或显式 target。`oracle_profiles.py` 只保留通用 profile 选择、可审计的 API-family 语义模型和 `MAGUS_ORACLE_*` 语义模式，不能包含 Juliet 或其他 benchmark 专用代码。自动生成的 source/API payload runner 会把 `MAGUS_D_PROJECT_ID`、`MAGUS_D_SAMPLE_ID`、`MAGUS_D_HYPOTHESIS_ID`、`MAGUS_D_ROUTE`、`MAGUS_D_FILE`、`MAGUS_D_LINE`、`MAGUS_D_ENTRY_SYMBOL`、`MAGUS_D_ORACLE_PROFILE_ID`、`MAGUS_D_PAYLOAD`、`MAGUS_D_PAYLOAD_MARKER`、`MAGUS_D_RUNTIME_INPUT`、`MAGUS_D_RUNTIME_INPUTS_JSON` 和 `MAGUS_D_CONFIRM_PATTERNS_JSON` 注入到运行命令环境中；任意项目 harness 都可以读取这些变量，输出 `MAGUS_ROUTE_EXECUTED` 和对应的 `MAGUS_ORACLE_*` marker。搜索路径类 profile 是通用 profile，覆盖 `putenv`、`_putenv`、`_wputenv`、`SetEnvironmentVariableA/W`、`SearchPathA/W`、`SetDllDirectoryA/W`、`AddDllDirectory`，以及 `system`/`_wsystem`/`popen`/`_popen`/`_wpopen` 的未限定命令搜索路径。命令执行类 `process.command_execution` profile 通过 route-bound 的 `MAGUS_ORACLE_SINK name=<api> tainted=1` 语义 marker 确认攻击者可控命令或进程执行，覆盖 `system`、`_wsystem`、`popen`、`_popen`、`_wpopen`、`_spawn*`、`_wspawn*`、`_exec*`、`_wexec*` 和 `CreateProcessA/W`。资源生命周期 profile 根据当前 route 的 acquire/duplicate API 选择资源家族，并按 API 家族和运行环境分开：用户态 fd 覆盖 `open`/`socket`/`pipe` 等到 `close`，C stdio 覆盖 `fopen`/`fdopen`/`popen` 到 `fclose`/`pclose`，Win32 HANDLE 覆盖 `CreateFile*`/HANDLE API 到 `CloseHandle`，Linux kernel 覆盖 `filp_open`/`fput`、`kmalloc`/`kfree`、`kobject_get`/`kobject_put` 等内核语义。memory/integer sanitizer profile 覆盖 route-bound ASan/UBSan 可观察的越界读写、use-after-free 和整数溢出；这些 profile 仍需要显式 sidecar 或项目 harness 证明当前 route 已执行，不能只依赖任意 sanitizer 崩溃。kernel profile 必须由 KUnit、kselftest、QEMU、syzkaller repro 或模块 harness 等显式执行上下文承载，不能复用用户态 `open`/`close` oracle。benchmark 或运行环境 helper 只能放在 `tools/` 或测试脚本里，并通过命令行 sidecar 显式接入。

sidecar 的 oracle 支持：

```text
failure_patterns         # confirmed 模式
required_patterns        # confirmed 前必须同时存在的 route-bound 模式；自动 target 默认要求 MAGUS_ROUTE_EXECUTED
capability_patterns      # 证明 harness 确实运行了该 profile 的语义 oracle；资源生命周期 profile 默认要求 MAGUS_ORACLE_RAN profile=<id>
failure_code_patterns    # 把输出模式映射为 NOT_ROUTE_BOUND / NOT_EXPLOITABLE 等失败码
unsupported_patterns     # route 已执行但 D oracle 不支持当前漏洞语义时返回 UNSUPPORTED_ORACLE
```

自动脚本会先生成 `targets.auto.json`。如果显式传入 sidecar，再通过 `bind_verification_contexts.py` 输出 `targets.executable.json` 给原 verifier 执行。没有 sidecar 或显式 targets 时，D 仍会生成 payload/plan，但执行结果会以 `ENV_MISSING` 回流。
sidecar 里的记录必须能命中当前 targets；如果出现未匹配的 `project_id`、`route` 或 `hypothesis_id`，脚本会直接失败。

## 3. 自动验证

运行：

```text
./01_auto_attack_from_C_linux.sh
```

带 sidecar：

```text
./01_auto_attack_from_C_linux.sh verification_contexts.<run>.jsonl
```

仓库根目录也提供等价入口：

```text
make run-d
```

带 sidecar：

```text
make run-d D_CONTEXTS=d/memberD_verifier/02_run_with_C/verification_contexts.<run>.jsonl
```

完整顺序链路：

```text
make run-abcd
```

`make run-abcd` 现在是 A、B 顺序执行，C 和 D 并行流式执行。D 只读 C 当前输出，不写回 `c/out`，并且只处理换行结束的完整 JSONL 记录。

带 sidecar：

```text
make run-abcd D_CONTEXTS=d/memberD_verifier/02_run_with_C/verification_contexts.<run>.jsonl
```

D 的批处理和流式模式共用输出锁：

```text
.stage_d_output.lock
```

锁存在时，另一个 D 写进程会直接失败，避免 `verification*.jsonl` 和 `payloads/` 被并发写入。

D 当前只使用 Python 标准库；`../01_demo_test/01_setup_linux.sh` 在没有真实 requirements 依赖时会创建不带 pip 的 `.venv`。

输出：

```text
targets.auto.json
targets.executable.json  # only when an explicit sidecar is supplied
output/payloads/*.payload.py
output/payloads/*.api-plan.json
output/verification.jsonl
output/verification.failed.jsonl
output/verification.summary.md
```

`run-abcd` 流式模式使用同样的文件名，但放在 `output/<run-name>/` 下。

`validate_outputs.py` 只校验 D 输出。自动脚本在 D 校验通过后调用根目录 `pipeline.py report`，再由它调用 `report/code/generate_report.py`。`run-abcd` 的最终漏洞报告写到 `report/<run-name>/`，并和 D 的 `output/<run-name>/` 使用同一个名字；需要手工指定目录名时设置 `REPORT_RUN_NAME=<name>`。独立批处理脚本的 Report 目录由根 `pipeline.py report` 从 D 输出中的唯一 `project_id` 推导，也可用 `REPORT_RUN_NAME=<name>` 覆盖。

```text
report/<run-name>/verification.report.jsonl
report/<run-name>/verification.report.md
```

报告从 D `verification.jsonl` 的 reportable 记录生成。报告的每条漏洞必须包含：漏洞位置（文件路径、行号、route）、漏洞类型、风险等级、触发条件、运行证据和 payload/plan 引用。`report/code/validate_report.py` 会校验报告文件存在，并要求报告行数与 `verification.jsonl` reportable 行数一致；报告状态可以是 `confirmed` 或 `P0`/`P1` 的 `stage_c_preserved`。

`verification.failed.jsonl` 中的 `NOT_ROUTE_BOUND` 表示执行成功但不能把证据归因到当前候选 route。
`NOT_EXPLOITABLE` 只表示支持的 oracle profile 已运行且未确认漏洞；如果 D 没有能力验证当前漏洞语义，应使用 `UNSUPPORTED_ORACLE`。只有 `P0`/`P1 + UNSUPPORTED_ORACLE` 会保留 C 判断为 `stage_c_preserved`，`P2 + UNSUPPORTED_ORACLE` 进入 `verification.failed.jsonl`。生成的 plan 和 D 记录可能包含 `oracle_profile_id` / `oracle_profile_supported`，用于审计 profile 覆盖情况。

## 4. 什么时候能执行

sidecar 最小可执行字段是：

```text
repo_path
run_cmd 或 poc_cmd 或 test_cmd
oracle
```

`config_cmd` 和 `build_cmd` 可选，用来准备源码项目。

## 5. 如果自动模式失败

失败不是坏事，它会输出失败回流。可以运行：

```text
./02_generate_targets_from_C_linux.sh
```

生成 `targets.manual.json` 后补真实仓库路径、构建命令、运行命令、PoC harness 或 oracle，再运行：

```text
./03_verify_manual_targets_linux.sh
```
