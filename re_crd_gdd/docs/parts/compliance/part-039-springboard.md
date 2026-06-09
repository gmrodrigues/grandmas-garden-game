## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-039-springboard.md` describes part type `39`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 39`

### TC-002: Mass value is positive
- **Given** Springboard has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Springboard has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: No SOLVE.RES state transitions
- **Given** Springboard has no programmatic state transitions
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-005: Triggers are collision and electrical
- **Given** Category Rules show `Triggers: collision, electrical`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-006: Part used in 54 levels
- **Given** Springboard (type 39)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 54 levels reference `part_num = 39`

### TC-007: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-008: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** springboard activates passively on contact

### TC-009: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** springboard is not destroyed

### TC-010: Progressive bounce height increase
- **Given** Description: "Anything you drop on this springboard will go higher with each bounce"
- **When** object contacts springboard
- **Then** bounce velocity increases with each contact

### TC-011: Category Part Count is 7
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Springs / Pneumatics category

### TC-012: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-013: Bitmap dimensions 49×27
- **Given** Physics Properties show `bitmap_w = 49`, `bitmap_h = 27`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-014: Spring physics with increasing energy
- **Given** Springboard collision response
- **When** object lands on springboard
- **Then** upward impulse is applied with energy multiplier

### TC-015: Multi-bounce constraint enforcement
- **Given** Object bounces on springboard multiple times
- **When** physics engine resolves collision
- **Then** each bounce applies progressively larger impulse
