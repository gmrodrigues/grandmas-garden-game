## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-053-thumb-tack.md` describes part type `53`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 53`

### TC-002: Popping capability for blimps and balloons
- **Given** Description: "This thumb tack is handy for popping blimps and balloons"
- **When** balloon/blimp contacts thumb tack point
- **Then** target is destroyed

### TC-003: Part used in 34 levels
- **Given** Thumb Tack (type 53)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 34 levels reference `part_num = 53`

### TC-004: No triggers defined (passive popping)
- **Given** Category Rules show `Triggers: (none)` or collision-only
- **When** behavior handler evaluates
- **Then** popping occurs on contact

### TC-005: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-006: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** thumb tack is passive obstacle

### TC-007: Cutting / Popping category
- **Given** Category shows `Cutting / Popping`
- **When** behavior handler processes
- **Then** popping mechanic is applied

### TC-008: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** thumb tack is not destroyed

### TC-009: No electrical/belt/rope/fire/laser connections
- **Given** Connections & Capabilities shows most flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-010: Flip capability changes point direction
- **Given** Description: "It can be flipped so that the point is facing up, down, or either side"
- **When** player flips thumb tack
- **Then** pop direction changes

### TC-011: Category Part Count is 3
- **Given** Category Rules show `Category Part Count: 3`
- **When** validated
- **Then** 3 parts in Cutting / Popping category

### TC-012: Collision trigger activates popping
- **Given** Thumb tack is stationary
- **When** balloon/blimp contacts point
- **Then** target is popped

### TC-013: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-014: Sprite existence validation
- **Given** Thumb Tack ANM references sprite files
- **When** `decoder/d_t2anm.py` parses Section D
- **Then** all referenced PNGs exist in `build/phase-3/bitmaps/`

### TC-015: Level YAML cross-reference
- **Given** Thumb Tack appears in level YAML files
- **When** `validate_spec.py` loads level
- **Then** thumb tack part is correctly instantiated
