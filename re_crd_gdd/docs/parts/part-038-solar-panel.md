# Part 38 — Solar Panel

## Identity

| Field | Value |
|-------|-------|
| Part Type | `38` |
| Category | Electrical |
| Description | This solar panel comes with its own electrical outlet. Shine a light on the panel, then plug in any electric part you want to operate. |
| ANM File | `PART38.ANM` → `build/phase-4/anm/PART38.json` |
| BMP Resource | `PART38.BMP` → `build/phase-3/bitmaps/PART38_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**16 level(s)** use this part type:

- `build/phase-5/yaml/HH27.yaml` → `godot/assets/levels/HH27.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH44.yaml` → `godot/assets/levels/HH44.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV30.yaml` → `godot/assets/levels/HLEV30.yaml`
- `build/phase-5/yaml/MLEV12.yaml` → `godot/assets/levels/MLEV12.yaml`
- `build/phase-5/yaml/MLEV14.yaml` → `godot/assets/levels/MLEV14.yaml`
- `build/phase-5/yaml/MLEV22.yaml` → `godot/assets/levels/MLEV22.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/RLEV5.yaml` → `godot/assets/levels/RLEV5.yaml`
- `build/phase-5/yaml/TLEV7.yaml` → `godot/assets/levels/TLEV7.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 71 | bitmap frame width |
| `bitmap_h` | 32 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `electrical`, `collision` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 9 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 8 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `3` | 0 | 0–3 (4 frames) | 72×32 | 0 |
| `2` | 4 | 4–7 (4 frames) | 72×32 | 52 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART38_f000.png :material-check:` |
| 1 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART38_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART38_f002.png :material-check:` |
| 2 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART38_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART38_f002.png :material-check:` |
| 3 | `0001_0000`, `0001_0002`, `0001_0002` | `build/phase-3/bitmaps/PART38_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART38_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART38_f002.png :material-check:` |
| 4 | `0001_0001` | `build/phase-3/bitmaps/PART38_f001.png :material-check:` |
| 5 | `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART38_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART38_f002.png :material-check:` |
| 6 | `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART38_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART38_f002.png :material-check:` |
| 7 | `0001_0001`, `0001_0002`, `0001_0002` | `build/phase-3/bitmaps/PART38_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART38_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART38_f002.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 16 |
| `END_FRAME` | 8 |
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

**Solar Panel** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART38.json` |
| Sprite PNGs | `godot/assets/sprites/PART38_f*.png` |
| Level YAML | `godot/assets/levels/HH27.yaml` |
| Level YAML | `godot/assets/levels/HH32.yaml` |
| Level YAML | `godot/assets/levels/HH44.yaml` |
| Level YAML | `godot/assets/levels/HLEV18.yaml` |
| Level YAML | `godot/assets/levels/HLEV30.yaml` |
| ... | +11 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART38.json` + `build/phase-5/yaml/`*
