## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-071-boxes.md` describes part type `71`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 71`

### TC-002: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-003: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** boxes are static containers

### TC-004: Container category (Category Part Count = 5)
- **Given** Category Rules show `Category Part Count: 5`
- **When** validated
- **Then** 5 parts in Containers category

### TC-005: Triggers are collision
- **Given** Category Rules show `Triggers: collision`
- **When** behavior handler evaluates
- **Then** collision trigger is registered

### TC-006: Part used in 43 levels
- **Given** Boxes (type 71)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 43 levels reference `part_num = 71`

### TC-007: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** boxes are not destroyed

### TC-008: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-009: 9 states (5 box types + 4 material variants)
- **Given** ANM shows `Total States: 9`
- **When** box type is programmed
- **Then** correct ANM state is selected

### TC-010: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-011: Bitmap dimensions 48×32
- **Given** Physics Properties show `bitmap_w = 48`, `bitmap_h = 32`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-012: 5 box material types (glass, wooden, wicker, metal, cardboard)
- **Given** Description: "Program it to be glass, wooden, wicker, metal, or cardboard, which are all different sizes"
- **When** player programs box
- **Then** selected material determines box size and appearance

### TC-013: No SOLVE.RES state transitions (static part)
- **Given** State Machine shows *No SOLVE.RES state data — this part has no programmatic state transitions*
- **When** behavior handler evaluates
- **Then** no state transitions are triggered

### TC-014: Container accepts dropped objects
- **Given** Description: "Drop things inside the box, or use it to catch falling objects"
- **When** object falls into box
- **Then** object is contained within box bounds

### TC-015: State determined by appearance field at placement
- **Given** Behavior Notes: "Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file)"
- **When** level is loaded
- **Then** box renders with programmed appearance state
