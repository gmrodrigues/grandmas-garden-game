# Godot 4.6 Level Editor — Implementation Plan

**Project**: `level_editor`
**Location**: `godot_level_editor/`
**Godot Version**: 4.6 (Forward Plus, GDScript)
**Reference**: Python editor at `re_crd_gdd/tim2_editor/` (1,077 LOC, fully functional)
**Date**: 2026-06-04

---

## 1. Project Overview

Full-featured graphical level editor for TIM2 (The Incredible Machine 2), porting the
Python reference editor into Godot 4.6 with complete ANM animation support and
deterministic 60Hz physics.

Architecture: pure-logic backend (no scene dependencies) + Godot scene graph frontend.
Physics and simulation are decoupled from rendering — the same WorldState can be
driven by editor tools or game-play mode.

---

## 2. Directory Structure

```
godot_level_editor/
├── project.godot                    name="level_editor"
├── data/                            ← copy from re_crd_gdd/tim2_editor/data/
│   ├── part-name-catalog.json       149 entries
│   ├── anm/                         433 JSON files
│   ├── sprites/                     BMP PNGs
│   ├── palettes/                    24 palette JSON+PNG
│   └── wav/                         113 WAV files
├── autoload/
│   ├── PartDatabase.gd             singleton: catalog + physics props lookup
│   ├── AnmDatabase.gd              singleton: all 433 ANM JSONs cached
│   ├── BehaviorRegistry.gd          singleton: SOLVE.RES, state limits, categories
│   └── AudioManager.gd             sound pool (16 players), WAV playback
├── backend/                         pure logic, no Node2D/RigidBody
│   ├── PartData.gd                 48-byte struct, all physics fields
│   ├── WorldState.gd               parts[], gravity, pressure, tick_count
│   ├── PhysicsSolver.gd            6-pass deterministic engine @ 60Hz
│   ├── SolutionChecker.gd          evaluates SolutionCondition[] vs WorldState
│   ├── LevelSerializer.gd          YAML load/save (full spec from level.py)
│   └── SimulationLoop.gd           drives PhysicsSolver.tick() at 60Hz
├── editor/                          editor-mode UI and tools
│   ├── EditorController.gd         main handler: mode machine, input
│   ├── CatalogPanel.gd             part browser: category tree + thumbnails
│   ├── ViewportCanvas.gd           TileMap (grid) + pan/zoom + part container
│   ├── PartNode.gd                 per-part: Area2D + Sprite2D + CollisionShape2D
│   ├── SelectionHandles.gd         8-point resize handles + action labels
│   ├── ConnectionTool.gd           rope/belt connection drawing + validation
│   ├── SolutionRectTool.gd         click-drag solution rectangles
│   ├── LevelInfoDialog.gd          modal: title/goal/bg_color/pressure/gravity/music
│   ├── ProgrammablePartDialog.gd   modal: type-87 density/elasticity/friction/buoyancy
│   └── Toolbar.gd                  top bar: mode buttons, save/load/new, preview
├── game/                            game-play mode
│   ├── GameController.gd           top-level: SELECT_LEVEL → PLAY → SOLVED
│   ├── GoalBar.gd                  animated goal text
│   └── SolveOverlay.gd             WIN overlay when solution conditions met
└── scenes/
    ├── Main.tscn                   VBox: toolbar + (canvas | catalog)
    └── PartNode.tscn               per-part sprite scene
```

---

## 3. Key Deliberables

### Rendering: TileMap + Sprite2D (per-part)
- TileMap layer 0: grid background.
- Each placed part is a `Sprite2D` child of ViewportCanvas (not TileMap cells —
  parts can be any size, layered, non-grid-aligned).
- Catalog panel: 32×32 thumbnails via AnmRenderer.
- PartNode.tscn: Area2D + Sprite2D + CollisionShape2D. Click-to-select via input_event.
- Z-index: scenery (-1), fixed (0), moving (+1).

