## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-086-tiny-gear.md` describes part type `86`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 86`

### TC-002: Mass value is positive
- **Given** Tiny Gear has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Tiny Gear has `property_q8 = 1024`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 4.000`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** tiny gear rotates automatically when connected to motor

### TC-006: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical: Yes`
- **When** behavior handler evaluates
- **Then** electrical triggers are registered

### TC-007: Belt connection supported
- **Given** Connections & Capabilities shows `Belt Connection: Yes`
- **When** behavior handler evaluates
- **Then** belt constraint is registered

### TC-008: Rope connection supported
- **Given** Connections & Capabilities shows `Rope Connection: Yes`
- **When** behavior handler evaluates
- **Then** rope constraint is registered

### TC-009: Triggers are collision, electrical, rope
- **Given** Category Rules show `Triggers: collision, electrical, rope`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-010: Part used in 16 levels
- **Given** Tiny Gear (type 86)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 16 levels reference `part_num = 86`

### TC-011: Rotating Power Sources category (Category Part Count = 7)
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Rotating Power Sources category

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** tiny gear is not destroyed

### TC-013: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-014: Bitmap dimensions 17×17
- **Given** Physics Properties show `bitmap_w = 17`, `bitmap_h = 17`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-015: Rotates at 2× speed of big gear
- **Given** Description: "This tiny gear rotates at twice the speed of a big gear when it's placed next to one"
- **When** gear train is connected to motor
- **Then** tiny gear angular velocity = 2× big gear angular velocity
