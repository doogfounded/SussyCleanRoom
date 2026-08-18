# EXPERIMENTS_RUNBOOK

This runbook tells contributors exactly what to test, how to run the existing probes (Experiments 005–008), what to capture, and how to report results so your experiments are reproducible and easy to verify.

Keep this short and actionable — copy the commands exactly and paste outputs into the issue template at the end.

---

## Quick goals
- Reproduce the experiments that probe Regions 2, 3, and 4.
- For each test case capture: consumed bytes (`ctx.cursor`), overflow flag (`ctx.has_overflow`), `res.next` (next-state), and `current_state` if it changes.
- Run the exact input combinations below and attach raw outputs to an issue using the provided template.

---

## Build (examples)
Note: the repository includes `clean_src/test_harness.cpp` probes. If a single translation unit causes build issues, the examples below exclude `FUN_102b23f0.cpp` which is known to cause issues in some environments.

### Linux / macOS (bash)

```bash
mkdir -p build outputs
SRCS=$(ls clean_src/*.cpp | grep -v 'FUN_102b23f0.cpp' || true)
# compile into a single harness (may take a moment)
g++ -std=c++20 -O2 -I./clean_src $SRCS -o build/test_harness
```

### Windows (PowerShell)

```powershell
New-Item -ItemType Directory -Path build,outputs -Force | Out-Null
$srcs = Get-ChildItem clean_src/*.cpp | Where-Object { $_.Name -ne 'FUN_102b23f0.cpp' } | ForEach-Object { $_.FullName }
g++ -std=c++20 -O2 -I./clean_src $srcs -o build\test_harness.exe
```

If the repo's harness is already set up to compile only the selected probes, follow its existing build commands instead of the generic compilation above.

---

## Run and capture

After building, run the harness and capture stdout/stderr to a file to attach to issues.

Linux/macOS:

```bash
./build/test_harness > outputs/exp_run.txt 2>&1
```

Windows (PowerShell):

```powershell
.\build\test_harness.exe > outputs\exp_run.txt 2>&1
```

If the harness contains multiple probe functions, either edit `clean_src/test_harness.cpp` to run a specific probe, or use the harness's CLI if one exists.

---

## Exact test cases (copy these inputs)
The probes print per-test telemetry lines. For every test case below, make sure the harness prints the four telemetry fields (or add prints to the harness):
- consumed (ctx.cursor) — integer
- overflow (ctx.has_overflow) — YES/NO or boolean
- next-state (res.next) — hex
- current_state (if printed) — hex

### Experiment 007 — Region 4 (even-parity ladder)
Inputs:
- Byte0 = 0x00
- Byte1 = 0x00 (even parity path)
- Byte2 ∈ {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08}

What to expect (from captured runs):
- Byte2 == 0x01 → consumed ≈ 4
- Byte2 ∈ {0x02..0x08} → consumed ≈ 6
- next-state observed in captured runs: 0x103281d0
- overflow: NO

What to record: one line per Byte2 with consumed, overflow, next-state.

### Experiment 008 — Region 4 (odd-parity sweep)
Inputs:
- Byte0 = 0x00
- Byte1 = 0x01 (odd parity path)
- Byte2 ∈ {0x00, 0x01, 0x02, 0x03, 0x04, 0x08, 0x7F, 0xFF}

What to expect (from captured runs):
- consumed = 2 for all tested Byte2 values
- overflow: NO
- next-state: 0x103281d0

### Experiment 005 — Region 2 (Byte2 length modifier — broader sweep)
Inputs (recommended exhaustive-ish sweep):
- Byte0 ∈ {0x00, 0x01}
- Byte1 ∈ {0x00, 0x01}
- Byte2 ∈ {0x00,0x01,0x02,0x03,0x04,0x08,0x10,0x24,0x26,0x7F,0xFF}

What to look for / interpretation:
- If `consumed == 38` when `Byte0 == 0x01` → Byte0 likely an activation flag unlocking 38B block.
- If `consumed` scales dynamically with Byte2 → Byte2 likely a payload length selector.
- If consumed remains small (2–3B) for all combos → 38B block likely requires a larger magic prefix across Bytes 0–3.

Record: every test line where `consumed >= 4` (highlight if `consumed == 38`).

### Experiment 006 — Region 3 (framing & dispatch)
Inputs:
- Byte0 ∈ {0x00,0x01}
- Byte1 ∈ {0x00,0x01}
- Byte2 ∈ {0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x7F,0xFF}

What to classify:
- `consumed == 0` → yield / no progress
- `consumed <= 3` → header-path (framing header only)
- `consumed > 3` → expanded frame (record amount)
- If none of the Byte2 values cause `consumed > 3` → region might be a state-keyed compute block rather than a framing block

Record counts for each category and highlight any expanded frames.

---

## Output format recommendation (machine-parsable)
Modify the harness or add a single-line JSON-like print per test case to make parsing easy. Example line to append after each test-case run:

{"b0":"0x00","b1":"0x01","b2":"0x02","consumed":2,"overflow":false,"next":"0x103281d0","current_state":"0x10288d10"}

Saving `outputs/exp_run.txt` with these lines makes it trivial to extract results and generate a summary table.

---

## Short issue report template (copy into a new issue)

Title: Repro: Exp00X — Region N probe — [one-line conclusion]

Body (paste this and fill the sections):

- Environment
  - OS: [e.g. Ubuntu 22.04]
  - g++ version: [paste `g++ --version`]
  - Commit SHA used: [paste commit hash]
- Commands run (copy your exact build + run commands):
  - ...
- Inputs tested (list exact Byte0/Byte1/Byte2 combinations you ran):
  - ...
- Raw output: attach `outputs/exp_run.txt` or paste relevant excerpts (include the JSON lines if available)
- Summary table (one line per tested input):
  - Byte0 Byte1 Byte2 → consumed, overflow, next-state
- Interpretation / short conclusion (1–3 sentences):
  - ...
- Notes / observations (optional):
  - ...

---

## Quick sanity checklist
- Did the binary compile? If not, paste compiler errors in the issue.
- Did the harness print `ctx.cursor` for each test? If not, add prints to `clean_src/test_harness.cpp`.
- If results differ from expected (e.g., from Exp007/008 captured outputs), re-run the single-case with `-g` or print more debug and attach the full trace.

---

## Optional improvements to add (good follow-up PR tasks)
- Add `scripts/run_all.sh` and `scripts/run_all.ps1` that compile and run each probe, saving outputs/expected/ and returning non-zero on mismatch.
- Add a GitHub Actions workflow that builds and runs the probes and uploads outputs as artifacts.
- Add small verifiers that diff actual vs expected outputs and return non-zero on mismatch.
- Add a single `test_harness` CLI that accepts `--exp 005`/`--exp 006` etc. and prints JSON lines.

---

## Where to look in the code
- Probes: `clean_src/test_harness.cpp` (functions: `probe_r2_byte2_sweep`, `probe_r3_framing`, `probe_r4_ladder`, `probe_r4_odd_path`)
- Region handlers: search for `ProcessCoreLoopRegion_Case2`, `ProcessCoreLoopRegion_Case3`, `ProcessCoreLoopRegion_Case4` in `clean_src/` to find the implementation files.
- Telemetry fields: `BufferContext` (`cursor`, `has_overflow`) and `RegionResult` (`next`)

---

If you want, I can prepare the runnable scripts and a GitHub Actions workflow and open a PR with them (build/run scripts, a simple verifier, and `.github/ISSUE_TEMPLATE/experiment_report.md`). Say "Create scripts + CI" and I'll add those files next.
