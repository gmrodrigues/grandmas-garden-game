# Grandma's Garden — Rube Goldberg Physics Game

A deterministic 2D physics puzzle game built with Godot 4.6.3, featuring a chain-scriptable Rube Goldberg machine engine, per-part state machines, and a data-driven collision resolution system.

## Project Structure

```
mvp_rube_goldberg/
├── Scripts/          — Core game logic
│   ├── Board.gd           — Part container + sprite management
│   ├── Part.gd            — Physics part (data-driven, 60+ fields)
│   ├── PartData.gd       — Editor representation (OOP, 282 fields)
│   ├── PartFactory.gd     — Factory from catalog JSON
│   ├── PhysicsEngine.gd  — 16-pass deterministic physics
│   ├── ChainManager.gd   — Chain script evaluator (8 condition types, 6 actions)
│   ├── SimulationRunner.gd— Wall-clock pacemaker + simulation orchestration
│   ├── PreviewSolver.gd   — Inline editor preview solver
│   ├── EditorController.gd— 6-mode level editor (SELECT/PLACE/DELETE/CONNECT/PREVIEW/LEVEL_INFO)
│   ├── PuzzleEditorController.gd— Inventory-constrained puzzle solver
│   ├── WorldState.gd     — PartData array + undo/redo + connection tracking
│   ├── UndoSystem.gd      — 50-level undo/redo stack
│   ├── BehaviorRegistry.gd— 260-part catalog with physics properties
│   ├── SolveResTable.gd  — 14 data-driven collision rules
│   ├── SolutionCondition.gd— Win condition checker (AABB overlap + state match)
│   └── LevelSerializer.gd — YAML/JSON save/load
├── Scenes/            — UI scenes
│   ├── Main.tscn          — Main game scene (Editor + Simulation modes)
│   ├── PuzzleToolbar.tscn
│   └── MainMenu.tscn
├── autoload/         — Global singletons
│   ├── AnmDatabase.gd    — ANM bytecode cache (278 entries)
│   ├── AnmRenderer.gd    — ANM bytecode interpreter (DRAW_BMP, wall tiling)
│   ├── AudioManager.gd   — FM/PCM sound dispatcher
│   └── OnlineManager.gd  — Session/matchmaking stub
├── data/
│   ├── part-name-catalog.json  — 280 part type definitions
│   ├── solve_res_table.json    — 14 collision rules
│   ├── levels/                — Level JSON files
│   └── anm/                   — ANM bytecode JSON files (13 real + 265 placeholders)
└── test/
    ├── TestFramework.gd    — Lightweight BDD test framework
    ├── TestRunner.gd/.tscn — Headless test runner
    └── tests/
        ├── TestPhysics.gd     — 10 physics simulation tests
        ├── TestStateMachine.gd — 6 state machine tests
        ├── TestChain.gd       — 8 chain script tests
        └── TestEditor.gd      — 12 editor tool tests
```

## Prerequisites

- **Godot 4.6.3** (Linux x86_64 binary at `./godot_v4.6.3`)
  - Download from https://godotengine.org or build from source
  - The binary at `godot_v4.6.3` in the project root is used by build scripts

## Running the Editor

```bash
cd mvp_rube_goldberg
../godot_v4.6.3 --path .
```

**Controls:**
- `1-6` — Switch tool modes (SELECT/PLACE/DELETE/CONNECT/PREVIEW/LEVEL_INFO)
- `P` — Enter Puzzle Editor mode (from Editor mode)
- `ESC` — Cancel operation / return to Editor mode
- `F` — Flip selected part horizontally
- `L` — Lock/unlock selected part
- `Delete` — Delete selected part
- `R` — Switch connection type to Rope
- `B` — Switch connection type to Belt
- `E` — Switch connection type to Electrical
- `Ctrl+S` — Save level
- `Ctrl+Z/Y` — Undo/Redo
- Mouse wheel — Zoom in/out
- Middle mouse — Pan viewport

## Running the Test Suite

```bash
cd mvp_rube_goldberg
../godot_v4.6.3 --headless --path . --scene test/TestRunner.tscn
```

**36 BDD tests across 4 suites:**
- Physics (10): state counter, random delay [40,239], sub_counter, gravity, AABB collision, COR impulse, wall bounce, buoyancy, spatial grid, destroy
- State Machine (6): wrap at LIMIT_UPPER, LIMIT_RESET value, LCG determinism, sub_counter countdown, freeze when not moving, LCG range
- Chain Script (8): tick repeat, once mode, flag condition, set_flag action, win action, prop_ge, and condition, log action
- Editor (12): SELECT/PLACE/DELETE/CONNECT/PREVIEW/LEVEL_INFO tool modes

## Architecture

The game has **three distinct contexts** that share the same simulation engine:

| Context | Purpose | Capabilities |
|---------|---------|--------------|
| **Level Editor** | Create levels | Place, connect, edit state machines, undo/redo |
| **Puzzle Editor** | Solve puzzles | Drag from inventory, position/rotate/flip (no delete/connect) |
| **Simulation** | Run physics | Isolated SubViewport, deterministic 60Hz, play/pause/stop/reset |

**Determinism:** Physics uses Q8.8 fixed-point arithmetic throughout. The 60Hz tick loop runs in a wall-clock pacemaker (`_process()`) that accumulates microseconds (`TICK_INTERVAL_USEC = 16667`). Simulation speed is controlled via `sim_speed_q8` (integer, default 256 = 1x).

**Data flow:** `LevelSerializer` bridges editor ↔ simulation via `editor_data_to_simulation()`. Parts are serialized as flat dictionaries in `PartData.to_dict()` / `from_dict()`. Chain scripts are pure data JSON arrays.

## Key Systems

### Physics Engine (16 passes)
1. Gravity integration
2. State counter advancement + sub_counter countdown
3. Driver power propagation
4. Velocity integration
5. AABB collision detection (spatial grid)
6. Collision resolution (COR impulse)
7. Wall/floor constraints
8. Rope constraint enforcement
9. Belt constraint enforcement
10. Electrical propagation
11. Proximity triggers
12. Flame/effect propagation
13. Destructible destruction
14. State synchronization
15. Board boundary cleanup
16. Part cleanup

### Chain Script Evaluator
Conditions: `tick`, `flag`, `and`, `prop_ge`, `prop_eq`, `prop_gt_ref`, `overlap`, `solution`
Actions: `set_flag`, `inc`, `set`, `delta`, `log`, `win`
Modes: `once` (fire once) or `repeat` (fire every tick)

### State Machine (per-part)
- `state_counter` advances through `state_limit_upper`
- `sub_counter` counts down before each advance (range `[sub_a, sub_b]`)
- `LIMIT_RESET` wraps to 0; `LIMIT_UPPER` clamps and wraps
- Deterministic LCG RNG seeded from `tick_count` — delay range [40, 239]

## Development

The codebase follows a strict OOP-vs-data-driven bifurcation:
- **Editor (OOP):** `PartData`, `EditorController`, `WorldState` — rich objects with signals, callbacks, undo stacks
- **Simulation (data-driven):** `Part`, `PhysicsEngine`, `Board` — flat structs, no signals, computed properties

This ensures the editor and simulation never interact directly — all bridging happens through serialization (`to_dict()` / `from_dict()`) and the `LevelSerializer`.