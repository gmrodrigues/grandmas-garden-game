## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-038-solar-panel.md` describes part type `38`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 38`

### TC-002: Mass value is positive
- **Given** Solar Panel has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Solar Panel has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: No SOLVE.RES state transitions
- **Given** Solar Panel has no programmatic state transitions
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-005: 2 ANM states (state IDs 2-3)
- **Given** Solar Panel ANM has `Total States = 2`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 2`

### TC-006: Electrical power generation from light
- **Given** Description: "Shine a light on the panel, then plug in any electric part you want to operate"
- **When** light source (flashlight, lava lamp) shines on panel
- **Then** panel generates electrical power

### TC-007: Part used in 16 levels
- **Given** Solar Panel (type 38)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 16 levels reference `part_num = 38`

### TC-008: Triggers are electrical and collision
- **Given** Category Rules show `Triggers: electrical, collision`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-009: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-010: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** panel activates passively with light

### TC-011: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical = Yes`
- **When** checked against `category_rules`
- **Then** panel has outlet for electrical parts

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** panel is not destroyed

### TC-013: Category Part Count is 9
- **Given** Category Rules show `Category Part Count: 9`
- **When** validated
- **Then** 9 parts in Electrical category

### TC-014: 4 frames per state (8 total)
- **Given** Solar Panel ANM has frames 0-3 (state 3) and frames 4-7 (state 2)
- **When** bytecode is executed
- **Then** each state renders correct sprites

### TC-015: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty
