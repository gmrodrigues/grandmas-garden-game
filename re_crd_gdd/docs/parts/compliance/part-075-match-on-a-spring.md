## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-075-match-on-a-spring.md` describes part type `75`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 75`

### TC-002: Mass value is positive
- **Given** Match-on-a-Spring has `mass = 2000`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Match-on-a-Spring has `property_q8 = 1024`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 4.000`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** match responds to rope pull

### TC-006: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical: Yes`
- **When** behavior handler evaluates
- **Then** electrical triggers are registered

### TC-007: SOLVE.RES state transitions (Unlit → Lit)
- **Given** Match-on-a-Spring has states: Unlit (`1→4`) and Lit (`3→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-008: Terminal state Lit (part removed)
- **Given** State Machine shows `Lit: 3→-1`
- **When** state reaches Lit
- **Then** part is removed from simulation (terminal)

### TC-009: Triggers are collision and electrical
- **Given** Category Rules show `Triggers: collision, electrical`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-010: Part used in 52 levels
- **Given** Match-on-a-Spring (type 75)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 52 levels reference `part_num = 75`

### TC-011: Springs / Pneumatics category (Category Part Count = 7)
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Springs / Pneumatics category

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** match-on-a-spring is not destroyed

### TC-013: Animated (Section A) — 35 duration entries
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 35 entries`
- **When** animation renderer processes frame timing
- **Then** Section A durations control playback at 60 Hz

### TC-014: 18 total animation frames across 4 states
- **Given** ANM shows `Total Frames: 18`, `Total States: 4`
- **When** animation renderer processes
- **Then** all 18 frames map to correct states

### TC-015: Rope pull launches lit match upward
- **Given** Description: "Pull the little peg with a rope to make this match pop up lit"
- **When** rope is pulled with sufficient force
- **Then** match launches upward in Lit state
