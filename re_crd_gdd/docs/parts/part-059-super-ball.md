# Part 59 — Super Ball

## Identity

| Field | Value |
|-------|-------|
| Part Type | `59` |
| Category | Balls |
| Description | This super ball gains height with each bounce. |
| ANM File | `PART59.ANM` → `build/phase-4/anm/PART59.json` |
| BMP Resource | `PART59.BMP` → `build/phase-3/bitmaps/PART59_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**7 level(s)** use this part type:

- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH2.yaml` → `godot/assets/levels/HH2.yaml`
- `build/phase-5/yaml/HH39.yaml` → `godot/assets/levels/HH39.yaml`
- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/TLEV1.yaml` → `godot/assets/levels/TLEV1.yaml`
- `build/phase-5/yaml/TLEV5.yaml` → `godot/assets/levels/TLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1800 | mass/density (relative scale) |
| `damping` | 14 | drag/air-resistance or density |
| `cor_q8` | 512 | COR = 2.000 |
| `radius` | 16 | collision radius in internal units |
| `sprite_w` | 240 | sprite width |
| `sprite_h` | 240 | sprite height |
| `data_offset` | 23 | offset to per-state data or count |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `trap` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 9 |

## State Machine

*Single default state — no named transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 3 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 24×23 | 0 |
| `3` | 1 | 1 | 24×27 | 7 |
| `4` | 2 | 2 | 32×22 | 14 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART59_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART59_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART59_f002.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 3 |
| `END_FRAME` | 3 |
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

**Super Ball** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART59.json` |
| Sprite PNGs | `godot/assets/sprites/PART59_f*.png` |
| Level YAML | `godot/assets/levels/HH17.yaml` |
| Level YAML | `godot/assets/levels/HH2.yaml` |
| Level YAML | `godot/assets/levels/HH39.yaml` |
| Level YAML | `godot/assets/levels/HH4.yaml` |
| Level YAML | `godot/assets/levels/RLEV16.yaml` |
| ... | +2 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART59.json` + `build/phase-5/yaml/`*
