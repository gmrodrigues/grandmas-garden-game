# Part 95 — Laser Mixer

## Identity

| Field | Value |
|-------|-------|
| Part Type | `95` |
| Category | Lasers / Optics |
| Description | This Laser Mixer will blend together the colors of any laser beams passing through it. For instance, a red beam and a blue beam will become violet. The violet beam could then be used to provide energy to a violet Laser-Activated Plug. |
| ANM File | `PART95.ANM` → `build/phase-4/anm/PART95.json` |
| BMP Resource | `PART95.BMP` → `build/phase-3/bitmaps/PART95_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**13 level(s)** use this part type:

- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV8.yaml` → `godot/assets/levels/HLEV8.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/RLEV13.yaml` → `godot/assets/levels/RLEV13.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV3.yaml` → `godot/assets/levels/RLEV3.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`
- `build/phase-5/yaml/TLEV28.yaml` → `godot/assets/levels/TLEV28.yaml`
- `build/phase-5/yaml/TLEV29.yaml` → `godot/assets/levels/TLEV29.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1000 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 24 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 40 | bitmap frame width |
| `bitmap_h` | 40 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `electrical`, `proximity`, `collision` |
| Destructible | No |
| Spawns | `laser_beam` |
| Category Part Count | 8 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 115 |
| Total States | 32 |
| Animated (Section A) | Yes |
| Section A Durations | 343 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 40×40 | 0 |
| `2` | 1 | 1–12 (12 frames) | 40×40 | 7 |
| `3` | 13 | 13–24 (12 frames) | 40×40 | 235 |
| `4` | 25 | 25–36 (12 frames) | 40×40 | 463 |
| `5` | 37 | 37–48 (12 frames) | 40×40 | 679 |
| `6` | 49 | 49–60 (12 frames) | 40×40 | 907 |
| `7` | 61 | 61–72 (12 frames) | 40×40 | 1123 |
| `8` | 73 | 73–84 (12 frames) | 40×40 | 1351 |
| `16` | 85 | 85–87 (3 frames) | 40×40 | 1579 |
| `17` | 88 | 88–99 (12 frames) | 40×40 | 1618 |
| `19` | 100 | 100–108 (9 frames) | 40×40 | 1846 |
| `20` | 109 | 109–120 (12 frames) | 40×40 | 2017 |
| `21` | 121 | 121–132 (12 frames) | 0×0 | 0 |
| `22` | 133 | 133–144 (12 frames) | 0×0 | 0 |
| `23` | 145 | 145–156 (12 frames) | 0×0 | 0 |
| `24` | 157 | 157–168 (12 frames) | 0×0 | 0 |
| `25` | 169 | 169–171 (3 frames) | 0×0 | 0 |
| `26` | 172 | 172–183 (12 frames) | 0×0 | 0 |
| `27` | 184 | 184–195 (12 frames) | 0×0 | 0 |
| `28` | 196 | 196–207 (12 frames) | 0×0 | 0 |
| `29` | 208 | 208–219 (12 frames) | 0×0 | 0 |
| `30` | 220 | 220–231 (12 frames) | 0×0 | 0 |
| `31` | 232 | 232–243 (12 frames) | 0×0 | 0 |
| `32` | 244 | 244–255 (12 frames) | 0×0 | 0 |
| `33` | 256 | 256–258 (3 frames) | 0×0 | 0 |
| `9` | 259 | 259–270 (12 frames) | 0×0 | 0 |
| `10` | 271 | 271–282 (12 frames) | 0×0 | 0 |
| `11` | 283 | 283–294 (12 frames) | 0×0 | 0 |
| `12` | 295 | 295–306 (12 frames) | 0×0 | 0 |
| `13` | 307 | 307–318 (12 frames) | 0×0 | 0 |
| `14` | 319 | 319–330 (12 frames) | 0×0 | 0 |
| `15` | 331 | 331 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART95_f000.png :material-check:` |
| 1 | `0001_0000`, `0001_0001`, `0001_0022` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f022.png :material-check:` |
| 2 | `0001_0000`, `0001_0002`, `0001_0022` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f022.png :material-check:` |
| 3 | `0001_0000`, `0001_0003`, `0001_0022` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f022.png :material-check:` |
| 4 | `0001_0000`, `0001_0002`, `0001_0022` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f022.png :material-check:` |
| 5 | `0001_0000`, `0001_0004`, `0001_0024` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f024.png :material-check:` |
| 6 | `0001_0000`, `0001_0005`, `0001_0024` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f024.png :material-check:` |
| 7 | `0001_0000`, `0001_0006`, `0001_0024` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f024.png :material-check:` |
| 8 | `0001_0000`, `0001_0005`, `0001_0024` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f024.png :material-check:` |
| 9 | `0001_0000`, `0001_0026`, `0001_0007` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f026.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f007.png :material-check:` |
| 10 | `0001_0000`, `0001_0026`, `0001_0008` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f026.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f008.png :material-check:` |
| 11 | `0001_0000`, `0001_0026`, `0001_0009` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f026.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f009.png :material-check:` |
| 12 | `0001_0000`, `0001_0026`, `0001_0008` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f026.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f008.png :material-check:` |
| 13 | `0001_0000`, `0001_0025`, `0001_0010` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f025.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f010.png :material-check:` |
| 14 | `0001_0000`, `0001_0011`, `0001_0025` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f025.png :material-check:` |
| 15 | `0001_0000`, `0001_0025`, `0001_0012` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f025.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f012.png :material-check:` |
| 16 | `0001_0000`, `0001_0011`, `0001_0025` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f025.png :material-check:` |
| 17 | `0001_0000`, `0001_0027`, `0001_0013` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f027.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f013.png :material-check:` |
| 18 | `0001_0000`, `0001_0027`, `0001_0014` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f027.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f014.png :material-check:` |
| 19 | `0001_0000`, `0001_0027`, `0001_0015` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f027.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f015.png :material-check:` |
| 20 | `0001_0000`, `0001_0027`, `0001_0014` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f027.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f014.png :material-check:` |
| 21 | `0001_0000`, `0001_0016`, `0001_0023` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f023.png :material-check:` |
| 22 | `0001_0000`, `0001_0017`, `0001_0023` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f023.png :material-check:` |
| 23 | `0001_0000`, `0001_0018`, `0001_0023` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f023.png :material-check:` |
| 24 | `0001_0000`, `0001_0017`, `0001_0023` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f023.png :material-check:` |
| 25 | `0001_0000`, `0001_0028`, `0001_0019` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f028.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f019.png :material-check:` |
| 26 | `0001_0000`, `0001_0028`, `0001_0020` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f028.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f020.png :material-check:` |
| 27 | `0001_0000`, `0001_0028`, `0001_0021` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f028.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f021.png :material-check:` |
| 28 | `0001_0000`, `0001_0028`, `0001_0020` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f028.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f020.png :material-check:` |
| 29 | `0001_0029` | `build/phase-3/bitmaps/PART95_f029.png :material-check:` |
| 30 | `0001_0029`, `0001_0031`, `0001_0051` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f031.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f051.png :material-check:` |
| 31 | `0001_0029`, `0001_0030`, `0001_0051` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f030.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f051.png :material-check:` |
| 32 | `0001_0029`, `0001_0031`, `0001_0051` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f031.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f051.png :material-check:` |
| 33 | `0001_0029`, `0001_0051`, `0001_0032` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f051.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f032.png :material-check:` |
| 34 | `0001_0029`, `0001_0034`, `0001_0052` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f034.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f052.png :material-check:` |
| 35 | `0001_0029`, `0001_0033`, `0001_0052` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f033.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f052.png :material-check:` |
| 36 | `0001_0029`, `0001_0035`, `0001_0052` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f035.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f052.png :material-check:` |
| 37 | `0001_0029`, `0001_0053`, `0001_0037` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f053.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f037.png :material-check:` |
| 38 | `0001_0029`, `0001_0053`, `0001_0036` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f053.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f036.png :material-check:` |
| 39 | `0001_0029`, `0001_0053`, `0001_0037` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f053.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f037.png :material-check:` |
| 40 | `0001_0029`, `0001_0053`, `0001_0038` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f053.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f038.png :material-check:` |
| 41 | `0001_0029`, `0001_0054`, `0001_0040` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f054.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f040.png :material-check:` |
| 42 | `0001_0029`, `0001_0054`, `0001_0039` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f054.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f039.png :material-check:` |
| 43 | `0001_0029`, `0001_0054`, `0001_0040` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f054.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f040.png :material-check:` |
| 44 | `0001_0029`, `0001_0054`, `0001_0041` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f054.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f041.png :material-check:` |
| 45 | `0001_0029`, `0001_0055`, `0001_0043` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f055.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f043.png :material-check:` |
| 46 | `0001_0029`, `0001_0055`, `0001_0042` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f055.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f042.png :material-check:` |
| 47 | `0001_0029`, `0001_0055`, `0001_0043` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f055.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f043.png :material-check:` |
| 48 | `0001_0029`, `0001_0055`, `0001_0044` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f055.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f044.png :material-check:` |
| 49 | `0001_0029`, `0001_0056`, `0001_0046` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f056.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f046.png :material-check:` |
| 50 | `0001_0029`, `0001_0056`, `0001_0045` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f056.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f045.png :material-check:` |
| 51 | `0001_0029`, `0001_0056`, `0001_0046` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f056.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f046.png :material-check:` |
| 52 | `0001_0029`, `0001_0056`, `0001_0047` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f056.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f047.png :material-check:` |
| 53 | `0001_0029`, `0001_0057`, `0001_0049` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f057.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f049.png :material-check:` |
| 54 | `0001_0029`, `0001_0057`, `0001_0048` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f057.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f048.png :material-check:` |
| 55 | `0001_0029`, `0001_0057`, `0001_0049` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f057.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f049.png :material-check:` |
| 56 | `0001_0029`, `0001_0057`, `0001_0050` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f057.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f050.png :material-check:` |
| 57 | `0001_0000` | `build/phase-3/bitmaps/PART95_f000.png :material-check:` |
| 58 | `0001_0000`, `0001_0022`, `0001_0002` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f022.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f002.png :material-check:` |
| 59 | `0001_0000`, `0001_0022`, `0001_0003` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f022.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f003.png :material-check:` |
| 60 | `0001_0000`, `0001_0022`, `0001_0002` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f022.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f002.png :material-check:` |
| 61 | `0001_0000`, `0001_0022`, `0001_0001` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f022.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f001.png :material-check:` |
| 62 | `0001_0000`, `0001_0024`, `0001_0005` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f024.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f005.png :material-check:` |
| 63 | `0001_0000`, `0001_0024`, `0001_0006` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f024.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f006.png :material-check:` |
| 64 | `0001_0000`, `0001_0024`, `0001_0005` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f024.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f005.png :material-check:` |
| 65 | `0001_0000`, `0001_0024`, `0001_0004` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f024.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f004.png :material-check:` |
| 66 | `0001_0000`, `0001_0026`, `0001_0008` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f026.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f008.png :material-check:` |
| 67 | `0001_0000`, `0001_0026`, `0001_0009` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f026.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f009.png :material-check:` |
| 68 | `0001_0000`, `0001_0026`, `0001_0008` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f026.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f008.png :material-check:` |
| 69 | `0001_0000`, `0001_0026`, `0001_0007` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f026.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f007.png :material-check:` |
| 70 | `0001_0000`, `0001_0025`, `0001_0011` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f025.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f011.png :material-check:` |
| 71 | `0001_0000`, `0001_0025`, `0001_0012` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f025.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f012.png :material-check:` |
| 72 | `0001_0000`, `0001_0025`, `0001_0011` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f025.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f011.png :material-check:` |
| 73 | `0001_0000`, `0001_0025`, `0001_0010` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f025.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f010.png :material-check:` |
| 74 | `0001_0000`, `0001_0027`, `0001_0014` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f027.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f014.png :material-check:` |
| 75 | `0001_0000`, `0001_0027`, `0001_0015` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f027.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f015.png :material-check:` |
| 76 | `0001_0000`, `0001_0027`, `0001_0014` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f027.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f014.png :material-check:` |
| 77 | `0001_0000`, `0001_0027`, `0001_0013` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f027.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f013.png :material-check:` |
| 78 | `0001_0000`, `0001_0023`, `0001_0017` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f023.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f017.png :material-check:` |
| 79 | `0001_0000`, `0001_0023`, `0001_0018` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f023.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f018.png :material-check:` |
| 80 | `0001_0000`, `0001_0023`, `0001_0017` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f023.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f017.png :material-check:` |
| 81 | `0001_0000`, `0001_0023`, `0001_0016` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f023.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f016.png :material-check:` |
| 82 | `0001_0000`, `0001_0028`, `0001_0020` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f028.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f020.png :material-check:` |
| 83 | `0001_0000`, `0001_0028`, `0001_0021` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f028.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f021.png :material-check:` |
| 84 | `0001_0000`, `0001_0028`, `0001_0020` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f028.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f020.png :material-check:` |
| 85 | `0001_0000`, `0001_0028`, `0001_0019` | `build/phase-3/bitmaps/PART95_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f028.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f019.png :material-check:` |
| 86 | `0001_0029` | `build/phase-3/bitmaps/PART95_f029.png :material-check:` |
| 87 | `0001_0029`, `0001_0051` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f051.png :material-check:` |
| 88 | `0001_0029`, `0001_0051`, `0001_0031` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f051.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f031.png :material-check:` |
| 89 | `0001_0029`, `0001_0051`, `0001_0030` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f051.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f030.png :material-check:` |
| 90 | `0001_0029`, `0001_0051`, `0001_0031` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f051.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f031.png :material-check:` |
| 91 | `0001_0029`, `0001_0052`, `0001_0035` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f052.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f035.png :material-check:` |
| 92 | `0001_0029`, `0001_0052`, `0001_0034` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f052.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f034.png :material-check:` |
| 93 | `0001_0029`, `0001_0052`, `0001_0033` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f052.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f033.png :material-check:` |
| 94 | `0001_0029`, `0001_0052`, `0001_0034` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f052.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f034.png :material-check:` |
| 95 | `0001_0029`, `0001_0053`, `0001_0038` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f053.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f038.png :material-check:` |
| 96 | `0001_0029`, `0001_0053`, `0001_0037` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f053.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f037.png :material-check:` |
| 97 | `0001_0029`, `0001_0053`, `0001_0036` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f053.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f036.png :material-check:` |
| 98 | `0001_0029`, `0001_0053`, `0001_0037` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f053.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f037.png :material-check:` |
| 99 | `0001_0029`, `0001_0054`, `0001_0041` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f054.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f041.png :material-check:` |
| 100 | `0001_0029`, `0001_0054`, `0001_0040` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f054.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f040.png :material-check:` |
| 101 | `0001_0029`, `0001_0054`, `0001_0039` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f054.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f039.png :material-check:` |
| 102 | `0001_0029`, `0001_0054`, `0001_0040` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f054.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f040.png :material-check:` |
| 103 | `0001_0029`, `0001_0055`, `0001_0044` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f055.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f044.png :material-check:` |
| 104 | `0001_0029`, `0001_0055`, `0001_0043` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f055.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f043.png :material-check:` |
| 105 | `0001_0029`, `0001_0055`, `0001_0042` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f055.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f042.png :material-check:` |
| 106 | `0001_0029`, `0001_0055`, `0001_0043` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f055.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f043.png :material-check:` |
| 107 | `0001_0029`, `0001_0056`, `0001_0047` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f056.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f047.png :material-check:` |
| 108 | `0001_0029`, `0001_0056`, `0001_0046` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f056.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f046.png :material-check:` |
| 109 | `0001_0029`, `0001_0056`, `0001_0045` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f056.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f045.png :material-check:` |
| 110 | `0001_0029`, `0001_0056`, `0001_0046` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f056.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f046.png :material-check:` |
| 111 | `0001_0029`, `0001_0057`, `0001_0050` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f057.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f050.png :material-check:` |
| 112 | `0001_0029`, `0001_0057`, `0001_0049` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f057.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f049.png :material-check:` |
| 113 | `0001_0029`, `0001_0057`, `0001_0048` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f057.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f048.png :material-check:` |
| 114 | `0001_0029`, `0001_0057`, `0001_0049` | `build/phase-3/bitmaps/PART95_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f057.png :material-check:`<br>`build/phase-3/bitmaps/PART95_f049.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 336 |
| `END_FRAME` | 115 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | Yes |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | No |
| Laser | Yes |
| Projectile | No |

## Behavior Notes

**Laser Mixer** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part emits a **laser beam**. The beam interacts with mirrors, mixers, and laser-activated plugs.

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART95.json` |
| Sprite PNGs | `godot/assets/sprites/PART95_f*.png` |
| Level YAML | `godot/assets/levels/HLEV20.yaml` |
| Level YAML | `godot/assets/levels/HLEV26.yaml` |
| Level YAML | `godot/assets/levels/HLEV8.yaml` |
| Level YAML | `godot/assets/levels/MLEV26.yaml` |
| Level YAML | `godot/assets/levels/RLEV13.yaml` |
| ... | +8 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART95.json` + `build/phase-5/yaml/`*
