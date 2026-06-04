# Part 137 — Egg Timer

## Identity

| Field | Value |
|-------|-------|
| Part Type | `137` |
| Category | Special Mechanics |
| Description | Program this egg timer to a desired amount of time. Then drop something on the top knob to make it start. When the time is up, an arm pops out, bumping anything in its way. |
| ANM File | `PART137.ANM` → `build/phase-4/anm/PART137.json` |
| BMP Resource | `PART137.BMP` → `build/phase-3/bitmaps/PART137_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**46 level(s)** use this part type:

- `build/phase-5/yaml/ELEV20.yaml` → `godot/assets/levels/ELEV20.yaml`
- `build/phase-5/yaml/ELEV4.yaml` → `godot/assets/levels/ELEV4.yaml`
- `build/phase-5/yaml/ELEV6.yaml` → `godot/assets/levels/ELEV6.yaml`
- `build/phase-5/yaml/HH13.yaml` → `godot/assets/levels/HH13.yaml`
- `build/phase-5/yaml/HH15.yaml` → `godot/assets/levels/HH15.yaml`
- `build/phase-5/yaml/HH16.yaml` → `godot/assets/levels/HH16.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH23.yaml` → `godot/assets/levels/HH23.yaml`
- `build/phase-5/yaml/HH24.yaml` → `godot/assets/levels/HH24.yaml`
- `build/phase-5/yaml/HH25.yaml` → `godot/assets/levels/HH25.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HH28.yaml` → `godot/assets/levels/HH28.yaml`
- `build/phase-5/yaml/HH29.yaml` → `godot/assets/levels/HH29.yaml`
- `build/phase-5/yaml/HH31.yaml` → `godot/assets/levels/HH31.yaml`
- `build/phase-5/yaml/HH34.yaml` → `godot/assets/levels/HH34.yaml`
- `build/phase-5/yaml/HH35.yaml` → `godot/assets/levels/HH35.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH38.yaml` → `godot/assets/levels/HH38.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HH46.yaml` → `godot/assets/levels/HH46.yaml`
- `build/phase-5/yaml/HH48.yaml` → `godot/assets/levels/HH48.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV17.yaml` → `godot/assets/levels/HLEV17.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV7.yaml` → `godot/assets/levels/HLEV7.yaml`
- ... and 16 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2000 | mass/density (relative scale) |
| `unk_2` | 120 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 26 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 49 | bitmap frame width |
| `bitmap_h` | 40 | bitmap frame height |

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
| Unactivated | `22→37`, `23→38`, `26→39`, `28→40`, `30→41`, `36→42`, `33→43`, `34→44` | — | No |
| Time Out | `19→-1`, `19→-1`, `19→-1`, `19→-1`, `19→-1`, `19→-1`, `19→-1`, `19→-1` | — | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 33 |
| Total States | 26 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `22` | 0 | 0 | 50×40 | 0 |
| `37` | 1 | 1 | 50×36 | 37 |
| `21` | 2 | 2 | 50×33 | 74 |
| `23` | 3 | 3 | 50×40 | 105 |
| `38` | 4 | 4 | 50×36 | 142 |
| `24` | 5 | 5 | 50×33 | 179 |
| `26` | 6 | 6 | 50×40 | 210 |
| `39` | 7 | 7 | 50×36 | 247 |
| `25` | 8 | 8 | 50×33 | 284 |
| `28` | 9 | 9 | 50×40 | 315 |
| `40` | 10 | 10 | 50×36 | 352 |
| `27` | 11 | 11 | 50×33 | 389 |
| `30` | 12 | 12 | 50×40 | 420 |
| `41` | 13 | 13 | 50×36 | 457 |
| `29` | 14 | 14 | 50×33 | 494 |
| `36` | 15 | 15 | 50×40 | 525 |
| `42` | 16 | 16 | 50×36 | 562 |
| `31` | 17 | 17 | 50×33 | 599 |
| `33` | 18 | 18 | 50×40 | 630 |
| `43` | 19 | 19 | 50×36 | 667 |
| `32` | 20 | 20 | 50×33 | 704 |
| `34` | 21 | 21 | 50×40 | 735 |
| `44` | 22 | 22 | 50×36 | 772 |
| `35` | 23 | 23 | 50×33 | 809 |
| `19` | 24 | 24–31 (8 frames) | 50×33 | 840 |
| `20` | 32 | 32 | 50×33 | 1186 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0003`, `0001_0004`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0006` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f006.png :material-check:` |
| 1 | `0001_0004`, `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0006` | `build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f006.png :material-check:` |
| 2 | `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0006` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f006.png :material-check:` |
| 3 | `0001_0003`, `0001_0004`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0007` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f007.png :material-check:` |
| 4 | `0001_0004`, `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0007` | `build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f007.png :material-check:` |
| 5 | `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0007` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f007.png :material-check:` |
| 6 | `0001_0003`, `0001_0004`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0008` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f008.png :material-check:` |
| 7 | `0001_0004`, `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0008` | `build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f008.png :material-check:` |
| 8 | `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0008` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f008.png :material-check:` |
| 9 | `0001_0003`, `0001_0004`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0009` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f009.png :material-check:` |
| 10 | `0001_0004`, `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0009` | `build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f009.png :material-check:` |
| 11 | `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0009` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f009.png :material-check:` |
| 12 | `0001_0003`, `0001_0004`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0010` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f010.png :material-check:` |
| 13 | `0001_0004`, `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0010` | `build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f010.png :material-check:` |
| 14 | `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0010` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f010.png :material-check:` |
| 15 | `0001_0003`, `0001_0004`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0011` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f011.png :material-check:` |
| 16 | `0001_0004`, `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0011` | `build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f011.png :material-check:` |
| 17 | `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0011` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f011.png :material-check:` |
| 18 | `0001_0003`, `0001_0004`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0012` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f012.png :material-check:` |
| 19 | `0001_0004`, `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0012` | `build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f012.png :material-check:` |
| 20 | `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0012` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f012.png :material-check:` |
| 21 | `0001_0003`, `0001_0004`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0005` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f005.png :material-check:` |
| 22 | `0001_0004`, `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0005` | `build/phase-3/bitmaps/PART137_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f005.png :material-check:` |
| 23 | `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0005` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f005.png :material-check:` |
| 24 | `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0005` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f005.png :material-check:` |
| 25 | `0001_0003`, `0001_0000`, `0001_0005`, `0001_0001`, `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:` |
| 26 | `0001_0003`, `0001_0000`, `0001_0005`, `0001_0001`, `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:` |
| 27 | `0001_0003`, `0001_0000`, `0001_0005`, `0001_0001`, `0001_0001`, `0001_0001`, `0001_0001`, `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:` |
| 28 | `0001_0003`, `0001_0000`, `0001_0005`, `0001_0001`, `0001_0001`, `0001_0001`, `0001_0001`, `0001_0001`, `0001_0001`, `0001_0001`, `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:` |
| 29 | `0001_0003`, `0001_0000`, `0001_0005`, `0001_0001`, `0001_0001`, `0001_0001`, `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:` |
| 30 | `0001_0003`, `0001_0000`, `0001_0005`, `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:` |
| 31 | `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0005` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f005.png :material-check:` |
| 32 | `0001_0003`, `0001_0001`, `0001_0000`, `0001_0002`, `0001_0005` | `build/phase-3/bitmaps/PART137_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART137_f005.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 25 | `3337` | 0 | `build/phase-6/raw-wav/SX_3337_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 197 |
| `END_FRAME` | 33 |
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

**Egg Timer** has 2 semantic states: Unactivated, Time Out. Transitions are triggered by: collision, electrical, proximity.

Terminal state(s): Time Out, Time Out, Time Out, Time Out, Time Out, Time Out, Time Out, Time Out (part is removed from simulation).

This part has custom spawn behavior defined in SOLVE.RES.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART137.json` |
| Sprite PNGs | `godot/assets/sprites/PART137_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| Level YAML | `godot/assets/levels/ELEV4.yaml` |
| Level YAML | `godot/assets/levels/ELEV6.yaml` |
| Level YAML | `godot/assets/levels/HH13.yaml` |
| Level YAML | `godot/assets/levels/HH15.yaml` |
| ... | +41 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART137.json` + `build/phase-5/yaml/`*
