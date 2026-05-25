# MAGUS Pipeline

MAGUS is a multi-stage mining pipeline plus a small root-level orchestrator:

- `a/`: Stage `A` static-analysis pipeline that emits `samples.raw.jsonl`, the derived `samples.stats.jsonl` view, and `samples.llm.jsonl` evidence.
- `b/`: Stage `B` miner that consumes Stage `A` `samples.stats.jsonl` and `samples.llm.jsonl`, mines high-support feature patterns, scores candidates, and prepares the route-aggregated C audit queue.
- `c/`: Stage `C` two-agent adversarial audit that consumes Stage `B` `candidates.for_c.jsonl`, then routes findings into static confirmations, D candidates, or audit-only records.
- `d/`: Stage `D` source/API verifier that consumes the Stage `C` dynamic-verification queue in `c/out/*.jsonl` and produces reportable/failed verification records. Reportable records are either D-confirmed or Stage-C-preserved `P0`/`P1` records when D explicitly reports `UNSUPPORTED_ORACLE`; unsupported `P2` records stay in failed output.
- `report/code/`: final report generator and validator; it reads Stage `D` verification outputs and writes final report artifacts under `report/<run-name>/`.
- `test/`: paper-evaluation helpers, including Juliet final-report comparison, timing summaries, and monitored adapted-CWE batch runs.
- `pipeline.py`: root entrypoint for generating Stage `A` input, running Stage `A`, Stage `B`, Stage `C`, Stage `D`, Report, or the full `A -> B -> streamed C/D -> Report` flow from one place.
- `tools/sanitize_juliet_tree.py`: generates `srcs_sanitized/` plus `juliet_sanitization_map.json` from the original Juliet tree.
- `tools/gen_srcs_compile_commands.py`: explicit helper for generating `srcs_sanitized/compile_commands.json` for the sanitized Juliet sample tree.
- `tools/gen_juliet_verification_contexts.py`: explicit helper for generating a Stage `D` sidecar when running Juliet Win32 samples through the Linux shim.


## Layout

- `pipeline.py`: root orchestration for `build-analyzer`, `gen-input`, `a`, `b`, `c`, `d`, `report`, `abcd`, `stats-path`, and `llm-path`
- `Makefile`: convenience wrappers around `pipeline.py`
- `tools/`: repository-level helper scripts
- `a/`: standalone Stage `A` project
- `b/`: standalone Stage `B` miner, usage notes, and outputs
- `c/`: standalone Stage `C` audit agent and outputs
- `d/`: standalone Stage `D` source/API verifier, Linux scripts, and usage notes
- `report/code/`: standalone Report generator and validator
- `test/`: final-report evaluation scripts, adapted-CWE batch runner, and generated evaluation artifacts

## Common Commands

Build the Stage `A` analyzer once before the first Stage `A` or full pipeline run if the binary is not present yet.

- Temporarily add the local Clang/LLVM toolchain to the current shell `PATH` when only the versioned LLVM install is available:

```bash
export LLVM_HOME=/usr/lib/llvm-20
export PATH="$LLVM_HOME/bin:$PATH"
clang --version
llvm-link --version
```

This is intentionally temporary: open a new shell to clear it, or run the same export again before generating Stage `A` input or launching `pipeline.py abcd`.

- Build the Stage `A` analyzer:

```bash
make build-analyzer
```

- Generate the sanitized Juliet copy and `srcs_sanitized/compile_commands.json`:

```bash
make gen-srcs-compile-commands
```

The Juliet compile database helper defaults to the Linux Win32 shim include path, the Juliet `testcasesupport` include path, `-D_WIN32`, and the shared `tools/juliet_win_shim/juliet_win_compat.h` forced include so Windows API samples compile to bitcode under Linux using the same shim declarations as Stage `D`.

If the environment only has versioned Clang binaries, generate the compile database normally, then pass the real compiler paths when converting it to Stage `A` input:

```bash
make gen-srcs-compile-commands SRC_CC_FORCE=1
make gen-input \
  GEN_CLANG=/usr/bin/clang-20 \
  GEN_CLANGXX=/usr/bin/clang++-20 \
  GEN_FORCE=1
```

- Generate a Stage `A` input JSONL from `compile_commands.json`:

```bash
make gen-input
```

Equivalent direct command:

