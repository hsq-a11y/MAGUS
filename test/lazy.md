# Lazy Juliet Runs

These commands mirror `test/README.md`: run MAGUS on `srcs_sanitized`, and let the evaluation script map sanitized report paths back to the original Juliet tree under `srcs` for ground truth.

Run the one-time setup first:

```bash
export LLVM_HOME=/usr/lib/llvm-20
export PATH="$LLVM_HOME/bin:$PATH"

python3 tools/sanitize_juliet_tree.py \
  --input srcs \
  --output srcs_sanitized \
  --force

(cd d/memberD_verifier/01_demo_test && ./01_setup_linux.sh)
```

Stage C calls the configured OpenAI-compatible LLM client, so set the required API credentials in the same shell before running a folder command.

For monitored batch testing, use the runner in `test/`. It parses the folder list below, keeps each folder run intact, does not impose a Stage C submission time budget, records when `(fn_cases + fp_unique_units) / truth_cases > 0.10`, continues to the next folder even when the threshold is exceeded, and writes per-folder logs plus CSV/JSONL summaries under `test/out/lazy_batch/<run-id>/`.

```bash
python3 test/run_lazy_batch.py
```

Useful variants:

```bash
python3 test/run_lazy_batch.py --prepare
python3 test/run_lazy_batch.py --start-at cwe252
python3 test/run_lazy_batch.py --only cwe252
python3 test/run_lazy_batch.py --dry-run --max-folders 1
```

Load this helper once in the shell:

```bash
run_juliet_folder() {
  local cwe_dir="$1"
  local cwe_id="$2"
  local run_name="$cwe_dir"

  python3 tools/gen_srcs_compile_commands.py \
    --repo-path srcs_sanitized \
    --output "srcs_sanitized/compile_commands.${cwe_id}.json" \
    --source-glob "juliet-api-misuse/testcases/${cwe_dir}/**/*.c" \
    --source-glob "juliet-api-misuse/testcases/${cwe_dir}/**/*.cc" \
    --source-glob "juliet-api-misuse/testcases/${cwe_dir}/**/*.cpp" \
    --source-glob "juliet-api-misuse/testcases/${cwe_dir}/**/*.cxx" \
    --include-dir ../tools/juliet_win_shim \
    --include-dir juliet-api-misuse/testcasesupport \
    --force

  python3 pipeline.py gen-input \
    --repo-path srcs_sanitized \
    --compile-commands "srcs_sanitized/compile_commands.${cwe_id}.json" \
    --output "a/input/srcs.${cwe_id}.in.jsonl" \
    --project-id "${cwe_id}" \
    --bc-dir "bc.${cwe_id}" \
    --force

  python3 tools/gen_juliet_verification_contexts.py \
    --project-id "${cwe_id}" \
    --out "d/memberD_verifier/02_run_with_C/verification_contexts.${cwe_id}.jsonl"

  python3 test/evaluate_juliet_report.py \
    --run-command "python3 pipeline.py abcd --a-input a/input/srcs.${cwe_id}.in.jsonl --a-output a/out/srcs.${cwe_id}.raw.jsonl --b-output-dir b/b_output_${cwe_id} --c-output c/out/${cwe_id}.hypotheses.jsonl --report-run-name ${run_name} --d-contexts d/memberD_verifier/02_run_with_C/verification_contexts.${cwe_id}.jsonl" \
    --d-output-dir "d/memberD_verifier/02_run_with_C/output/${run_name}" \
    --report-run-name "${run_name}" \
    --scope-compile-commands "srcs_sanitized/compile_commands.${cwe_id}.json"
}
```

The queue below is ordered by current Stage D adaptation confidence. Every listed folder has decisive source/API behavior that maps to a route-bound, project-agnostic D oracle profile, and the Juliet sidecar/shim can map the concrete run to `MAGUS_ROUTE_EXECUTED` plus the selected profile's `MAGUS_ORACLE_*` semantic markers. Do not add a CWE folder here until both pieces exist: generic profile coverage in D core and an explicit Juliet execution sidecar/shim marker path. The sidecar/shim is benchmark adapter glue only; core D must not infer profile selection from Juliet folders, filenames, or good/bad labels. `CWE114_Process_Control` and `CWE15_External_Control_of_System_or_Configuration_Setting` already ran and are intentionally not listed in this follow-up queue.

## CWE252_Unchecked_Return_Value

```bash
run_juliet_folder 'CWE252_Unchecked_Return_Value' 'cwe252'
```

## CWE404_Improper_Resource_Shutdown

```bash
run_juliet_folder 'CWE404_Improper_Resource_Shutdown' 'cwe404'
```

## CWE672_Operation_on_Resource_After_Expiration_or_Release

```bash
run_juliet_folder 'CWE672_Operation_on_Resource_After_Expiration_or_Release' 'cwe672'
```

## CWE675_Duplicate_Operations_on_Resource

```bash
run_juliet_folder 'CWE675_Duplicate_Operations_on_Resource' 'cwe675'
```

## CWE775_Missing_Release_of_File_Descriptor_or_Handle

```bash
run_juliet_folder 'CWE775_Missing_Release_of_File_Descriptor_or_Handle' 'cwe775'
```

## CWE426_Untrusted_Search_Path

```bash
run_juliet_folder 'CWE426_Untrusted_Search_Path' 'cwe426'
```

## CWE427_Uncontrolled_Search_Path_Element

```bash
run_juliet_folder 'CWE427_Uncontrolled_Search_Path_Element' 'cwe427'
```

## CWE78_OS_Command_Injection

```bash
run_juliet_folder 'CWE78_OS_Command_Injection' 'cwe78'
```

## CWE90_LDAP_Injection

```bash
run_juliet_folder 'CWE90_LDAP_Injection' 'cwe90'
```

## CWE319_Cleartext_Tx_Sensitive_Info

```bash
run_juliet_folder 'CWE319_Cleartext_Tx_Sensitive_Info' 'cwe319'
```
