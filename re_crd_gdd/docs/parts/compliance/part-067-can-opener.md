## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-067-can-opener.md` describes part type `67`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 67`

### TC-002: Mass value is positive
- **Given** Can Opener has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Can Opener has `property_q8 = 1024`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 4.000`

### TC-004: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-005: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** can opener responds to electrical activation

### TC-006: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical: Yes`
- **When** behavior handler evaluates
- **Then** electrical triggers are registered

### TC-007: SOLVE.RES state transitions (Unopened → Opened)
- **Given** Can Opener has states: Unopened (`1→3`) and Opened (`2→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-008: Terminal state Opened (part removed)
- **Given** State Machine shows `Opened: 2→-1`
- **When** state reaches Opened
- **Then** part is removed from simulation (terminal)

### TC-009: Triggers are electrical and collision
- **Given** Category Rules show `Triggers: electrical, collision`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-010: Part used in 11 levels
- **Given** Can Opener (type 67)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 11 levels reference `part_num = 67`

### TC-011: Electrical category (Category Part Count = 9)
- **Given** Category Rules show `Category Part Count: 9`
- **When** validated
- **Then** 9 parts in Electrical category

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** can opener is not destroyed

### TC-013: Animated (Section A) — 36 duration entries
- **Given** ANM shows `Animated (Section A): Yes`, `Section A Durations: 36 entries`
- **When** animation renderer processes frame timing
- **Then** Section A durations control playback at 60 Hz

### TC-014: Bitmap dimensions 37×51
- **Given** Physics Properties show `bitmap_w = 37`, `bitmap_h = 51`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-015: Curie Cat attracted by spilled sauce
- **Given** Description: "When the sauce spills out of the can, Curie Cat will come lap it up if she's within range"
- **When** can opener opens and sauce spills
- **Then** Curie Cat pathfinds toward sauce
