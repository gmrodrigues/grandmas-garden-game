# Part 111 — Spruce Tree

## Identity

| Field | Value |
|-------|-------|
| Part Type | `111` |
| Category | Scenery |
| Description | scenery part |
| ANM File | `PART111.ANM` → `build/phase-4/anm/PART111.json` |
| BMP Resource | `PART111.BMP` → `build/phase-3/bitmaps/PART111_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**10 level(s)** use this part type:

- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV24.yaml` → `godot/assets/levels/ELEV24.yaml`
- `build/phase-5/yaml/ELEV7.yaml` → `godot/assets/levels/ELEV7.yaml`
- `build/phase-5/yaml/ELEV8.yaml` → `godot/assets/levels/ELEV8.yaml`
- `build/phase-5/yaml/HLEV19.yaml` → `godot/assets/levels/HLEV19.yaml`
- `build/phase-5/yaml/HLEV30.yaml` → `godot/assets/levels/HLEV30.yaml`
- `build/phase-5/yaml/HLEV8.yaml` → `godot/assets/levels/HLEV8.yaml`
- `build/phase-5/yaml/HLEV9.yaml` → `godot/assets/levels/HLEV9.yaml`
- `build/phase-5/yaml/MLEV1.yaml` → `godot/assets/levels/MLEV1.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `unk_2` | 900 | scenery property (900 for trees, 1100-1200 for clouds/sun) |
| `bitmap_w` | 59 | bitmap frame width |
| `bitmap_h` | 88 | bitmap frame height |

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
| Total States | 0 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART111.png :material-check:` |

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

**Spruce Tree** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART111.json` |
| Sprite PNGs | `godot/assets/sprites/PART111_f*.png` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV24.yaml` |
| Level YAML | `godot/assets/levels/ELEV7.yaml` |
| Level YAML | `godot/assets/levels/ELEV8.yaml` |
| Level YAML | `godot/assets/levels/HLEV19.yaml` |
| ... | +5 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART111.json` + `build/phase-5/yaml/`*
