## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-077-tin-snips.md` describes part type `77`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 77`

### TC-002: Mass value is positive
- **Given** Tin Snips has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Tin Snips has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 0.500`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** tin snips respond to collision

### TC-006: SOLVE.RES state transitions (Open → Closed)
- **Given** Tin Snips has states: Open (`4→5`) and Closed (`3→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-007: Terminal state Closed (part removed)
- **Given** State Machine shows `Closed: 3→-1`
- **When** state reaches Closed
- **Then** part is removed from simulation (terminal)

### TC-008: Triggers are collision
- **Given** Category Rules show `Triggers: collision`
- **When** behavior handler evaluates
- **Then** collision trigger is registered

### TC-009: Part used in 6 levels
- **Given** Tin Snips (type 77)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 6 levels reference `part_num = 77`

### TC-010: Cutting / Popping category (Category Part Count = 3)
- **Given** Category Rules show `Category Part Count: 3`
- **When** validated
- **Then** 3 parts in Cutting / Popping category

### TC-011: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** tin snips are not destroyed

### TC-012: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-013: 4 total animation frames across 4 states
- **Given** ANM shows `Total Frames: 4`, `Total States: 4`
- **When** animation renderer processes
- **Then** all 4 frames map to correct states

### TC-014: Cuts rope and steel cable on collision
- **Given** Description: "You can use these tin snips to cut through rope or steel cable"
- **When** collision triggers snips
- **Then** connected rope or steel cable is severed

### TC-015: Pops balloons and blimps
- **Given** Description: "They can also be used to pop blimps and balloons"
- **When** snips activate near balloon/blimp
- **Then** balloon or blimp is destroyed
