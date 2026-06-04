# Part 18 — Cannon

## Identity

| Field | Value |
|-------|-------|
| Part Type | `18` |
| Category | Explosives / Projectiles |
| Description | Light the fuse of this cannon with a laser, a flaming part (like a candle or rocket), or by using a magnifying glass and light source. It fires cannon balls which can be used to break and bump things. It can be rotated to aim in six different angles. |
| ANM File | `PART18.ANM` → `build/phase-4/anm/PART18.json` |
| BMP Resource | `PART18.BMP` → `build/phase-3/bitmaps/PART18_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**21 level(s)** use this part type:

- `build/phase-5/yaml/ELEV5.yaml` → `godot/assets/levels/ELEV5.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH38.yaml` → `godot/assets/levels/HH38.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HH6.yaml` → `godot/assets/levels/HH6.yaml`
- `build/phase-5/yaml/HLEV11.yaml` → `godot/assets/levels/HLEV11.yaml`
- `build/phase-5/yaml/HLEV2.yaml` → `godot/assets/levels/HLEV2.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/HLEV6.yaml` → `godot/assets/levels/HLEV6.yaml`
- `build/phase-5/yaml/MLEV15.yaml` → `godot/assets/levels/MLEV15.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/MLEV6.yaml` → `godot/assets/levels/MLEV6.yaml`
- `build/phase-5/yaml/RLEV10.yaml` → `godot/assets/levels/RLEV10.yaml`
- `build/phase-5/yaml/RLEV11.yaml` → `godot/assets/levels/RLEV11.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV24.yaml` → `godot/assets/levels/RLEV24.yaml`
- `build/phase-5/yaml/TLEV11.yaml` → `godot/assets/levels/TLEV11.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 14726 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 192 | Q8.8 = 0.750 |
| `unk_6` | 12 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 101 | bitmap frame width |
| `bitmap_h` | 78 | bitmap frame height |

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
| Not Fired | `1→23`, `4→25`, `7→27`, `34→35`, `41→42`, `47→48` | 47 | No |
| Fired | `19→4`, `20→7`, `31→34`, `38→41`, `45→47`, `50→-1` | 48 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 136 |
| Total States | 37 |
| Animated (Section A) | Yes |
| Section A Durations | 178 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 80×61 | 0 |
| `23` | 1 | 1–11 (11 frames) | 91×82 | 19 |
| `24` | 12 | 12–21 (10 frames) | 80×59 | 296 |
| `19` | 22 | 22–26 (5 frames) | 80×59 | 566 |
| `29` | 27 | 27–28 (2 frames) | 90×80 | 675 |
| `3` | 29 | 29 | 88×93 | 725 |
| `4` | 30 | 30 | 98×96 | 750 |
| `25` | 31 | 31–41 (11 frames) | 99×78 | 775 |
| `26` | 42 | 42–51 (10 frames) | 107×43 | 1082 |
| `20` | 52 | 52–56 (5 frames) | 86×78 | 1304 |
| `30` | 57 | 57–58 (2 frames) | 79×78 | 1429 |
| `6` | 59 | 59 | 56×69 | 1467 |
| `7` | 60 | 60 | 64×63 | 1480 |
| `27` | 61 | 61–71 (11 frames) | 132×170 | 1493 |
| `28` | 72 | 72–81 (10 frames) | 94×80 | 1808 |
| `22` | 82 | 82–85 (4 frames) | 72×58 | 2046 |
| `31` | 86 | 86 | 194×129 | 2160 |
| `15` | 87 | 87–89 (3 frames) | 184×129 | 2203 |
| `9` | 90 | 90 | 88×61 | 2290 |
| `34` | 91 | 91 | 80×59 | 2303 |
| `35` | 92 | 92–101 (10 frames) | 88×65 | 2316 |
| `36` | 102 | 102–111 (10 frames) | 98×67 | 2562 |
| `38` | 112 | 112–116 (5 frames) | 96×46 | 2844 |
| `39` | 117 | 117–118 (2 frames) | 91×78 | 2941 |
| `40` | 119 | 119 | 100×78 | 2991 |
| `41` | 120 | 120 | 103×78 | 3016 |
| `42` | 121 | 121–130 (10 frames) | 90×82 | 3041 |
| `43` | 131 | 131–140 (10 frames) | 128×176 | 3311 |
| `45` | 141 | 141–145 (5 frames) | 0×0 | 0 |
| `44` | 146 | 146–147 (2 frames) | 0×0 | 0 |
| `46` | 148 | 148 | 0×0 | 0 |
| `47` | 149 | 149 | 0×0 | 0 |
| `48` | 150 | 150–159 (10 frames) | 0×0 | 0 |
| `49` | 160 | 160–169 (10 frames) | 0×0 | 0 |
| `50` | 170 | 170–174 (5 frames) | 0×0 | 0 |
| `51` | 175 | 175–176 (2 frames) | 0×0 | 0 |
| `52` | 177 | 177 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0002_0000`, `0002_0004` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)` |
| 1 | `0001_0000`, `0002_0000`, `0002_0004`, `0002_0009` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 2 | `0001_0000`, `0002_0000`, `0002_0004`, `0002_0009` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 3 | `0001_0000`, `0002_0000`, `0002_0004`, `0002_0010` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)` |
| 4 | `0001_0000`, `0002_0000`, `0002_0005`, `0002_0011` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)` |
| 5 | `0001_0000`, `0002_0000`, `0002_0005`, `0002_0009` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 6 | `0001_0000`, `0002_0000`, `0002_0006`, `0002_0010` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f006.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)` |
| 7 | `0001_0000`, `0002_0000`, `0002_0006`, `0002_0011` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f006.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)` |
| 8 | `0001_0000`, `0002_0000`, `0002_0007`, `0002_0009` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f007.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 9 | `0001_0000`, `0002_0000`, `0002_0007`, `0002_0010` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f007.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)` |
| 10 | `0001_0000`, `0002_0000`, `0002_0008`, `0002_0011` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f008.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)` |
| 11 | `0001_0000`, `0002_0000`, `0002_0008`, `0002_0009` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f008.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 12 | `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 13 | `0001_0001`, `0002_0001` | `build/phase-3/bitmaps/PART18_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f001.png :material-alert-outline: (not found)` |
| 14 | `0001_0002`, `0002_0002` | `build/phase-3/bitmaps/PART18_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f002.png :material-alert-outline: (not found)` |
| 15 | `0003_0000`, `0003_0001`, `0003_0002`, `0001_0005`, `0002_0000`, `0001_0003`, `0001_0004` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f004.png :material-alert-outline: (not found)` |
| 16 | `0003_0000`, `0003_0001`, `0003_0002`, `0001_0005`, `0002_0000`, `0001_0003`, `0001_0004` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f004.png :material-alert-outline: (not found)` |
| 17 | `0003_0000`, `0003_0001`, `0001_0005`, `0001_0004`, `0002_0003`, `0001_0006`, `0001_0003` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f006.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f003.png :material-alert-outline: (not found)` |
| 18 | `0003_0000`, `0001_0005`, `0001_0004`, `0002_0003`, `0001_0007`, `0001_0003` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f007.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f003.png :material-alert-outline: (not found)` |
| 19 | `0001_0005`, `0001_0004`, `0002_0003`, `0001_0008` | `build/phase-3/bitmaps/PART18_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f008.png :material-alert-outline: (not found)` |
| 20 | `0001_0005`, `0001_0004`, `0002_0003`, `0001_0009` | `build/phase-3/bitmaps/PART18_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f009.png :material-alert-outline: (not found)` |
| 21 | `0001_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 22 | `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 23 | `0004_0000`, `0002_0000`, `0002_0004` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)` |
| 24 | `0004_0000`, `0002_0000`, `0002_0004`, `0002_0009` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 25 | `0004_0000`, `0002_0000`, `0002_0004`, `0002_0009` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 26 | `0004_0000`, `0002_0000`, `0002_0004`, `0002_0010` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)` |
| 27 | `0004_0000`, `0002_0000`, `0002_0005`, `0002_0011` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)` |
| 28 | `0004_0000`, `0002_0000`, `0002_0005`, `0002_0009` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 29 | `0004_0000`, `0002_0000`, `0002_0006`, `0002_0010` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f006.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)` |
| 30 | `0004_0000`, `0002_0000`, `0002_0006`, `0002_0011` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f006.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)` |
| 31 | `0004_0000`, `0002_0000`, `0002_0007`, `0002_0009` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f007.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 32 | `0004_0000`, `0002_0000`, `0002_0007`, `0002_0010` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f007.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)` |
| 33 | `0004_0000`, `0002_0000`, `0002_0008`, `0002_0011` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f008.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)` |
| 34 | `0004_0000`, `0002_0000`, `0002_0008`, `0002_0009` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f008.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 35 | `0004_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 36 | `0004_0001`, `0004_0011` | `build/phase-3/bitmaps/PART18_4_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f011.png :material-alert-outline: (not found)` |
| 37 | `0004_0002`, `0004_0012` | `build/phase-3/bitmaps/PART18_4_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f012.png :material-alert-outline: (not found)` |
| 38 | `0003_0000`, `0003_0001`, `0003_0002`, `0004_0005`, `0002_0001`, `0004_0003`, `0004_0004` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f004.png :material-alert-outline: (not found)` |
| 39 | `0003_0000`, `0003_0001`, `0003_0002`, `0004_0005`, `0002_0001`, `0004_0003`, `0004_0004` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f004.png :material-alert-outline: (not found)` |
| 40 | `0003_0000`, `0003_0001`, `0004_0005`, `0002_0003`, `0004_0003`, `0004_0004`, `0004_0006` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f006.png :material-alert-outline: (not found)` |
| 41 | `0003_0000`, `0004_0005`, `0002_0003`, `0004_0007`, `0004_0003`, `0004_0004` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f007.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f004.png :material-alert-outline: (not found)` |
| 42 | `0004_0005`, `0002_0003`, `0004_0003`, `0004_0008` | `build/phase-3/bitmaps/PART18_4_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f008.png :material-alert-outline: (not found)` |
| 43 | `0004_0005`, `0002_0003`, `0004_0003`, `0004_0009` | `build/phase-3/bitmaps/PART18_4_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f009.png :material-alert-outline: (not found)` |
| 44 | `0004_0010`, `0002_0003` | `build/phase-3/bitmaps/PART18_4_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)` |
| 45 | `0004_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 46 | `0005_0000`, `0002_0000`, `0005_0013` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f013.png :material-alert-outline: (not found)` |
| 47 | `0005_0000`, `0002_0000`, `0005_0013`, `0002_0009` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f013.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 48 | `0005_0000`, `0002_0000`, `0005_0013`, `0002_0009` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f013.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 49 | `0005_0000`, `0002_0000`, `0005_0013`, `0002_0010` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f013.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)` |
| 50 | `0005_0000`, `0002_0000`, `0005_0014`, `0002_0011` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f014.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)` |
| 51 | `0005_0000`, `0002_0000`, `0005_0014`, `0002_0009` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f014.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 52 | `0005_0000`, `0002_0000`, `0005_0015`, `0002_0010` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f015.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)` |
| 53 | `0005_0000`, `0002_0000`, `0005_0015`, `0002_0011` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f015.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)` |
| 54 | `0005_0000`, `0002_0000`, `0005_0016`, `0002_0009` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f016.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 55 | `0005_0000`, `0002_0000`, `0005_0016`, `0002_0011` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f016.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)` |
| 56 | `0005_0000`, `0002_0000`, `0005_0017`, `0002_0009` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f017.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 57 | `0005_0000`, `0002_0000`, `0005_0017`, `0002_0010` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f017.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)` |
| 58 | `0005_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 59 | `0005_0001`, `0002_0001` | `build/phase-3/bitmaps/PART18_5_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f001.png :material-alert-outline: (not found)` |
| 60 | `0005_0002`, `0002_0002` | `build/phase-3/bitmaps/PART18_5_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f002.png :material-alert-outline: (not found)` |
| 61 | `0003_0000`, `0003_0001`, `0003_0002`, `0005_0005`, `0005_0003`, `0002_0000`, `0005_0004` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f004.png :material-alert-outline: (not found)` |
| 62 | `0003_0000`, `0003_0001`, `0003_0002`, `0005_0005`, `0005_0003`, `0002_0000`, `0005_0004` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f004.png :material-alert-outline: (not found)` |
| 63 | `0003_0000`, `0003_0001`, `0005_0005`, `0005_0003`, `0005_0011`, `0005_0004`, `0005_0006` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f006.png :material-alert-outline: (not found)` |
| 64 | `0003_0000`, `0005_0005`, `0005_0003`, `0005_0011`, `0005_0004`, `0005_0007` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f007.png :material-alert-outline: (not found)` |
| 65 | `0005_0005`, `0005_0003`, `0005_0011`, `0005_0008` | `build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f008.png :material-alert-outline: (not found)` |
| 66 | `0005_0005`, `0005_0003`, `0005_0011`, `0005_0009` | `build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f009.png :material-alert-outline: (not found)` |
| 67 | `0005_0005`, `0005_0003`, `0005_0011`, `0005_0004` | `build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f004.png :material-alert-outline: (not found)` |
| 68 | `0005_0010`, `0005_0012` | `build/phase-3/bitmaps/PART18_5_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f012.png :material-alert-outline: (not found)` |
| 69 | `0005_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 70 | `0002_0004`, `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 71 | `0002_0004`, `0001_0000`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 72 | `0002_0004`, `0001_0000`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 73 | `0002_0004`, `0001_0000`, `0002_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 74 | `0002_0005`, `0001_0000`, `0002_0000`, `0002_0011` | `build/phase-3/bitmaps/PART18_2_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)` |
| 75 | `0002_0005`, `0001_0000`, `0002_0000`, `0002_0009` | `build/phase-3/bitmaps/PART18_2_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)` |
| 76 | `0002_0006`, `0001_0000`, `0002_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f006.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 77 | `0002_0006`, `0001_0000`, `0002_0011`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f006.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 78 | `0002_0007`, `0001_0000`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f007.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 79 | `0002_0007`, `0001_0000`, `0002_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f007.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 80 | `0002_0008`, `0001_0000`, `0002_0011`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f008.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 81 | `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 82 | `0001_0001`, `0002_0001` | `build/phase-3/bitmaps/PART18_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f001.png :material-alert-outline: (not found)` |
| 83 | `0001_0002`, `0002_0002` | `build/phase-3/bitmaps/PART18_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f002.png :material-alert-outline: (not found)` |
| 84 | `0003_0000`, `0003_0001`, `0003_0002`, `0001_0004`, `0001_0005`, `0002_0000`, `0001_0003` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f003.png :material-alert-outline: (not found)` |
| 85 | `0003_0000`, `0003_0001`, `0003_0002`, `0001_0004`, `0001_0005`, `0002_0000`, `0001_0003` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f003.png :material-alert-outline: (not found)` |
| 86 | `0003_0000`, `0003_0001`, `0001_0005`, `0001_0004`, `0002_0003`, `0001_0003`, `0001_0006` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f006.png :material-alert-outline: (not found)` |
| 87 | `0003_0000`, `0001_0005`, `0001_0004`, `0002_0003`, `0001_0003`, `0001_0007` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f007.png :material-alert-outline: (not found)` |
| 88 | `0001_0005`, `0001_0004`, `0002_0003`, `0001_0008` | `build/phase-3/bitmaps/PART18_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f008.png :material-alert-outline: (not found)` |
| 89 | `0001_0005`, `0001_0004`, `0002_0003`, `0001_0009` | `build/phase-3/bitmaps/PART18_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_f009.png :material-alert-outline: (not found)` |
| 90 | `0001_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 91 | `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 92 | `0002_0004`, `0004_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 93 | `0002_0004`, `0004_0000`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 94 | `0002_0004`, `0004_0000`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 95 | `0002_0004`, `0004_0000`, `0002_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 96 | `0002_0005`, `0004_0000`, `0002_0011`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 97 | `0002_0005`, `0004_0000`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 98 | `0002_0006`, `0004_0000`, `0002_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f006.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 99 | `0002_0006`, `0004_0000`, `0002_0011`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f006.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 100 | `0002_0007`, `0004_0000`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f007.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 101 | `0002_0007`, `0004_0000`, `0002_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f007.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 102 | `0002_0008`, `0004_0000`, `0002_0011`, `0002_0000` | `build/phase-3/bitmaps/PART18_2_f008.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 103 | `0004_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 104 | `0004_0001`, `0004_0011` | `build/phase-3/bitmaps/PART18_4_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f011.png :material-alert-outline: (not found)` |
| 105 | `0004_0002`, `0004_0012` | `build/phase-3/bitmaps/PART18_4_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f012.png :material-alert-outline: (not found)` |
| 106 | `0003_0000`, `0003_0001`, `0003_0002`, `0004_0005`, `0004_0004`, `0004_0003`, `0002_0000` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 107 | `0003_0000`, `0003_0001`, `0003_0002`, `0004_0005`, `0004_0004`, `0004_0003`, `0002_0000` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 108 | `0003_0000`, `0003_0001`, `0004_0005`, `0002_0003`, `0004_0004`, `0004_0003`, `0004_0006` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f006.png :material-alert-outline: (not found)` |
| 109 | `0003_0000`, `0004_0005`, `0002_0003`, `0004_0004`, `0004_0003`, `0004_0007` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f007.png :material-alert-outline: (not found)` |
| 110 | `0004_0005`, `0002_0003`, `0004_0003`, `0004_0008` | `build/phase-3/bitmaps/PART18_4_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f008.png :material-alert-outline: (not found)` |
| 111 | `0004_0005`, `0002_0003`, `0004_0003`, `0004_0009` | `build/phase-3/bitmaps/PART18_4_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_4_f009.png :material-alert-outline: (not found)` |
| 112 | `0004_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_4_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 113 | `0004_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_4_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 114 | `0005_0013`, `0005_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f013.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 115 | `0005_0013`, `0005_0000`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f013.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 116 | `0005_0013`, `0005_0000`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f013.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 117 | `0005_0013`, `0005_0000`, `0002_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f013.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 118 | `0005_0014`, `0005_0000`, `0002_0011`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f014.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 119 | `0005_0014`, `0005_0000`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f014.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 120 | `0005_0015`, `0005_0000`, `0002_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f015.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 121 | `0005_0015`, `0005_0000`, `0002_0011`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f015.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 122 | `0005_0016`, `0005_0000`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f016.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f009.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 123 | `0005_0016`, `0005_0000`, `0002_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f016.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 124 | `0005_0017`, `0005_0000`, `0002_0011`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f017.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 125 | `0005_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 126 | `0005_0001`, `0002_0001` | `build/phase-3/bitmaps/PART18_5_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f001.png :material-alert-outline: (not found)` |
| 127 | `0005_0002`, `0002_0002` | `build/phase-3/bitmaps/PART18_5_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f002.png :material-alert-outline: (not found)` |
| 128 | `0003_0000`, `0003_0001`, `0003_0002`, `0005_0003`, `0005_0005`, `0005_0012`, `0005_0004` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f012.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f004.png :material-alert-outline: (not found)` |
| 129 | `0003_0000`, `0003_0001`, `0003_0002`, `0005_0003`, `0005_0005`, `0005_0012`, `0005_0004` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f002.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f012.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f004.png :material-alert-outline: (not found)` |
| 130 | `0003_0000`, `0003_0001`, `0005_0003`, `0005_0005`, `0005_0011`, `0005_0004`, `0005_0006` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_3_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f006.png :material-alert-outline: (not found)` |
| 131 | `0003_0000`, `0005_0003`, `0005_0005`, `0005_0011`, `0005_0004`, `0005_0007` | `build/phase-3/bitmaps/PART18_3_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f004.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f007.png :material-alert-outline: (not found)` |
| 132 | `0005_0003`, `0005_0005`, `0005_0011`, `0005_0008` | `build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f008.png :material-alert-outline: (not found)` |
| 133 | `0005_0003`, `0005_0005`, `0005_0011`, `0005_0009` | `build/phase-3/bitmaps/PART18_5_f003.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f005.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f011.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_5_f009.png :material-alert-outline: (not found)` |
| 134 | `0005_0010`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f010.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |
| 135 | `0005_0000`, `0002_0000` | `build/phase-3/bitmaps/PART18_5_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART18_2_f000.png :material-alert-outline: (not found)` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 15 | `3018` | 0 | `build/phase-6/raw-wav/SX_3018_11025.wav` |
| 24 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 38 | `3018` | 0 | `build/phase-6/raw-wav/SX_3018_11025.wav` |
| 47 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 61 | `3018` | 0 | `build/phase-6/raw-wav/SX_3018_11025.wav` |
| 71 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 84 | `3018` | 0 | `build/phase-6/raw-wav/SX_3018_11025.wav` |
| 93 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 106 | `3018` | 0 | `build/phase-6/raw-wav/SX_3018_11025.wav` |
| 115 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 128 | `3018` | 0 | `build/phase-6/raw-wav/SX_3018_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 544 |
| `END_FRAME` | 136 |
| `PLAY_SFX` | 12 |
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

**Cannon** has 2 semantic states: Not Fired, Fired. Transitions are triggered by: collision, proximity, timer.

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
| ANM JSON | `build/phase-4/anm/PART18.json` |
| Sprite PNGs | `godot/assets/sprites/PART18_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV5.yaml` |
| Level YAML | `godot/assets/levels/HH33.yaml` |
| Level YAML | `godot/assets/levels/HH38.yaml` |
| Level YAML | `godot/assets/levels/HH49.yaml` |
| Level YAML | `godot/assets/levels/HH6.yaml` |
| ... | +16 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART18.json` + `build/phase-5/yaml/`*
