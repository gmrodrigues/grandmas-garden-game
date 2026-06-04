# Part 26 — Generator

## Identity

| Field | Value |
|-------|-------|
| Part Type | `26` |
| Category | Electrical |
| Description | This generator comes with its own outlet. Use it to supply electricity to power parts by connecting the generator's wheel to a rotational motor (like the Mandrill Motor, the Mouse Motor, or the Electric Motor) by adding a belt. |
| ANM File | `PART26.ANM` → `build/phase-4/anm/PART26.json` |
| BMP Resource | `PART26.BMP` → `build/phase-3/bitmaps/PART26_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**15 level(s)** use this part type:

- `build/phase-5/yaml/ELEV16.yaml` → `godot/assets/levels/ELEV16.yaml`
- `build/phase-5/yaml/ELEV17.yaml` → `godot/assets/levels/ELEV17.yaml`
- `build/phase-5/yaml/ELEV23.yaml` → `godot/assets/levels/ELEV23.yaml`
- `build/phase-5/yaml/HH11.yaml` → `godot/assets/levels/HH11.yaml`
- `build/phase-5/yaml/HH48.yaml` → `godot/assets/levels/HH48.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/MLEV10.yaml` → `godot/assets/levels/MLEV10.yaml`
- `build/phase-5/yaml/MLEV11.yaml` → `godot/assets/levels/MLEV11.yaml`
- `build/phase-5/yaml/RLEV13.yaml` → `godot/assets/levels/RLEV13.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`
- `build/phase-5/yaml/RLEV29.yaml` → `godot/assets/levels/RLEV29.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`
- `build/phase-5/yaml/TLEV6.yaml` → `godot/assets/levels/TLEV6.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 3776 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 81 | bitmap frame width |
| `bitmap_h` | 34 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `electrical`, `collision` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 9 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Off | `9→10` | — | No |
| On | `2→3` | — | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 36 |
| Total States | 8 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `9` | 0 | 0 | 81×34 | 0 |
| `10` | 1 | 1 | 81×34 | 13 |
| `11` | 2 | 2 | 81×34 | 32 |
| `12` | 3 | 3 | 81×34 | 51 |
| `2` | 4 | 4–11 (8 frames) | 81×34 | 76 |
| `3` | 12 | 12–19 (8 frames) | 81×34 | 244 |
| `4` | 20 | 20–27 (8 frames) | 81×34 | 460 |
| `5` | 28 | 28–35 (8 frames) | 81×34 | 676 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART26_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)` |
| 1 | `0001_0000`, `0002_0000`, `0002_0001` | `build/phase-3/bitmaps/PART26_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 2 | `0001_0000`, `0002_0000`, `0002_0001` | `build/phase-3/bitmaps/PART26_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 3 | `0001_0000`, `0002_0000`, `0002_0001`, `0002_0001` | `build/phase-3/bitmaps/PART26_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 4 | `0002_0000`, `0001_0001`, `0003_0000` | `build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART26_3_f000.png :material-alert-outline: (not found)` |
| 5 | `0001_0002`, `0002_0000`, `0003_0001` | `build/phase-3/bitmaps/PART26_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f001.png :material-alert-outline: (not found)` |
| 6 | `0001_0003`, `0002_0000`, `0003_0002` | `build/phase-3/bitmaps/PART26_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f002.png :material-alert-outline: (not found)` |
| 7 | `0001_0004`, `0002_0000`, `0003_0003` | `build/phase-3/bitmaps/PART26_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f003.png :material-alert-outline: (not found)` |
| 8 | `0002_0000`, `0001_0001`, `0003_0004` | `build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART26_3_f004.png :material-alert-outline: (not found)` |
| 9 | `0001_0002`, `0002_0000`, `0003_0005` | `build/phase-3/bitmaps/PART26_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f005.png :material-alert-outline: (not found)` |
| 10 | `0001_0003`, `0002_0000`, `0003_0006` | `build/phase-3/bitmaps/PART26_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f006.png :material-alert-outline: (not found)` |
| 11 | `0001_0004`, `0002_0000`, `0003_0007` | `build/phase-3/bitmaps/PART26_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f007.png :material-alert-outline: (not found)` |
| 12 | `0002_0000`, `0001_0001`, `0002_0001`, `0003_0000` | `build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f000.png :material-alert-outline: (not found)` |
| 13 | `0001_0002`, `0002_0000`, `0002_0001`, `0003_0001` | `build/phase-3/bitmaps/PART26_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f001.png :material-alert-outline: (not found)` |
| 14 | `0001_0003`, `0002_0000`, `0002_0001`, `0003_0002` | `build/phase-3/bitmaps/PART26_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f002.png :material-alert-outline: (not found)` |
| 15 | `0001_0004`, `0002_0000`, `0002_0001`, `0003_0003` | `build/phase-3/bitmaps/PART26_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f003.png :material-alert-outline: (not found)` |
| 16 | `0002_0000`, `0001_0001`, `0002_0001`, `0003_0004` | `build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f004.png :material-alert-outline: (not found)` |
| 17 | `0001_0002`, `0002_0000`, `0002_0001`, `0003_0005` | `build/phase-3/bitmaps/PART26_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f005.png :material-alert-outline: (not found)` |
| 18 | `0001_0003`, `0002_0000`, `0002_0001`, `0003_0006` | `build/phase-3/bitmaps/PART26_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f006.png :material-alert-outline: (not found)` |
| 19 | `0001_0004`, `0002_0000`, `0002_0001`, `0003_0007` | `build/phase-3/bitmaps/PART26_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f007.png :material-alert-outline: (not found)` |
| 20 | `0002_0000`, `0001_0001`, `0003_0000`, `0002_0001` | `build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART26_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 21 | `0001_0002`, `0002_0000`, `0003_0001`, `0002_0001` | `build/phase-3/bitmaps/PART26_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 22 | `0001_0003`, `0002_0000`, `0003_0002`, `0002_0001` | `build/phase-3/bitmaps/PART26_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 23 | `0001_0004`, `0002_0000`, `0003_0003`, `0002_0001` | `build/phase-3/bitmaps/PART26_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 24 | `0002_0000`, `0001_0001`, `0003_0004`, `0002_0001` | `build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART26_3_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 25 | `0001_0002`, `0002_0000`, `0003_0005`, `0002_0001` | `build/phase-3/bitmaps/PART26_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 26 | `0001_0003`, `0002_0000`, `0003_0006`, `0002_0001` | `build/phase-3/bitmaps/PART26_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f006.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 27 | `0001_0004`, `0002_0000`, `0003_0007`, `0002_0001` | `build/phase-3/bitmaps/PART26_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f007.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 28 | `0002_0000`, `0001_0001`, `0003_0000`, `0002_0001`, `0002_0001` | `build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART26_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 29 | `0001_0002`, `0002_0000`, `0002_0001`, `0003_0001`, `0002_0001` | `build/phase-3/bitmaps/PART26_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 30 | `0001_0003`, `0002_0000`, `0002_0001`, `0003_0002`, `0002_0001` | `build/phase-3/bitmaps/PART26_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 31 | `0001_0004`, `0002_0000`, `0002_0001`, `0003_0003`, `0002_0001` | `build/phase-3/bitmaps/PART26_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 32 | `0002_0000`, `0001_0001`, `0002_0001`, `0003_0004`, `0002_0001` | `build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 33 | `0001_0002`, `0002_0000`, `0002_0001`, `0003_0005`, `0002_0001` | `build/phase-3/bitmaps/PART26_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 34 | `0001_0003`, `0002_0000`, `0002_0001`, `0003_0006`, `0002_0001` | `build/phase-3/bitmaps/PART26_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f006.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |
| 35 | `0001_0004`, `0002_0000`, `0002_0001`, `0003_0007`, `0002_0001` | `build/phase-3/bitmaps/PART26_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART26_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_3_f007.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART26_2_f001.png :material-alert-outline: (not found)` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 4 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 5 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 6 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 7 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 8 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 9 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 10 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 11 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 12 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 13 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 14 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 15 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 16 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 17 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 18 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 19 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 20 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 21 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 22 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 23 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 24 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 25 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 26 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 27 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 28 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 29 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 30 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 31 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 32 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 33 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 34 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |
| 35 | `26` | 0 | `build/phase-6/raw-wav/SX_26_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 140 |
| `END_FRAME` | 36 |
| `PLAY_SFX` | 32 |
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

**Generator** has 2 semantic states: Off, On. Transitions are triggered by: electrical, collision.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART26.json` |
| Sprite PNGs | `godot/assets/sprites/PART26_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV16.yaml` |
| Level YAML | `godot/assets/levels/ELEV17.yaml` |
| Level YAML | `godot/assets/levels/ELEV23.yaml` |
| Level YAML | `godot/assets/levels/HH11.yaml` |
| Level YAML | `godot/assets/levels/HH48.yaml` |
| ... | +10 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART26.json` + `build/phase-5/yaml/`*
