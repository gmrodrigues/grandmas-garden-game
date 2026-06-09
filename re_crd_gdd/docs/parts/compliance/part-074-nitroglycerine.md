## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-074-nitroglycerine.md` describes part type `74`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 74`

### TC-002: Mass value is positive
- **Given** Nitroglycerine has `mass = 2200`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Nitroglycerine has `property_q8 = 64`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 0.250`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** nitroglycerine responds to collision/proximity triggers

### TC-006: Projectile connection supported
- **Given** Connections & Capabilities shows `Projectile: Yes`
- **When** behavior handler evaluates
- **Then** projectile spawn behavior is enabled

### TC-007: SOLVE.RES state transitions (Unexploded → Exploded)
- **Given** Nitroglycerine has states: Unexploded (`1→3`) and Exploded (`3→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-008: Exploded state is explosive
- **Given** State Machine shows `Exploded` as explosive
- **When** state reaches Exploded
- **Then** explosion damages nearby parts

### TC-009: Terminal state Exploded (part removed)
- **Given** State Machine shows `Exploded: 3→-1`
- **When** state reaches Exploded
- **Then** part is removed from simulation (terminal)

### TC-010: Destructible flag is Yes
- **Given** Category Rules show `Destructible: Yes`
- **When** explosive part collides
- **Then** nitroglycerine can be destroyed by other explosives

### TC-011: Spawns projectile
- **Given** Category Rules show `Spawns: projectile`
- **When** trigger activates nitroglycerine
- **Then** projectile part instance is spawned

### TC-012: Part used in 38 levels
- **Given** Nitroglycerine (type 74)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 38 levels reference `part_num = 74`

### TC-013: Explosives / Projectiles category (Category Part Count = 10)
- **Given** Category Rules show `Category Part Count: 10`
- **When** validated
- **Then** 10 parts in Explosives / Projectiles category

### TC-014: Animated (Section A) — 14 duration entries
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 14 entries`
- **When** animation renderer processes frame timing
- **Then** Section A durations control playback at 60 Hz

### TC-015: Explodes on bump or drop with sufficient force
- **Given** Description: "This tube of nitroglycerine will explode if it's bumped or dropped with enough force"
- **When** collision or fall produces sufficient impact energy
- **Then** nitroglycerine transitions to Exploded state