```bash
python3 pipeline.py gen-input \
  --repo-path ./srcs_sanitized \
  --compile-commands ./srcs_sanitized/compile_commands.json \
  --output ./a/input/srcs.in.jsonl
```

This step is explicit. `make run-a` does not generate or overwrite Stage `A` input automatically.
By default, `gen-input` writes `extensions.analysis_timeout = 1800` seconds into the Stage `A` project record; override it with `GEN_ANALYSIS_TIMEOUT` or `--analysis-timeout`.
It also writes bitcode into `bc.<project_id>/` by default and records `extensions.bitcode_globs` for that directory. Stage `A` treats `bitcode_globs` as generated output ownership: each glob must have a concrete repo-local directory prefix that Stage `A` may clear before build, so interrupted or failed prior runs cannot be collected into the next run.
The Juliet helper above is also explicit; Stage `A` input generation still requires an existing `compile_commands.json` and does not infer compile flags from a bare source scan. The original `srcs/` tree remains the Juliet ground-truth source; default MAGUS runs use the sanitized `srcs_sanitized/` copy so comments, path names, macros, and symbols no longer expose bad/good labels to Stage `A`, Stage `B`, or Stage `C`.

- Run Stage `A` on the sanitized Juliet sample tree after generating its compile database and Stage `A` input:

```bash
make run-a A_INPUT=a/input/srcs.in.jsonl A_OUTPUT=a/out/srcs.raw.jsonl
```

- Run only Stage `A`. This also exports `samples.llm.jsonl` beside the raw output:

```bash
make run-a
```

- Run only Stage `B` against the derived stats view:

```bash
make run-b
```

- Run only Stage `C` against the Stage `B` C-ready candidate queue:

```bash
make run-c
```

- Run Stage `D` after Stage `C` has written one or more dynamic-verification candidate files under `c/out/`; this also generates the final report:

```bash
make run-d
```

Pass project-specific execution contexts explicitly when the source project needs a harness sidecar:

```bash
make run-d D_CONTEXTS=d/memberD_verifier/02_run_with_C/verification_contexts.<run>.jsonl
```

- Regenerate only the final report from an existing Stage `D` output directory:

```bash
make run-report
```

- Run the full `A -> B -> streamed C/D -> Report` pipeline:

```bash
make run-abcd
```

This command runs Stage `A` and Stage `B`, then starts Stage `D` as a stream consumer for the current Stage `C` output file before launching Stage `C`. Stage `B` writes `candidates.for_c.jsonl` as route-aggregated Stage `A` LLM evidence records with `stage_b` scoring metadata attached and sorted by `c_priority_score` to front-load candidates that are more likely to become `P0`/`P1`/`P2` under a Stage `C` time budget. As Stage `C` flushes dynamic-verification JSONL records, including `P1`/`P2` and completed `P0` records, Stage `D` verifies those records without waiting for all Stage `C` candidates to finish. The full-chain command chooses `<run-name>` from `REPORT_RUN_NAME` / `--report-run-name`, or from the Stage `A` input `project_id` when no override is supplied. Stage `D` writes the streamed run under `d/memberD_verifier/02_run_with_C/output/<run-name>/`, and Report reads that same directory and writes the final vulnerability report under `report/<run-name>/`. Set `C_TIME_LIMIT_SECONDS=<seconds>` to stop Stage `C` from submitting more candidates after a time budget. Stage `C` audits each Stage `B` route record independently; it first decides whether the route violates a source/API contract or CWE definition, then separately reflects exploitability and impact in confidence, priority, and wording. Clear API contract violations remain dynamic candidates even when runtime impact is low or uncertain. Stage `C` does not reuse benchmark-template answers across sibling routes. After the deadline plus a short grace period, unfinished workers are terminated and their candidates are written as `P3` timeout audit records, while completed records remain complete newline-terminated JSONL. This command reaches Stage `C` and calls the DeepSeek API through the OpenAI-compatible Python SDK.

Pass a D sidecar explicitly in the streamed chain when the source project needs one:

```bash
make run-abcd D_CONTEXTS=d/memberD_verifier/02_run_with_C/verification_contexts.<run>.jsonl
```

