## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-069-anti-gravity-pad.md` describes part type `69`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 69`

### TC-002: Mass value is positive
- **Given** Anti-Gravity Pad has `mass = 3776`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Anti-Gravity Pad has `property_q8 = 1024`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 4.000`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** anti-gravity pad responds to triggers

### TC-006: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical: Yes`
- **When** behavior handler evaluates
- **Then** electrical triggers are registered

### TC-007: SOLVE.RES state transitions (Unactivated → Operating)
- **Given** Anti-Gravity Pad has states: Unactivated (`1→2`) and Operating (`2→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-008: Terminal state Operating (part removed)
- **Given** State Machine shows `Operating: 2→-1`
- **When** state reaches Operating
- **Then** part is removed from simulation (terminal)

### TC-009: Triggers are collision, electrical, proximity
- **Given** Category Rules show `Triggers: collision, electrical, proximity`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-010: Part used in 76 levels (highest usage)
- **Given** Anti-Gravity Pad (type 69)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 76 levels reference `part_num = 69`

### TC-011: Custom spawn behavior
- **Given** Category Rules show `Spawns: custom`
- **When** behavior handler processes
- **Then** custom spawn logic is applied

### TC-012: Special Mechanics category (Category Part Count = 15)
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Special Mechanics category

### TC-013: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** anti-gravity pad is not destroyed

### TC-014: Bitmap dimensions 48×16
- **Given** Physics Properties show `bitmap_w = 48`, `bitmap_h = 16`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-015: Gravity reversal affects balloons inversely
- **Given** Description: "Without gravity, most things will float up into the air. But balloons will drop"
- **When** object lands on anti-gravity pad
- **Then** gravity field is reversed for normal objects but inverted for balloons
