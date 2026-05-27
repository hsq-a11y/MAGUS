.PHONY: build-analyzer sanitize-srcs gen-srcs-compile-commands gen-input run-a run-b run-c run-d run-report run-abcd

A_INPUT ?= a/input/srcs.in.jsonl
A_OUTPUT ?= a/out/samples.raw.jsonl
ORIGINAL_SRC_ROOT ?= srcs
SRC_ROOT ?= srcs_sanitized
SANITIZE_MAP ?= $(SRC_ROOT)/juliet_sanitization_map.json
SANITIZE_FORCE ?= 1
COMPILE_COMMANDS ?= $(SRC_ROOT)/compile_commands.json
SRC_CC_OUTPUT ?= $(COMPILE_COMMANDS)
SRC_CC ?= clang
SRC_CXX ?= clang++
SRC_CC_SOURCE_GLOB ?=
SRC_CC_INCLUDE_DIR ?=
SRC_CC_DEFINE ?=
SRC_CC_FORCE_INCLUDE ?=
SRC_CC_FORCE ?=
GEN_INPUT_OUTPUT ?= a/input/srcs.in.jsonl
GEN_PROJECT_ID ?= srcs_sanitized
GEN_LANGUAGE ?= c
GEN_FRAMEWORK ?= generic
GEN_ANALYZER_JOBS ?= 2
GEN_ANALYSIS_TIMEOUT ?= 1800
GEN_CLANG ?= clang
GEN_CLANGXX ?= clang++
GEN_BC_DIR ?= bc.$(GEN_PROJECT_ID)
GEN_SOURCE_GLOB ?=
GEN_FORCE ?=
B_INPUT ?= $(shell python3 pipeline.py stats-path --raw-output $(A_OUTPUT))
B_LLM_INPUT ?= $(shell python3 pipeline.py llm-path --raw-output $(A_OUTPUT))
B_OUTPUT_DIR ?= b/b_output
C_CANDIDATES ?= $(B_OUTPUT_DIR)/candidates.for_c.jsonl
C_OUTPUT ?= c/out/hypotheses.jsonl
C_TIME_LIMIT_SECONDS ?=
C_WORKERS ?= 20
MIN_SUPPORT ?= 3
D_CONTEXTS ?=
D_OUTPUT_DIR ?= d/memberD_verifier/02_run_with_C/output
REPORT_ROOT ?= report
REPORT_RUN_NAME ?=

build-analyzer:
	python3 pipeline.py build-analyzer

sanitize-srcs:
	python3 tools/sanitize_juliet_tree.py --input $(ORIGINAL_SRC_ROOT) --output $(SRC_ROOT) $(if $(SANITIZE_FORCE),--force,)

gen-srcs-compile-commands: sanitize-srcs
	python3 tools/gen_srcs_compile_commands.py --repo-path $(SRC_ROOT) --output $(SRC_CC_OUTPUT) --cc $(SRC_CC) --cxx $(SRC_CXX) $(foreach glob,$(SRC_CC_SOURCE_GLOB),--source-glob $(glob)) $(foreach dir,$(SRC_CC_INCLUDE_DIR),--include-dir $(dir)) $(foreach define,$(SRC_CC_DEFINE),--define $(define)) $(foreach header,$(SRC_CC_FORCE_INCLUDE),--force-include $(header)) $(if $(SRC_CC_FORCE),--force,)

gen-input:
	python3 pipeline.py gen-input --repo-path $(SRC_ROOT) --compile-commands $(COMPILE_COMMANDS) --output $(GEN_INPUT_OUTPUT) --project-id $(GEN_PROJECT_ID) --language $(GEN_LANGUAGE) --framework $(GEN_FRAMEWORK) --analyzer-jobs $(GEN_ANALYZER_JOBS) --analysis-timeout $(GEN_ANALYSIS_TIMEOUT) --clang $(GEN_CLANG) --clangxx $(GEN_CLANGXX) --bc-dir $(GEN_BC_DIR) $(foreach glob,$(GEN_SOURCE_GLOB),--source-glob $(glob)) $(if $(GEN_FORCE),--force,)

run-a:
	python3 pipeline.py a --input $(A_INPUT) --output $(A_OUTPUT)

run-b:
	python3 pipeline.py b --input $(B_INPUT) --llm-input $(B_LLM_INPUT) --output-dir $(B_OUTPUT_DIR) --min-support $(MIN_SUPPORT)

run-c:
	python3 pipeline.py c --candidates $(C_CANDIDATES) --output $(C_OUTPUT) --workers $(C_WORKERS) $(if $(C_TIME_LIMIT_SECONDS),--time-limit-seconds $(C_TIME_LIMIT_SECONDS),)

run-d:
	python3 pipeline.py d $(if $(D_CONTEXTS),--contexts $(D_CONTEXTS),)

run-report:
	python3 pipeline.py report --d-output-dir $(D_OUTPUT_DIR) --report-root $(REPORT_ROOT) $(if $(REPORT_RUN_NAME),--run-name $(REPORT_RUN_NAME),)

run-abcd:
	python3 pipeline.py abcd --a-input $(A_INPUT) --a-output $(A_OUTPUT) --b-output-dir $(B_OUTPUT_DIR) --c-output $(C_OUTPUT) --min-support $(MIN_SUPPORT) --c-workers $(C_WORKERS) --report-root $(REPORT_ROOT) $(if $(REPORT_RUN_NAME),--report-run-name $(REPORT_RUN_NAME),) $(if $(C_TIME_LIMIT_SECONDS),--c-time-limit-seconds $(C_TIME_LIMIT_SECONDS),) $(if $(D_CONTEXTS),--d-contexts $(D_CONTEXTS),)
