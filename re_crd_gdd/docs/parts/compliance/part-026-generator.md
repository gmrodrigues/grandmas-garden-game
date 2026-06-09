## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-026-generator.md` describes part type `26`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 26`

### TC-002: Mass value is positive
- **Given** Generator has `mass = 3776`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Generator has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: SOLVE.RES state transitions (Off → On)
- **Given** Generator has 2 states: Off (`9→10`) and On (`2→3`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Belt connection to power rotating parts
- **Given** Description: "Attach a belt to the treadmill to power anything that is driven with a belt"
- **When** belt connects generator to motor
- **Then** rotational power is transferred

### TC-006: 8 ANM states (state IDs span multiple values)
- **Given** Generator ANM has `Total States = 8`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 8`

### TC-007: Part used in 15 levels
- **Given** Generator (type 26)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 15 levels reference `part_num = 26`

### TC-008: Triggers are electrical and collision
- **Given** Category Rules show `Triggers: electrical, collision`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-009: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-010: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** generator can be manually activated

### TC-011: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical = Yes`
- **When** checked against `category_rules`
- **Then** generator has its own outlet for electrical parts

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** generator is not destroyed

### TC-013: Belt Connection flag is Yes
- **Given** Connections & Capabilities shows `Belt Connection = Yes`
- **When** belt is attached
- **Then** rotational power is transferred to connected part

### TC-014: Bitmap dimensions 81×34
- **Given** Physics Properties show `bitmap_w = 81`, `bitmap_h = 34`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-015: Category Part Count is 9
- **Given** Category Rules show `Category Part Count: 9`
- **When** validated
- **Then** 9 parts in Electrical category
