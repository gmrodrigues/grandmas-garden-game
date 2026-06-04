# Part 50 — Electric Motor

## Identity

| Field | Value |
|-------|-------|
| Part Type | `50` |
| Category | Rotating Power Sources |
| Description | Plug this electric motor into an outlet and flick on the switch. Then use a belt to attach it to gears, conveyor belts, and other rotating parts. This motor can also be flipped. |
| ANM File | `PART50.ANM` → `build/phase-4/anm/PART50.json` |
| BMP Resource | `PART50.BMP` → `build/phase-3/bitmaps/PART50_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**32 level(s)** use this part type:

- `build/phase-5/yaml/ELEV16.yaml` → `godot/assets/levels/ELEV16.yaml`
- `build/phase-5/yaml/ELEV5.yaml` → `godot/assets/levels/ELEV5.yaml`
- `build/phase-5/yaml/ELEV6.yaml` → `godot/assets/levels/ELEV6.yaml`
- `build/phase-5/yaml/HH10.yaml` → `godot/assets/levels/HH10.yaml`
- `build/phase-5/yaml/HH11.yaml` → `godot/assets/levels/HH11.yaml`
- `build/phase-5/yaml/HH13.yaml` → `godot/assets/levels/HH13.yaml`
- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/HLEV8.yaml` → `godot/assets/levels/HLEV8.yaml`
- `build/phase-5/yaml/HLEV9.yaml` → `godot/assets/levels/HLEV9.yaml`
- `build/phase-5/yaml/MLEV22.yaml` → `godot/assets/levels/MLEV22.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/MLEV7.yaml` → `godot/assets/levels/MLEV7.yaml`
- `build/phase-5/yaml/MLEV9.yaml` → `godot/assets/levels/MLEV9.yaml`
- `build/phase-5/yaml/RLEV10.yaml` → `godot/assets/levels/RLEV10.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV20.yaml` → `godot/assets/levels/RLEV20.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/RLEV29.yaml` → `godot/assets/levels/RLEV29.yaml`
- `build/phase-5/yaml/RLEV3.yaml` → `godot/assets/levels/RLEV3.yaml`
- `build/phase-5/yaml/RLEV5.yaml` → `godot/assets/levels/RLEV5.yaml`
- `build/phase-5/yaml/RLEV6.yaml` → `godot/assets/levels/RLEV6.yaml`
- `build/phase-5/yaml/RLEV7.yaml` → `godot/assets/levels/RLEV7.yaml`
- `build/phase-5/yaml/RLEV8.yaml` → `godot/assets/levels/RLEV8.yaml`
- `build/phase-5/yaml/TLEV5.yaml` → `godot/assets/levels/TLEV5.yaml`
- ... and 2 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 66 | bitmap frame width |
| `bitmap_h` | 54 | bitmap frame height |

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
| Off | `1→4` | — | No |
| Running | `4→-1` | 3 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 38 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 70×54 | 0 |
| `4` | 1 | 1–9 (9 frames) | 70×54 | 19 |
| `3` | 10 | 10–37 (28 frames) | 70×50 | 244 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0005`, `0001_0008` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f008.png :material-check:` |
| 1 | `0001_0000`, `0001_0005`, `0001_0009`, `0001_0022` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f022.png :material-check:` |
| 2 | `0001_0001`, `0001_0005`, `0001_0006`, `0001_0021` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f021.png :material-check:` |
| 3 | `0001_0002`, `0001_0005`, `0001_0007`, `0001_0020` | `build/phase-3/bitmaps/PART50_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f020.png :material-check:` |
| 4 | `0001_0003`, `0001_0005`, `0001_0008`, `0001_0019` | `build/phase-3/bitmaps/PART50_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f019.png :material-check:` |
| 5 | `0001_0004`, `0001_0005`, `0001_0009`, `0001_0018` | `build/phase-3/bitmaps/PART50_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f018.png :material-check:` |
| 6 | `0001_0003`, `0001_0005`, `0001_0006`, `0001_0025` | `build/phase-3/bitmaps/PART50_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f025.png :material-check:` |
| 7 | `0001_0002`, `0001_0005`, `0001_0007`, `0001_0024` | `build/phase-3/bitmaps/PART50_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f024.png :material-check:` |
| 8 | `0001_0001`, `0001_0005`, `0001_0008`, `0001_0023` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f023.png :material-check:` |
| 9 | `0001_0000`, `0001_0005`, `0001_0009`, `0001_0022` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f022.png :material-check:` |
| 10 | `0001_0001`, `0001_0005`, `0001_0006`, `0001_0010` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f010.png :material-check:` |
| 11 | `0001_0000`, `0001_0005`, `0001_0007`, `0001_0014` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f014.png :material-check:` |
| 12 | `0001_0001`, `0001_0005`, `0001_0008`, `0001_0011` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f011.png :material-check:` |
| 13 | `0001_0000`, `0001_0005`, `0001_0009`, `0001_0015` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f015.png :material-check:` |
| 14 | `0001_0001`, `0001_0005`, `0001_0006`, `0001_0012` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f012.png :material-check:` |
| 15 | `0001_0000`, `0001_0005`, `0001_0007`, `0001_0016` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f016.png :material-check:` |
| 16 | `0001_0001`, `0001_0005`, `0001_0008`, `0001_0013` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f013.png :material-check:` |
| 17 | `0001_0000`, `0001_0005`, `0001_0009`, `0001_0014` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f014.png :material-check:` |
| 18 | `0001_0001`, `0001_0005`, `0001_0006`, `0001_0017` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f017.png :material-check:` |
| 19 | `0001_0000`, `0001_0005`, `0001_0007`, `0001_0022`, `0001_0026` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f022.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f026.png :material-check:` |
| 20 | `0001_0001`, `0001_0005`, `0001_0008`, `0001_0027` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f027.png :material-check:` |
| 21 | `0001_0000`, `0001_0005`, `0001_0009`, `0001_0013` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f013.png :material-check:` |
| 22 | `0001_0001`, `0001_0005`, `0001_0006`, `0001_0028` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f028.png :material-check:` |
| 23 | `0001_0000`, `0001_0005`, `0001_0007`, `0001_0015` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f015.png :material-check:` |
| 24 | `0001_0001`, `0001_0005`, `0001_0008`, `0001_0029` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f029.png :material-check:` |
| 25 | `0001_0000`, `0001_0005`, `0001_0009`, `0001_0016` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f016.png :material-check:` |
| 26 | `0001_0001`, `0001_0005`, `0001_0006`, `0001_0030` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f030.png :material-check:` |
| 27 | `0001_0000`, `0001_0005`, `0001_0007`, `0001_0014` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f014.png :material-check:` |
| 28 | `0001_0001`, `0001_0005`, `0001_0008`, `0001_0031` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f031.png :material-check:` |
| 29 | `0001_0000`, `0001_0005`, `0001_0009`, `0001_0014` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f014.png :material-check:` |
| 30 | `0001_0001`, `0001_0005`, `0001_0006`, `0001_0032` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f032.png :material-check:` |
| 31 | `0001_0000`, `0001_0005`, `0001_0007`, `0001_0015` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f015.png :material-check:` |
| 32 | `0001_0001`, `0001_0005`, `0001_0008`, `0001_0033` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f033.png :material-check:` |
| 33 | `0001_0000`, `0001_0005`, `0001_0009`, `0001_0013` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f013.png :material-check:` |
| 34 | `0001_0001`, `0001_0005`, `0001_0006`, `0001_0010` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f010.png :material-check:` |
| 35 | `0001_0000`, `0001_0005`, `0001_0007`, `0001_0015` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f015.png :material-check:` |
| 36 | `0001_0001`, `0001_0005`, `0001_0008`, `0001_0010` | `build/phase-3/bitmaps/PART50_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f010.png :material-check:` |
| 37 | `0001_0000`, `0001_0005`, `0001_0009`, `0001_0014` | `build/phase-3/bitmaps/PART50_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART50_f014.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 10 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 11 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 12 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 13 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 14 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 15 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 16 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 17 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 18 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 19 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 20 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 21 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 22 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 23 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 24 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 25 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 26 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 27 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 28 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 29 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 30 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 31 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 32 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 33 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 34 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 35 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 36 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |
| 37 | `50` | 0 | `build/phase-6/raw-wav/SX_50_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 152 |
| `END_FRAME` | 38 |
| `PLAY_SFX` | 28 |
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

**Electric Motor** has 2 semantic states: Off, Running. Transitions are triggered by: collision, electrical, rope.

Terminal state(s): Running (part is removed from simulation).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART50.json` |
| Sprite PNGs | `godot/assets/sprites/PART50_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV16.yaml` |
| Level YAML | `godot/assets/levels/ELEV5.yaml` |
| Level YAML | `godot/assets/levels/ELEV6.yaml` |
| Level YAML | `godot/assets/levels/HH10.yaml` |
| Level YAML | `godot/assets/levels/HH11.yaml` |
| ... | +27 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART50.json` + `build/phase-5/yaml/`*
