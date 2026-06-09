## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-040-pinwheel.md` describes part type `40`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 40`

### TC-002: Mass value is positive
- **Given** Pinwheel has `mass = 7552`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Pinwheel has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: SOLVE.RES state transitions (Not Spinning → Spinning)
- **Given** Pinwheel has 2 states: Not Spinning (`1→2`) and Spinning (`2→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Terminal state Spinning (part removed)
- **Given** State Machine shows `Spinning: 2→-1`
- **When** state reaches Spinning
- **Then** part is removed from simulation (terminal)

### TC-006: Belt connection to power devices
- **Given** Description: "Attach a belt and use it to turn other rotating parts"
- **When** belt connects pinwheel to device
- **Then** rotational power is transferred

### TC-007: Wind-activated rotation
- **Given** Description: "You can make this pinwheel spin by blowing air on it (from parts like the fan or the bike pump)"
- **When** wind from fan/bike pump contacts pinwheel
- **Then** pinwheel begins spinning

### TC-008: 2 ANM states (state IDs 1-2)
- **Given** Pinwheel ANM has `Total States = 2`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 2`

### TC-009: Part used in 16 levels
- **Given** Pinwheel (type 40)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 16 levels reference `part_num = 40`

### TC-010: Triggers include collision, electrical, rope
- **Given** Category Rules show `Triggers: collision, electrical, rope`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-011: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-012: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** pinwheel can be manually positioned/activated

### TC-013: Belt Connection flag is Yes
- **Given** Connections & Capabilities shows `Belt Connection = Yes`
- **When** belt is attached
- **Then** rotational power is transferred to connected part

### TC-014: Category Part Count is 7
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Rotating Power Sources category

### TC-015: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty
