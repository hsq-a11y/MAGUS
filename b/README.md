# Stage B Miner

Stage `B` consumes Stage `A` `samples.stats.jsonl` records plus matching `samples.llm.jsonl` evidence, mines high-support feature relations within each `api_group`, scores samples that miss those expected features, and prepares a route-aggregated C-ready audit queue.

## Input Contract

Stats input records must use:

```text
schema_version = stagea.stats.features.v1
```

Required fields:

- `project_id`
- `sample_id`
- `api_group`
- `location_id`
- `location`
- `seed_id`
- `seed_token`
- `feature_tokens`
- `feature_details`
- `source_kinds`
- `sink_types`
- `focus`
- `feature_stats`

The miner validates these fields in `b_miner.py` before mining. It does not accept the old `edge_tokens` stats schema.

The LLM evidence input must be the matching Stage `A` `samples.llm.jsonl`. Every stats `sample_id` must have exactly one matching LLM evidence record. Stage `B` fails explicitly if evidence is missing or duplicated.

## Run

From the repository root:

```bash
make run-b
```

The root Stage `A` command emits both `samples.stats.jsonl` and `samples.llm.jsonl`; Stage `B` consumes both files so it can prepare the C-ready queue. Use `make run-abcd` for the full `A -> B -> streamed C/D -> Report` chain, where Stage `D` verifies complete Stage `C` JSONL records as they are flushed and Report generates the final vulnerability report under `report/<run-name>/` from the D output. Stage `C` runs with 20 worker processes by default, overridable with `C_WORKERS` or `pipeline.py abcd --c-workers`. Stage `C` writes `P1`/`P2` records to that stream, and also writes completed `P0` records so D can route-bound verify them.

Or directly from `b/`:

```bash
python3 b_miner.py \
  --input ../a/out/samples.stats.jsonl \
  --llm-input ../a/out/samples.llm.jsonl \
  --output-dir b_output \
  --min-support 3
```

Direct runs may also set:

- `--min-support-ratio`: minimum within-`api_group` support ratio, default `0.90`
- `--risk-threshold`: `risk_score` threshold for `threshold_pass`, default `0.60`

## Outputs

Stage `B` writes:

- `patterns.json`: high-support feature patterns
- `candidates.scored.jsonl`: scored samples with missing expected features
- `candidates.for_c.jsonl`: route-aggregated C-ready records based on Stage `A` LLM evidence, with Stage `B` scoring metadata attached for Stage `C`
- `b_miner_stats.json`: aggregate run statistics

Candidate records include `schema_version = stageb.feature_candidates.v1`.

`candidates.for_c.jsonl` records include `schema_version = stageb.c_ready_candidates.v3`. Each record is grouped by `project_id + route`, keeps only the fields Stage `C` reads, stores the merged Stage `A` evidence under `llm_evidence`, and attaches route-level Stage `B` metadata under `stage_b`. The `stage_b` object contains the contributing seed candidates, route-level max scores, risk score weights, missing feature payloads, reference samples, API seed tokens, reason tags, `static_confirmation_support`, and C audit queue priority metadata. The queue is sorted first by `c_priority_score`, then by max risk, max sink score, max deviation, max rarity, route-level `threshold_pass`, and candidate count.

`c_priority_score` is a Stage `B`-only queue ordering score designed to front-load candidates that are more likely to become Stage `C` `P0`/`P1`/`P2` records when Stage `C` has a time budget. It combines the existing route risk scores with semantic signals already present in B output, including external-input source kinds (`environment`, `stdin`, `network`), high-risk source/sink seed tokens such as `getenv`, `fgets`, and `recv`, route aggregation size, and demotions for dispatcher-only `main.cpp` routes or filesystem source/sink metadata without external-input evidence. `threshold_pass` contributes a bounded evidence bonus instead of creating a separate high/low priority band, and route/file names alone are not treated as external-input source evidence. The score is written as top-level `c_priority_score` and mirrored under `stage_b.c_priority_score`; the per-signal breakdown is written as top-level `c_priority_components` and mirrored under `stage_b.c_priority_components`. B does not read Stage `C` or Stage `D` outputs at runtime.

`risk_score` is currently weighted as `0.10 * rarity_score + 0.45 * sink_score + 0.45 * pattern_deviation_score`, keeping pure rarity from dominating C audit priority. `threshold_pass` is true only when a candidate has missing high-support features and `risk_score >= risk_threshold`. Stage `C` uses that gate, the missing feature payload, reference samples, and `static_confirmation_support` as prompt evidence to constrain LLM reasoning; none of those fields is a standalone vulnerability verdict. `static_confirmation_support.supported=false` tells Stage `C` that P0 static confirmation is not supported by B unless Stage `A` evidence independently closes the source-to-sink route.

`b_miner_stats.json` is a run summary. It reports aggregate counts, expected-feature sparsity by group, `risk_threshold`, score distribution, and the candidate sort order; it is not a replacement for the detailed `samples.stats.jsonl` input or the candidate JSONL outputs.