### Full ANM Bytecode Interpreter
- AnmDatabase autoload: loads all 433 JSON files into `anm_cache{}` at startup.
- AnmRenderer (RefCounted, not Node):
  - `load_anm(anm_name) → dict`
  - `get_default_state_id(anm_name) → int`
  - `get_first_frame_for_state(anm_data, state_id) → int`
  - `render_frame(anm_name, state_id, frame_idx, bmp_dir) → Image`
  - `render_wall(anm_name, w, h, bmp_dir) → Image`
- ANM Section D opcodes: END_FRAME(0), END_ANM(1), DRAW_BMP(2), DRAW_RECT(3),
  DRAW_LINE(4), PLAY_SFX(5).
- BMP loading: `resource_id` → BMP filename; `sub_image` → sub-image index.
  Multiple sub-images per BMP file (16×16 default).
- Palette: 24 named palettes from `data/palettes/`. TTLMED default; per-level
  `bg_color` index (0–15) selects from palette list.
- Flip: `appearance & 0x8000` → `Image.flip_horizontally()`.
- Caching: BMP surfaces by path+sub_image; ANM JSON by name; palettes by name.

### Physics: 6-Pass Deterministic Engine
Matches Python `world.py` exactly — runs at 60Hz independent of rendering.

| Pass | Name | Behavior |
|------|------|----------|
| 0 | State counters | `advance_state()` — sub_counter delay OR random(40-239) for state=0, else advance with LIMIT_UPPER wrap |
| 1 | Gravity | `vel_y += gravity; pos_y += vel_y >> 9`; wind (`flags_3 & 0x08`) → `vel_x -= gravity/2`; clamp to max_gravity |
| 2 | Behaviors | Per-part handlers: motor angular velocity, conveyor, rocket thrust, etc. |
| 3 | Viewport bounds | Floor bounce at `viewport.h - 32`; ceiling bounce at 0; left/right clamp |
| 4 | Collisions | O(N²) AABB; shape dispatch (circle vs AABB); collision matrix gating; connected parts skip; state bump via SOLVE.RES |
| 5 | Electrical/proximity | `_propagate_electrical()` — outlet→consumer via `outlet_plugged_1/2`; proximity triggers (fire→balloon) |
| 6 | Constraints | Rope distance constraint (3 iterations); belt angular velocity avg sync |

State machine from `state-machine-specification.md` §2 — 17 parts need custom
LIMIT_UPPER (up to 37 for rockets). State limits loaded from `godot/behaviors.json`.

### Data Files (copy from re_crd_gdd/tim2_editor/data/)
- `part-name-catalog.json` (149 entries) → PartDatabase.gd
- `anm/*.json` (433 files) → AnmDatabase.gd
- `sprites/` (BMP PNGs) → ANM rendering
- `palettes/*.json` (24 palettes) → palette system
- `wav/*.wav` (113 files) → AudioManager.gd
- `build/phase-16/solve-decoded.json` (147 entries) → BehaviorRegistry.gd
- `build/phase-16/godot/behaviors.json` (147 entries) → state limits per part
- `build/phase-9/part-properties.json` (149 entries) → physics props (mass, COR, friction, collision dims)
- `build/phase-16/part-assets.json` (147 entries) → sound IDs + ANM metadata
- `build/phase-19/state-machine-report.json` → orphan ANM states (warning at load)
- `build/phase-5/yaml/*.yaml` (206 levels) → test corpus

---

## 4. Collision Categories (from world.py)

```
STATIC     → Walls, Floors, Inclines
DYNAMIC    → Balls, Containers, Characters, Pipe Systems, Pool Table
EXPLOSIVE  → Explosives, Projectiles
TOOL       → Cutting, Springs, Rotating Power, Electrical, Lasers, Special Mechanics
ROPE       → Ropes, Belts, Pulleys (ROPE only collides with ROPE)
SCENERY    → Light/Flame Sources, Scenery (no collisions)
CREATED    → Created/Phantom (hits STATIC only)
```

Collision matrix asymmetric — 6 known asymmetries documented in `world.py`.

---

## 5. Editor Modes & Hotkeys

