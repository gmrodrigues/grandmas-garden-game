## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-052-cheese.md` describes part type `52`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 52`

### TC-002: Newton Mouse attraction target
- **Given** Description: "Newton Mouse will come after this cheese whenever he's close enough and on the same level of flooring"
- **When** cheese placed in level with Newton Mouse
- **Then** mouse pathfinds toward cheese

### TC-003: Same-level flooring requirement
- **Given** Cheese attraction requires same floor level
- **When** cheese is on different elevation than mouse
- **Then** mouse does not pathfind to cheese

### TC-004: Part used in 29 levels
- **Given** Cheese (type 52)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 29 levels reference `part_num = 52`

### TC-005: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-006: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** cheese is static bait

### TC-007: Special Mechanics category
- **Given** Category shows `Special Mechanics`
- **When** behavior handler evaluates
- **Then** cheese acts as mouse attractor

### TC-008: No triggers defined
- **Given** Category Rules show `Triggers: (none)` or passive triggers
- **When** behavior handler evaluates
- **Then** cheese behavior is purely attractor-based

### TC-009: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** cheese is not destroyed (or may be eaten)

### TC-010: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-011: Mouse hole destination pairing
- **Given** Description: "He'll run inside a mouse hole if you place a hunk of cheese on the other side of it"
- **When** cheese placed beyond mouse hole
- **Then** mouse enters hole when reaching cheese

### TC-012: Category Part Count is 15
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Special Mechanics category

### TC-013: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-014: Sprite existence validation
- **Given** Cheese ANM references sprite files
- **When** `decoder/d_t2anm.py` parses Section D
- **Then** all referenced PNGs exist in `build/phase-3/bitmaps/`

### TC-015: Level YAML cross-reference
- **Given** Cheese appears in level YAML files
- **When** `validate_spec.py` loads level
- **Then** cheese part is correctly instantiated
