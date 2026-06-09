## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-057-large-curved-pipe.md` describes part type `57`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 57`

### TC-002: Ball guidance through pipe system
- **Given** Description: "Drop balls and other objects into this large curved pipe to make them come out the other end"
- **When** ball enters pipe
- **Then** ball exits at pipe output

### TC-003: Pipe System category
- **Given** Category shows `Pipe Systems`
- **When** physics simulation runs
- **Then** ball guidance through curve is calculated

### TC-004: Part used in 43 levels
- **Given** Large Curved Pipe (type 57)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 43 levels reference `part_num = 57`

### TC-005: Connects to straight pipe sections and t-connectors
- **Given** Description: "It can be attached to straight sections of large pipe and t-connectors"
- **When** pipe placed adjacent to compatible pipe
- **Then** connection is formed

### TC-006: Accelerator tube attachment
- **Given** Description: "You can also attach an accelerator tube to speed up or reverse the direction of objects"
- **When** accelerator attached to pipe
- **Then** ball velocity is modified

### TC-007: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-008: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** pipe is static geometry

### TC-009: No triggers defined
- **Given** Category Rules show `Triggers: (none)` or passive
- **When** behavior handler evaluates
- **Then** pipe guides balls passively

### TC-010: Destructible flag is No (pipe walls are indestructible)
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** pipe is not destroyed

### TC-011: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-012: Category Part Count includes this pipe type
- **Given** Large Curved Pipe is in Pipe Systems category
- **When** validated
- **Then** category count reflects pipe system parts

### TC-013: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-014: Sprite existence validation
- **Given** Large Curved Pipe ANM references sprite files
- **When** `decoder/d_t2anm.py` parses Section D
- **Then** all referenced PNGs exist in `build/phase-3/bitmaps/`

### TC-015: Level YAML cross-reference
- **Given** Large Curved Pipe appears in level YAML files
- **When** `validate_spec.py` loads level
- **Then** pipe part is correctly instantiated
