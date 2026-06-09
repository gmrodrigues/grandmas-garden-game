## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-032-boris-the-bat.md` describes part type `32`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 32`

### TC-002: Mass value is positive
- **Given** Boris the Bat has `mass = 2400`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Boris the Bat has `property_q8 = 64`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (64 >> 8) <= 1.0` i.e. `COR = 0.250`

### TC-004: No SOLVE.RES state transitions
- **Given** Boris the Bat has no programmatic state transitions
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-005: 2 ANM states (state IDs 1-2)
- **Given** Boris the Bat ANM has `Total States = 2`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 2`

### TC-006: Animated Section A (6 duration entries)
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 6 entries`
- **When** animation renderer processes frame timing
- **Then** durations control playback speed at 60 Hz

### TC-007: Sound effect on flight activation
- **Given** Sound Effects table shows frame 2 triggers sound ID `3032`
- **When** animation reaches frame 2
- **Then** `PLAY_SFX` opcode dispatches sound ID `3032`

### TC-008: Triggers are collision and proximity
- **Given** Category Rules show `Triggers: collision, proximity`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-009: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-010: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** bat activates passively on bump

### TC-011: Not used in any built-in level
- **Given** Boris the Bat has no level references
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** no built-in level references `part_num = 32`

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** bat is not destroyed

### TC-013: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-014: Hangs in mid-air until bumped
- **Given** Description: "He hangs in mid-air until he's bumped. Then he flies around acting batty"
- **When** collision or proximity trigger fires
- **Then** bat enters flying state

### TC-015: Category Part Count is 8
- **Given** Category Rules show `Category Part Count: 8`
- **When** validated
- **Then** 8 parts in Characters category

---

## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-032-boris-the-bat.md` describes part type `32`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 32`

### TC-002: Mass value is positive
- **Given** Boris the Bat has `mass = 2400`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Boris the Bat has `property_q8 = 64`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (64 >> 8) <= 1.0` i.e. `COR = 0.250`

### TC-004: Not used in any built-in level
- **Given** Boris the Bat is a Character type
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** no built-in level references `part_num = 32`

### TC-005: 2 ANM states with animated flight
- **Given** Boris the Bat ANM has `Total States = 2`, `Section A Durations: 6 entries`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 2`

### TC-006: Animated Section A for bat movement
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 6 entries`
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

### TC-009: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** bat behavior is automatic (AI-driven)

### TC-010: Character AI activates on bump
- **Given** Description: "He hangs in mid-air until he's bumped. Then he flies around acting batty"
- **When** collision or proximity trigger fires
- **Then** bat enters flying state

### TC-011: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** bat is not destroyed

### TC-012: Sound effect on flight activation
- **Given** Sound Effects show `Frame 2: Sound ID 3032`
- **When** bat enters flying state
- **Then** `PLAY_SFX` opcode dispatches sound ID `3032`

### TC-013: Bitmap dimensions 22×54
- **Given** Physics Properties show `bitmap_w = 22`, `bitmap_h = 54`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-014: Category Part Count is 8
- **Given** Category Rules show `Category Part Count: 8`
- **When** validated
- **Then** 8 parts in Characters category

### TC-015: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections
