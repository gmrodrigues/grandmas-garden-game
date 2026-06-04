# Part 41 — explosion

## Identity

| Field | Value |
|-------|-------|
| Part Type | `41` |
| Category | Created / Phantom |
| Description | [CREATED PART] |
| ANM File | `PART41.ANM` → `build/phase-4/anm/PART41.json` |
| BMP Resource | `PART41.BMP` → `build/phase-3/bitmaps/PART41_f*.png` |
| Created Part | Yes |
| Interactive | No |

## Levels Using This Part

*This part is not used in any built-in level (may be created dynamically at runtime).*

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `unk_2` | 1 | scenery property (900 for trees, 1100-1200 for clouds/sun) |
| `bitmap_w` | 70 | bitmap frame width |
| `bitmap_h` | 66 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | *(none)* |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 1 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 3 |
| Total States | 1 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 0 | 0–2 (3 frames) | 72×66 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0002` | `build/phase-3/bitmaps/PART41_f002.png :material-check:` |
| 1 | `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART41_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART41_f000.png :material-check:` |
| 2 | `0001_0001`, `0001_0002` | `build/phase-3/bitmaps/PART41_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART41_f002.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 0 | `3211` | 0 | `build/phase-6/raw-wav/SX_3211_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 5 |
| `PLAY_SFX` | 1 |
| `END_FRAME` | 3 |
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

**explosion** is a dynamically created (phantom) part. It is not placed by the player but spawned at runtime by another part's behavior (e.g., explosion debris, laser beam, rope end phantom).

**explosion** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART41.json` |
| Sprite PNGs | `godot/assets/sprites/PART41_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART41.json` + `build/phase-5/yaml/`*
