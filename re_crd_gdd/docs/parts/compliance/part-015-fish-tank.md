## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-015-fish-tank.md` describes part type `15`
- **When** parsed
- **Then** `part_num == 15`

### TC-002: Mass value is positive
- **Given** Fish Tank has `mass = 2000`
- **When** validated
- **Then** `mass > 0`

### TC-003: Timed Section A animation (300 entries)
- **Given** Fish Tank has `Animated: Yes` with 300 duration entries
- **When** Bill swims inside
- **Then** animation plays at 60Hz

### TC-004: SOLVE.RES transition to Broken
- **Given** Fish Tank transitions `15→9` (Not Broken → Broken)
- **When** dropped or collision with force
- **Then** ANM state becomes `14`

### TC-005: Terminal state removes tank
- **Given** Fish Tank transitions `9→-1`
- **When** breaking animation completes
- **Then** `part is removed from simulation`

### TC-006: 3 ANM states
- **Given** Fish Tank ANM shows `Total States = 3`
- **When** rendered
- **Then** states: normal (255 frames), breaking (44 frames), broken

### TC-007: Contains Bill the Goldfish
- **Given** Description: "Bill the Goldfish swims inside"
- **When** tank breaks
- **Then** Bill may be released (attracts Curie Cat from greater distance)

### TC-008: Collision triggers break
- **Given** Fish Tank shows `Triggers: collision`
- **When** heavy object dropped on tank
- **Then** state transitions to Broken

### TC-009: Part used in 11 levels
- **Given** Fish Tank (type 15)
- **When** checked against YAML levels
- **Then** at least 11 levels reference it

### TC-010: Category Part Count is 5
- **Given** Category Rules show `Category Part Count: 5`
- **When** validated
- **Then** 5 parts in Containers category

### TC-011: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-012: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** player interacts
- **Then** may trigger break

### TC-013: property_q8 encodes water volume
- **Given** Fish Tank has `property_q8 = 128` (Q8.8 = 0.500)
- **When** containment check
- **Then** value affects break threshold

### TC-014: unk_2 = 1000 (structural integrity)
- **Given** Fish Tank has `unk_2 = 1000`
- **When** force applied
- **Then** determines break trigger threshold

### TC-015: Destructible via collision
- **Given** Description: "drop just about anything on tank to break it"
- **When** collision force > threshold
- **Then** tank breaks
