## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-004-balloon.md` describes part type `4`
- **When** parsed
- **Then** `part_num == 4`

### TC-002: Very low mass (buoyant object)
- **Given** Balloon has `mass = 9`
- **When** gravity applied
- **Then** `mass` is lowest in category, enabling buoyancy

### TC-003: property_q8 encodes lift force
- **Given** Balloon has `property_q8 = 64` (Q8.8 = 0.250)
- **When** buoyancy calculated
- **Then** `gravity_buoyancy = pressure * (1.0 - mass/density)`

### TC-004: 8 ANM states (4 colors × 2 states each)
- **Given** Balloon ANM shows `Total States = 8`
- **When** rendered
- **Then** states map to 4 appearances × (Normal + Popped)

### TC-005: SOLVE.RES transitions for popping
- **Given** Balloon has transitions `3→7`, `2→6`, `4→8`, `5→9`
- **When** collision/proximity with sharp objects occurs
- **Then** state transitions to popped variant

### TC-006: Terminal state is Popped (removed from sim)
- **Given** Balloon transitions to Popped state
- **When** `state_counter` reaches terminal value
- **Then** `part is removed from simulation`

### TC-007: 4 PLAY_SFX opcodes (pop sound)
- **Given** Balloon ANM has `PLAY_SFX: 4`
- **When** pop animation plays
- **Then** sound `SX_3004_11025.wav` plays at each pop frame

### TC-008: Destructible by explosives
- **Given** Balloon shows `Destructible: Yes`
- **When** explosive part collides
- **Then** balloon pops immediately

### TC-009: Triggers include collision and proximity
- **Given** Balloon shows `Triggers: collision, proximity`
- **When** any object enters proximity radius
- **Then** SOLVE.RES lookup determines new state

### TC-010: Part used in 68 levels
- **Given** Balloon (type 4)
- **When** checked against YAML levels
- **Then** at least 68 levels reference it

### TC-011: Rope connection lifts balloon
- **Given** Balloon tied with rope to object
- **When** simulation runs
- **Then** rope constrains upward buoyancy

### TC-012: Balloon pops near lasers, flames, gears
- **Given** sharp objects (laser beams, flames, hedge trimmers, tacks) nearby
- **When** proximity check runs
- **Then** balloon state transitions to Popped

### TC-013: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-014: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** player clicks during simulation
- **Then** may trigger state change (placement orientation)

### TC-015: 4 balloon color appearances
- **Given** Description mentions "four different appearances"
- **When** `appearance` field varies
- **Then** visual sprite set changes but physics unchanged
