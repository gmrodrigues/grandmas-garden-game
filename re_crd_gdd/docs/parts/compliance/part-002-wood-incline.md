## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** the part file `part-002-wood-incline.md` describes part type `2`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 2`

### TC-002: Mass value is positive
- **Given** Wood Incline has `mass = 1510`
- **When** validated
- **Then** `mass > 0`

### TC-003: Friction value is valid
- **Given** Wood Incline has `friction_q8 = 1024`
- **When** converted
- **Then** `friction = 4.000` (wood surface)

### TC-004: Destructible flag is No
- **Given** Wood Incline shows `Destructible: No`
- **When** explosive collides with it
- **Then** wall is NOT destroyed

### TC-005: No SOLVE.RES state transitions
- **Given** Wood Incline has no SOLVE.RES data
- **When** any collision occurs
- **Then** no state change triggered

### TC-006: Collision height is 0 (degenerate AABB)
- **Given** Wood Incline has `collision_h = 0`
- **When** AABB collision check runs
- **Then** this represents a 1D line collision (incline has no thickness)

### TC-007: Collision width is 64
- **Given** Wood Incline has `collision_w = 64`
- **When** collision check runs
- **Then** collision extends 64 units along incline

### TC-008: ANM single state with 4 frames
- **Given** Wood Incline ANM shows `Total Frames = 4`, `Total States = 1`
- **When** rendered
- **Then** only one visual appearance state

### TC-009: No connections supported
- **Given** Wood Incline declares no connections
- **When** checked
- **Then** `Electrical=No`, `Belt=No`, `Rope=No`, `Fire=No`, `Laser=No`, `Projectile=No`

### TC-010: Part used in 36 levels
- **Given** Wood Incline (type 2)
- **When** checked against YAML levels
- **Then** at least 36 levels reference it

### TC-011: Incline angle determined by stretch gizmo
- **Given** Wood Incline can be stretched
- **When** gizmo changes `width_1` dimension
- **Then** collision box updates accordingly

### TC-012: Bitmap height matches incline sprite
- **Given** Wood Incline has `bitmap_h = 32`
- **When** sprite is rendered
- **Then** frame height is 32 pixels

### TC-013: Category is Inclines
- **Given** Wood Incline Category is "Inclines"
- **When** placed with other inclines
- **Then** they can stack/be adjacent

### TC-014: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-015: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** no player interaction required
