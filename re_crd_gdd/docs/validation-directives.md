# TIM2 Validation Directives

Complete reference for all validation scripts, patterns, and data dependencies
in the TIM2 reverse engineering and reimplementation project.

## What Are We Validating?

**The code IS the spec.** We are not validating that code matches a written
specification. Instead, the Python implementation in `tim2_editor/` IS the
specification — a testable, executable model of how TIM2 works. Validation
scripts check that this model is internally consistent and complete.

```
Spec (in human language)
    ↓ expressed as
Python implementation (tim2_editor/engine/, tim2_editor/sprites/)
    ↓ checked by
Validation scripts (scripts/phase-*/, tim2_editor/validate_*.py)
    ↓ confirms
Spec (internal consistency + completeness)
```

This means:
- When behavior is ambiguous, the implementation decides — then the
  validation directives document what the implementation does, not what
  it "should" do.
- When the implementation reveals inconsistencies in our understanding,
  the validation directives are updated to reflect the discovered behavior.
- Gaps in validation = gaps in the spec — a missing test means an
  unverified part of the spec.

In short: **code is ground truth, docs describe what the code does.**

## Code Misbehavior → Documentation Enhancement

Every time the implementation behaves differently from what the docs describe,
the code is correct and the docs are wrong. Every discovered discrepancy
is an opportunity to improve the documentation. This is not a bug-fixing
process — it is a spec-discovery process.

**The 4-step process when code "misbehaves":**

1. **Investigate** — Run targeted tests, add debug traces, or step through
   the code to understand what the implementation actually does. Do not
   assume the code is wrong.

2. **Update the docs** — Modify the relevant spec document to describe
   the discovered behavior, not the assumed behavior. The docs must match
   what the code does.

3. **Add a validation test case** — Write a test that captures the
   discovered behavior. This test becomes the new spec reference.

4. **Announce the discovery** — Note the discrepancy in the experiment
   journal (E-NNN) and the relevant R-NNN findings report.

**What counts as "misbehavior"?**

- Collision matrix gaps (e.g., Scenery parts passing through Walls)
- State machine edge cases (unexpected state transitions under certain conditions)
- Physics corner cases (parts with COR=0 settling, gravity interactions)
- Data format surprises (PAR file variants, ANM bytecode patterns)
- Missing features (animations not playing, sounds not triggering)

**Examples from this project:**

| Discovery | Doc Updated | Test Added |
|-----------|-------------|------------|
| Ball passes through floor → surface clamping | Collision Matrix Specification | wall collision test |
| No horizontal velocity integration | Physics integration section | wall bounce test |
| Floor top is `y`, not `y+height` | validate_spec.py comment | surface clamp test |
| Ball_right beyond wall → bounds clamp | viewport bounds section | right wall test |

Discrepancies are not failures — they are discoveries. Every discovery
strengthens the spec.

## Validation Pyramid

```
                              ┌─────────────────┐
                              │  L5: Full Game  │  game.py, sandbox.py
                              │  (interactive)  │  manual play-testing
                              └────────┬────────┘
                          ┌────────────┴────────────┐
                          │  L4: Integration Tests  │  validate-all.py
                          │  (206 levels, 147 parts)│  26 checks
                          └────────────┬────────────┘
                     ┌─────────────────┴─────────────────┐
                     │  L3: Cross-Reference Checks       │  validate-state-machine.py
                     │  (SOLVE.RES ↔ ANM ↔ matrix)       │  cross-source consistency
                     └─────────────────┬─────────────────┘
                ┌──────────────────────┴──────────────────────┐
                │  L2: Unit Checks                           │  validate-part-specs.py
                │  (per-file structural, field existence)     │  validate-part-struct.py
                └──────────────────────┬──────────────────────┘
           ┌───────────────────────────┴───────────────────────────┐
           │  L1: Sentinel Files                                  │  acceptance-report.py
           │  (phase completion markers, build dir existence)     │  status.txt, .*-complete
           └───────────────────────────────────────────────────────┘
```

## Standard Patterns

Every validation script must follow these conventions:

### check() Assertion Pattern

