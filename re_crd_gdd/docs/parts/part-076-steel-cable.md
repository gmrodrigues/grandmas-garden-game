# Part 76 — Steel Cable

## Identity

| Field | Value |
|-------|-------|
| Part Type | `76` |
| Category | Ropes / Belts / Pulleys |
| Description | This steel cable works just like rope, except it's much stronger. It can only be cut with tin snips. To use the steel cable:  pull it out of the Parts Bin onto the screen. Click on the first object you want tied, then drag the cursor over the second object. When the line turns from red to green the cable is in position. Click again to attach it. |
| ANM File | `PART76.ANM` → `build/phase-4/anm/PART76.json` |
| BMP Resource | `PART76.BMP` → `build/phase-3/bitmaps/PART76_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**14 level(s)** use this part type:

- `build/phase-5/yaml/ELEV9.yaml` → `godot/assets/levels/ELEV9.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH6.yaml` → `godot/assets/levels/HH6.yaml`
- `build/phase-5/yaml/HLEV16.yaml` → `godot/assets/levels/HLEV16.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- `build/phase-5/yaml/RLEV18.yaml` → `godot/assets/levels/RLEV18.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`
- `build/phase-5/yaml/TLEV33.yaml` → `godot/assets/levels/TLEV33.yaml`
- `build/phase-5/yaml/TLEV4.yaml` → `godot/assets/levels/TLEV4.yaml`
- `build/phase-5/yaml/TLEV7.yaml` → `godot/assets/levels/TLEV7.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1600 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `property_q8` | 0 | Q8.8 = 0.000 |
| `unk_6` | 0 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 11 | bitmap frame width |
| `bitmap_h` | 10 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | *(none)* |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 4 |

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
| `1` | 0 | 0 | 24×15 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART76.png :material-check:` |

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
| Belt Connection | Yes |
| Rope Connection | Yes |
| Fire/Flame | No |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Steel Cable** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART76.json` |
| Sprite PNGs | `godot/assets/sprites/PART76_f*.png` |
| Level YAML | `godot/assets/levels/ELEV9.yaml` |
| Level YAML | `godot/assets/levels/HH42.yaml` |
| Level YAML | `godot/assets/levels/HH6.yaml` |
| Level YAML | `godot/assets/levels/HLEV16.yaml` |
| Level YAML | `godot/assets/levels/HLEV5.yaml` |
| ... | +9 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART76.json` + `build/phase-5/yaml/`*
