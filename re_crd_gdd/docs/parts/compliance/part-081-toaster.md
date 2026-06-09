## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-081-toaster.md` describes part type `81`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 81`

### TC-002: Mass value is positive
- **Given** Toaster has `mass = 3776`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Toaster has `property_q8 = 1024`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 4.000`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** toaster responds to electrical activation

### TC-006: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical: Yes`
- **When** behavior handler evaluates
- **Then** electrical triggers are registered

### TC-007: SOLVE.RES state transitions (Not Toasting → Toasting)
- **Given** Toaster has states: Not Toasting (`1→8`, `6→9`, `7→10`) and Toasting (`2→6`, `3→7`, `4→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-008: Terminal state Toasting (part removed)
- **Given** State Machine shows `Toasting: 4→-1`
- **When** state reaches Toasting
- **Then** part is removed from simulation (terminal)

### TC-009: Triggers are electrical and collision
- **Given** Category Rules show `Triggers: electrical, collision`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-010: Part used in 12 levels
- **Given** Toaster (type 81)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 12 levels reference `part_num = 81`

### TC-011: Electrical category (Category Part Count = 9)
- **Given** Category Rules show `Category Part Count: 9`
- **When** validated
- **Then** 9 parts in Electrical category

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** toaster is not destroyed

### TC-013: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-014: 48 total animation frames across 9 states
- **Given** ANM shows `Total Frames: 48`, `Total States: 9`
- **When** animation renderer processes
- **Then** all 48 frames map to correct states

### TC-015: Toast pops up after timer (darkness programmable)
- **Given** Description: "You can also program it to work as a timer. The darker the toast you choose, the longer the amount of time it takes to pop up"
- **When** toasting timer completes
- **Then** toast pops upward with velocity
