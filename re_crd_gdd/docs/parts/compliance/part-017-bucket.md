## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-017-bucket.md` describes part type `17`
- **When** parsed
- **Then** `part_num == 17`

### TC-002: Mass value is positive
- **Given** Bucket has `mass = 7552` (heavy for lifting)
- **When** validated
- **Then** `mass > 0`

### TC-003: property_q8 encodes hold strength
- **Given** Bucket has `property_q8 = 92` (Q8.8 = 0.359)
- **When** containment check
- **Then** value affects how much weight it can hold

### TC-004: Collision trigger only
- **Given** Bucket shows `Triggers: collision`
- **When** object enters bucket
- **Then** collision response applied

### TC-005: Single default state
- **Given** Bucket has "Single default state"
- **When** rendered
- **Then** no state transitions

### TC-006: 2 ANM states (empty/filled appearance)
- **Given** Bucket ANM shows `Total States = 2`
- **When** rendered
- **Then** state 1 and 4 represent visual variants

### TC-007: Rope connection for lifting
- **Given** Description: "tie a rope to it, tie other end to second object"
- **When** rope attached
- **Then** bucket can lift other objects

### TC-008: Heavy object in bucket lifts other end
- **Given** Description: "drop something heavy into bucket to lift other object"
- **When** bucket weighted
- **Then** rope pulls other attached object up

### TC-009: Part used in 48 levels
- **Given** Bucket (type 17)
- **When** checked against YAML levels
- **Then** at least 48 levels reference it

### TC-010: Category Part Count is 5
- **Given** Category Rules show `Category Part Count: 5`
- **When** validated
- **Then** 5 parts in Containers category

### TC-011: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-012: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** bucket physics automatic

### TC-013: Bitmap dimensions (37×49)
- **Given** Bucket has `bitmap_w = 37`, `bitmap_h = 49`
- **When** rendered
- **Then** rectangular container shape

### TC-014: unk_2 = 100 (structural)
- **Given** Bucket has `unk_2 = 100`
- **When** force applied
- **Then** determines break threshold

### TC-015: Rope mechanical advantage
- **Given** Bucket tied to teeter-totter or pulley
- **When** bucket descends
- **Then** rope pulls connected object up
