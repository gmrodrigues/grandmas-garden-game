# Part 138 — Candle

## Identity

| Field | Value |
|-------|-------|
| Part Type | `138` |
| Category | Light / Flame Sources |
| Description | This candle can be lit with a laser beam, a phazer, another flaming part (like a rocket or an oil lamp), or with a magnifying glass and light source. Use it to light fuses, make the coffee pot percolate, or pop blimps and balloons. |
| ANM File | `PART138.ANM` → `build/phase-4/anm/PART138.json` |
| BMP Resource | `PART138.BMP` → `build/phase-3/bitmaps/PART138_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**26 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV19.yaml` → `godot/assets/levels/ELEV19.yaml`
- `build/phase-5/yaml/ELEV25.yaml` → `godot/assets/levels/ELEV25.yaml`
- `build/phase-5/yaml/HH14.yaml` → `godot/assets/levels/HH14.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH22.yaml` → `godot/assets/levels/HH22.yaml`
- `build/phase-5/yaml/HH27.yaml` → `godot/assets/levels/HH27.yaml`
- `build/phase-5/yaml/HH29.yaml` → `godot/assets/levels/HH29.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH34.yaml` → `godot/assets/levels/HH34.yaml`
- `build/phase-5/yaml/HH35.yaml` → `godot/assets/levels/HH35.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HLEV14.yaml` → `godot/assets/levels/HLEV14.yaml`
- `build/phase-5/yaml/HLEV2.yaml` → `godot/assets/levels/HLEV2.yaml`
- `build/phase-5/yaml/HLEV23.yaml` → `godot/assets/levels/HLEV23.yaml`
- `build/phase-5/yaml/HLEV25.yaml` → `godot/assets/levels/HLEV25.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/MLEV12.yaml` → `godot/assets/levels/MLEV12.yaml`
- `build/phase-5/yaml/MLEV22.yaml` → `godot/assets/levels/MLEV22.yaml`
- `build/phase-5/yaml/MLEV9.yaml` → `godot/assets/levels/MLEV9.yaml`
- `build/phase-5/yaml/RLEV11.yaml` → `godot/assets/levels/RLEV11.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`
- `build/phase-5/yaml/TLEV14.yaml` → `godot/assets/levels/TLEV14.yaml`
- `build/phase-5/yaml/TLEV8.yaml` → `godot/assets/levels/TLEV8.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2000 | mass/density (relative scale) |
| `unk_2` | 45 | category-specific property |
| `property_q8` | 54 | Q8.8 = 0.211 |
| `unk_6` | 28 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 24 | bitmap frame width |
| `bitmap_h` | 33 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `proximity`, `electrical` |
| Destructible | No |
| Spawns | `fire` |
| Category Part Count | 5 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Unlit | `1→2` | 1 | No |
| Lit | `2→-1` | 2 | No |

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
| `1` | 0 | 0 | 24×33 | 0 |
| `2` | 1 | 1–5 (5 frames) | 24×39 | 7 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART138.png :material-check:` |
| 1 | `0001_0000`, `0002_0005` | `build/phase-3/bitmaps/PART138.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f005.png :material-check:` |
| 2 | `0001_0000`, `0002_0006` | `build/phase-3/bitmaps/PART138.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f006.png :material-check:` |
| 3 | `0001_0000`, `0002_0007` | `build/phase-3/bitmaps/PART138.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f007.png :material-check:` |
| 4 | `0001_0000`, `0002_0008` | `build/phase-3/bitmaps/PART138.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f008.png :material-check:` |
| 5 | `0001_0000`, `0002_0009` | `build/phase-3/bitmaps/PART138.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f009.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 11 |
| `END_FRAME` | 6 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | Yes |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | Yes |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Candle** has 2 semantic states: Unlit, Lit. Transitions are triggered by: proximity, electrical.

Terminal state(s): Lit (part is removed from simulation).

This part can ignite nearby combustible parts (balloons, explosives). Uses proximity trigger.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART138.json` |
| Sprite PNGs | `godot/assets/sprites/PART138_f*.png` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV19.yaml` |
| Level YAML | `godot/assets/levels/ELEV25.yaml` |
| Level YAML | `godot/assets/levels/HH14.yaml` |
| ... | +21 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART138.json` + `build/phase-5/yaml/`*
