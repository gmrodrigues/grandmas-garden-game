## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-064-pinball-bumper.md` describes part type `64`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 64`

### TC-002: Mass value is positive
- **Given** Pinball Bumper has `mass = 2400`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Pinball Bumper has `property_q8 = 256`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (256 >> 8) <= 1.0` i.e. `COR = 1.000`

### TC-004: Bounce redirection mechanic
- **Given** Description: "This pinball bumper can be placed so that moving objects will bounce off in any direction"
- **When** object contacts bumper
- **Then** object bounces in direction determined by bumper orientation

### TC-005: COR = 1.0 (perfect elastic collision)
- **Given** Pinball Bumper COR = 1.000
- **When** collision occurs
- **Then** no energy is lost (perfect bounce)

### TC-006: Part used in 20 levels
- **Given** Pinball Bumper (type 64)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 20 levels reference `part_num = 64`

### TC-007: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-008: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** bumper is passive collision device

### TC-009: Special Mechanics category
- **Given** Category shows `Special Mechanics`
- **When** behavior handler evaluates
- **Then** bounce redirection is applied

### TC-010: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** bumper is not destroyed

### TC-011: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-012: Category Part Count is 15
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Special Mechanics category

### TC-013: Flip changes bounce direction
- **Given** Bumper can be flipped
- **When** player flips bumper
- **Then** bounce direction changes accordingly

### TC-014: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-015: Collision response redirects momentum
- **Given** Object contacts bumper at angle θ
- **When** physics engine resolves collision
- **Then** object velocity is redirected while magnitude is preserved (COR=1.0)
