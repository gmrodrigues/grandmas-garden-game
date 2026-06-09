# Part 53 — Thumb Tack

## Identity

| Field | Value |
|-------|-------|
| Part Type | `53` |
| Category | Cutting / Popping |
| Description | This thumb tack is handy for popping blimps and balloons. It can be flipped so that the point is facing up, down, or either side. |
| ANM File | `PART53.ANM` → `build/phase-4/anm/PART53.json` |
| BMP Resource | `PART53.BMP` → `build/phase-3/bitmaps/PART53_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**34 level(s)** use this part type:

- `build/phase-5/yaml/ELEV15.yaml` → `godot/assets/levels/ELEV15.yaml`
- `build/phase-5/yaml/ELEV24.yaml` → `godot/assets/levels/ELEV24.yaml`
- `build/phase-5/yaml/ELEV25.yaml` → `godot/assets/levels/ELEV25.yaml`
- `build/phase-5/yaml/ELEV26.yaml` → `godot/assets/levels/ELEV26.yaml`
- `build/phase-5/yaml/ELEV6.yaml` → `godot/assets/levels/ELEV6.yaml`
- `build/phase-5/yaml/ELEV7.yaml` → `godot/assets/levels/ELEV7.yaml`
- `build/phase-5/yaml/ELEV9.yaml` → `godot/assets/levels/ELEV9.yaml`
- `build/phase-5/yaml/HH16.yaml` → `godot/assets/levels/HH16.yaml`
- `build/phase-5/yaml/HH18.yaml` → `godot/assets/levels/HH18.yaml`
- `build/phase-5/yaml/HH19.yaml` → `godot/assets/levels/HH19.yaml`
- `build/phase-5/yaml/HH20.yaml` → `godot/assets/levels/HH20.yaml`
- `build/phase-5/yaml/HH23.yaml` → `godot/assets/levels/HH23.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HH31.yaml` → `godot/assets/levels/HH31.yaml`
- `build/phase-5/yaml/HH35.yaml` → `godot/assets/levels/HH35.yaml`
- `build/phase-5/yaml/HH39.yaml` → `godot/assets/levels/HH39.yaml`
- `build/phase-5/yaml/HH7.yaml` → `godot/assets/levels/HH7.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/HLEV6.yaml` → `godot/assets/levels/HLEV6.yaml`
- `build/phase-5/yaml/HLEV7.yaml` → `godot/assets/levels/HLEV7.yaml`
- `build/phase-5/yaml/MLEV11.yaml` → `godot/assets/levels/MLEV11.yaml`
- `build/phase-5/yaml/MLEV12.yaml` → `godot/assets/levels/MLEV12.yaml`
- `build/phase-5/yaml/MLEV13.yaml` → `godot/assets/levels/MLEV13.yaml`
- `build/phase-5/yaml/MLEV16.yaml` → `godot/assets/levels/MLEV16.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`
- `build/phase-5/yaml/MLEV8.yaml` → `godot/assets/levels/MLEV8.yaml`
- `build/phase-5/yaml/RLEV11.yaml` → `godot/assets/levels/RLEV11.yaml`
- `build/phase-5/yaml/RLEV12.yaml` → `godot/assets/levels/RLEV12.yaml`
- ... and 4 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 20 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 2 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 24 | bitmap frame width |
| `bitmap_h` | 24 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 3 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 16 |
| Total States | 8 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `6` | 0 | 0 | 24×24 | 0 |
| `7` | 1 | 1–3 (3 frames) | 24×25 | 7 |
| `8` | 4 | 4 | 24×24 | 46 |
| `9` | 5 | 5–7 (3 frames) | 24×25 | 53 |
| `11` | 8 | 8 | 24×17 | 92 |
| `10` | 9 | 9–11 (3 frames) | 25×17 | 99 |
| `13` | 12 | 12 | 24×17 | 138 |
| `12` | 13 | 13–15 (3 frames) | 78×30 | 145 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART53_f000.png :material-check:` |
| 1 | `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART53_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f000.png :material-check:` |
| 2 | `0001_0000`, `0002_0001` | `build/phase-3/bitmaps/PART53_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f001.png :material-check:` |
| 3 | `0001_0000`, `0002_0002` | `build/phase-3/bitmaps/PART53_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f002.png :material-check:` |
| 4 | `0001_0003` | `build/phase-3/bitmaps/PART53_f003.png :material-check:` |
| 5 | `0001_0003`, `0002_0000` | `build/phase-3/bitmaps/PART53_f003.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f000.png :material-check:` |
| 6 | `0001_0003`, `0002_0001` | `build/phase-3/bitmaps/PART53_f003.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f001.png :material-check:` |
| 7 | `0001_0003`, `0002_0002` | `build/phase-3/bitmaps/PART53_f003.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f002.png :material-check:` |
| 8 | `0001_0002` | `build/phase-3/bitmaps/PART53_f002.png :material-check:` |
| 9 | `0001_0002`, `0002_0000` | `build/phase-3/bitmaps/PART53_f002.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f000.png :material-check:` |
| 10 | `0001_0002`, `0002_0001` | `build/phase-3/bitmaps/PART53_f002.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f001.png :material-check:` |
| 11 | `0001_0002`, `0002_0002` | `build/phase-3/bitmaps/PART53_f002.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f002.png :material-check:` |
| 12 | `0001_0001` | `build/phase-3/bitmaps/PART53_f001.png :material-check:` |
| 13 | `0001_0001`, `0002_0000`, `0002_0000` | `build/phase-3/bitmaps/PART53_f001.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f000.png :material-check:` |
| 14 | `0001_0001`, `0002_0001` | `build/phase-3/bitmaps/PART53_f001.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f001.png :material-check:` |
| 15 | `0001_0001`, `0002_0002` | `build/phase-3/bitmaps/PART53_f001.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f002.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 29 |
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

**Thumb Tack** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART53.json` |
| Sprite PNGs | `godot/assets/sprites/PART53_f*.png` |
| Level YAML | `godot/assets/levels/ELEV15.yaml` |
| Level YAML | `godot/assets/levels/ELEV24.yaml` |
| Level YAML | `godot/assets/levels/ELEV25.yaml` |
| Level YAML | `godot/assets/levels/ELEV26.yaml` |
| Level YAML | `godot/assets/levels/ELEV6.yaml` |
| ... | +29 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART53.json` + `build/phase-5/yaml/`*
