## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-054-mel-schlemming.md` describes part type `54`
- **When** parsed by `decoder/d_puzzle.py` → `nt_part_info_t2_base`
- **Then** `part_num == 54`

### TC-002: Walking AI with direction reversal
- **Given** Description: "Mel walks mindlessly forward until he bumps into something. Then he turns around and walks mindlessly in the other direction"
- **When** Mel collides with obstacle
- **Then** direction reverses

### TC-003: Programmable walk/run/stand modes
- **Given** Description: "You can program him to walk, run, or stand still until he's bumped"
- **When** player sets Mel's mode
- **Then** movement behavior changes accordingly

### TC-004: Fall damage and snooze recovery
- **Given** Description: "If he falls too far, he drops to the floor and takes a snooze"
- **When** Mel falls from height
- **Then** Mel enters snooze state (recovery)

### TC-005: Alligator avoidance behavior
- **Given** Description: "He also has to watch out for alligators"
- **When** alligator enters proximity
- **Then** Mel pathfinds to avoid

### TC-006: Part used in 32 levels
- **Given** Mel Schlemming (type 54)
- **When** checked against `build/phase-5/yaml/*.yaml`
- **Then** at least 32 levels reference `part_num = 54`

### TC-007: Triggers are collision and proximity
- **Given** Category Rules show `Triggers: collision, proximity`
- **When** behavior handler evaluates
- **Then** both trigger types are registered

### TC-008: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** `nt_part_info_t2_base.is_created` is accessed
- **Then** `is_created == False`

### TC-009: Interactive flag is Yes
- **Given** Identity shows `Interactive: Yes`
- **When** simulation runs
- **Then** Mel's behavior can be programmed

### TC-010: Character category (Category Part Count = 8)
- **Given** Category Rules show `Category Part Count: 8`
- **When** validated
- **Then** 8 parts in Characters category

### TC-011: SOLVE.RES state transitions for character AI
- **Given** Mel has named states in SOLVE.RES
- **When** behavior handler evaluates triggers
- **Then** state transitions follow SOLVE.RES rules

### TC-012: Destructible flag is No
- **Given** Category Rules show `Destructible: No`
- **When** explosive part collides
- **Then** Mel is not destroyed

### TC-013: No electrical/belt/rope/fire/laser/projectile connections
- **Given** Connections & Capabilities shows all connection flags as No
- **When** checked against `category_rules`
- **Then** only default connections

### TC-014: Mel's House attraction (home destination)
- **Given** Mel is paired with Mel's House (type 58)
- **When** Mel sees his house
- **Then** Mel pathfinds home

### TC-015: Animated Section A for walking animation
- **Given** ANM shows `Animated (Section A): Yes`
- **When** Mel walks
- **Then** animation plays walk cycle
