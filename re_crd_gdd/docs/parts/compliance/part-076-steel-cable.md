## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-076-steel-cable.md` describes part type `76`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 76`

### TC-002: Mass value is positive
- **Given** Steel Cable has `mass = 1600`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 is zero
- **Given** Steel Cable has `property_q8 = 0`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 0.000`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** steel cable is static constraint

### TC-006: Belt connection supported
- **Given** Connections & Capabilities shows `Belt Connection: Yes`
- **When** behavior handler evaluates
- **Then** belt constraint is registered

### TC-007: Rope connection supported
- **Given** Connections & Capabilities shows `Rope Connection: Yes`
- **When** behavior handler evaluates
- **Then** rope constraint is registered

### TC-008: No triggers (static constraint)
- **Given** Category Rules show `Triggers: *(none)*`
- **When** behavior handler evaluates
- **Then** no triggers are registered

### TC-009: Part used in 14 levels
- **Given** Steel Cable (type 76)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 14 levels reference `part_num = 76`

### TC-010: Ropes / Belts / Pulleys category (Category Part Count = 4)
- **Given** Category Rules show `Category Part Count: 4`
- **When** validated
- **Then** 4 parts in Ropes / Belts / Pulleys category

### TC-011: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** steel cable is not destroyed

### TC-012: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-013: Bitmap dimensions 11×10
- **Given** Physics Properties show `bitmap_w = 11`, `bitmap_h = 10`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-014: No SOLVE.RES state transitions (static part)
- **Given** State Machine shows *No SOLVE.RES state data — this part has no programmatic state transitions*
- **When** behavior handler evaluates
- **Then** no state transitions are triggered

### TC-015: Cut only by tin snips
- **Given** Description: "This steel cable works just like rope, except it's much stronger. It can only be cut with tin snips"
- **When** object other than tin snips contacts cable
- **Then** cable remains intact
