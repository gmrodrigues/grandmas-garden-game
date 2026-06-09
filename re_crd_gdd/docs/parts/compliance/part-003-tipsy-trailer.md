## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-003-tipsy-trailer.md` describes part type `3`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 3`

### TC-002: Mass value is positive
- **Given** Tipsy Trailer has `mass = 1888`
- **When** validated
- **Then** `mass > 0`

### TC-003: property_q8 encodes mechanical property
- **Given** Tipsy Trailer has `property_q8 = 1024` (Q8.8 = 4.000)
- **When** behavior handler runs
- **Then** value represents pivot sensitivity or counterweight effect

### TC-004: Category triggers include collision, electrical, proximity
- **Given** Tipsy Trailer shows `Triggers: collision, electrical, proximity`
- **When** any of these stimuli occur
- **Then** state transition may be triggered

### TC-005: Spawns custom behavior
- **Given** Tipsy Trailer shows `Spawns: custom`
- **When** activated
- **Then** special behavior handler is invoked (teeter-totter pivot)

### TC-006: Electrical connection supported
- **Given** Tipsy Trailer shows `Electrical: Yes`
- **When** connected to power network
- **Then** can be activated via electrical signal

### TC-007: ANM state ID is 6 (non-default initial)
- **Given** Tipsy Trailer ANM shows `State ID: 6` for first frame
- **When** simulation starts
- **Then** `state_counter` may initialize to `6` (check flags_3)

### TC-008: 3 animation frames for pivot motion
- **Given** Tipsy Trailer ANM has `Total Frames = 3`
- **When** animated
- **Then** frames show trailer pivoting between positions

### TC-009: Bytecode draws 6 sprites (2 per frame)
- **Given** Bytecode shows `DRAW_BMP: 6`
- **When** rendering
- **Then** each frame composes 2 sprite images

### TC-010: Part used in 38 levels
- **Given** Tipsy Trailer (type 3)
- **When** checked against YAML levels
- **Then** at least 38 levels reference it

### TC-011: Rope connection anchor points
- **Given** Description mentions rope attachment at either end
- **When** rope connects to trailer
- **Then** force applied at attachment point creates pivot torque

### TC-012: Teeter-totter pivot physics
- **Given** heavy object dropped on high end
- **When** physics tick runs
- **Then** angular momentum transfers to low end (catapult effect)

### TC-013: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-014: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** player clicks during sim
- **Then** no direct interaction

### TC-015: Category Part Count is 15
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Special Mechanics category
