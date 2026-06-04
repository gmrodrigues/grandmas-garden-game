# Part 9 — Basketball

## Identity

| Field | Value |
|-------|-------|
| Part Type | `9` |
| Category | Balls |
| Description | This basketball is medium in weight and very bouncy. |
| ANM File | `PART9.ANM` → `build/phase-4/anm/PART9.json` |
| BMP Resource | `PART9.BMP` → `build/phase-3/bitmaps/PART9_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**21 level(s)** use this part type:

- `build/phase-5/yaml/ELEV13.yaml` → `godot/assets/levels/ELEV13.yaml`
- `build/phase-5/yaml/ELEV20.yaml` → `godot/assets/levels/ELEV20.yaml`
- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`
- `build/phase-5/yaml/HH1.yaml` → `godot/assets/levels/HH1.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV18.yaml` → `godot/assets/levels/RLEV18.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/RLEV27.yaml` → `godot/assets/levels/RLEV27.yaml`
- `build/phase-5/yaml/RLEV28.yaml` → `godot/assets/levels/RLEV28.yaml`
- `build/phase-5/yaml/TLEV1.yaml` → `godot/assets/levels/TLEV1.yaml`
- `build/phase-5/yaml/TLEV16.yaml` → `godot/assets/levels/TLEV16.yaml`
- `build/phase-5/yaml/TLEV23.yaml` → `godot/assets/levels/TLEV23.yaml`
- `build/phase-5/yaml/TLEV3.yaml` → `godot/assets/levels/TLEV3.yaml`
- `build/phase-5/yaml/TLEV7.yaml` → `godot/assets/levels/TLEV7.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1322 | mass/density (relative scale) |
| `damping` | 20 | drag/air-resistance or density |
| `cor_q8` | 192 | COR = 0.750 |
| `radius` | 16 | collision radius in internal units |
| `sprite_w` | 240 | sprite width |
| `sprite_h` | 240 | sprite height |
| `data_offset` | 32 | offset to per-state data or count |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `trap` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 9 |

## State Machine

*Single default state — no named transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 17 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `3` | 0 | 0 | 32×32 | 0 |
| `4` | 1 | 1–16 (16 frames) | 32×32 | 7 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART9_f000.png :material-check:` |
| 1 | `0001_0000` | `build/phase-3/bitmaps/PART9_f000.png :material-check:` |
| 2 | `0001_0001` | `build/phase-3/bitmaps/PART9_f001.png :material-check:` |
| 3 | `0001_0002` | `build/phase-3/bitmaps/PART9_f002.png :material-check:` |
| 4 | `0001_0003` | `build/phase-3/bitmaps/PART9_f003.png :material-check:` |
| 5 | `0001_0004` | `build/phase-3/bitmaps/PART9_f004.png :material-check:` |
| 6 | `0001_0005` | `build/phase-3/bitmaps/PART9_f005.png :material-check:` |
| 7 | `0001_0006` | `build/phase-3/bitmaps/PART9_f006.png :material-check:` |
| 8 | `0001_0007` | `build/phase-3/bitmaps/PART9_f007.png :material-check:` |
| 9 | `0001_0008` | `build/phase-3/bitmaps/PART9_f008.png :material-check:` |
| 10 | `0001_0010` | `build/phase-3/bitmaps/PART9_f010.png :material-check:` |
| 11 | `0001_0011` | `build/phase-3/bitmaps/PART9_f011.png :material-check:` |
| 12 | `0001_0012` | `build/phase-3/bitmaps/PART9_f012.png :material-check:` |
| 13 | `0001_0013` | `build/phase-3/bitmaps/PART9_f013.png :material-check:` |
| 14 | `0001_0014` | `build/phase-3/bitmaps/PART9_f014.png :material-check:` |
| 15 | `0001_0015` | `build/phase-3/bitmaps/PART9_f015.png :material-check:` |
| 16 | `0001_0009` | `build/phase-3/bitmaps/PART9_f009.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 17 |
| `END_FRAME` | 17 |
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

**Basketball** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART9.json` |
| Sprite PNGs | `godot/assets/sprites/PART9_f*.png` |
| Level YAML | `godot/assets/levels/ELEV13.yaml` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| Level YAML | `godot/assets/levels/HH1.yaml` |
| Level YAML | `godot/assets/levels/HH26.yaml` |
| ... | +16 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART9.json` + `build/phase-5/yaml/`*
