## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-036-rocket.md` describes part type `36`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 36`

### TC-002: Mass value is positive
- **Given** Rocket has `mass = 18000`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Rocket has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: SOLVE.RES state transitions (Not Fired → Fired)
- **Given** Rocket has 2 states: Not Fired (`2→17`, `12→18`, `25→21`) and Fired (`8→12`, `15→25`, `24→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Terminal state Fired (part removed)
- **Given** State Machine shows `Fired: 24→-1`
- **When** state reaches Fired
- **Then** part is removed from simulation (terminal)

### TC-006: Destructible flag is Yes
- **Given** Category Rules show `Destructible: Yes`
- **When** explosive part collides
- **Then** rocket is destroyed

### TC-007: Spawns projectile
- **Given** Category Rules show `Spawns: projectile`
- **When** rocket is triggered
- **Then** projectile is spawned as separate part instance

### TC-008: Triggers include collision, proximity, timer
- **Given** Category Rules show `Triggers: collision, proximity, timer`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-009: Part used in 24 levels
- **Given** Rocket (type 36)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 24 levels reference `part_num = 36`

### TC-010: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-011: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** rocket can be flipped to change direction

### TC-012: Multiple ignition sources
- **Given** Description: "You can light the fuse with a candle, a laser beam, a phazer, or by using a magnifying glass and light source"
- **When** any valid ignition source contacts fuse
- **Then** rocket state transitions to Fired

### TC-013: 15 ANM states
- **Given** Rocket ANM has `Total States = 15`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 15`

### TC-014: Animated Section A (117 duration entries)
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 117 entries`
- **When** animation renderer processes frame timing
- **Then** durations control playback speed at 60 Hz

### TC-015: Projectile connection flag is Yes
- **Given** Connections & Capabilities shows `Projectile = Yes`
- **When** checked against `category_rules`
- **Then** part can spawn projectiles

### TC-016: Sound effects at key flight frames
- **Given** Sound Effects table shows frames 4, 21, 35, 56, 73, 94 trigger sounds
- **When** animation reaches those frames
- **Then** `PLAY_SFX` opcode dispatches corresponding sound IDs

---

## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-036-rocket.md` describes part type `36`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 36`

### TC-002: Mass value is positive
- **Given** Rocket has `mass = 18000`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Rocket has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: 2 SOLVE.RES states (Not Fired → Fired)
- **Given** Rocket has states: Not Fired (`2→17`, `12→18`, `25→21`) and Fired (`8→12`, `15→25`, `24→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Terminal state Fired (part removed)
- **Given** State Machine shows `Fired: 24→-1`
- **When** state reaches Fired
- **Then** part is removed from simulation (terminal)

### TC-006: Destructible flag is Yes
- **Given** Category Rules show `Destructible: Yes`
- **When** explosive part collides
- **Then** rocket is destroyed

### TC-007: Spawns projectile
- **Given** Category Rules show `Spawns: projectile`
- **When** rocket is triggered
- **Then** projectile is spawned as separate part instance

### TC-008: Part used in 24 levels
- **Given** Rocket (type 36)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 24 levels reference `part_num = 36`

### TC-009: Triggers include collision, proximity, timer
- **Given** Category Rules show `Triggers: collision, proximity, timer`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-010: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-011: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** rocket can be flipped to change flight direction

### TC-012: Multiple ignition sources
- **Given** Description: "You can light the fuse with a candle, a laser beam, a phazer, or by using a magnifying glass and light source"
- **When** any valid ignition source contacts fuse
- **Then** rocket transitions to Fired state

### TC-013: 15 ANM states (largest state count in batch 2)
- **Given** Rocket ANM has `Total States = 15`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 15`

### TC-014: Animated Section A (117 duration entries)
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 117 entries`
- **When** animation renderer processes frame timing
- **Then** durations control playback speed at 60 Hz

### TC-015: Projectile connection flag is Yes
- **Given** Connections & Capabilities shows `Projectile = Yes`
- **When** checked against `category_rules`
- **Then** part can spawn projectiles

### TC-016: Sound effects at key flight frames
- **Given** Sound Effects table shows frames 4, 21, 35, 56, 73, 94 trigger sounds
- **When** animation reaches those frames
- **Then** `PLAY_SFX` opcode dispatches corresponding sound IDs
