# Part 36 — Rocket

## Identity

| Field | Value |
|-------|-------|
| Part Type | `36` |
| Category | Explosives / Projectiles |
| Description | You can light the fuse of this rocket with a candle (or other flaming part), a laser beam, a phazer, or by using a magnifying glass and light source. It can be flipped to fly straight up, left, or right. |
| ANM File | `PART36.ANM` → `build/phase-4/anm/PART36.json` |
| BMP Resource | `PART36.BMP` → `build/phase-3/bitmaps/PART36_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**24 level(s)** use this part type:

- `build/phase-5/yaml/HH11.yaml` → `godot/assets/levels/HH11.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH30.yaml` → `godot/assets/levels/HH30.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH48.yaml` → `godot/assets/levels/HH48.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV23.yaml` → `godot/assets/levels/HLEV23.yaml`
- `build/phase-5/yaml/HLEV25.yaml` → `godot/assets/levels/HLEV25.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/MLEV7.yaml` → `godot/assets/levels/MLEV7.yaml`
- `build/phase-5/yaml/RLEV11.yaml` → `godot/assets/levels/RLEV11.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/RLEV7.yaml` → `godot/assets/levels/RLEV7.yaml`
- `build/phase-5/yaml/RLEV9.yaml` → `godot/assets/levels/RLEV9.yaml`
- `build/phase-5/yaml/TLEV10.yaml` → `godot/assets/levels/TLEV10.yaml`
- `build/phase-5/yaml/TLEV16.yaml` → `godot/assets/levels/TLEV16.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 18000 | mass/density (relative scale) |
| `unk_2` | 1800 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 84 | bitmap frame width |
| `bitmap_h` | 84 | bitmap frame height |

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
| Not Fired | `2→17`, `12→18`, `25→21` | 25 | No |
| Fired | `8→12`, `15→25`, `24→-1` | 21 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 107 |
| Total States | 15 |
| Animated (Section A) | Yes |
| Section A Durations | 117 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 0 | 0 | 32×85 | 0 |
| `10` | 1 | 1–3 (3 frames) | 32×87 | 13 |
| `17` | 4 | 4–30 (27 frames) | 64×110 | 70 |
| `9` | 31 | 31–34 (4 frames) | 86×29 | 557 |
| `8` | 35 | 35–40 (6 frames) | 114×62 | 633 |
| `12` | 41 | 41 | 111×50 | 749 |
| `16` | 42 | 42–44 (3 frames) | 105×62 | 768 |
| `18` | 45 | 45–65 (21 frames) | 102×62 | 825 |
| `14` | 66 | 66–71 (6 frames) | 88×29 | 1178 |
| `15` | 72 | 72–77 (6 frames) | 86×51 | 1274 |
| `25` | 78 | 78 | 110×49 | 1390 |
| `20` | 79 | 79–82 (4 frames) | 112×50 | 1409 |
| `21` | 83 | 83–103 (21 frames) | 102×62 | 1485 |
| `23` | 104 | 104–110 (7 frames) | 84×29 | 1838 |
| `24` | 111 | 111 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0002_0000`, `0001_0000` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:` |
| 1 | `0002_0000`, `0001_0000`, `0003_0000` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f000.png :material-check:` |
| 2 | `0002_0000`, `0001_0000`, `0003_0001` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f001.png :material-check:` |
| 3 | `0002_0000`, `0001_0000`, `0003_0002` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f002.png :material-check:` |
| 4 | `0002_0000`, `0001_0000`, `0001_0005` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f005.png :material-check:` |
| 5 | `0002_0000`, `0001_0000`, `0001_0005` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f005.png :material-check:` |
| 6 | `0002_0000`, `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 7 | `0002_0000`, `0001_0001`, `0001_0007` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 8 | `0002_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 9 | `0002_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f001.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 10 | `0002_0000`, `0001_0002`, `0001_0007` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 11 | `0002_0000`, `0001_0002`, `0001_0007` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 12 | `0002_0000`, `0001_0002`, `0001_0006` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f002.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 13 | `0002_0000`, `0001_0003`, `0001_0007` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 14 | `0002_0000`, `0001_0003`, `0001_0007` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 15 | `0002_0000`, `0001_0003`, `0001_0006` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:` |
| 16 | `0002_0000`, `0001_0003`, `0001_0007` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 17 | `0002_0000`, `0001_0004`, `0001_0007` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f004.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f007.png :material-check:` |
| 18 | `0001_0004`, `0001_0006`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f004.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART36_f000.png :material-check:` |
| 19 | `0002_0000` | `build/phase-3/bitmaps/PART36_f000.png :material-check:` |
| 20 | `0002_0001` | `build/phase-3/bitmaps/PART36_f001.png :material-check:` |
| 21 | `0001_0008`, `0001_0012`, `0002_0002` | `build/phase-3/bitmaps/ROKTBLAS_f008.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART36_f002.png :material-check:` |
| 22 | `0001_0008`, `0001_0012`, `0002_0002` | `build/phase-3/bitmaps/ROKTBLAS_f008.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART36_f002.png :material-check:` |
| 23 | `0001_0009`, `0001_0013`, `0001_0014`, `0001_0015`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f013.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f014.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART36_f000.png :material-check:` |
| 24 | `0001_0014`, `0001_0017`, `0001_0015`, `0001_0016`, `0001_0011`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f014.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f017.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f015.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f016.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART36_f000.png :material-check:` |
| 25 | `0001_0010`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART36_f000.png :material-check:` |
| 26 | `0002_0000`, `0001_0009` | `build/phase-3/bitmaps/PART36_f000.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:` |
| 27 | `0001_0008`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART36_f000.png :material-check:` |
| 28 | `0001_0009`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART36_f000.png :material-check:` |
| 29 | `0001_0010`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART36_f000.png :material-check:` |
| 30 | `0001_0011`, `0002_0000` | `build/phase-3/bitmaps/ROKTBLAS_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART36_f000.png :material-check:` |
| 31 | `0002_0003`, `0001_0018` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:` |
| 32 | `0002_0003`, `0002_0003`, `0001_0018`, `0003_0000` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f000.png :material-check:` |
| 33 | `0002_0003`, `0001_0018`, `0003_0001` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f001.png :material-check:` |
| 34 | `0002_0003`, `0001_0018`, `0003_0002` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f002.png :material-check:` |
| 35 | `0002_0003`, `0001_0018`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 36 | `0002_0003`, `0001_0018`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 37 | `0002_0003`, `0001_0018`, `0001_0024` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 38 | `0002_0003`, `0001_0018`, `0001_0025` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 39 | `0002_0003`, `0001_0019`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f019.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 40 | `0002_0003`, `0001_0019`, `0001_0024` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f019.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 41 | `0002_0003`, `0001_0019`, `0001_0025` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f019.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 42 | `0002_0003`, `0001_0020`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f020.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 43 | `0002_0003`, `0001_0020`, `0001_0024` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f020.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 44 | `0002_0003`, `0001_0020`, `0001_0025` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f020.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 45 | `0002_0003`, `0001_0021`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f021.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 46 | `0002_0003`, `0001_0021`, `0001_0024` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f021.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 47 | `0002_0003`, `0001_0021`, `0001_0025` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f021.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 48 | `0002_0003`, `0001_0022`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f022.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 49 | `0002_0003`, `0001_0022`, `0001_0024` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f022.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 50 | `0002_0003`, `0001_0022`, `0001_0025` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f022.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 51 | `0002_0003`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 52 | `0002_0003`, `0001_0024` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 53 | `0002_0003`, `0001_0025` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 54 | `0002_0003` | `build/phase-3/bitmaps/PART36_f003.png :material-check:` |
| 55 | `0002_0004` | `build/phase-3/bitmaps/PART36_f004.png :material-check:` |
| 56 | `0002_0005`, `0001_0026`, `0001_0030` | `build/phase-3/bitmaps/PART36_f005.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f026.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f030.png :material-check:` |
| 57 | `0002_0005`, `0001_0026`, `0001_0030` | `build/phase-3/bitmaps/PART36_f005.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f026.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f030.png :material-check:` |
| 58 | `0002_0003`, `0001_0026`, `0001_0031`, `0001_0032`, `0001_0034` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f026.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f031.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f032.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f034.png :material-check:` |
| 59 | `0002_0003`, `0001_0027`, `0001_0032`, `0001_0034`, `0001_0035`, `0001_0032` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f032.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f034.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f035.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f032.png :material-check:` |
| 60 | `0002_0003`, `0001_0028` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:` |
| 61 | `0002_0003`, `0001_0029` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f029.png :material-check:` |
| 62 | `0002_0003`, `0001_0028` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:` |
| 63 | `0002_0003`, `0001_0027` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:` |
| 64 | `0002_0003`, `0001_0026` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f026.png :material-check:` |
| 65 | `0002_0003`, `0001_0027` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:` |
| 66 | `0002_0003`, `0001_0028` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:` |
| 67 | `0002_0003`, `0001_0029` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f029.png :material-check:` |
| 68 | `0002_0003`, `0001_0018` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:` |
| 69 | `0002_0003`, `0001_0018`, `0003_0000` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f000.png :material-check:` |
| 70 | `0002_0003`, `0001_0018`, `0003_0001` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f001.png :material-check:` |
| 71 | `0002_0003`, `0001_0018`, `0003_0002` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f002.png :material-check:` |
| 72 | `0002_0003`, `0001_0018`, `0003_0003` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f003.png :material-check:` |
| 73 | `0002_0003`, `0001_0018`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 74 | `0002_0003`, `0001_0018`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 75 | `0002_0003`, `0001_0018`, `0001_0024` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 76 | `0002_0003`, `0001_0018`, `0001_0025` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f018.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 77 | `0002_0003`, `0001_0019`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f019.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 78 | `0002_0003`, `0001_0019`, `0001_0024` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f019.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 79 | `0002_0003`, `0001_0019`, `0001_0025` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f019.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 80 | `0002_0003`, `0001_0020`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f020.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 81 | `0002_0003`, `0001_0020`, `0001_0024` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f020.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 82 | `0002_0003`, `0001_0020`, `0001_0025` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f020.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 83 | `0002_0003`, `0001_0021`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f021.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 84 | `0002_0003`, `0001_0021`, `0001_0024` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f021.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 85 | `0002_0003`, `0001_0021`, `0001_0025` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f021.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 86 | `0002_0003`, `0001_0022`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f022.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 87 | `0002_0003`, `0001_0022`, `0001_0024` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f022.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 88 | `0002_0003`, `0001_0022`, `0001_0025` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f022.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 89 | `0002_0003`, `0001_0023` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f023.png :material-check:` |
| 90 | `0002_0003`, `0001_0024` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f024.png :material-check:` |
| 91 | `0002_0003`, `0001_0025` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f025.png :material-check:` |
| 92 | `0002_0003` | `build/phase-3/bitmaps/PART36_f003.png :material-check:` |
| 93 | `0002_0004` | `build/phase-3/bitmaps/PART36_f004.png :material-check:` |
| 94 | `0002_0005`, `0001_0026`, `0001_0030` | `build/phase-3/bitmaps/PART36_f005.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f026.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f030.png :material-check:` |
| 95 | `0002_0005`, `0001_0026`, `0001_0030` | `build/phase-3/bitmaps/PART36_f005.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f026.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f030.png :material-check:` |
| 96 | `0002_0003`, `0001_0027`, `0001_0031`, `0001_0032`, `0001_0035` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f031.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f032.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f035.png :material-check:` |
| 97 | `0002_0003`, `0001_0028`, `0001_0035`, `0001_0032`, `0001_0034`, `0001_0033` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f035.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f032.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f034.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f033.png :material-check:` |
| 98 | `0002_0003`, `0001_0029` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f029.png :material-check:` |
| 99 | `0002_0003`, `0001_0028` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:` |
| 100 | `0002_0003`, `0001_0027` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:` |
| 101 | `0002_0003`, `0001_0026` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f026.png :material-check:` |
| 102 | `0002_0003`, `0001_0027` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:` |
| 103 | `0002_0003`, `0001_0028` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:` |
| 104 | `0002_0003`, `0001_0029` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f029.png :material-check:` |
| 105 | `0002_0003`, `0001_0028` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f028.png :material-check:` |
| 106 | `0002_0003`, `0001_0027` | `build/phase-3/bitmaps/PART36_f003.png :material-check:`<br>`build/phase-3/bitmaps/ROKTBLAS_f027.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 4 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 21 | `3036` | 0 | `build/phase-6/raw-wav/SX_3036_11025.wav` |
| 35 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 56 | `3036` | 0 | `build/phase-6/raw-wav/SX_3036_11025.wav` |
| 73 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 94 | `3036` | 0 | `build/phase-6/raw-wav/SX_3036_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 293 |
| `END_FRAME` | 107 |
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

**Rocket** has 2 semantic states: Not Fired, Fired. Transitions are triggered by: collision, proximity, timer.

Terminal state(s): Fired (part is removed from simulation).

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
| ANM JSON | `build/phase-4/anm/PART36.json` |
| Sprite PNGs | `godot/assets/sprites/PART36_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/HH11.yaml` |
| Level YAML | `godot/assets/levels/HH17.yaml` |
| Level YAML | `godot/assets/levels/HH30.yaml` |
| Level YAML | `godot/assets/levels/HH32.yaml` |
| Level YAML | `godot/assets/levels/HH33.yaml` |
| ... | +19 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART36.json` + `build/phase-5/yaml/`*
