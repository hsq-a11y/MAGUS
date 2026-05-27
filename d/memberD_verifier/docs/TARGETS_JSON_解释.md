# targets.json 是什么

`targets.json` 是 D 自己维护或自动生成的源码/API 验证配置。

C 给 D：哪里疑似存在 C/C++ 函数调用接口误用。  
D 的 `targets.json`：怎么在源码仓库里触达这条调用路径，以及用什么 oracle 判断。

D 不支持 HTTP API targets，因此没有 `base_url`、token、HTTP method、headers、query params 或 `*.http` payload。

## 最小例子

```json
{
  "targets": [
    {
      "project_id": "openssl",
      "target_type": "source_api",
      "env_profile": "source_repository",
      "cases": {
        "hyp_api_0001": {
          "target_type": "source_api",
          "payload_kind": "api_misuse_plan",
          "source_file": "crypto/x509/example.c",
          "entry_symbol": "parse_cert",
          "api_sequence": ["parse_cert -> ASN1_OCTET_STRING_new -> dereference"],
          "payload": {
            "seed_inputs": ["malformed serialized bytes"]
          },
          "execution": {
            "repo_path": "/datasets/openssl",
            "config_cmd": "./Configure enable-asan",
            "build_cmd": "make -j4",
            "run_cmd": "${PYTHON} poc_parse_cert.py"
          },
          "oracle": {
            "failure_patterns": [
              "MAGUS_ORACLE_FLAW name=_putenv reason=tainted_search_path_environment"
            ],
            "semantic_failure_patterns": [
              "MAGUS_ORACLE_FLAW name=_putenv reason=tainted_search_path_environment"
            ],
            "required_patterns": ["MAGUS_ROUTE_EXECUTED"],
            "failure_code_patterns": {
              "NOT_ROUTE_BOUND": ["MAGUS_NOT_ROUTE_BOUND"],
              "NOT_EXPLOITABLE": ["MAGUS_NOT_CONFIRMED"]
            },
            "expect_nonzero_exit": false
          }
        }
      }
    }
  ]
}
```

## 字段解释

- `project_id`：必须和 C 的 `c/out/*.jsonl` 假设记录里一致。
- `target_type`：固定为 `source_api`，历史 `native` 可视为同义。
- `cases`：每个假设一个 case，key 是 `hypothesis_id`。
- `payload_kind`：固定为 `api_misuse_plan` 或历史 `native_plan`。
- 执行上下文必须来自显式 target 字段或 `verification_contexts` sidecar；核心 target 生成器不自动附加项目/benchmark 运行配置。
- `source_file`：可疑源文件。
- `entry_symbol`：入口函数或可触达可疑路径的符号。
- `api_sequence`：C/C++ 函数调用链或 API 使用序列。
- `payload.seed_inputs`：用于构造 harness / PoC 的输入种子说明。
- `execution.repo_path`：源码仓库根目录。
- `execution.config_cmd` / `build_cmd`：可选准备命令。
- `execution.run_cmd` / `poc_cmd` / `test_cmd`：至少需要一个，用来实际触达 API 序列。
- `oracle.failure_patterns`：stdout/stderr 中可确认漏洞的模式。
- `oracle.profile_id`：D 选择的可复用 oracle profile；由 API 名、route、attack_path、evidence_slice、claim 和可选 CWE 推导，CWE 不是必需输入。
- `oracle_profile.semantic_model`：profile 附带的可审计语义模型。资源生命周期 profile 会列出 acquire/release/transfer/duplicate/sentinel 语义、释放 API 兼容关系和所需运行环境；用户态 fd、C stdio、Win32 HANDLE、Linux kernel lifecycle 必须作为不同 API family 处理。memory/integer sanitizer profile 会列出 memory_safety 或 integer_overflow 语义、sanitizer_or_harness 执行环境和 route-bound 证据要求。
- `oracle.semantic_failure_patterns`：profile 语义证据模式；这些模式使用项目无关的 `MAGUS_ORACLE_*` marker，具体项目 runner 或 sidecar 可以选择输出/映射这些 marker。
  返回值检查类 profile 不能只依赖“API 被强制失败”marker，还需要失败后错误继续使用或错误未传播的 route-bound marker。
