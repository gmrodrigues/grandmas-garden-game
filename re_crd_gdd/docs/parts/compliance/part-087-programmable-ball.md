## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-087-programmable-ball.md` describes part type `87`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 87`

### TC-002: Mass value is positive
- **Given** Programmable Ball has `mass = 2832`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Programmable Ball has `cor_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: Radius is non-negative
- **Given** Programmable Ball has `radius = 16`
- **When** physics engine initializes collision
- **Then** `radius >= 0`

### TC-005: Damping value is non-negative
- **Given** Programmable Ball has `damping = 200`
- **When** physics engine applies drag
- **Then** `damping >= 0`

### TC-006: Part used in 11 levels
- **Given** Programmable Ball (type 87)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 11 levels reference `part_num = 87`

### TC-007: Triggers are collision and trap
- **Given** Category Rules show `Triggers: collision, trap`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-008: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-009: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** programmable ball physics are automatic

### TC-010: Balls category (Category Part Count = 9)
- **Given** Category Rules show `Category Part Count: 9`
- **When** validated
- **Then** 9 parts in Balls category

### TC-011: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** programmable ball is not destroyed

### TC-012: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-013: Single default state (no SOLVE.RES transitions)
- **Given** State Machine shows *Single default state — no named transitions*
- **When** behavior handler evaluates
- **Then** no state transitions are triggered

### TC-014: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-015: 21 total animation frames across 7 states (programmed variants)
- **Given** ANM shows `Total Frames: 21`, `Total States: 7`
- **When** animation renderer processes
- **Then** all 21 frames map to correct programmed states

### TC-016: Programmable appearance, mass, elasticity, density, friction
- **Given** Description: "This ball can be programmed to vary in appearance, mass, elasticity, density, and friction"
- **When** player programs ball parameters
- **Then** ball physics and appearance reflect programmed values
