## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-007-pulley.md` describes part type `7`
- **When** parsed
- **Then** `part_num == 7`

### TC-002: Mass value is positive
- **Given** Pulley has `mass = 3776`
- **When** validated
- **Then** `mass > 0`

### TC-003: Extra data structure for pulley
- **Given** Pulley requires extra data per `d_item_extra_data_1_type_t2`
- **When** parsed
- **Then** `nt_part_extra_pulley` (8 bytes) is appended

### TC-004: No SOLVE.RES state transitions
- **Given** Pulley has no SOLVE.RES state data
- **When** collision occurs
- **Then** no state change (static anchor point)

### TC-005: Belt and Rope connections supported
- **Given** Pulley shows `Belt=Yes`, `Rope=Yes`
- **When** rope goes over pulley
- **Then** mechanical advantage is calculated

### TC-006: 2 ANM states for pulley wheel rotation
- **Given** Pulley ANM shows `Total States = 2`
- **When** rope moves
- **Then** wheel rotates through 3 frames

### TC-007: Rope constraint routing through pulley
- **Given** Rope connects object A to object B with pulley in between
- **When** constraint solver runs
- **Then** pulley redirects rope force vector

### TC-008: Part used in 91 levels
- **Given** Pulley (type 7)
- **When** checked against YAML levels
- **Then** at least 91 levels reference it (highest of Batch 1)

### TC-009: Pulley redirects force direction
- **Given** Description: "run the rope over as many pulleys"
- **When** object pulls rope down
- **Then** pulley redirects force to lift other object

### TC-010: Category Part Count is 4
- **Given** Category Rules show `Category Part Count: 4`
- **When** validated
- **Then** 4 parts in Ropes/Belts/Pulleys category

### TC-011: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-012: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** no direct player interaction

### TC-013: Bitmap dimensions match pulley wheel
- **Given** Pulley has `bitmap_w = 22`, `bitmap_h = 24`
- **When** rendered
- **Then** wheel sprite is approximately square

### TC-014: Mechanical advantage calculation
- **Given** Pulley connects two rope segments
- **When** force applied
- **Then** force magnitude divided by segment count

### TC-015: property_q8 is 0 (no motor)
- **Given** Pulley has `property_q8 = 0`
- **When** physics runs
- **Then** pulley is passive (no self-propulsion)