- `oracle.required_patterns`：可选；confirmed 前必须同时出现在 stdout/stderr 中的模式，常用于证明当前 route / source API 序列已执行。
- `oracle.capability_patterns`：可选；证明当前 harness 确实运行了该 profile 的语义 oracle。资源生命周期 profile 默认要求 `MAGUS_ORACLE_RAN profile=<oracle_profile_id>`；route 已执行但 capability marker 缺失时，D 返回 `UNSUPPORTED_ORACLE`，不返回 `NOT_EXPLOITABLE`。
- `oracle.failure_code_patterns`：可选；把 stdout/stderr 中的模式映射为失败码，例如 `NOT_ROUTE_BOUND` 或 `NOT_EXPLOITABLE`。
- `oracle.unsupported_patterns`：可选；把 stdout/stderr 中的模式映射为 D oracle 能力缺口。命中时只对 Stage C `P0`/`P1` 输出 `stage_c_preserved`，`P2` 进入 failed 并保留 `failure_code=UNSUPPORTED_ORACLE`。
- `oracle.expect_nonzero_exit`：是否把非零退出作为确认信号之一。

## 能否 confirmed

自动生成的 source/API target 默认要求 `MAGUS_ROUTE_EXECUTED`，并把 `MAGUS_ORACLE_UNSUPPORTED` 作为能力缺口 marker。资源生命周期 profile 还默认要求 `MAGUS_ORACLE_RAN profile=<oracle_profile_id>`，用来区分“oracle 运行后未确认”和“harness 没有能力观察资源状态”。payload runner 会把 `MAGUS_D_PROJECT_ID`、`MAGUS_D_SAMPLE_ID`、`MAGUS_D_HYPOTHESIS_ID`、`MAGUS_D_ROUTE`、`MAGUS_D_FILE`、`MAGUS_D_LINE`、`MAGUS_D_ENTRY_SYMBOL`、`MAGUS_D_ORACLE_PROFILE_ID`、`MAGUS_D_PAYLOAD`、`MAGUS_D_PAYLOAD_MARKER`、`MAGUS_D_RUNTIME_INPUT`、`MAGUS_D_RUNTIME_INPUTS_JSON` 和 `MAGUS_D_CONFIRM_PATTERNS_JSON` 注入到命令环境中，方便任意项目 harness 输出 route-bound marker 和 profile 语义 marker。

搜索路径类漏洞使用通用 `path.untrusted_search_path` profile，不依赖 Juliet 文件名或 good/bad 标签。该 profile 覆盖 `putenv`、`_putenv`、`_wputenv`、`SetEnvironmentVariableA/W`、`SearchPathA/W`、`SetDllDirectoryA/W`、`AddDllDirectory`，以及 `system`/`_wsystem`/`popen`/`_popen`/`_wpopen` 的未限定命令搜索路径，项目 harness 只需要在当前 route 执行后输出 `MAGUS_ROUTE_EXECUTED`，并在确有攻击者可控搜索路径语义时输出对应的 `MAGUS_ORACLE_*` marker。

资源生命周期类漏洞使用通用状态语义，但不共用同一个 API 规则。D 根据当前 route 或证据中的 acquire/duplicate API 选择用户态 fd、C stdio、Win32 HANDLE、Linux kernel resource lifecycle profile；kernel profile 还需要 KUnit、kselftest、QEMU、syzkaller repro 或模块 harness 等显式内核运行上下文。项目 harness 需要证明同一个逻辑资源上的 acquire/release/transfer/duplicate 状态，而不是只证明某个同名 C 函数被调用。

memory/integer sanitizer profile 覆盖 route-bound ASan/UBSan 可观察的越界读写、use-after-free 和整数溢出。项目 sidecar 或 harness 必须证明当前 route 已执行，并把 sanitizer/harness 观察映射到当前 profile 的 `MAGUS_ORACLE_*` 语义 marker；不能用无关路径上的任意 sanitizer 崩溃确认当前假设。

只有生成 payload 不会自动 confirmed。要 confirmed，必须能在 `repo_path` 中运行具体命令，并且运行结果命中当前 oracle profile 的语义证据。若运行结果不能证明当前 `route` 或 source API 序列被触发，即使同项目里存在其他可触发路径，也不能写 confirmed，应回流为 failed。若 route 已执行但 D 明确命中 `unsupported_patterns`，不把能力缺口记成 `NOT_EXPLOITABLE`；`P0`/`P1` 写 `stage_c_preserved`，`P2` 写 failed。
