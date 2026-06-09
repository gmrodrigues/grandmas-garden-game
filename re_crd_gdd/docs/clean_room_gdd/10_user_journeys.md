# 10. Catálogo de User Journeys (Fluxos de UX)

Este documento especifica os 14 diagramas de interação e fluxo de usuário ponta-a-ponta, extraídos do motor original. Ele estabelece as regras exatas das máquinas de estado da Interface Gráfica (UI) que a versão da Godot deve implementar.


Complete specification for all 14 user journeys in The Incredible Machine 2.
Cross-referenced with the original game manual (SierraChest walkthrough),
the Python reference editor (`tim2_editor/`), and reverse-engineered ANM/BMP assets.

## Journey Overview

| ID | Journey | Original Game | Python Editor | Standalone Script |
|----|---------|:---:|:---:|:---:|
| J01 | Sign-In Window | Yes | ❌ | `j01_signin.py` |
| J02 | Main Menu | Yes | ❌ | `j02_mainmenu.py` |
| J03 | Puzzle Select | Yes | ❌ | `j03_puzzle_select.py` |
| J04 | Parts Bin — Browse & Place | Yes | ✅ | `j04_parts_bin.py` |
| J05 | Part Handles — Flip/Stretch/Program/Delete | Yes | ❌ | `j05_part_handles.py` |
| J06 | Connections — Rope/Belt/Electrical | Yes | ✅ | `j06_connections.py` |
| J07 | Programmable Parts — 14 dialogs | Yes | ❌ | `j07_programmable.py` |
| J08 | Simulation — Start/Observe/Pause/Reset | Yes | ✅ | `j08_simulation.py` |
| J09 | Simulation — Solve Conditions | Yes | ✅ | `j09_solve.py` |
| J10 | Save & Load | Yes | ✅ | `j10_save_load.py` |
| J11 | Player Preferences | Yes | ❌ | `j11_preferences.py` |
| J12 | Music & Sound | Yes | ❌ | `j12_music_sound.py` |
| J13 | Hints & Info Dialogs | Yes | ❌ | `j13_hints_info.py` |
| J14 | Head-to-Head | Yes | ❌ | `j14_head_to_head.py` |

---

## J01 — Sign-In Window

![J01 UI](../../build/phase-3/bitmaps/SIGN_IN_f000.png)


### Screen Spec
- ANM: `SIGN_IN.ANM` (279×125 canvas)
- BMP: `SIGN_IN.BMP`
- Original features per manual:
  - Dark blue player name input field
  - Light blue player registry (all signed-in names)
  - Green help question mark button
  - Done button

### Interaction Flow
```
Window opens → type name → Enter/Add → name in registry
→ click name to select → Done → proceed to Main Menu
```

### States
| State | ANM State | Visual |
|-------|-----------|--------|
| Idle | 1 | Window visible, empty input |
| Editing | 2 | Cursor in name field |
| Selected | 3 | Name highlighted in registry |
| Done | 4 | Window closing |

### Test Script
- Asset checks: SIGN_IN.ANM exists, has valid Section C/B/D
- Behavioral: input parsing, registry management, selection
- Manual: `python3 scripts/phase-20/journeys/j01_signin.py --interactive`

---

## J02 — Main Menu

![J02 UI](../../build/phase-3/bitmaps/MAINMENU_f000.png)


### Screen Spec
- ANM: `MAINMENU.ANM` (672×377 canvas, 11 states, 116 frames)
- BMP: `MAINMENU.BMP`, `MAINBUTN.BMP`

### Button Layout (per manual)
| Row | Left | Center | Right |
|-----|------|--------|-------|
| Upper | Puzzle Play | Professor Tim's Workshop | Head-to-Head |
| Lower | Guided Tour | Sign-In | Tutorial |
| Right icons | Computer (preferences) | Stop (quit) | Question mark (help) |

### Interaction Flow
```
Main Menu → hover button → click → navigate to target screen
Computer icon → J11 Preferences
Stop icon → Quit dialog → Exit
```

### States
| State | Description |
|-------|-------------|
| idle | Menu visible, all buttons ready |
| hover_X | Button X highlighted |
| click_X | Navigate to target screen |
| quit | Exit game |

---

## J03 — Puzzle Select

