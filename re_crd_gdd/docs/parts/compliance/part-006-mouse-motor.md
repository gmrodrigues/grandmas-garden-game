## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-006-mouse-motor.md` describes part type `6`
- **When** parsed
- **Then** `part_num == 6`

### TC-002: Mass value is positive
- **Given** Mouse Motor has `mass = 3776`
- **When** validated
- **Then** `mass > 0`

### TC-003: property_q8 encodes rotation speed
- **Given** Mouse Motor has `property_q8 = 1024` (Q8.8 = 4.000)
- **When** motor runs
- **Then** angular velocity is set per property

### TC-004: SOLVE.RES transition to Running state
- **Given** Mouse Motor transitions `3→6` (Not Running → Running)
- **When** collision/electrical/rope trigger occurs
- **Then** ANM state becomes `6`

### TC-005: Terminal state removes part from sim
- **Given** Mouse Motor transitions to `6→-1`
- **When** Running animation completes
- **Then** `part is removed from simulation`

### TC-006: Timed Section A animation at 60Hz
- **Given** Mouse Motor has `Animated (Section A): Yes` with 36 entries
- **When** simulation tick runs
- **Then** animation advances at 60 Hz rate

### TC-007: PLAY_SFX at frame 12 (squeak sound)
- **Given** Mouse Motor ANM has `PLAY_SFX: 1` at frame 12
- **When** running animation reaches frame 12
- **Then** `SX_3006_11025.wav` plays

### TC-008: Electrical connection supported
- **Given** Mouse Motor shows `Electrical: Yes`
- **When** connected to power network
- **Then** can be activated remotely

### TC-009: Belt connection to conveyor/gear
- **Given** Mouse Motor shows `Belt: Yes`
- **When** belt connects to other rotating parts
- **Then** torque is transmitted

### TC-010: Part used in 44 levels
- **Given** Mouse Motor (type 6)
- **When** checked against YAML levels
- **Then** at least 44 levels reference it

### TC-011: Mouse in cage animation
- **Given** Description: "bump cage to make mouse run around on wheel"
- **When** activated
- **Then** 31-frame animation shows mouse running

### TC-012: Belt connection starts motor
- **Given** Mouse Motor connected via belt to conveyor
- **When** motor runs
- **Then** connected parts receive angular velocity

### TC-013: Category Part Count is 7
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Rotating Power Sources category

### TC-014: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-015: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** player bumps cage
- **Then** motor starts running