```python
pass_count = 0
fail_count = 0
results = []

def check(name: str, condition: bool, detail: str = ""):
    global pass_count, fail_count
    if condition: pass_count += 1
    else: fail_count += 1
    results.append({"name": name, "status": "PASS" if condition else "FAIL",
                    "detail": detail})
    symbol = "✅" if condition else "❌"
    if not condition:
        print(f"  [{symbol}] {name}{' — ' + detail if detail else ''}")
```

### JSON Report Output

Every validation writes a machine-readable report:

```python
report = {
    "milestone": "MXX",
    "pass_count": pass_count,
    "fail_count": fail_count,
    "results": results,
    # ... data-specific fields ...
}
with open(BUILD_ROOT / "phase-NN" / "report-name.json", "w") as f:
    json.dump(report, f, indent=2)
```

### Exit Code Contract

```python
sys.exit(0 if fail_count == 0 else 1)
```

### Logger Class (for journey tests)

```python
class Logger:
    def __init__(self, name):
        LOGS_DIR.mkdir(parents=True, exist_ok=True)
        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
        self.path = LOGS_DIR / f"JNN_{ts}.log"
        self.f = open(self.path, "w")

    def log(self, msg): print(msg); self.f.write(msg + "\n")
    def check(self, name, condition, detail=""): ...
    def close(self): self.f.close()
```

### Interactive Mode

All journey scripts support `--interactive`:

```python
INTERACTIVE = "--interactive" in sys.argv
if INTERACTIVE:
    # Show pygame window, accept user input
```

### Idempotency Pattern (from common.py)

```python
def is_up_to_date(output: Path, inputs: list[Path]) -> bool:
    if not output.exists():
        return False
    out_mtime = output.stat().st_mtime
    return all(inp.stat().st_mtime <= out_mtime for inp in inputs)
```

---

## Data Source Dependency Graph

```
RESOURCE.MAP + RESOURCE.001
  └── phase-1 extract ──→ extracted/ (1,467 files)
        ├── phase-2 hash ──→ tim2_hash.py, resource-lookup.json
        ├── phase-3 decode ──→ bitmaps/ (3,054 PNGs) + palettes/ (27 palettes)
        ├── phase-4 parse ──→ anm/ (433 JSONs with Section A/B/C/D)
        ├── phase-5 parse ──→ yaml/ (206 level YAMLs)
        └── phase-6 analyse ──→ sx-report.json, raw-wav/, fm-validation/

SOLVE.RES (binary)
  └── phase-16 decode ──→ solve-decoded.json (52 interactive parts)

PART{N}.PAR files
  └── phase-9 decode ──→ part-properties.json (mass, COR, dimensions)

ANM JSONs + solve-decoded.json + catalog
  ├── phase-16 merge ──→ godot/behaviors.json + godot/categories.json
  ├── phase-17 generate ──→ docs/parts/part-NNN-name.md (147 files)
  └── phase-19 cross-ref ──→ docs/state-machine-specification.md

behaviors.json + catalog + properties + yaml/
  ├── phase-18 validate ──→ build/phase-18/validation-report.json
  └── phase-20 journeys ──→ docs/user-journey-specification.md
```

---

## Validation Script Index

| # | Script | Lvl | Inputs | Checks | Output |
|---|--------|-----|--------|--------|--------|
| 1 | `phase-8/01-acceptance-report.py` | L1 | sentinel files | 9 | `build/phase-8/acceptance-report.json` |
| 2 | `phase-9/01-validate-part-struct.py` | L2 | 203 YAML files | field counts | stdout |
| 3 | `phase-17/02-validate-part-specs.py` | L2 | 147 markdown files + JSON | 2,406 | `build/phase-17/validation-report.json` |
| 4 | `phase-18/01-validate-all.py` | L4 | 206 YAML + 4 JSON files | 26 | `build/phase-18/validation-report.json` |
| 5 | `phase-19/01-validate-state-machine.py` | L3 | solve + matrix + ANM JSONs | 12 | `build/phase-19/state-machine-report.json` |
| 6 | `phase-20/01-validate-user-journeys.py` | L4 | 14 journey scripts | per-journey | `build/phase-20/user-journey-report.json` |
| 7 | `phase-20/journeys/j01_signin.py` | L4 | ANM + BMP + interactive | 7 | `build/phase-20/logs/J01_*.log` |
| 8–19 | `phase-20/journeys/j02–j14_*.py` | L4 | per-journey data | 5–8 each | `build/phase-20/logs/JNN_*.log` |
| 20 | `tim2_editor/validate_spec.py` | L4 | engine modules | 31 | `build/phase-14/validation-results.json` |
| 21 | `tim2_editor/test_deterministic.py` | L4 | engine modules | 11 | `build/phase-14/deterministic-results.json` |
| 22 | `tim2_editor/test_level.py` | L4 | ELEV1.yaml | 27 | stdout |
| 23 | `tim2_editor/sandbox.py` | L5 | interactive | manual | user observation |

