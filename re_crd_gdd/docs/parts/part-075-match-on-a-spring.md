# Part 75 — Match-on-a-Spring

## Identity

| Field | Value |
|-------|-------|
| Part Type | `75` |
| Category | Springs / Pneumatics |
| Description | Pull the little peg with a rope to make this match pop up lit. Use it to light fuses, pop blimps and balloons, and heat up coffee pots. |
| ANM File | `PART75.ANM` → `build/phase-4/anm/PART75.json` |
| BMP Resource | `PART75.BMP` → `build/phase-3/bitmaps/PART75_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**52 level(s)** use this part type:

- `build/phase-5/yaml/ELEV17.yaml` → `godot/assets/levels/ELEV17.yaml`
- `build/phase-5/yaml/ELEV19.yaml` → `godot/assets/levels/ELEV19.yaml`
- `build/phase-5/yaml/ELEV23.yaml` → `godot/assets/levels/ELEV23.yaml`
- `build/phase-5/yaml/ELEV24.yaml` → `godot/assets/levels/ELEV24.yaml`
- `build/phase-5/yaml/ELEV25.yaml` → `godot/assets/levels/ELEV25.yaml`
- `build/phase-5/yaml/HH10.yaml` → `godot/assets/levels/HH10.yaml`
- `build/phase-5/yaml/HH14.yaml` → `godot/assets/levels/HH14.yaml`
- `build/phase-5/yaml/HH16.yaml` → `godot/assets/levels/HH16.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH22.yaml` → `godot/assets/levels/HH22.yaml`
- `build/phase-5/yaml/HH29.yaml` → `godot/assets/levels/HH29.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH39.yaml` → `godot/assets/levels/HH39.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH44.yaml` → `godot/assets/levels/HH44.yaml`
- `build/phase-5/yaml/HH46.yaml` → `godot/assets/levels/HH46.yaml`
- `build/phase-5/yaml/HH48.yaml` → `godot/assets/levels/HH48.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HH6.yaml` → `godot/assets/levels/HH6.yaml`
- `build/phase-5/yaml/HH8.yaml` → `godot/assets/levels/HH8.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV13.yaml` → `godot/assets/levels/HLEV13.yaml`
- `build/phase-5/yaml/HLEV14.yaml` → `godot/assets/levels/HLEV14.yaml`
- `build/phase-5/yaml/HLEV15.yaml` → `godot/assets/levels/HLEV15.yaml`
- `build/phase-5/yaml/HLEV16.yaml` → `godot/assets/levels/HLEV16.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- ... and 22 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2000 | mass/density (relative scale) |
| `unk_2` | 995 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 36 | bitmap frame width |
| `bitmap_h` | 23 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 7 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Unlit | `1→4` | 1 | No |
| Lit | `3→-1` | 2 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 18 |
| Total States | 4 |
| Animated (Section A) | Yes |
| Section A Durations | 35 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–1 (2 frames) | 43×23 | 0 |
| `4` | 2 | 2–9 (8 frames) | 46×23 | 50 |
| `3` | 10 | 10–26 (17 frames) | 33×38 | 192 |
| `2` | 27 | 27 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0008`, `0001_0000`, `0001_0009`, `0001_0010` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f010.png :material-check:` |
| 1 | `0001_0008`, `0001_0000`, `0001_0009`, `0001_0010` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f010.png :material-check:` |
| 2 | `0001_0008`, `0001_0000`, `0001_0009`, `0001_0010` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f010.png :material-check:` |
| 3 | `0001_0008`, `0001_0000`, `0001_0009`, `0001_0010` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f010.png :material-check:` |
| 4 | `0001_0008`, `0001_0000`, `0001_0009`, `0001_0010` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f010.png :material-check:` |
| 5 | `0001_0008`, `0001_0010` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f010.png :material-check:` |
| 6 | `0001_0008`, `0001_0011` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f011.png :material-check:` |
| 7 | `0001_0008`, `0001_0012` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f012.png :material-check:` |
| 8 | `0001_0008`, `0001_0012` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f012.png :material-check:` |
| 9 | `0001_0008`, `0001_0013` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f013.png :material-check:` |
| 10 | `0001_0008`, `0001_0014` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f014.png :material-check:` |
| 11 | `0001_0008`, `0001_0015`, `0002_0000`, `0001_0016` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f015.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f016.png :material-check:` |
| 12 | `0001_0008`, `0001_0015`, `0001_0017`, `0002_0001` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f017.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f001.png :material-check:` |
| 13 | `0001_0008`, `0001_0015`, `0001_0016`, `0002_0002` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f016.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f002.png :material-check:` |
| 14 | `0001_0008`, `0001_0015`, `0002_0000`, `0001_0017` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f015.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f017.png :material-check:` |
| 15 | `0001_0008`, `0001_0015`, `0001_0017`, `0002_0001` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f017.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f001.png :material-check:` |
| 16 | `0001_0008`, `0001_0015`, `0001_0017`, `0002_0003` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f017.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f003.png :material-check:` |
| 17 | `0001_0008`, `0001_0015`, `0001_0017`, `0002_0004` | `build/phase-3/bitmaps/PART75_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART75_f017.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f004.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 7 | `3075` | 0 | `build/phase-6/raw-wav/SX_3075_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 60 |
| `END_FRAME` | 18 |
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

**Match-on-a-Spring** has 2 semantic states: Unlit, Lit. Transitions are triggered by: collision, electrical.

Terminal state(s): Lit (part is removed from simulation).

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART75.json` |
| Sprite PNGs | `godot/assets/sprites/PART75_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV17.yaml` |
| Level YAML | `godot/assets/levels/ELEV19.yaml` |
| Level YAML | `godot/assets/levels/ELEV23.yaml` |
| Level YAML | `godot/assets/levels/ELEV24.yaml` |
| Level YAML | `godot/assets/levels/ELEV25.yaml` |
| ... | +47 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART75.json` + `build/phase-5/yaml/`*
