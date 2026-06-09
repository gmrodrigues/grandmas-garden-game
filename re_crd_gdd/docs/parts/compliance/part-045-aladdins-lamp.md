## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-045-aladdins-lamp.md` describes part type `45`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 45`

### TC-002: Mass value is positive
- **Given** Aladdin's Lamp has `mass = 2000`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Aladdin's Lamp has `property_q8 = 84`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (84 >> 8) <= 1.0` i.e. `COR = 0.328`

### TC-004: SOLVE.RES state transitions (Out → Lit)
- **Given** Aladdin's Lamp has 2 primary states: Out (`1→2`) and Lit (`2→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Terminal state Lit (part removed)
- **Given** State Machine shows `Lit: 2→-1`
- **When** state reaches Lit
- **Then** part is removed from simulation (terminal)

### TC-006: Spawns fire (light source)
- **Given** Category Rules show `Spawns: fire`
- **When** lamp is lit
- **Then** fire/light beam is emitted

### TC-007: Triggers are proximity and electrical
- **Given** Category Rules show `Triggers: proximity, electrical`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-008: Part used in 8 levels
- **Given** Aladdin's Lamp (type 45)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 8 levels reference `part_num = 45`

### TC-009: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-010: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** lamp can be manually activated

### TC-011: Multiple ignition sources
- **Given** Description: "Light this oil lamp with a laser, a flaming part, or a light source and a magnifying glass"
- **When** any valid ignition source contacts lamp
- **Then** lamp transitions to Lit state

### TC-012: Can pop blimps and balloons
- **Given** Description: "Once it's burning, you can use it to... pop blimps and balloons"
- **When** fire beam contacts balloon/blimp
- **Then** target is destroyed

### TC-013: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** lamp is not destroyed

### TC-014: 3 ANM states (state IDs 1, 2, 3)
- **Given** Aladdin's Lamp ANM has `Total States = 3`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 3`

### TC-015: Category Part Count is 5
- **Given** Category Rules show `Category Part Count: 5`
- **When** validated
- **Then** 5 parts in Light / Flame Sources category
