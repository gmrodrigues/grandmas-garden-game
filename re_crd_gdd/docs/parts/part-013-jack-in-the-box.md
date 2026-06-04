# Part 13 — Jack-in-the-box

## Identity

| Field | Value |
|-------|-------|
| Part Type | `13` |
| Category | Springs / Pneumatics |
| Description | You can hitch this Jack-in-the-box to any rotating part by adding a belt. When the wheel turns, it will pop open. And when Jack pops out, anything on top of his box will be shot into the air. |
| ANM File | `PART13.ANM` → `build/phase-4/anm/PART13.json` |
| BMP Resource | `PART13.BMP` → `build/phase-3/bitmaps/PART13_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**25 level(s)** use this part type:

- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`
- `build/phase-5/yaml/HH20.yaml` → `godot/assets/levels/HH20.yaml`
- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HH48.yaml` → `godot/assets/levels/HH48.yaml`
- `build/phase-5/yaml/HH9.yaml` → `godot/assets/levels/HH9.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV3.yaml` → `godot/assets/levels/HLEV3.yaml`
- `build/phase-5/yaml/MLEV1.yaml` → `godot/assets/levels/MLEV1.yaml`
- `build/phase-5/yaml/MLEV15.yaml` → `godot/assets/levels/MLEV15.yaml`
- `build/phase-5/yaml/MLEV17.yaml` → `godot/assets/levels/MLEV17.yaml`
- `build/phase-5/yaml/MLEV18.yaml` → `godot/assets/levels/MLEV18.yaml`
- `build/phase-5/yaml/MLEV2.yaml` → `godot/assets/levels/MLEV2.yaml`
- `build/phase-5/yaml/RLEV10.yaml` → `godot/assets/levels/RLEV10.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- `build/phase-5/yaml/RLEV20.yaml` → `godot/assets/levels/RLEV20.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/RLEV28.yaml` → `godot/assets/levels/RLEV28.yaml`
- `build/phase-5/yaml/RLEV29.yaml` → `godot/assets/levels/RLEV29.yaml`
- `build/phase-5/yaml/RLEV6.yaml` → `godot/assets/levels/RLEV6.yaml`
- `build/phase-5/yaml/RLEV7.yaml` → `godot/assets/levels/RLEV7.yaml`
- `build/phase-5/yaml/TLEV17.yaml` → `godot/assets/levels/TLEV17.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 3776 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 33 | bitmap frame width |
| `bitmap_h` | 32 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 7 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Closed | `3→4` | — | No |
| Popped Out | `5→-1` | 4 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 30 |
| Total States | 4 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `3` | 0 | 0 | 33×32 | 0 |
| `4` | 1 | 1–11 (11 frames) | 33×32 | 25 |
| `5` | 12 | 12–28 (17 frames) | 33×49 | 300 |
| `13` | 29 | 29 | 61×52 | 865 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0001`, `0001_0000`, `0001_0003`, `0001_0002` | `build/phase-3/bitmaps/PART13_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 1 | `0001_0001`, `0001_0000`, `0001_0003`, `0001_0002` | `build/phase-3/bitmaps/PART13_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 2 | `0001_0001`, `0001_0000`, `0001_0004`, `0001_0002` | `build/phase-3/bitmaps/PART13_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 3 | `0001_0001`, `0001_0000`, `0001_0005`, `0001_0002` | `build/phase-3/bitmaps/PART13_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 4 | `0001_0001`, `0001_0000`, `0001_0004`, `0001_0002` | `build/phase-3/bitmaps/PART13_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 5 | `0001_0001`, `0001_0000`, `0001_0003`, `0001_0002` | `build/phase-3/bitmaps/PART13_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 6 | `0001_0001`, `0001_0000`, `0001_0006`, `0001_0002` | `build/phase-3/bitmaps/PART13_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 7 | `0001_0001`, `0001_0000`, `0001_0003`, `0001_0002` | `build/phase-3/bitmaps/PART13_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 8 | `0001_0001`, `0001_0000`, `0001_0004`, `0001_0002` | `build/phase-3/bitmaps/PART13_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 9 | `0001_0001`, `0001_0000`, `0001_0005`, `0001_0002` | `build/phase-3/bitmaps/PART13_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 10 | `0001_0001`, `0001_0000`, `0001_0003`, `0001_0002` | `build/phase-3/bitmaps/PART13_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 11 | `0001_0001`, `0001_0000`, `0001_0006`, `0001_0002` | `build/phase-3/bitmaps/PART13_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 12 | `0001_0007`, `0001_0000`, `0001_0002`, `0001_0003` | `build/phase-3/bitmaps/PART13_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:` |
| 13 | `0001_0009`, `0001_0015`, `0001_0000`, `0001_0003`, `0001_0002` | `build/phase-3/bitmaps/PART13_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 14 | `0001_0000`, `0001_0003`, `0001_0002`, `0001_0008`, `0001_0015` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f015.png :material-check:` |
| 15 | `0001_0000`, `0001_0003`, `0001_0002`, `0001_0010`, `0001_0016`, `0001_0017` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f017.png :material-check:` |
| 16 | `0001_0000`, `0001_0003`, `0001_0002`, `0001_0011`, `0001_0020`, `0001_0019` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f019.png :material-check:` |
| 17 | `0001_0000`, `0001_0003`, `0001_0002`, `0001_0012`, `0001_0020`, `0001_0021` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f021.png :material-check:` |
| 18 | `0001_0000`, `0001_0003`, `0001_0013`, `0001_0002`, `0001_0022`, `0001_0023` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f022.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f023.png :material-check:` |
| 19 | `0001_0016`, `0001_0000`, `0001_0003`, `0001_0014`, `0001_0023`, `0001_0002` | `build/phase-3/bitmaps/PART13_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f023.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 20 | `0001_0000`, `0001_0003`, `0001_0014`, `0001_0002`, `0001_0024` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f024.png :material-check:` |
| 21 | `0001_0000`, `0001_0003`, `0001_0014`, `0001_0002`, `0001_0025` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f025.png :material-check:` |
| 22 | `0001_0000`, `0001_0003`, `0001_0014`, `0001_0002`, `0001_0016`, `0001_0019` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f019.png :material-check:` |
| 23 | `0001_0000`, `0001_0003`, `0001_0014`, `0001_0002`, `0001_0016`, `0001_0021` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f021.png :material-check:` |
| 24 | `0001_0000`, `0001_0003`, `0001_0014`, `0001_0025`, `0001_0002` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f025.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 25 | `0001_0000`, `0001_0003`, `0001_0014`, `0001_0026`, `0001_0002` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f026.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 26 | `0001_0000`, `0001_0003`, `0001_0014`, `0001_0027`, `0001_0002` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f027.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 27 | `0001_0000`, `0001_0003`, `0001_0014`, `0001_0028`, `0001_0002` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f028.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 28 | `0001_0000`, `0001_0003`, `0001_0014`, `0001_0029`, `0001_0002` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |
| 29 | `0001_0000`, `0001_0003`, `0001_0014`, `0001_0029`, `0001_0002` | `build/phase-3/bitmaps/PART13_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f029.png :material-check:`<br>`build/phase-3/bitmaps/PART13_f002.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 12 | `3013` | 0 | `build/phase-6/raw-wav/SX_3013_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 144 |
| `END_FRAME` | 30 |
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

**Jack-in-the-box** has 2 semantic states: Closed, Popped Out. Transitions are triggered by: collision, electrical.

Terminal state(s): Popped Out (part is removed from simulation).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART13.json` |
| Sprite PNGs | `godot/assets/sprites/PART13_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| Level YAML | `godot/assets/levels/HH20.yaml` |
| Level YAML | `godot/assets/levels/HH4.yaml` |
| Level YAML | `godot/assets/levels/HH41.yaml` |
| Level YAML | `godot/assets/levels/HH48.yaml` |
| ... | +20 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART13.json` + `build/phase-5/yaml/`*
