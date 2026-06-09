## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-035-boxing-glove.md` describes part type `35`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 35`

### TC-002: Mass value is positive
- **Given** Boxing Glove has `mass = 3776`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Boxing Glove has `property_q8 = 32`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (32 >> 8) <= 1.0` i.e. `COR = 0.125`

### TC-004: No SOLVE.RES state transitions
- **Given** Boxing Glove has no programmatic state transitions
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-005: Part used in 44 levels
- **Given** Boxing Glove (type 35)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 44 levels reference `part_num = 35`

### TC-006: No triggers defined
- **Given** Category Rules show `Triggers: (none)`
- **When** behavior handler evaluates
- **Then** part activates purely from collision

### TC-007: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-008: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** glove punches on button activation

### TC-009: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** glove is not destroyed

### TC-010: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-011: Punch force applies to impacted part
- **Given** Description: "Bump the button on the back of this boxing glove to make it punch things"
- **When** button is activated
- **Then** glove extends and applies force to target

### TC-012: Category Part Count is 7
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Springs / Pneumatics category

### TC-013: Bitmap dimensions 53×39
- **Given** Physics Properties show `bitmap_w = 53`, `bitmap_h = 39`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-014: Low COR (0.125) indicates soft surface
- **Given** Boxing Glove COR = 0.125 (lowest in springs category)
- **When** collision occurs
- **Then** energy absorption is high

### TC-015: Collision trigger activates punch
- **Given** Glove button is depressed by falling object
- **When** collision force exceeds threshold
- **Then** punch animation triggers

---

## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-035-boxing-glove.md` describes part type `35`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 35`

### TC-002: Mass value is positive
- **Given** Boxing Glove has `mass = 3776`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Boxing Glove has `property_q8 = 32`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (32 >> 8) <= 1.0` i.e. `COR = 0.125`

### TC-004: No SOLVE.RES state transitions
- **Given** Boxing Glove has no programmatic state transitions
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-005: Part used in 44 levels
- **Given** Boxing Glove (type 35)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 44 levels reference `part_num = 35`

### TC-006: Triggers are collision-based activation
- **Given** Description: "Bump the button on the back of this boxing glove to make it punch things"
- **When** collision activates button
- **Then** glove punches in direction of collision

### TC-007: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-008: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** glove activates on collision without player input

### TC-009: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** glove is not destroyed

### TC-010: Category Part Count is 7
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Springs / Pneumatics category

### TC-011: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-012: Bitmap dimensions 53×39
- **Given** Physics Properties show `bitmap_w = 53`, `bitmap_h = 39`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-013: Punch force transfers momentum
- **Given** Boxing Glove activates on collision
- **When** glove strikes target
- **Then** target receives momentum transfer from punch

### TC-014: Low COR (0.125) — minimal bounce
- **Given** Boxing Glove COR = 0.125
- **When** glove collides with surface
- **Then** minimal bounce response

### TC-015: Spring/pneumatic category behavior
- **Given** Boxing Glove is in Springs / Pneumatics category
- **When** behavior handler processes
- **Then** pneumatic punch force is applied
