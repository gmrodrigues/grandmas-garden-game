## Compliance Test Cases

### TC-001: Part type number matches filename
- **Given** `part-010-rope.md` describes part type `10`
- **When** parsed
- **Then** `part_num == 10`

### TC-002: Extra data structure for rope
- **Given** Rope requires extra data per `d_item_extra_data_1_type_t2`
- **When** parsed
- **Then** `nt_part_extra_rope` (6 bytes) is appended

### TC-003: Rope connects two parts
- **Given** Description: "tie objects together", "tie one end to object, other end to second object"
- **When** rope placed between A and B
- **Then** `rope_info_1/2` stores connected part indices

### TC-004: Rope turns red then green when valid
- **Given** rope being placed
- **When** both endpoints can connect
- **Then** line color changes red → green

### TC-005: Rope cut by hedge trimmers or tin snips
- **Given** rope exists between two objects
- **When** hedge trimmers (type 37) or tin snips (type 77) touch rope
- **Then** rope connection is severed

### TC-006: Max stretch distance enforced
- **Given** rope between two objects
- **When** distance(A, B) > rope.max_length
- **Then** constraint solver corrects position

### TC-007: Single-pass rope constraint (per Q-018)
- **Given** rope constraint in simulation loop
- **When** constraint solver runs
- **Then** rope correction is single-pass (no iterations)

### TC-008: Belt and Rope connections supported
- **Given** Rope shows `Belt=Yes`, `Rope=Yes`
- **When** connected
- **Then** both mechanical systems recognize

### TC-009: Part used in 117 levels
- **Given** Rope (type 10)
- **When** checked against YAML levels
- **Then** at least 117 levels reference it (highest usage in all parts)

### TC-010: Rope used with pulleys
- **Given** Description: "hang things in the air, or hoist things with pulley"
- **When** pulley redirects rope
- **Then** mechanical advantage applies

### TC-011: Rope can attach to teeter-totter, boat cleat, laundry basket, bucket, phazer, balloon
- **Given** rope placement mode
- **When** click on valid anchor part
- **Then** connection established

### TC-012: Category Part Count is 4
- **Given** Category Rules show `Category Part Count: 4`
- **When** validated
- **Then** 4 parts in Ropes/Belts/Pulleys category

### TC-013: Created Part flag is No
- **Given** Identity shows `Created Part: No`
- **When** level loads
- **Then** part is in Parts Bin

### TC-014: Interactive flag is No
- **Given** Identity shows `Interactive: No`
- **When** simulation runs
- **Then** rope physics are automatic

### TC-015: Bitmap dimensions small (13×5)
- **Given** Rope has `bitmap_w = 13`, `bitmap_h = 5`
- **When** rendered
- **Then** sprite represents rope segment texture
