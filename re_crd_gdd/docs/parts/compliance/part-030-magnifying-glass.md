## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-030-magnifying-glass.md` describes part type `30`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 30`

### TC-002: Mass value is positive
- **Given** Magnifying Glass has `mass = 3776`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Magnifying Glass has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: Spawns laser beam
- **Given** Category Rules show `Spawns: laser_beam`
- **When** light source shines through glass
- **Then** focused laser beam is emitted

### TC-005: No SOLVE.RES state transitions
- **Given** Magnifying Glass has no programmatic state transitions
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-006: 1 ANM state (single frame)
- **Given** Magnifying Glass ANM has `Total States = 1`, `Total Frames = 1`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 1`

### TC-007: Part used in 52 levels
- **Given** Magnifying Glass (type 30)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 52 levels reference `part_num = 30`

### TC-008: Triggers include electrical, proximity, collision
- **Given** Category Rules show `Triggers: electrical, proximity, collision`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-009: Laser connection supported
- **Given** Connections & Capabilities shows `Laser = Yes`
- **When** checked against `category_rules`
- **Then** part emits laser beam

### TC-010: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical = Yes`
- **When** checked against `category_rules`
- **Then** part can interact with electrical systems

### TC-011: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-012: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** magnifying glass activates passively with light

### TC-013: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** magnifying glass is not destroyed

### TC-014: Can ignite fuses and candles
- **Given** Description: "Place this magnifying glass in front of any light source to ignite fuses or candles"
- **When** laser beam hits fuse/candle
- **Then** target is ignited

### TC-015: Category Part Count is 8
- **Given** Category Rules show `Category Part Count: 8`
- **When** validated
- **Then** 8 parts in Lasers / Optics category
