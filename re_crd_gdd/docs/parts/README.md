# TIM2 Part Behavior — Complete Reference

Clean-room specification for all 147 part types in The Incredible Machine 2.
Auto-generated from reverse-engineered binary data. Validated against the Python
reference editor (`tim2_editor/`).

## Quick Navigation

### By Category

| Category | Count | Parts |
|----------|-------|-------|
| [Balls](#balls) | 9 | 0, 9, 28, 43, 44, 59, 63, 68, 87 |
| [Walls / Floors](#walls--floors) | 15 | 1, 48, 56, 60, 82, 83, 84, 85, 100–106, 125 |
| [Inclines](#inclines) | 6 | 2, 99–102, 126 |
| [Special Mechanics](#special-mechanics) | 15 | 3, 13, 15, 17, 22, 23, 30, 35, 45, 62, 66, 71, 73, 88, 139 |
| [Balloons / Airships](#balloons--airships) | 3 | 4, 79, 109 |
| [Rotating Power Sources](#rotating-power-sources) | 7 | 5, 6, 14, 31, 40, 50, 86 |
| [Ropes / Belts / Pulleys](#ropes--belts--pulleys) | 4 | 7, 8, 10, 76 |
| [Containers](#containers) | 5 | 11, 52, 64, 72, 90 |
| [Characters](#characters) | 8 | 12, 32, 33, 34, 42, 54, 61, 65 |
| [Springs / Pneumatics](#springs--pneumatics) | 7 | 16, 39, 75, 89, 97, 98, 107 |
| [Explosives / Projectiles](#explosives--projectiles) | 10 | 18, 19, 20, 27, 36, 41, 55, 70, 74, 80 |
| [Electrical](#electrical) | 9 | 21, 24, 25, 26, 38, 51, 67, 81, 120 |
| [Light / Flame Sources](#light--flame-sources) | 5 | 29, 78, 108, 136, 138 |
| [Lasers / Optics](#lasers--optics) | 8 | 30, 91–96, 148 |
| [Cutting / Popping](#cutting--popping) | 3 | 37, 53, 77 |
| [Created / Phantom](#created--phantom) | 1 | 72 |
| [Pipe Systems](#pipe-systems) | 4 | 46, 47, 57, 97 |
| [Scenery](#scenery) | 26 | 58, 69, 110–115, 121–124, 128–135, 140–147 |
| [Pool Table](#pool-table) | 2 | 116–119 |

### By Part Type

| Part | Name | Category | Interactive | File |
|------|------|----------|-------------|------|
| 0 | Bowling Ball | Balls | No | [part-000-bowling-ball.md](part-000-bowling-ball.md) |
| 1 | Brick Wall | Walls / Floors | No | [part-001-brick-wall.md](part-001-brick-wall.md) |
| 2 | Wood incline | Inclines | No | [part-002-wood-incline.md](part-002-wood-incline.md) |
| 3 | Tipsy Trailer | Special Mechanics | No | [part-003-tipsy-trailer.md](part-003-tipsy-trailer.md) |
| 4 | Balloon | Balloons / Airships | Yes | [part-004-balloon.md](part-004-balloon.md) |
| 5 | Conveyor Belt | Rotating Power Sources | No | [part-005-conveyor-belt.md](part-005-conveyor-belt.md) |
| 6 | Mouse Motor | Rotating Power Sources | Yes | [part-006-mouse-motor.md](part-006-mouse-motor.md) |
| 7 | Pulley | Ropes / Belts / Pulleys | No | [part-007-pulley.md](part-007-pulley.md) |
| 8 | Belt | Ropes / Belts / Pulleys | No | [part-008-belt.md](part-008-belt.md) |
| 9 | Basketball | Balls | No | [part-009-basketball.md](part-009-basketball.md) |
| 10 | Rope | Ropes / Belts / Pulleys | No | [part-010-rope.md](part-010-rope.md) |
| 11 | Laundry Basket | Containers | No | [part-011-laundry-basket.md](part-011-laundry-basket.md) |
| 12 | Curie Cat | Characters | Yes | [part-012-curie-cat.md](part-012-curie-cat.md) |
| 13 | Jack-in-the-Box | Special Mechanics | Yes | [part-013-jack-in-the-box.md](part-013-jack-in-the-box.md) |
| 14 | Gear | Rotating Power Sources | No | [part-014-gear.md](part-014-gear.md) |
| 15 | Fish Tank | Special Mechanics | Yes | [part-015-fish-tank.md](part-015-fish-tank.md) |
| 16 | Bike Pump | Springs / Pneumatics | Yes | [part-016-bike-pump.md](part-016-bike-pump.md) |
| 17 | Bucket | Special Mechanics | No | [part-017-bucket.md](part-017-bucket.md) |
| 18 | Cannon | Explosives / Projectiles | Yes | [part-018-cannon.md](part-018-cannon.md) |
| 19 | Dynamite | Explosives / Projectiles | Yes | [part-019-dynamite.md](part-019-dynamite.md) |
| 20 | Phazer Pulse | Explosives / Projectiles | No | [part-020-phazer-pulse.md](part-020-phazer-pulse.md) |
| 21 | Electric Switch & Outlet | Electrical | Yes | [part-021-electric-switch-&-outlet.md](part-021-electric-switch-&-outlet.md) |
| 22 | Remote Control | Special Mechanics | Yes | [part-022-remote-control.md](part-022-remote-control.md) |
| 23 | Boat Cleat | Special Mechanics | No | [part-023-boat-cleat.md](part-023-boat-cleat.md) |
| 24 | Electric Fan | Electrical | Yes | [part-024-electric-fan.md](part-024-electric-fan.md) |
| 25 | Flashlight | Electrical | Yes | [part-025-flashlight.md](part-025-flashlight.md) |
| 26 | Generator | Electrical | Yes | [part-026-generator.md](part-026-generator.md) |
| 27 | Captain Z Super Phazer | Explosives / Projectiles | Yes | [part-027-captain-z-super-phazer.md](part-027-captain-z-super-phazer.md) |
| 28 | Baseball | Balls | No | [part-028-baseball.md](part-028-baseball.md) |
| 29 | Lava Lamp | Light / Flame Sources | Yes | [part-029-lava-lamp.md](part-029-lava-lamp.md) |
| 30 | Magnifying Glass | Light / Flame Sources | No | [part-030-magnifying-glass.md](part-030-magnifying-glass.md) |

... [remaining parts omitted for brevity — full index at bottom of each per-part file]

## Per-File Structure

Each `part-NNN-name.md` contains:

1. **Identity** — Part type, category, description, ANM/BMP resource references
2. **Levels Using This Part** — All built-in levels from `build/phase-5/yaml/`
3. **Physics Properties** — Mass, COR, friction, collision data, gravity category
4. **Category Rules** — Trigger types, destructible flag, spawn behavior
5. **State Machine** — SOLVE.RES state transitions (self→other triggers, ANM state, explosive flag)
6. **ANM Animation** — Frame/states count, Section A durations, state→frame mapping
7. **Frame Sprite Details** — Per-frame sprite references with PNG existence check
8. **Sound Effects** — Per-frame sound IDs with WAV references
9. **Bytecode Opcodes** — Summary of Section D commands
10. **Connections & Capabilities** — Electrical, belt, rope, fire, laser, projectile
11. **Behavior Notes** — Human-readable behavior description
12. **Godot Data Sources** — All asset paths for a Godot implementation

## Asset Path Conventions

| Asset Type | Source Directory | Godot Target |
|------------|-----------------|--------------|
| Sprite PNGs | `build/phase-3/bitmaps/{BMP}_f{NNN}.png` | `godot/assets/sprites/` |
| Palette JSON | `build/phase-3/palettes/{name}.json` | `godot/assets/palettes/` |
| ANM JSON | `build/phase-4/anm/{ANM}.json` | `godot/assets/anm/` |
| Level YAML | `build/phase-5/yaml/{LEVEL}.yaml` | `godot/assets/levels/` |
| Sound WAV | `build/phase-6/raw-wav/SX_{ID}_11025.wav` | `godot/assets/sounds/` |
| Behavior JSON | `build/phase-16/godot/behaviors.json` | `godot/assets/data/` |
| Properties JSON | `build/phase-9/part-properties.json` | `godot/assets/data/` |

## Validation

- **Generated by**: `scripts/phase-17/01-generate-part-specs.py`
- **Validated by**: `scripts/phase-17/02-validate-part-specs.py` — 2,406 checks, 0 failures
- **Editor reference**: `tim2_editor/` — Python reference implementation (the game)
- **Report**: `build/phase-17/validation-report.json`

## Status Legend

| Icon | Meaning |
|------|---------|
| `:material-check:` | PNG file exists on disk |
| `:material-alert-outline:` | PNG file not found (may use different resource ID) |
| `:material-bomb:` | Explosive state — destroys the part |

## See Also

- `docs/game-architecture-specification.md` — High-level game architecture
- `docs/godot-specification.md` — Godot implementation specification
- `docs/experiments/` — Lab notebooks and findings reports
- `MILESTONES.md` — Project milestone tracker
