# Part 29 — Lava Lamp

## Identity

| Field | Value |
|-------|-------|
| Part Type | `29` |
| Category | Light / Flame Sources |
| Description | This groovy lava lamp isn't just a cool piece of retro-decor taken from Professor Tim's attic. It's also an excellent light source. Tie a rope to the chain and give it a tug to turn on the lamp. Use it to power up the solar panel, or shine it through a magnifying glass to light fuses and candles. |
| ANM File | `PART29.ANM` → `build/phase-4/anm/PART29.json` |
| BMP Resource | `PART29.BMP` → `build/phase-3/bitmaps/PART29_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**19 level(s)** use this part type:

- `build/phase-5/yaml/HH10.yaml` → `godot/assets/levels/HH10.yaml`
- `build/phase-5/yaml/HH27.yaml` → `godot/assets/levels/HH27.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH34.yaml` → `godot/assets/levels/HH34.yaml`
- `build/phase-5/yaml/HH44.yaml` → `godot/assets/levels/HH44.yaml`
- `build/phase-5/yaml/HH6.yaml` → `godot/assets/levels/HH6.yaml`
- `build/phase-5/yaml/HLEV11.yaml` → `godot/assets/levels/HLEV11.yaml`
- `build/phase-5/yaml/HLEV14.yaml` → `godot/assets/levels/HLEV14.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/MLEV12.yaml` → `godot/assets/levels/MLEV12.yaml`
- `build/phase-5/yaml/MLEV20.yaml` → `godot/assets/levels/MLEV20.yaml`
- `build/phase-5/yaml/MLEV22.yaml` → `godot/assets/levels/MLEV22.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV24.yaml` → `godot/assets/levels/RLEV24.yaml`
- `build/phase-5/yaml/TLEV7.yaml` → `godot/assets/levels/TLEV7.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1300 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 24 | bitmap frame width |
| `bitmap_h` | 65 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `proximity`, `electrical` |
| Destructible | No |
| Spawns | `fire` |
| Category Part Count | 5 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Off | `1→2` | 1 | No |
| On | `2→-1` | 3 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 8 |
| Total States | 3 |
| Animated (Section A) | Yes |
| Section A Durations | 22 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 28×65 | 0 |
| `2` | 1 | 1–6 (6 frames) | 27×79 | 25 |
| `3` | 7 | 7 | 28×65 | 265 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0001`, `0001_0002`, `0001_0003` | `build/phase-3/bitmaps/PART29_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f003.png :material-check:` |
| 1 | `0001_0000`, `0001_0001`, `0001_0002`, `0001_0002`, `0001_0003`, `0001_0001`, `0001_0004` | `build/phase-3/bitmaps/PART29_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f004.png :material-check:` |
| 2 | `0001_0000`, `0001_0001`, `0001_0002`, `0001_0002`, `0001_0003`, `0001_0001`, `0001_0005` | `build/phase-3/bitmaps/PART29_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f005.png :material-check:` |
| 3 | `0001_0000`, `0001_0001`, `0001_0002`, `0001_0003`, `0001_0006` | `build/phase-3/bitmaps/PART29_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f006.png :material-check:` |
| 4 | `0001_0000`, `0001_0001`, `0001_0002`, `0001_0003`, `0001_0007` | `build/phase-3/bitmaps/PART29_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f007.png :material-check:` |
| 5 | `0001_0000`, `0001_0001`, `0001_0002`, `0001_0003`, `0001_0008` | `build/phase-3/bitmaps/PART29_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f008.png :material-check:` |
| 6 | `0001_0000`, `0001_0001`, `0001_0002`, `0001_0003`, `0001_0004`, `0001_0000`, `0001_0001`, `0001_0002`, `0001_0003`, `0001_0004` | `build/phase-3/bitmaps/PART29_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f004.png :material-check:` |
| 7 | `0001_0000`, `0001_0001`, `0001_0002`, `0001_0003`, `0001_0005` | `build/phase-3/bitmaps/PART29_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART29_f005.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 48 |
| `END_FRAME` | 8 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | Yes |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | Yes |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Lava Lamp** has 2 semantic states: Off, On. Transitions are triggered by: proximity, electrical.

Terminal state(s): On (part is removed from simulation).

This part can ignite nearby combustible parts (balloons, explosives). Uses proximity trigger.

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART29.json` |
| Sprite PNGs | `godot/assets/sprites/PART29_f*.png` |
| Level YAML | `godot/assets/levels/HH10.yaml` |
| Level YAML | `godot/assets/levels/HH27.yaml` |
| Level YAML | `godot/assets/levels/HH32.yaml` |
| Level YAML | `godot/assets/levels/HH34.yaml` |
| Level YAML | `godot/assets/levels/HH44.yaml` |
| ... | +14 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART29.json` + `build/phase-5/yaml/`*