![J03 UI](../../build/phase-3/bitmaps/MAINPUZL_f000.png)


### Screen Spec
- BMP: `PUZDISP.BMP`, `PUZTYPE1.BMP` through `PUZTYPE8.BMP`
- 206 levels across 7 categories

### Categories (per manual)
| Category | Level Prefix | Count |
|----------|-------------|-------|
| Tutorial | TLEV* | ~40 |
| Easy | ELEV* | 26 |
| Medium | MLEV* | 30 |
| Hard | HLEV* | 31 |
| Really Hard | RLEV* | 29 |
| Head-to-Head | HH* | 50 |
| Workshop (custom) | user-saved | varies |

### Interaction Flow
```
Select category → scroll puzzle list → click puzzle → LOAD
Light bulb icon: solved (on) / unsolved (off)
Double-click = quick load
```

---

## J04 — Parts Bin → Browse & Place

![J04 UI](../../build/phase-3/bitmaps/BINSOLVE_f000.png)


### Screen Spec
- ANM: `BINSOLVE.ANM` (8 states, 9 frames)
- BMP: `ICONS1-10.BMP`, `PARTSBIN.BMP`
- Data: `build/phase-9/part-name-catalog.json` (149 parts × 19 categories)

### Hotkeys (per manual)
| Key | Category |
|-----|----------|
| B | Balls |
| W | Walls |
| P | Pipes |
| I | Inclines |
| A | Arches |
| O | Pool Stuff |
| G | Gears & Belts |
| R | Ropes |
| F | Flames |
| E | Electrical |
| L | Lasers |
| M | Mouse Cage |
| C | Critters |

### Interaction Flow
```
Parts Bin visible → scroll categories → hover part → part name tooltip
→ click part → part attached to cursor → click canvas → part placed at grid snap
→ right-click existing part → duplicate copy
```

### In-Editor Status
- Catalog panel: ✅ Implemented (`tim2_editor/main.py:draw_catalog()`)
- Grid snap: ✅ (`16px grid`, `place_part()`)
- Hotkeys: 🟡 Not implemented
- Duplicate: 🟡 Not implemented
- Tooltips: 🟡 Not implemented

---

## J05 — Part Handles

![J05 UI](../../build/phase-3/bitmaps/BUTTONS_f000.png)


### Handle Types (per manual)
| Handle | Icon | Action |
|--------|------|--------|
| Recycle | Trash can | Remove part back to Parts Bin |
| Flip | Curved arrows | Rotate/flip part orientation |
| Size/Stretch | Double arrow | Click-drag to resize |
| Program | Computer | Open programming dialog (J07) |
| Info | Magnifying glass | Open info dialog (J13) |
| Solve | Checkered flag | Program solution condition (Workshop only) |
| Lock | Padlock | Lock part in position (Workshop only) |

### ANM Reference
- `HANDLES.ANM` (16 states, 108 frames, animated)
- `BUTTONS.ANM` (21 states, 49 frames)

### Interaction Flow
```
Part placed on canvas → cursor over part → handles appear as overlay
→ click handle → execute action
→ flip: rotate clockwise 90°/flip horizontal/flip vertical
→ stretch: click-drag to resize, click to set
→ recycle: remove part
→ program: open dialog window
→ info: open description window
```

---

## J06 — Connections

### Connection Types (per manual)
**Rope** (part type 10, steel cable type 76):
- Attaches to 16 part types: Teeter-Totter, Leaky Bucket, Lava Lamp, Pulley, Boat Cleat,
  Phazer, Mandrill Motor, Trans-Roto-Matic, Laundry Basket, Balloon, Tipsy Trailer,
  Roto-Trans-Converter, Bucket, Hot Air Balloon, Match-on-a-spring, Remote Control Bomb

**Belt** (part type 8):
- Attaches to 11 rotating part types: Large Gears, Small Gears, Pinwheel, Conveyor Belt,
  Mouse Motor, Generator, Electric Motor, Trans-Roto-Matic, Roto-Trans-Converter,
  Jack-in-the-Box, Mandrill Motor

**Electrical** (outlet connections):
- 5 power sources: Generator, Electric Switch & Outlet, Electrical Outlet,
  Solar Panel, Laser-Activated Plug

