## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-027-captain-z-super-phazer.md` describes part type `27`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 27`

### TC-002: Mass value is positive
- **Given** Captain Z Super Phazer has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Captain Z Super Phazer has `property_q8 = 192`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (192 >> 8) <= 1.0` i.e. `COR = 0.750`

### TC-004: SOLVE.RES state transitions (Not Fired → Fired)
- **Given** Captain Z has 2 states: Not Fired (`1→6`) and Fired (`6→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Terminal state Fired (part removed)
- **Given** State Machine shows `Fired: 6→-1`
- **When** state reaches Fired
- **Then** part is removed from simulation (terminal)

### TC-006: Spawns projectile (phazer pulse)
- **Given** Category Rules show `Spawns: projectile`
- **When** rope pulls trigger
- **Then** phazer pulse (type 20) is spawned

### TC-007: Destructible flag is Yes
- **Given** Category Rules show `Destructible: Yes`
- **When** explosive part collides
- **Then** Captain Z is destroyed

### TC-008: Triggers include collision, proximity, timer
- **Given** Category Rules show `Triggers: collision, proximity, timer`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-009: Part used in 22 levels
- **Given** Captain Z Super Phazer (type 27)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 22 levels reference `part_num = 27`

### TC-010: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-011: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** phazer requires rope-trigger mechanism to fire

### TC-012: Rope-activated trigger mechanism
- **Given** Description: "Tie one end of a rope to the trigger and run it through a pulley"
- **When** rope pulls trigger
- **Then** phazer fires programmed number of pulses

### TC-013: Can pop balloons and blimps
- **Given** Description: "use phazer pulses to bump things, pop balloons and blimps"
- **When** projectile hits balloon/blimp
- **Then** target is destroyed

### TC-014: 4 ANM states (state IDs 1, 6, and others)
- **Given** Captain Z ANM has `Total States = 4`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 4`

### TC-015: Projectile connection flag is Yes
- **Given** Connections & Capabilities shows `Projectile = Yes`
- **When** checked against `category_rules`
- **Then** part can spawn projectiles
