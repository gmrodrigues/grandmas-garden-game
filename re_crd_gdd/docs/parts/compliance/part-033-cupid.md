## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-033-cupid.md` describes part type `33`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 33`

### TC-002: Mass value is positive
- **Given** Cupid has `mass = 11`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Cupid has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: No SOLVE.RES state transitions
- **Given** Cupid has no programmatic state transitions
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-005: 2 ANM states (state IDs 1-2)
- **Given** Cupid ANM has `Total States = 2`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 2`

### TC-006: Triggers are collision and proximity
- **Given** Category Rules show `Triggers: collision, proximity`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-007: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-008: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** cupid activates passively on bump

### TC-009: Not used in any built-in level
- **Given** Cupid has no level references
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** no built-in level references `part_num = 33`

### TC-010: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** cupid is not destroyed

### TC-011: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-012: Pops balloons on arrow contact
- **Given** Description: "Any balloons that touch his arrow will pop"
- **When** cupid arrow intersects balloon
- **Then** balloon is destroyed

### TC-013: Flies around on bump
- **Given** Description: "Bump him to make him fly around"
- **When** collision or proximity trigger fires
- **Then** cupid enters flying state

### TC-014: 5 frames with static animation
- **Given** Cupid ANM has `Total Frames = 5`, `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-015: Category Part Count is 8
- **Given** Category Rules show `Category Part Count: 8`
- **When** validated
- **Then** 8 parts in Characters category

---

## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-033-cupid.md` describes part type `33`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 33`

### TC-002: Mass value is positive
- **Given** Cupid has `mass = 11` (very light)
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Cupid has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: Not used in any built-in level
- **Given** Cupid is a Character type
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** no built-in level references `part_num = 33`

### TC-005: 2 ANM states (static animation)
- **Given** Cupid ANM has `Total States = 2`, `Animated (Section A): No`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 2`

### TC-006: Triggers are collision and proximity
- **Given** Category Rules show `Triggers: collision, proximity`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-007: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-008: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** cupid behavior is automatic (AI-driven)

### TC-009: Character AI activates on bump
- **Given** Description: "Bump him to make him fly around"
- **When** collision or proximity trigger fires
- **Then** cupid enters flying state

### TC-010: Pops balloons on contact
- **Given** Description: "Any balloons that touch his arrow will pop"
- **When** cupid arrow collides with balloon
- **Then** balloon is destroyed

### TC-011: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** cupid is not destroyed

### TC-012: Bitmap dimensions 67×50
- **Given** Physics Properties show `bitmap_w = 67`, `bitmap_h = 50`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-013: Category Part Count is 8
- **Given** Category Rules show `Category Part Count: 8`
- **When** validated
- **Then** 8 parts in Characters category

### TC-014: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-015: 5 frames across 2 states
- **Given** Cupid ANM has `Total Frames = 5`, `Total States = 2`
- **When** bytecode is executed
- **Then** state 1 has frame 0, state 2 has frames 1-4