### Interaction Flow
```
Select Rope/Belt from Parts Bin → cursor shows line
→ click first part (anchor turns red) → drag to second part
→ line turns green when valid connection → click to attach
→ connection line drawn between parts (center-to-center)
```

### Part Struct Fields
- `connected_1`, `connected_2`: Part indices for rope/belt connections
- `outlet_plugged_1`, `outlet_plugged_2`: Part indices for electrical
- `belt_anchor_x/y`, `rope_1_anchor_x/y`, `rope_2_anchor_x/y`: Anchor positions

### In-Editor Status
- Connection line rendering: ✅ (`main.py:draw_part()` lines 330-337)
- Click-and-drag connection tool: ❌ Not implemented
- Red/green line color feedback: ❌ Not implemented

---

## J08 — Simulation → Run/Pause/Reset

![J08 UI](../../build/phase-3/bitmaps/MAINPIEC_f000.png)


### Game Loop (per godot-specification.md §1)
```
60 Hz tick rate
  Pass 0: advance state machines
  Pass 1: apply gravity
  Pass 2-3: AABB collision detection + response
  Pass 4-5: proximity interactions
  Pass 6-7: constraint enforcement (3 passes)
```

### Controls (per manual)
| Action | Trigger |
|--------|---------|
| Start | Click green flag (Parts Bin) |
| Stop/Pause | Click checkered flag |
| Reset | Click broom icon (remove unlocked parts) |
| Timeout | Auto-stop after ~10,000 ticks (if unsolved) |

### Visual Feedback
- Parts animate via ANM state machine (Section C → Section D bytecode)
- Moving parts update position each tick
- Collisions trigger state transitions + sound effects
- Goal Bar shows progress

### In-Editor Status
- Simulation loop: ✅ (`world.py:step()` 5 passes)
- Green flag / play toggle: ✅ (space bar, `toggle_preview()`)
- Reset on stop: ✅ (`world.reset()`)
- ANM rendering during sim: 🟡 (gray rectangles placeholder)
- Sound on collision: ❌ Not implemented

---

## J09 — Simulation → Solve Conditions

![J09 UI](../../build/phase-3/bitmaps/SOLVE_f000.png)


### Condition Types
| Type | Rect | Check |
|------|------|-------|
| Position | (x, y, w, h) | Part bbox overlaps target rect |
| Off-screen | (-1, -1, -1, -1) | Part outside viewport |
| Off-top | (-500, -2000, 1640, 2000) | Part above screen |
| Off-bottom | (-500, 400, 1640, 3000) | Part below screen |
| State-only | (0, 0, 0, 0) | part.state_counter == target_state |

### Solution Struct (per level file)
```
conditions_count: N
delay: ticks_before_end
conditions:
  - part_index: INT16LE
    part_state_1: UINT16LE
    part_state_2: UINT16LE
    part_count: UINT16LE
    rect: { x, y, width, height }
```

### Interaction Flow
```
Simulation runs → each tick: check all conditions
→ all met → delay_ticks → puzzle solved overlay
→ SOLVE.ANM victory animation
→ menu: Replay / Next Puzzle / Back to Select
```

### In-Editor Status
- Solution checker: ✅ (`solver.py`)
- Green target rects: ✅ (`main.py:draw()` lines 242-252)
- Victory overlay: ❌ SOLVE.ANM not integrated
- Victory menu: ❌ Not implemented

---

## J10 — Save & Load

![J10 UI](../../build/phase-3/bitmaps/LOADSAVE_f000.png)


### Actions (per manual)
| Action | Shortcut | Description |
|--------|----------|-------------|
| Save | Ctrl+S | Serialize level to YAML file |
| Load | Ctrl+L | Load YAML file, populate editor |
| New | N key | Clear editor, start empty level |

### Serialization Format
```
level_info: magic, title, goal, bg_color
environment: pressure, gravity, music_track
hints: count, entries
parts: fixed_count, moving_count, part_entries
solution: conditions_count, delay, conditions
```

### Fidelity Requirements
- All 48-byte part struct fields preserved
- Hex flags (`0xNNNN`) preserved
- Connections (connected_1/2, outlet_plugged_1/2) preserved
- Solution conditions preserved
- Float/int round-trip tolerance

