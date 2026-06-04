# Part 147 — medium mesa

## Identity

| Field | Value |
|-------|-------|
| Part Type | `147` |
| Category | Scenery |
| Description | scenery part |
| ANM File | `PART147.ANM` → `build/phase-4/anm/PART147.json` |
| BMP Resource | `PART147.BMP` → `build/phase-3/bitmaps/PART147_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**5 level(s)** use this part type:

- `build/phase-5/yaml/ELEV5.yaml` → `godot/assets/levels/ELEV5.yaml`
- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `unk_2` | 0 | scenery property (900 for trees, 1100-1200 for clouds/sun) |
| `bitmap_w` | 76 | bitmap frame width |
| `bitmap_h` | 67 | bitmap frame height |

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
| `2` | 0 | 0 | 80×67 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART147.png :material-check:` |

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

**medium mesa** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART147.json` |
| Sprite PNGs | `godot/assets/sprites/PART147_f*.png` |
| Level YAML | `godot/assets/levels/ELEV5.yaml` |
| Level YAML | `godot/assets/levels/HLEV21.yaml` |
| Level YAML | `godot/assets/levels/HLEV22.yaml` |
| Level YAML | `godot/assets/levels/MLEV25.yaml` |
| Level YAML | `godot/assets/levels/RLEV17.yaml` |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART147.json` + `build/phase-5/yaml/`*
