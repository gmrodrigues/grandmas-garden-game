## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-012-curie-cat.md` describes part type `12`
- **When** parsed
- **Then** `part_num == 12`

### TC-002: Mass value is positive
- **Given** Curie Cat has `mass = 2000`
- **When** validated
- **Then** `mass > 0`

### TC-003: 12 ANM states (complex AI behavior)
- **Given** Curie Cat ANM shows `Total States = 12`
- **When** rendered
- **Then** states cover walking, eating, turning animations

### TC-004: Timed Section A animation (334 entries)
- **Given** Curie Cat has `Animated: Yes` with 334 duration entries
- **When** AI behavior runs
- **Then** animation advances at 60Hz

### TC-005: SOLVE.RES transition to Has Eaten
- **Given** Curie Cat transitions `1→9` (Hasn't Eaten → Has Eaten)
- **When** eats goldfish (proximity to Bill)
- **Then** ANM state becomes `9`

### TC-006: Terminal state removes part from sim
- **Given** Curie Cat transitions `9→-1`
- **When** eating animation completes
- **Then** `part is removed from simulation`

### TC-007: Proximity AI to chase targets
- **Given** Description: "heads toward Newton Mouse or Bill the Goldfish"
- **When** simulation runs
- **Then** cat moves toward nearest valid target

### TC-008: Collision causes turn-around
- **Given** Description: "turns around if bumped or runs into something"
- **When** collision detected
- **Then** direction inverts

### TC-009: Attracted by goo from can opener
- **Given** Description: "likes goo from can opener"
- **When** can-opened can spills goo
- **Then** cat redirected toward goo source

### TC-010: Part used in 21 levels
- **Given** Curie Cat (type 12)
- **When** checked against YAML levels
- **Then** at least 21 levels reference it

### TC-011: Category Part Count is 8
- **Given** Category Rules show `Category Part Count: 8`
- **When** validated
- **Then** 8 parts in Characters category

### TC-012: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-013: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** player intervention possible
- **Then** player can bump/redirect cat

### TC-014: 3 PLAY_SFX opcodes (meow/eating sounds)
- **Given** Curie Cat ANM has `PLAY_SFX: 3`
- **When** walking/eating animation plays
- **Then** appropriate sounds trigger

### TC-015: Triggers include collision and proximity
- **Given** Curie Cat shows `Triggers: collision, proximity`
- **When** touching target or goo
- **Then** AI behavior state updates