Stage `D` has two root modes. `make run-d` uses the formal batch script under `d/memberD_verifier/02_run_with_C`; it reads every `c/out/*.jsonl` file in filename order, trusts that Stage `C` has already selected the records that need dynamic verification, rejects duplicate `project_id + hypothesis_id` records, generates source/API targets, binds a sidecar only when `D_CONTEXTS` or `pipeline.py d --contexts` is supplied, runs the verifier, writes the batch result directly under `d/memberD_verifier/02_run_with_C/output/`, and validates the D output files. `make run-abcd` uses `d/memberD_verifier/02_run_with_C/stream_from_C.py` to follow only the current `--c-output` file while Stage `C` is still running, writing that run under `output/<run-name>/`; it binds a sidecar only when `D_CONTEXTS` or `pipeline.py abcd --d-contexts` is supplied. Both D modes use the same output lock so two D writers cannot run concurrently. D may execute a complete project or full testcase, but `confirmed` records require route-bound oracle evidence that the candidate route or source/API sequence was reached plus oracle-profile-specific semantic evidence. D selects oracle profiles from API names, route text, attack path, evidence slice, and claim wording; CWE is only an optional tie-breaker. Oracle profiles are project-agnostic, use generic semantic markers such as `MAGUS_ORACLE_*`, and must not contain benchmark-specific code or marker names. Resource lifecycle profiles also carry a structured semantic model for acquire/release/transfer/duplicate/sentinel behavior, keeping user-space POSIX fd, C stdio, Win32 HANDLE, and Linux kernel resource lifecycles separate. Target generation emits project-agnostic source/API targets first; execution context must come from an explicit sidecar or explicit target with `repo_path`, `run_cmd`/`poc_cmd`/`test_cmd`, and oracle fields. The generated runner exports `MAGUS_D_PROJECT_ID`, `MAGUS_D_SAMPLE_ID`, `MAGUS_D_HYPOTHESIS_ID`, `MAGUS_D_ROUTE`, `MAGUS_D_FILE`, `MAGUS_D_LINE`, `MAGUS_D_ENTRY_SYMBOL`, `MAGUS_D_ORACLE_PROFILE_ID`, `MAGUS_D_PAYLOAD`, `MAGUS_D_PAYLOAD_MARKER`, and `MAGUS_D_CONFIRM_PATTERNS_JSON` so any project harness can emit `MAGUS_ROUTE_EXECUTED` plus the selected `MAGUS_ORACLE_*` markers. The search-path oracle profile is generic and covers APIs such as `putenv`, `_putenv`, `_wputenv`, `SetEnvironmentVariableA/W`, `SearchPathA/W`, `SetDllDirectoryA/W`, and `AddDllDirectory`. Resource lifecycle profiles currently cover user-space fd APIs such as `open`/`socket`/`pipe` to `close`, C stdio `fopen`/`fdopen`/`popen` to `fclose`/`pclose`, Win32 `CreateFile*`/HANDLE APIs to `CloseHandle`, and Linux kernel examples such as `filp_open`/`fput`, `kmalloc`/`kfree`, and `kobject_get`/`kobject_put`; kernel profiles require explicit kernel execution context such as KUnit, kselftest, QEMU, syzkaller repro, or a module harness. For return-value/privilege-drop profiles, a forced API failure marker alone is insufficient; D confirms only when the run also proves post-failure misuse or unpropagated failure on the candidate route. Unbound runs stay in `verification.failed.jsonl` as `NOT_ROUTE_BOUND`. If the selected route executes and D explicitly reports `UNSUPPORTED_ORACLE`, D writes a `stage_c_preserved` record to `verification.jsonl` only for Stage `C` `P0`/`P1`; unsupported `P2` records stay in `verification.failed.jsonl` with `failure_code=UNSUPPORTED_ORACLE`. This preserves stronger Stage `C` judgments while making clear that D did not dynamically confirm them. Stage `C` emits hypothesis/routing evidence only; Stage `D` owns verifier and oracle generation. Report then writes `report/<run-name>/verification.report.jsonl` and `report/<run-name>/verification.report.md` from D reportable/failed records; each report entry includes file path, line, vulnerability type, risk level, and trigger condition. Prepare the local D Python environment once before running D:

```bash
(cd d/memberD_verifier/01_demo_test && ./01_setup_linux.sh)
```

Stage `D` currently uses only the Python standard library, so the setup script creates a no-pip virtual environment unless `00_core/requirements.txt` contains real dependencies.

- Compare the final report with Juliet answers for paper evaluation:

```bash
python3 test/evaluate_juliet_report.py \
  --report report/CWE15_External_Control_of_System_or_Configuration_Setting/verification.report.jsonl \
  --scope-compile-commands srcs_sanitized/compile_commands.cwe15.json \
  --stage-a-start 2026-05-20T10:00:00Z
```

To time a fresh full run from Stage `A` start through final report generation and then evaluate it:

```bash
python3 tools/gen_juliet_verification_contexts.py \
  --project-id srcs_sanitized \
  --out d/memberD_verifier/02_run_with_C/verification_contexts.srcs_sanitized.jsonl

python3 test/evaluate_juliet_report.py \
  --run-command "python3 pipeline.py abcd --d-contexts d/memberD_verifier/02_run_with_C/verification_contexts.srcs_sanitized.jsonl" \
  --scope-compile-commands srcs_sanitized/compile_commands.cwe15.json
```

The evaluator infers Juliet ground truth from the original `srcs/juliet-api-misuse` bad/good paths by default, or from an explicit `--answer-file`. Report paths from `srcs_sanitized/` are mapped back through `srcs_sanitized/juliet_sanitization_map.json` before classification. It writes paper-ready precision/recall/F1, false-positive, false-negative, duplicate-report, and elapsed-time artifacts under `test/out/juliet_eval/<run-name>/`; `<run-name>` follows the same derivation used for the final report. Override the evaluation output location with `--out-dir`.

For monitored adapted-CWE Juliet batch testing, use `python3 test/run_lazy_batch.py`. It parses the ordered queue in `test/lazy.md`, runs one CWE folder at a time, applies the Stage C time budget, records when `(fn_cases + fp_unique_units) / truth_cases` exceeds the configured 10% mismatch threshold, continues to the next folder even when the threshold is exceeded, and writes logs plus per-folder summaries under `test/out/lazy_batch/<run-id>/`. The batch queue is intentionally limited to Juliet source/API misuse folders whose decisive behavior maps to a route-bound Stage D oracle profile with matching project-agnostic semantic evidence, or an explicit `UNSUPPORTED_ORACLE` preservation path for Stage C `P0`/`P1`. Do not add memory-safety-only Juliet folders such as stack/heap buffer overflow directories to this queue unless Stage D first gains an explicit matching verifier/oracle profile or preservation classification.

- Show the derived `samples.stats.jsonl` path for a given Stage `A` raw output:

```bash
python3 pipeline.py stats-path --raw-output a/out/samples.raw.jsonl
```

- Show the derived `samples.llm.jsonl` path for a given Stage `A` raw output:

```bash
python3 pipeline.py llm-path --raw-output a/out/samples.raw.jsonl
```

## Validation Boundaries

The root orchestrator intentionally preserves separate validation:

- Stage `A` can still be validated independently through `make run-a` or the original commands inside `a/`; the root `make run-a` command also exports LLM evidence
- Stage `A` exits non-zero if any project record is invalid or mining fails, so root chained runs stop before Stage `B` consumes empty stats
- Stage `A` requires explicit `extensions.bitcode_globs` with a concrete repo-local generated-output directory prefix, clears those output directories before build, and then collects only matching `.bc` files
- `srcs_sanitized/` and `srcs_sanitized/compile_commands.json` can be generated independently with `make gen-srcs-compile-commands`
- Stage `A` input can be generated independently with `make gen-input` from an existing `compile_commands.json`
- Stage `B` can still be validated independently by pointing it at matching `samples.stats.jsonl` and `samples.llm.jsonl`
- Stage `C` can still be validated independently by pointing it at an existing `candidates.for_c.jsonl`
- `make run-abcd` chains Stage `A` and Stage `B`, then streams Stage `C` dynamic candidates into Stage `D`
- Stage `D` can still be validated independently from `d/memberD_verifier` or through `make run-d`
- Report can be regenerated independently with `make run-report` from an existing Stage `D` output directory; it writes under `report/<run-name>/`
- Juliet report evaluation can be run independently from the final report; `--run-command` is only a convenience wrapper for timing a fresh pipeline run. `test/run_lazy_batch.py` is the monitored batch wrapper for the adapted Juliet CWE queue in `test/lazy.md`.

