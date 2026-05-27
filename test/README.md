# Juliet Report Evaluation

`evaluate_juliet_report.py` compares the MAGUS final report with Juliet ground truth and writes paper-ready evaluation artifacts.

`run_lazy_batch.py` is the monitored batch wrapper for Juliet source/API misuse folders that are already adapted to the Stage D marker/oracle model. It reads the ordered queue in `test/lazy.md`, runs one CWE folder at a time without imposing a Stage C time budget, records when the configured mismatch threshold is exceeded, continues to the next folder, and writes logs plus per-folder metrics under `test/out/lazy_batch/<run-id>/`.

Default inputs:

- report: `report/<run-name>/verification.report.jsonl`, derived from Stage D output when `--report` is omitted
- sanitized input root: `srcs_sanitized/juliet-api-misuse`
- Juliet truth root: `srcs/juliet-api-misuse`
- sanitization map: `srcs_sanitized/juliet_sanitization_map.json`, used to map sanitized report paths back to original Juliet ground truth
- output: `test/out/juliet_eval/<run-name>`, using the same run name as the final report when `--out-dir` is omitted

Typical run for a scoped Juliet experiment:

```bash
python3 test/evaluate_juliet_report.py \
  --report report/CWE15_External_Control_of_System_or_Configuration_Setting/verification.report.jsonl \
  --scope-compile-commands srcs_sanitized/compile_commands.cwe15.json \
  --stage-a-start 2026-05-20T10:00:00Z
```

## Full Pipeline Test

`evaluate_juliet_report.py` does not replace `pipeline.py`. A complete test has two parts:

1. prepare Stage A input from the sanitized Juliet sources;
2. run the existing MAGUS pipeline, then compare the final report with Juliet answers.

Prepare the compile database and Stage A input first. This preparation is not included in the paper runtime metric because the metric starts at Stage A execution.

If this machine only exposes unversioned `clang`, `clang++`, and LLVM tools under the versioned LLVM install directory, add that directory to the current shell before preparation and before the timed pipeline run:

```bash
export LLVM_HOME=/usr/lib/llvm-20
export PATH="$LLVM_HOME/bin:$PATH"
clang --version
llvm-link --version
```

The export is temporary and is inherited by the `--run-command` subprocess only when `evaluate_juliet_report.py` is launched from the same shell.

For the CWE15-only experiment, scope the compile database to that Juliet folder:

```bash
python3 tools/sanitize_juliet_tree.py \
  --input srcs \
  --output srcs_sanitized \
  --force

python3 tools/gen_srcs_compile_commands.py \
  --repo-path srcs_sanitized \
  --output srcs_sanitized/compile_commands.cwe15.json \
  --source-glob 'juliet-api-misuse/testcases/CWE15_External_Control_of_System_or_Configuration_Setting/**/*.c' \
  --source-glob 'juliet-api-misuse/testcases/CWE15_External_Control_of_System_or_Configuration_Setting/**/*.cc' \
  --source-glob 'juliet-api-misuse/testcases/CWE15_External_Control_of_System_or_Configuration_Setting/**/*.cpp' \
  --source-glob 'juliet-api-misuse/testcases/CWE15_External_Control_of_System_or_Configuration_Setting/**/*.cxx' \
  --include-dir ../tools/juliet_win_shim \
  --include-dir juliet-api-misuse/testcasesupport \
  --force

python3 pipeline.py gen-input \
  --repo-path srcs_sanitized \
  --compile-commands srcs_sanitized/compile_commands.cwe15.json \
  --output a/input/srcs.cwe15.in.jsonl \
  --project-id cwe15 \
  --bc-dir bc.cwe15 \
  --force

python3 tools/gen_juliet_verification_contexts.py \
  --project-id cwe15 \
  --out d/memberD_verifier/02_run_with_C/verification_contexts.cwe15.jsonl
```

Then run the full MAGUS pipeline over only that CWE15 Stage A input and evaluate against the same CWE15 scope:

```bash
python3 test/evaluate_juliet_report.py \
  --run-command "python3 pipeline.py abcd --a-input a/input/srcs.cwe15.in.jsonl --a-output a/out/srcs.cwe15.raw.jsonl --b-output-dir b/b_output_cwe15 --c-output c/out/cwe15.hypotheses.jsonl --report-run-name CWE15_External_Control_of_System_or_Configuration_Setting --d-contexts d/memberD_verifier/02_run_with_C/verification_contexts.cwe15.jsonl" \
  --d-output-dir d/memberD_verifier/02_run_with_C/output/CWE15_External_Control_of_System_or_Configuration_Setting \
  --report-run-name CWE15_External_Control_of_System_or_Configuration_Setting \
  --scope-compile-commands srcs_sanitized/compile_commands.cwe15.json
```

