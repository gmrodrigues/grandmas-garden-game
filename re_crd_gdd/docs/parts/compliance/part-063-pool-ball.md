## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-063-pool-ball.md` describes part type `63`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 63`

### TC-002: Mass value is positive
- **Given** Pool Ball has `mass = 2400`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Pool Ball has `cor_q8 = 224`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (224 >> 8) <= 1.0` i.e. `COR = 0.875`

### TC-004: Radius is non-negative
- **Given** Pool Ball has `radius = 1`
- **When** physics engine initializes collision
- **Then** `radius >= 0`

### TC-005: No gravity behavior
- **Given** Description: "It isn't affected by gravity"
- **When** simulation runs
- **Then** pool ball maintains constant vertical position unless acted upon

### TC-006: Programmable number display
- **Given** Description: "You can program it to show any number on its surface"
- **When** player sets ball number
- **Then** ANM sprite reflects programmed number

### TC-007: Only moves when hit
- **Given** Description: "This pool ball won't move until it's hit"
- **When** collision transfers momentum
- **Then** pool ball velocity changes proportional to impact

### TC-008: Part used in 21 levels
- **Given** Pool Ball (type 63)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 21 levels reference `part_num = 63`

### TC-009: Category Part Count is 9 (Balls category)
- **Given** Category Rules show `Category Part Count: 9`
- **When** validated
- **Then** 9 parts in Balls category

### TC-010: Triggers are collision and trap
- **Given** Category Rules show `Triggers: collision, trap`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-011: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-012: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** pool ball physics are automatic

### TC-013: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** pool ball is not destroyed

### TC-014: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-015: Sprite dimensions 240×240
- **Given** Physics Properties show `sprite_w = 240`, `sprite_h = 240`
- **When** sprite is loaded
- **Then** sprite dimensions match
