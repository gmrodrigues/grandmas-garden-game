# Part 136 — Message Computer

## Identity

| Field | Value |
|-------|-------|
| Part Type | `136` |
| Category | Special Mechanics |
| Description | This little computer is a handy way to relay messages one letter at a time. A letter will appear on the monitor if something bumps the keyboard. The computer may be programmed to display any letter in the alphabet, numbers 0 through 9, and several symbols. Line them up side by side to spell out a whole message. |
| ANM File | `PART136.ANM` → `build/phase-4/anm/PART136.json` |
| BMP Resource | `PART136.BMP` → `build/phase-3/bitmaps/PART136_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**4 level(s)** use this part type:

- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/TLEV23.yaml` → `godot/assets/levels/TLEV23.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2400 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 12 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 46 | bitmap frame width |
| `bitmap_h` | 43 | bitmap frame height |

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
| Off | `4→5` | — | No |
| On | `5→-1` | 5 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 9 |
| Total States | 3 |
| Animated (Section A) | Yes |
| Section A Durations | 16 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `4` | 0 | 0 | 48×43 | 0 |
| `5` | 1 | 1 | 48×43 | 13 |
| `6` | 2 | 2–8 (7 frames) | 48×43 | 20 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART136_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART136_f001.png :material-check:` |
| 1 | `0001_0000` | `build/phase-3/bitmaps/PART136_f000.png :material-check:` |
| 2 | `0001_0000`, `0002_0000` | `build/phase-3/bitmaps/PART136_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART136_2_f000.png :material-alert-outline: (not found)` |
| 3 | `0001_0000`, `0002_0001` | `build/phase-3/bitmaps/PART136_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART136_2_f001.png :material-alert-outline: (not found)` |
| 4 | `0001_0000`, `0002_0002` | `build/phase-3/bitmaps/PART136_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART136_2_f002.png :material-alert-outline: (not found)` |
| 5 | `0001_0000`, `0002_0003` | `build/phase-3/bitmaps/PART136_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART136_2_f003.png :material-alert-outline: (not found)` |
| 6 | `0001_0000`, `0002_0004` | `build/phase-3/bitmaps/PART136_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART136_2_f004.png :material-alert-outline: (not found)` |
| 7 | `0001_0000`, `0002_0005` | `build/phase-3/bitmaps/PART136_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART136_2_f005.png :material-alert-outline: (not found)` |
| 8 | `0001_0000`, `0002_0006` | `build/phase-3/bitmaps/PART136_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART136_2_f006.png :material-alert-outline: (not found)` |

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
| Fire/Flame | No |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Message Computer** has 2 semantic states: Off, On. Transitions are triggered by: collision, electrical, proximity.

Terminal state(s): On (part is removed from simulation).

This part has custom spawn behavior defined in SOLVE.RES.

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART136.json` |
| Sprite PNGs | `godot/assets/sprites/PART136_f*.png` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/HLEV28.yaml` |
| Level YAML | `godot/assets/levels/MLEV30.yaml` |
| Level YAML | `godot/assets/levels/TLEV23.yaml` |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART136.json` + `build/phase-5/yaml/`*
