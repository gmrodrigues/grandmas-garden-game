# Part 73 — Trap Door

## Identity

| Field | Value |
|-------|-------|
| Part Type | `73` |
| Category | Special Mechanics |
| Description | This trap door drops open when heavy objects land on top of it. |
| ANM File | `PART73.ANM` → `build/phase-4/anm/PART73.json` |
| BMP Resource | `PART73.BMP` → `build/phase-3/bitmaps/PART73_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**33 level(s)** use this part type:

- `build/phase-5/yaml/ELEV10.yaml` → `godot/assets/levels/ELEV10.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/ELEV26.yaml` → `godot/assets/levels/ELEV26.yaml`
- `build/phase-5/yaml/ELEV6.yaml` → `godot/assets/levels/ELEV6.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH19.yaml` → `godot/assets/levels/HH19.yaml`
- `build/phase-5/yaml/HH25.yaml` → `godot/assets/levels/HH25.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HH28.yaml` → `godot/assets/levels/HH28.yaml`
- `build/phase-5/yaml/HH30.yaml` → `godot/assets/levels/HH30.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HH45.yaml` → `godot/assets/levels/HH45.yaml`
- `build/phase-5/yaml/HH5.yaml` → `godot/assets/levels/HH5.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV4.yaml` → `godot/assets/levels/HLEV4.yaml`
- `build/phase-5/yaml/MLEV13.yaml` → `godot/assets/levels/MLEV13.yaml`
- `build/phase-5/yaml/MLEV16.yaml` → `godot/assets/levels/MLEV16.yaml`
- `build/phase-5/yaml/MLEV17.yaml` → `godot/assets/levels/MLEV17.yaml`
- `build/phase-5/yaml/MLEV19.yaml` → `godot/assets/levels/MLEV19.yaml`
- `build/phase-5/yaml/MLEV21.yaml` → `godot/assets/levels/MLEV21.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/MLEV8.yaml` → `godot/assets/levels/MLEV8.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- ... and 3 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1000 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 512 | Q8.8 = 2.000 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 48 | bitmap frame width |
| `bitmap_h` | 49 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical`, `proximity` |
| Destructible | No |
| Spawns | `custom` |
| Category Part Count | 15 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Up | `2→3` | 2 | No |
| Down | `3→-1` | 4 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 9 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 0 | 0 | 53×49 | 0 |
| `3` | 1 | 1–7 (7 frames) | 61×52 | 19 |
| `4` | 8 | 8 | 22×49 | 154 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0001`, `0001_0007` | `build/phase-3/bitmaps/PART73_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f007.png :material-check:` |
| 1 | `0001_0000`, `0001_0001`, `0001_0008` | `build/phase-3/bitmaps/PART73_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f008.png :material-check:` |
| 2 | `0001_0000`, `0001_0009`, `0001_0002` | `build/phase-3/bitmaps/PART73_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f002.png :material-check:` |
| 3 | `0001_0000`, `0001_0003`, `0001_0010` | `build/phase-3/bitmaps/PART73_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f010.png :material-check:` |
| 4 | `0001_0000`, `0001_0004`, `0001_0011` | `build/phase-3/bitmaps/PART73_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f011.png :material-check:` |
| 5 | `0001_0000`, `0001_0005`, `0001_0012` | `build/phase-3/bitmaps/PART73_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f012.png :material-check:` |
| 6 | `0001_0000`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART73_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f013.png :material-check:` |
| 7 | `0001_0000`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART73_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f013.png :material-check:` |
| 8 | `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART73_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART73_f006.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 6 | `3073` | 0 | `build/phase-6/raw-wav/SX_3073_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 26 |
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

**Trap Door** has 2 semantic states: Up, Down. Transitions are triggered by: collision, electrical, proximity.

Terminal state(s): Down (part is removed from simulation).

This part has custom spawn behavior defined in SOLVE.RES.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART73.json` |
| Sprite PNGs | `godot/assets/sprites/PART73_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV10.yaml` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/ELEV26.yaml` |
| Level YAML | `godot/assets/levels/ELEV6.yaml` |
| Level YAML | `godot/assets/levels/HH17.yaml` |
| ... | +28 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART73.json` + `build/phase-5/yaml/`*
