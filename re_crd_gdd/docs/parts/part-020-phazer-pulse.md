# Part 20 — Phazer pulse

## Identity

| Field | Value |
|-------|-------|
| Part Type | `20` |
| Category | Explosives / Projectiles |
| Description | [CREATED PART] |
| ANM File | `PART20.ANM` → `build/phase-4/anm/PART20.json` |
| BMP Resource | `PART20.BMP` → `build/phase-3/bitmaps/PART20_f*.png` |
| Created Part | Yes |
| Interactive | No |

## Levels Using This Part

*This part is not used in any built-in level (may be created dynamically at runtime).*

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `unk_2` | 20000 | scenery property (900 for trees, 1100-1200 for clouds/sun) |
| `bitmap_w` | 16 | bitmap frame width |
| `bitmap_h` | 4 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `proximity`, `timer` |
| Destructible | Yes |
| Spawns | `projectile` |
| Category Part Count | 10 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 7 |
| Total States | 1 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–6 (7 frames) | 24×12 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART20_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART20_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART20_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART20_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART20_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART20_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART20_f006.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 7 |
| `END_FRAME` | 7 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | No |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | No |
| Laser | No |
| Projectile | Yes |

## Behavior Notes

**Phazer pulse** is a dynamically created (phantom) part. It is not placed by the player but spawned at runtime by another part's behavior (e.g., explosion debris, laser beam, rope end phantom).

**Phazer pulse** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

This part spawns a **projectile** (cannonball, rocket, missile) when triggered. The projectile is a separate part instance.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART20.json` |
| Sprite PNGs | `godot/assets/sprites/PART20_f*.png` |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART20.json` + `build/phase-5/yaml/`*
