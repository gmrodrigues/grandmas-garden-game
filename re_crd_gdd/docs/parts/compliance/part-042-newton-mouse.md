## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-042-newton-mouse.md` describes part type `42`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 42`

### TC-002: Mass value is positive
- **Given** Newton Mouse has `mass = 2000`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR is 0.000 (fixed-point property)
- **Given** Newton Mouse has `property_q8 = 0`
- **When** converted from Q8.8 fixed-point
- **Then** `COR = 0.000`

### TC-004: Character AI with cheese-seeking behavior
- **Given** Description: "He'll go after any cheese he can see"
- **When** cheese (part 52) is placed in level
- **Then** mouse pathfinds toward cheese

### TC-005: Fear response to Curie Cat
- **Given** Description: "He'll also run away if Curie Cat comes after him"
- **When** Curie Cat (part 12) enters proximity
- **Then** mouse flees in opposite direction

### TC-006: Mouse hole destination behavior
- **Given** Description: "He'll run inside a mouse hole if you place a hunk of cheese on the other side of it"
- **When** cheese placed beyond mouse hole
- **Then** mouse enters hole and disappears

### TC-007: SOLVE.RES state transitions (complex character AI)
- **Given** Newton Mouse has named states in SOLVE.RES
- **When** behavior handler evaluates triggers
- **Then** state transitions follow SOLVE.RES rules

### TC-008: Part used in 37 levels
- **Given** Newton Mouse (type 42)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 37 levels reference `part_num = 42`

### TC-009: Triggers are collision and proximity
- **Given** Category Rules show `Triggers: collision, proximity`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-010: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-011: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** mouse AI responds to environment

### TC-012: Character category (Category Part Count = 8)
- **Given** Category Rules show `Category Part Count: 8`
- **When** validated
- **Then** 8 parts in Characters category

### TC-013: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** mouse is not destroyed

### TC-014: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-015: Alligator avoidance behavior
- **Given** Description mentions alligators as threat
- **When** alligator enters proximity
- **Then** mouse pathfinds to avoid
