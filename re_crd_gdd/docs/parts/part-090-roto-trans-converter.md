# Part 90 — Roto-Trans Converter

## Identity

| Field | Value |
|-------|-------|
| Part Type | `90` |
| Category | Special Mechanics |
| Description | This nifty contraption turns rotational energy (circular) into translational motion (back and forth movement). Hitch the little wheel to a rotational motor with a belt, then tie a rope to the eye hook and hitch it to something you want to lift or pull (like a teeter-totter, phazer trigger, or laundry basket). |
| ANM File | `PART90.ANM` → `build/phase-4/anm/PART90.json` |
| BMP Resource | `PART90.BMP` → `build/phase-3/bitmaps/PART90_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**15 level(s)** use this part type:

- `build/phase-5/yaml/ELEV16.yaml` → `godot/assets/levels/ELEV16.yaml`
- `build/phase-5/yaml/ELEV24.yaml` → `godot/assets/levels/ELEV24.yaml`
- `build/phase-5/yaml/HLEV14.yaml` → `godot/assets/levels/HLEV14.yaml`
- `build/phase-5/yaml/HLEV16.yaml` → `godot/assets/levels/HLEV16.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/MLEV13.yaml` → `godot/assets/levels/MLEV13.yaml`
- `build/phase-5/yaml/MLEV17.yaml` → `godot/assets/levels/MLEV17.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/MLEV9.yaml` → `godot/assets/levels/MLEV9.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`
- `build/phase-5/yaml/RLEV5.yaml` → `godot/assets/levels/RLEV5.yaml`
- `build/phase-5/yaml/TLEV31.yaml` → `godot/assets/levels/TLEV31.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1000 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 24 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 22 | bitmap frame width |
| `bitmap_h` | 69 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical`, `proximity` |
| Destructible | No |
| Spawns | `custom` |
| Category Part Count | 15 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 9 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 24×69 | 0 |
| `2` | 1 | 1–8 (8 frames) | 24×69 | 25 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0003`, `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART90_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f001.png :material-check:` |
| 1 | `0001_0000`, `0001_0003`, `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART90_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f001.png :material-check:` |
| 2 | `0001_0000`, `0001_0004`, `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART90_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f001.png :material-check:` |
| 3 | `0001_0000`, `0001_0005`, `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART90_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f001.png :material-check:` |
| 4 | `0001_0000`, `0001_0006`, `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART90_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f001.png :material-check:` |
| 5 | `0001_0000`, `0001_0007`, `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART90_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f001.png :material-check:` |
| 6 | `0001_0000`, `0001_0008`, `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART90_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f001.png :material-check:` |
| 7 | `0001_0000`, `0001_0009`, `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART90_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f001.png :material-check:` |
| 8 | `0001_0000`, `0001_0010`, `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART90_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART90_f001.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `3090` | 0 | `build/phase-6/raw-wav/SX_3090_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 36 |
| `END_FRAME` | 9 |
| `PLAY_SFX` | 1 |
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

**Roto-Trans Converter** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part has custom spawn behavior defined in SOLVE.RES.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART90.json` |
| Sprite PNGs | `godot/assets/sprites/PART90_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV16.yaml` |
| Level YAML | `godot/assets/levels/ELEV24.yaml` |
| Level YAML | `godot/assets/levels/HLEV14.yaml` |
| Level YAML | `godot/assets/levels/HLEV16.yaml` |
| Level YAML | `godot/assets/levels/HLEV27.yaml` |
| ... | +10 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART90.json` + `build/phase-5/yaml/`*
