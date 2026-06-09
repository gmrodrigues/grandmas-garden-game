## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-059-super-ball.md` describes part type `59`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 59`

### TC-002: Mass value is positive
- **Given** Super Ball has `mass = 1800`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR exceeds 1.0 (bounce amplification)
- **Given** Super Ball has `cor_q8 = 512`
- **When** converted from Q8.8 fixed-point
- **Then** `COR = 2.000` (exceeds normal range, ball gains height)

### TC-004: Radius is non-negative
- **Given** Super Ball has `radius = 16`
- **When** physics engine initializes collision
- **Then** `radius >= 0`

### TC-005: Damping value affects air resistance
- **Given** Super Ball has `damping = 14`
- **When** physics simulation runs
- **Then** velocity decay reflects light mass

### TC-006: Single default state — no named transitions
- **Given** Super Ball has no SOLVE.RES state data
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-007: Part used in 7 levels
- **Given** Super Ball (type 59)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 7 levels reference `part_num = 59`

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
- **Then** super ball physics are automatic

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** super ball is not destroyed

### TC-013: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-014: Sprite dimensions 240×240
- **Given** Physics Properties show `sprite_w = 240`, `sprite_h = 240`
- **When** sprite is loaded
- **Then** sprite dimensions match

### TC-015: COR > 1.0 validated (unique among all balls)
- **Given** Super Ball COR = 2.000 vs normal range [0.0, 1.0]
- **When** collision response calculated
- **Then** bounce height exceeds fall height (energy gain mechanic)
