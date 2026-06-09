## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-066-mouse-hole.md` describes part type `66`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 66`

### TC-002: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-003: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** mouse hole responds to Newton Mouse proximity

### TC-004: Electrical connection supported
- **Given** Connections & Capabilities shows `Electrical: Yes`
- **When** behavior handler evaluates
- **Then** electrical triggers are registered

### TC-005: SOLVE.RES state transitions (Vacant → Occupied)
- **Given** Mouse Hole has states: Vacant (`1→3`) and Occupied (`3→-1`)
- **When** behavior handler evaluates trigger
- **Then** state transitions follow SOLVE.RES rules

### TC-006: Terminal state Occupied (part removed)
- **Given** State Machine shows `Occupied: 3→-1`
- **When** state reaches Occupied
- **Then** part is removed from simulation (terminal)

### TC-007: Triggers are collision, electrical, proximity
- **Given** Category Rules show `Triggers: collision, electrical, proximity`
- **When** behavior handler evaluates
- **Then** all three trigger types are registered

### TC-008: Part used in 6 levels
- **Given** Mouse Hole (type 66)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** 6 levels reference `part_num = 66`

### TC-009: Custom spawn behavior
- **Given** Category Rules show `Spawns: custom`
- **When** behavior handler processes
- **Then** custom spawn logic is applied

### TC-010: Special Mechanics category (Category Part Count = 15)
- **Given** Category Rules show `Category Part Count: 15`
- **When** validated
- **Then** 15 parts in Special Mechanics category

### TC-011: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** mouse hole is not destroyed

### TC-012: Bitmap dimensions 19×21
- **Given** Physics Properties show `bitmap_w = 19`, `bitmap_h = 21`
- **When** sprite is loaded
- **Then** frame dimensions match

### TC-013: 7 total animation frames across 3 states
- **Given** ANM shows `Total Frames: 7`, `Total States: 3`
- **When** animation renderer processes
- **Then** all 7 frames map to correct states

### TC-014: Static animation (no Section A durations)
- **Given** ANM shows `Animated (Section A): No`
- **When** animation renderer processes frame timing
- **Then** Section A durations is empty

### TC-015: Newton Mouse hides inside when chased
- **Given** Description: "Newton Mouse likes to hide in this mouse hole when he's chased by Curie Cat"
- **When** mouse is chased by cat and reaches hole
- **Then** mouse enters Occupied state and is hidden
