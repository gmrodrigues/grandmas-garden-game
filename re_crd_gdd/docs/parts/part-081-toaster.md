# Part 81 — Toaster

## Identity

| Field | Value |
|-------|-------|
| Part Type | `81` |
| Category | Electrical |
| Description | Plug this toaster into an electrical outlet and push down on the switch to make it work. When the toast is done, it pops into the air. Use it to bump other objects. You can also program it to work as a timer. The darker the toast you choose, the longer the amount of time it takes to pop up. |
| ANM File | `PART81.ANM` → `build/phase-4/anm/PART81.json` |
| BMP Resource | `PART81.BMP` → `build/phase-3/bitmaps/PART81_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**12 level(s)** use this part type:

- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HH8.yaml` → `godot/assets/levels/HH8.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/MLEV13.yaml` → `godot/assets/levels/MLEV13.yaml`
- `build/phase-5/yaml/RLEV1.yaml` → `godot/assets/levels/RLEV1.yaml`
- `build/phase-5/yaml/RLEV18.yaml` → `godot/assets/levels/RLEV18.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/TLEV20.yaml` → `godot/assets/levels/TLEV20.yaml`
- `build/phase-5/yaml/TLEV5.yaml` → `godot/assets/levels/TLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 3776 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 24 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 44 | bitmap frame width |
| `bitmap_h` | 35 | bitmap frame height |

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
| Not Toasting | `1→8`, `6→9`, `7→10` | — | No |
| Toasting | `2→6`, `3→7`, `4→-1` | — | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 48 |
| Total States | 9 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 48×35 | 0 |
| `8` | 1 | 1–4 (4 frames) | 48×31 | 19 |
| `2` | 5 | 5–15 (11 frames) | 40×49 | 73 |
| `6` | 16 | 16 | 48×35 | 336 |
| `9` | 17 | 17–20 (4 frames) | 48×31 | 355 |
| `3` | 21 | 21–31 (11 frames) | 40×49 | 409 |
| `7` | 32 | 32 | 48×35 | 672 |
| `10` | 33 | 33–36 (4 frames) | 48×31 | 691 |
| `4` | 37 | 37–47 (11 frames) | 40×49 | 745 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f006.png :material-check:` |
| 1 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 2 | `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART81_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 3 | `0001_0003`, `0001_0001` | `build/phase-3/bitmaps/PART81_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 4 | `0001_0003`, `0001_0001` | `build/phase-3/bitmaps/PART81_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 5 | `0001_0004`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART81_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f006.png :material-check:` |
| 6 | `0001_0007`, `0001_0000`, `0001_0007`, `0001_0001` | `build/phase-3/bitmaps/PART81_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 7 | `0001_0000`, `0001_0001`, `0001_0008`, `0001_0008` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f008.png :material-check:` |
| 8 | `0001_0000`, `0001_0001`, `0001_0008`, `0001_0008` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f008.png :material-check:` |
| 9 | `0001_0004`, `0001_0001`, `0001_0009`, `0001_0008` | `build/phase-3/bitmaps/PART81_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f008.png :material-check:` |
| 10 | `0001_0005`, `0001_0001`, `0001_0008`, `0001_0009` | `build/phase-3/bitmaps/PART81_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f009.png :material-check:` |
| 11 | `0001_0003`, `0001_0001`, `0001_0008`, `0001_0008` | `build/phase-3/bitmaps/PART81_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f008.png :material-check:` |
| 12 | `0001_0002`, `0001_0001`, `0001_0008`, `0001_0008` | `build/phase-3/bitmaps/PART81_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f008.png :material-check:` |
| 13 | `0001_0000`, `0001_0001`, `0001_0008`, `0001_0010` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f010.png :material-check:` |
| 14 | `0001_0000`, `0001_0001`, `0001_0010`, `0001_0008` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f008.png :material-check:` |
| 15 | `0001_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f006.png :material-check:` |
| 16 | `0001_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f006.png :material-check:` |
| 17 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 18 | `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART81_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 19 | `0001_0003`, `0001_0001` | `build/phase-3/bitmaps/PART81_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 20 | `0001_0003`, `0001_0001` | `build/phase-3/bitmaps/PART81_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 21 | `0001_0004`, `0001_0001`, `0001_0015` | `build/phase-3/bitmaps/PART81_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f015.png :material-check:` |
| 22 | `0001_0011`, `0001_0000`, `0001_0011`, `0001_0001` | `build/phase-3/bitmaps/PART81_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f011.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 23 | `0001_0000`, `0001_0001`, `0001_0012`, `0001_0012` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f012.png :material-check:` |
| 24 | `0001_0000`, `0001_0001`, `0001_0012`, `0001_0012` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f012.png :material-check:` |
| 25 | `0001_0004`, `0001_0001`, `0001_0013`, `0001_0012` | `build/phase-3/bitmaps/PART81_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f012.png :material-check:` |
| 26 | `0001_0005`, `0001_0001`, `0001_0012`, `0001_0013` | `build/phase-3/bitmaps/PART81_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f013.png :material-check:` |
| 27 | `0001_0003`, `0001_0001`, `0001_0012`, `0001_0012` | `build/phase-3/bitmaps/PART81_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f012.png :material-check:` |
| 28 | `0001_0002`, `0001_0001`, `0001_0012`, `0001_0012` | `build/phase-3/bitmaps/PART81_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f012.png :material-check:` |
| 29 | `0001_0000`, `0001_0001`, `0001_0012`, `0001_0014` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f014.png :material-check:` |
| 30 | `0001_0000`, `0001_0001`, `0001_0014`, `0001_0012` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f012.png :material-check:` |
| 31 | `0001_0000`, `0001_0001`, `0001_0015` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f015.png :material-check:` |
| 32 | `0001_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f006.png :material-check:` |
| 33 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 34 | `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART81_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 35 | `0001_0003`, `0001_0001` | `build/phase-3/bitmaps/PART81_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 36 | `0001_0003`, `0001_0001` | `build/phase-3/bitmaps/PART81_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 37 | `0001_0004`, `0001_0001`, `0001_0020` | `build/phase-3/bitmaps/PART81_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f020.png :material-check:` |
| 38 | `0001_0016`, `0001_0000`, `0001_0016`, `0001_0001` | `build/phase-3/bitmaps/PART81_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:` |
| 39 | `0001_0000`, `0001_0001`, `0001_0017`, `0001_0017` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f017.png :material-check:` |
| 40 | `0001_0000`, `0001_0001`, `0001_0017`, `0001_0017` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f017.png :material-check:` |
| 41 | `0001_0004`, `0001_0001`, `0001_0018`, `0001_0017` | `build/phase-3/bitmaps/PART81_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f018.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f017.png :material-check:` |
| 42 | `0001_0005`, `0001_0001`, `0001_0017`, `0001_0018` | `build/phase-3/bitmaps/PART81_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f018.png :material-check:` |
| 43 | `0001_0003`, `0001_0001`, `0001_0017`, `0001_0017` | `build/phase-3/bitmaps/PART81_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f017.png :material-check:` |
| 44 | `0001_0002`, `0001_0001`, `0001_0017`, `0001_0017` | `build/phase-3/bitmaps/PART81_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f017.png :material-check:` |
| 45 | `0001_0000`, `0001_0001`, `0001_0017`, `0001_0019` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f019.png :material-check:` |
| 46 | `0001_0000`, `0001_0001`, `0001_0019`, `0001_0017` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f019.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f017.png :material-check:` |
| 47 | `0001_0000`, `0001_0001`, `0001_0020` | `build/phase-3/bitmaps/PART81_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART81_f020.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 3 | `3081` | 0 | `build/phase-6/raw-wav/SX_3081_11025.wav` |
| 19 | `3081` | 0 | `build/phase-6/raw-wav/SX_3081_11025.wav` |
| 35 | `3081` | 0 | `build/phase-6/raw-wav/SX_3081_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 159 |
| `END_FRAME` | 48 |
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

**Toaster** has 2 semantic states: Not Toasting, Toasting. Transitions are triggered by: electrical, collision.

Terminal state(s): Toasting (part is removed from simulation).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART81.json` |
| Sprite PNGs | `godot/assets/sprites/PART81_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/HH4.yaml` |
| Level YAML | `godot/assets/levels/HH8.yaml` |
| Level YAML | `godot/assets/levels/HLEV10.yaml` |
| Level YAML | `godot/assets/levels/HLEV18.yaml` |
| Level YAML | `godot/assets/levels/HLEV26.yaml` |
| ... | +7 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART81.json` + `build/phase-5/yaml/`*
