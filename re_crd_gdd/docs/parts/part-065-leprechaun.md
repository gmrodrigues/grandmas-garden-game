# Part 65 — Leprechaun

## Identity

| Field | Value |
|-------|-------|
| Part Type | `65` |
| Category | Characters |
| Description | Happy Saint Patrick's Day! Say hi to Blarney O'Reilly, the leprechaun who lives in Professor Tim's garden. Give him a nudge and he'll dance a jig for you. |
| ANM File | `PART65.ANM` → `build/phase-4/anm/PART65.json` |
| BMP Resource | `PART65.BMP` → `build/phase-3/bitmaps/PART65_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

*This part is not used in any built-in level (may be created dynamically at runtime).*

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2000 | mass/density (relative scale) |
| `unk_2` | 800 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 64 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 39 | bitmap frame width |
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
| Resting | `1→2` | — | No |
| Dancing | `2→-1` | — | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 18 |
| Total States | 3 |
| Animated (Section A) | Yes |
| Section A Durations | 20 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 40×62 | 0 |
| `2` | 1 | 1–7 (7 frames) | 40×62 | 13 |
| `3` | 8 | 8–17 (10 frames) | 48×65 | 118 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART65_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 1 | `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART65_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 2 | `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART65_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 3 | `0001_0002`, `0001_0000` | `build/phase-3/bitmaps/PART65_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 4 | `0001_0003`, `0001_0000` | `build/phase-3/bitmaps/PART65_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 5 | `0001_0004`, `0001_0000` | `build/phase-3/bitmaps/PART65_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 6 | `0001_0005`, `0001_0000` | `build/phase-3/bitmaps/PART65_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 7 | `0001_0004`, `0001_0000` | `build/phase-3/bitmaps/PART65_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 8 | `0001_0003`, `0001_0000` | `build/phase-3/bitmaps/PART65_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 9 | `0001_0002`, `0001_0000` | `build/phase-3/bitmaps/PART65_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 10 | `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART65_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 11 | `0001_0002`, `0001_0000` | `build/phase-3/bitmaps/PART65_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 12 | `0001_0003`, `0001_0000` | `build/phase-3/bitmaps/PART65_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 13 | `0001_0004`, `0001_0000` | `build/phase-3/bitmaps/PART65_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 14 | `0001_0005`, `0001_0000` | `build/phase-3/bitmaps/PART65_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 15 | `0001_0004`, `0001_0000` | `build/phase-3/bitmaps/PART65_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 16 | `0001_0003`, `0001_0000` | `build/phase-3/bitmaps/PART65_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |
| 17 | `0001_0002`, `0001_0000` | `build/phase-3/bitmaps/PART65_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART65_f000.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 2 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 3 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 4 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 5 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 6 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 7 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 8 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 9 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 10 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 11 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 12 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 13 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 14 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 15 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 16 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |
| 17 | `65` | 0 | `build/phase-6/raw-wav/SX_65_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 36 |
| `END_FRAME` | 18 |
| `PLAY_SFX` | 17 |
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

**Leprechaun** has 2 semantic states: Resting, Dancing. Transitions are triggered by: collision, proximity.

Terminal state(s): Dancing (part is removed from simulation).

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART65.json` |
| Sprite PNGs | `godot/assets/sprites/PART65_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART65.json` + `build/phase-5/yaml/`*
