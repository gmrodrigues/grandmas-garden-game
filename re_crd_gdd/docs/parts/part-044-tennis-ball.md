# Part 44 — Tennis Ball

## Identity

| Field | Value |
|-------|-------|
| Part Type | `44` |
| Category | Balls |
| Description | This tennis ball is very light and bouncy. |
| ANM File | `PART44.ANM` → `build/phase-4/anm/PART44.json` |
| BMP Resource | `PART44.BMP` → `build/phase-3/bitmaps/PART44_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**44 level(s)** use this part type:

- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV4.yaml` → `godot/assets/levels/ELEV4.yaml`
- `build/phase-5/yaml/HH13.yaml` → `godot/assets/levels/HH13.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH20.yaml` → `godot/assets/levels/HH20.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HH8.yaml` → `godot/assets/levels/HH8.yaml`
- `build/phase-5/yaml/HLEV15.yaml` → `godot/assets/levels/HLEV15.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV23.yaml` → `godot/assets/levels/HLEV23.yaml`
- `build/phase-5/yaml/HLEV25.yaml` → `godot/assets/levels/HLEV25.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/HLEV30.yaml` → `godot/assets/levels/HLEV30.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/HLEV4.yaml` → `godot/assets/levels/HLEV4.yaml`
- `build/phase-5/yaml/MLEV10.yaml` → `godot/assets/levels/MLEV10.yaml`
- `build/phase-5/yaml/MLEV13.yaml` → `godot/assets/levels/MLEV13.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`
- `build/phase-5/yaml/RLEV13.yaml` → `godot/assets/levels/RLEV13.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV18.yaml` → `godot/assets/levels/RLEV18.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV20.yaml` → `godot/assets/levels/RLEV20.yaml`
- `build/phase-5/yaml/RLEV25.yaml` → `godot/assets/levels/RLEV25.yaml`
- ... and 14 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1322 | mass/density (relative scale) |
| `damping` | 5 | drag/air-resistance or density |
| `cor_q8` | 192 | COR = 0.750 |
| `radius` | 16 | collision radius in internal units |
| `sprite_w` | 240 | sprite width |
| `sprite_h` | 240 | sprite height |
| `data_offset` | 15 | offset to per-state data or count |

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
| `1` | 0 | 0–7 (8 frames) | 16×15 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART44_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART44_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART44_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART44_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART44_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART44_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART44_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART44_f007.png :material-check:` |

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

**Tennis Ball** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART44.json` |
| Sprite PNGs | `godot/assets/sprites/PART44_f*.png` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV4.yaml` |
| Level YAML | `godot/assets/levels/HH13.yaml` |
| Level YAML | `godot/assets/levels/HH17.yaml` |
| Level YAML | `godot/assets/levels/HH20.yaml` |
| ... | +39 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART44.json` + `build/phase-5/yaml/`*
