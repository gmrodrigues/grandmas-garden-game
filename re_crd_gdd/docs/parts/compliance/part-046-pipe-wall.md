## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-046-pipe-wall.md` describes part type `46`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 46`

### TC-002: Mass value is positive
- **Given** Pipe Wall has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Pipe Wall has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: Slippery surface (low friction)
- **Given** Description: "It has a slippery surface"
- **When** objects slide on pipe wall
- **Then** friction is reduced

### TC-005: Part used in 27 levels
- **Given** Pipe Wall (type 46)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 27 levels reference `part_num = 46`

### TC-006: No triggers defined
- **Given** Category Rules show `Triggers: (none)`
- **When** behavior handler evaluates
- **Then** wall is purely static geometry

### TC-007: Destructible flag is No (explosion-immune)
- **Given** Description: "Explosions won't affect it"
- **When** explosive part collides
- **Then** pipe wall is not destroyed

### TC-008: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-009: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** pipe wall is static geometry

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

### TC-014: Bitmap dimensions variable
- **Given** Pipe Wall has variable length
- **When** sprite is rendered
- **Then** bitmap dimensions reflect actual size

### TC-015: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty
