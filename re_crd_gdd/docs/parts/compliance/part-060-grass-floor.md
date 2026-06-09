## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-060-grass-floor.md` describes part type `60`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 60`

### TC-002: Mass value is positive
- **Given** Grass Floor has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Friction value within range
- **Given** Grass Floor has `friction_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `friction = 0.500` (not very slippery)

### TC-004: Destructible by explosives
- **Given** Description: "Explosions will blast holes through it"
- **When** explosive part collides
- **Then** grass floor is destroyed (hole created)

### TC-005: Part used in 10 levels
- **Given** Grass Floor (type 60)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 10 levels reference `part_num = 60`

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
- **Then** grass floor is static geometry

### TC-009: Walls / Floors category
- **Given** Category shows `Walls / Floors`
- **When** physics collision detected
- **Then** wall provides collision surface

### TC-010: Vertically/horizontally stretchable
- **Given** Description: "Stretch it vertically or horizontally to any length you need"
- **When** editor resizes part
- **Then** collision geometry updates accordingly

### TC-011: Category Part Count is 15
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Walls / Floors category

### TC-012: Tile dimensions 16×16 base
- **Given** Physics Properties show `tile_w = 16`, `tile_h = 16`
- **When** sprite is loaded
- **Then** base tile dimensions match

### TC-013: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-014: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-015: Collision AABB dimensions 576×416
- **Given** Physics Properties show `collision_w = 576`, `collision_h = 416`
- **When** physics engine resolves collisions
- **Then** AABB matches grass floor geometry
