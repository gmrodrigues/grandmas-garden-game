## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-050-electric-motor.md` describes part type `50`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 50`

### TC-002: Mass value is positive
- **Given** Electric Motor has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Electric Motor has `property_q8 = 1024`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (1024 >> 8) <= 1.0` i.e. `COR = 4.000`

### TC-004: SOLVE.RES state transitions
- **Given** Electric Motor has named state transitions
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Belt connection to power devices
- **Given** Description: "use a belt to attach it to gears, conveyor belts, and other rotating parts"
- **When** belt connects motor to device
- **Then** rotational power is transferred

### TC-006: Electrical activation via outlet
- **Given** Description: "Plug this electric motor into an outlet and flick on the switch"
- **When** connected to electrical outlet
- **Then** motor activates

### TC-007: Part used in 32 levels
- **Given** Electric Motor (type 50)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 32 levels reference `part_num = 50`

### TC-008: Triggers include collision, electrical, rope
- **Given** Category Rules show `Triggers: collision, electrical, rope`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-009: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-010: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** motor can be manually activated

### TC-011: Belt Connection flag is Yes
- **Given** Connections & Capabilities shows `Belt Connection = Yes`
- **When** belt is attached
- **Then** rotational power is transferred to connected part

### TC-012: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical = Yes`
- **When** checked against `category_rules`
- **Then** motor can be plugged into outlet

### TC-013: Category Part Count is 7
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Rotating Power Sources category

### TC-014: Flip capability changes motor orientation
- **Given** Description: "This motor can also be flipped"
- **When** player flips motor
- **Then** belt connection orientation changes

### TC-015: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** motor is not destroyed
