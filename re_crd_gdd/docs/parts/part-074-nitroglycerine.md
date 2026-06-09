# Part 74 — Nitroglycerine

## Identity

| Field | Value |
|-------|-------|
| Part Type | `74` |
| Category | Explosives / Projectiles |
| Description | This tube of nitroglycerine will explode if it's bumped or dropped with enough force. It blows up all kinds of things, including most walls. |
| ANM File | `PART74.ANM` → `build/phase-4/anm/PART74.json` |
| BMP Resource | `PART74.BMP` → `build/phase-3/bitmaps/PART74_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**38 level(s)** use this part type:

- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/HH13.yaml` → `godot/assets/levels/HH13.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HH27.yaml` → `godot/assets/levels/HH27.yaml`
- `build/phase-5/yaml/HH28.yaml` → `godot/assets/levels/HH28.yaml`
- `build/phase-5/yaml/HH29.yaml` → `godot/assets/levels/HH29.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HH6.yaml` → `godot/assets/levels/HH6.yaml`
- `build/phase-5/yaml/HH7.yaml` → `godot/assets/levels/HH7.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV13.yaml` → `godot/assets/levels/HLEV13.yaml`
- `build/phase-5/yaml/HLEV17.yaml` → `godot/assets/levels/HLEV17.yaml`
- `build/phase-5/yaml/HLEV19.yaml` → `godot/assets/levels/HLEV19.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/HLEV30.yaml` → `godot/assets/levels/HLEV30.yaml`
- `build/phase-5/yaml/HLEV7.yaml` → `godot/assets/levels/HLEV7.yaml`
- `build/phase-5/yaml/MLEV10.yaml` → `godot/assets/levels/MLEV10.yaml`
- `build/phase-5/yaml/MLEV21.yaml` → `godot/assets/levels/MLEV21.yaml`
- `build/phase-5/yaml/MLEV23.yaml` → `godot/assets/levels/MLEV23.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/MLEV3.yaml` → `godot/assets/levels/MLEV3.yaml`
- `build/phase-5/yaml/MLEV8.yaml` → `godot/assets/levels/MLEV8.yaml`
- ... and 8 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2200 | mass/density (relative scale) |
| `unk_2` | 1800 | category-specific property |
| `property_q8` | 64 | Q8.8 = 0.250 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 10 | bitmap frame width |
| `bitmap_h` | 29 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `proximity`, `timer` |
| Destructible | Yes |
| Spawns | `projectile` |
| Category Part Count | 10 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Unexploded | `1→3` | 1 | No |
| Exploded | `3→-1` | — | Yes :material-bomb: |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 8 |
| Total States | 2 |
| Animated (Section A) | Yes |
| Section A Durations | 14 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–12 (13 frames) | 16×29 | 0 |
| `3` | 13 | 13 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART74_f000.png :material-check:` |
| 1 | `0001_0000` | `build/phase-3/bitmaps/PART74_f000.png :material-check:` |
| 2 | `0001_0001` | `build/phase-3/bitmaps/PART74_f001.png :material-check:` |
| 3 | `0001_0002` | `build/phase-3/bitmaps/PART74_f002.png :material-check:` |
| 4 | `0001_0003` | `build/phase-3/bitmaps/PART74_f003.png :material-check:` |
| 5 | `0001_0004` | `build/phase-3/bitmaps/PART74_f004.png :material-check:` |
| 6 | `0001_0005` | `build/phase-3/bitmaps/PART74_f005.png :material-check:` |
| 7 | `0002_0000` | `build/phase-3/bitmaps/BLANK.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `74` | 0 | `build/phase-6/raw-wav/SX_74_11025.wav` |
| 2 | `74` | 0 | `build/phase-6/raw-wav/SX_74_11025.wav` |
| 3 | `74` | 0 | `build/phase-6/raw-wav/SX_74_11025.wav` |
| 4 | `74` | 0 | `build/phase-6/raw-wav/SX_74_11025.wav` |
| 5 | `74` | 0 | `build/phase-6/raw-wav/SX_74_11025.wav` |
| 6 | `74` | 0 | `build/phase-6/raw-wav/SX_74_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 8 |
| `END_FRAME` | 8 |
| `PLAY_SFX` | 6 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | No |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | No |
| Laser | No |
| Projectile | Yes |

## Behavior Notes

**Nitroglycerine** has 2 semantic states: Unexploded, Exploded. Transitions are triggered by: collision, proximity, timer.

State(s) Exploded are explosive — reaching these destroys the part.

Terminal state(s): Exploded (part is removed from simulation).

This part can be destroyed by explosives.

This part spawns a **projectile** (cannonball, rocket, missile) when triggered. The projectile is a separate part instance.

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART74.json` |
| Sprite PNGs | `godot/assets/sprites/PART74_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/HH13.yaml` |
| Level YAML | `godot/assets/levels/HH26.yaml` |
| Level YAML | `godot/assets/levels/HH27.yaml` |
| Level YAML | `godot/assets/levels/HH28.yaml` |
| ... | +33 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART74.json` + `build/phase-5/yaml/`*
