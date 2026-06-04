# Part 51 — Vacuum

## Identity

| Field | Value |
|-------|-------|
| Part Type | `51` |
| Category | Electrical |
| Description | Plug this vacuum into an electrical outlet and use it to suck up any object that's affected by gravity. |
| ANM File | `PART51.ANM` → `build/phase-4/anm/PART51.json` |
| BMP Resource | `PART51.BMP` → `build/phase-3/bitmaps/PART51_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**7 level(s)** use this part type:

- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HH9.yaml` → `godot/assets/levels/HH9.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/RLEV18.yaml` → `godot/assets/levels/RLEV18.yaml`
- `build/phase-5/yaml/RLEV29.yaml` → `godot/assets/levels/RLEV29.yaml`
- `build/phase-5/yaml/TLEV40.yaml` → `godot/assets/levels/TLEV40.yaml`
- `build/phase-5/yaml/TLEV5.yaml` → `godot/assets/levels/TLEV5.yaml`

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
| `bitmap_w` | 59 | bitmap frame width |
| `bitmap_h` | 33 | bitmap frame height |

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
| Vacuuming | `10→-1` | 10 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 60 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `9` | 0 | 0 | 65×33 | 0 |
| `10` | 1 | 1–59 (59 frames) | 65×33 | 13 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f000.png :material-check:` |
| 1 | `0001_0001`, `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 2 | `0001_0002`, `0001_0003`, `0001_0011` | `build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f011.png :material-check:` |
| 3 | `0001_0005`, `0001_0000`, `0001_0007` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f007.png :material-check:` |
| 4 | `0001_0004`, `0001_0001`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 5 | `0001_0000`, `0001_0003`, `0001_0006` | `build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 6 | `0001_0005`, `0001_0004`, `0001_0010` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f010.png :material-check:` |
| 7 | `0001_0001`, `0001_0002`, `0001_0011` | `build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f011.png :material-check:` |
| 8 | `0001_0005`, `0001_0000`, `0001_0007` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f007.png :material-check:` |
| 9 | `0001_0004`, `0001_0003`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 10 | `0001_0001`, `0001_0002`, `0001_0009` | `build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 11 | `0001_0004`, `0001_0003` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:` |
| 12 | `0001_0005`, `0001_0002`, `0001_0011` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f011.png :material-check:` |
| 13 | `0001_0004`, `0001_0001`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 14 | `0001_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 15 | `0001_0000`, `0001_0003`, `0001_0006` | `build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 16 | `0001_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 17 | `0001_0005`, `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 18 | `0001_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 19 | `0001_0005`, `0001_0002`, `0001_0009` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 20 | `0001_0004`, `0001_0003`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 21 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:` |
| 22 | `0001_0004`, `0001_0008`, `0001_0005` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f005.png :material-check:` |
| 23 | `0001_0002`, `0001_0003`, `0001_0009` | `build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 24 | `0001_0004`, `0001_0003`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 25 | `0001_0000`, `0001_0003`, `0001_0006` | `build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 26 | `0001_0005`, `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 27 | `0001_0005`, `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 28 | `0001_0005`, `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 29 | `0001_0005`, `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 30 | `0001_0005`, `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 31 | `0001_0005`, `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 32 | `0001_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 33 | `0001_0001`, `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f006.png :material-check:` |
| 34 | `0001_0004`, `0001_0001`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 35 | `0001_0002`, `0001_0003`, `0001_0009` | `build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 36 | `0001_0004`, `0001_0005`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 37 | `0001_0002`, `0001_0001`, `0001_0009` | `build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 38 | `0001_0004`, `0001_0001`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 39 | `0001_0005`, `0001_0002`, `0001_0009` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 40 | `0001_0004`, `0001_0003`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 41 | `0001_0001`, `0001_0002`, `0001_0009` | `build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 42 | `0001_0004`, `0001_0003`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 43 | `0001_0005`, `0001_0002`, `0001_0009` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 44 | `0001_0004`, `0001_0001`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 45 | `0001_0002`, `0001_0003`, `0001_0009` | `build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 46 | `0001_0004`, `0001_0003`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 47 | `0001_0005`, `0001_0002`, `0001_0009` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 48 | `0001_0004`, `0001_0001`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 49 | `0001_0002`, `0001_0001`, `0001_0009` | `build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 50 | `0001_0004`, `0001_0003`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 51 | `0001_0002`, `0001_0001`, `0001_0009` | `build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 52 | `0001_0005`, `0001_0004`, `0001_0008` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 53 | `0001_0002`, `0001_0003`, `0001_0009` | `build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 54 | `0001_0004`, `0001_0001`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 55 | `0001_0002`, `0001_0003`, `0001_0009` | `build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 56 | `0001_0004`, `0001_0001`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 57 | `0001_0005`, `0001_0002`, `0001_0009` | `build/phase-3/bitmaps/PART51_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |
| 58 | `0001_0004`, `0001_0001`, `0001_0008` | `build/phase-3/bitmaps/PART51_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f008.png :material-check:` |
| 59 | `0001_0002`, `0001_0003`, `0001_0009` | `build/phase-3/bitmaps/PART51_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART51_f009.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 2 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 3 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 4 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 5 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 6 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 7 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 8 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 9 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 10 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 11 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 12 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 13 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 14 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 15 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 16 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 17 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 18 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 19 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 20 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 21 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 22 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 23 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 24 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 25 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 26 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 27 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 28 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 29 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 30 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 31 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 32 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 33 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 34 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 35 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 36 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 37 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 38 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 39 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 40 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 41 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 42 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 43 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 44 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 45 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 46 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 47 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 48 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 49 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 50 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 51 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 52 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 53 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 54 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 55 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 56 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 57 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 58 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |
| 59 | `51` | 0 | `build/phase-6/raw-wav/SX_51_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 177 |
| `END_FRAME` | 60 |
| `PLAY_SFX` | 59 |
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

**Vacuum** has 2 semantic states: Off, Vacuuming. Transitions are triggered by: electrical, collision.

Terminal state(s): Vacuuming (part is removed from simulation).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART51.json` |
| Sprite PNGs | `godot/assets/sprites/PART51_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/HH4.yaml` |
| Level YAML | `godot/assets/levels/HH9.yaml` |
| Level YAML | `godot/assets/levels/HLEV28.yaml` |
| Level YAML | `godot/assets/levels/RLEV18.yaml` |
| Level YAML | `godot/assets/levels/RLEV29.yaml` |
| ... | +2 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART51.json` + `build/phase-5/yaml/`*
