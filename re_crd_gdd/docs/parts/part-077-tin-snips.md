# Part 77 — Tin Snips

## Identity

| Field | Value |
|-------|-------|
| Part Type | `77` |
| Category | Cutting / Popping |
| Description | You can use these tin snips to cut through rope or steel cable, or to pop blimps and balloons. To make them cut, just bump the handles with another object. They can also be used to pop blimps and balloons. |
| ANM File | `PART77.ANM` → `build/phase-4/anm/PART77.json` |
| BMP Resource | `PART77.BMP` → `build/phase-3/bitmaps/PART77_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**6 level(s)** use this part type:

- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV7.yaml` → `godot/assets/levels/RLEV7.yaml`
- `build/phase-5/yaml/TLEV33.yaml` → `godot/assets/levels/TLEV33.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 56 | bitmap frame width |
| `bitmap_h` | 33 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 3 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Open | `4→5` | — | No |
| Closed | `3→-1` | — | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 4 |
| Total States | 4 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `4` | 0 | 0 | 61×33 | 0 |
| `5` | 1 | 1 | 16×8 | 13 |
| `6` | 2 | 2 | 64×21 | 20 |
| `3` | 3 | 3 | 64×21 | 29 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART77_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART77_f002.png :material-check:` |
| 1 | `0001_0002` | `build/phase-3/bitmaps/PART77_f002.png :material-check:` |
| 2 | `0001_0001` | `build/phase-3/bitmaps/PART77_f001.png :material-check:` |
| 3 | `0001_0001` | `build/phase-3/bitmaps/PART77_f001.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 2 | `3077` | 0 | `build/phase-6/raw-wav/SX_3077_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 5 |
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

**Tin Snips** has 2 semantic states: Open, Closed. Transitions are triggered by: collision.

Terminal state(s): Closed (part is removed from simulation).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART77.json` |
| Sprite PNGs | `godot/assets/sprites/PART77_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/HH42.yaml` |
| Level YAML | `godot/assets/levels/MLEV27.yaml` |
| Level YAML | `godot/assets/levels/MLEV28.yaml` |
| Level YAML | `godot/assets/levels/RLEV14.yaml` |
| Level YAML | `godot/assets/levels/RLEV7.yaml` |
| ... | +1 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART77.json` + `build/phase-5/yaml/`*
