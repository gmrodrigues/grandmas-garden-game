# Part 32 — Boris the Bat

## Identity

| Field | Value |
|-------|-------|
| Part Type | `32` |
| Category | Characters |
| Description | Happy Halloween! Meet Boris the Bat. He hangs in mid-air until he's bumped. Then he flies around acting batty. |
| ANM File | `PART32.ANM` → `build/phase-4/anm/PART32.json` |
| BMP Resource | `PART32.BMP` → `build/phase-3/bitmaps/PART32_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

*This part is not used in any built-in level (may be created dynamically at runtime).*

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2400 | mass/density (relative scale) |
| `unk_2` | 40 | category-specific property |
| `property_q8` | 64 | Q8.8 = 0.250 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 22 | bitmap frame width |
| `bitmap_h` | 54 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `proximity` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 8 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 4 |
| Total States | 2 |
| Animated (Section A) | Yes |
| Section A Durations | 6 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 24×54 | 0 |
| `2` | 1 | 1–3 (3 frames) | 106×40 | 7 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART32_f000.png :material-check:` |
| 1 | `0001_0002`, `0001_0002`, `0001_0001` | `build/phase-3/bitmaps/PART32_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART32_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART32_f001.png :material-check:` |
| 2 | `0001_0001`, `0001_0003` | `build/phase-3/bitmaps/PART32_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART32_f003.png :material-check:` |
| 3 | `0001_0001`, `0001_0003` | `build/phase-3/bitmaps/PART32_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART32_f003.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 2 | `3032` | 0 | `build/phase-6/raw-wav/SX_3032_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 8 |
| `END_FRAME` | 4 |
| `PLAY_SFX` | 1 |
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

**Boris the Bat** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART32.json` |
| Sprite PNGs | `godot/assets/sprites/PART32_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART32.json` + `build/phase-5/yaml/`*
