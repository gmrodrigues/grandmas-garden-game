## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-056-caution-wall.md` describes part type `56`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 56`

### TC-002: Mass value is positive
- **Given** Caution Wall has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Caution Wall has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: Very slippery surface (high friction reduction)
- **Given** Description: "It's very slippery"
- **When** objects slide on caution wall
- **Then** friction is minimized

### TC-005: Explosion-immune
- **Given** Description: "isn't affected by explosives"
- **When** explosive part collides
- **Then** caution wall is not destroyed

### TC-006: Part used in 48 levels
- **Given** Caution Wall (type 56)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 48 levels reference `part_num = 56`

### TC-007: No triggers defined
- **Given** Category Rules show `Triggers: (none)`
- **When** behavior handler evaluates
- **Then** wall is purely static geometry

### TC-008: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-009: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** caution wall is static geometry

### TC-010: Walls / Floors category
- **Given** Category shows `Walls / Floors`
- **When** physics collision detected
- **Then** wall provides collision surface

### TC-011: Vertically/horizontally stretchable
- **Given** Description: "Stretch it vertically or horizontally to any length you need"
- **When** editor resizes part
- **Then** collision geometry updates accordingly

### TC-012: Category Part Count is 15
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Walls / Floors category

### TC-013: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-014: Destructible flag is No (explosion-immune)
- **Given** Category Rules and description confirm immunity
- **When** explosive collision occurs
- **Then** caution wall persists

### TC-015: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty
