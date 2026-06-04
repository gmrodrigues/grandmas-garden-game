# Part 58 — Mel's House

## Identity

| Field | Value |
|-------|-------|
| Part Type | `58` |
| Category | Special Mechanics |
| Description | Here's Mel Schlemming's cozy suburban duplex. If he sees it, he'll head home. It can also be programmed to be a rustic log cabin. |
| ANM File | `PART58.ANM` → `build/phase-4/anm/PART58.json` |
| BMP Resource | `PART58.BMP` → `build/phase-3/bitmaps/PART58_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**18 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV7.yaml` → `godot/assets/levels/ELEV7.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HLEV17.yaml` → `godot/assets/levels/HLEV17.yaml`
- `build/phase-5/yaml/HLEV19.yaml` → `godot/assets/levels/HLEV19.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/MLEV1.yaml` → `godot/assets/levels/MLEV1.yaml`
- `build/phase-5/yaml/MLEV18.yaml` → `godot/assets/levels/MLEV18.yaml`
- `build/phase-5/yaml/MLEV19.yaml` → `godot/assets/levels/MLEV19.yaml`
- `build/phase-5/yaml/MLEV23.yaml` → `godot/assets/levels/MLEV23.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/RLEV11.yaml` → `godot/assets/levels/RLEV11.yaml`
- `build/phase-5/yaml/RLEV12.yaml` → `godot/assets/levels/RLEV12.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/RLEV29.yaml` → `godot/assets/levels/RLEV29.yaml`
- `build/phase-5/yaml/RLEV3.yaml` → `godot/assets/levels/RLEV3.yaml`
- `build/phase-5/yaml/TLEV38.yaml` → `godot/assets/levels/TLEV38.yaml`

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
| `bitmap_w` | 48 | bitmap frame width |
| `bitmap_h` | 64 | bitmap frame height |

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
| Vacant | `5→6`, `4→15` | 4 | No |
| Occupied | `6→4`, `15→-1` | 15 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 86 |
| Total States | 8 |
| Animated (Section A) | Yes |
| Section A Durations | 141 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `5` | 0 | 0 | 48×64 | 0 |
| `6` | 1 | 1–69 (69 frames) | 48×64 | 13 |
| `9` | 70 | 70–107 (38 frames) | 72×97 | 2298 |
| `8` | 108 | 108–110 (3 frames) | 0×0 | 0 |
| `4` | 111 | 111 | 0×0 | 0 |
| `15` | 112 | 112–121 (10 frames) | 0×0 | 0 |
| `13` | 122 | 122–130 (9 frames) | 0×0 | 0 |
| `14` | 131 | 131 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0008`, `0001_0009` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:` |
| 1 | `0001_0008` | `build/phase-3/bitmaps/PART58_f008.png :material-check:` |
| 2 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:` |
| 3 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:` |
| 4 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 5 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0012`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 6 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0012`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 7 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0012`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 8 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0012`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 9 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0013`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 10 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0013`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 11 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0013`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 12 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 13 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 14 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 15 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 16 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 17 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 18 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 19 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 20 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 21 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 22 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 23 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 24 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 25 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0014`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 26 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0013`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 27 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0013`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 28 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0013`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 29 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0012`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 30 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0012`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 31 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0012`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 32 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0012`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 33 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 34 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 35 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 36 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 37 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 38 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 39 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 40 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0019`, `0001_0015` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f015.png :material-check:` |
| 41 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0020`, `0001_0015` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f015.png :material-check:` |
| 42 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0021`, `0001_0015` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f015.png :material-check:` |
| 43 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0019`, `0001_0015` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f015.png :material-check:` |
| 44 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0020`, `0001_0015` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f015.png :material-check:` |
| 45 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0021`, `0001_0015` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f015.png :material-check:` |
| 46 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0016`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 47 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0016`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 48 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0016`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 49 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0017`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 50 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0017`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 51 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0017`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 52 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 53 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 54 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 55 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 56 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 57 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 58 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 59 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 60 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 61 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 62 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 63 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 64 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 65 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0018`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 66 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0017`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 67 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0017`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 68 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0017`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 69 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0016`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 70 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0016`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 71 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0015`, `0001_0019` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f019.png :material-check:` |
| 72 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0015`, `0001_0020` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f020.png :material-check:` |
| 73 | `0001_0008`, `0001_0009`, `0001_0010`, `0001_0011`, `0001_0015`, `0001_0021` | `build/phase-3/bitmaps/PART58_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f021.png :material-check:` |
| 74 | `0001_0000` | `build/phase-3/bitmaps/PART58_f000.png :material-check:` |
| 75 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART58_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f001.png :material-check:` |
| 76 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART58_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f002.png :material-check:` |
| 77 | `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART58_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f003.png :material-check:` |
| 78 | `0001_0000` | `build/phase-3/bitmaps/PART58_f000.png :material-check:` |
| 79 | `0001_0000`, `0001_0004`, `0001_0004`, `0001_0005` | `build/phase-3/bitmaps/PART58_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f005.png :material-check:` |
| 80 | `0001_0000`, `0001_0004`, `0001_0004`, `0001_0006` | `build/phase-3/bitmaps/PART58_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f006.png :material-check:` |
| 81 | `0001_0000`, `0001_0004`, `0001_0004`, `0001_0007` | `build/phase-3/bitmaps/PART58_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f007.png :material-check:` |
| 82 | `0001_0000`, `0001_0004`, `0001_0004`, `0001_0005`, `0001_0001` | `build/phase-3/bitmaps/PART58_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f001.png :material-check:` |
| 83 | `0001_0000`, `0001_0004`, `0001_0004`, `0001_0006`, `0001_0002` | `build/phase-3/bitmaps/PART58_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f002.png :material-check:` |
| 84 | `0001_0000`, `0001_0004`, `0001_0004`, `0001_0007`, `0001_0003` | `build/phase-3/bitmaps/PART58_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f003.png :material-check:` |
| 85 | `0001_0000`, `0001_0004`, `0001_0004`, `0001_0007` | `build/phase-3/bitmaps/PART58_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART58_f007.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 2 | `3058` | 0 | `build/phase-6/raw-wav/SX_3058_11025.wav` |
| 78 | `3058` | 0 | `build/phase-6/raw-wav/SX_3058_11025.wav` |
| 85 | `3058` | 0 | `build/phase-6/raw-wav/SX_3058_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 434 |
| `END_FRAME` | 86 |
| `PLAY_SFX` | 3 |
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

**Mel's House** has 2 semantic states: Vacant, Occupied. Transitions are triggered by: collision, electrical, proximity.

Terminal state(s): Occupied (part is removed from simulation).

This part has custom spawn behavior defined in SOLVE.RES.

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART58.json` |
| Sprite PNGs | `godot/assets/sprites/PART58_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV7.yaml` |
| Level YAML | `godot/assets/levels/HH43.yaml` |
| Level YAML | `godot/assets/levels/HLEV17.yaml` |
| ... | +13 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART58.json` + `build/phase-5/yaml/`*
