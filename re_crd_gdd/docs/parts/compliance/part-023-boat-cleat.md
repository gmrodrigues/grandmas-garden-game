## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-023-boat-cleat.md` describes part type `23`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 23`

### TC-002: Mass value is positive
- **Given** Boat Cleat has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Boat Cleat has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: Rope connection supported
- **Given** Description: "Any object that can be tied with a rope may be hitched to this boat cleat"
- **When** rope is attached
- **Then** `rope_info_1/2` stores connected part indices

### TC-005: No SOLVE.RES state transitions
- **Given** Boat Cleat has no programmatic state transitions
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-006: Part used in 75 levels
- **Given** Boat Cleat (type 23)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 75 levels reference `part_num = 23`

### TC-007: Triggers include collision, electrical, proximity
- **Given** Category Rules show `Triggers: collision, electrical, proximity`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-008: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-009: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** boat cleat does not require user interaction

### TC-010: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** boat cleat is not destroyed

### TC-011: Bitmap dimensions 30×15
- **Given** Physics Properties show `bitmap_w = 30`, `bitmap_h = 15`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-012: Category Part Count is 15
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Special Mechanics category

### TC-013: Anchor point for rope connections
- **Given** Boat Cleat is used to "hang things from the air, or to keep balloons from floating away"
- **When** rope placement connects
- **Then** cleat acts as fixed anchor point

### TC-014: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-015: No belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows only default connections
- **When** checked against `category_rules`
- **Then** rope is a logical connector, not a connection flag
