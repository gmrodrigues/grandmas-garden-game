## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-018-cannon.md` describes part type `18`
- **When** parsed
- **Then** `part_num == 18`

### TC-002: Mass value is positive
- **Given** Cannon has `mass = 14726` (very heavy)
- **When** validated
- **Then** `mass > 0`

### TC-003: property_q8 encodes explosive force
- **Given** Cannon has `property_q8 = 192` (Q8.8 = 0.750)
- **When** cannon fires
- **Then** projectile velocity proportional to property

### TC-004: Complex SOLVE.RES with 6 firing angles
- **Given** Cannon has 12 SOLVE.RES transitions
- **When** lit fuse triggers
- **Then** state transitions through 6 angle variants × 2 states

### TC-005: Spawns projectile (cannonball)
- **Given** Cannon shows `Spawns: projectile`
- **When** fired
- **Then** cannonball part instance created

### TC-006: 37 ANM states (complex firing sequence)
- **Given** Cannon ANM shows `Total States = 37`
- **When** rendered
- **Then** multiple angles × animation frames

### TC-007: 6 aiming angles (flip gizmo)
- **Given** Description: "can be rotated to aim in six different angles"
- **When** flip gizmo used
- **Then** `appearance` field selects angle variant

### TC-008: Fire via laser, flame, or magnifying glass
- **Given** Description: "light fuse with laser, flaming part, or magnifying glass"
- **When** fire/proximity trigger
- **Then** fuse timer starts

### TC-009: Cannonball breaks and bumps things
- **Given** Description: "fires cannon balls to break and bump things"
- **When** ball hits target
- **Then** collision force applied

### TC-010: Part used in 21 levels
- **Given** Cannon (type 18)
- **When** checked against YAML levels
- **Then** at least 21 levels reference it

### TC-011: Category Part Count is 10
- **Given** Category Rules show `Category Part Count: 10`
- **When** validated
- **Then** 10 parts in Explosives/Projectiles category

### TC-012: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-013: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** player aims cannon
- **Then** orientation can be changed

### TC-014: Destructible by explosives
- **Given** Cannon shows `Destructible: Yes`
- **When** explosive collision
- **Then** cannon may be destroyed

### TC-015: Timed Section A animation (178 entries)
- **Given** Cannon has `Animated: Yes` with 178 duration entries
- **When** firing
- **Then** firing animation plays at 60Hz
