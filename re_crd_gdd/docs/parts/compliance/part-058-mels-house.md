## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-058-mels-house.md` describes part type `58`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 58`

### TC-002: Mel attraction destination
- **Given** Description: "Here's Mel Schlemming's cozy suburban duplex. If he sees it, he'll head home"
- **When** Mel (type 54) sees house
- **Then** Mel pathfinds toward house

### TC-003: Programmable appearance (suburban vs log cabin)
- **Given** Description: "It can also be programmed to be a rustic log cabin"
- **When** player selects appearance
- **Then** house sprite changes

### TC-004: Part used in 18 levels
- **Given** Mel's House (type 58)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 18 levels reference `part_num = 58`

### TC-005: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-006: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** house appearance can be programmed

### TC-007: Special Mechanics category
- **Given** Category shows `Special Mechanics`
- **When** behavior handler evaluates
- **Then** house acts as Mel's destination

### TC-008: No triggers defined (passive destination)
- **Given** Category Rules show passive or no triggers
- **When** behavior handler evaluates
- **Then** house is passive destination marker

### TC-009: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** house is not destroyed

### TC-010: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-011: Category Part Count is 15
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Special Mechanics category

### TC-012: SOLVE.RES state transitions for programming
- **Given** Mel's House has SOLVE.RES states for appearance modes
- **When** behavior handler evaluates
- **Then** state reflects selected appearance

### TC-013: Animated Section A for house details
- **Given** ANM shows `Animated (Section A): Yes`
- **When** simulation runs
- **Then** house animation plays (smoke, lights, etc.)

### TC-014: Sprite existence validation
- **Given** Mel's House ANM references sprite files
- **When** `decoder/d_t2anm.py` parses Section D
- **Then** all referenced PNGs exist in `build/phase-3/bitmaps/`

### TC-015: Level YAML cross-reference
- **Given** Mel's House appears in level YAML files
- **When** `validate_spec.py` loads level
- **Then** house part is correctly instantiated
