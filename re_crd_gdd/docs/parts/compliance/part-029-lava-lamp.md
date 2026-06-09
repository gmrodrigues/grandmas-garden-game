## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-029-lava-lamp.md` describes part type `29`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 29`

### TC-002: Mass value is positive
- **Given** Lava Lamp has `mass = 1300`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Lava Lamp has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: SOLVE.RES state transitions (Off → On)
- **Given** Lava Lamp has 2 states: Off (`1→2`) and On (`2→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Terminal state On (part removed)
- **Given** State Machine shows `On: 2→-1`
- **When** state reaches On
- **Then** part is removed from simulation (terminal)

### TC-006: Spawns fire (light source)
- **Given** Category Rules show `Spawns: fire`
- **When** lava lamp is activated
- **Then** fire/light beam is emitted

### TC-007: Triggers are proximity and electrical
- **Given** Category Rules show `Triggers: proximity, electrical`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-008: Part used in 19 levels
- **Given** Lava Lamp (type 29)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 19 levels reference `part_num = 29`

### TC-009: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-010: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** lava lamp can be rope-activated

### TC-011: Rope chain pull activation
- **Given** Description: "Tie a rope to the chain and give it a tug to turn on the lamp"
- **When** rope pulls chain
- **Then** lamp state changes from Off to On

### TC-012: Powers solar panels (light energy)
- **Given** Description: "Use it to power up the solar panel"
- **When** lamp is On and solar panel is nearby
- **Then** electrical power is generated

### TC-013: Can light fuses through magnifying glass
- **Given** Description: "shine it through a magnifying glass to light fuses and candles"
- **When** light beam intersects magnifying glass
- **Then** focused beam ignites fuse/candle

### TC-014: Animated Section A (22 duration entries)
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 22 entries`
- **When** animation renderer processes frame timing
- **Then** durations control playback speed at 60 Hz

### TC-015: 3 ANM states (state IDs 1, 2, 3)
- **Given** Lava Lamp ANM has `Total States = 3`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 3`
