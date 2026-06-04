# Godot 4.6 Level Editor — Milestones

**Date**: 2026-06-04
**Project**: `godot_level_editor/` (19 GDScript files, 1 scene, 206 YAML test levels, 433 ANM files, 3,054 sprites)

---

## M0: Project Scaffold

| Item | Status |
|------|--------|
| `godot_level_editor/project.godot` (name="level_editor", Godot 4.6 Forward Plus) | ✅ Done |
| `data/` directory copied from `re_crd_gdd/tim2_editor/data/` | ✅ Done |
| `build/` directory with phase-16, phase-9, phase-19, phase-5 JSON/YAML data | ✅ Done |
| `.gitignore` | ✅ Done |
| **Validation**: 433 ANM JSONs, 113 WAVs, 206 YAML levels, 3,054 sprites, 24 palettes | ✅ All present |

---

## M1: Autoload Singletons

| Deliverable | File | Status |
|---|---|---|
| Part database | `autoload/PartDatabase.gd` | ✅ Done |
| ANM cache | `autoload/AnmDatabase.gd` | ✅ Done |
| Behavior registry | `autoload/BehaviorRegistry.gd` | ✅ Done |
| Audio manager | `autoload/AudioManager.gd` | ✅ Done |

**Key Features**:
- `PartDatabase`: loads `part-name-catalog.json` (149 entries) + `part-anm-catalog.json` → provides `get_part_data()`, `get_part_name()`, `get_part_anm_name()`, `get_categories()`
- `AnmDatabase`: loads all 433 ANM files from `data/anm/` at startup → `load_anm()`, `get_default_state_id()`, `get_first_frame_for_state()`, `get_bytecodes_for_frame()`
- `BehaviorRegistry`: loads `solve-decoded.json` (147), `behaviors.json` (state limits), `categories.json`, `part-properties.json` (149), `part-assets.json` (147), `state-machine-report.json` → state limits, SOLVE.RES transitions, behavior rules per category, physics props, orphan state validation
- `AudioManager`: 16-player pool, WAV playback from `data/wav/SX_{id}_11025.wav` (with 22050/8000 fallbacks)

---

## M2: Backend Physics Engine

| Deliverable | File | Status |
|---|---|---|
| Part data struct | `backend/PartData.gd` | ✅ Done |
| World state | `backend/WorldState.gd` | ✅ Done |
| Physics solver | `backend/PhysicsSolver.gd` | ✅ Done |
| Simulation loop | `backend/SimulationLoop.gd` | ✅ Done |
| Level serializer | `backend/LevelSerializer.gd` | ✅ Done |
| Solution checker | `backend/SolutionChecker.gd` | ✅ Done |
| Solution condition | `backend/SolutionCondition.gd` | ✅ Done |

**Key Features**:
- `PartData`: full 48-byte struct with all fields from Python `Part` dataclass (position, velocity, flags, connections, rope/pulley/belt-specific fields, state machine with deterministic LCG RNG, programmable ball fields for type 87, gravity category/system, collision shape dispatch)
- `WorldState`: parts array with gravity/pressure/tick, collision category mapping (STATIC/DYNAMIC/EXPLOSIVE/TOOL/ROPE/SCENERY/CREATED), callbacks for collision and state change
- `PhysicsSolver`: 6-pass deterministic engine matching Python `world.py`:
  - Pass 0: State counters (`advance_state()` with sub_counter delay, RNG random delay for state=0, LIMIT_UPPER/LIMIT_RESET)
  - Pass 1: Gravity integration (`vel_y += gravity`, `pos_y += vel_y >> 9`, wind via `flags_3 & 0x08`, max_gravity clamp)
  - Pass 2: Behavior handlers (conveyor, gear, cannon, rocket, belt sync, etc.)
  - Pass 3: Viewport bounds (floor/ceiling bounce with COR, left/right walls)
  - Pass 4: AABB + circle collision, collision matrix gating, connected parts skip, SOLVE.RES trigger resolution
  - Pass 5: Proximity (fire→balloon) + electrical propagation (source→outlet→consumer)
  - Pass 6: Rope distance constraint (3 iterations) + belt angular velocity sync