---

## Validation Categories

### Category 1: Asset Integrity

| What | How |
|------|-----|
| ANM files exist | `ANM_DIR / "{name}.json"` exists |
| BMP PNGs exist | `BITMAPS_DIR / "{bmp}_f{sub:03d}.png"` exists |
| Sound WAVs exist | `build/phase-6/raw-wav/SX_{id}_11025.wav` exists |
| Level YAMLs exist | `yaml_dir.glob("*.yaml")` |
| Palette JSONs exist | `palettes_dir.glob("*.json")` |

### Category 2: Format Integrity

| What | How |
|------|-----|
| ANM has Section C | `len(anm["section_c"]) > 0` |
| ANM has Section B | `len(anm["section_b"]) > 0` |
| ANM has Section D | `len(anm["section_d"]) > 0` |
| YAML parts have required fields | check `part_type`, `x`, `y`, `flags`, `dimensions` |
| JSON has expected keys | check top-level keys exist |

### Category 3: Cross-Reference Consistency

| What | How |
|------|-----|
| SOLVE.RES → ANM state | `anm_state` values exist in ANM Section C |
| behaviors.json ↔ part-properties.json | compare `num_frames`, `num_states` |
| behaviors.json ↔ part-name-catalog.json | compare `anm_name`, `category` |
| Trigger chains resolve | `other` values in SOLVE.RES reference valid states |
| Sprites → PNGs | sprite IDs resolve to PNG file paths |
| Sounds → WAVs | sound IDs resolve to WAV file paths |

### Category 4: Behavioral Integrity

| What | How |
|------|-----|
| State machine cycles correctly | `advance_state()` produces expected sequence 0→1→...→7→0 |
| Gravity integration is correct | verify `pos_y += vel_y >> 9` after N ticks |
| AABB collision responds | verify push-apart, velocity reflection |
| Rope constraint enforced | verify distance ≤ max_len |
| Deterministic RNG | verify identical sequence across runs |
| Save/restore bit-identical | verify same final state as continuous run |
| Collision matrix: category pairs | `world.step()` fires only for valid pairs (Balls↔Walls, Explosives↔Any, etc.) |
| Surface clamping on collision | moving part's bottom == obstacle's top when falling; top == obstacle's bottom when rising |
| Static obstacle immobility | part with `flags_1=0x2000\|0x4000` never moves during collision resolution |
| Non-interacting categories pass-through | Scenery, Created, Rope parts do NOT trigger collision at all |

### Category 5: Coverage

| What | How |
|------|-----|
| All parts have behaviors | `registry.get_behavior(pt)` returns valid data |
| All parts have ANM | `anm_path.exists()` for all part types |
| All parts have PNGs | at least 1 sprite resolves per part |
| All levels load | `load_yaml(path)` succeeds for all 206 |
| All categories have rules | `categories.json` has entry for every category used |

---

## Collision Matrix Specification

The collision system does NOT use generic AABB for all part pairs.
Interactions are gated by a category-pair matrix derived from TIM2's
behavior system and SOLVE.RES triggers.

### Valid Interaction Pairs

