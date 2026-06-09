## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-080-fireworks.md` describes part type `80`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 80`

### TC-002: Mass value is positive
- **Given** Fireworks has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Fireworks has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 0.500`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** fireworks respond to fuse ignition

### TC-006: Projectile connection supported
- **Given** Connections & Capabilities shows `Projectile: Yes`
- **When** behavior handler evaluates
- **Then** projectile spawn behavior is enabled

### TC-007: SOLVE.RES state transitions (Not Set Off → Set Off)
- **Given** Fireworks has states: Not Set Off (`9→19`, `12→20`, `16→21`) and Set Off (`6→12`, `7→16`, `8→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-008: Terminal state Set Off (part removed)
- **Given** State Machine shows `Set Off: 8→-1`
- **When** state reaches Set Off
- **Then** part is removed from simulation (terminal)

### TC-009: Triggers are collision, proximity, timer
- **Given** Category Rules show `Triggers: collision, proximity, timer`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-010: Part used in 17 levels
- **Given** Fireworks (type 80)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 17 levels reference `part_num = 80`

### TC-011: Explosives / Projectiles category (Category Part Count = 10)
- **Given** Category Rules show `Category Part Count: 10`
- **When** validated
- **Then** 10 parts in Explosives / Projectiles category

### TC-012: Destructible flag is Yes
- **Given** Category Rules show `Destructible: Yes`
- **When** explosive part collides
- **Then** fireworks can be destroyed

### TC-013: Spawns projectile
- **Given** Category Rules show `Spawns: projectile`
- **When** trigger activates fireworks
- **Then** projectile part instance is spawned

### TC-014: Animated (Section A) — 147 duration entries
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 147 entries`
- **When** animation renderer processes frame timing
- **Then** Section A durations control playback at 60 Hz

### TC-015: 135 total animation frames across 15 states
- **Given** ANM shows `Total Frames: 135`, `Total States: 15`
- **When** animation renderer processes
- **Then** all 135 frames map to correct states

### TC-016: Three programmable firework displays
- **Given** Description: "This part lets you choose between three different types of fireworks displays"
- **When** player programs firework type
- **Then** correct ANM state sequence is selected
