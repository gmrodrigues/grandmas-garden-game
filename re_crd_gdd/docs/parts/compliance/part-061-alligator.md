## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-061-alligator.md` describes part type `61`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 61`

### TC-002: Mass value is positive
- **Given** Alligator has `mass = 2400`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Alligator has `property_q8 = 192`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (192 >> 8) <= 1.0` i.e. `COR = 0.750`

### TC-004: Predator of Mel and Newton Mouse
- **Given** Description: "He'll chow down Mel Schlemming or Newton Mouse if they get too close"
- **When** alligator proximity detects character
- **Then** character is eaten (removed from simulation)

### TC-005: Snout flip mechanic
- **Given** Description: "He also flips things into the air with his snout"
- **When** alligator collides with object
- **Then** object is launched upward

### TC-006: SOLVE.RES state transitions (character AI)
- **Given** Alligator has named states in SOLVE.RES
- **When** behavior handler evaluates triggers
- **Then** state transitions follow SOLVE.RES rules

### TC-007: Part used in 14 levels
- **Given** Alligator (type 61)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 14 levels reference `part_num = 61`

### TC-008: Triggers are collision and proximity
- **Given** Category Rules show `Triggers: collision, proximity`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-009: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-010: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** alligator AI responds to environment

### TC-011: Character category (Category Part Count = 8)
- **Given** Category Rules show `Category Part Count: 8`
- **When** validated
- **Then** 8 parts in Characters category

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** alligator is not destroyed

### TC-013: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-014: Bitmap dimensions 94×16
- **Given** Physics Properties show `bitmap_w = 94`, `bitmap_h = 16`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-015: Threat to mouse and Mel AI systems
- **Given** Alligator is predator for two character types
- **When** simulation runs
- **Then** both Newton Mouse and Mel Schlemming pathfind to avoid
