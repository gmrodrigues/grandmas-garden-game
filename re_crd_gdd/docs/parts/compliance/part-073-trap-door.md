## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-073-trap-door.md` describes part type `73`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 73`

### TC-002: Mass value is positive
- **Given** Trap Door has `mass = 1000`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Trap Door has `property_q8 = 512`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 2.000`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** trap door responds to heavy objects landing

### TC-006: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical: Yes`
- **When** behavior handler evaluates
- **Then** electrical triggers are registered

### TC-007: SOLVE.RES state transitions (Up → Down)
- **Given** Trap Door has states: Up (`2→3`) and Down (`3→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-008: Terminal state Down (part removed)
- **Given** State Machine shows `Down: 3→-1`
- **When** state reaches Down
- **Then** part is removed from simulation (terminal)

### TC-009: Triggers are collision, electrical, proximity
- **Given** Category Rules show `Triggers: collision, electrical, proximity`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-010: Part used in 33 levels
- **Given** Trap Door (type 73)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 33 levels reference `part_num = 73`

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
- **Then** trap door is not destroyed

### TC-014: Bitmap dimensions 48×49
- **Given** Physics Properties show `bitmap_w = 48`, `bitmap_h = 49`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-015: Drops open when heavy objects land
- **Given** Description: "This trap door drops open when heavy objects land on top of it"
- **When** object with sufficient mass lands on trap door
- **Then** trap door transitions to Down state
