# Part 148 — Laser Detector

## Identity

| Field | Value |
|-------|-------|
| Part Type | `148` |
| Category | Lasers / Optics |
| Description | This laser detector can receive laser beams of any color. When a beam strikes the black eye, the green light turns on. If the beam is broken, the red light flashes. If the beam returns, both lights will flash. |
| ANM File | `PART148.ANM` → `build/phase-4/anm/PART148.json` |
| BMP Resource | `PART148.BMP` → `build/phase-3/bitmaps/PART148_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**6 level(s)** use this part type:

- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/MLEV12.yaml` → `godot/assets/levels/MLEV12.yaml`
- `build/phase-5/yaml/RLEV11.yaml` → `godot/assets/levels/RLEV11.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/TLEV30.yaml` → `godot/assets/levels/TLEV30.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `unk_2` | 0 | scenery property (900 for trees, 1100-1200 for clouds/sun) |
| `bitmap_w` | 37 | bitmap frame width |
| `bitmap_h` | 32 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `electrical`, `proximity`, `collision` |
| Destructible | No |
| Spawns | `laser_beam` |
| Category Part Count | 8 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Activated | `2→3` | — | No |
| Activated | `3→4` | — | No |
| Alarm On | `4→-1` | — | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 7 |
| Total States | 4 |
| Animated (Section A) | Yes |
| Section A Durations | 58 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 0 | 0 | 40×32 | 0 |
| `3` | 1 | 1–19 (19 frames) | 40×32 | 7 |
| `4` | 20 | 20–38 (19 frames) | 0×0 | 0 |
| `5` | 39 | 39 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART148_f000.png :material-check:` |
| 1 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART148_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART148_f001.png :material-check:` |
| 2 | `0001_0000` | `build/phase-3/bitmaps/PART148_f000.png :material-check:` |
| 3 | `0001_0000` | `build/phase-3/bitmaps/PART148_f000.png :material-check:` |
| 4 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART148_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART148_f002.png :material-check:` |
| 5 | `0001_0000`, `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART148_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART148_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART148_f002.png :material-check:` |
| 6 | `0001_0000` | `build/phase-3/bitmaps/PART148_f000.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 11 |
| `END_FRAME` | 7 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | Yes |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | No |
| Laser | Yes |
| Projectile | No |

## Behavior Notes

**Laser Detector** has 3 semantic states: Not Activated, Activated, Alarm On. Transitions are triggered by: electrical, proximity, collision.

Terminal state(s): Alarm On (part is removed from simulation).

This part emits a **laser beam**. The beam interacts with mirrors, mixers, and laser-activated plugs.

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART148.json` |
| Sprite PNGs | `godot/assets/sprites/PART148_f*.png` |
| Level YAML | `godot/assets/levels/HH21.yaml` |
| Level YAML | `godot/assets/levels/MLEV12.yaml` |
| Level YAML | `godot/assets/levels/RLEV11.yaml` |
| Level YAML | `godot/assets/levels/RLEV22.yaml` |
| Level YAML | `godot/assets/levels/RLEV26.yaml` |
| ... | +1 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART148.json` + `build/phase-5/yaml/`*
