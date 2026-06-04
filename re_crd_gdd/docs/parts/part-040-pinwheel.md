# Part 40 — Pinwheel

## Identity

| Field | Value |
|-------|-------|
| Part Type | `40` |
| Category | Rotating Power Sources |
| Description | You can make this pinwheel spin by blowing air on it (from parts like the fan or the bike pump). Attach a belt and use it to turn other rotating parts. |
| ANM File | `PART40.ANM` → `build/phase-4/anm/PART40.json` |
| BMP Resource | `PART40.BMP` → `build/phase-3/bitmaps/PART40_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**16 level(s)** use this part type:

- `build/phase-5/yaml/HH18.yaml` → `godot/assets/levels/HH18.yaml`
- `build/phase-5/yaml/HH35.yaml` → `godot/assets/levels/HH35.yaml`
- `build/phase-5/yaml/HLEV16.yaml` → `godot/assets/levels/HLEV16.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/MLEV10.yaml` → `godot/assets/levels/MLEV10.yaml`
- `build/phase-5/yaml/MLEV2.yaml` → `godot/assets/levels/MLEV2.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/RLEV10.yaml` → `godot/assets/levels/RLEV10.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/RLEV27.yaml` → `godot/assets/levels/RLEV27.yaml`
- `build/phase-5/yaml/RLEV29.yaml` → `godot/assets/levels/RLEV29.yaml`
- `build/phase-5/yaml/TLEV12.yaml` → `godot/assets/levels/TLEV12.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 50 | bitmap frame width |
| `bitmap_h` | 55 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical`, `rope` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 7 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Spinning | `1→2` | 1 | No |
| Spinning | `2→-1` | 2 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 11 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 56×55 | 0 |
| `2` | 1 | 1–10 (10 frames) | 56×55 | 13 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0010`, `0001_0000` | `build/phase-3/bitmaps/PART40_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART40_f000.png :material-check:` |
| 1 | `0001_0010`, `0001_0000` | `build/phase-3/bitmaps/PART40_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART40_f000.png :material-check:` |
| 2 | `0001_0010`, `0001_0001` | `build/phase-3/bitmaps/PART40_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART40_f001.png :material-check:` |
| 3 | `0001_0010`, `0001_0002` | `build/phase-3/bitmaps/PART40_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART40_f002.png :material-check:` |
| 4 | `0001_0010`, `0001_0003` | `build/phase-3/bitmaps/PART40_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART40_f003.png :material-check:` |
| 5 | `0001_0010`, `0001_0004` | `build/phase-3/bitmaps/PART40_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART40_f004.png :material-check:` |
| 6 | `0001_0010`, `0001_0005` | `build/phase-3/bitmaps/PART40_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART40_f005.png :material-check:` |
| 7 | `0001_0010`, `0001_0006` | `build/phase-3/bitmaps/PART40_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART40_f006.png :material-check:` |
| 8 | `0001_0010`, `0001_0007` | `build/phase-3/bitmaps/PART40_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART40_f007.png :material-check:` |
| 9 | `0001_0010`, `0001_0008` | `build/phase-3/bitmaps/PART40_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART40_f008.png :material-check:` |
| 10 | `0001_0010`, `0001_0009` | `build/phase-3/bitmaps/PART40_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART40_f009.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 22 |
| `END_FRAME` | 11 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | Yes |
| Belt Connection | Yes |
| Rope Connection | Yes |
| Fire/Flame | No |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Pinwheel** has 2 semantic states: Not Spinning, Spinning. Transitions are triggered by: collision, electrical, rope.

Terminal state(s): Spinning (part is removed from simulation).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART40.json` |
| Sprite PNGs | `godot/assets/sprites/PART40_f*.png` |
| Level YAML | `godot/assets/levels/HH18.yaml` |
| Level YAML | `godot/assets/levels/HH35.yaml` |
| Level YAML | `godot/assets/levels/HLEV16.yaml` |
| Level YAML | `godot/assets/levels/HLEV27.yaml` |
| Level YAML | `godot/assets/levels/MLEV10.yaml` |
| ... | +11 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART40.json` + `build/phase-5/yaml/`*