- `LevelSerializer`: YAML save/load supporting all sections (level_info, environment, hints, fixed/moving parts with full flags/dimensions/physics, solution conditions)
- `SolutionCondition`: POSITION/OFF_SCREEN/OFF_TOP/OFF_BOTTOM/STATE_ONLY checks with tick counting
- `SolutionChecker`: evaluates all conditions against WorldState
- `SimulationLoop`: 60Hz driver

---

## M3: ANM Rendering Pipeline

| Deliverable | File | Status |
|---|---|---|
| ANM renderer | `backend/AnmRenderer.gd` | ✅ Done |

**Key Features**:
- Full ANM Section D bytecode interpreter (opcodes: END_FRAME=0, END_ANM=1, DRAW_BMP=2, DRAW_RECT=3, DRAW_LINE=4, PLAY_SFX=5)
- Section A→C→B frame pipeline: `state_id → first_frame_id → section_a[index] → section_b[meta] → section_d [bytecodes]`
- Section A animation frame cycling via `state_counter`
- Dimension auto-detect for incline ramps (width 16/32/48/64 match)
- Wall rendering: Section C end-caps + center tile tiling (horizontal and vertical)
- BMP loading from `data/sprites/` (multi-sub-image PNGs, `_f000.png` format)
- Palette system: loads 24 palettes from `data/palettes/` JSON format, VGA 16-color fallback
- Flip support via `appearance & 0x8000` → `Image.flip_x()`
- Resource name resolution: `resource_id=1 → anm_name`, `resource_id>1 → anm_name_{id}`
- DRAW_RECT and DRAW_LINE rasterization onto Image
- BMP/ANM/palette caching

---

## M4: Editor UI v1 — Place & Select

| Deliverable | File | Status |
|---|---|---|
| Main scene | `scenes/Main.tscn` | ✅ Done |
| Editor controller (integrated toolbar + catalog + canvas) | `editor/EditorController.gd` | ✅ Done |
| Level info dialog | `editor/LevelInfoDialog.gd` | ✅ Done |
| Programmable part dialog | `editor/ProgrammablePartDialog.gd` | ✅ Done |
| Part node (via Sprite2D) | built into `EditorController.gd` | ✅ Done |
| Selection handles (via _draw) | built into `EditorController.gd` | ✅ Done |

**Key Features**:
- Full mode machine: SELECT / PLACE / DELETE / CONNECT / PREVIEW / LEVEL INFO
- Keyboard shortcuts: S/P/D/C/Space/I/F/L/Del/Z/0/+/-/Ctrl+S/Ctrl+L/N
- Zoom: scroll wheel (1.25× factor), Z reset, zoom range 0.25×–4.0×
- Pan: middle mouse drag
- Grid: drawn in `_draw()` with 16px step, pan/zoom aware
- Part placement: grid-snapped (16px), click catalog part → click canvas
- Selection: click to select, drag to move, amber outline + 8 resize handles drawn
- Connection tool: click source → preview line → click target → `connected_1` link
- Save/Load: FileDialog with *.yaml filter
- Part rendering via ANM sprites with fallback to colored rectangles
- Mode indicator + zoom indicator in status bar
- Preview: snapshot save/restore, physics step in `_process()`, timeout at 10,000 ticks

---

## M5: Editor UI v2 — Tools & Dialogs

| Deliverable | File | Status |
|---|---|---|
| Selection handles | integrated in `EditorController.gd` | ✅ Done |
| Connection tool | integrated in `EditorController.gd` | ✅ Done |
| Solution rect tool | `editor/SolutionRectTool.gd` | ✅ Done |
| Level info dialog | `editor/LevelInfoDialog.gd` | ✅ Done |
| Programmable part dialog | `editor/ProgrammablePartDialog.gd` | ✅ Done |

**Key Features**:
- Selection handles: 8-point (corners + midpoints), amber `Color(1, 0.78, 0)`, zoom-aware size
- Connection preview line: amber dashed line from source center to cursor
- `LevelInfoDialog`: Window with 6 fields (title, goal, bg_color, pressure, gravity, music_track), OK/Cancel, int validation
- `ProgrammablePartDialog`: Window with 4 fields (density, elasticity, friction, gravity_buoyancy)
- `SolutionRectTool`: click-drag to define solution rectangles, cancel support

---

## M6: Preview & Solution Checking

| Deliverable | File | Status |
|---|---|---|
| Game controller | `game/GameController.gd` | ✅ Done |
| Goal bar | `game/GoalBar.gd` | ✅ Done |
| Solve overlay | `game/SolveOverlay.gd` | ✅ Done |

**Key Features**:
- `GameController`: 3-state machine (SELECT_LEVEL → PLAYING → SOLVED), level loading via `LevelSerializer.load_yaml()`, `SimulationLoop.tick()` in `_physics_process()`, WIN detection via `SolutionChecker`
- `GoalBar`: text label with custom font color/size, show/hide
- `SolveOverlay`: semi-transparent overlay with "LEVEL SOLVED!" text, auto-dismiss after 3 seconds

---

## M7: Polish & Edge Cases

| Deliverable | Status | Notes |
|---|---|---|
| Part handles (8-point resize handles) | ✅ Done | Drawn in `_draw()` with grid snapping |
| Flip (F key) | ✅ Done | `appearance ^= 0x8000` |
| Lock (L key) | ✅ Done | Toggle `is_moving` flag |
| Delete (Del key) | ✅ Done | Remove part from world + canvas |
| Connection preview line | ✅ Done | Amber line from source to cursor |
| Part tooltip on hover | ❌ Pending | Show part name near cursor |
| Undo/redo (command stack) | ❌ Pending | Ctrl+Z/Ctrl+Y — stretch goal |
| Toolbar icons from ANM sprites | ❌ Pending | ICONS1-10 ANM — stretch goal |
| Dedicated catalog panel scene | ❌ Pending | Currently built in EditorController |
| Dedicated viewport canvas scene | ❌ Pending | Currently built in EditorController |
| Dedicated toolbar scene | ❌ Pending | Currently built in EditorController |

---

## Summary

| Milestone | Files | Status |
|---|---|---|
| M0: Scaffold | 1 project.godot, 1 .gitignore | ✅ Done |
| M1: Autoloads | 4 GDScript | ✅ Done |
| M2: Backend | 7 GDScript | ✅ Done |
| M3: ANM Renderer | 1 GDScript | ✅ Done |
| M4: Editor UI v1 | 2 GDScript + 1 scene | ✅ Done |
| M5: Editor UI v2 | 3 GDScript | ✅ Done |
| M6: Game Play | 3 GDScript | ✅ Done |
| M7: Polish | integrated | 🟡 Partial (3/7 items done) |
| **Total** | **19 GDScript, 1 scene** | **M0–M6 complete, M7 partial** |

### Files Created

```
godot_level_editor/
├── project.godot
├── .gitignore
├── autoload/
│   ├── PartDatabase.gd
│   ├── AnmDatabase.gd
│   ├── BehaviorRegistry.gd
│   └── AudioManager.gd
├── backend/
│   ├── PartData.gd
│   ├── WorldState.gd
│   ├── PhysicsSolver.gd
│   ├── SimulationLoop.gd
│   ├── LevelSerializer.gd
│   ├── SolutionChecker.gd
│   ├── SolutionCondition.gd
│   └── AnmRenderer.gd
├── editor/
│   ├── EditorController.gd
│   ├── LevelInfoDialog.gd
│   ├── ProgrammablePartDialog.gd
│   └── SolutionRectTool.gd
├── game/
│   ├── GameController.gd
│   ├── GoalBar.gd
│   └── SolveOverlay.gd
└── scenes/
    └── Main.tscn
```

### Data Assets

| Type | Count |
|---|---|
| GDScript files | 19 |
| Scene files | 1 |
| ANM JSON files | 433 |
| Sprite BMP files | 3,054 |
| Palette JSON files | 24 |
| WAV sound files | 113 |
| YAML test levels | 206 |
| Data JSON files | 7 |
