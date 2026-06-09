## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-009-basketball.md` describes part type `9`
- **When** parsed
- **Then** `part_num == 9`

### TC-002: Mass value is positive
- **Given** Basketball has `mass = 1322`
- **When** validated
- **Then** `mass > 0`

### TC-003: COR is high (bouncy)
- **Given** Basketball has `cor_q8 = 192`
- **When** converted
- **Then** `COR = 0.750` (75% restitution — much bouncier than bowling ball)

### TC-004: Low damping (air resistance)
- **Given** Basketball has `damping = 20`
- **When** physics runs
- **Then** drag is minimal (lighter than bowling ball's 200)

### TC-005: Radius is 16 (same as bowling ball)
- **Given** Basketball has `radius = 16`
- **When** collision check runs
- **Then** same collision sphere size as bowling ball

### TC-006: Single default state (no transitions)
- **Given** Basketball has "Single default state — no named transitions"
- **When** collision occurs
- **Then** no state change (balls don't transform)

### TC-007: 2 ANM states (normal + bounce frames)
- **Given** Basketball ANM shows `Total States = 2`
- **When** rendered
- **Then** state 3 = normal, state 4 = bounce sequence (16 frames)

### TC-008: 17 animation frames for bounce
- **Given** Basketball ANM has `Total Frames = 17`
- **When** ball bounces
- **Then** 16-frame squash-and-stretch animation plays

### TC-009: No connections supported
- **Given** Basketball declares no connections
- **When** checked
- **Then** `Electrical=No`, `Belt=No`, `Rope=No`, `Fire=No`, `Laser=No`, `Projectile=No`

### TC-010: Part used in 21 levels
- **Given** Basketball (type 9)
- **When** checked against YAML levels
- **Then** at least 21 levels reference it

### TC-011: Category triggers include collision and trap
- **Given** Basketball shows `Triggers: collision, trap`
- **When** hits ground or wall
- **Then** bounce physics applied with COR

### TC-012: Ball category mass range
- **Given** Basketball (type 9) in Balls category (9 parts)
- **When** mass values compared
- **Then** bowling ball (2832) > basket (1322) > tennis (lower)

### TC-013: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-014: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** ball physics are automatic

### TC-015: Sprite dimensions are 32x32
- **Given** Basketball ANM frame 0 has dimensions `32×32`
- **When** rendered
- **Then** sprite matches collision radius
