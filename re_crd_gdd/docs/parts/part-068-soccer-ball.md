# Part 68 — Soccer Ball

## Identity

| Field | Value |
|-------|-------|
| Part Type | `68` |
| Category | Balls |
| Description | This soccer ball is medium in weight and quite bouncy. |
| ANM File | `PART68.ANM` → `build/phase-4/anm/PART68.json` |
| BMP Resource | `PART68.BMP` → `build/phase-3/bitmaps/PART68_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**20 level(s)** use this part type:

- `build/phase-5/yaml/ELEV13.yaml` → `godot/assets/levels/ELEV13.yaml`
- `build/phase-5/yaml/ELEV20.yaml` → `godot/assets/levels/ELEV20.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/HH25.yaml` → `godot/assets/levels/HH25.yaml`
- `build/phase-5/yaml/HH47.yaml` → `godot/assets/levels/HH47.yaml`
- `build/phase-5/yaml/HH6.yaml` → `godot/assets/levels/HH6.yaml`
- `build/phase-5/yaml/HH8.yaml` → `godot/assets/levels/HH8.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/MLEV22.yaml` → `godot/assets/levels/MLEV22.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`
- `build/phase-5/yaml/MLEV8.yaml` → `godot/assets/levels/MLEV8.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/RLEV27.yaml` → `godot/assets/levels/RLEV27.yaml`
- `build/phase-5/yaml/TLEV1.yaml` → `godot/assets/levels/TLEV1.yaml`
- `build/phase-5/yaml/TLEV23.yaml` → `godot/assets/levels/TLEV23.yaml`
- `build/phase-5/yaml/TLEV8.yaml` → `godot/assets/levels/TLEV8.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1522 | mass/density (relative scale) |
| `damping` | 28 | drag/air-resistance or density |
| `cor_q8` | 160 | COR = 0.625 |
| `radius` | 24 | collision radius in internal units |
| `sprite_w` | 0 | sprite width |
| `sprite_h` | 0 | sprite height |
| `data_offset` | 32 | offset to per-state data or count |

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
| Total Frames | 8 |
| Total States | 1 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–7 (8 frames) | 32×32 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART68_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART68_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART68_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART68_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART68_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART68_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART68_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART68_f007.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 8 |
| `END_FRAME` | 8 |
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

**Soccer Ball** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART68.json` |
| Sprite PNGs | `godot/assets/sprites/PART68_f*.png` |
| Level YAML | `godot/assets/levels/ELEV13.yaml` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/HH25.yaml` |
| Level YAML | `godot/assets/levels/HH47.yaml` |
| ... | +15 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART68.json` + `build/phase-5/yaml/`*
