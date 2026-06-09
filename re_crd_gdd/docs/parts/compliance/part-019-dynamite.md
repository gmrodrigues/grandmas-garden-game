## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-019-dynamite.md` describes part type `19`
- **When** parsed
- **Then** `part_num == 19`

### TC-002: Mass value is positive
- **Given** Dynamite has `mass = 1132`
- **When** validated
- **Then** `mass > 0`

### TC-003: property_q8 encodes fuse timer
- **Given** Dynamite has `property_q8 = 64` (Q8.8 = 0.250)
- **When** lit
- **Then** explosion after `0.250 * 255` ticks (fuse duration)

### TC-004: SOLVE.RES transition to Blown up
- **Given** Dynamite transitions `2→3` (Not Blown up → Blown up)
- **When** fuse timer expires OR collision/proximity trigger
- **Then** ANM state becomes `3`

### TC-005: Terminal explosive state removes part
- **Given** Dynamite transitions `3→-1`
- **When** explosion animation completes
- **Then** `part is removed from simulation` and destroys nearby parts

### TC-006: Explosive state destroys walls
- **Given** Dynamite has `Explosive: Yes` flag for state 3
- **When** in blown up state
- **Then** any wall with `Destructible: Yes` within blast radius is destroyed

### TC-007: Fire via laser, flame, or magnifying glass
- **Given** Description: "light with laser, flaming part, or magnifying glass"
- **When** fire/proximity trigger
- **Then** fuse timer starts

### TC-008: 3 ANM states
- **Given** Dynamite ANM shows `Total States = 3`
- **When** rendered
- **Then** states: fuse (idle), burning (16 frames), explosion

### TC-009: 18 animation frames
- **Given** Dynamite ANM has `Total Frames = 18`
- **When** lit
- **Then** fuse burning animation plays

### TC-010: PLAY_SFX at frame 1 (sizzle)
- **Given** Dynamite ANM has `PLAY_SFX: 1` at frame 1
- **When** fuse burning
- **Then** `SX_3019_11025.wav` plays

### TC-011: Part used in 28 levels
- **Given** Dynamite (type 19)
- **When** checked against YAML levels
- **Then** at least 28 levels reference it

### TC-012: Category Part Count is 10
- **Given** Category Rules show `Category Part Count: 10`
- **When** validated
- **Then** 10 parts in Explosives/Projectiles category

### TC-013: Spawns projectile
- **Given** Dynamite shows `Spawns: projectile`
- **When** explosion occurs
- **Then** debris projectile created

### TC-014: Destructible by other explosives
- **Given** Dynamite shows `Destructible: Yes`
- **When** other explosion nearby
- **Then** chain reaction triggers

### TC-015: Triggers include collision, proximity, timer
- **Given** Dynamite shows `Triggers: collision, proximity, timer`
- **When** any trigger activates
- **Then** fuse burns or explosion triggers
