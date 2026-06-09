## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-085-log-wall.md` describes part type `85`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 85`

### TC-002: Mass value is positive
- **Given** Log Wall has `mass = 4153`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Friction value within range
- **Given** Log Wall has `friction_q8 = 96`
- **When** converted from Q8.8 fixed-point
- **Then** `friction = 0.375` (not very slippery)

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** log wall is static geometry

### TC-006: Walls / Floors category (Category Part Count = 15)
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Walls / Floors category

### TC-007: Destructible flag is Yes
- **Given** Category Rules show `Destructible: Yes`
- **When** explosive part collides
- **Then** log wall is destroyed (hole created)

### TC-008: No triggers (static wall)
- **Given** Category Rules show `Triggers: *(none)*`
- **When** behavior handler evaluates
- **Then** no triggers are registered

### TC-009: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-010: Part used in 18 levels
- **Given** Log Wall (type 85)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 18 levels reference `part_num = 85`

### TC-011: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-012: Tile dimensions 16×16 base
- **Given** Physics Properties show `tile_w = 16`, `tile_h = 16`
- **When** sprite is loaded
- **Then** base tile dimensions match

### TC-013: Collision AABB dimensions 576×416
- **Given** Physics Properties show `collision_w = 576`, `collision_h = 416`
- **When** physics engine resolves collisions
- **Then** AABB matches log wall geometry

### TC-014: Vertically/horizontally stretchable
- **Given** Description: "Stretch it vertically or horizontally to any length you need"
- **When** editor resizes wall
- **Then** collision geometry updates accordingly

### TC-015: Explosions blow holes through it
- **Given** Description: "Explosions will blow holes through it"
- **When** explosive part contacts wall
- **Then** hole is created in wall geometry
