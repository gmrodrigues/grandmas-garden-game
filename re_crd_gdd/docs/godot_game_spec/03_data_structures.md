# 3. Data Structures

## 3.1 Part Struct (48 bytes base)

All parts share the first 40 bytes and last 8 bytes. Belt, rope, pulley, and programmable balls insert extra bytes in the middle.

```c
INT16LE part_type        // 0x00: Part type number (0-261)
UINT16LE flags_1         // 0x02: Orientation/gravity flags
UINT16LE flags_2         // 0x04: Belt/rope/scale connector flags  
UINT16LE flags_3         // 0x06: Electrical/fire/scenery flags
UINT16LE appearance      // 0x08: ANM sprite resource ID
INT16LE pad_0a           // 0x0A: Always 0
INT16LE width_1, height_1 // 0x0C-0x0E: Primary dimensions
INT16LE width_2, height_2 // 0x10-0x12: Flipped/alternate dimensions
INT16LE pos_x, pos_y     // 0x14-0x16: Position in level coordinates
INT16LE behavior         // 0x18: Rope segment length / behavior modifier
UINT16LE velocity_y_file // 0x1A: Part of velocity (runtime)
UINT16LE belt_connect    // 0x1C: Packed belt anchor (LO=cx, HI=cy)
UINT16LE belt_distance   // 0x1E: Distance between belt lines
UINT16LE pad_20          // 0x20: Always 0
UINT16LE rope_1_connect  // 0x22: Packed rope1 anchor (LO=x, HI=y)
UINT16LE pad_24          // 0x24: Always 0
UINT16LE rope_2_connect  // 0x26: Packed rope2 anchor (LO=x, HI=y)
--- variable extra (belt=52, rope=54, pulley=56, prog_ball=60 total bytes) ---
INT16LE connected_1      // -8: Index of connected part 1
INT16LE connected_2      // -6: Index of connected part 2  
INT16LE outlet_plugged_1 // -4: Index of plugged outlet part
INT16LE outlet_plugged_2 // -2: Index of plugged outlet part
```

## 3.2 Flag Semantics

**flags_1:**
- `0x0020`: Physics bias toggle (2 vs 32 units on collision tolerance)
- `0x0040`: Constraint-processing skip flag (rope/belt init)
- `0x0200`: Can flip vertically
- `0x0400`: Can flip horizontally
- `0x0800`: Initially in parts bin
- `0x1000`: Moving, gravity-affected
- `0x2000` / `0x4000`: Static, gravity-immune

**flags_2:**
- `0x0001`: Belt can connect
- `0x0002`: Belt is connected
- `0x0004` / `0x0008`: Rope / Second rope can connect
- `0x0010` / `0x0020`: Horizontally / Vertically flipped
- `0x0080` / `0x0100`: 1D scalable / 2D freely scalable

**flags_3:**
- `0x0001`: Has electrical plug
- `0x0002`: Generator/outlet
- `0x0004`: Combustible/fuse
- `0x0008`: gravity_x direction (wind)
- `0x0040`: Locked in editor
- `0x0080`: Sizable scenery
- `0x0100`: Read-only mechanical part marker
- `0x1000`: Scenery part
- `0x2000`: Wall block
- `0x8000`: Solution component

## 3.3 Level Binary Format

`EF AC 13 01` header:
```c
UINT32LE magic_number    // EF AC 13 01
UINT16LE num_parts
UINT16LE unknown_6       // always 0
UINT16LE bg_color
UINT16LE pressure
UINT16LE gravity         // 272 = standard
UINT16LE unknown_14      // always 0
UINT32LE music_track
UINT16LE num_hints
[num_hints × hint_entry]
UINT16LE num_fixed
[num_fixed × part_entry]
UINT16LE num_moving
[num_moving × part_entry]
[solution_block]
```

## 3.4 Solution Block (132 bytes)

```c
UINT16LE conditions_count
8 × {
  UINT16LE part_index    // 0xFFFF = unused
  UINT16LE part_state_1  // base state
  UINT16LE part_state_2  // sub-state qualifier
  UINT16LE part_count    // count threshold
  INT16LE  rect_x, rect_y
  INT16LE  rect_w, rect_h
}
UINT16LE delay
```
