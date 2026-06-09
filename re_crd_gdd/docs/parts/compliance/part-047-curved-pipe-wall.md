## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-047-curved-pipe-wall.md` describes part type `47`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 47`

### TC-002: Mass value is positive
- **Given** Curved Pipe Wall has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Friction value within range
- **Given** Curved Pipe Wall has `friction_q8 = 1024`
- **When** converted from Q8.8 fixed-point
- **Then** `friction = 4.000` (high friction surface)

### TC-004: Destructible flag is Yes
- **Given** Category Rules show `Destructible: Yes`
- **When** explosive part collides
- **Then** curved pipe wall can be destroyed

### TC-005: Part used in 7 levels
- **Given** Curved Pipe Wall (type 47)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 7 levels reference `part_num = 47`

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
- **Then** curved pipe wall is static geometry

### TC-009: Flip capability changes curve direction
- **Given** Description: "Flip it to curve in the direction needed"
- **When** player flips part
- **Then** pipe curve direction changes

### TC-010: Category Part Count is 15
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Walls / Floors category

### TC-011: Connects to pipe wall or floor
- **Given** Description: "This curved pipe section can be connected to a pipe wall or floor"
- **When** placed adjacent to pipe wall
- **Then** connection is formed

### TC-012: Tile dimensions 240×240 base
- **Given** Physics Properties show `tile_w = 240`, `tile_h = 240`
- **When** sprite is loaded
- **Then** base tile dimensions match

### TC-013: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-014: Bitmap dimensions 32×32
- **Given** Physics Properties show `bitmap_w = 32`, `bitmap_h = 32`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-015: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty
