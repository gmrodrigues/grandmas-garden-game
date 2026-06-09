# Part 70 — Missile

## Identity

| Field | Value |
|-------|-------|
| Part Type | `70` |
| Category | Explosives / Projectiles |
| Description | This missile is handy for blowing up all sorts of things, including most walls. Light the fuse with a laser, a phazer, a candle (or other flaming part), or by using a magnifying glass and light source. You can flip it to fly straight up, right, or left. |
| ANM File | `PART70.ANM` → `build/phase-4/anm/PART70.json` |
| BMP Resource | `PART70.BMP` → `build/phase-3/bitmaps/PART70_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**23 level(s)** use this part type:

- `build/phase-5/yaml/ELEV19.yaml` → `godot/assets/levels/ELEV19.yaml`
- `build/phase-5/yaml/ELEV24.yaml` → `godot/assets/levels/ELEV24.yaml`
- `build/phase-5/yaml/HH10.yaml` → `godot/assets/levels/HH10.yaml`
- `build/phase-5/yaml/HH13.yaml` → `godot/assets/levels/HH13.yaml`
- `build/phase-5/yaml/HH14.yaml` → `godot/assets/levels/HH14.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH38.yaml` → `godot/assets/levels/HH38.yaml`
- `build/phase-5/yaml/HH45.yaml` → `godot/assets/levels/HH45.yaml`
- `build/phase-5/yaml/HH46.yaml` → `godot/assets/levels/HH46.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV13.yaml` → `godot/assets/levels/HLEV13.yaml`
- `build/phase-5/yaml/HLEV15.yaml` → `godot/assets/levels/HLEV15.yaml`
- `build/phase-5/yaml/HLEV23.yaml` → `godot/assets/levels/HLEV23.yaml`
- `build/phase-5/yaml/HLEV30.yaml` → `godot/assets/levels/HLEV30.yaml`
- `build/phase-5/yaml/HLEV4.yaml` → `godot/assets/levels/HLEV4.yaml`
- `build/phase-5/yaml/MLEV24.yaml` → `godot/assets/levels/MLEV24.yaml`
- `build/phase-5/yaml/MLEV3.yaml` → `godot/assets/levels/MLEV3.yaml`
- `build/phase-5/yaml/MLEV5.yaml` → `godot/assets/levels/MLEV5.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`
- `build/phase-5/yaml/RLEV7.yaml` → `godot/assets/levels/RLEV7.yaml`
- `build/phase-5/yaml/TLEV10.yaml` → `godot/assets/levels/TLEV10.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 22000 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 96 | bitmap frame width |
| `bitmap_h` | 96 | bitmap frame height |

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
| Not Launched | `2→8`, `13→14`, `18→19` | 18 | No |
| Launched | `3→12`, `16→17`, `21→22` | 19 | No |
| Exploded | `12→13`, `17→18`, `22→-1` | — | Yes :material-bomb: |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 93 |
| Total States | 15 |
| Animated (Section A) | Yes |
| Section A Durations | 103 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 0 | 0 | 32×95 | 0 |
| `8` | 1 | 1–27 (27 frames) | 64×120 | 13 |
| `4` | 28 | 28–31 (4 frames) | 8×2 | 506 |
| `3` | 32 | 32–37 (6 frames) | 124×49 | 566 |
| `12` | 38 | 38 | 114×49 | 680 |
| `13` | 39 | 39 | 115×50 | 699 |
| `14` | 40 | 40–55 (16 frames) | 109×62 | 718 |
| `15` | 56 | 56–63 (8 frames) | 109×25 | 1018 |
| `16` | 64 | 64–69 (6 frames) | 121×49 | 1130 |
| `17` | 70 | 70 | 116×49 | 1244 |
| `18` | 71 | 71 | 119×50 | 1263 |
| `19` | 72 | 72–87 (16 frames) | 116×62 | 1282 |
| `20` | 88 | 88–95 (8 frames) | 109×25 | 1576 |
| `21` | 96 | 96–101 (6 frames) | 0×0 | 0 |
| `22` | 102 | 102 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0002_0000`, `0001_0000` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:` |
| 1 | `0002_0000`, `0001_0000`, `0001_0005` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f005.png :material-check:` |
| 2 | `0002_0000`, `0001_0000`, `0001_0005` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f005.png :material-check:` |
| 3 | `0002_0000`, `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 4 | `0002_0000`, `0001_0001`, `0001_0007` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 5 | `0002_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 6 | `0002_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 7 | `0002_0000`, `0001_0002`, `0001_0007` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 8 | `0002_0000`, `0001_0002`, `0001_0007` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 9 | `0002_0000`, `0001_0002`, `0001_0006` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 10 | `0002_0000`, `0001_0003`, `0001_0007` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 11 | `0002_0000`, `0001_0003`, `0001_0007` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 12 | `0002_0000`, `0001_0003`, `0001_0006` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 13 | `0002_0000`, `0001_0003`, `0001_0007` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 14 | `0002_0000`, `0001_0004`, `0001_0007` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f004.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 15 | `0002_0000`, `0001_0004`, `0001_0006`, `0002_0000` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f004.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f000.png :material-check:` |
| 16 | `0002_0000` | `build/phase-3/bitmaps/PART70_f000.png :material-check:` |
| 17 | `0002_0001` | `build/phase-3/bitmaps/PART70_f001.png :material-check:` |
| 18 | `0001_0008`, `0001_0012`, `0002_0002` | `build/phase-3/bitmaps/ROKTBLAS_f008.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f002.png :material-check:` |
| 19 | `0001_0008`, `0001_0012`, `0002_0002` | `build/phase-3/bitmaps/ROKTBLAS_f008.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f002.png :material-check:` |
| 20 | `0001_0009`, `0001_0013`, `0001_0014`, `0001_0015`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f013.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f014.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f000.png :material-check:` |
| 21 | `0001_0014`, `0001_0017`, `0001_0015`, `0001_0016`, `0001_0011`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f014.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f017.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f015.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f016.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f000.png :material-check:` |
| 22 | `0001_0010`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f000.png :material-check:` |
| 23 | `0002_0000`, `0001_0009` | `build/phase-3/bitmaps/PART70_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:` |
| 24 | `0001_0008`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f000.png :material-check:` |
| 25 | `0001_0009`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f000.png :material-check:` |
| 26 | `0001_0010`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f000.png :material-check:` |
| 27 | `0001_0011`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f000.png :material-check:` |
| 28 | `0003_0000` | `build/phase-3/bitmaps/BLANK.png :material-check:` |
| 29 | `0002_0003`, `0001_0018` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:` |
| 30 | `0002_0003`, `0001_0018`, `0001_0023` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 31 | `0002_0003`, `0001_0018`, `0001_0023` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 32 | `0002_0003`, `0001_0018`, `0001_0024` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 33 | `0002_0003`, `0001_0018`, `0001_0025` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 34 | `0002_0003`, `0001_0019`, `0001_0023` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f019.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 35 | `0002_0003`, `0001_0019`, `0001_0024` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f019.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 36 | `0002_0003`, `0001_0019`, `0001_0025` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f019.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 37 | `0002_0003`, `0001_0020`, `0001_0023` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f020.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 38 | `0002_0003`, `0001_0020`, `0001_0024` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f020.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 39 | `0002_0003`, `0001_0020`, `0001_0025` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f020.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 40 | `0002_0003`, `0001_0021`, `0001_0023` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f021.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 41 | `0002_0003`, `0001_0021`, `0001_0024` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f021.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 42 | `0002_0003`, `0001_0021`, `0001_0025` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f021.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 43 | `0002_0003`, `0001_0022`, `0001_0023` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f022.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 44 | `0002_0003`, `0001_0022`, `0001_0024` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f022.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 45 | `0002_0003`, `0001_0022`, `0001_0025` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f022.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 46 | `0002_0003` | `build/phase-3/bitmaps/PART70_f003.png :material-check:` |
| 47 | `0002_0004` | `build/phase-3/bitmaps/PART70_f004.png :material-check:` |
| 48 | `0002_0005`, `0001_0027`, `0001_0030` | `build/phase-3/bitmaps/PART70_f005.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f030.png :material-check:` |
| 49 | `0002_0005`, `0001_0027`, `0001_0030` | `build/phase-3/bitmaps/PART70_f005.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f030.png :material-check:` |
| 50 | `0001_0026`, `0002_0005`, `0001_0031`, `0001_0032`, `0001_0034` | `build/phase-3/bitmaps/ROKTBLAS_f026.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f005.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f031.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f032.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f034.png :material-check:` |
| 51 | `0001_0027`, `0002_0005`, `0001_0035`, `0001_0033`, `0001_0034`, `0001_0033`, `0001_0034`, `0001_0034` | `build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f005.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f035.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f033.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f034.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f033.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f034.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f034.png :material-check:` |
| 52 | `0001_0028`, `0002_0003` | `build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f003.png :material-check:` |
| 53 | `0001_0029`, `0002_0003` | `build/phase-3/bitmaps/ROKTBLAS_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f003.png :material-check:` |
| 54 | `0001_0028`, `0002_0003` | `build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f003.png :material-check:` |
| 55 | `0001_0027`, `0002_0003` | `build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f003.png :material-check:` |
| 56 | `0001_0026`, `0002_0003` | `build/phase-3/bitmaps/ROKTBLAS_f026.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f003.png :material-check:` |
| 57 | `0001_0027`, `0002_0003` | `build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:`<br>`build/phase-3/bitmaps/PART70_f003.png :material-check:` |
| 58 | `0002_0003`, `0001_0028` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:` |
| 59 | `0002_0003`, `0001_0029` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f029.png :material-check:` |
| 60 | `0003_0000` | `build/phase-3/bitmaps/BLANK.png :material-check:` |
| 61 | `0002_0003`, `0001_0018` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:` |
| 62 | `0002_0003`, `0001_0018`, `0001_0023` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 63 | `0002_0003`, `0001_0018`, `0001_0023` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 64 | `0002_0003`, `0001_0018`, `0001_0024` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 65 | `0002_0003`, `0001_0018`, `0001_0025` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 66 | `0002_0003`, `0001_0019`, `0001_0023` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f019.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 67 | `0002_0003`, `0001_0019`, `0001_0024` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f019.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 68 | `0002_0003`, `0001_0019`, `0001_0025` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f019.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 69 | `0002_0003`, `0001_0020`, `0001_0023` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f020.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 70 | `0002_0003`, `0001_0020`, `0001_0024` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f020.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 71 | `0002_0003`, `0001_0020`, `0001_0025` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f020.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 72 | `0002_0003`, `0001_0021`, `0001_0023` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f021.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 73 | `0002_0003`, `0001_0021`, `0001_0024` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f021.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 74 | `0002_0003`, `0001_0021`, `0001_0025` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f021.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 75 | `0002_0003`, `0001_0022`, `0001_0023` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f022.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 76 | `0002_0003`, `0001_0022`, `0001_0024` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f022.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 77 | `0002_0003`, `0001_0022`, `0001_0025` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f022.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 78 | `0002_0003` | `build/phase-3/bitmaps/PART70_f003.png :material-check:` |
| 79 | `0002_0004` | `build/phase-3/bitmaps/PART70_f004.png :material-check:` |
| 80 | `0002_0005`, `0001_0027`, `0001_0030` | `build/phase-3/bitmaps/PART70_f005.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f030.png :material-check:` |
| 81 | `0002_0005`, `0001_0027`, `0001_0030` | `build/phase-3/bitmaps/PART70_f005.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f030.png :material-check:` |
| 82 | `0002_0005`, `0001_0026`, `0001_0031`, `0001_0032`, `0001_0034` | `build/phase-3/bitmaps/PART70_f005.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f026.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f031.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f032.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f034.png :material-check:` |
| 83 | `0002_0005`, `0001_0027`, `0001_0033`, `0001_0033`, `0001_0034`, `0001_0035`, `0001_0034` | `build/phase-3/bitmaps/PART70_f005.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f033.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f033.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f034.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f035.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f034.png :material-check:` |
| 84 | `0002_0003`, `0001_0028` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:` |
| 85 | `0002_0003`, `0001_0029` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f029.png :material-check:` |
| 86 | `0002_0003`, `0001_0028` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:` |
| 87 | `0002_0003`, `0001_0027` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:` |
| 88 | `0002_0003`, `0001_0026` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f026.png :material-check:` |
| 89 | `0002_0003`, `0001_0027` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:` |
| 90 | `0002_0003`, `0001_0028` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:` |
| 91 | `0002_0003`, `0001_0029` | `build/phase-3/bitmaps/PART70_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f029.png :material-check:` |
| 92 | `0003_0000` | `build/phase-3/bitmaps/BLANK.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 18 | `3070` | 0 | `build/phase-6/raw-wav/SX_3070_11025.wav` |
| 30 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 48 | `3070` | 0 | `build/phase-6/raw-wav/SX_3070_11025.wav` |
| 62 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 80 | `3070` | 0 | `build/phase-6/raw-wav/SX_3070_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 255 |
| `END_FRAME` | 93 |
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

**Missile** has 3 semantic states: Not Launched, Launched, Exploded. Transitions are triggered by: collision, proximity, timer.

State(s) Exploded are explosive — reaching these destroys the part.

Terminal state(s): Exploded (part is removed from simulation).

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
| ANM JSON | `build/phase-4/anm/PART70.json` |
| Sprite PNGs | `godot/assets/sprites/PART70_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV19.yaml` |
| Level YAML | `godot/assets/levels/ELEV24.yaml` |
| Level YAML | `godot/assets/levels/HH10.yaml` |
| Level YAML | `godot/assets/levels/HH13.yaml` |
| Level YAML | `godot/assets/levels/HH14.yaml` |
| ... | +18 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART70.json` + `build/phase-5/yaml/`*
