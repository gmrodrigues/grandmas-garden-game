# Part 108 — Leaky Bucket

## Identity

| Field | Value |
|-------|-------|
| Part Type | `108` |
| Category | Containers |
| Description | There's a hole in the bottom of this bucket. You can program how fast the water leaks out. The faster it drips, the heavier the bucket is when you start the puzzle. As the contents drip out, the bucket gets lighter. Tie a rope to the top and use pulleys to connect it to another object. |
| ANM File | `PART108.ANM` → `build/phase-4/anm/PART108.json` |
| BMP Resource | `PART108.BMP` → `build/phase-3/bitmaps/PART108_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**11 level(s)** use this part type:

- `build/phase-5/yaml/ELEV9.yaml` → `godot/assets/levels/ELEV9.yaml`
- `build/phase-5/yaml/HH47.yaml` → `godot/assets/levels/HH47.yaml`
- `build/phase-5/yaml/MLEV14.yaml` → `godot/assets/levels/MLEV14.yaml`
- `build/phase-5/yaml/MLEV16.yaml` → `godot/assets/levels/MLEV16.yaml`
- `build/phase-5/yaml/MLEV8.yaml` → `godot/assets/levels/MLEV8.yaml`
- `build/phase-5/yaml/RLEV18.yaml` → `godot/assets/levels/RLEV18.yaml`
- `build/phase-5/yaml/RLEV20.yaml` → `godot/assets/levels/RLEV20.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/RLEV9.yaml` → `godot/assets/levels/RLEV9.yaml`
- `build/phase-5/yaml/TLEV32.yaml` → `godot/assets/levels/TLEV32.yaml`
- `build/phase-5/yaml/TLEV33.yaml` → `godot/assets/levels/TLEV33.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 100 | category-specific property |
| `property_q8` | 32 | Q8.8 = 0.125 |
| `unk_6` | 48 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 35 | bitmap frame width |
| `bitmap_h` | 50 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 5 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Dripping | `1→4` | 1 | No |
| Empty | `4→10` | 4 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 42 |
| Total States | 8 |
| Animated (Section A) | Yes |
| Section A Durations | 91 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 40×50 | 0 |
| `9` | 1 | 1–7 (7 frames) | 40×50 | 7 |
| `8` | 8 | 8–17 (10 frames) | 40×50 | 88 |
| `7` | 18 | 18–29 (12 frames) | 40×50 | 202 |
| `6` | 30 | 30–50 (21 frames) | 40×60 | 350 |
| `5` | 51 | 51–79 (29 frames) | 0×0 | 0 |
| `4` | 80 | 80–89 (10 frames) | 0×0 | 0 |
| `10` | 90 | 90 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART108_f000.png :material-check:` |
| 1 | `0001_0000` | `build/phase-3/bitmaps/PART108_f000.png :material-check:` |
| 2 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f001.png :material-check:` |
| 3 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f002.png :material-check:` |
| 4 | `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f003.png :material-check:` |
| 5 | `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f004.png :material-check:` |
| 6 | `0001_0000`, `0001_0005` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f005.png :material-check:` |
| 7 | `0001_0000` | `build/phase-3/bitmaps/PART108_f000.png :material-check:` |
| 8 | `0001_0000` | `build/phase-3/bitmaps/PART108_f000.png :material-check:` |
| 9 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f001.png :material-check:` |
| 10 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f001.png :material-check:` |
| 11 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f002.png :material-check:` |
| 12 | `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f003.png :material-check:` |
| 13 | `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f004.png :material-check:` |
| 14 | `0001_0000`, `0001_0005` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f005.png :material-check:` |
| 15 | `0001_0000` | `build/phase-3/bitmaps/PART108_f000.png :material-check:` |
| 16 | `0001_0000` | `build/phase-3/bitmaps/PART108_f000.png :material-check:` |
| 17 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f001.png :material-check:` |
| 18 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f002.png :material-check:` |
| 19 | `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f003.png :material-check:` |
| 20 | `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f003.png :material-check:` |
| 21 | `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f004.png :material-check:` |
| 22 | `0001_0000`, `0001_0005` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f005.png :material-check:` |
| 23 | `0001_0000` | `build/phase-3/bitmaps/PART108_f000.png :material-check:` |
| 24 | `0001_0000` | `build/phase-3/bitmaps/PART108_f000.png :material-check:` |
| 25 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f001.png :material-check:` |
| 26 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f002.png :material-check:` |
| 27 | `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f003.png :material-check:` |
| 28 | `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f004.png :material-check:` |
| 29 | `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f004.png :material-check:` |
| 30 | `0001_0000`, `0001_0005` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f005.png :material-check:` |
| 31 | `0001_0000` | `build/phase-3/bitmaps/PART108_f000.png :material-check:` |
| 32 | `0001_0000` | `build/phase-3/bitmaps/PART108_f000.png :material-check:` |
| 33 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f001.png :material-check:` |
| 34 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f002.png :material-check:` |
| 35 | `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f003.png :material-check:` |
| 36 | `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f004.png :material-check:` |
| 37 | `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f004.png :material-check:` |
| 38 | `0001_0000`, `0001_0005` | `build/phase-3/bitmaps/PART108_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART108_f005.png :material-check:` |
| 39 | `0001_0000` | `build/phase-3/bitmaps/PART108_f000.png :material-check:` |
| 40 | `0001_0000` | `build/phase-3/bitmaps/PART108_f000.png :material-check:` |
| 41 | `0001_0006` | `build/phase-3/bitmaps/PART108_f006.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 2 | `3108` | 0 | `build/phase-6/raw-wav/SX_3108_11025.wav` |
| 9 | `3108` | 0 | `build/phase-6/raw-wav/SX_3108_11025.wav` |
| 19 | `3108` | 0 | `build/phase-6/raw-wav/SX_3108_11025.wav` |
| 28 | `3108` | 0 | `build/phase-6/raw-wav/SX_3108_11025.wav` |
| 36 | `3108` | 0 | `build/phase-6/raw-wav/SX_3108_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 71 |
| `END_FRAME` | 42 |
| `PLAY_SFX` | 5 |
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

**Leaky Bucket** has 2 semantic states: Dripping, Empty. Transitions are triggered by: collision.

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART108.json` |
| Sprite PNGs | `godot/assets/sprites/PART108_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV9.yaml` |
| Level YAML | `godot/assets/levels/HH47.yaml` |
| Level YAML | `godot/assets/levels/MLEV14.yaml` |
| Level YAML | `godot/assets/levels/MLEV16.yaml` |
| Level YAML | `godot/assets/levels/MLEV8.yaml` |
| ... | +6 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART108.json` + `build/phase-5/yaml/`*