### In-Editor Status
- Save: ✅ (`save_yaml()` → 269 lines of YAML output)
- Load: ✅ (`load_yaml()` → regex parser, all 206 levels)
- New: ✅ (`new_level()`)
- Shortcuts: ✅ (`Ctrl+S`, `Ctrl+L`, `N`)

---

## J11 — Player Preferences

### Toggles (per manual)
| Preference | Default | Effect |
|------------|---------|--------|
| Ambient Animation | ON | Parts wiggle/twinkle when idle |
| Scenery Displayed | ON | Background scenery visible |
| Background | ON | Wallpaper/tiles/color blocks |
| Info Handles | ON | Magnifying glass on part hover |
| Sound Effects | ON | Play sounds on collisions/actions |

### Storage
- JSON file in user data directory
- Keyed by player name (from J01 sign-in)
- Loaded on game start, saved on preference change

---

## J12 — Music & Sound

### Music System
- Tracks: IDs 1000–1023 (24 tracks)
- Format: FM synthesis via ADL.DRV (OPL2)
- Access: Click guitar icon on control panel

### Sound Effects
- FM synthesis: 14 patches in TIM2.SX (IDs < 300)
- Digital audio: 113 RAW files at 11025 Hz (IDs 3001–3754)
- Access via ANM Section D bytecode: `PLAY_SFX sound_id`

### Controls
| Control | Action |
|---------|--------|
| Music list | Scroll, click to select |
| Note button | Restart current track |
| Switch | Turn music on/off |
| POW button | Preview selected sound effect |
| Volume arrows | Increase/decrease volume |
| Done | Close panel |

---

## J13 — Hints & Info Dialogs

### Info Dialogs
- ANM: `INFO0.ANM` through `INFO148.ANM` (one per part type)
- Each displays: part name, description, usage tips
- Access: click magnifying glass handle on part OR click ? then click part
- Text source: `build/phase-9/part-name-catalog.json` description field

### Hints System
- ANM: `HINTLOCK.ANM` (4 states, 43 frames)
- Each level can have 0–5 hints
- Hint data: position (x, y), icon flip, text
- Access: click Hand icon on control panel → pointing hands appear → click to read

### Professor Help
- ANM: `PROFESOR.ANM` (329×138 canvas)
- Professor Tim provides contextual tips
- Triggered by tutorial and guided tour modes

---

## J14 — Head-to-Head Mode

![J14 UI](../../build/phase-3/bitmaps/MAINH2H_f000.png)


### Screen Spec
- ANM: `HEDTOHED.ANM` (639×399, 5 states, 21 frames)
- 50 head-to-head puzzles

### Gameplay
- Two players alternate turns placing parts
- Turn indicator shows current player
- Each player builds toward completing the puzzle
- First player to trigger solution wins
- Score tracking per puzzle

### In-Editor Status
- Not implemented in Python editor
- Standalone test script only

---

## Validation

- **Master runner**: `scripts/phase-20/01-validate-user-journeys.py`
- **Per-journey scripts**: `scripts/phase-20/journeys/j{NN}_{name}.py`
- **Logs**: `build/phase-20/logs/J{NN}_{timestamp}.log`
- **Report**: `build/phase-20/user-journey-report.json`

### Running Tests
```bash
# List all journeys
python3 scripts/phase-20/01-validate-user-journeys.py --list

# Run all headless
python3 scripts/phase-20/01-validate-user-journeys.py

# Run one interactively (with pygame window)
python3 scripts/phase-20/01-validate-user-journeys.py --interactive J04

# Run specific journey headless
python3 scripts/phase-20/01-validate-user-journeys.py --journey J08
```

---

## Sound & Animation Integration

Every user journey references specific sound effects and animation states.
The following table shows which journeys trigger audio and ANM playback:

### Sound References by Journey

