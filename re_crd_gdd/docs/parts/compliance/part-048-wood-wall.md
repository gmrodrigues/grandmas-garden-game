## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-048-wood-wall.md` describes part type `48`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 48`

### TC-002: Mass value is positive
- **Given** Wood Wall has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Wood Wall has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: Destructible by explosives
- **Given** Description: "Explosions will blast holes through it"
- **When** explosive part collides
- **Then** wood wall is destroyed (hole created)

### TC-005: Part used in 39 levels
- **Given** Wood Wall (type 48)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 39 levels reference `part_num = 48`

### TC-006: No triggers defined
- **Given** Category Rules show `Triggers: (none)`
- **When** behavior handler evaluates
- **Then** wall is purely static geometry

### TC-007: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-008: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** wood wall is static geometry

### TC-009: Walls / Floors category
- **Given** Category shows `Walls / Floors`
- **When** physics collision detected
- **Then** wall provides collision surface

### TC-010: Vertically/horizontally stretchable
- **Given** Description: "Stretch it vertically or horizontally to any length you need"
- **When** editor resizes part
- **Then** collision geometry updates accordingly

### TC-011: Non-slippery surface (contrasts with pipe wall)
- **Given** Description: "Its surface isn't very slippery"
- **When** objects slide on wood wall
- **Then** friction is higher than pipe wall

### TC-012: Category Part Count is 15
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Walls / Floors category

### TC-013: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-014: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-015: Different from pipe wall (destructible vs explosion-immune)
- **Given** Wood Wall (destructible) vs Pipe Wall (explosion-immune)
- **When** explosive collision occurs
- **Then** wood wall is destroyed, pipe wall persists
