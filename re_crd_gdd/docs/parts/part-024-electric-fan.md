# Part 24 — Electric Fan

## Identity

| Field | Value |
|-------|-------|
| Part Type | `24` |
| Category | Electrical |
| Description | Plug this electric fan into an outlet to make it blow air. Flip it to change wind direction. Use it to blow objects away or to turn the pinwheel. |
| ANM File | `PART24.ANM` → `build/phase-4/anm/PART24.json` |
| BMP Resource | `PART24.BMP` → `build/phase-3/bitmaps/PART24_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**23 level(s)** use this part type:

- `build/phase-5/yaml/HH10.yaml` → `godot/assets/levels/HH10.yaml`
- `build/phase-5/yaml/HH3.yaml` → `godot/assets/levels/HH3.yaml`
- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HH48.yaml` → `godot/assets/levels/HH48.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV16.yaml` → `godot/assets/levels/HLEV16.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV30.yaml` → `godot/assets/levels/HLEV30.yaml`
- `build/phase-5/yaml/MLEV10.yaml` → `godot/assets/levels/MLEV10.yaml`
- `build/phase-5/yaml/MLEV11.yaml` → `godot/assets/levels/MLEV11.yaml`
- `build/phase-5/yaml/MLEV12.yaml` → `godot/assets/levels/MLEV12.yaml`
- `build/phase-5/yaml/MLEV2.yaml` → `godot/assets/levels/MLEV2.yaml`
- `build/phase-5/yaml/RLEV10.yaml` → `godot/assets/levels/RLEV10.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/RLEV29.yaml` → `godot/assets/levels/RLEV29.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`
- `build/phase-5/yaml/TLEV12.yaml` → `godot/assets/levels/TLEV12.yaml`
- `build/phase-5/yaml/TLEV5.yaml` → `godot/assets/levels/TLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 27 | bitmap frame width |
| `bitmap_h` | 46 | bitmap frame height |

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
| Off | `1→2` | — | No |
| On | `2→-1` | 2 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 69 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 32×46 | 0 |
| `2` | 1 | 1–68 (68 frames) | 32×46 | 25 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 1 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 2 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 3 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 4 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 5 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 6 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 7 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 8 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 9 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 10 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 11 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 12 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 13 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 14 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 15 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 16 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 17 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 18 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 19 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 20 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 21 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 22 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 23 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 24 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 25 | `0001_0000`, `0001_0001`, `0001_0006`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 26 | `0001_0000`, `0001_0001`, `0001_0005`, `0001_0013` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f013.png :material-check:` |
| 27 | `0001_0000`, `0001_0002`, `0001_0008`, `0001_0014` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f014.png :material-check:` |
| 28 | `0001_0000`, `0001_0002`, `0001_0007`, `0001_0014` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f014.png :material-check:` |
| 29 | `0001_0000`, `0001_0002`, `0001_0008`, `0001_0014` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f014.png :material-check:` |
| 30 | `0001_0000`, `0001_0002`, `0001_0007`, `0001_0014` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f014.png :material-check:` |
| 31 | `0001_0000`, `0001_0003`, `0001_0009`, `0001_0015` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f015.png :material-check:` |
| 32 | `0001_0000`, `0001_0003`, `0001_0010`, `0001_0015` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f015.png :material-check:` |
| 33 | `0001_0000`, `0001_0003`, `0001_0009`, `0001_0015` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f015.png :material-check:` |
| 34 | `0001_0000`, `0001_0003`, `0001_0010`, `0001_0015` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f015.png :material-check:` |
| 35 | `0001_0011`, `0001_0016`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 36 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 37 | `0001_0011`, `0001_0016`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 38 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 39 | `0001_0011`, `0001_0016`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 40 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 41 | `0001_0011`, `0001_0016`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 42 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 43 | `0001_0011`, `0001_0016`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 44 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 45 | `0001_0011`, `0001_0016`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 46 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 47 | `0001_0011`, `0001_0016`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 48 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 49 | `0001_0011`, `0001_0016`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 50 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 51 | `0001_0011`, `0001_0016`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 52 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 53 | `0001_0011`, `0001_0016`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 54 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 55 | `0001_0011`, `0001_0016`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 56 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 57 | `0001_0011`, `0001_0016`, `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 58 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 59 | `0001_0000`, `0001_0011`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 60 | `0001_0000`, `0001_0012`, `0001_0016`, `0001_0004` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f004.png :material-check:` |
| 61 | `0001_0000`, `0001_0003`, `0001_0009`, `0001_0015` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f015.png :material-check:` |
| 62 | `0001_0000`, `0001_0003`, `0001_0010`, `0001_0015` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f015.png :material-check:` |
| 63 | `0001_0000`, `0001_0003`, `0001_0009`, `0001_0015` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f015.png :material-check:` |
| 64 | `0001_0000`, `0001_0003`, `0001_0010`, `0001_0015` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f015.png :material-check:` |
| 65 | `0001_0000`, `0001_0002`, `0001_0008`, `0001_0014` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f014.png :material-check:` |
| 66 | `0001_0000`, `0001_0002`, `0001_0007`, `0001_0014` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f014.png :material-check:` |
| 67 | `0001_0000`, `0001_0002`, `0001_0008`, `0001_0014` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f014.png :material-check:` |
| 68 | `0001_0000`, `0001_0002`, `0001_0007`, `0001_0014` | `build/phase-3/bitmaps/PART24_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART24_f014.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 2 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 3 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 4 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 5 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 6 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 7 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 8 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 9 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 10 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 11 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 12 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 13 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 14 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 15 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 16 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 17 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 18 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 19 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 20 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 21 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 22 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 23 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 24 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 25 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 26 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 27 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 28 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 29 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 30 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 31 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 32 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 33 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 34 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 35 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 36 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 37 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 38 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 39 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 40 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 41 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 42 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 43 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 44 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 45 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 46 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 47 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 48 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 49 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 50 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 51 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 52 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 53 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 54 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 55 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 56 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 57 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 58 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 59 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 60 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 61 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 62 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 63 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 64 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 65 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 66 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 67 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |
| 68 | `24` | 0 | `build/phase-6/raw-wav/SX_24_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 276 |
| `END_FRAME` | 69 |
| `PLAY_SFX` | 68 |
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

**Electric Fan** has 2 semantic states: Off, On. Transitions are triggered by: electrical, collision.

Terminal state(s): On (part is removed from simulation).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART24.json` |
| Sprite PNGs | `godot/assets/sprites/PART24_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/HH10.yaml` |
| Level YAML | `godot/assets/levels/HH3.yaml` |
| Level YAML | `godot/assets/levels/HH4.yaml` |
| Level YAML | `godot/assets/levels/HH48.yaml` |
| Level YAML | `godot/assets/levels/HLEV10.yaml` |
| ... | +18 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART24.json` + `build/phase-5/yaml/`*
