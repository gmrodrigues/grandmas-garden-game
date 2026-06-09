## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-014-gear.md` describes part type `14`
- **When** parsed
- **Then** `part_num == 14`

### TC-002: Mass value is positive
- **Given** Gear has `mass = 7552` (heaviest in Batch 1)
- **When** validated
- **Then** `mass > 0`

### TC-003: Electrical, Belt, Rope connections all supported
- **Given** Gear shows `Electrical=Yes`, `Belt=Yes`, `Rope=Yes`
- **When** connected to system
- **Then** torque transmits through all connection types

### TC-004: Gear ratio changes direction
- **Given** Description: "place gears side by side to change direction of rotation"
- **When** odd number of gears in chain
- **Then** rotation direction inverts

### TC-005: No SOLVE.RES (static rotation state)
- **Given** Gear has no SOLVE.RES state data
- **When** belt drives it
- **Then** continuous rotation animation

### TC-006: 2 ANM states (still/rotating)
- **Given** Gear ANM shows `Total States = 2`
- **When** rendered
- **Then** state 1 = still, state 4 = rotating (4 frames)

### TC-007: Collision triggers gear
- **Given** Gear shows `Triggers: collision, electrical, rope`
- **When** collision occurs
- **Then** SOLVE.RES may trigger animation

### TC-008: Part used in 32 levels
- **Given** Gear (type 14)
- **When** checked against YAML levels
- **Then** at least 32 levels reference it

### TC-009: Category Part Count is 7
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Rotating Power Sources category

### TC-010: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-011: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** gear rotation is automatic when driven

### TC-012: Bitmap dimensions (35×35 square)
- **Given** Gear has `bitmap_w = 35`, `bitmap_h = 35`
- **When** rendered
- **Then** square gear sprite

### TC-013: property_q8 encodes gear teeth count
- **Given** Gear has `property_q8 = 1024` (Q8.8 = 4.000)
- **When** behavior handler runs
- **Then** value affects mesh with adjacent gears

### TC-014: unk_6 = 48 (teeth spacing)
- **Given** Gear has `unk_6 = 48`
- **When** collision with other gear
- **Then** tooth engagement distance

### TC-015: Belt connects gears together
- **Given** Description: "belt and hitch to other rotating parts"
- **When** belt placed
- **Then** multiple gears can be driven from single motor
