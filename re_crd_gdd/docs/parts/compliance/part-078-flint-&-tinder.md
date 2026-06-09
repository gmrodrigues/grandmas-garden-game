## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-078-flint-&-tinder.md` describes part type `78`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 78`

### TC-002: Mass value is positive
- **Given** Flint & Tinder has `mass = 4000`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Flint & Tinder has `property_q8 = 96`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 0.375`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** flint & tinder responds to proximity/electrical triggers

### TC-006: Fire/Flame connection supported
- **Given** Connections & Capabilities shows `Fire/Flame: Yes`
- **When** behavior handler evaluates
- **Then** fire spawn behavior is enabled

### TC-007: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical: Yes`
- **When** behavior handler evaluates
- **Then** electrical triggers are registered

### TC-008: SOLVE.RES state transitions (Unlit → Lit)
- **Given** Flint & Tinder has states: Unlit (`1→2`) and Lit (`2→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-009: Terminal state Lit (part removed)
- **Given** State Machine shows `Lit: 2→-1`
- **When** state reaches Lit
- **Then** part is removed from simulation (terminal)

### TC-010: Triggers are proximity and electrical
- **Given** Category Rules show `Triggers: proximity, electrical`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-011: Spawns fire
- **Given** Category Rules show `Spawns: fire`
- **When** flint & tinder is bumped
- **Then** fire is spawned at location

### TC-012: Part used in 44 levels
- **Given** Flint & Tinder (type 78)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 44 levels reference `part_num = 78`

### TC-013: Light / Flame Sources category (Category Part Count = 5)
- **Given** Category Rules show `Category Part Count: 5`
- **When** validated
- **Then** 5 parts in Light / Flame Sources category

### TC-014: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** flint & tinder is not destroyed

### TC-015: 32 total animation frames across 4 states
- **Given** ANM shows `Total Frames: 32`, `Total States: 4`
- **When** animation renderer processes
- **Then** all 32 frames map to correct states

### TC-016: Bump ignition lights fire
- **Given** Description: "Bump these flint rocks to start a fire"
- **When** collision or proximity trigger fires
- **Then** flint & tinder enters Lit state and spawns fire
