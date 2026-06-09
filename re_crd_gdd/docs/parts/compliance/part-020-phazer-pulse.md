## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-020-phazer-pulse.md` describes part type `20`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 20`

### TC-002: Created Part flag is Yes
- **Given** Phazer Pulse Identity shows `Created Part: Yes`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == True`

### TC-003: Not placed by player — no level usage
- **Given** Phazer Pulse is a dynamically created phantom part
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** no built-in level references `part_num = 20`

### TC-004: Spawns projectile (category rule)
- **Given** Category Rules show `Spawns: projectile`
- **When** behavior handler executes
- **Then** a separate part instance is spawned on trigger

### TC-005: Destructible flag is Yes
- **Given** Category Rules show `Destructible: Yes`
- **When** explosive part collides
- **Then** phazer pulse is removed from simulation

### TC-006: Triggers include collision, proximity, timer
- **Given** Category Rules show `Triggers: collision, proximity, timer`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-007: No SOLVE.RES state data
- **Given** Phazer Pulse has no programmatic state transitions
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-008: ANM animation frames match state count
- **Given** Phazer Pulse ANM has `Total Frames = 7`, `Total States = 1`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 1`

### TC-009: All 7 frames have DRAW_BMP bytecode
- **Given** Phazer Pulse ANM has 7 frames
- **When** bytecode is executed
- **Then** each frame contains a `DRAW_BMP` opcode referencing valid sprite

### TC-010: No electrical/belt/rope/laser connections
- **Given** Connections & Capabilities shows `Electrical=No`, `Belt=No`, `Rope=No`, `Laser=No`
- **When** checked against `category_rules`
- **Then** only `Projectile=Yes`

### TC-011: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** phazer pulse does not require user interaction

### TC-012: 7-frame static animation (no Section A durations)
- **Given** Phazer Pulse ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty and frames are static

### TC-013: Bitmap dimensions 16×4
- **Given** Physics Properties show `bitmap_w = 16`, `bitmap_h = 4`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-014: No sound effects
- **Given** Phazer Pulse ANM has no Sound Effects table
- **When** frame renders
- **Then** no `PLAY_SFX` opcode is present

### TC-015: Extra data for phantom projectile
- **Given** Phazer Pulse is a created projectile part
- **When** `nt_part_info_t2_base` is parsed
- **Then** extra data fields are initialized for spawn parameters
