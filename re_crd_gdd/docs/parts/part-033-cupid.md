# Part 33 — Cupid

## Identity

| Field | Value |
|-------|-------|
| Part Type | `33` |
| Category | Characters |
| Description | Well, well, if it isn't Cupid, dropping in for Valentine's Day! Bump him to make him fly around. Any balloons that touch his arrow will pop. |
| ANM File | `PART33.ANM` → `build/phase-4/anm/PART33.json` |
| BMP Resource | `PART33.BMP` → `build/phase-3/bitmaps/PART33_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

*This part is not used in any built-in level (may be created dynamically at runtime).*

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 11 | mass/density (relative scale) |
| `unk_2` | 4 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 8 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 67 | bitmap frame width |
| `bitmap_h` | 50 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `proximity` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 8 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 5 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 72×50 | 0 |
| `2` | 1 | 1–4 (4 frames) | 72×50 | 19 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0002`, `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART33_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART33_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART33_f000.png :material-check:` |
| 1 | `0001_0002`, `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART33_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART33_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART33_f000.png :material-check:` |
| 2 | `0001_0004`, `0001_0003`, `0001_0000` | `build/phase-3/bitmaps/PART33_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART33_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART33_f000.png :material-check:` |
| 3 | `0001_0002`, `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART33_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART33_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART33_f000.png :material-check:` |
| 4 | `0001_0005`, `0001_0006`, `0001_0000` | `build/phase-3/bitmaps/PART33_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART33_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART33_f000.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 15 |
| `END_FRAME` | 5 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | No |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | No |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Cupid** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART33.json` |
| Sprite PNGs | `godot/assets/sprites/PART33_f*.png` |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART33.json` + `build/phase-5/yaml/`*
