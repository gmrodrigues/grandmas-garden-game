## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-062-coffee-pot.md` describes part type `62`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 62`

### TC-002: Mass value is positive
- **Given** Coffee Pot has `mass = 2400`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Coffee Pot has `property_q8 = 64`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (64 >> 8) <= 1.0` i.e. `COR = 0.250`

### TC-004: Steam propulsion mechanic
- **Given** Description: "Then use the steam to push things"
- **When** coffee pot is heated and percolating
- **Then** steam applies force to nearby objects

### TC-005: Fire activation sources
- **Given** Description: "Make this coffee pot percolate by heating it with a candle, Aladdin's lamp, match-on-a-spring, or flint & tinder"
- **When** any valid heat source contacts pot
- **Then** percolation begins

### TC-006: Part used in 17 levels
- **Given** Coffee Pot (type 62)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 17 levels reference `part_num = 62`

### TC-007: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-008: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** pot can be heated by player-placed fire sources

### TC-009: Special Mechanics category
- **Given** Category shows `Special Mechanics`
- **When** behavior handler evaluates
- **Then** steam propulsion is applied

### TC-010: Triggers include fire/heat activation
- **Given** Category Rules show `Triggers: fire` or passive heat detection
- **When** heat source contacts pot
- **Then** percolation state activates

### TC-011: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** pot is not destroyed

### TC-012: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-013: Category Part Count is 15
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Special Mechanics category

### TC-014: Bitmap dimensions 38×41
- **Given** Physics Properties show `bitmap_w = 38`, `bitmap_h = 41`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-015: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty
