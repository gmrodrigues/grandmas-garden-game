## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-044-tennis-ball.md` describes part type `44`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 44`

### TC-002: Mass value is positive
- **Given** Tennis Ball has `mass = 1322`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Tennis Ball has `cor_q8 = 192`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (192 >> 8) <= 1.0` i.e. `COR = 0.750`

### TC-004: Radius is non-negative
- **Given** Tennis Ball has `radius = 16`
- **When** physics engine initializes collision
- **Then** `radius >= 0`

### TC-005: Damping value affects air resistance
- **Given** Tennis Ball has `damping = 5`
- **When** physics simulation runs
- **Then** velocity decay is minimal (light and bouncy)

### TC-006: Single default state — no named transitions
- **Given** Tennis Ball has no SOLVE.RES state data
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-007: Part used in 44 levels
- **Given** Tennis Ball (type 44)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 44 levels reference `part_num = 44`

### TC-008: Category Part Count is 9 (Balls category)
- **Given** Category Rules show `Category Part Count: 9`
- **When** validated
- **Then** 9 parts in Balls category

### TC-009: Triggers are collision and trap
- **Given** Category Rules show `Triggers: collision, trap`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-010: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-011: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** tennis ball physics are automatic

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** tennis ball is not destroyed

### TC-013: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-014: Sprite dimensions 240×240
- **Given** Physics Properties show `sprite_w = 240`, `sprite_h = 240`
- **When** sprite is loaded
- **Then** sprite dimensions match

### TC-015: Highest COR of all balls (0.750 vs bowling ball 0.500)
- **Given** Tennis Ball COR = 0.750, Bowling Ball COR = 0.500
- **When** bouncing
- **Then** tennis ball bounces significantly higher than bowling ball
