# Part 88 — Accelerator Tube

## Identity

| Field | Value |
|-------|-------|
| Part Type | `88` |
| Category | Pipe Systems |
| Description | This accelerator tube can be connected to any type of large pipe. It will speed up or change the direction of any object passing through it. |
| ANM File | `PART88.ANM` → `build/phase-4/anm/PART88.json` |
| BMP Resource | `PART88.BMP` → `build/phase-3/bitmaps/PART88_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**38 level(s)** use this part type:

- `build/phase-5/yaml/ELEV13.yaml` → `godot/assets/levels/ELEV13.yaml`
- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV22.yaml` → `godot/assets/levels/ELEV22.yaml`
- `build/phase-5/yaml/ELEV26.yaml` → `godot/assets/levels/ELEV26.yaml`
- `build/phase-5/yaml/ELEV6.yaml` → `godot/assets/levels/ELEV6.yaml`
- `build/phase-5/yaml/HH1.yaml` → `godot/assets/levels/HH1.yaml`
- `build/phase-5/yaml/HH2.yaml` → `godot/assets/levels/HH2.yaml`
- `build/phase-5/yaml/HH25.yaml` → `godot/assets/levels/HH25.yaml`
- `build/phase-5/yaml/HH28.yaml` → `godot/assets/levels/HH28.yaml`
- `build/phase-5/yaml/HH3.yaml` → `godot/assets/levels/HH3.yaml`
- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HH9.yaml` → `godot/assets/levels/HH9.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV19.yaml` → `godot/assets/levels/HLEV19.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/HLEV6.yaml` → `godot/assets/levels/HLEV6.yaml`
- `build/phase-5/yaml/HLEV7.yaml` → `godot/assets/levels/HLEV7.yaml`
- `build/phase-5/yaml/MLEV14.yaml` → `godot/assets/levels/MLEV14.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`
- `build/phase-5/yaml/MLEV29.yaml` → `godot/assets/levels/MLEV29.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/MLEV4.yaml` → `godot/assets/levels/MLEV4.yaml`
- `build/phase-5/yaml/MLEV5.yaml` → `godot/assets/levels/MLEV5.yaml`
- `build/phase-5/yaml/MLEV6.yaml` → `godot/assets/levels/MLEV6.yaml`
- `build/phase-5/yaml/MLEV7.yaml` → `godot/assets/levels/MLEV7.yaml`
- `build/phase-5/yaml/MLEV8.yaml` → `godot/assets/levels/MLEV8.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- ... and 8 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 38 | bitmap frame width |
| `bitmap_h` | 32 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 4 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 10 |
| Total States | 4 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `20` | 0 | 0 | 40×48 | 0 |
| `16` | 1 | 1–4 (4 frames) | 40×48 | 19 |
| `21` | 5 | 5 | 48×38 | 95 |
| `22` | 6 | 6–9 (4 frames) | 48×38 | 114 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0018`, `0001_0019`, `0001_0020` | `build/phase-3/bitmaps/PART88_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f019.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f020.png :material-check:` |
| 1 | `0001_0018`, `0001_0019`, `0001_0020` | `build/phase-3/bitmaps/PART88_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f019.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f020.png :material-check:` |
| 2 | `0001_0018`, `0001_0019`, `0001_0021` | `build/phase-3/bitmaps/PART88_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f019.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f021.png :material-check:` |
| 3 | `0001_0018`, `0001_0019`, `0001_0022` | `build/phase-3/bitmaps/PART88_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f019.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f022.png :material-check:` |
| 4 | `0001_0018`, `0001_0019`, `0001_0023` | `build/phase-3/bitmaps/PART88_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f019.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f023.png :material-check:` |
| 5 | `0001_0000`, `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART88_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f001.png :material-check:` |
| 6 | `0001_0000`, `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART88_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f001.png :material-check:` |
| 7 | `0001_0000`, `0001_0001`, `0001_0003` | `build/phase-3/bitmaps/PART88_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f003.png :material-check:` |
| 8 | `0001_0000`, `0001_0001`, `0001_0004` | `build/phase-3/bitmaps/PART88_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f004.png :material-check:` |
| 9 | `0001_0000`, `0001_0001`, `0001_0005` | `build/phase-3/bitmaps/PART88_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART88_f005.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 30 |
| `END_FRAME` | 10 |
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

**Accelerator Tube** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART88.json` |
| Sprite PNGs | `godot/assets/sprites/PART88_f*.png` |
| Level YAML | `godot/assets/levels/ELEV13.yaml` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV22.yaml` |
| Level YAML | `godot/assets/levels/ELEV26.yaml` |
| Level YAML | `godot/assets/levels/ELEV6.yaml` |
| ... | +33 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART88.json` + `build/phase-5/yaml/`*