| Key | Mode | Behavior |
|-----|------|----------|
| S | SELECT | Click part to select → drag to move → 8 resize handles → F/L/Del actions |
| P | PLACE | Click catalog → click canvas to place (16px grid snap) |
| D | DELETE | Click part to delete |
| C | CONNECT | Click source → drag line → click target → `connected_1` link |
| Space | PREVIEW | Save snapshot → run sim → check solution → show WIN/timeout → restore |
| I | LEVEL INFO | Modal: title, goal, bg_color(0–15), pressure, gravity, music_track |
| F | FLIP | `appearance ^= 0x8000` on selected |
| L | LOCK | Toggle `is_moving` flag (0x1000 in flags_1) |
| Delete | DELETE | Remove selected part |
| Ctrl+S | SAVE | File dialog → LevelSerializer.save_yaml() |
| Ctrl+L | LOAD | File dialog → LevelSerializer.load_yaml() |
| N | NEW | Create empty LevelData |
| Z | ZOOM RESET | zoom = 1.0 |
| +/- | ZOOM | zoom *= 1.25 / 0.8 |
| Scroll | CANVAS ZOOM / CATALOG SCROLL | context-sensitive |
| Middle drag | PAN | pan canvas |
| Tab | DIALOG NAV | cycle fields in modals |

---

## 6. Solution Checking

- SolutionChecker evaluates all SolutionCondition after each tick.
- Condition types: POSITION (rect intersection), OFF_SCREEN, OFF_TOP, OFF_BOTTOM, STATE_ONLY.
- Condition must hold for `ticks_to_wait` consecutive ticks before triggering WIN.
- Preview mode: saves YAML snapshot → runs simulation → shows message → restores.
- Timeout: 10,000 ticks → "❌ Timeout — conditions not met".

---

## 7. Audio

- AudioManager: 16-player AudioStreamPlayer pool.
- `play_sfx(sound_id)`: loads `data/wav/SX_{id}_11025.wav` (22050/8000 variants exist).
- PLAY_SFX ANM opcode → AudioManager.play_sfx().
- `world.on_state_change` callback → `play_sfx(sounds[state_counter % len(sounds)])`.
- Music tracks (1000–1023): AU6 gap — not implemented.

---

## 8. Implementation Phases

### Phase 1: Project Scaffold + Autoloads (3–4 days)
- Create `godot_level_editor/` with `project.godot` (name="level_editor", main_scene="scenes/Main.tscn").
- Copy `data/` from `re_crd_gdd/tim2_editor/data/`.
- `PartDatabase.gd`: load `part-name-catalog.json` → `part_catalog{}`.
  Methods: `get_part_data(pt)`, `get_part_name(pt)`.
- `AnmDatabase.gd`: load all 433 `anm/*.json` into `anm_cache{}`.
  Methods: `load_anm(name)`, `get_anm_for_part(pt)`.
- `BehaviorRegistry.gd`: load `solve-decoded.json`, `godot/behaviors.json`,
  `part-properties.json`, `state-machine-report.json`.
  Methods: `get_state_limits(pt)`, `get_solve_transitions(pt)`,
  `validate_orphan_states()`, `validate_trigger_chains()`.
- `AudioManager.gd`: 16-player pool, `play_sfx(sound_id)`, load WAV on demand.

**Validation**: Print catalog sizes, ANM count, verify JSON parse for all 433 files.

### Phase 2: Backend Core (3–4 days)
- `PartData.gd`: all fields from Python `Part` dataclass — position, velocity,
  flags, appearance, behavior, connections, rope_segment_length, state machine
  fields (state_counter, sub_counter, state_limit_*), physics props (mass, COR,
  friction, collision shape/radius/w/h), gravity_category, max_gravity, wind_force,
  explosion_timer, programmable ball fields (density, elasticity, friction_extra,
  gravity_buoyancy).
- `WorldState.gd`: `parts[]`, `gravity`, `pressure`, `tick_count`, `viewport`,
  `on_collision` callback, `on_state_change` callback.
- `PhysicsSolver.gd`: all 6 passes as specified in §3.
- `SimulationLoop.gd`: call `PhysicsSolver.step()` at 60Hz via `_physics_process`.
- `LevelSerializer.gd`: YAML load/save (full spec from Python `level.py`).
- `SolutionChecker.gd`: check all conditions against WorldState.

