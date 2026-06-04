# Part 47 — Curved Pipe Wall

## Identity

| Field | Value |
|-------|-------|
| Part Type | `47` |
| Category | Walls / Floors |
| Description | This curved pipe section can be connected to a pipe wall or floor. Flip it to curve in the direction needed. |
| ANM File | `PART47.ANM` → `build/phase-4/anm/PART47.json` |
| BMP Resource | `PART47.BMP` → `build/phase-3/bitmaps/PART47_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**7 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/HLEV25.yaml` → `godot/assets/levels/HLEV25.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/MLEV14.yaml` → `godot/assets/levels/MLEV14.yaml`
- `build/phase-5/yaml/MLEV20.yaml` → `godot/assets/levels/MLEV20.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/TLEV2.yaml` → `godot/assets/levels/TLEV2.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `friction_q8` | 1024 | friction = 4.000 |
| `unk_6` | 16 | category-specific property |
| `tile_w` | 240 | base width in tile units |
| `tile_h` | 240 | base height in tile units |
| `collision_w` | 0 | AABB collision width |
| `collision_h` | 0 | AABB collision height |
| `bitmap_w` | 32 | bitmap frame width |
| `bitmap_h` | 32 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | *(none)* |
| Destructible | Yes |
| Spawns | *(none)* |
| Category Part Count | 15 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 4 |
| Total States | 1 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–3 (4 frames) | 32×32 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART47_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART47_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART47_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART47_f003.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 4 |
| `END_FRAME` | 4 |
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

**Curved Pipe Wall** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART47.json` |
| Sprite PNGs | `godot/assets/sprites/PART47_f*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/HLEV25.yaml` |
| Level YAML | `godot/assets/levels/HLEV31.yaml` |
| Level YAML | `godot/assets/levels/MLEV14.yaml` |
| Level YAML | `godot/assets/levels/MLEV20.yaml` |
| ... | +2 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART47.json` + `build/phase-5/yaml/`*
