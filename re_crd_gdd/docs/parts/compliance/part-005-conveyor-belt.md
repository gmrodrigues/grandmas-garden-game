## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-005-conveyor-belt.md` describes part type `5`
- **When** parsed
- **Then** `part_num == 5`

### TC-002: Mass value is positive
- **Given** Conveyor Belt has `mass = 3776`
- **When** validated
- **Then** `mass > 0`

### TC-003: 10 ANM states (5 widths × 2 for direction)
- **Given** Conveyor Belt ANM shows `Total States = 10`
- **When** rendered
- **Then** states map to 5 size variants × 2 animation directions

### TC-004: Electrical connection required
- **Given** Conveyor Belt shows `Electrical: Yes`
- **When** motor starts
- **Then** conveyor belt activates

### TC-005: Belt and Rope connections supported
- **Given** Conveyor Belt shows `Belt=Yes`, `Rope=Yes`
- **When** connected to motor
- **Then** torque is transmitted

### TC-006: Triggers include collision, electrical, rope
- **Given** Conveyor Belt shows `Triggers: collision, electrical, rope`
- **When** any trigger activates
- **Then** belt motion state changes

### TC-007: 20 PLAY_SFX opcodes (belt movement sound)
- **Given** Conveyor Belt ANM has `PLAY_SFX: 20`
- **When** belt is running
- **Then** mechanical sound plays

### TC-008: Animation frames tied to state
- **Given** Belt has 5 width variants: 32, 48, 64, 80, 96 pixels
- **When** gizmo stretches belt
- **Then** appropriate ANM state is selected

### TC-009: Part used in 61 levels
- **Given** Conveyor Belt (type 5)
- **When** checked against YAML levels
- **Then** at least 61 levels reference it

### TC-010: Conveyor belt moves objects on collision
- **Given** object placed on active conveyor belt
- **When** physics tick runs
- **Then** object velocity += belt_speed (direction based on belt orientation)

### TC-011: Belt speed standardized at ±60px/s
- **Given** Conveyor Belt is active
- **When** `belt_speed` is applied to object
- **Then** speed magnitude is `±60px/s` per `02_core_mechanics.md`

### TC-012: Motor connection starts belt
- **Given** Conveyor Belt connected to Mouse Motor via belt
- **When** motor runs
- **Then** belt animation starts

### TC-013: Category Part Count is 7
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Rotating Power Sources category

### TC-014: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-015: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** no direct player interaction