**Validation**: Load all 206 YAML levels without crash.

### Phase 3: ANM Rendering Pipeline (3–4 days)
- `AnmRenderer.gd` (RefCounted): `render_frame(anm_name, state_id, frame_idx, bmp_dir)`,
  `render_wall(anm_name, w, h, bmp_dir)`.
- BMP loading: multi-sub-image BMP files; `resource_id` → filename, `sub_image` → index.
- Palette application: TTLMED default; per-level `bg_color` index → palette lookup.
- Tile rendering: parts larger than one BMP tile tiled across width/height.
- Flip support: `appearance & 0x8000` → horizontal flip.
- Cache: BMP surfaces, ANM JSON, palettes — all cached by name/path.

**Validation**: Render all 149 part types at default state, verify no crashes.

### Phase 4: Editor UI (4–5 days)
- `Main.tscn`: `VBoxContainer` → `Toolbar` (HBox) + `HSplitContainer` (canvas left, catalog right).
- `Toolbar.gd`: buttons for New/Save/Load/Preview; mode indicator; zoom display.
- `CatalogPanel.gd`: scrollable category tree + part list; 32×32 thumbnails.
- `ViewportCanvas.gd`: `Node2D` with pan/zoom; children are `PartNode` instances.
- `PartNode.tscn`: `Area2D` + `Sprite2D` + `CollisionShape2D` (rectangle).
- `EditorController.gd`: full mode machine, keyboard/mouse handlers.
- `SelectionHandles.gd`: 8 resize handles + action labels.
- `ConnectionTool.gd`: preview line during drag; validation before creating.
- `LevelInfoDialog.gd`: modal with 6 fields, Tab/Enter/Esc navigation.
- `SolutionRectTool.gd`: click-drag to define solution rectangles.

**Validation**: All editor hotkeys functional; place/delete/select/move/resize parts.

### Phase 5: Game Play Mode (2–3 days)
- `GameController.gd`: state machine (SELECT_LEVEL → PLAY → SOLVED).
  `_physics_process` drives simulation.
- `GoalBar.gd`: animated text showing level goal.
- `SolveOverlay.gd`: WIN overlay when all conditions met.

**Validation**: Load and play a level through to WIN state.

### Phase 6: Integration & Polish (2–3 days)
- Part handles: resize (8-point drag), flip, lock, delete.
- Connection color feedback: amber during drag, green for valid.
- Part tooltip on hover.
- Undo/redo (command stack) — stretch goal, lower priority.
- Toolbar icons: ICONS1-10 ANM sprites (ED14 from milestone).

**Validation**: editor-validation milestone tests pass.

---

## 9. Effort Estimate

| Phase | Days |
|-------|------|
| 1. Scaffold + Autoloads | 3–4 |
| 2. Backend Core | 3–4 |
| 3. ANM Rendering | 3–4 |
| 4. Editor UI | 4–5 |
| 5. Game Play Mode | 2–3 |
| 6. Integration & Polish | 2–3 |
| **Total** | **17–23 days** |

---

## 10. Source-to-Target File Map

| Python Source | Godot Target |
|---|---|
| `tim2_editor/engine/part.py` | `backend/PartData.gd` |
| `tim2_editor/engine/world.py` | `backend/PhysicsSolver.gd` + `backend/WorldState.gd` |
| `tim2_editor/engine/level.py` | `backend/LevelSerializer.gd` + `backend/SolutionCondition.gd` |
| `tim2_editor/engine/solver.py` | `backend/SolutionChecker.gd` |
| `tim2_editor/engine/behavior.py` | `autoload/BehaviorRegistry.gd` |
| `tim2_editor/engine/behaviors.py` | `backend/` behavior handlers |
| `tim2_editor/sprites/anm_renderer.py` | `autoload/AnmDatabase.gd` + `AnmRenderer.gd` (RefCounted) |
| `tim2_editor/editor/config.py` | editor constants (window/viewport/catalog sizes, colors, grid) |
| `tim2_editor/main.py` | `editor/EditorController.gd` + all editor UI nodes |
| `godot_toy/backend/*.gd` | `backend/` (extend from prototype) |
| `godot_toy/frontend/*.gd` | `editor/` + `game/` (extend from prototype) |

