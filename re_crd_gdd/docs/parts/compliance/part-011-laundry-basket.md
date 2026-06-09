## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-011-laundry-basket.md` describes part type `11`
- **When** parsed
- **Then** `part_num == 11`

### TC-002: Mass value is positive
- **Given** Laundry Basket has `mass = 4000`
- **When** validated
- **Then** `mass > 0`

### TC-003: property_q8 encodes container property
- **Given** Laundry Basket has `property_q8 = 128` (Q8.8 = 0.500)
- **When** containment check runs
- **Then** value represents hold strength

### TC-004: Collision trigger only
- **Given** Laundry Basket shows `Triggers: collision`
- **When** object enters basket
- **Then** only collision response, no state change

### TC-005: Single default state
- **Given** Laundry Basket has "Single default state"
- **When** rendered
- **Then** no SOLVE.RES transitions

### TC-006: 2 ANM states (open/closed appearance)
- **Given** Laundry Basket ANM shows `Total States = 2`
- **When** rendered
- **Then** state 6 = default, state 5 = alternate (containment states)

### TC-007: Rope connection anchor
- **Given** Description: "tie one end of rope to laundry basket"
- **When** rope attached
- **Then** basket can be lifted/lowered

### TC-008: Container for Curie Cat, Newton Mouse, Mel Schlemming
- **Given** Description lists valid trapped characters
- **When** animal enters basket
- **Then** animal is contained

### TC-009: Part used in 12 levels
- **Given** Laundry Basket (type 11)
- **When** checked against YAML levels
- **Then** at least 12 levels reference it

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
- **Then** container behavior is automatic

### TC-013: Bitmap dimensions (64×62)
- **Given** Laundry Basket has `bitmap_w = 64`, `bitmap_h = 62`
- **When** rendered
- **Then** sprite is rectangular container shape

### TC-014: Destructible flag is No
- **Given** Laundry Basket shows `Destructible: No`
- **When** collision with force occurs
- **Then** basket holds shape

### TC-015: unk_2 = 70 (category-specific)
- **Given** Laundry Basket has `unk_2 = 70`
- **When** behavior handler processes
- **Then** value encodes containment capacity
