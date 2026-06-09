## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-070-missile.md` describes part type `70`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 70`

### TC-002: Mass value is positive
- **Given** Missile has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Missile has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 0.500`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** missile responds to fuse ignition

### TC-006: Projectile connection supported
- **Given** Connections & Capabilities shows `Projectile: Yes`
- **When** behavior handler evaluates
- **Then** projectile spawn behavior is enabled

### TC-007: SOLVE.RES state transitions (Not Launched → Launched → Exploded)
- **Given** Missile has states: Not Launched (`2→8`, `13→14`, `18→19`), Launched (`3→12`, `16→17`, `21→22`), Exploded (`12→13`, `17→18`, `22→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-008: Exploded state is explosive
- **Given** State Machine shows `Exploded` as explosive
- **When** state reaches Exploded
- **Then** explosion damages nearby parts

### TC-009: Terminal state Exploded (part removed)
- **Given** State Machine shows `Exploded: 22→-1`
- **When** state reaches Exploded
- **Then** part is removed from simulation (terminal)

### TC-010: Destructible flag is Yes
- **Given** Category Rules show `Destructible: Yes`
- **When** explosive part collides
- **Then** missile can be destroyed by other explosives

### TC-011: Spawns projectile
- **Given** Category Rules show `Spawns: projectile`
- **When** trigger activates missile
- **Then** projectile part instance is spawned

### TC-012: Part used in 23 levels
- **Given** Missile (type 70)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 23 levels reference `part_num = 70`

### TC-013: Explosives / Projectiles category (Category Part Count = 10)
- **Given** Category Rules show `Category Part Count: 10`
- **When** validated
- **Then** 10 parts in Explosives / Projectiles category

### TC-014: Animated (Section A) — 103 duration entries
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 103 entries`
- **When** animation renderer processes frame timing
- **Then** Section A durations control playback at 60 Hz

### TC-015: 93 total animation frames across 15 states
- **Given** ANM shows `Total Frames: 93`, `Total States: 15`
- **When** animation renderer processes
- **Then** all 93 frames map to correct states

### TC-016: Fuse ignition sources (laser, phazer, flame, magnifying glass)
- **Given** Description: "Light the fuse with a laser, a phazer, a candle (or other flaming part), or by using a magnifying glass and light source"
- **When** any valid ignition source contacts fuse
- **Then** missile enters Launched state