Important contract boundary:

- Stage `B` consumes Stage `A` stats records with schema `stagea.stats.features.v1` and matching Stage `A` LLM evidence keyed by `sample_id`
- Stage `B` validates the required stats fields before mining and rejects unsupported schemas
- Stage `B` writes a complete seed-level `candidates.scored.jsonl` plus a route-aggregated C-ready `candidates.for_c.jsonl`; C-ready records use schema `stageb.c_ready_candidates.v3`, keep only Stage `C` input fields, store merged Stage `A` LLM evidence under `llm_evidence`, and attach B scoring metadata under `stage_b`, including risk score weights, `static_confirmation_support`, `c_priority_score`, and `c_priority_components`; `threshold_pass` is a bounded evidence bonus in C queue priority rather than a hard high/low priority band
- Stage `C` consumes Stage `B` `candidates.for_c.jsonl`; it does not read Stage `A` outputs directly, and its prompt treats `stage_b` threshold gates, missing high-support features, seed tokens, reference samples, C queue priority metadata, and static-confirmation support as anti-hallucination constraints rather than vulnerability conclusions. Stage `C` validates `stage_b.static_confirmation_support` and routes otherwise-P0 findings to dynamic verification when B says static confirmation is unsupported.
- Stage `C` routes records by priority after fixed three-round two-agent review: round 1 is red `red_proposer`, round 2 is blue `blue_challenger`, and round 3 is red `red_rebuttal`; completed records store these under `agent_rounds`. `P1`/`P2` dynamic-verification candidates go to `c/out/*.jsonl`; completed `P0` static confirmations also go to `c/out/*.jsonl` so Stage `D` can route-bound verify them; `P3` audit-only records go to `c/audit/audit.jsonl`. Stage `C` time budgets only stop new submissions and turn unfinished in-flight work into `P3` timeout audit records. `P1` means the final red rebuttal still reports a vulnerability and at least two rounds support the vulnerability, including first-round no-vulnerability findings corrected by blue plus red, or first-round findings reaffirmed after the blue challenge. Otherwise, any record with at least one vulnerability round but without stable final support is `P2`; LLM/API failures do not count as no-vulnerability votes and are routed with `stage_c_llm_error` or `stage_c_partial_llm_error`. Records enter `P3` only when all completed non-error agent rounds return no vulnerability and no deterministic source/API semantic safety net recognizes an unchecked failure route. The safety net emits semantic hypothesis evidence without requiring or synthesizing a CWE label and routes to `P1`. Stage `C` does not infer or emit D verifier/oracle configuration.
- Stage `D` batch mode consumes every record Stage `C` places under `c/out/*.jsonl`; root full-chain streaming mode consumes the current Stage `C --output` file as JSONL lines become complete. In both modes D does not re-check `P1`/`P2` or `agent_verdict`, does not read Stage `A` or Stage `B` outputs directly, and verifies C/C++ source/API misuse cases rather than HTTP endpoints. Stage `D` applies a 10-second execution timeout only to `P0`; `P1`/`P2` dynamic-verification records are not D-time-limited. D-confirmed records require route-bound dynamic evidence and a matching oracle profile; resource lifecycle profiles are selected by API family and execution environment, not by benchmark folder or C language alone. Resource lifecycle profiles also require a capability marker such as `MAGUS_ORACLE_RAN profile=<oracle_profile_id>` before a missing flaw marker can mean `NOT_EXPLOITABLE`; route execution without that capability marker is `UNSUPPORTED_ORACLE`. D returns failed records such as `NOT_EXPLOITABLE`, `NOT_ROUTE_BOUND`, `ENV_MISSING`, `HYPOTHESIS_WRONG`, `TIMEOUT`, or `NON_DETERMINISTIC` when execution or attribution is insufficient. `NOT_EXPLOITABLE` means a supported oracle profile ran and did not confirm the hypothesis. If route execution succeeds but D lacks an oracle profile for the hypothesis semantics, D emits `UNSUPPORTED_ORACLE`; only `P0`/`P1` records are preserved as `stage_c_preserved` in `verification.jsonl`, while `P2` records go to `verification.failed.jsonl` with `failure_code=UNSUPPORTED_ORACLE`. Target generation is project-agnostic first; executable context must be supplied through explicit D sidecars (`--contexts` / `--d-contexts`) or explicit targets that provide repository, command, and oracle details.
- Report consumes Stage `D` `verification.jsonl` and `verification.failed.jsonl`; it does not read Stage `A`, Stage `B`, or Stage `C` outputs directly. In `abcd`, the root pipeline uses the selected `<run-name>` for both `output/<run-name>/` and `report/<run-name>/`; report-only runs derive the report directory from the unique `project_id` in the supplied D output when `--run-name` is omitted. `validate_report.py` requires one report row per `verification.jsonl` reportable record and accepts `confirmed` plus `P0`/`P1` `stage_c_preserved` statuses.
- `test/evaluate_juliet_report.py` consumes the final report plus Juliet answers only. It does not change pipeline outputs; it maps sanitized report paths back to original Juliet paths, classifies report rows against original Juliet bad/good cases, and measures elapsed time from Stage `A` start to final report generation when timing inputs are provided.

## Outputs

Default outputs:

- Stage `A` raw output: `a/out/samples.raw.jsonl`
- Stage `A` derived stats output: `a/out/samples.stats.jsonl`
- Stage `A` LLM evidence output: `a/out/samples.llm.jsonl`
- Generated Stage `A` project input: `a/input/srcs.in.jsonl`
- Sanitized Juliet copy and mapping: `srcs_sanitized/` and `srcs_sanitized/juliet_sanitization_map.json`
- Stage `B` outputs: `b/b_output/patterns.json`, `b/b_output/candidates.scored.jsonl`, `b/b_output/candidates.for_c.jsonl`, `b/b_output/b_miner_stats.json`
- Stage `C` dynamic-verification output: `c/out/hypotheses.jsonl` for `P1`/`P2` plus completed `P0` records; Stage `C` audit-only output: `c/audit/audit.jsonl`; Stage `D` batch input: all `c/out/*.jsonl`; Stage `D` streaming input in `run-abcd`: the current `C_OUTPUT` file
- Stage `D` outputs: batch `make run-d` writes `d/memberD_verifier/02_run_with_C/output/verification.jsonl`, `verification.failed.jsonl`, `verification.summary.md`, and `payloads/*.api-plan.json` / `payloads/*.payload.py`; `verification.jsonl` contains D `confirmed` plus `P0`/`P1` `stage_c_preserved` reportable records, while `P2 + UNSUPPORTED_ORACLE` remains in `verification.failed.jsonl`. Generated plans and D records may include `oracle_profile_id` / `oracle_profile_supported` to show which reusable oracle profile was selected. Streaming `run-abcd` writes the same files under `d/memberD_verifier/02_run_with_C/output/<run-name>/`
- Report outputs: `report/<run-name>/verification.report.jsonl` and `report/<run-name>/verification.report.md`
- Juliet evaluation outputs: `test/out/juliet_eval/<run-name>/summary.md`, `summary.json`, `false_positives.csv`, `false_negatives.csv`, `true_positives.csv`, `duplicate_true_positives.csv`, `all_findings.csv`, and `truth_cases.csv`
- Monitored adapted-CWE batch outputs: `test/out/lazy_batch/<run-id>/config.json`, `runs.jsonl`, per-folder logs, and per-folder evaluation directories

If you override `A_OUTPUT`, `pipeline.py` derives the matching stats and LLM paths automatically during full runs; `make run-b` derives the matching `samples.llm.jsonl` path for `B_LLM_INPUT`.

`samples.llm.jsonl` is Stage `A` evidence output produced by `a/cmd/llm_export.py`; it is emitted by the root `make run-a` and `make run-abcd` paths.

Stage `C` uses the DeepSeek-compatible OpenAI client configuration in `c/agent1.py`. It requires the Python `openai` package and an API key in `DEEPSEEK_API_KEY` or `OPENAI_API_KEY`; `DEEPSEEK_MODEL` and `DEEPSEEK_BASE_URL` can override the defaults.

Stage `B` does not currently expose a worker-count flag, and the root pipeline does not provide one. Stage `C` no longer exposes a candidate-count limit; use `C_TIME_LIMIT_SECONDS` or `pipeline.py c --time-limit-seconds` for time-bounded C runs. Time-bounded C runs write explicit `stage_c_time_budget_exhausted` P3 records for unfinished in-flight candidates after the grace period.
