# Part 28 — Baseball

## Identity

| Field | Value |
|-------|-------|
| Part Type | `28` |
| Category | Balls |
| Description | This baseball is pretty light and not very bouncy. |
| ANM File | `PART28.ANM` → `build/phase-4/anm/PART28.json` |
| BMP Resource | `PART28.BMP` → `build/phase-3/bitmaps/PART28_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**47 level(s)** use this part type:

- `build/phase-5/yaml/ELEV10.yaml` → `godot/assets/levels/ELEV10.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/ELEV4.yaml` → `godot/assets/levels/ELEV4.yaml`
- `build/phase-5/yaml/HH10.yaml` → `godot/assets/levels/HH10.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH20.yaml` → `godot/assets/levels/HH20.yaml`
- `build/phase-5/yaml/HH24.yaml` → `godot/assets/levels/HH24.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV2.yaml` → `godot/assets/levels/HLEV2.yaml`
- `build/phase-5/yaml/HLEV24.yaml` → `godot/assets/levels/HLEV24.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/MLEV15.yaml` → `godot/assets/levels/MLEV15.yaml`
- `build/phase-5/yaml/MLEV21.yaml` → `godot/assets/levels/MLEV21.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/MLEV29.yaml` → `godot/assets/levels/MLEV29.yaml`
- `build/phase-5/yaml/MLEV6.yaml` → `godot/assets/levels/MLEV6.yaml`
- `build/phase-5/yaml/RLEV13.yaml` → `godot/assets/levels/RLEV13.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/RLEV29.yaml` → `godot/assets/levels/RLEV29.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`
- ... and 17 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2000 | mass/density (relative scale) |
| `damping` | 9 | drag/air-resistance or density |
| `cor_q8` | 112 | COR = 0.438 |
| `radius` | 24 | collision radius in internal units |
| `sprite_w` | 240 | sprite width |
| `sprite_h` | 240 | sprite height |
| `data_offset` | 18 | offset to per-state data or count |

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
| `1` | 0 | 0–7 (8 frames) | 24×18 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART28_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART28_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART28_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART28_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART28_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART28_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART28_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART28_f007.png :material-check:` |

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

**Baseball** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART28.json` |
| Sprite PNGs | `godot/assets/sprites/PART28_f*.png` |
| Level YAML | `godot/assets/levels/ELEV10.yaml` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/ELEV4.yaml` |
| Level YAML | `godot/assets/levels/HH10.yaml` |
| Level YAML | `godot/assets/levels/HH17.yaml` |
| ... | +42 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART28.json` + `build/phase-5/yaml/`*
