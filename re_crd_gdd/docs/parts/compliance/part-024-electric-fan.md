## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-024-electric-fan.md` describes part type `24`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 24`

### TC-002: Mass value is positive
- **Given** Electric Fan has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Electric Fan has `property_q8 = 1024`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (1024 >> 8) <= 1.0` i.e. `COR = 4.000`

### TC-004: SOLVE.RES state transitions (Off → On)
- **Given** Electric Fan has 2 states: Off (`1→2`) and On (`2→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Terminal state On (part removed)
- **Given** Electric Fan State Machine shows `On: 2→-1`
- **When** state reaches On
- **Then** part is removed from simulation (terminal)

### TC-006: 2 ANM states (state IDs 1-2)
- **Given** Electric Fan ANM has `Total States = 2`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 2`

### TC-007: 69 frames with animated fan blades
- **Given** Electric Fan ANM has `Total Frames = 69`
- **When** simulation runs
- **Then** frames 1-68 animate fan blades in On state

### TC-008: PLAY_SFX on each animation frame
- **Given** Bytecode Opcodes show `PLAY_SFX = 68`
- **When** animation runs
- **Then** each frame may trigger sound effect

### TC-009: Part used in 23 levels
- **Given** Electric Fan (type 24)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 23 levels reference `part_num = 24`

### TC-010: Triggers are electrical and collision
- **Given** Category Rules show `Triggers: electrical, collision`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-011: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-012: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** fan can be manually activated by player

### TC-013: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical = Yes`
- **When** checked against `category_rules`
- **Then** fan can be plugged into outlet

### TC-014: Wind direction flip capability
- **Given** Description: "Flip it to change wind direction"
- **When** player interacts with fan
- **Then** wind vector changes direction

### TC-015: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** fan is not destroyed
