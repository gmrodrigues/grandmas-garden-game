# Part 11 — Laundry Basket

## Identity

| Field | Value |
|-------|-------|
| Part Type | `11` |
| Category | Containers |
| Description | Use this laundry basket to trap Curie Cat, Newton Mouse, or Mel Schlemming. Tie one end of a rope to the laundry basket, and tie the other end to another part (like a bucket or teeter-totter). |
| ANM File | `PART11.ANM` → `build/phase-4/anm/PART11.json` |
| BMP Resource | `PART11.BMP` → `build/phase-3/bitmaps/PART11_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**12 level(s)** use this part type:

- `build/phase-5/yaml/ELEV14.yaml` → `godot/assets/levels/ELEV14.yaml`
- `build/phase-5/yaml/HH15.yaml` → `godot/assets/levels/HH15.yaml`
- `build/phase-5/yaml/HH29.yaml` → `godot/assets/levels/HH29.yaml`
- `build/phase-5/yaml/HH36.yaml` → `godot/assets/levels/HH36.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV2.yaml` → `godot/assets/levels/RLEV2.yaml`
- `build/phase-5/yaml/RLEV24.yaml` → `godot/assets/levels/RLEV24.yaml`
- `build/phase-5/yaml/RLEV28.yaml` → `godot/assets/levels/RLEV28.yaml`
- `build/phase-5/yaml/RLEV9.yaml` → `godot/assets/levels/RLEV9.yaml`
- `build/phase-5/yaml/TLEV37.yaml` → `godot/assets/levels/TLEV37.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 4000 | mass/density (relative scale) |
| `unk_2` | 70 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 64 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 64 | bitmap frame width |
| `bitmap_h` | 62 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 5 |

## State Machine

*Single default state — no named transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 2 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `6` | 0 | 0 | 64×62 | 0 |
| `5` | 1 | 1 | 64×62 | 13 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART11_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART11_f001.png :material-check:` |
| 1 | `0001_0000` | `build/phase-3/bitmaps/PART11_f000.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 3 |
| `END_FRAME` | 2 |
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

**Laundry Basket** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART11.json` |
| Sprite PNGs | `godot/assets/sprites/PART11_f*.png` |
| Level YAML | `godot/assets/levels/ELEV14.yaml` |
| Level YAML | `godot/assets/levels/HH15.yaml` |
| Level YAML | `godot/assets/levels/HH29.yaml` |
| Level YAML | `godot/assets/levels/HH36.yaml` |
| Level YAML | `godot/assets/levels/HH41.yaml` |
| ... | +7 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART11.json` + `build/phase-5/yaml/`*
