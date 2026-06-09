## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** the part file `part-000-bowling-ball.md` describes part type `0`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 0`

### TC-002: Mass value is positive
- **Given** Bowling Ball has `mass = 2832`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Bowling Ball has `cor_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: Radius is non-negative
- **Given** Bowling Ball has `radius = 16`
- **When** physics engine initializes collision
- **Then** `radius >= 0`

### TC-005: Initial state at simulation start
- **Given** Bowling Ball is placed in a level
- **When** simulation starts
- **Then** `state_counter` initializes to `0`

### TC-006: Single default state — no named transitions
- **Given** Bowling Ball has no SOLVE.RES state data
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-007: ANM animation frames match state count
- **Given** Bowling Ball ANM has `Total Frames = 8`, `Total States = 1`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 1`

### TC-008: Bytecode draws correct sprites
- **Given** Bowling Ball ANM frame `0`
- **When** bytecode is executed
- **Then** `DRAW_BMP` opcode references valid sprite in `build/phase-3/bitmaps/PART0_f*.png`

### TC-009: Connection flags match category rules
- **Given** Bowling Ball (Balls category) declares no connections
- **When** checked against `category_rules`
- **Then** `Electrical=No`, `Belt=No`, `Rope=No`, `Fire=No`, `Laser=No`, `Projectile=No`

### TC-010: Part used in real levels
- **Given** Bowling Ball (type 0)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 40 levels reference `part_num = 0`

### TC-011: Snap-to-grid (16px) in edit mode
- **Given** Bowling Ball placed at position `(47, 23)`
- **When** editor snaps position
- **Then** result is `(48, 16)` — both coordinates multiple of 16

### TC-012: Physics disabled in edit mode
- **Given** Bowling Ball in edit mode
- **Then** `velocity_x = velocity_y = 0` and `state_counter` frozen

### TC-013: Created Part flag is No
- **Given** Bowling Ball Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-014: Interactive flag is No
- **Given** Bowling Ball Identity shows `Interactive: No`
- **When** `nt_part_info_t2_base.behavior` is checked
- **Then** part does not require user interaction to activate

### TC-015: Namedtuple field count matches format
- **Given** `nt_part_info_t2_base` parsed from binary
- **Then** `len(nt_part_info_t2_base._fields) == 25` fields

### TC-016: Flags_3 bitfield decodes correctly
- **Given** Bowling Ball `flags_3` from level data
- **When** decoded per `fformat.txt`
- **Then** gravity direction bit (bit 3) and initial state bit (bit 12) are valid
