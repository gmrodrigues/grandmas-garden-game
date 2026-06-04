# Part 34 — Santa Claus

## Identity

| Field | Value |
|-------|-------|
| Part Type | `34` |
| Category | Characters |
| Description | Ho, ho, ho! Happy Holidays! This cheesy plastic Santa Claus lamp will only light up when you place it next to an electric socket. |
| ANM File | `PART34.ANM` → `build/phase-4/anm/PART34.json` |
| BMP Resource | `PART34.BMP` → `build/phase-3/bitmaps/PART34_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

*This part is not used in any built-in level (may be created dynamically at runtime).*

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
| `bitmap_w` | 53 | bitmap frame width |
| `bitmap_h` | 62 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `proximity` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 8 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Off | `1→2` | 1 | No |
| On | `2→-1` | 2 | No |
| !Part | *(none)* | — | No |
| Boxing Glove | *(none)* | — | No |
| Cocked | `2→3` | — | No |
| Punched | `3→-1` | — | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 13 |
| Total States | 2 |
| Animated (Section A) | Yes |
| Section A Durations | 56 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 56×62 | 0 |
| `2` | 1 | 1–12 (12 frames) | 56×62 | 7 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART34_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART34_f001.png :material-check:` |
| 2 | `0001_0000` | `build/phase-3/bitmaps/PART34_f000.png :material-check:` |
| 3 | `0001_0001` | `build/phase-3/bitmaps/PART34_f001.png :material-check:` |
| 4 | `0001_0000` | `build/phase-3/bitmaps/PART34_f000.png :material-check:` |
| 5 | `0001_0001` | `build/phase-3/bitmaps/PART34_f001.png :material-check:` |
| 6 | `0001_0000` | `build/phase-3/bitmaps/PART34_f000.png :material-check:` |
| 7 | `0001_0001` | `build/phase-3/bitmaps/PART34_f001.png :material-check:` |
| 8 | `0001_0000` | `build/phase-3/bitmaps/PART34_f000.png :material-check:` |
| 9 | `0001_0001` | `build/phase-3/bitmaps/PART34_f001.png :material-check:` |
| 10 | `0001_0000` | `build/phase-3/bitmaps/PART34_f000.png :material-check:` |
| 11 | `0001_0001` | `build/phase-3/bitmaps/PART34_f001.png :material-check:` |
| 12 | `0001_0000` | `build/phase-3/bitmaps/PART34_f000.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 13 |
| `END_FRAME` | 13 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | No |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | No |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Santa Claus** has 6 semantic states: Off, On, !Part, Boxing Glove, Cocked, Punched. Transitions are triggered by: collision, proximity.

Terminal state(s): On, Punched (part is removed from simulation).

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART34.json` |
| Sprite PNGs | `godot/assets/sprites/PART34_f*.png` |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART34.json` + `build/phase-5/yaml/`*
