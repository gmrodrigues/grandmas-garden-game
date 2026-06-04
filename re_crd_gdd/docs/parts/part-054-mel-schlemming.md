# Part 54 — Mel Schlemming

## Identity

| Field | Value |
|-------|-------|
| Part Type | `54` |
| Category | Characters |
| Description | Meet Mel Schlemming. Mel walks mindlessly forward until he bumps into something. Then he turns around and walks mindlessly in the other direction. You can program him to walk, run, or stand still until he's bumped. If he falls too far, he drops to the floor and takes a snooze. He also has to watch out for alligators. |
| ANM File | `PART54.ANM` → `build/phase-4/anm/PART54.json` |
| BMP Resource | `PART54.BMP` → `build/phase-3/bitmaps/PART54_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**32 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV7.yaml` → `godot/assets/levels/ELEV7.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH24.yaml` → `godot/assets/levels/HH24.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HLEV17.yaml` → `godot/assets/levels/HLEV17.yaml`
- `build/phase-5/yaml/HLEV19.yaml` → `godot/assets/levels/HLEV19.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/MLEV1.yaml` → `godot/assets/levels/MLEV1.yaml`
- `build/phase-5/yaml/MLEV18.yaml` → `godot/assets/levels/MLEV18.yaml`
- `build/phase-5/yaml/MLEV19.yaml` → `godot/assets/levels/MLEV19.yaml`
- `build/phase-5/yaml/MLEV20.yaml` → `godot/assets/levels/MLEV20.yaml`
- `build/phase-5/yaml/MLEV23.yaml` → `godot/assets/levels/MLEV23.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/RLEV11.yaml` → `godot/assets/levels/RLEV11.yaml`
- `build/phase-5/yaml/RLEV12.yaml` → `godot/assets/levels/RLEV12.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/RLEV24.yaml` → `godot/assets/levels/RLEV24.yaml`
- `build/phase-5/yaml/RLEV29.yaml` → `godot/assets/levels/RLEV29.yaml`
- `build/phase-5/yaml/RLEV3.yaml` → `godot/assets/levels/RLEV3.yaml`
- ... and 2 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2400 | mass/density (relative scale) |
| `unk_2` | 40 | category-specific property |
| `property_q8` | 0 | Q8.8 = 0.000 |
| `unk_6` | 128 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 20 | bitmap frame width |
| `bitmap_h` | 26 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `proximity` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 8 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Normal | `1→8` | 1 | No |
| Sleeping | `51→-1` | 11 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 103 |
| Total States | 14 |
| Animated (Section A) | Yes |
| Section A Durations | 276 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 24×26 | 0 |
| `18` | 1 | 1–23 (23 frames) | 16×28 | 7 |
| `19` | 24 | 24–46 (23 frames) | 16×28 | 446 |
| `20` | 47 | 47–69 (23 frames) | 24×26 | 707 |
| `21` | 70 | 70–94 (25 frames) | 24×26 | 872 |
| `23` | 95 | 95–133 (39 frames) | 40×11 | 1129 |
| `25` | 134 | 134 | 0×0 | 0 |
| `3` | 135 | 135–150 (16 frames) | 0×0 | 0 |
| `15` | 151 | 151 | 0×0 | 0 |
| `16` | 152 | 152–159 (8 frames) | 0×0 | 0 |
| `8` | 160 | 160–167 (8 frames) | 0×0 | 0 |
| `9` | 168 | 168–197 (30 frames) | 0×0 | 0 |
| `11` | 198 | 198–234 (37 frames) | 0×0 | 0 |
| `51` | 235 | 235 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART54_f000.png :material-check:` |
| 1 | `0001_0042` | `build/phase-3/bitmaps/PART54_f042.png :material-check:` |
| 2 | `0001_0043`, `0001_0044`, `0001_0046` | `build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f046.png :material-check:` |
| 3 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 4 | `0001_0047`, `0001_0043`, `0001_0045` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f045.png :material-check:` |
| 5 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 6 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 7 | `0001_0047`, `0001_0043`, `0001_0045` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f045.png :material-check:` |
| 8 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 9 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 10 | `0001_0047`, `0001_0043`, `0001_0045` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f045.png :material-check:` |
| 11 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 12 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 13 | `0001_0047`, `0001_0043`, `0001_0045` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f045.png :material-check:` |
| 14 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 15 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 16 | `0001_0047`, `0001_0043`, `0001_0045` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f045.png :material-check:` |
| 17 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 18 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 19 | `0001_0047`, `0001_0043`, `0001_0045` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f045.png :material-check:` |
| 20 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 21 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 22 | `0001_0047`, `0001_0043`, `0001_0045` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f045.png :material-check:` |
| 23 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 24 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 25 | `0001_0047`, `0001_0043`, `0001_0045` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f045.png :material-check:` |
| 26 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 27 | `0001_0047`, `0001_0043`, `0001_0044` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f044.png :material-check:` |
| 28 | `0001_0047`, `0001_0043`, `0001_0045` | `build/phase-3/bitmaps/PART54_f047.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f043.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f045.png :material-check:` |
| 29 | `0001_0041`, `0001_0050` | `build/phase-3/bitmaps/PART54_f041.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f050.png :material-check:` |
| 30 | `0001_0041`, `0001_0050` | `build/phase-3/bitmaps/PART54_f041.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f050.png :material-check:` |
| 31 | `0001_0041`, `0001_0049` | `build/phase-3/bitmaps/PART54_f041.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f049.png :material-check:` |
| 32 | `0001_0041`, `0001_0048` | `build/phase-3/bitmaps/PART54_f041.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f048.png :material-check:` |
| 33 | `0001_0041`, `0001_0049` | `build/phase-3/bitmaps/PART54_f041.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f049.png :material-check:` |
| 34 | `0001_0041`, `0001_0050` | `build/phase-3/bitmaps/PART54_f041.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f050.png :material-check:` |
| 35 | `0001_0000` | `build/phase-3/bitmaps/PART54_f000.png :material-check:` |
| 36 | `0001_0003` | `build/phase-3/bitmaps/PART54_f003.png :material-check:` |
| 37 | `0001_0004` | `build/phase-3/bitmaps/PART54_f004.png :material-check:` |
| 38 | `0001_0005` | `build/phase-3/bitmaps/PART54_f005.png :material-check:` |
| 39 | `0001_0006` | `build/phase-3/bitmaps/PART54_f006.png :material-check:` |
| 40 | `0001_0007` | `build/phase-3/bitmaps/PART54_f007.png :material-check:` |
| 41 | `0001_0008` | `build/phase-3/bitmaps/PART54_f008.png :material-check:` |
| 42 | `0001_0001` | `build/phase-3/bitmaps/PART54_f001.png :material-check:` |
| 43 | `0001_0002` | `build/phase-3/bitmaps/PART54_f002.png :material-check:` |
| 44 | `0001_0000` | `build/phase-3/bitmaps/PART54_f000.png :material-check:` |
| 45 | `0001_0010` | `build/phase-3/bitmaps/PART54_f010.png :material-check:` |
| 46 | `0001_0011` | `build/phase-3/bitmaps/PART54_f011.png :material-check:` |
| 47 | `0001_0012` | `build/phase-3/bitmaps/PART54_f012.png :material-check:` |
| 48 | `0001_0013` | `build/phase-3/bitmaps/PART54_f013.png :material-check:` |
| 49 | `0001_0014` | `build/phase-3/bitmaps/PART54_f014.png :material-check:` |
| 50 | `0001_0015` | `build/phase-3/bitmaps/PART54_f015.png :material-check:` |
| 51 | `0001_0016` | `build/phase-3/bitmaps/PART54_f016.png :material-check:` |
| 52 | `0001_0009` | `build/phase-3/bitmaps/PART54_f009.png :material-check:` |
| 53 | `0001_0017` | `build/phase-3/bitmaps/PART54_f017.png :material-check:` |
| 54 | `0001_0018` | `build/phase-3/bitmaps/PART54_f018.png :material-check:` |
| 55 | `0001_0019` | `build/phase-3/bitmaps/PART54_f019.png :material-check:` |
| 56 | `0001_0020` | `build/phase-3/bitmaps/PART54_f020.png :material-check:` |
| 57 | `0001_0021` | `build/phase-3/bitmaps/PART54_f021.png :material-check:` |
| 58 | `0001_0022` | `build/phase-3/bitmaps/PART54_f022.png :material-check:` |
| 59 | `0001_0023` | `build/phase-3/bitmaps/PART54_f023.png :material-check:` |
| 60 | `0001_0024` | `build/phase-3/bitmaps/PART54_f024.png :material-check:` |
| 61 | `0001_0025` | `build/phase-3/bitmaps/PART54_f025.png :material-check:` |
| 62 | `0001_0026` | `build/phase-3/bitmaps/PART54_f026.png :material-check:` |
| 63 | `0001_0027` | `build/phase-3/bitmaps/PART54_f027.png :material-check:` |
| 64 | `0001_0028` | `build/phase-3/bitmaps/PART54_f028.png :material-check:` |
| 65 | `0001_0027` | `build/phase-3/bitmaps/PART54_f027.png :material-check:` |
| 66 | `0001_0029` | `build/phase-3/bitmaps/PART54_f029.png :material-check:` |
| 67 | `0001_0029` | `build/phase-3/bitmaps/PART54_f029.png :material-check:` |
| 68 | `0001_0030` | `build/phase-3/bitmaps/PART54_f030.png :material-check:` |
| 69 | `0001_0031` | `build/phase-3/bitmaps/PART54_f031.png :material-check:` |
| 70 | `0001_0032` | `build/phase-3/bitmaps/PART54_f032.png :material-check:` |
| 71 | `0001_0029` | `build/phase-3/bitmaps/PART54_f029.png :material-check:` |
| 72 | `0001_0030` | `build/phase-3/bitmaps/PART54_f030.png :material-check:` |
| 73 | `0001_0031` | `build/phase-3/bitmaps/PART54_f031.png :material-check:` |
| 74 | `0001_0032` | `build/phase-3/bitmaps/PART54_f032.png :material-check:` |
| 75 | `0001_0029` | `build/phase-3/bitmaps/PART54_f029.png :material-check:` |
| 76 | `0001_0030` | `build/phase-3/bitmaps/PART54_f030.png :material-check:` |
| 77 | `0001_0031` | `build/phase-3/bitmaps/PART54_f031.png :material-check:` |
| 78 | `0001_0032` | `build/phase-3/bitmaps/PART54_f032.png :material-check:` |
| 79 | `0001_0033` | `build/phase-3/bitmaps/PART54_f033.png :material-check:` |
| 80 | `0001_0034` | `build/phase-3/bitmaps/PART54_f034.png :material-check:` |
| 81 | `0001_0035` | `build/phase-3/bitmaps/PART54_f035.png :material-check:` |
| 82 | `0001_0035` | `build/phase-3/bitmaps/PART54_f035.png :material-check:` |
| 83 | `0001_0036` | `build/phase-3/bitmaps/PART54_f036.png :material-check:` |
| 84 | `0001_0037` | `build/phase-3/bitmaps/PART54_f037.png :material-check:` |
| 85 | `0001_0038` | `build/phase-3/bitmaps/PART54_f038.png :material-check:` |
| 86 | `0001_0039` | `build/phase-3/bitmaps/PART54_f039.png :material-check:` |
| 87 | `0001_0040` | `build/phase-3/bitmaps/PART54_f040.png :material-check:` |
| 88 | `0001_0040`, `0001_0055` | `build/phase-3/bitmaps/PART54_f040.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f055.png :material-check:` |
| 89 | `0001_0040`, `0001_0055` | `build/phase-3/bitmaps/PART54_f040.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f055.png :material-check:` |
| 90 | `0001_0052`, `0001_0055`, `0001_0056` | `build/phase-3/bitmaps/PART54_f052.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f055.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f056.png :material-check:` |
| 91 | `0001_0052`, `0001_0055`, `0001_0056`, `0001_0057` | `build/phase-3/bitmaps/PART54_f052.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f055.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f056.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f057.png :material-check:` |
| 92 | `0001_0052`, `0001_0055`, `0001_0056`, `0001_0057` | `build/phase-3/bitmaps/PART54_f052.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f055.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f056.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f057.png :material-check:` |
| 93 | `0001_0052`, `0001_0056`, `0001_0057` | `build/phase-3/bitmaps/PART54_f052.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f056.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f057.png :material-check:` |
| 94 | `0001_0040`, `0001_0057` | `build/phase-3/bitmaps/PART54_f040.png :material-check:`<br>`build/phase-3/bitmaps/PART54_f057.png :material-check:` |
| 95 | `0001_0053` | `build/phase-3/bitmaps/PART54_f053.png :material-check:` |
| 96 | `0001_0053` | `build/phase-3/bitmaps/PART54_f053.png :material-check:` |
| 97 | `0001_0054` | `build/phase-3/bitmaps/PART54_f054.png :material-check:` |
| 98 | `0001_0054` | `build/phase-3/bitmaps/PART54_f054.png :material-check:` |
| 99 | `0001_0054` | `build/phase-3/bitmaps/PART54_f054.png :material-check:` |
| 100 | `0001_0054` | `build/phase-3/bitmaps/PART54_f054.png :material-check:` |
| 101 | `0001_0054` | `build/phase-3/bitmaps/PART54_f054.png :material-check:` |
| 102 | `0001_0053` | `build/phase-3/bitmaps/PART54_f053.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 5 | `3454` | 0 | `build/phase-6/raw-wav/SX_3454_11025.wav` |
| 8 | `3454` | 0 | `build/phase-6/raw-wav/SX_3454_11025.wav` |
| 11 | `3454` | 0 | `build/phase-6/raw-wav/SX_3454_11025.wav` |
| 14 | `3454` | 0 | `build/phase-6/raw-wav/SX_3454_11025.wav` |
| 17 | `3454` | 0 | `build/phase-6/raw-wav/SX_3454_11025.wav` |
| 20 | `3454` | 0 | `build/phase-6/raw-wav/SX_3454_11025.wav` |
| 23 | `3454` | 0 | `build/phase-6/raw-wav/SX_3454_11025.wav` |
| 26 | `3454` | 0 | `build/phase-6/raw-wav/SX_3454_11025.wav` |
| 29 | `3054` | 0 | `build/phase-6/raw-wav/SX_3054_11025.wav` |
| 53 | `3554` | 0 | `build/phase-6/raw-wav/SX_3554_11025.wav` |
| 66 | `3254` | 0 | `build/phase-6/raw-wav/SX_3254_11025.wav` |
| 81 | `3354` | 0 | `build/phase-6/raw-wav/SX_3354_11025.wav` |
| 89 | `3654` | 0 | `build/phase-6/raw-wav/SX_3654_11025.wav` |
| 95 | `3754` | 0 | `build/phase-6/raw-wav/SX_3754_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 176 |
| `END_FRAME` | 103 |
| `PLAY_SFX` | 14 |
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

**Mel Schlemming** has 2 semantic states: Normal, Sleeping. Transitions are triggered by: collision, proximity.

Terminal state(s): Sleeping (part is removed from simulation).

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART54.json` |
| Sprite PNGs | `godot/assets/sprites/PART54_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV7.yaml` |
| Level YAML | `godot/assets/levels/HH17.yaml` |
| ... | +27 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART54.json` + `build/phase-5/yaml/`*
