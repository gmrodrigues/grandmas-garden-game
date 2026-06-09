# Part 80 — Fireworks

## Identity

| Field | Value |
|-------|-------|
| Part Type | `80` |
| Category | Explosives / Projectiles |
| Description | This part lets you choose between three different types of fireworks displays. Program the part to get the celebration of your choice. Light the fuse with a flaming part like a candle, rocket, or an Aladdin's lamp. |
| ANM File | `PART80.ANM` → `build/phase-4/anm/PART80.json` |
| BMP Resource | `PART80.BMP` → `build/phase-3/bitmaps/PART80_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**17 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH44.yaml` → `godot/assets/levels/HH44.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV25.yaml` → `godot/assets/levels/HLEV25.yaml`
- `build/phase-5/yaml/HLEV4.yaml` → `godot/assets/levels/HLEV4.yaml`
- `build/phase-5/yaml/MLEV8.yaml` → `godot/assets/levels/MLEV8.yaml`
- `build/phase-5/yaml/MLEV9.yaml` → `godot/assets/levels/MLEV9.yaml`
- `build/phase-5/yaml/RLEV1.yaml` → `godot/assets/levels/RLEV1.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV2.yaml` → `godot/assets/levels/RLEV2.yaml`
- `build/phase-5/yaml/RLEV7.yaml` → `godot/assets/levels/RLEV7.yaml`
- `build/phase-5/yaml/TLEV10.yaml` → `godot/assets/levels/TLEV10.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 1500 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 23 | bitmap frame width |
| `bitmap_h` | 86 | bitmap frame height |

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
| Not Set Off | `9→19`, `12→20`, `16→21` | — | No |
| Set Off | `6→12`, `7→16`, `8→-1` | 21 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 135 |
| Total States | 15 |
| Animated (Section A) | Yes |
| Section A Durations | 147 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `9` | 0 | 0 | 26×86 | 0 |
| `19` | 1 | 1–21 (21 frames) | 64×106 | 13 |
| `10` | 22 | 22–24 (3 frames) | 24×87 | 420 |
| `11` | 25 | 25–30 (6 frames) | 24×86 | 459 |
| `6` | 31 | 31–47 (17 frames) | 56×57 | 515 |
| `12` | 48 | 48 | 56×105 | 678 |
| `20` | 49 | 49–69 (21 frames) | 56×106 | 697 |
| `14` | 70 | 70–72 (3 frames) | 24×86 | 1078 |
| `15` | 73 | 73–78 (6 frames) | 40×37 | 1107 |
| `7` | 79 | 79–94 (16 frames) | 40×37 | 1149 |
| `16` | 95 | 95 | 56×100 | 1353 |
| `21` | 96 | 96–116 (21 frames) | 56×97 | 1372 |
| `17` | 117 | 117–119 (3 frames) | 96×111 | 1713 |
| `18` | 120 | 120–125 (6 frames) | 96×111 | 1734 |
| `8` | 126 | 126–134 (9 frames) | 96×111 | 1776 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:` |
| 1 | `0001_0000`, `0002_0000`, `0002_0005` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f005.png :material-check:` |
| 2 | `0001_0000`, `0002_0000`, `0002_0005` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f005.png :material-check:` |
| 3 | `0001_0000`, `0002_0000`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 4 | `0001_0000`, `0002_0001`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 5 | `0001_0000`, `0002_0001`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 6 | `0001_0000`, `0002_0001`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 7 | `0001_0000`, `0002_0002`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 8 | `0001_0000`, `0002_0002`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 9 | `0001_0000`, `0002_0002`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 10 | `0001_0000`, `0002_0003`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 11 | `0001_0000`, `0002_0003`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 12 | `0001_0000`, `0002_0003`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 13 | `0001_0000`, `0002_0003`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 14 | `0001_0000`, `0002_0004`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f004.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 15 | `0001_0000`, `0002_0004`, `0001_0000`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 16 | `0001_0000` | `build/phase-3/bitmaps/PART80_f000.png :material-check:` |
| 17 | `0001_0001` | `build/phase-3/bitmaps/PART80_f001.png :material-check:` |
| 18 | `0001_0002`, `0002_0008`, `0002_0012` | `build/phase-3/bitmaps/PART80_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f008.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f012.png :material-check:` |
| 19 | `0002_0013`, `0002_0014`, `0002_0015`, `0001_0000`, `0002_0009` | `build/phase-3/bitmaps/ROKTBLAS_f013.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f014.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:` |
| 20 | `0002_0014`, `0002_0017`, `0002_0015`, `0002_0016`, `0001_0000`, `0002_0011` | `build/phase-3/bitmaps/ROKTBLAS_f014.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f017.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f015.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f011.png :material-check:` |
| 21 | `0001_0000`, `0002_0010` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f010.png :material-check:` |
| 22 | `0001_0000`, `0002_0009` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:` |
| 23 | `0001_0000`, `0002_0008` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f008.png :material-check:` |
| 24 | `0001_0000`, `0002_0009` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:` |
| 25 | `0001_0000`, `0002_0010` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f010.png :material-check:` |
| 26 | `0001_0000`, `0002_0011` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f011.png :material-check:` |
| 27 | `0004_0000` | `build/phase-3/bitmaps/FWBLUE_f000.png :material-check:` |
| 28 | `0004_0000` | `build/phase-3/bitmaps/FWBLUE_f000.png :material-check:` |
| 29 | `0004_0001` | `build/phase-3/bitmaps/FWBLUE_f001.png :material-check:` |
| 30 | `0004_0002` | `build/phase-3/bitmaps/FWBLUE_f002.png :material-check:` |
| 31 | `0004_0003` | `build/phase-3/bitmaps/FWBLUE_f003.png :material-check:` |
| 32 | `0004_0004` | `build/phase-3/bitmaps/FWBLUE_f004.png :material-check:` |
| 33 | `0004_0005` | `build/phase-3/bitmaps/FWBLUE_f005.png :material-check:` |
| 34 | `0004_0006` | `build/phase-3/bitmaps/FWBLUE_f006.png :material-check:` |
| 35 | `0004_0007` | `build/phase-3/bitmaps/FWBLUE_f007.png :material-check:` |
| 36 | `0004_0008` | `build/phase-3/bitmaps/FWBLUE_f008.png :material-check:` |
| 37 | `0004_0009` | `build/phase-3/bitmaps/FWBLUE_f009.png :material-check:` |
| 38 | `0004_0010` | `build/phase-3/bitmaps/FWBLUE_f010.png :material-check:` |
| 39 | `0004_0011` | `build/phase-3/bitmaps/FWBLUE_f011.png :material-check:` |
| 40 | `0004_0012` | `build/phase-3/bitmaps/FWBLUE_f012.png :material-check:` |
| 41 | `0004_0013` | `build/phase-3/bitmaps/FWBLUE_f013.png :material-check:` |
| 42 | `0004_0014` | `build/phase-3/bitmaps/FWBLUE_f014.png :material-check:` |
| 43 | `0003_0000` | `build/phase-3/bitmaps/BLANK.png :material-check:` |
| 44 | `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:` |
| 45 | `0001_0000`, `0002_0000`, `0002_0005` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f005.png :material-check:` |
| 46 | `0001_0000`, `0002_0000`, `0002_0005` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f005.png :material-check:` |
| 47 | `0001_0000`, `0002_0000`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 48 | `0001_0000`, `0002_0001`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 49 | `0001_0000`, `0002_0001`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 50 | `0001_0000`, `0002_0001`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 51 | `0001_0000`, `0002_0002`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 52 | `0001_0000`, `0002_0002`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 53 | `0001_0000`, `0002_0002`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 54 | `0001_0000`, `0002_0003`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 55 | `0001_0000`, `0002_0003`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 56 | `0001_0000`, `0002_0003`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 57 | `0001_0000`, `0002_0003`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 58 | `0001_0000`, `0002_0004`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f004.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 59 | `0001_0000`, `0002_0004`, `0001_0000`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 60 | `0001_0000` | `build/phase-3/bitmaps/PART80_f000.png :material-check:` |
| 61 | `0001_0001` | `build/phase-3/bitmaps/PART80_f001.png :material-check:` |
| 62 | `0001_0002`, `0002_0008`, `0002_0012` | `build/phase-3/bitmaps/PART80_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f008.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f012.png :material-check:` |
| 63 | `0002_0013`, `0002_0014`, `0002_0015`, `0001_0000`, `0002_0009` | `build/phase-3/bitmaps/ROKTBLAS_f013.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f014.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:` |
| 64 | `0002_0014`, `0002_0017`, `0002_0015`, `0002_0016`, `0001_0000`, `0002_0011` | `build/phase-3/bitmaps/ROKTBLAS_f014.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f017.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f015.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f011.png :material-check:` |
| 65 | `0001_0000`, `0002_0010` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f010.png :material-check:` |
| 66 | `0001_0000`, `0002_0009` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:` |
| 67 | `0001_0000`, `0002_0008` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f008.png :material-check:` |
| 68 | `0001_0000`, `0002_0009` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:` |
| 69 | `0001_0000`, `0002_0010` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f010.png :material-check:` |
| 70 | `0001_0000`, `0002_0011` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f011.png :material-check:` |
| 71 | `0005_0000` | `build/phase-3/bitmaps/FWGREN_f000.png :material-check:` |
| 72 | `0005_0000` | `build/phase-3/bitmaps/FWGREN_f000.png :material-check:` |
| 73 | `0005_0001` | `build/phase-3/bitmaps/FWGREN_f001.png :material-check:` |
| 74 | `0005_0002` | `build/phase-3/bitmaps/FWGREN_f002.png :material-check:` |
| 75 | `0005_0003` | `build/phase-3/bitmaps/FWGREN_f003.png :material-check:` |
| 76 | `0005_0004` | `build/phase-3/bitmaps/FWGREN_f004.png :material-check:` |
| 77 | `0005_0005` | `build/phase-3/bitmaps/FWGREN_f005.png :material-check:` |
| 78 | `0005_0006` | `build/phase-3/bitmaps/FWGREN_f006.png :material-check:` |
| 79 | `0005_0007` | `build/phase-3/bitmaps/FWGREN_f007.png :material-check:` |
| 80 | `0005_0008` | `build/phase-3/bitmaps/FWGREN_f008.png :material-check:` |
| 81 | `0005_0009` | `build/phase-3/bitmaps/FWGREN_f009.png :material-check:` |
| 82 | `0005_0010` | `build/phase-3/bitmaps/FWGREN_f010.png :material-check:` |
| 83 | `0005_0011` | `build/phase-3/bitmaps/FWGREN_f011.png :material-check:` |
| 84 | `0005_0012` | `build/phase-3/bitmaps/FWGREN_f012.png :material-check:` |
| 85 | `0005_0013` | `build/phase-3/bitmaps/FWGREN_f013.png :material-check:` |
| 86 | `0003_0000` | `build/phase-3/bitmaps/BLANK.png :material-check:` |
| 87 | `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:` |
| 88 | `0001_0000`, `0002_0000`, `0002_0005` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f005.png :material-check:` |
| 89 | `0001_0000`, `0002_0000`, `0002_0005` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f005.png :material-check:` |
| 90 | `0001_0000`, `0002_0000`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 91 | `0001_0000`, `0002_0001`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 92 | `0001_0000`, `0002_0001`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 93 | `0001_0000`, `0002_0001`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 94 | `0001_0000`, `0002_0002`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 95 | `0001_0000`, `0002_0002`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 96 | `0001_0000`, `0002_0002`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 97 | `0001_0000`, `0002_0003`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 98 | `0001_0000`, `0002_0003`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 99 | `0001_0000`, `0002_0003`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 100 | `0001_0000`, `0002_0003`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 101 | `0001_0000`, `0002_0004`, `0002_0007` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f004.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 102 | `0001_0000`, `0002_0004`, `0001_0000`, `0002_0006` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 103 | `0001_0000` | `build/phase-3/bitmaps/PART80_f000.png :material-check:` |
| 104 | `0001_0001` | `build/phase-3/bitmaps/PART80_f001.png :material-check:` |
| 105 | `0001_0002`, `0002_0008`, `0002_0012` | `build/phase-3/bitmaps/PART80_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f008.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f012.png :material-check:` |
| 106 | `0002_0013`, `0002_0014`, `0002_0015`, `0001_0000`, `0002_0009` | `build/phase-3/bitmaps/ROKTBLAS_f013.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f014.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:` |
| 107 | `0002_0014`, `0002_0017`, `0002_0015`, `0002_0016`, `0001_0000`, `0002_0011` | `build/phase-3/bitmaps/ROKTBLAS_f014.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f017.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f015.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f011.png :material-check:` |
| 108 | `0001_0000`, `0002_0010` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f010.png :material-check:` |
| 109 | `0001_0000`, `0002_0009` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:` |
| 110 | `0001_0000`, `0002_0008` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f008.png :material-check:` |
| 111 | `0001_0000`, `0002_0009` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:` |
| 112 | `0001_0000`, `0002_0010` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f010.png :material-check:` |
| 113 | `0001_0000`, `0002_0011` | `build/phase-3/bitmaps/PART80_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f011.png :material-check:` |
| 114 | `0006_0000` | `build/phase-3/bitmaps/FWYEL_f000.png :material-check:` |
| 115 | `0006_0000` | `build/phase-3/bitmaps/FWYEL_f000.png :material-check:` |
| 116 | `0006_0001` | `build/phase-3/bitmaps/FWYEL_f001.png :material-check:` |
| 117 | `0006_0002` | `build/phase-3/bitmaps/FWYEL_f002.png :material-check:` |
| 118 | `0006_0003` | `build/phase-3/bitmaps/FWYEL_f003.png :material-check:` |
| 119 | `0006_0004` | `build/phase-3/bitmaps/FWYEL_f004.png :material-check:` |
| 120 | `0006_0005` | `build/phase-3/bitmaps/FWYEL_f005.png :material-check:` |
| 121 | `0006_0006` | `build/phase-3/bitmaps/FWYEL_f006.png :material-check:` |
| 122 | `0006_0007` | `build/phase-3/bitmaps/FWYEL_f007.png :material-check:` |
| 123 | `0006_0008` | `build/phase-3/bitmaps/FWYEL_f008.png :material-check:` |
| 124 | `0006_0009` | `build/phase-3/bitmaps/FWYEL_f009.png :material-check:` |
| 125 | `0006_0010` | `build/phase-3/bitmaps/FWYEL_f010.png :material-check:` |
| 126 | `0006_0011` | `build/phase-3/bitmaps/FWYEL_f011.png :material-check:` |
| 127 | `0006_0012` | `build/phase-3/bitmaps/FWYEL_f012.png :material-check:` |
| 128 | `0006_0013` | `build/phase-3/bitmaps/FWYEL_f013.png :material-check:` |
| 129 | `0006_0014` | `build/phase-3/bitmaps/FWYEL_f014.png :material-check:` |
| 130 | `0006_0015` | `build/phase-3/bitmaps/FWYEL_f015.png :material-check:` |
| 131 | `0006_0016` | `build/phase-3/bitmaps/FWYEL_f016.png :material-check:` |
| 132 | `0006_0017` | `build/phase-3/bitmaps/FWYEL_f017.png :material-check:` |
| 133 | `0006_0018` | `build/phase-3/bitmaps/FWYEL_f018.png :material-check:` |
| 134 | `0003_0000` | `build/phase-3/bitmaps/BLANK.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 27 | `3080` | 0 | `build/phase-6/raw-wav/SX_3080_11025.wav` |
| 45 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 71 | `3080` | 0 | `build/phase-6/raw-wav/SX_3080_11025.wav` |
| 88 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 114 | `3080` | 0 | `build/phase-6/raw-wav/SX_3080_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 282 |
| `END_FRAME` | 135 |
| `PLAY_SFX` | 6 |
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

**Fireworks** has 2 semantic states: Not Set Off, Set Off. Transitions are triggered by: collision, proximity, timer.

Terminal state(s): Set Off (part is removed from simulation).

This part can be destroyed by explosives.

This part spawns a **projectile** (cannonball, rocket, missile) when triggered. The projectile is a separate part instance.

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART80.json` |
| Sprite PNGs | `godot/assets/sprites/PART80_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/HH32.yaml` |
| Level YAML | `godot/assets/levels/HH33.yaml` |
| Level YAML | `godot/assets/levels/HH44.yaml` |
| Level YAML | `godot/assets/levels/HH50.yaml` |
| ... | +12 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART80.json` + `build/phase-5/yaml/`*
