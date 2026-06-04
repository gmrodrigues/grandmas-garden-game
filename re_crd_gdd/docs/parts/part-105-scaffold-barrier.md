# Part 105 — Scaffold Barrier

## Identity

| Field | Value |
|-------|-------|
| Part Type | `105` |
| Category | Walls / Floors |
| Description | This chunk of metal scaffolding can be used to fill spaces so objects can't pass through. You can set things on top of it, or bounce things off it. But you can't blow it up. |
| ANM File | `PART105.ANM` → `build/phase-4/anm/PART105.json` |
| BMP Resource | `PART105.BMP` → `build/phase-3/bitmaps/PART105_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**10 level(s)** use this part type:

- `build/phase-5/yaml/ELEV12.yaml` → `godot/assets/levels/ELEV12.yaml`
- `build/phase-5/yaml/ELEV16.yaml` → `godot/assets/levels/ELEV16.yaml`
- `build/phase-5/yaml/ELEV8.yaml` → `godot/assets/levels/ELEV8.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/MLEV12.yaml` → `godot/assets/levels/MLEV12.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `friction_q8` | 1024 | friction = 4.000 |
| `unk_6` | 24 | category-specific property |
| `tile_w` | 0 | base width in tile units |
| `tile_h` | 0 | base height in tile units |
| `collision_w` | 0 | AABB collision width |
| `collision_h` | 0 | AABB collision height |
| `bitmap_w` | 64 | bitmap frame width |
| `bitmap_h` | 64 | bitmap frame height |

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
| Total Frames | 1 |
| Total States | 1 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 64×64 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART105.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 1 |
| `END_FRAME` | 1 |
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

**Scaffold Barrier** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART105.json` |
| Sprite PNGs | `godot/assets/sprites/PART105_f*.png` |
| Level YAML | `godot/assets/levels/ELEV12.yaml` |
| Level YAML | `godot/assets/levels/ELEV16.yaml` |
| Level YAML | `godot/assets/levels/ELEV8.yaml` |
| Level YAML | `godot/assets/levels/HLEV12.yaml` |
| Level YAML | `godot/assets/levels/HLEV26.yaml` |
| ... | +5 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART105.json` + `build/phase-5/yaml/`*
