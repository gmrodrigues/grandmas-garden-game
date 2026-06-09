## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-008-belt.md` describes part type `8`
- **When** parsed
- **Then** `part_num == 8`

### TC-002: Mass value is positive
- **Given** Belt has `mass = 3776`
- **When** validated
- **Then** `mass > 0`

### TC-003: Extra data structure for belt
- **Given** Belt requires extra data per `d_item_extra_data_1_type_t2`
- **When** parsed
- **Then** `nt_part_extra_belt` (4 bytes) is appended

### TC-004: No ANM animation frames
- **Given** Belt ANM shows `Total Frames = 0`
- **When** rendered
- **Then** belt is drawn as line between two pulleys (procedural)

### TC-005: Belt connects two rotating parts
- **Given** Description: "hitch any two rotating parts together"
- **When** belt placed between motor and conveyor
- **Then** torque transmits from motor to conveyor

### TC-006: Belt has max stretch distance
- **Given** Description: "Belt can only be stretched a limited distance"
- **When** distance exceeds maximum
- **Then** placement is rejected (red line)

### TC-007: Belt turns red then green when valid
- **Given** Belt being placed
- **When** distance is within range
- **Then** line color changes from red to green

### TC-008: Belt and Rope connections supported
- **Given** Belt shows `Belt=Yes`, `Rope=Yes`
- **When** connected
- **Then** both belt and rope systems recognize connection

### TC-009: Part used in 83 levels
- **Given** Belt (type 8)
- **When** checked against YAML levels
- **Then** at least 83 levels reference it

### TC-010: Angular velocity sync between connected parts
- **Given** Motor (type 6) connected to Conveyor Belt (type 5) via Belt (type 8)
- **When** simulation runs
- **Then** all connected parts share same angular velocity

### TC-011: Category Part Count is 4
- **Given** Category Rules show `Category Part Count: 4`
- **When** validated
- **Then** 4 parts in Ropes/Belts/Pulleys category

### TC-012: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-013: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** belt auto-transmits when motor runs

### TC-014: Bitmap dimensions are large (stretched line)
- **Given** Belt has `bitmap_w = 656`, `bitmap_h = 4467`
- **When** sprite rendered
- **Then** represents maximum stretched length

### TC-015: Torque direction based on gear ratio
- **Given** Description: "place gears side by side to change direction of rotation"
- **When** odd number of gears in chain
- **Then** rotation direction inverts
