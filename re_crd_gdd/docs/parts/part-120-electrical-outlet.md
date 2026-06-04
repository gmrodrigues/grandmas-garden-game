# Part 120 — Electrical Outlet

## Identity

| Field | Value |
|-------|-------|
| Part Type | `120` |
| Category | Electrical |
| Description | This electrical outlet has juice running to it at all times. Plug in any electrical part and it will work. |
| ANM File | `PART120.ANM` → `build/phase-4/anm/PART120.json` |
| BMP Resource | `PART120.BMP` → `build/phase-3/bitmaps/PART120_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**32 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV25.yaml` → `godot/assets/levels/ELEV25.yaml`
- `build/phase-5/yaml/ELEV6.yaml` → `godot/assets/levels/ELEV6.yaml`
- `build/phase-5/yaml/HH10.yaml` → `godot/assets/levels/HH10.yaml`
- `build/phase-5/yaml/HH11.yaml` → `godot/assets/levels/HH11.yaml`
- `build/phase-5/yaml/HH20.yaml` → `godot/assets/levels/HH20.yaml`
- `build/phase-5/yaml/HH3.yaml` → `godot/assets/levels/HH3.yaml`
- `build/phase-5/yaml/HH30.yaml` → `godot/assets/levels/HH30.yaml`
- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HLEV11.yaml` → `godot/assets/levels/HLEV11.yaml`
- `build/phase-5/yaml/HLEV13.yaml` → `godot/assets/levels/HLEV13.yaml`
- `build/phase-5/yaml/HLEV23.yaml` → `godot/assets/levels/HLEV23.yaml`
- `build/phase-5/yaml/MLEV15.yaml` → `godot/assets/levels/MLEV15.yaml`
- `build/phase-5/yaml/MLEV16.yaml` → `godot/assets/levels/MLEV16.yaml`
- `build/phase-5/yaml/MLEV17.yaml` → `godot/assets/levels/MLEV17.yaml`
- `build/phase-5/yaml/MLEV2.yaml` → `godot/assets/levels/MLEV2.yaml`
- `build/phase-5/yaml/MLEV9.yaml` → `godot/assets/levels/MLEV9.yaml`
- `build/phase-5/yaml/RLEV13.yaml` → `godot/assets/levels/RLEV13.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/RLEV3.yaml` → `godot/assets/levels/RLEV3.yaml`
- `build/phase-5/yaml/TLEV12.yaml` → `godot/assets/levels/TLEV12.yaml`
- `build/phase-5/yaml/TLEV20.yaml` → `godot/assets/levels/TLEV20.yaml`
- `build/phase-5/yaml/TLEV26.yaml` → `godot/assets/levels/TLEV26.yaml`
- `build/phase-5/yaml/TLEV27.yaml` → `godot/assets/levels/TLEV27.yaml`
- `build/phase-5/yaml/TLEV28.yaml` → `godot/assets/levels/TLEV28.yaml`
- `build/phase-5/yaml/TLEV29.yaml` → `godot/assets/levels/TLEV29.yaml`
- `build/phase-5/yaml/TLEV30.yaml` → `godot/assets/levels/TLEV30.yaml`
- ... and 2 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `unk_2` | 0 | scenery property (900 for trees, 1100-1200 for clouds/sun) |
| `bitmap_w` | 25 | bitmap frame width |
| `bitmap_h` | 32 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `electrical`, `collision` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 9 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

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
| `1` | 0 | 0 | 32×32 | 0 |
| `2` | 1 | 1 | 32×32 | 7 |
| `3` | 2 | 2 | 32×32 | 20 |
| `4` | 3 | 3 | 32×32 | 33 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART120_f000.png :material-check:` |
| 1 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART120_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART120_f001.png :material-check:` |
| 2 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART120_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART120_f001.png :material-check:` |
| 3 | `0001_0000`, `0001_0001`, `0001_0001` | `build/phase-3/bitmaps/PART120_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART120_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART120_f001.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 8 |
| `END_FRAME` | 4 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | Yes |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | No |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Electrical Outlet** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART120.json` |
| Sprite PNGs | `godot/assets/sprites/PART120_f*.png` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV25.yaml` |
| Level YAML | `godot/assets/levels/ELEV6.yaml` |
| Level YAML | `godot/assets/levels/HH10.yaml` |
| Level YAML | `godot/assets/levels/HH11.yaml` |
| ... | +27 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART120.json` + `build/phase-5/yaml/`*
