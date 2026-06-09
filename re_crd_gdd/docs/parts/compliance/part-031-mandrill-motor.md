## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-031-mandrill-motor.md` describes part type `31`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 31`

### TC-002: Mass value is positive
- **Given** Mandrill Motor has `mass = 3776`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Mandrill Motor has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: SOLVE.RES state transitions (Sitting → Treading → Bonked)
- **Given** Mandrill Motor has 3 states: Sitting (`1→4`), Treading (`4→7`), Bonked (`7→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Terminal state Bonked (part removed)
- **Given** State Machine shows `Bonked: 7→-1`
- **When** state reaches Bonked
- **Then** part is removed from simulation (terminal)

### TC-006: Belt connection to power other parts
- **Given** Description: "Attach a belt to the treadmill to power anything that is driven with a belt"
- **When** belt connects motor to generator/fan
- **Then** rotational power is transferred

### TC-007: 7 ANM states
- **Given** Mandrill Motor ANM has `Total States = 7`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 7`

### TC-008: Animated Section A (185 duration entries)
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 185 entries`
- **When** animation renderer processes frame timing
- **Then** durations control playback speed at 60 Hz

### TC-009: Part used in 9 levels
- **Given** Mandrill Motor (type 31)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 9 levels reference `part_num = 31`

### TC-010: Triggers are collision, electrical, rope
- **Given** Category Rules show `Triggers: collision, electrical, rope`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-011: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-012: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** motor requires rope activation by player

### TC-013: Belt Connection flag is Yes
- **Given** Connections & Capabilities shows `Belt Connection = Yes`
- **When** belt is attached
- **Then** rotational power is transferred to connected part

### TC-014: Rope-activated shade trigger
- **Given** Description: "tie a rope to the shade and give it a tug"
- **When** rope pulls shade
- **Then** motor starts pedaling

### TC-015: Category Part Count is 7
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Rotating Power Sources category

---

## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-031-mandrill-motor.md` describes part type `31`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 31`

### TC-002: Mass value is positive
- **Given** Mandrill Motor has `mass = 3776`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Mandrill Motor has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: 3 SOLVE.RES states (Sitting → Treading → Bonked)
- **Given** Mandrill Motor has states: Sitting (`1→4`), Treading (`4→7`), Bonked (`7→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Belt connection to power devices
- **Given** Description: "Attach a belt to the treadmill to power anything that is driven with a belt"
- **When** belt connects motor to device
- **Then** rotational power is transferred

### TC-006: Rope trigger for activation
- **Given** Description: "tie a rope to the shade and give it a tug"
- **When** rope pulls shade
- **Then** motor starts pedaling

### TC-007: 7 ANM states with timed animation (185 duration entries)
- **Given** Mandrill Motor ANM has `Total States = 7`, `Section A Durations: 185 entries`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 7`

### TC-008: Animated Section A controls playback
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 185 entries`
- **When** animation renderer processes frame timing
- **Then** durations control playback speed at 60 Hz

### TC-009: Part used in 9 levels
- **Given** Mandrill Motor (type 31)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 9 levels reference `part_num = 31`

### TC-010: Triggers include collision, electrical, rope
- **Given** Category Rules show `Triggers: collision, electrical, rope`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-011: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-012: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** motor can be rope-activated

### TC-013: Belt Connection flag is Yes
- **Given** Connections & Capabilities shows `Belt Connection = Yes`
- **When** belt is attached
- **Then** rotational power is transferred to connected part

### TC-014: Terminal state Bonked (part removed)
- **Given** State Machine shows `Bonked: 7→-1`
- **When** state reaches Bonked
- **Then** part is removed from simulation (terminal)

### TC-015: Category Part Count is 7
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Rotating Power Sources category
