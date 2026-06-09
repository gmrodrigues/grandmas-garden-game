## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-037-hedge-trimmers.md` describes part type `37`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 37`

### TC-002: Mass value is positive
- **Given** Hedge Trimmers has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Hedge Trimmers has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: SOLVE.RES state transitions
- **Given** Hedge Trimmers has named state transitions
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Cuts rope connections
- **Given** Description: "You can cut ropes with these hedge trimmers"
- **When** trimmer blades contact rope
- **Then** rope connection is severed

### TC-006: Pops balloons and blimps
- **Given** Description: "Balloons and blimps pop against the tips"
- **When** balloon/blimp contacts trimmer tips
- **Then** target is destroyed

### TC-007: Collision trigger activates
- **Given** Category Rules show `Triggers: collision`
- **When** object bumps trimmers
- **Then** cutting animation plays

### TC-008: Part used in 51 levels
- **Given** Hedge Trimmers (type 37)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 51 levels reference `part_num = 37`

### TC-009: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-010: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** trimmers respond to object collision

### TC-011: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** trimmers are not destroyed

### TC-012: No electrical/belt/rope/fire/laser connections
- **Given** Connections & Capabilities shows all mechanical connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-013: Category Part Count is 3
- **Given** Category Rules show `Category Part Count: 3`
- **When** validated
- **Then** 3 parts in Cutting / Popping category

### TC-014: Bitmap dimensions 55×36
- **Given** Physics Properties show `bitmap_w = 55`, `bitmap_h = 36`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-015: Rope can be cut by mechanical interaction
- **Given** Rope exists between two objects
- **When** Hedge Trimmers (type 37) contact rope
- **Then** rope connection is severed (per Q-018 rope constraint)
