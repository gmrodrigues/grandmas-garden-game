## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** the part file `part-001-brick-wall.md` describes part type `1`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 1`

### TC-002: Mass value is positive
- **Given** Brick Wall has `mass = 4153`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Friction within valid range
- **Given** Brick Wall has `friction_q8 = 1024`
- **When** converted from Q8.8 fixed-point
- **Then** `friction = 4.000` (reasonable for rough surface)

### TC-004: Destructible flag matches category rules
- **Given** Brick Wall shows `Destructible: Yes`
- **When** explosive part collides with it
- **Then** SOLVE.RES triggers destruction state

### TC-005: Category Part Count is 15
- **Given** Brick Wall category rules show `Category Part Count: 15`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** 15 parts share this category

### TC-006: No SOLVE.RES state transitions
- **Given** Brick Wall has "No SOLVE.RES state data"
- **When** collision occurs
- **Then** no programmatic state change occurs

### TC-007: ANM has 2 states but single default behavior
- **Given** Brick Wall ANM shows `Total States = 2`
- **When** animation plays
- **Then** appearance determined by `appearance` field, not state machine

### TC-008: Collision dimensions match bitmap
- **Given** Brick Wall has `collision_w = 576`, `collision_h = 416`
- **When** AABB collision check runs
- **Then** collision box is larger than bitmap (due to stretch gizmo)

### TC-009: Connection flags all disabled
- **Given** Brick Wall declares no connections
- **When** checked against connections table
- **Then** `Electrical=No`, `Belt=No`, `Rope=No`, `Fire=No`, `Laser=No`, `Projectile=No`

### TC-010: Part used in 37 levels
- **Given** Brick Wall (type 1)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 37 levels reference `part_num = 1`

### TC-011: Tile dimensions are multiples of 16
- **Given** Brick Wall has `tile_w = 16`, `tile_h = 16`
- **When** gizmo stretches the wall
- **Then** dimensions snap to 16-pixel grid increments

### TC-012: Created Part flag is No
- **Given** Brick Wall Identity shows `Created Part: No`
- **When** level is loaded
- **Then** part appears in Parts Bin

### TC-013: Interactive flag is No
- **Given** Brick Wall Identity shows `Interactive: No`
- **When** player clicks on it during simulation
- **Then** no action triggered

### TC-014: Scenery-part boundary respected
- **Given** Brick Wall has part_num 1 (< 149)
- **When** placed in level
- **Then** part is NOT scenery (scenery starts at 149)

### TC-015: Wall stretch gizmo is single-axis
- **Given** Brick Wall is a Wall/Floor category
- **When** gizmo type is determined
- **Then** stretch is constrained to horizontal or vertical axis
