## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-072-peg.md` describes part type `72`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 72`

### TC-002: Mass value is positive
- **Given** Peg has `mass = 4000`
- **When** validated against `build/phase-9/part-properties.json`
- **Then** `mass > 0`

### TC-003: Property Q8.8 within range
- **Given** Peg has `property_q8 = 128`
- **When** converted from Q8.8 fixed-point
- **Then** `property = 0.500`

### TC-004: Created Part flag is Yes
- **Given** Identity shows `Created Part: Yes`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == True`

### TC-005: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** peg is spawned dynamically and has no player interaction

### TC-006: Not used in any built-in level
- **Given** Levels Using This Part shows *This part is not used in any built-in level (may be created dynamically at runtime)*
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** no level references `part_num = 72`

### TC-007: Custom spawn behavior
- **Given** Category Rules show `Spawns: custom`
- **When** behavior handler processes
- **Then** custom spawn logic is applied

### TC-008: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical: Yes`
- **When** behavior handler evaluates
- **Then** electrical triggers are registered

### TC-009: Special Mechanics category (Category Part Count = 15)
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Special Mechanics category

### TC-010: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** peg is not destroyed

### TC-011: Triggers are collision, electrical, proximity
- **Given** Category Rules show `Triggers: collision, electrical, proximity`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-012: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-013: Bitmap dimensions 15×10
- **Given** Physics Properties show `bitmap_w = 15`, `bitmap_h = 10`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-014: No SOLVE.RES state transitions (static part)
- **Given** State Machine shows *No SOLVE.RES state data — this part has no programmatic state transitions*
- **When** behavior handler evaluates
- **Then** no state transitions are triggered

### TC-015: Spawned at runtime by other parts
- **Given** Behavior Notes: "It is not placed by the player but spawned at runtime by another part's behavior (e.g., explosion debris, laser beam, rope end phantom)"
- **When** parent part triggers spawn
- **Then** peg instance is created dynamically
