## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-065-leprechaun.md` describes part type `65`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 65`

### TC-002: Mass value is positive
- **Given** Leprechaun has `mass = 2000`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: COR within valid range [0.0, 1.0]
- **Given** Leprechaun has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `0.0 <= (128 >> 8) <= 1.0` i.e. `COR = 0.500`

### TC-004: SOLVE.RES state transitions (Resting → Dancing)
- **Given** Leprechaun has states: Resting (`1→2`) and Dancing (`2→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-005: Not used in any built-in level
- **Given** Leprechaun is a Character type
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** no built-in level references `part_num = 65`

### TC-006: Triggers are collision and proximity
- **Given** Category Rules show `Triggers: collision, proximity`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-007: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-008: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** leprechaun dances when nudged

### TC-009: Character category (Category Part Count = 8)
- **Given** Category Rules show `Category Part Count: 8`
- **When** validated
- **Then** 8 parts in Characters category

### TC-010: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** leprechaun is not destroyed

### TC-011: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-012: Dancing jig on nudge
- **Given** Description: "Give him a nudge and he'll dance a jig for you"
- **When** collision or proximity trigger fires
- **Then** leprechaun enters Dancing state

### TC-013: Terminal state Dancing (part removed)
- **Given** State Machine shows `Dancing: 2→-1`
- **When** state reaches Dancing
- **Then** part is removed from simulation (terminal)

### TC-014: Bitmap dimensions 39×62
- **Given** Physics Properties show `bitmap_w = 39`, `bitmap_h = 62`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-015: Saint Patrick's Day themed character
- **Given** Description: "Happy Saint Patrick's Day! Say hi to Blarney O'Reilly, the leprechaun who lives in Professor Tim's garden"
- **When** character activates
- **Then** dance animation plays
