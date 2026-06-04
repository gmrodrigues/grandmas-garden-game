# 6. Animation System (ANM)

The ANM system dictates exactly what sprite to draw for each part at any given state, and at what speed. 

## 6.1 ANM File Format

The `ANM` files are chunked containers containing a "TB" inner format. The python extractor has parsed these into `JSON` formats for Godot to load.

```c
ANM: chunked container:
  magic "ANM:" (4 bytes)
  size UINT32LE
  inner "TB" format:
    magic "TB" (2 bytes)
    version UINT16LE (1000 or 1001)
    section_sizes[4] UINT16LE  // A, B, C, D sizes
    width, height (UINT16LE each)
    Section A: UINT16LE[nFrames] tick durations
    Section B: 10-byte entries {x, y, w, h, bytecode_offset}
    Section C: 4-byte entries {first_frame_id, state_id}
    Section D: bytecode stream
```

## 6.2 The Rendering Pipeline in Godot (`ANMPlayer.gd`)

Since Godot's `AnimationPlayer` cannot execute `DRAW_BMP` TIM2 bytecode dynamically, we implement a custom node.

1. **State Translation (Section C)**
   Poll the `backend` for the part's `current_state`.
   ```gdscript
   for entry in Section_C:
       if entry.state_id == current_state:
           first_frame_id = entry.first_frame_id
   ```

2. **Frame Timing (Section A)**
   Section A provides tick durations per frame. The state engine's 60 Hz tick counter drives frame advancement.
   `current_frame_id = first_frame_id + (state_counter % loop_length)`

3. **Frame Execution (Section B & D)**
   Fetch the `bytecode_offset` from Section B for the `current_frame_id`.
   Execute the opcodes found in Section D at that offset.

## 6.3 Bytecode Opcodes (Section D)

Six opcodes, all UINT16LE:

| Cmd | Opcode | Parameters | Description |
|-----|--------|------------|-------------|
| 0 | `END_FRAME` | — | End current frame bytecode |
| 1 | `END_ANM` | — | End entire animation |
| 2 | `DRAW_BMP` | `res_id, sub_image, x, y, flags` | Draw BMP sub-resource |
| 3 | `DRAW_RECT` | `x, y, w, h, color, flags` | Fill rectangle |
| 4 | `DRAW_LINE` | `x1, y1, x2, y2, flags` | Draw line |
| 5 | `PLAY_SFX` | `sound_id` | Play sound effect |

### Flag Decoding
- **DRAW_BMP flags**: `bit 0` = horizontal flip, `bit 1` = vertical flip. Maps directly to Godot `Sprite2D.flip_h` and `flip_v`.
- **DRAW_RECT flags**: `bit 15` = Absolute coordinates vs relative. Bits 0-3 = Draw mode (e.g. `0xB` is filled with border, `0x1` is outline only). Maps to Godot `ColorRect` or custom `_draw()` calls.
