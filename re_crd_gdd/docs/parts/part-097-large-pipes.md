# Part 97 — Large Pipes

## Identity

| Field | Value |
|-------|-------|
| Part Type | `97` |
| Category | Pipe Systems |
| Description | Connect sections of this large pipe together and drop balls or other things inside. Attach sections of curved pipe and t-connectors to control the direction that objects go. You can also attach an accelerator tube to speed up or reverse the direction of objects moving through the pipes. |
| ANM File | `PART97.ANM` → `build/phase-4/anm/PART97.json` |
| BMP Resource | `PART97.BMP` → `build/phase-3/bitmaps/PART97_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**16 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV22.yaml` → `godot/assets/levels/ELEV22.yaml`
- `build/phase-5/yaml/ELEV6.yaml` → `godot/assets/levels/ELEV6.yaml`
- `build/phase-5/yaml/HH1.yaml` → `godot/assets/levels/HH1.yaml`
- `build/phase-5/yaml/HH2.yaml` → `godot/assets/levels/HH2.yaml`
- `build/phase-5/yaml/HH3.yaml` → `godot/assets/levels/HH3.yaml`
- `build/phase-5/yaml/HH39.yaml` → `godot/assets/levels/HH39.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HH9.yaml` → `godot/assets/levels/HH9.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV6.yaml` → `godot/assets/levels/HLEV6.yaml`
- `build/phase-5/yaml/MLEV4.yaml` → `godot/assets/levels/MLEV4.yaml`
- `build/phase-5/yaml/MLEV7.yaml` → `godot/assets/levels/MLEV7.yaml`
- `build/phase-5/yaml/RLEV3.yaml` → `godot/assets/levels/RLEV3.yaml`
- `build/phase-5/yaml/RLEV7.yaml` → `godot/assets/levels/RLEV7.yaml`
- `build/phase-5/yaml/TLEV21.yaml` → `godot/assets/levels/TLEV21.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 48 | dimension 1 width |
| `dim_h1` | 48 | dimension 1 height |
| `dim_w2` | 576 | dimension 2 width |
| `dim_h2` | 416 | dimension 2 height |
| `bitmap_w` | 16 | bitmap frame width |
| `bitmap_h` | 38 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 4 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 6 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–2 (3 frames) | 16×38 | 0 |
| `2` | 3 | 3–5 (3 frames) | 40×16 | 21 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART97_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART97_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART97_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART97_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART97_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART97_f005.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 6 |
| `END_FRAME` | 6 |
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

**Large Pipes** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART97.json` |
| Sprite PNGs | `godot/assets/sprites/PART97_f*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV22.yaml` |
| Level YAML | `godot/assets/levels/ELEV6.yaml` |
| Level YAML | `godot/assets/levels/HH1.yaml` |
| Level YAML | `godot/assets/levels/HH2.yaml` |
| ... | +11 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART97.json` + `build/phase-5/yaml/`*
