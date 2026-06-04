# Part 43 — Pinball

## Identity

| Field | Value |
|-------|-------|
| Part Type | `43` |
| Category | Balls |
| Description | This pinball is very hard and heavy, and doesn't bounce much. |
| ANM File | `PART43.ANM` → `build/phase-4/anm/PART43.json` |
| BMP Resource | `PART43.BMP` → `build/phase-3/bitmaps/PART43_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**78 level(s)** use this part type:

- `build/phase-5/yaml/ELEV10.yaml` → `godot/assets/levels/ELEV10.yaml`
- `build/phase-5/yaml/ELEV14.yaml` → `godot/assets/levels/ELEV14.yaml`
- `build/phase-5/yaml/ELEV17.yaml` → `godot/assets/levels/ELEV17.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/ELEV26.yaml` → `godot/assets/levels/ELEV26.yaml`
- `build/phase-5/yaml/ELEV4.yaml` → `godot/assets/levels/ELEV4.yaml`
- `build/phase-5/yaml/ELEV5.yaml` → `godot/assets/levels/ELEV5.yaml`
- `build/phase-5/yaml/HH12.yaml` → `godot/assets/levels/HH12.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH19.yaml` → `godot/assets/levels/HH19.yaml`
- `build/phase-5/yaml/HH20.yaml` → `godot/assets/levels/HH20.yaml`
- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HH22.yaml` → `godot/assets/levels/HH22.yaml`
- `build/phase-5/yaml/HH24.yaml` → `godot/assets/levels/HH24.yaml`
- `build/phase-5/yaml/HH25.yaml` → `godot/assets/levels/HH25.yaml`
- `build/phase-5/yaml/HH28.yaml` → `godot/assets/levels/HH28.yaml`
- `build/phase-5/yaml/HH30.yaml` → `godot/assets/levels/HH30.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH35.yaml` → `godot/assets/levels/HH35.yaml`
- `build/phase-5/yaml/HH38.yaml` → `godot/assets/levels/HH38.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH44.yaml` → `godot/assets/levels/HH44.yaml`
- `build/phase-5/yaml/HH47.yaml` → `godot/assets/levels/HH47.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV13.yaml` → `godot/assets/levels/HLEV13.yaml`
- `build/phase-5/yaml/HLEV15.yaml` → `godot/assets/levels/HLEV15.yaml`
- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- ... and 48 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 21428 | mass/density (relative scale) |
| `damping` | 28000 | drag/air-resistance or density |
| `cor_q8` | 96 | COR = 0.375 |
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
| Total Frames | 4 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 24×23 | 0 |
| `2` | 1 | 1–3 (3 frames) | 26×24 | 7 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART43.png :material-check:` |
| 1 | `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART43.png :material-check:`<br>`build/phase-3/bitmaps/PART43_2_f000.png :material-alert-outline: (not found)` |
| 2 | `0001_0000`, `0002_0001` | `build/phase-3/bitmaps/PART43.png :material-check:`<br>`build/phase-3/bitmaps/PART43_2_f001.png :material-alert-outline: (not found)` |
| 3 | `0001_0000`, `0002_0002` | `build/phase-3/bitmaps/PART43.png :material-check:`<br>`build/phase-3/bitmaps/PART43_2_f002.png :material-alert-outline: (not found)` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 7 |
| `END_FRAME` | 4 |
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

**Pinball** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART43.json` |
| Sprite PNGs | `godot/assets/sprites/PART43_f*.png` |
| Level YAML | `godot/assets/levels/ELEV10.yaml` |
| Level YAML | `godot/assets/levels/ELEV14.yaml` |
| Level YAML | `godot/assets/levels/ELEV17.yaml` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/ELEV26.yaml` |
| ... | +73 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART43.json` + `build/phase-5/yaml/`*
