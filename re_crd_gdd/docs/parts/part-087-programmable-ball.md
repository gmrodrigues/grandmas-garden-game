# Part 87 — Programmable Ball

## Identity

| Field | Value |
|-------|-------|
| Part Type | `87` |
| Category | Balls |
| Description | This ball can be programmed to vary in appearance, mass, elasticity, density, and friction. |
| ANM File | `PART87.ANM` → `build/phase-4/anm/PART87.json` |
| BMP Resource | `PART87.BMP` → `build/phase-3/bitmaps/PART87_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**11 level(s)** use this part type:

- `build/phase-5/yaml/ELEV12.yaml` → `godot/assets/levels/ELEV12.yaml`
- `build/phase-5/yaml/ELEV6.yaml` → `godot/assets/levels/ELEV6.yaml`
- `build/phase-5/yaml/ELEV9.yaml` → `godot/assets/levels/ELEV9.yaml`
- `build/phase-5/yaml/HH6.yaml` → `godot/assets/levels/HH6.yaml`
- `build/phase-5/yaml/MLEV10.yaml` → `godot/assets/levels/MLEV10.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/TLEV1.yaml` → `godot/assets/levels/TLEV1.yaml`
- `build/phase-5/yaml/TLEV7.yaml` → `godot/assets/levels/TLEV7.yaml`
- `build/phase-5/yaml/TLEV9.yaml` → `godot/assets/levels/TLEV9.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2832 | mass/density (relative scale) |
| `damping` | 200 | drag/air-resistance or density |
| `cor_q8` | 128 | COR = 0.500 |
| `radius` | 16 | collision radius in internal units |
| `sprite_w` | 0 | sprite width |
| `sprite_h` | 0 | sprite height |
| `data_offset` | 27 | offset to per-state data or count |

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
| Total Frames | 21 |
| Total States | 7 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 0 | 0 | 32×27 | 0 |
| `3` | 1 | 1 | 32×27 | 7 |
| `7` | 2 | 2 | 32×27 | 14 |
| `8` | 3 | 3 | 32×27 | 21 |
| `9` | 4 | 4 | 32×27 | 28 |
| `5` | 5 | 5–12 (8 frames) | 32×27 | 35 |
| `4` | 13 | 13–20 (8 frames) | 32×27 | 91 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0020` | `build/phase-3/bitmaps/PART87_f020.png :material-check:` |
| 1 | `0001_0018` | `build/phase-3/bitmaps/PART87_f018.png :material-check:` |
| 2 | `0001_0016` | `build/phase-3/bitmaps/PART87_f016.png :material-check:` |
| 3 | `0001_0017` | `build/phase-3/bitmaps/PART87_f017.png :material-check:` |
| 4 | `0001_0019` | `build/phase-3/bitmaps/PART87_f019.png :material-check:` |
| 5 | `0001_0008` | `build/phase-3/bitmaps/PART87_f008.png :material-check:` |
| 6 | `0001_0009` | `build/phase-3/bitmaps/PART87_f009.png :material-check:` |
| 7 | `0001_0010` | `build/phase-3/bitmaps/PART87_f010.png :material-check:` |
| 8 | `0001_0011` | `build/phase-3/bitmaps/PART87_f011.png :material-check:` |
| 9 | `0001_0012` | `build/phase-3/bitmaps/PART87_f012.png :material-check:` |
| 10 | `0001_0013` | `build/phase-3/bitmaps/PART87_f013.png :material-check:` |
| 11 | `0001_0014` | `build/phase-3/bitmaps/PART87_f014.png :material-check:` |
| 12 | `0001_0015` | `build/phase-3/bitmaps/PART87_f015.png :material-check:` |
| 13 | `0001_0000` | `build/phase-3/bitmaps/PART87_f000.png :material-check:` |
| 14 | `0001_0001` | `build/phase-3/bitmaps/PART87_f001.png :material-check:` |
| 15 | `0001_0002` | `build/phase-3/bitmaps/PART87_f002.png :material-check:` |
| 16 | `0001_0003` | `build/phase-3/bitmaps/PART87_f003.png :material-check:` |
| 17 | `0001_0004` | `build/phase-3/bitmaps/PART87_f004.png :material-check:` |
| 18 | `0001_0005` | `build/phase-3/bitmaps/PART87_f005.png :material-check:` |
| 19 | `0001_0006` | `build/phase-3/bitmaps/PART87_f006.png :material-check:` |
| 20 | `0001_0007` | `build/phase-3/bitmaps/PART87_f007.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 21 |
| `END_FRAME` | 21 |
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

**Programmable Ball** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART87.json` |
| Sprite PNGs | `godot/assets/sprites/PART87_f*.png` |
| Level YAML | `godot/assets/levels/ELEV12.yaml` |
| Level YAML | `godot/assets/levels/ELEV6.yaml` |
| Level YAML | `godot/assets/levels/ELEV9.yaml` |
| Level YAML | `godot/assets/levels/HH6.yaml` |
| Level YAML | `godot/assets/levels/MLEV10.yaml` |
| ... | +6 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART87.json` + `build/phase-5/yaml/`*
