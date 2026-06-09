## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-051-vacuum.md` describes part type `51`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 51`

### TC-002: Mass value is positive
- **Given** Vacuum has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Vacuum has `property_q8 = 1024`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (1024 >> 8) <= 1.0` i.e. `COR = 4.000`

### TC-004: SOLVE.RES state transitions
- **Given** Vacuum has named state transitions
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Suction force on gravity-affected objects
- **Given** Description: "use it to suck up any object that's affected by gravity"
- **When** vacuum is active and object is nearby
- **Then** object is pulled toward vacuum

### TC-006: Part used in 7 levels
- **Given** Vacuum (type 51)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 7 levels reference `part_num = 51`

### TC-007: Triggers are electrical and collision
- **Given** Category Rules show `Triggers: electrical, collision`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-008: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-009: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** vacuum can be manually activated

### TC-010: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical = Yes`
- **When** checked against `category_rules`
- **Then** vacuum must be plugged in to operate

### TC-011: Category Part Count is 9
- **Given** Category Rules show `Category Part Count: 9`
- **When** validated
- **Then** 9 parts in Electrical category

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** vacuum is not destroyed

### TC-013: Belt Connection flag is Yes
- **Given** Connections & Capabilities shows `Belt Connection = Yes`
- **When** belt is attached
- **Then** vacuum suction can be powered mechanically

### TC-014: No rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows most flags as No
- **When** checked against `category_rules`
- **Then** only Electrical and Belt are Yes

### TC-015: Animated Section A for suction effect
- **Given** ANM shows animated suction effect
- **When** vacuum activates
- **Then** animation plays suction visual
