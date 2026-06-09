# Part 45 — Aladdin's Lamp

## Identity

| Field | Value |
|-------|-------|
| Part Type | `45` |
| Category | Light / Flame Sources |
| Description | Light this oil lamp with a laser, a flaming part (like flint rocks or a match-on-a-spring), or a light source and a magnifying glass. Once it's burning, you can use it to light candles and fuses, heat up coffee pots, or to pop blimps and balloons. |
| ANM File | `PART45.ANM` → `build/phase-4/anm/PART45.json` |
| BMP Resource | `PART45.BMP` → `build/phase-3/bitmaps/PART45_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**8 level(s)** use this part type:

- `build/phase-5/yaml/HH10.yaml` → `godot/assets/levels/HH10.yaml`
- `build/phase-5/yaml/HH11.yaml` → `godot/assets/levels/HH11.yaml`
- `build/phase-5/yaml/HH14.yaml` → `godot/assets/levels/HH14.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH29.yaml` → `godot/assets/levels/HH29.yaml`
- `build/phase-5/yaml/HH8.yaml` → `godot/assets/levels/HH8.yaml`
- `build/phase-5/yaml/MLEV14.yaml` → `godot/assets/levels/MLEV14.yaml`
- `build/phase-5/yaml/TLEV8.yaml` → `godot/assets/levels/TLEV8.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2000 | mass/density (relative scale) |
| `unk_2` | 50 | category-specific property |
| `property_q8` | 84 | Q8.8 = 0.328 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 51 | bitmap frame width |
| `bitmap_h` | 29 | bitmap frame height |

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
| Out | `1→2` | 1 | No |
| Lit | `2→-1` | 2 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 9 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 56×29 | 0 |
| `3` | 1 | 1–3 (3 frames) | 57×29 | 7 |
| `2` | 4 | 4–8 (5 frames) | 57×46 | 46 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART45.png :material-check:` |
| 1 | `0001_0000`, `0003_0000` | `build/phase-3/bitmaps/PART45.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f000.png :material-check:` |
| 2 | `0001_0000`, `0003_0001` | `build/phase-3/bitmaps/PART45.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f001.png :material-check:` |
| 3 | `0001_0000`, `0003_0002` | `build/phase-3/bitmaps/PART45.png :material-check:`<br>`build/phase-3/bitmaps/TWINKLE_f002.png :material-check:` |
| 4 | `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART45.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f000.png :material-check:` |
| 5 | `0002_0001`, `0001_0000` | `build/phase-3/bitmaps/FLAMES_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART45.png :material-check:` |
| 6 | `0001_0000`, `0002_0002` | `build/phase-3/bitmaps/PART45.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f002.png :material-check:` |
| 7 | `0001_0000`, `0002_0003` | `build/phase-3/bitmaps/PART45.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f003.png :material-check:` |
| 8 | `0001_0000`, `0002_0004` | `build/phase-3/bitmaps/PART45.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f004.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 17 |
| `END_FRAME` | 9 |
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

**Aladdin's Lamp** has 2 semantic states: Out, Lit. Transitions are triggered by: proximity, electrical.

Terminal state(s): Lit (part is removed from simulation).

This part can ignite nearby combustible parts (balloons, explosives). Uses proximity trigger.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART45.json` |
| Sprite PNGs | `godot/assets/sprites/PART45_f*.png` |
| Level YAML | `godot/assets/levels/HH10.yaml` |
| Level YAML | `godot/assets/levels/HH11.yaml` |
| Level YAML | `godot/assets/levels/HH14.yaml` |
| Level YAML | `godot/assets/levels/HH17.yaml` |
| Level YAML | `godot/assets/levels/HH29.yaml` |
| ... | +3 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART45.json` + `build/phase-5/yaml/`*
