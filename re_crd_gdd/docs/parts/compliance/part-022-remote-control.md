## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-022-remote-control.md` describes part type `22`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 22`

### TC-002: Mass value is positive
- **Given** Remote Control has `mass = 4153`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Remote Control has `property_q8 = 1024`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (1024 >> 8) <= 1.0` i.e. `COR = 4.000`

### TC-004: 2 ANM states (state IDs 3-4)
- **Given** Remote Control ANM has `Total States = 2`
- **When** `decoder/d_t2anm.py` parses Section C
- **Then** `len(Section C entries) == 2`

### TC-005: No SOLVE.RES state transitions
- **Given** Remote Control has no programmatic state transitions
- **When** the part is loaded
- **Then** `state_machine` section shows "Single default state"

### TC-006: Part used in 57 levels
- **Given** Remote Control (type 22)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 57 levels reference `part_num = 22`

### TC-007: PLAY_SFX opcode triggers sound ID 3022
- **Given** Bytecode Opcodes show `PLAY_SFX = 1` at frame 3
- **When** animation reaches frame 3
- **Then** `PLAY_SFX` opcode dispatches sound ID `3022`

### TC-008: 14 frames across 2 states
- **Given** Remote Control ANM has `Total Frames = 14`, `Total States = 2`
- **When** bytecode is executed
- **Then** state 3 has frame 0, state 4 has frames 1-13

### TC-009: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-010: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** remote control does not require user interaction

### TC-011: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows `Electrical=No`, `Belt=No`, `Rope=No`, `Fire=No`, `Laser=No`, `Projectile=No`
- **When** checked against `category_rules`
- **Then** only default connections

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** remote control is not destroyed

### TC-013: Bitmap dimensions 30×37
- **Given** Physics Properties show `bitmap_w = 30`, `bitmap_h = 37`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-014: 52 DRAW_BMP opcodes across 14 frames
- **Given** Bytecode Opcodes show `DRAW_BMP = 52`
- **When** bytecode is executed
- **Then** each frame renders correct sprites

### TC-015: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty
