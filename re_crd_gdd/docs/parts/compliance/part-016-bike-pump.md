## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-016-bike-pump.md` describes part type `16`
- **When** parsed
- **Then** `part_num == 16`

### TC-002: Mass value is positive
- **Given** Bike Pump has `mass = 3776`
- **When** validated
- **Then** `mass > 0`

### TC-003: Electrical connection supported
- **Given** Bike Pump shows `Electrical: Yes`
- **When** triggered
- **Then** pump activates

### TC-004: SOLVE.RES transition to Pumped
- **Given** Bike Pump transitions `2→4` (Not Pumped → Pumped)
- **When** collision or electrical trigger
- **Then** ANM state becomes `5`

### TC-005: Terminal state removes part
- **Given** Bike Pump transitions `4→-1`
- **When** pumping animation completes
- **Then** `part is removed from simulation`

### TC-006: 3 ANM states
- **Given** Bike Pump ANM shows `Total States = 3`
- **When** rendered
- **Then** states: not pumped, pumping (1 frame), pumped

### TC-007: Pushes balloons and objects
- **Given** Description: "blow air to push away balloons and other objects"
- **When** pumped
- **Then** air burst applies force to nearby objects

### TC-008: Makes pinwheels turn
- **Given** Description: "to make pinwheels turn"
- **When** air burst hits pinwheel
- **Then** pinwheel angular velocity increases

### TC-009: Part used in 27 levels
- **Given** Bike Pump (type 16)
- **When** checked against YAML levels
- **Then** at least 27 levels reference it

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
- **When** object drops on pump handle
- **Then** pump activates

### TC-013: PLAY_SFX at frame 1 (pump sound)
- **Given** Bike Pump ANM has `PLAY_SFX: 1` at frame 1
- **When** pumping
- **Then** `SX_3016_11025.wav` plays

### TC-014: property_q8 encodes air pressure
- **Given** Bike Pump has `property_q8 = 128` (Q8.8 = 0.500)
- **When** air burst calculated
- **Then** force magnitude proportional to property

### TC-015: Collision trigger from dropped object
- **Given** Bike Pump shows `Triggers: collision, electrical`
- **When** object drops on top handle
- **Then** pump activates
