# Part 127 — Color Block

## Identity

| Field | Value |
|-------|-------|
| Part Type | `127` |
| Category | Scenery |
| Description | scenery part |
| ANM File | `None.ANM` → `build/phase-4/anm/None.json` |
| BMP Resource | `None.BMP` → `build/phase-3/bitmaps/None_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**24 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV20.yaml` → `godot/assets/levels/ELEV20.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV14.yaml` → `godot/assets/levels/HLEV14.yaml`
- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV24.yaml` → `godot/assets/levels/HLEV24.yaml`
- `build/phase-5/yaml/HLEV25.yaml` → `godot/assets/levels/HLEV25.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/HLEV30.yaml` → `godot/assets/levels/HLEV30.yaml`
- `build/phase-5/yaml/MLEV1.yaml` → `godot/assets/levels/MLEV1.yaml`
- `build/phase-5/yaml/MLEV13.yaml` → `godot/assets/levels/MLEV13.yaml`
- `build/phase-5/yaml/MLEV2.yaml` → `godot/assets/levels/MLEV2.yaml`
- `build/phase-5/yaml/MLEV20.yaml` → `godot/assets/levels/MLEV20.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`
- `build/phase-5/yaml/RLEV24.yaml` → `godot/assets/levels/RLEV24.yaml`
- `build/phase-5/yaml/RLEV3.yaml` → `godot/assets/levels/RLEV3.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `unk_2` | 0 | scenery property (900 for trees, 1100-1200 for clouds/sun) |
| `bitmap_w` | 48 | bitmap frame width |
| `bitmap_h` | 48 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | *(none)* |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 26 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 0 |
| Total States | 0 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

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

**Color Block** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/None.json` |
| Sprite PNGs | `godot/assets/sprites/None_f*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| Level YAML | `godot/assets/levels/HLEV10.yaml` |
| ... | +19 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/None.json` + `build/phase-5/yaml/`*
