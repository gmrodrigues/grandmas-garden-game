# Part 71 — Boxes

## Identity

| Field | Value |
|-------|-------|
| Part Type | `71` |
| Category | Containers |
| Description | This box is really five boxes in one. Program it to be glass, wooden, wicker, metal, or cardboard, which are all different sizes. Drop things inside the box, or use it to catch falling objects. |
| ANM File | `PART71.ANM` → `build/phase-4/anm/PART71.json` |
| BMP Resource | `PART71.BMP` → `build/phase-3/bitmaps/PART71_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**43 level(s)** use this part type:

- `build/phase-5/yaml/ELEV10.yaml` → `godot/assets/levels/ELEV10.yaml`
- `build/phase-5/yaml/ELEV12.yaml` → `godot/assets/levels/ELEV12.yaml`
- `build/phase-5/yaml/ELEV13.yaml` → `godot/assets/levels/ELEV13.yaml`
- `build/phase-5/yaml/ELEV16.yaml` → `godot/assets/levels/ELEV16.yaml`
- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`
- `build/phase-5/yaml/ELEV4.yaml` → `godot/assets/levels/ELEV4.yaml`
- `build/phase-5/yaml/HH16.yaml` → `godot/assets/levels/HH16.yaml`
- `build/phase-5/yaml/HH19.yaml` → `godot/assets/levels/HH19.yaml`
- `build/phase-5/yaml/HH20.yaml` → `godot/assets/levels/HH20.yaml`
- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HH25.yaml` → `godot/assets/levels/HH25.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HH28.yaml` → `godot/assets/levels/HH28.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH44.yaml` → `godot/assets/levels/HH44.yaml`
- `build/phase-5/yaml/HH47.yaml` → `godot/assets/levels/HH47.yaml`
- `build/phase-5/yaml/HH5.yaml` → `godot/assets/levels/HH5.yaml`
- `build/phase-5/yaml/HH8.yaml` → `godot/assets/levels/HH8.yaml`
- `build/phase-5/yaml/HH9.yaml` → `godot/assets/levels/HH9.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV16.yaml` → `godot/assets/levels/HLEV16.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/HLEV9.yaml` → `godot/assets/levels/HLEV9.yaml`
- `build/phase-5/yaml/MLEV17.yaml` → `godot/assets/levels/MLEV17.yaml`
- `build/phase-5/yaml/MLEV18.yaml` → `godot/assets/levels/MLEV18.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/RLEV12.yaml` → `godot/assets/levels/RLEV12.yaml`
- ... and 13 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `unk_2` | 1000 | scenery property (900 for trees, 1100-1200 for clouds/sun) |
| `bitmap_w` | 48 | bitmap frame width |
| `bitmap_h` | 32 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 5 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 9 |
| Total States | 9 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 0 | 0 | 50×32 | 0 |
| `3` | 1 | 1 | 64×32 | 13 |
| `4` | 2 | 2 | 48×48 | 26 |
| `5` | 3 | 3 | 64×48 | 39 |
| `6` | 4 | 4 | 80×64 | 52 |
| `7` | 5 | 5 | 48×32 | 59 |
| `8` | 6 | 6 | 64×32 | 66 |
| `9` | 7 | 7 | 48×48 | 73 |
| `10` | 8 | 8 | 64×48 | 80 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0005`, `0001_0000` | `build/phase-3/bitmaps/PART71_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART71_f000.png :material-check:` |
| 1 | `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART71_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART71_f006.png :material-check:` |
| 2 | `0001_0007`, `0001_0002` | `build/phase-3/bitmaps/PART71_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART71_f002.png :material-check:` |
| 3 | `0001_0008`, `0001_0003` | `build/phase-3/bitmaps/PART71_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART71_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART71_f004.png :material-check:` |
| 5 | `0001_0000` | `build/phase-3/bitmaps/PART71_f000.png :material-check:` |
| 6 | `0001_0001` | `build/phase-3/bitmaps/PART71_f001.png :material-check:` |
| 7 | `0001_0002` | `build/phase-3/bitmaps/PART71_f002.png :material-check:` |
| 8 | `0001_0003` | `build/phase-3/bitmaps/PART71_f003.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 13 |
| `END_FRAME` | 9 |
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

**Boxes** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART71.json` |
| Sprite PNGs | `godot/assets/sprites/PART71_f*.png` |
| Level YAML | `godot/assets/levels/ELEV10.yaml` |
| Level YAML | `godot/assets/levels/ELEV12.yaml` |
| Level YAML | `godot/assets/levels/ELEV13.yaml` |
| Level YAML | `godot/assets/levels/ELEV16.yaml` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| ... | +38 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART71.json` + `build/phase-5/yaml/`*
