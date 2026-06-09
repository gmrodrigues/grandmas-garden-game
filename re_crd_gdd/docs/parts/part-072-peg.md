# Part 72 — Peg

## Identity

| Field | Value |
|-------|-------|
| Part Type | `72` |
| Category | Special Mechanics |
| Description | [CREATED PART] |
| ANM File | `PART72.ANM` → `build/phase-4/anm/PART72.json` |
| BMP Resource | `PART72.BMP` → `build/phase-3/bitmaps/PART72_f*.png` |
| Created Part | Yes |
| Interactive | No |

## Levels Using This Part

*This part is not used in any built-in level (may be created dynamically at runtime).*

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 4000 | mass/density (relative scale) |
| `unk_2` | 8 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 64 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 15 | bitmap frame width |
| `bitmap_h` | 10 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical`, `proximity` |
| Destructible | No |
| Spawns | `custom` |
| Category Part Count | 15 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 12 |
| Total States | 1 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 1 | 1–11 (11 frames) | 24×7 | 7 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0001` | `build/phase-3/bitmaps/PART75_f001.png :material-check:` |
| 1 | `0001_0000` | `build/phase-3/bitmaps/PART75_f000.png :material-check:` |
| 2 | `0001_0003` | `build/phase-3/bitmaps/PART75_f003.png :material-check:` |
| 3 | `0001_0004` | `build/phase-3/bitmaps/PART75_f004.png :material-check:` |
| 4 | `0001_0006` | `build/phase-3/bitmaps/PART75_f006.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART75_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART75_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART75_f007.png :material-check:` |
| 8 | `0001_0006` | `build/phase-3/bitmaps/PART75_f006.png :material-check:` |
| 9 | `0001_0005` | `build/phase-3/bitmaps/PART75_f005.png :material-check:` |
| 10 | `0001_0006` | `build/phase-3/bitmaps/PART75_f006.png :material-check:` |
| 11 | `0001_0005` | `build/phase-3/bitmaps/PART75_f005.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 12 |
| `END_FRAME` | 12 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | Yes |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | No |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Peg** is a dynamically created (phantom) part. It is not placed by the player but spawned at runtime by another part's behavior (e.g., explosion debris, laser beam, rope end phantom).

**Peg** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part has custom spawn behavior defined in SOLVE.RES.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART72.json` |
| Sprite PNGs | `godot/assets/sprites/PART72_f*.png` |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART72.json` + `build/phase-5/yaml/`*
