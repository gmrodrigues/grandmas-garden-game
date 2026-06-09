## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-025-flashlight.md` describes part type `25`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 25`

### TC-002: Mass value is positive
- **Given** Flashlight has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Flashlight has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: SOLVE.RES state transitions (Off → On)
- **Given** Flashlight has 2 states: Off and On
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Terminal state On (part removed)
- **Given** Flashlight State Machine shows `On: 2→-1`
- **When** state reaches On
- **Then** part is removed from simulation (terminal)

### TC-006: Spawns fire (light source)
- **Given** Category Rules show `Spawns: fire`
- **When** flashlight is activated
- **Then** fire/light beam is emitted

### TC-007: Triggers are proximity and electrical
- **Given** Category Rules show `Triggers: proximity, electrical`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-008: Part used in 55 levels
- **Given** Flashlight (type 25)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 55 levels reference `part_num = 25`

### TC-009: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-010: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** flashlight can be manually activated

### TC-011: Powers solar panels (electrical output)
- **Given** Description: "Use it to power solar panels"
- **When** flashlight is On
- **Then** electrical power is supplied to connected parts

### TC-012: Can light fuses with magnifying glass
- **Given** Description: "put a magnifying glass right in front of it and use it to light fuses and candles"
- **When** light beam intersects magnifying glass
- **Then** focused beam ignites fuse/candle

### TC-013: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** flashlight is not destroyed

### TC-014: Bitmap dimensions 46×21
- **Given** Physics Properties show `bitmap_w = 46`, `bitmap_h = 21`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-015: Category Part Count is 5
- **Given** Category Rules show `Category Part Count: 5`
- **When** validated
- **Then** 5 parts in Light / Flame Sources category
