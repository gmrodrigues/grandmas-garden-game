# Part 6 — Mouse Motor

## Identity

| Field | Value |
|-------|-------|
| Part Type | `6` |
| Category | Rotating Power Sources |
| Description | This little cage is actually a Mouse Motor.  Bump the cage to make the mouse run around on his wheel. Add a belt and hitch it up to things like the conveyor belt or the Jack-in-the- box to make them work. |
| ANM File | `PART6.ANM` → `build/phase-4/anm/PART6.json` |
| BMP Resource | `PART6.BMP` → `build/phase-3/bitmaps/PART6_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**44 level(s)** use this part type:

- `build/phase-5/yaml/ELEV17.yaml` → `godot/assets/levels/ELEV17.yaml`
- `build/phase-5/yaml/ELEV24.yaml` → `godot/assets/levels/ELEV24.yaml`
- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`
- `build/phase-5/yaml/HH1.yaml` → `godot/assets/levels/HH1.yaml`
- `build/phase-5/yaml/HH11.yaml` → `godot/assets/levels/HH11.yaml`
- `build/phase-5/yaml/HH15.yaml` → `godot/assets/levels/HH15.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH19.yaml` → `godot/assets/levels/HH19.yaml`
- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HH48.yaml` → `godot/assets/levels/HH48.yaml`
- `build/phase-5/yaml/HH5.yaml` → `godot/assets/levels/HH5.yaml`
- `build/phase-5/yaml/HH9.yaml` → `godot/assets/levels/HH9.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV14.yaml` → `godot/assets/levels/HLEV14.yaml`
- `build/phase-5/yaml/HLEV15.yaml` → `godot/assets/levels/HLEV15.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV23.yaml` → `godot/assets/levels/HLEV23.yaml`
- `build/phase-5/yaml/HLEV25.yaml` → `godot/assets/levels/HLEV25.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/MLEV10.yaml` → `godot/assets/levels/MLEV10.yaml`
- `build/phase-5/yaml/MLEV11.yaml` → `godot/assets/levels/MLEV11.yaml`
- `build/phase-5/yaml/MLEV13.yaml` → `godot/assets/levels/MLEV13.yaml`
- `build/phase-5/yaml/MLEV17.yaml` → `godot/assets/levels/MLEV17.yaml`
- `build/phase-5/yaml/RLEV13.yaml` → `godot/assets/levels/RLEV13.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- ... and 14 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 3776 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 49 | bitmap frame width |
| `bitmap_h` | 33 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical`, `rope` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 7 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Running | `3→6` | — | No |
| Running | `6→-1` | 6 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 17 |
| Total States | 2 |
| Animated (Section A) | Yes |
| Section A Durations | 36 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `3` | 0 | 0–30 (31 frames) | 48×32 | 0 |
| `6` | 31 | 31 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0001`, `0002_0000`, `0001_0000` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:` |
| 1 | `0001_0001`, `0002_0000`, `0001_0000`, `0003_0000` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f000.png :material-check:` |
| 2 | `0001_0001`, `0002_0000`, `0001_0000`, `0003_0001` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f001.png :material-check:` |
| 3 | `0001_0001`, `0002_0000`, `0001_0000`, `0003_0002`, `0003_0000` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f002.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f000.png :material-check:` |
| 4 | `0001_0001`, `0002_0000`, `0001_0000`, `0003_0003`, `0003_0001` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f003.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f001.png :material-check:` |
| 5 | `0001_0001`, `0002_0000`, `0001_0000`, `0003_0002` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f002.png :material-check:` |
| 6 | `0001_0001`, `0002_0000`, `0001_0000`, `0003_0003` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f003.png :material-check:` |
| 7 | `0001_0001`, `0002_0000`, `0001_0000` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:` |
| 8 | `0001_0001`, `0002_0000`, `0001_0000`, `0003_0000` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f000.png :material-check:` |
| 9 | `0001_0001`, `0002_0000`, `0001_0000`, `0003_0001` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f001.png :material-check:` |
| 10 | `0001_0001`, `0002_0000`, `0001_0000`, `0003_0002` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f002.png :material-check:` |
| 11 | `0001_0001`, `0002_0000`, `0001_0000`, `0003_0003` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f003.png :material-check:` |
| 12 | `0001_0001`, `0001_0000`, `0002_0002` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f002.png :material-check:` |
| 13 | `0001_0001`, `0001_0000`, `0002_0002` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f002.png :material-check:` |
| 14 | `0001_0002`, `0001_0000`, `0001_0003`, `0002_0004` | `build/phase-3/bitmaps/PART6_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f004.png :material-check:` |
| 15 | `0001_0001`, `0001_0000`, `0001_0004`, `0002_0014` | `build/phase-3/bitmaps/PART6_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f014.png :material-check:` |
| 16 | `0001_0002`, `0001_0000`, `0002_0013`, `0001_0005` | `build/phase-3/bitmaps/PART6_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART42_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART6_f005.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 12 | `3006` | 0 | `build/phase-6/raw-wav/SX_3006_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 66 |
| `END_FRAME` | 17 |
| `PLAY_SFX` | 1 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | Yes |
| Belt Connection | Yes |
| Rope Connection | Yes |
| Fire/Flame | No |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Mouse Motor** has 2 semantic states: Not Running, Running. Transitions are triggered by: collision, electrical, rope.

Terminal state(s): Running (part is removed from simulation).

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART6.json` |
| Sprite PNGs | `godot/assets/sprites/PART6_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV17.yaml` |
| Level YAML | `godot/assets/levels/ELEV24.yaml` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| Level YAML | `godot/assets/levels/HH1.yaml` |
| Level YAML | `godot/assets/levels/HH11.yaml` |
| ... | +39 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART6.json` + `build/phase-5/yaml/`*