---

## 11. Spec Cross-References

| Document | Key Sections Used |
|---|---|
| `state-machine-specification.md` | §1–8: state concepts, execution engine, state limits, SOLVE.RES mapping, trigger chains |
| `tim2-editor-validation-milestone.md` | ED1-ED18 todos, open gaps, test suite coverage |
| `tim2-backend-milestone.md` | Physics gaps PH1-PH12, state machine SM1-SM5, all fixed, test results |
| `tim2-frontend-milestone.md` | GF1-GF14 game flow gaps |
| `validation-directives.md` | L1-L5 validation pyramid, 4-step spec discovery process |
| `code-reference.md` | GHIDRA address maps, EXE function addresses, data structure layouts |

---

## 12. Deliverables & Dependencies

### DATA FILES

| File | Size | Used By | Purpose |
|------|------|---------|---------|
| `part-name-catalog.json` | 149 entries | `PartDatabase.gd` | Part names, categories, ANM mappings |
| `anm/*.json` | 433 files | `AnmDatabase.gd` | ANM bytecode (Sections A/B/C/D) |
| `sprites/*.bmp` | ~1,273 files | `AnmRenderer.gd` | BMP sub-images for DRAW_BMP opcode |
| `palettes/*.json` | 24 files | `AnmRenderer.gd` | Color palettes (TTLMED default, 15 level palettes) |
| `wav/*.wav` | 113 files | `AudioManager.gd` | Sound effects (SX_ID_HZ.wav) |

### BUILD OUTPUT FILES

| File | Entries | Used By | Purpose |
|------|---------|---------|---------|
| `phase-16/solve-decoded.json` | 147 | `BehaviorRegistry.gd` | SOLVE.RES trigger chains per part |
| `phase-16/godot/behaviors.json` | 147 | `BehaviorRegistry.gd` | State limits (LIMIT_UPPER/RESET/SUB_A/SUB_B) per part |
| `phase-16/part-assets.json` | 147 | `BehaviorRegistry.gd` | Sound IDs + ANM metadata per part |
| `phase-9/part-properties.json` | 149 | `BehaviorRegistry.gd` | Physics props (mass, COR, friction, collision dims) |
| `phase-19/state-machine-report.json` | — | `BehaviorRegistry.gd` | Orphan ANM states (warning at load) |
| `phase-5/yaml/*.yaml` | 206 files | `LevelSerializer.gd` | Test corpus for validation |

### AUTOLOAD MODULES

| Deliverable | Dependencies | Files Created |
|---|---|---|
| `PartDatabase.gd` | `data/part-name-catalog.json` | `autoload/PartDatabase.gd` |
| `AnmDatabase.gd` | `data/anm/*.json` (433 files) | `autoload/AnmDatabase.gd` |
| `BehaviorRegistry.gd` | `build/phase-16/solve-decoded.json`, `behaviors.json`, `part-assets.json`, `phase-9/part-properties.json`, `phase-19/state-machine-report.json` | `autoload/BehaviorRegistry.gd` |
| `AudioManager.gd` | `data/wav/*.wav` (113 files) | `autoload/AudioManager.gd` |

### BACKEND MODULES

| Deliverable | Dependencies | Files Created |
|---|---|---|
| `PartData.gd` | All field definitions from Python `part.py`; `BehaviorRegistry.gd` for state limits | `backend/PartData.gd` |
| `WorldState.gd` | `backend/PartData.gd` | `backend/WorldState.gd` |
| `PhysicsSolver.gd` | `backend/WorldState.gd`, `BehaviorRegistry.gd` (SOLVE.RES, collision matrix), `AnmDatabase.gd` (state→frame lookup for behavior handlers) | `backend/PhysicsSolver.gd` |
| `SimulationLoop.gd` | `backend/PhysicsSolver.gd`, `backend/WorldState.gd` | `backend/SimulationLoop.gd` |
| `SolutionChecker.gd` | `backend/WorldState.gd`, `backend/SolutionCondition.gd` | `backend/SolutionChecker.gd` |
| `LevelSerializer.gd` | `backend/WorldState.gd`, `backend/PartData.gd`, `backend/SolutionCondition.gd` | `backend/LevelSerializer.gd` |
| `SolutionCondition.gd` | None (pure data struct) | `backend/SolutionCondition.gd` |
| Behavior handlers | `backend/PartData.gd`, `PhysicsSolver.gd`, `BehaviorRegistry.gd` | `backend/BehaviorExecutor.gd` + per-type handler files |

