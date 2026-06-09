## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-021-electric-switch-&-outlet.md` describes part type `21`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 21`

### TC-002: Mass value is positive
- **Given** Electric Switch & Outlet has `mass = 3776`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Electric Switch & Outlet has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical = Yes`
- **When** checked against `category_rules`
- **Then** electrical parts can be plugged in

### TC-005: 8 ANM states (state IDs 6-13)
- **Given** Electric Switch & Outlet ANM has `Total States = 8`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 8`

### TC-006: No SOLVE.RES state transitions
- **Given** Electric Switch & Outlet has no programmatic state transitions
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-007: Part used in 54 levels
- **Given** Electric Switch & Outlet (type 21)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 54 levels reference `part_num = 21`

### TC-008: No belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows `Belt=No`, `Rope=No`, `Fire=No`, `Laser=No`, `Projectile=No`
- **When** checked against `category_rules`
- **Then** only `Electrical=Yes`

### TC-009: Triggers are electrical and collision
- **Given** Category Rules show `Triggers: electrical, collision`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-010: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-011: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** switch does not require user interaction to activate

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** switch is not destroyed

### TC-013: Bitmap dimensions 32×32
- **Given** Physics Properties show `bitmap_w = 32`, `bitmap_h = 32`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-014: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-015: 24 DRAW_BMP opcodes across 8 states
- **Given** Bytecode Opcodes show `DRAW_BMP = 24` across 8 states
- **When** bytecode is executed
- **Then** each frame renders correct sprites for that state
