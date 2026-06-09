## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-079-hot-air-balloon.md` describes part type `79`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 79`

### TC-002: Mass value is positive
- **Given** Hot Air Balloon has `mass = 12`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Hot Air Balloon has `property_q8 = 64`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 0.250`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** balloon responds to candle ignition

### TC-006: SOLVE.RES state transitions (Not Lit → Lit → Popped)
- **Given** Hot Air Balloon has states: Not Lit (`1→5`), Lit (`5→4`), Popped (`4→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-007: Terminal state Popped (part removed)
- **Given** State Machine shows `Popped: 4→-1`
- **When** state reaches Popped
- **Then** part is removed from simulation (terminal)

### TC-008: Triggers are collision and proximity
- **Given** Category Rules show `Triggers: collision, proximity`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-009: Part used in 30 levels
- **Given** Hot Air Balloon (type 79)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 30 levels reference `part_num = 79`

### TC-010: Balloons / Airships category (Category Part Count = 3)
- **Given** Category Rules show `Category Part Count: 3`
- **When** validated
- **Then** 3 parts in Balloons / Airships category

### TC-011: Destructible flag is Yes
- **Given** Category Rules show `Destructible: Yes`
- **When** explosive part collides
- **Then** balloon can be destroyed

### TC-012: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-013: 12 total animation frames across 5 states
- **Given** ANM shows `Total Frames: 12`, `Total States: 5`
- **When** animation renderer processes
- **Then** all 12 frames map to correct states

### TC-014: Candle ignition causes balloon to rise
- **Given** Description: "Light the candle to create hot air, which will makes this balloon rise into the air"
- **When** candle flame contacts balloon candle
- **Then** balloon transitions to Lit state and rises

### TC-015: Rope attachment point for lifting
- **Given** Description: "Tie a rope to the eye hook on the bottom and use it to lift things"
- **When** rope is attached to eye hook
- **Then** rising balloon can lift connected objects
