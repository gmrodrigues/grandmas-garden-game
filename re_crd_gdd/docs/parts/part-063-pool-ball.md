# Part 63 — Pool Ball

## Identity

| Field | Value |
|-------|-------|
| Part Type | `63` |
| Category | Balls |
| Description | This pool ball won't move until it's hit. The harder it's hit, the farther it will roll. It isn't affected by gravity. You can program it to show any number on its surface. |
| ANM File | `PART63.ANM` → `build/phase-4/anm/PART63.json` |
| BMP Resource | `PART63.BMP` → `build/phase-3/bitmaps/PART63_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**21 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/HH1.yaml` → `godot/assets/levels/HH1.yaml`
- `build/phase-5/yaml/HH12.yaml` → `godot/assets/levels/HH12.yaml`
- `build/phase-5/yaml/HH2.yaml` → `godot/assets/levels/HH2.yaml`
- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HH3.yaml` → `godot/assets/levels/HH3.yaml`
- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV24.yaml` → `godot/assets/levels/HLEV24.yaml`
- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/HLEV3.yaml` → `godot/assets/levels/HLEV3.yaml`
- `build/phase-5/yaml/MLEV22.yaml` → `godot/assets/levels/MLEV22.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`
- `build/phase-5/yaml/RLEV2.yaml` → `godot/assets/levels/RLEV2.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV25.yaml` → `godot/assets/levels/RLEV25.yaml`
- `build/phase-5/yaml/RLEV6.yaml` → `godot/assets/levels/RLEV6.yaml`
- `build/phase-5/yaml/TLEV1.yaml` → `godot/assets/levels/TLEV1.yaml`
- `build/phase-5/yaml/TLEV20.yaml` → `godot/assets/levels/TLEV20.yaml`
- `build/phase-5/yaml/TLEV24.yaml` → `godot/assets/levels/TLEV24.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2400 | mass/density (relative scale) |
| `damping` | 40 | drag/air-resistance or density |
| `cor_q8` | 224 | COR = 0.875 |
| `radius` | 1 | collision radius in internal units |
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
| Total Frames | 16 |
| Total States | 16 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 0 | 0 | 24×23 | 0 |
| `3` | 1 | 1 | 24×23 | 7 |
| `4` | 2 | 2 | 24×23 | 14 |
| `5` | 3 | 3 | 24×23 | 21 |
| `6` | 4 | 4 | 24×23 | 28 |
| `7` | 5 | 5 | 24×23 | 35 |
| `8` | 6 | 6 | 24×23 | 42 |
| `9` | 7 | 7 | 24×23 | 49 |
| `10` | 8 | 8 | 24×23 | 56 |
| `11` | 9 | 9 | 24×23 | 63 |
| `12` | 10 | 10 | 24×23 | 70 |
| `13` | 11 | 11 | 24×23 | 77 |
| `14` | 12 | 12 | 24×23 | 84 |
| `15` | 13 | 13 | 24×23 | 91 |
| `16` | 14 | 14 | 24×23 | 98 |
| `17` | 15 | 15 | 24×23 | 105 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART63_f000.png :material-check:` |
| 1 | `0001_0002` | `build/phase-3/bitmaps/PART63_f002.png :material-check:` |
| 2 | `0001_0003` | `build/phase-3/bitmaps/PART63_f003.png :material-check:` |
| 3 | `0001_0004` | `build/phase-3/bitmaps/PART63_f004.png :material-check:` |
| 4 | `0001_0005` | `build/phase-3/bitmaps/PART63_f005.png :material-check:` |
| 5 | `0001_0006` | `build/phase-3/bitmaps/PART63_f006.png :material-check:` |
| 6 | `0001_0007` | `build/phase-3/bitmaps/PART63_f007.png :material-check:` |
| 7 | `0001_0008` | `build/phase-3/bitmaps/PART63_f008.png :material-check:` |
| 8 | `0001_0009` | `build/phase-3/bitmaps/PART63_f009.png :material-check:` |
| 9 | `0001_0010` | `build/phase-3/bitmaps/PART63_f010.png :material-check:` |
| 10 | `0001_0011` | `build/phase-3/bitmaps/PART63_f011.png :material-check:` |
| 11 | `0001_0012` | `build/phase-3/bitmaps/PART63_f012.png :material-check:` |
| 12 | `0001_0013` | `build/phase-3/bitmaps/PART63_f013.png :material-check:` |
| 13 | `0001_0014` | `build/phase-3/bitmaps/PART63_f014.png :material-check:` |
| 14 | `0001_0015` | `build/phase-3/bitmaps/PART63_f015.png :material-check:` |
| 15 | `0001_0001` | `build/phase-3/bitmaps/PART63_f001.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 16 |
| `END_FRAME` | 16 |
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

**Pool Ball** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART63.json` |
| Sprite PNGs | `godot/assets/sprites/PART63_f*.png` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/HH1.yaml` |
| Level YAML | `godot/assets/levels/HH12.yaml` |
| Level YAML | `godot/assets/levels/HH2.yaml` |
| ... | +16 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART63.json` + `build/phase-5/yaml/`*
