## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-068-soccer-ball.md` describes part type `68`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 68`

### TC-002: Mass value is positive
- **Given** Soccer Ball has `mass = 1522`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Soccer Ball has `cor_q8 = 160`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (160 >> 8) <= 1.0` i.e. `COR = 0.625`

### TC-004: Radius is non-negative
- **Given** Soccer Ball has `radius = 24`
- **When** physics engine initializes collision
- **Then** `radius >= 0`

### TC-005: Damping value is non-negative
- **Given** Soccer Ball has `damping = 28`
- **When** physics engine applies drag
- **Then** `damping >= 0`

### TC-006: Part used in 20 levels
- **Given** Soccer Ball (type 68)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 20 levels reference `part_num = 68`

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
- **Then** soccer ball physics are automatic

### TC-010: Balls category (Category Part Count = 9)
- **Given** Category Rules show `Category Part Count: 9`
- **When** validated
- **Then** 9 parts in Balls category

### TC-011: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** soccer ball is not destroyed

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

### TC-015: 8 animation frames (rotating appearance)
- **Given** ANM shows `Total Frames: 8`, `Total States: 1`
- **When** animation renderer processes
- **Then** all 8 frames render in sequence for rolling effect
