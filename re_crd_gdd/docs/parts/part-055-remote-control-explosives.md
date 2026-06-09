# Part 55 — Remote Control Explosives

## Identity

| Field | Value |
|-------|-------|
| Part Type | `55` |
| Category | Explosives / Projectiles |
| Description | These explosives come with the remote control part. They'll blow up all kinds of things, including most walls. Drop something on top of the remote control button to set them off. You can also tie one end of a rope to the button and hitch the other end to a teeter-totter, or another object that will allow you to pull the button down. |
| ANM File | `PART55.ANM` → `build/phase-4/anm/PART55.json` |
| BMP Resource | `PART55.BMP` → `build/phase-3/bitmaps/PART55_f*.png` |
| Created Part | No |
| Interactive | Yes |

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
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 60 | bitmap frame width |
| `bitmap_h` | 48 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `proximity`, `timer` |
| Destructible | Yes |
| Spawns | `projectile` |
| Category Part Count | 10 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Exploded | `2→5` | — | No |
| Exploded | `5→-1` | — | Yes :material-bomb: |

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
| `2` | 0 | 0 | 62×48 | 0 |
| `5` | 1 | 1–8 (8 frames) | 62×48 | 13 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0006`, `0001_0008` | `build/phase-3/bitmaps/PART22_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f008.png :material-check:` |
| 1 | `0001_0006`, `0001_0008` | `build/phase-3/bitmaps/PART22_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f008.png :material-check:` |
| 2 | `0001_0006`, `0001_0008`, `0001_0009` | `build/phase-3/bitmaps/PART22_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f009.png :material-check:` |
| 3 | `0001_0006`, `0001_0008`, `0001_0010` | `build/phase-3/bitmaps/PART22_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f010.png :material-check:` |
| 4 | `0001_0006`, `0001_0008`, `0001_0010` | `build/phase-3/bitmaps/PART22_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f010.png :material-check:` |
| 5 | `0001_0006`, `0001_0008`, `0001_0011` | `build/phase-3/bitmaps/PART22_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f011.png :material-check:` |
| 6 | `0001_0006`, `0001_0008`, `0001_0012` | `build/phase-3/bitmaps/PART22_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f012.png :material-check:` |
| 7 | `0001_0006`, `0001_0008`, `0001_0013` | `build/phase-3/bitmaps/PART22_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f013.png :material-check:` |
| 8 | `0001_0007`, `0001_0008` | `build/phase-3/bitmaps/PART22_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART22_f008.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 3 | `3055` | 0 | `build/phase-6/raw-wav/SX_3055_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 24 |
| `END_FRAME` | 9 |
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
| Projectile | Yes |

## Behavior Notes

**Remote Control Explosives** has 2 semantic states: Not Exploded, Exploded. Transitions are triggered by: collision, proximity, timer.

State(s) Exploded are explosive — reaching these destroys the part.

Terminal state(s): Exploded (part is removed from simulation).

This part can be destroyed by explosives.

This part spawns a **projectile** (cannonball, rocket, missile) when triggered. The projectile is a separate part instance.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART55.json` |
| Sprite PNGs | `godot/assets/sprites/PART55_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV10.yaml` |
| Level YAML | `godot/assets/levels/ELEV13.yaml` |
| Level YAML | `godot/assets/levels/ELEV14.yaml` |
| Level YAML | `godot/assets/levels/ELEV2.yaml` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| ... | +52 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART55.json` + `build/phase-5/yaml/`*
