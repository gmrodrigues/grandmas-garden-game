## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-034-santa-claus.md` describes part type `34`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 34`

### TC-002: Mass value is positive
- **Given** Santa Claus has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Santa Claus has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: SOLVE.RES state transitions (Off → On)
- **Given** Santa Claus has 2 primary states: Off (`1→2`) and On (`2→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Terminal state On (part removed)
- **Given** State Machine shows `On: 2→-1`
- **When** state reaches On
- **Then** part is removed from simulation (terminal)

### TC-006: 2 ANM states (state IDs 1-2)
- **Given** Santa Claus ANM has `Total States = 2`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 2`

### TC-007: Animated Section A (56 duration entries)
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 56 entries`
- **When** animation renderer processes frame timing
- **Then** durations control playback speed at 60 Hz

### TC-008: Triggers are collision and proximity
- **Given** Category Rules show `Triggers: collision, proximity`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-009: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-010: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** santa can be activated by player

### TC-011: Not used in any built-in level
- **Given** Santa Claus has no level references
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** no built-in level references `part_num = 34`

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** santa is not destroyed

### TC-013: Electrical activation via socket
- **Given** Description: "This cheesy plastic Santa Claus lamp will only light up when you place it next to an electric socket"
- **When** connected to electrical outlet
- **Then** lamp state changes from Off to On

### TC-014: Category Part Count is 8
- **Given** Category Rules show `Category Part Count: 8`
- **When** validated
- **Then** 8 parts in Characters category

### TC-015: 13 frames alternating between 2 sprites
- **Given** Santa Claus ANM has `Total Frames = 13`
- **When** bytecode is executed
- **Then** frames alternate between sprite 0 and 1

---

## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-034-santa-claus.md` describes part type `34`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 34`

### TC-002: Mass value is positive
- **Given** Santa Claus has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Santa Claus has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: 6 SOLVE.RES states (Off, On, !Part, Boxing Glove, Cocked, Punched)
- **Given** Santa Claus has states: Off (`1→2`), On (`2→-1`), !Part, Boxing Glove, Cocked (`2→3`), Punched (`3→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Not used in any built-in level
- **Given** Santa Claus is a Character type
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** no built-in level references `part_num = 34`

### TC-006: Animated Section A (56 duration entries)
- **Given** Santa Claus ANM has `Animated (Section A): Yes`, `Section A Durations: 56 entries`
- **When** animation renderer processes frame timing
- **Then** durations control playback speed at 60 Hz

### TC-007: Triggers are collision and proximity
- **Given** Category Rules show `Triggers: collision, proximity`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-008: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-009: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** santa can be activated by electrical connection

### TC-010: Electrical activation
- **Given** Description: "This cheesy plastic Santa Claus lamp will only light up when you place it next to an electric socket"
- **When** electrical connection is made
- **Then** santa lamp turns on

### TC-011: Terminal states On and Punched (part removed)
- **Given** State Machine shows `On: 2→-1`, `Punched: 3→-1`
- **When** state reaches terminal
- **Then** part is removed from simulation

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** santa is not destroyed

### TC-013: 2 ANM states (states 1-2)
- **Given** Santa Claus ANM has `Total States = 2`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 2`

### TC-014: Category Part Count is 8
- **Given** Category Rules show `Category Part Count: 8`
- **When** validated
- **Then** 8 parts in Characters category

### TC-015: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections
