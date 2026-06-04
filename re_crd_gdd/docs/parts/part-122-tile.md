# Part 122 — tile

## Identity

| Field | Value |
|-------|-------|
| Part Type | `122` |
| Category | Scenery |
| Description | scenery part |
| ANM File | `PART122.ANM` → `build/phase-4/anm/PART122.json` |
| BMP Resource | `PART122.BMP` → `build/phase-3/bitmaps/PART122_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/MLEV29.yaml` → `godot/assets/levels/MLEV29.yaml`
- `build/phase-5/yaml/MLEV6.yaml` → `godot/assets/levels/MLEV6.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `unk_2` | 0 | scenery property (900 for trees, 1100-1200 for clouds/sun) |
| `bitmap_w` | 96 | bitmap frame width |
| `bitmap_h` | 80 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | *(none)* |
| Destructible | Yes |
| Spawns | *(none)* |
| Category Part Count | 26 |

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
| `2` | 0 | 0 | 96×80 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART122.png :material-check:` |

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

**tile** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART122.json` |
| Sprite PNGs | `godot/assets/sprites/PART122_f*.png` |
| Level YAML | `godot/assets/levels/MLEV29.yaml` |
| Level YAML | `godot/assets/levels/MLEV6.yaml` |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART122.json` + `build/phase-5/yaml/`*
