# Part 12 — Curie Cat

## Identity

| Field | Value |
|-------|-------|
| Part Type | `12` |
| Category | Characters |
| Description | Curie Cat will head toward Newton Mouse or Bill the Goldfish whenever he can see them. He'll turn around if he's bumped or runs into something. He also likes the goo that comes out of the can when it falls from the can opener. |
| ANM File | `PART12.ANM` → `build/phase-4/anm/PART12.json` |
| BMP Resource | `PART12.BMP` → `build/phase-3/bitmaps/PART12_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**21 level(s)** use this part type:

- `build/phase-5/yaml/ELEV16.yaml` → `godot/assets/levels/ELEV16.yaml`
- `build/phase-5/yaml/ELEV2.yaml` → `godot/assets/levels/ELEV2.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/ELEV23.yaml` → `godot/assets/levels/ELEV23.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HLEV11.yaml` → `godot/assets/levels/HLEV11.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV2.yaml` → `godot/assets/levels/HLEV2.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV4.yaml` → `godot/assets/levels/HLEV4.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/MLEV1.yaml` → `godot/assets/levels/MLEV1.yaml`
- `build/phase-5/yaml/MLEV11.yaml` → `godot/assets/levels/MLEV11.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV18.yaml` → `godot/assets/levels/RLEV18.yaml`
- `build/phase-5/yaml/RLEV2.yaml` → `godot/assets/levels/RLEV2.yaml`
- `build/phase-5/yaml/RLEV28.yaml` → `godot/assets/levels/RLEV28.yaml`
- `build/phase-5/yaml/RLEV8.yaml` → `godot/assets/levels/RLEV8.yaml`
- `build/phase-5/yaml/TLEV34.yaml` → `godot/assets/levels/TLEV34.yaml`
- `build/phase-5/yaml/TLEV35.yaml` → `godot/assets/levels/TLEV35.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2000 | mass/density (relative scale) |
| `unk_2` | 120 | category-specific property |
| `property_q8` | 0 | Q8.8 = 0.000 |
| `unk_6` | 64 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 39 | bitmap frame width |
| `bitmap_h` | 42 | bitmap frame height |

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
| Hasn't Eaten | `1→9` | 1 | No |
| Has Eaten | `9→-1` | 9 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 182 |
| Total States | 12 |
| Animated (Section A) | Yes |
| Section A Durations | 334 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 45×42 | 0 |
| `8` | 1 | 1–74 (74 frames) | 45×42 | 19 |
| `7` | 75 | 75–96 (22 frames) | 72×57 | 1249 |
| `6` | 97 | 97–148 (52 frames) | 45×42 | 1439 |
| `4` | 149 | 149–159 (11 frames) | 48×33 | 2349 |
| `5` | 160 | 160–169 (10 frames) | 48×33 | 2492 |
| `9` | 170 | 170 | 72×57 | 2576 |
| `11` | 171 | 171–244 (74 frames) | 72×57 | 2583 |
| `12` | 245 | 245–261 (17 frames) | 0×0 | 0 |
| `13` | 262 | 262–313 (52 frames) | 0×0 | 0 |
| `14` | 314 | 314–323 (10 frames) | 0×0 | 0 |
| `10` | 324 | 324 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0002`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 1 | `0001_0002`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 2 | `0001_0000`, `0001_0004`, `0001_0001` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 3 | `0001_0000`, `0001_0003`, `0001_0001` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 4 | `0001_0005`, `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:` |
| 5 | `0001_0006`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 6 | `0001_0004`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 7 | `0001_0002`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 8 | `0001_0004`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 9 | `0001_0003`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 10 | `0001_0005`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 11 | `0001_0006`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 12 | `0001_0004`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 13 | `0001_0005`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 14 | `0001_0000`, `0001_0001`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 15 | `0001_0003`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 16 | `0001_0002`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 17 | `0001_0000`, `0001_0001`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 18 | `0001_0000`, `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f002.png :material-check:` |
| 19 | `0001_0000`, `0001_0001`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 20 | `0001_0000`, `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f002.png :material-check:` |
| 21 | `0001_0000`, `0001_0001`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 22 | `0001_0005`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 23 | `0001_0000`, `0001_0001`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 24 | `0001_0002`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 25 | `0001_0002`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 26 | `0001_0000`, `0001_0022`, `0001_0002` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f022.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f002.png :material-check:` |
| 27 | `0001_0000`, `0001_0022`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f022.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 28 | `0001_0000`, `0001_0023`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f023.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 29 | `0001_0003`, `0001_0000`, `0001_0023` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f023.png :material-check:` |
| 30 | `0001_0003`, `0001_0000`, `0001_0024` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f024.png :material-check:` |
| 31 | `0001_0003`, `0001_0000`, `0001_0024` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f024.png :material-check:` |
| 32 | `0001_0000`, `0001_0024`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f024.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 33 | `0001_0000`, `0001_0025`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f025.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 34 | `0001_0006`, `0001_0000`, `0001_0025` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f025.png :material-check:` |
| 35 | `0001_0005`, `0001_0000`, `0001_0025` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f025.png :material-check:` |
| 36 | `0001_0006`, `0001_0000`, `0001_0025` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f025.png :material-check:` |
| 37 | `0001_0000`, `0001_0025`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f025.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 38 | `0001_0005`, `0001_0000`, `0001_0025` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f025.png :material-check:` |
| 39 | `0001_0000`, `0001_0025`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f025.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 40 | `0001_0006`, `0001_0000`, `0001_0025` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f025.png :material-check:` |
| 41 | `0001_0006`, `0001_0000`, `0001_0024` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f024.png :material-check:` |
| 42 | `0001_0003`, `0001_0000`, `0001_0024` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f024.png :material-check:` |
| 43 | `0001_0003`, `0001_0000`, `0001_0023` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f023.png :material-check:` |
| 44 | `0001_0000`, `0001_0023`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f023.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 45 | `0001_0000`, `0001_0022`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f022.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 46 | `0001_0006`, `0001_0000`, `0001_0022` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f022.png :material-check:` |
| 47 | `0001_0003`, `0001_0017` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f017.png :material-check:` |
| 48 | `0001_0003`, `0001_0018` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f018.png :material-check:` |
| 49 | `0001_0017`, `0001_0004` | `build/phase-3/bitmaps/PART12_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 50 | `0001_0018`, `0001_0004` | `build/phase-3/bitmaps/PART12_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 51 | `0001_0006`, `0001_0017` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f017.png :material-check:` |
| 52 | `0001_0006`, `0001_0018` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f018.png :material-check:` |
| 53 | `0001_0005`, `0001_0019` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f019.png :material-check:` |
| 54 | `0001_0005`, `0001_0020` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f020.png :material-check:` |
| 55 | `0001_0006`, `0001_0021` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f021.png :material-check:` |
| 56 | `0001_0006`, `0001_0019` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f019.png :material-check:` |
| 57 | `0001_0020`, `0001_0004` | `build/phase-3/bitmaps/PART12_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 58 | `0001_0021`, `0001_0004` | `build/phase-3/bitmaps/PART12_f021.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 59 | `0001_0003`, `0001_0019` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f019.png :material-check:` |
| 60 | `0001_0003`, `0001_0020` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f020.png :material-check:` |
| 61 | `0001_0005`, `0001_0021` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f021.png :material-check:` |
| 62 | `0001_0005`, `0001_0018` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f018.png :material-check:` |
| 63 | `0001_0006`, `0001_0017` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f017.png :material-check:` |
| 64 | `0001_0006`, `0001_0018` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f018.png :material-check:` |
| 65 | `0001_0004`, `0001_0017` | `build/phase-3/bitmaps/PART12_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f017.png :material-check:` |
| 66 | `0001_0018`, `0001_0004` | `build/phase-3/bitmaps/PART12_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 67 | `0001_0006`, `0001_0019` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f019.png :material-check:` |
| 68 | `0001_0006`, `0001_0020` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f020.png :material-check:` |
| 69 | `0001_0003`, `0001_0021` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f021.png :material-check:` |
| 70 | `0001_0003`, `0001_0019` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f019.png :material-check:` |
| 71 | `0001_0005`, `0001_0020` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f020.png :material-check:` |
| 72 | `0001_0005`, `0001_0021` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f021.png :material-check:` |
| 73 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 74 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 75 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 76 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 77 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 78 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 79 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 80 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 81 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 82 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 83 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 84 | `0001_0007` | `build/phase-3/bitmaps/PART12_f007.png :material-check:` |
| 85 | `0001_0008` | `build/phase-3/bitmaps/PART12_f008.png :material-check:` |
| 86 | `0001_0009` | `build/phase-3/bitmaps/PART12_f009.png :material-check:` |
| 87 | `0001_0010` | `build/phase-3/bitmaps/PART12_f010.png :material-check:` |
| 88 | `0001_0011` | `build/phase-3/bitmaps/PART12_f011.png :material-check:` |
| 89 | `0001_0012` | `build/phase-3/bitmaps/PART12_f012.png :material-check:` |
| 90 | `0001_0013` | `build/phase-3/bitmaps/PART12_f013.png :material-check:` |
| 91 | `0001_0014` | `build/phase-3/bitmaps/PART12_f014.png :material-check:` |
| 92 | `0001_0015` | `build/phase-3/bitmaps/PART12_f015.png :material-check:` |
| 93 | `0001_0016` | `build/phase-3/bitmaps/PART12_f016.png :material-check:` |
| 94 | `0001_0002`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 95 | `0001_0002`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 96 | `0001_0000`, `0001_0004`, `0001_0001` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 97 | `0001_0000`, `0001_0003`, `0001_0001` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 98 | `0001_0005`, `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:` |
| 99 | `0001_0006`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 100 | `0001_0004`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 101 | `0001_0002`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 102 | `0001_0004`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 103 | `0001_0003`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 104 | `0001_0005`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 105 | `0001_0006`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 106 | `0001_0004`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 107 | `0001_0005`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 108 | `0001_0000`, `0001_0001`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 109 | `0001_0003`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 110 | `0001_0002`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 111 | `0001_0000`, `0001_0001`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 112 | `0001_0000`, `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f002.png :material-check:` |
| 113 | `0001_0000`, `0001_0001`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 114 | `0001_0000`, `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f002.png :material-check:` |
| 115 | `0001_0000`, `0001_0001`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 116 | `0001_0005`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 117 | `0001_0000`, `0001_0001`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 118 | `0001_0002`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 119 | `0001_0002`, `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART12_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f001.png :material-check:` |
| 120 | `0001_0000`, `0001_0022`, `0001_0002` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f022.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f002.png :material-check:` |
| 121 | `0001_0000`, `0001_0022`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f022.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 122 | `0001_0000`, `0001_0023`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f023.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 123 | `0001_0003`, `0001_0000`, `0001_0023` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f023.png :material-check:` |
| 124 | `0001_0003`, `0001_0000`, `0001_0024` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f024.png :material-check:` |
| 125 | `0001_0000`, `0001_0024`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f024.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 126 | `0001_0000`, `0001_0025`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f025.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 127 | `0001_0005`, `0001_0000`, `0001_0025` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f025.png :material-check:` |
| 128 | `0001_0005`, `0001_0000`, `0001_0025` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f025.png :material-check:` |
| 129 | `0001_0006`, `0001_0000`, `0001_0025` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f025.png :material-check:` |
| 130 | `0001_0006`, `0001_0000`, `0001_0024` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f024.png :material-check:` |
| 131 | `0001_0003`, `0001_0000`, `0001_0024` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f024.png :material-check:` |
| 132 | `0001_0003`, `0001_0000`, `0001_0023` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f023.png :material-check:` |
| 133 | `0001_0000`, `0001_0023`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f023.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 134 | `0001_0000`, `0001_0022`, `0001_0004` | `build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f022.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 135 | `0001_0006`, `0001_0000`, `0001_0022` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f022.png :material-check:` |
| 136 | `0001_0003`, `0001_0017` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f017.png :material-check:` |
| 137 | `0001_0003`, `0001_0018` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f018.png :material-check:` |
| 138 | `0001_0017`, `0001_0004` | `build/phase-3/bitmaps/PART12_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 139 | `0001_0018`, `0001_0004` | `build/phase-3/bitmaps/PART12_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 140 | `0001_0006`, `0001_0017` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f017.png :material-check:` |
| 141 | `0001_0006`, `0001_0018` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f018.png :material-check:` |
| 142 | `0001_0005`, `0001_0019` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f019.png :material-check:` |
| 143 | `0001_0005`, `0001_0020` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f020.png :material-check:` |
| 144 | `0001_0006`, `0001_0021` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f021.png :material-check:` |
| 145 | `0001_0006`, `0001_0019` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f019.png :material-check:` |
| 146 | `0001_0020`, `0001_0004` | `build/phase-3/bitmaps/PART12_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 147 | `0001_0021`, `0001_0004` | `build/phase-3/bitmaps/PART12_f021.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 148 | `0001_0003`, `0001_0019` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f019.png :material-check:` |
| 149 | `0001_0003`, `0001_0020` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f020.png :material-check:` |
| 150 | `0001_0005`, `0001_0021` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f021.png :material-check:` |
| 151 | `0001_0005`, `0001_0018` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f018.png :material-check:` |
| 152 | `0001_0006`, `0001_0017` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f017.png :material-check:` |
| 153 | `0001_0006`, `0001_0018` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f018.png :material-check:` |
| 154 | `0001_0004`, `0001_0017` | `build/phase-3/bitmaps/PART12_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f017.png :material-check:` |
| 155 | `0001_0018`, `0001_0004` | `build/phase-3/bitmaps/PART12_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f004.png :material-check:` |
| 156 | `0001_0006`, `0001_0019` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f019.png :material-check:` |
| 157 | `0001_0006`, `0001_0020` | `build/phase-3/bitmaps/PART12_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f020.png :material-check:` |
| 158 | `0001_0003`, `0001_0021` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f021.png :material-check:` |
| 159 | `0001_0003`, `0001_0019` | `build/phase-3/bitmaps/PART12_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f019.png :material-check:` |
| 160 | `0001_0005`, `0001_0020` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f020.png :material-check:` |
| 161 | `0001_0005`, `0001_0021` | `build/phase-3/bitmaps/PART12_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART12_f021.png :material-check:` |
| 162 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 163 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 164 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 165 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 166 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 167 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 168 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 169 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 170 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 171 | `0001_0026` | `build/phase-3/bitmaps/PART12_f026.png :material-check:` |
| 172 | `0001_0007` | `build/phase-3/bitmaps/PART12_f007.png :material-check:` |
| 173 | `0001_0008` | `build/phase-3/bitmaps/PART12_f008.png :material-check:` |
| 174 | `0001_0009` | `build/phase-3/bitmaps/PART12_f009.png :material-check:` |
| 175 | `0001_0010` | `build/phase-3/bitmaps/PART12_f010.png :material-check:` |
| 176 | `0001_0011` | `build/phase-3/bitmaps/PART12_f011.png :material-check:` |
| 177 | `0001_0012` | `build/phase-3/bitmaps/PART12_f012.png :material-check:` |
| 178 | `0001_0013` | `build/phase-3/bitmaps/PART12_f013.png :material-check:` |
| 179 | `0001_0014` | `build/phase-3/bitmaps/PART12_f014.png :material-check:` |
| 180 | `0001_0015` | `build/phase-3/bitmaps/PART12_f015.png :material-check:` |
| 181 | `0001_0016` | `build/phase-3/bitmaps/PART12_f016.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 30 | `3312` | 0 | `build/phase-6/raw-wav/SX_3312_11025.wav` |
| 73 | `3012` | 0 | `build/phase-6/raw-wav/SX_3012_11025.wav` |
| 162 | `3012` | 0 | `build/phase-6/raw-wav/SX_3012_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 412 |
| `END_FRAME` | 182 |
| `PLAY_SFX` | 3 |
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

**Curie Cat** has 2 semantic states: Hasn't Eaten, Has Eaten. Transitions are triggered by: collision, proximity.

Terminal state(s): Has Eaten (part is removed from simulation).

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART12.json` |
| Sprite PNGs | `godot/assets/sprites/PART12_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV16.yaml` |
| Level YAML | `godot/assets/levels/ELEV2.yaml` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/ELEV23.yaml` |
| Level YAML | `godot/assets/levels/HH37.yaml` |
| ... | +16 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART12.json` + `build/phase-5/yaml/`*