| Journey | Sound Type | Sound IDs | Source |
|---------|-----------|-----------|--------|
| J01 Sign-In | — | — | No sounds in original |
| J02 Main Menu | UI click | 3000 (menu select) | MAINMENU ANM PLAY_SFX |
| J03 Puzzle Select | UI click, solved jingle | 3000, custom | PUZLTYPE BMP |
| J04 Parts Bin | Part pickup/place | 5, 3005 (generic pickup) | BINSOLVE ANM |
| J05 Part Handles | Flip, stretch click | per-part sounds | BUTTONS/HANDLES ANM |
| J06 Connections | Rope snap, belt attach | 3006 (click) | Connection validation |
| J07 Programmable | Open/close dialog | 3000 (UI) | INFO ANMs |
| J08 Simulation | Collision sounds | per-part sounds (61 unique IDs) | PLAY_SFX in ANM bytecode |
| J09 Solve | Victory fanfare | 3000, SOLVE sequence | SOLVE ANM |
| J10 Save/Load | Disk write | — | OS-level |
| J11 Preferences | Toggle click | 3000 | UI feedback |
| J12 Music & Sound | Track playback, SFX preview | 1000–1023 (music), 3001–3754 (SFX) | ADL.DRV + RAW files |
| J13 Hints | Hint reveal | 3000 | HINTLOCK ANM |
| J14 Head-to-Head | Turn change, victory | 3000, custom | HEDTOHED ANM |

### Animation States by Journey

| Journey | ANM | States Used | Frame Range |
|---------|-----|-------------|-------------|
| J01 Sign-In | SIGN_IN | 2 (editing), 3 (selected), 5 (idle) | 0–7 |
| J02 Main Menu | MAINMENU | 1–11 (11 states) | 0–460 (animated) |
| J03 Puzzle Select | — | (static BMPs) | PUZDISP, PUZTYPE1-8 |
| J04 Parts Bin | BINSOLVE | 1–8 | 0–8 |
| J05 Part Handles | HANDLES, BUTTONS | 1–16 (HANDLES), 1–21 (BUTTONS) | 0–107, 0–48 |
| J06 Connections | — | Dynamic (line drawing) | Draw via DRAW_LINE opcode |
| J07 Programmable | INFO0–INFO148 | 1 (info display) | 1–72 (varies per part) |
| J08 Simulation | PART0–PART261 | All part states (89 unique IDs) | 0–189 (varies) |
| J09 Solve | SOLVE | 1 (solved overlay) | 0–N |
| J10 Save/Load | LOADSAVE | 1,3,5 | 0–10 |
| J11 Preferences | — | (button highlights) | — |
| J12 Music & Sound | — | Track list, volume bar | Draw via DRAW_RECT |
| J13 Hints | HINTLOCK | 1–4 | 0–216 (animated) |
| J14 Head-to-Head | HEDTOHED | 1–5 | 0–20 |

### Validation Requirements for Sounds

Every journey test script that references sounds must:
1. Check that the sound ID exists in `behaviors.json` per-part `sounds[]`
2. Verify WAV file exists: `build/phase-6/raw-wav/SX_{ID}_11025.wav`
3. In interactive mode: play the sound when the associated action occurs
4. Log every sound triggered with sound_id and WAV path

### Validation Requirements for Animations

Every journey test script that references ANM states must:
1. Check that the ANM JSON exists in `build/phase-4/anm/`
2. Verify that the state ID exists in ANM Section C
3. Verify frame metadata exists in Section B
4. Verify PNG files exist for each DRAW_BMP sprite reference
5. Log state→frame→sprite resolutions

### Animation Frame Timing (Standard 60 Hz)

| Timing Type | Description |
|-------------|-------------|
| Static ANM | Section A empty — frame changes only on state transition |
| Animated ANM | Section A has durations — frames advance per tick |
| Idle animation | Parts wiggle/twinkle when ambient animation is ON (preference) |
| State transition | Instant frame change when state_counter changes |
| Sub-state countdown | Temporary state with timed reversion (offsets 0xAE–0xB0) |

## See Also

- `build/phase-15/handoff/godot-specification.md` §1 — Game loop (moved from docs/godot-specification.md)
- `tim2_specs/state-machine-specification.md` — Full state machine reference
- `tim2_specs/validation-directives.md` — Validation architecture and patterns
- `tim2_specs/user-journey-specification.md` — Full user journey reference
- `tim2_editor/main.py` — Python editor reference implementation
- `tim2_editor/game.py` — Game mode
- `tim2_editor/sandbox.py` — Interactive part viewer
- `scripts/phase-20/journeys/` — Per-journey test scripts
