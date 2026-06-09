## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-055-remote-control-explosives.md` describes part type `55`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 55`

### TC-002: Mass value is positive
- **Given** Remote Control Explosives has `mass = 4153`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Remote Control Explosives has `property_q8 = 1024`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (1024 >> 8) <= 1.0` i.e. `COR = 4.000`

### TC-004: SOLVE.RES state transitions
- **Given** Remote Control Explosives has named state transitions
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Destructible flag is Yes
- **Given** Category Rules show `Destructible: Yes`
- **When** explosive part collides
- **Then** explosives are destroyed

### TC-006: Spawns projectile on detonation
- **Given** Category Rules show `Spawns: projectile`
- **When** remote triggers explosion
- **Then** explosive force propagates

### TC-007: Part used in 57 levels
- **Given** Remote Control Explosives (type 55)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 57 levels reference `part_num = 55`

### TC-008: Triggers include collision, proximity, timer
- **Given** Category Rules show `Triggers: collision, proximity, timer`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-009: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-010: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** explosives require remote trigger activation

### TC-011: Rope-activated trigger mechanism
- **Given** Description: "tie one end of a rope to the button and hitch the other end to a teeter-totter"
- **When** rope pulls button
- **Then** explosion is triggered

### TC-012: Destroys walls including most types
- **Given** Description: "They'll blow up all kinds of things, including most walls"
- **When** explosion occurs near wall
- **Then** wall is destroyed (except explosion-immune types)

### TC-013: Category Part Count is 10
- **Given** Category Rules show `Category Part Count: 10`
- **When** validated
- **Then** 10 parts in Explosives / Projectiles category

### TC-014: No electrical/belt/rope/fire/laser connections
- **Given** Connections & Capabilities shows most flags as No
- **When** checked against `category_rules`
- **Then** only default connections and Projectile=Yes

### TC-015: Terminal state on detonation (part removed)
- **Given** State Machine shows terminal state on explosion
- **When** explosion triggers
- **Then** part is removed from simulation
