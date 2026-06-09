## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-013-jack-in-the-box.md` describes part type `13`
- **When** parsed
- **Then** `part_num == 13`

### TC-002: Mass value is positive
- **Given** Jack-in-the-box has `mass = 3776`
- **When** validated
- **Then** `mass > 0`

### TC-003: Electrical connection required
- **Given** Jack-in-the-box shows `Electrical: Yes`
- **When** belt connects to motor
- **Then** spring mechanism activates

### TC-004: SOLVE.RES transition to Popped Out
- **Given** Jack-in-the-box transitions `3→4` (Closed → Popped Out)
- **When** belt/electrical trigger
- **Then** ANM state becomes `4`

### TC-005: Terminal state removes part
- **Given** Jack-in-the-box transitions `5→-1`
- **When** popped out animation completes
- **Then** `part is removed from simulation`

### TC-006: 4 ANM states
- **Given** Jack-in-the-box ANM shows `Total States = 4`
- **When** rendered
- **Then** states: closed, popping, popped, jack airborne

### TC-007: Belt connection to motor
- **Given** Description: "hitch to any rotating part by adding a belt"
- **When** motor wheel turns
- **Then** jack-in-the-box activates

### TC-008: Shoots object on top
- **Given** Description: "when Jack pops out, anything on top will be shot into air"
- **When** pop animation triggers
- **Then** upward force applied to objects above

### TC-009: Part used in 25 levels
- **Given** Jack-in-the-box (type 13)
- **When** checked against YAML levels
- **Then** at least 25 levels reference it

### TC-010: Category Part Count is 7
- **Given** Category Rules show `Category Part Count: 7`
- **When** validated
- **Then** 7 parts in Springs/Pneumatics category

### TC-011: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-012: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** motor activates
- **Then** spring-loaded pop is mechanical

### TC-013: 30 total animation frames
- **Given** Jack-in-the-box ANM has `Total Frames = 30`
- **When** popping
- **Then** smooth jack extension animation

### TC-014: PLAY_SFX at frame 12 (spring sound)
- **Given** Jack-in-the-box ANM has `PLAY_SFX: 1` at frame 12
- **When** popping animation
- **Then** `SX_3013_11025.wav` plays

### TC-015: property_q8 encodes spring force
- **Given** Jack-in-the-box has `property_q8 = 1024`
- **When** popping
- **Then** upward velocity proportional to property