For an all-Juliet experiment, use the broader compile database instead:

```bash
python3 tools/gen_srcs_compile_commands.py \
  --repo-path srcs_sanitized \
  --output srcs_sanitized/compile_commands.json \
  --source-glob 'juliet-api-misuse/testcases/**/*.c' \
  --source-glob 'juliet-api-misuse/testcases/**/*.cc' \
  --source-glob 'juliet-api-misuse/testcases/**/*.cpp' \
  --source-glob 'juliet-api-misuse/testcases/**/*.cxx' \
  --include-dir ../tools/juliet_win_shim \
  --include-dir juliet-api-misuse/testcasesupport \
  --force

python3 pipeline.py gen-input \
  --repo-path srcs_sanitized \
  --compile-commands srcs_sanitized/compile_commands.json \
  --output a/input/srcs.in.jsonl \
  --bc-dir bc.srcs_sanitized \
  --force

python3 tools/gen_juliet_verification_contexts.py \
  --project-id srcs_sanitized \
  --out d/memberD_verifier/02_run_with_C/verification_contexts.srcs_sanitized.jsonl
```

Prepare the Stage D Python environment once if it does not exist:

```bash
(cd d/memberD_verifier/01_demo_test && ./01_setup_linux.sh)
```

Then run the full MAGUS pipeline and evaluate it:

```bash
python3 test/evaluate_juliet_report.py \
  --run-command "python3 pipeline.py abcd --a-input a/input/srcs.in.jsonl --a-output a/out/srcs.raw.jsonl --report-run-name srcs_sanitized --d-contexts d/memberD_verifier/02_run_with_C/verification_contexts.srcs_sanitized.jsonl" \
  --d-output-dir d/memberD_verifier/02_run_with_C/output/srcs_sanitized \
  --report-run-name srcs_sanitized \
  --scope-compile-commands srcs_sanitized/compile_commands.json
```

## Timing

The paper runtime metric is measured from Stage A start to final report generation.

When `--run-command` is used, `evaluate_juliet_report.py` records the start time immediately before launching the command. Because the command should be `pipeline.py abcd`, whose first step is Stage A, this is the Stage A start time. Do not put compile database generation or `pipeline.py gen-input` inside `--run-command`, because those are preparation steps and would inflate the metric.

The report end time is resolved in this order:

- `--report-generated-at`, if supplied;
- `--timing-json`, if supplied;
- `report/<run-name>/verification.report.md` `generated_at`;
- final report file mtime as a last-resort fallback.

The computed elapsed time is written to `summary.md` and `summary.json`.

## Existing Report Only

If the pipeline has already run and only the final report needs evaluation, pass the known Stage A start time manually:

```bash
python3 test/evaluate_juliet_report.py \
  --report report/CWE15_External_Control_of_System_or_Configuration_Setting/verification.report.jsonl \
  --scope-compile-commands srcs_sanitized/compile_commands.json \
  --stage-a-start 2026-05-20T10:00:00Z
```

For a D-only or report-only rerun, omit `--stage-a-start` unless the original Stage A start time is known. For example, the CWE78 D rerun over the existing Stage C hypotheses was evaluated with:

```bash
python3 test/evaluate_juliet_report.py \
  --report report/CWE78_OS_Command_Injection/verification.report.jsonl \
  --scope-compile-commands srcs_sanitized/compile_commands.cwe78.json \
  --out-dir test/out/juliet_eval/CWE78_OS_Command_Injection_d_rerun_20260527T1518Z
```

That benchmark evaluation produced 3,378 report rows, 3,089 unique true-positive Juliet cases out of 4,801 truth-positive cases, 0 false-positive rows, 1,712 false-negative cases, 100.00% precision, and 64.34% recall. Because this was a D-only/report-only rerun rather than a fresh `pipeline.py abcd` run, the elapsed Stage A-to-report metric is intentionally absent.

Generated artifacts:

- `summary.md`: human-readable metrics and FP/FN previews
- `summary.json`: machine-readable metrics, counts, and timing
- `false_positives.csv`: reported findings that map to Juliet good paths or outside the selected truth scope
- `false_negatives.csv`: Juliet bad cases not covered by the final report
- `true_positives.csv`: matched Juliet bad cases
- `duplicate_true_positives.csv`: extra reports for already covered Juliet bad cases
- `all_findings.csv`: one classification row per final report row
- `truth_cases.csv`: inferred or loaded Juliet answer set

Use `--answer-file` to supply an explicit JSONL/JSON/CSV answer set with `key` or `file`, plus one of `is_vulnerable`, `vulnerable`, `expected`, `label`, `verdict`, or `answer`. The default answer inference always reads the original Juliet tree; sanitized paths from reports, failed D output, audit output, and scope compile databases are translated back through `--sanitization-map`.