### ANM RENDERING PIPELINE

| Deliverable | Dependencies | Files Created |
|---|---|---|
| `AnmRenderer.gd` (RefCounted) | `AnmDatabase.gd` (anm_cache), `data/sprites/*.bmp`, `data/palettes/*.json` | `backend/AnmRenderer.gd` |
| Sprite cache | `AnmRenderer.gd` | internal to `AnmRenderer.gd` |
| Palette cache | `AnmRenderer.gd` | internal to `AnmRenderer.gd` |

### EDITOR UI

| Deliverable | Dependencies | Files Created |
|---|---|---|
| `EditorController.gd` | `backend/LevelSerializer.gd`, `backend/WorldState.gd`, `backend/PartData.gd`, `PartDatabase.gd` | `editor/EditorController.gd` |
| `CatalogPanel.gd` | `PartDatabase.gd`, `AnmDatabase.gd`, `AnmRenderer.gd` | `editor/CatalogPanel.gd` |
| `ViewportCanvas.gd` | `editor/PartNode.gd`, `backend/WorldState.gd`, `PartDatabase.gd` | `editor/ViewportCanvas.gd` |
| `PartNode.tscn` + `PartNode.gd` | `AnmRenderer.gd`, `PartDatabase.gd` | `editor/PartNode.tscn`, `editor/PartNode.gd` |
| `SelectionHandles.gd` | `editor/PartNode.gd` | `editor/SelectionHandles.gd` |
| `ConnectionTool.gd` | `backend/WorldState.gd` | `editor/ConnectionTool.gd` |
| `SolutionRectTool.gd` | `backend/SolutionChecker.gd` | `editor/SolutionRectTool.gd` |
| `LevelInfoDialog.gd` | `backend/LevelSerializer.gd` | `editor/LevelInfoDialog.gd` |
| `ProgrammablePartDialog.gd` | `backend/PartData.gd` | `editor/ProgrammablePartDialog.gd` |
| `Toolbar.gd` | `EditorController.gd` | `editor/Toolbar.gd` |
| `Main.tscn` | all editor modules | `scenes/Main.tscn` |

### GAME PLAY

| Deliverable | Dependencies | Files Created |
|---|---|---|
| `GameController.gd` | `backend/SimulationLoop.gd`, `backend/SolutionChecker.gd`, `game/GoalBar.gd`, `game/SolveOverlay.gd` | `game/GameController.gd` |
| `GoalBar.gd` | `backend/WorldState.gd` | `game/GoalBar.gd` |
| `SolveOverlay.gd` | `backend/SolutionChecker.gd` | `game/SolveOverlay.gd` |

### PROJECT CONFIG

| Deliverable | Dependencies | Files Created |
|---|---|---|
| `project.godot` | Godot 4.6, Forward Plus | `godot_level_editor/project.godot` |

### DEPENDENCY GRAPH (summary)

```
data/ files ──────────────────────────────────┐
                                                  ├─► PartDatabase.gd ──► EditorController.gd
                                                  ├─► AnmDatabase.gd ───┤
                                                  │                     ├─► AnmRenderer.gd ──► CatalogPanel.gd, PartNode.gd
                                                  │                     └─► PartNode.tscn
                                                  ├─► BehaviorRegistry.gd ──┤
                                                  │                         ├─► PhysicsSolver.gd ──► SimulationLoop.gd
                                                  │                         └─► PartData.gd
                                                  └─► AudioManager.gd

LevelSerializer.gd ──► EditorController.gd
SolutionChecker.gd ──┤
SolutionCondition.gd ┘
```