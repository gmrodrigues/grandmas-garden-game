# Part 7 — Pulley

## Identity

| Field | Value |
|-------|-------|
| Part Type | `7` |
| Category | Ropes / Belts / Pulleys |
| Description | You can place this pulley between any two parts that may be connected by rope or cable. For example: tie one end of a rope to an object (a laundry basket for instance), then run the rope over as many pulleys as necessary (click on each pulley), and tie the other end of the rope to another part, such as the phazer. When you run the puzzle, the laundry basket will fall, pulling the rope, which will pull the trigger and fire the phazer. |
| ANM File | `PART7.ANM` → `build/phase-4/anm/PART7.json` |
| BMP Resource | `PART7.BMP` → `build/phase-3/bitmaps/PART7_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**91 level(s)** use this part type:

- `build/phase-5/yaml/ELEV16.yaml` → `godot/assets/levels/ELEV16.yaml`
- `build/phase-5/yaml/ELEV17.yaml` → `godot/assets/levels/ELEV17.yaml`
- `build/phase-5/yaml/ELEV19.yaml` → `godot/assets/levels/ELEV19.yaml`
- `build/phase-5/yaml/ELEV20.yaml` → `godot/assets/levels/ELEV20.yaml`
- `build/phase-5/yaml/ELEV23.yaml` → `godot/assets/levels/ELEV23.yaml`
- `build/phase-5/yaml/ELEV24.yaml` → `godot/assets/levels/ELEV24.yaml`
- `build/phase-5/yaml/ELEV25.yaml` → `godot/assets/levels/ELEV25.yaml`
- `build/phase-5/yaml/ELEV26.yaml` → `godot/assets/levels/ELEV26.yaml`
- `build/phase-5/yaml/ELEV9.yaml` → `godot/assets/levels/ELEV9.yaml`
- `build/phase-5/yaml/HH10.yaml` → `godot/assets/levels/HH10.yaml`
- `build/phase-5/yaml/HH14.yaml` → `godot/assets/levels/HH14.yaml`
- `build/phase-5/yaml/HH16.yaml` → `godot/assets/levels/HH16.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH18.yaml` → `godot/assets/levels/HH18.yaml`
- `build/phase-5/yaml/HH20.yaml` → `godot/assets/levels/HH20.yaml`
- `build/phase-5/yaml/HH22.yaml` → `godot/assets/levels/HH22.yaml`
- `build/phase-5/yaml/HH23.yaml` → `godot/assets/levels/HH23.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HH27.yaml` → `godot/assets/levels/HH27.yaml`
- `build/phase-5/yaml/HH29.yaml` → `godot/assets/levels/HH29.yaml`
- `build/phase-5/yaml/HH3.yaml` → `godot/assets/levels/HH3.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH34.yaml` → `godot/assets/levels/HH34.yaml`
- `build/phase-5/yaml/HH35.yaml` → `godot/assets/levels/HH35.yaml`
- `build/phase-5/yaml/HH36.yaml` → `godot/assets/levels/HH36.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH39.yaml` → `godot/assets/levels/HH39.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- ... and 61 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 3776 | mass/density (relative scale) |
| `unk_2` | 999 | category-specific property |
| `property_q8` | 0 | Q8.8 = 0.000 |
| `unk_6` | 0 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 22 | bitmap frame width |
| `bitmap_h` | 24 | bitmap frame height |

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
| Total Frames | 4 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `4` | 0 | 0 | 24×22 | 0 |
| `3` | 1 | 1–3 (3 frames) | 24×19 | 7 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART7_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART7_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART7_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART7_f003.png :material-check:` |

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
| Belt Connection | Yes |
| Rope Connection | Yes |
| Fire/Flame | No |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Pulley** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART7.json` |
| Sprite PNGs | `godot/assets/sprites/PART7_f*.png` |
| Level YAML | `godot/assets/levels/ELEV16.yaml` |
| Level YAML | `godot/assets/levels/ELEV17.yaml` |
| Level YAML | `godot/assets/levels/ELEV19.yaml` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| Level YAML | `godot/assets/levels/ELEV23.yaml` |
| ... | +86 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART7.json` + `build/phase-5/yaml/`*
