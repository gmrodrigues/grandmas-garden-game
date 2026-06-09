## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-041-explosion.md` describes part type `41`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 41`

### TC-002: Created Part flag is Yes
- **Given** Explosion Identity shows `Created Part: Yes`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == True`

### TC-003: Not placed by player — no level usage
- **Given** Explosion is a dynamically spawned effect
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** no built-in level references `part_num = 41`

### TC-004: 3-frame explosion animation
- **Given** Explosion ANM has `Total Frames = 3`, `Total States = 1`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 1`

### TC-005: Sound effect at frame 0
- **Given** Sound Effects table shows frame 0 triggers sound ID `3211`
- **When** explosion spawns
- **Then** `PLAY_SFX` opcode dispatches sound ID `3211`

### TC-006: 5 DRAW_BMP opcodes across 3 frames
- **Given** Bytecode Opcodes show `DRAW_BMP = 5` across 3 frames
- **When** bytecode is executed
- **Then** each frame renders correct explosion sprites

### TC-007: PLAY_SFX opcode present
- **Given** Bytecode Opcodes show `PLAY_SFX = 1`
- **When** animation reaches trigger frame
- **Then** sound effect is dispatched

### TC-008: No SOLVE.RES state transitions
- **Given** Explosion has no programmatic state transitions
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-009: No triggers defined
- **Given** Category Rules show `Triggers: (none)`
- **When** behavior handler evaluates
- **Then** explosion is purely visual effect

### TC-010: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** checked
- **Then** explosion is not subject to destruction

### TC-011: Created / Phantom category
- **Given** Category shows `Created / Phantom`
- **When** part is spawned
- **Then** it is treated as temporary visual effect

### TC-012: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** explosion requires no player interaction

### TC-013: Bitmap dimensions 70×66
- **Given** Physics Properties show `bitmap_w = 70`, `bitmap_h = 66`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-014: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-015: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections
