# Part 21 — Electric Switch & Outlet

## Identity

| Field | Value |
|-------|-------|
| Part Type | `21` |
| Category | Electrical |
| Description | Plug any of the electrical parts (like the toaster, can opener, or fan) into this electric outlet, then drop something on the switch to turn on the power. Or bump up on the switch if it's upside-down. |
| ANM File | `PART21.ANM` → `build/phase-4/anm/PART21.json` |
| BMP Resource | `PART21.BMP` → `build/phase-3/bitmaps/PART21_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**54 level(s)** use this part type:

- `build/phase-5/yaml/ELEV16.yaml` → `godot/assets/levels/ELEV16.yaml`
- `build/phase-5/yaml/ELEV17.yaml` → `godot/assets/levels/ELEV17.yaml`
- `build/phase-5/yaml/ELEV24.yaml` → `godot/assets/levels/ELEV24.yaml`
- `build/phase-5/yaml/ELEV26.yaml` → `godot/assets/levels/ELEV26.yaml`
- `build/phase-5/yaml/ELEV5.yaml` → `godot/assets/levels/ELEV5.yaml`
- `build/phase-5/yaml/ELEV6.yaml` → `godot/assets/levels/ELEV6.yaml`
- `build/phase-5/yaml/HH10.yaml` → `godot/assets/levels/HH10.yaml`
- `build/phase-5/yaml/HH13.yaml` → `godot/assets/levels/HH13.yaml`
- `build/phase-5/yaml/HH19.yaml` → `godot/assets/levels/HH19.yaml`
- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HH22.yaml` → `godot/assets/levels/HH22.yaml`
- `build/phase-5/yaml/HH27.yaml` → `godot/assets/levels/HH27.yaml`
- `build/phase-5/yaml/HH29.yaml` → `godot/assets/levels/HH29.yaml`
- `build/phase-5/yaml/HH30.yaml` → `godot/assets/levels/HH30.yaml`
- `build/phase-5/yaml/HH36.yaml` → `godot/assets/levels/HH36.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HH8.yaml` → `godot/assets/levels/HH8.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV15.yaml` → `godot/assets/levels/HLEV15.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- ... and 24 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 3776 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 32 | bitmap frame width |
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
| Total Frames | 8 |
| Total States | 8 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `6` | 0 | 0 | 32×32 | 0 |
| `7` | 1 | 1 | 32×32 | 13 |
| `8` | 2 | 2 | 32×32 | 32 |
| `9` | 3 | 3 | 32×32 | 51 |
| `10` | 4 | 4 | 32×32 | 76 |
| `11` | 5 | 5 | 32×32 | 89 |
| `12` | 6 | 6 | 32×32 | 108 |
| `13` | 7 | 7 | 32×32 | 127 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART21_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f001.png :material-check:` |
| 1 | `0001_0000`, `0001_0001`, `0001_0003` | `build/phase-3/bitmaps/PART21_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f003.png :material-check:` |
| 2 | `0001_0000`, `0001_0001`, `0001_0003` | `build/phase-3/bitmaps/PART21_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f003.png :material-check:` |
| 3 | `0001_0000`, `0001_0001`, `0001_0003`, `0001_0003` | `build/phase-3/bitmaps/PART21_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f003.png :material-check:` |
| 4 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART21_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f002.png :material-check:` |
| 5 | `0001_0000`, `0001_0002`, `0001_0003` | `build/phase-3/bitmaps/PART21_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f003.png :material-check:` |
| 6 | `0001_0000`, `0001_0002`, `0001_0003` | `build/phase-3/bitmaps/PART21_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f003.png :material-check:` |
| 7 | `0001_0000`, `0001_0002`, `0001_0003`, `0001_0003` | `build/phase-3/bitmaps/PART21_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART21_f003.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 24 |
| `END_FRAME` | 8 |
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

**Electric Switch & Outlet** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART21.json` |
| Sprite PNGs | `godot/assets/sprites/PART21_f*.png` |
| Level YAML | `godot/assets/levels/ELEV16.yaml` |
| Level YAML | `godot/assets/levels/ELEV17.yaml` |
| Level YAML | `godot/assets/levels/ELEV24.yaml` |
| Level YAML | `godot/assets/levels/ELEV26.yaml` |
| Level YAML | `godot/assets/levels/ELEV5.yaml` |
| ... | +49 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART21.json` + `build/phase-5/yaml/`*