| Moving Category | Obstacle Category | Result |
|---|---|---|
| Balls | Walls / Floors | Full AABB bounce with COR from part-properties.json |
| Balls | Inclines | Surface-normal deflection |
| Balls | Balloons / Airships | State transition (pop) + AABB bounce |
| Balls | Characters | State transition (eat/activate) |
| Explosives / Projectiles | Any moving part | Detonation + chain reaction |
| Light / Flame Sources | Balloons / Airships | Proximity pop (not AABB collision) |
| Cutting / Popping | Balloons / Airships | State transition (pop) on AABB overlap |
| Lasers / Optics | Any moving part | Beam interaction (not AABB) |
| Rotating Power Sources | Ropes / Belts | Force transmission (not AABB) |
| All other | Walls / Floors | AABB bounce only (no state transition) |

All other category pairs → **no collision** (skip in nested loop).

### Surface Clamping Rule

When a valid collision is detected between moving part A and static
obstacle B, the separation is computed as:

```
if vel_y >= 0:                     # falling downward
    a.y = b.y - a.height_1         # clamp A's bottom to B's top
else:                              # rising upward
    a.y = b.y + b.height_1         # clamp A's top to B's bottom
```

This prevents incremental penetration — the part is placed exactly at
the surface boundary in one frame.

### Static Obstacle Invariance

Parts with flag bits `0x2000` or `0x4000` in `flags_1` are collision
obstacles but NEVER have their position, velocity, or state modified
during collision resolution. Only the moving part is adjusted.

### Flag Semantics for Collision

| flags_1 bits | Behavior |
|---|---|
| `0x0000` | Static scenery — no collision, no physics |
| `0x1000` | Moving — full physics, collision subject |
| `0x2000` | Fixed static — collision obstacle, never moves |
| `0x4000` | Fixed static (alt) — same as 0x2000 |
| `0x6000` | Fixed + puzzle icon — collision obstacle, never moves |

### Validation Test Cases

Each valid category pair must be tested with:
1. A 2-part level (one moving, one static) with known positions
2. One frame of `world.step()`
3. Assertion: part is surface-clamped (gap ≤ 2px)
4. Assertion: static part position unchanged
5. Assertion: state counter advanced by 1

Each non-interacting pair must be tested with:
1. A 2-part level where the moving part overlaps the static part
2. One frame of `world.step()`
3. Assertion: part passes through (state unchanged, position continues)

---

## Running All Validations

```bash
# Full validation suite (headless)
pipenv run python3 scripts/phase-8/01-acceptance-report.py
pipenv run python3 scripts/phase-9/01-validate-part-struct.py
pipenv run python3 scripts/phase-17/02-validate-part-specs.py
pipenv run python3 scripts/phase-18/01-validate-all.py
pipenv run python3 scripts/phase-19/01-validate-state-machine.py
pipenv run python3 scripts/phase-20/01-validate-user-journeys.py
pipenv run python3 tim2_editor/validate_spec.py
pipenv run python3 tim2_editor/test_deterministic.py

# Interactive testing
pipenv run python3 tim2_editor/sandbox.py          # Part viewer
pipenv run python3 tim2_editor/game.py ELEV1       # Play a level
pipenv run python3 tim2_editor/main.py             # Editor mode

# Single journey interactive
pipenv run python3 scripts/phase-20/journeys/j01_signin.py --interactive
```

## Adding a New Validation

1. Choose the right layer (L1-L5)
2. Create script under `scripts/phase-NN/` or `tim2_editor/`
3. Follow the check() pattern for assertions
4. Write JSON report to `build/phase-NN/report-name.json`
5. Follow idempotency: skip if output is newer than inputs
6. Exit 0 on pass, 1 on fail
7. If interactive: support `--interactive` flag
8. Add to this document's script index
9. Update MILESTONES.md with new milestone

## See Also

- `MILESTONES.md` — Project milestone tracker
- `docs/godot-specification.md` — Godot implementation specification
- `docs/state-machine-specification.md` — State machine cross-reference
- `docs/user-journey-specification.md` — All user journeys
- `docs/parts/README.md` — Per-part behavior reference
- `scripts/lib/common.py` — Shared helpers (ensure_build_dir, is_up_to_date, atomic_write)
