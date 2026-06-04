# Part 22 — Remote Control

## Identity

| Field | Value |
|-------|-------|
| Part Type | `22` |
| Category | Explosives / Projectiles |
| Description | As soon as you set this remote control down on the screen, a second part made up of explosives appears.  Drag the explosives to the area or object you want to blow up. Drop something on top of the remote control button to set off the explosion. You can also tie one end of a rope to the button and hitch the other end to a teeter-totter, or another object that will allow you to pull the button down. |
| ANM File | `PART22.ANM` → `build/phase-4/anm/PART22.json` |
| BMP Resource | `PART22.BMP` → `build/phase-3/bitmaps/PART22_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**57 level(s)** use this part type:

- `build/phase-5/yaml/ELEV10.yaml` → `godot/assets/levels/ELEV10.yaml`
- `build/phase-5/yaml/ELEV13.yaml` → `godot/assets/levels/ELEV13.yaml`
- `build/phase-5/yaml/ELEV14.yaml` → `godot/assets/levels/ELEV14.yaml`
- `build/phase-5/yaml/ELEV2.yaml` → `godot/assets/levels/ELEV2.yaml`
- `build/phase-5/yaml/ELEV20.yaml` → `godot/assets/levels/ELEV20.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/ELEV22.yaml` → `godot/assets/levels/ELEV22.yaml`
- `build/phase-5/yaml/ELEV9.yaml` → `godot/assets/levels/ELEV9.yaml`
- `build/phase-5/yaml/HH1.yaml` → `godot/assets/levels/HH1.yaml`
- `build/phase-5/yaml/HH13.yaml` → `godot/assets/levels/HH13.yaml`
- `build/phase-5/yaml/HH24.yaml` → `godot/assets/levels/HH24.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HH30.yaml` → `godot/assets/levels/HH30.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH34.yaml` → `godot/assets/levels/HH34.yaml`
- `build/phase-5/yaml/HH35.yaml` → `godot/assets/levels/HH35.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH45.yaml` → `godot/assets/levels/HH45.yaml`
- `build/phase-5/yaml/HH46.yaml` → `godot/assets/levels/HH46.yaml`
- `build/phase-5/yaml/HH7.yaml` → `godot/assets/levels/HH7.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV11.yaml` → `godot/assets/levels/HLEV11.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV13.yaml` → `godot/assets/levels/HLEV13.yaml`
- `build/phase-5/yaml/HLEV15.yaml` → `godot/assets/levels/HLEV15.yaml`
- `build/phase-5/yaml/HLEV16.yaml` → `godot/assets/levels/HLEV16.yaml`
- `build/phase-5/yaml/HLEV19.yaml` → `godot/assets/levels/HLEV19.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV25.yaml` → `godot/assets/levels/HLEV25.yaml`
- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- ... and 27 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 4153 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 30 | bitmap frame width |
| `bitmap_h` | 37 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | *(none)* |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 10 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 14 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `3` | 0 | 0 | 35×37 | 0 |
| `4` | 1 | 1–13 (13 frames) | 35×37 | 25 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0002`, `0001_0001`, `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f003.png :material-check:` |
| 1 | `0001_0002`, `0001_0001`, `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f003.png :material-check:` |
| 2 | `0001_0001`, `0001_0002`, `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART22_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f003.png :material-check:` |
| 3 | `0001_0001`, `0001_0002`, `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART22_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f003.png :material-check:` |
| 4 | `0001_0001`, `0001_0002`, `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART22_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f003.png :material-check:` |
| 5 | `0001_0002`, `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f003.png :material-check:` |
| 6 | `0001_0002`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f004.png :material-check:` |
| 7 | `0001_0002`, `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f003.png :material-check:` |
| 8 | `0001_0002`, `0001_0000`, `0001_0005`, `0001_0009` | `build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f009.png :material-check:` |
| 9 | `0001_0002`, `0001_0000`, `0001_0003`, `0001_0010` | `build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f010.png :material-check:` |
| 10 | `0001_0002`, `0001_0000`, `0001_0004`, `0001_0011` | `build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f011.png :material-check:` |
| 11 | `0001_0002`, `0001_0000`, `0001_0003`, `0001_0012` | `build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f012.png :material-check:` |
| 12 | `0001_0002`, `0001_0000`, `0001_0003`, `0001_0013` | `build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f013.png :material-check:` |
| 13 | `0001_0002`, `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART22_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f003.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 3 | `3022` | 0 | `build/phase-6/raw-wav/SX_3022_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 52 |
| `END_FRAME` | 14 |
| `PLAY_SFX` | 1 |
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

**Remote Control** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART22.json` |
| Sprite PNGs | `godot/assets/sprites/PART22_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV10.yaml` |
| Level YAML | `godot/assets/levels/ELEV13.yaml` |
| Level YAML | `godot/assets/levels/ELEV14.yaml` |
| Level YAML | `godot/assets/levels/ELEV2.yaml` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| ... | +52 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART22.json` + `build/phase-5/yaml/`*
