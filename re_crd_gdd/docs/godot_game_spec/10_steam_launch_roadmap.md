# Roadmap: From Clean Room Spec to Steam Launch

> **Audience**: The project lead (you) and any collaborator joining Track B.
> **Purpose**: Strategic advice on how to use the `09_project_file_database.md` and the rest of this repository to execute a full, clean-room compliant Godot reimplementation of The Incredible Machine 2 and ship it on Steam.

---

## The Core Thesis

You have already done the hardest part. Most indie developers who attempt a remake fail before they start because they don't know *what the game is* precisely enough to reproduce it. You solved this with ~22 milestones of reverse engineering.

What you now have is:

- A **working deterministic physics engine** in Python (206 levels load, 149 parts simulate, 296 tests pass)
- A **complete binary spec** for every data format the game uses
- **3,054 original sprites**, **433 animation descriptors**, **206 level files**, **119 audio files** — all decoded and ready
- A **standalone Godot spec** (`docs/godot_game_spec/`) as the blueprint

The Godot implementation is now an **engineering execution problem**, not a research problem.

---

## Part 1: How to Use This Database

### 1.1 Use it as a Build Order

The `09_project_file_database.md` Summary Index sorts files by relevance. Use this as your **sequenced build plan**:

```
Phase G1 — Core Backend (Critical files)
  → Port world.py + part.py → SimulationLoop.gd + PartData.gd
  → Port behaviors.py → BehaviorRegistry.gd
  → Copy tim2_editor/data/ → res://data/

Phase G2 — Data Layer (Critical + High files)
  → Load part-name-catalog.json + part-properties.json + solve-decoded.json
  → Port level.py → LevelLoader.gd
  → Port solver.py → SolutionChecker.gd

Phase G3 — Rendering (Critical + High files)
  → Implement ANMPlayer.gd (from R-002 + E-014 spec)
  → Implement GameRenderer.gd (60Hz: tick → update sprites)
  → Implement AudioDispatcher.gd (from R-003 + R-016 spec)

Phase G4 — Game Flow (High files)
  → Port game.py → GameManager.gd (screen state machine)
  → Port main.py → LevelEditor.gd (UI layout from editor/config.py)

Phase G5 — Validation (Critical test files)
  → Port validate_spec.py → GUT tests (conformance)
  → Port test_deterministic.py → GUT tests (determinism)
  → Run load_all_levels.py equivalent (206 levels, 0 crashes)

Phase G6 — Polish (Medium files)
  → Implement all 149 part behaviors (use docs/parts/ per-part docs)
  → Implement all 14 user journeys (use user-journey-specification.md)
  → Implement unknown scenery parts (use unknown-parts-visual-catalog.md)
```

### 1.2 Use it as a Reference Lookup

When you hit a bug or ambiguity during Godot implementation, the database tells you exactly which file has the answer:

| "Why does this part bounce wrong?" | → `build/phase-9/part-properties.json` (COR values) + `E-010` (collision algorithm) |
|---|---|
| "Which animation frame should display?" | → `R-002` (ANM format) + `E-014` (Section A indirection pipeline) |
| "Which state should this part be in?" | → `build/phase-16/solve-decoded.json` + `docs/state-machine-specification.md` |
| "What sound should play on this collision?" | → `R-016` (sound dispatch table) + `build/phase-6/raw-wav/` |
| "How does this specific part behave?" | → `docs/parts/part-NNN-name.md` |

### 1.3 Use the Python engine as the Oracle

**This is the most powerful tool you have.** The Python engine in `tim2_editor/` is spec-compliant and working. Whenever the Godot physics produces a suspicious result:

```bash
# Run the same scenario in Python first
python3 tim2_editor/sandbox.py [part_number]
# Then compare positions tick-by-tick against Godot output
```

The Python engine is your ground truth. If Godot and Python diverge after 100 ticks, **Godot is wrong**. The `test_deterministic.py` test methodology (snapshot at tick N, resume, compare final state) translates directly to a Godot GUT test.

---

## Part 2: Clean Room Legal Strategy for Steam

This is the critical section. Getting this right is what separates a professional release from a lawsuit. 

> [!WARNING]
> **"Abandonware" is a myth.** It is a community term with zero standing in copyright law. Copyright on a corporate work in the US lasts 95 years from publication. TIM2 was published in 1994, meaning its copyright expires in **2089**.

### 2.1 The Copyright Chain

The game is not abandoned. The copyright chain is very much alive:
1. Dynamix (Creator)
2. Sierra On-Line
3. CUC International / Vivendi
4. Vivendi Games / Sierra Entertainment
5. Activision Blizzard (2008)
6. **Microsoft (2023)**

**Microsoft owns the copyright to TIM2's assets right now.** Furthermore, *The Incredible Machine Mega Pack* (which includes TIM2) is currently actively sold on Steam and GOG. If you ship their assets on Steam, you risk an immediate DMCA takedown, the loss of your Steam developer account, and potential legal action.

### 2.2 What "Clean Room" Actually Protects

The clean-room methodology protects your **code** (the physics engine, the GDScript). It proves you didn't steal their source code. It does **not** give you any rights to their **assets** (sprites, audio, levels).

The key documentation you must preserve forever to prove your clean-room process:
- All `docs/experiments/E-NNN` and `R-NNN` files (proves specs came from binary analysis).
- `timgres/fformat.txt` (shows community prior art).
- `validate_spec.py` (shows behavioral equivalence was verified against a spec, not copied code).

### 2.3 The Asset Strategy: Original vs New

You have three practical options for Steam:

#### Option A: Require Player to Own the Original (Recommended for Launch)
**The ScummVM model.** Ship the Godot engine with *zero* original assets. On first launch, prompt the player to point to their TIM2 installation directory (which they can buy on Steam right now). Your Godot engine reads the original `RESOURCE.001`, decodes it on-the-fly, and plays.
- **Pros**: Legally bulletproof. This is exactly how ScummVM, ResidualVM, and OpenMW work. All are on Steam, none have been sued.
- **Cons**: Friction for new players.
- **Implementation**: Port your Python resource extractor to GDScript. Run the decode pipeline at first launch into a `user://` cache.

#### Option B: New Original Art + Sounds (Full Remake)
Commission original pixel art for all 149 parts and new music tracks. The game mechanics and puzzle rules are **not copyrightable** — only their specific expression is. You can legally clone the mechanics (like Open Surge did with Sonic, or Freedoom with Doom), just not the specific art and audio.
- **Pros**: True ownership, no dependency on the original game.
- **Cons**: Significant art/audio budget.

#### Option C: Contact Microsoft
Request a license. Microsoft has given free licenses to community projects before, though the game currently being sold makes this less likely. Still worth a professional email.

> [!TIP]
> **Best advice for Steam launch**: Start with Option A (ScummVM model) to ship fast and safe, then expand with original art (Option B) in a post-launch "Enhanced Edition."

### 2.4 What You Can Legally Ship in the Godot Binary
- All GDScript code you wrote ✅
- New original music and SFX ✅
- The `part-name-catalog.json` and `part-properties.json` — these encode physics facts (mass, COR), not copyrightable expression ✅
- The YAML level files (`build/phase-5/yaml/`) — **Grey Area**. The level *layouts* express the original designer's puzzle intent. Consider reimplementing 20–30 levels as originals for a "demo tier," then require the original game for the full 206.

---

## Part 3: The Godot Implementation Sequence in Detail

### Phase G1: Backend (4–6 weeks)

**Files to read first:**
1. `docs/godot_game_spec/04_physics_engine.md`
2. `tim2_editor/engine/world.py` (your GDScript template)
3. `docs/code-reference.md` (cross-check every physics constant)

**Goal**: `SimulationLoop.gd` running in Godot at 60 Hz with a bowling ball falling deterministically.

**Success criterion**: Run 1,000 ticks in Python (`sandbox.py 0`) and 1,000 ticks in Godot with identical `pos_y` values at every step. If they match, your physics is correct.

**The two hardest sub-tasks:**
- The **7-pass execution order** (world.py): do not skip or reorder passes. The whole game breaks if pass 4 (collision) runs before pass 1 (gravity).
- The **electrical propagation** (world.py line ~180–210): outlets wire to consumers by `outlet_plugged_1/2` index. Toggling state_counter on the consumer activates it. This drives motors, fans, toasters.

### Phase G2: Data Layer (2–3 weeks)

**Files to read first:**
1. `timgres/fformat.txt` (the binary ground truth)
2. `tim2_editor/engine/level.py` (your GDScript template)
3. `build/phase-5/yaml/` (load these, not the binary `.LEV` files)

**Goal**: Load all 206 YAML levels into Godot without crashes.

**Success criterion**: Port `load_all_levels.py` to a GDScript test. 206/206 pass.

**Key insight**: Use the YAMLs in `build/phase-5/yaml/`, not the binary LEV files. The YAMLs are already validated and human-readable. You can always re-derive them from the LEV files if needed, but the YAMLs are your working database.

### Phase G3: Renderer (3–4 weeks)

**Files to read first:**
1. `docs/godot_game_spec/06_animation_system.md`
2. `docs/experiments/R-002-anm-format.md` (the definitive ANM spec)
3. `docs/experiments/E-014-animation-pipeline.md` (the rendering chain)

**Goal**: All 149 parts rendering their correct idle animation (state 1) when placed in a scene.

**The critical insight from E-014**: Section A is **not** a duration table. It is an indirection array into Section B. The formula is:
```
frame_b_idx = Section_A[ first_frame_id + (state_counter % section_a_length) ]
```
Get this wrong and every animation will be wrong.

**Key shortcuts**:
- The 3,054 PNGs are already decoded. Load them as `ImageTexture` via `Image.load_from_file()`. Do NOT let Godot re-compress them — they must stay pixel-exact.
- The `DRAW_RECT` opcode with `bit 15` set means absolute screen coordinates. You need this for lasers and belts.

### Phase G4: Game Flow (3–4 weeks)

**Files to read first:**
1. `docs/user-journey-specification.md` (14 user flows)
2. `tim2_editor/game.py` (your GDScript template for screens)
3. `docs/godot_game_spec/01_game_overview.md`

**Goal**: Main Menu → Puzzle Select → Play → Solved working end-to-end.

**Godot scene structure for this:**
```
MainMenu.tscn  → PuzzleSelect.tscn  → GameScene.tscn
                                        ├─ SimulationLoop (autoload)
                                        ├─ LevelEditor (CanvasLayer)
                                        └─ GameRenderer (Node2D)
```

Use Godot's `SceneManager` pattern with `get_tree().change_scene_to_file()` for transitions.

### Phase G5: Validation (1–2 weeks, ongoing)

**The most important phase for Steam launch.** A puzzle game that has wrong physics is unsolvable and will be review-bombed.

**Port these tests to GUT (Godot Unit Test framework):**
1. `validate_spec.py` — 296 tests covering gravity, collisions, state machine, solution conditions
2. `test_deterministic.py` — Proves bit-identical results across runs
3. A custom "level solver" test: load each of the 206 levels, replay the known solution sequence, assert the solution condition is triggered

**The determinism test is your Steam launch gate.** If a player reports "this puzzle is unsolvable," you need to reproduce it with a tick-by-tick log. Determinism is what makes debugging possible.

### Phase G6: Polish → Steam (6–8 weeks)

**Per-part behavior polish:**
- The `docs/parts/` directory has 148 per-part markdown files. As you implement each part's special behavior (Newton Mouse chasing cheese, cannon trajectory, pipe BFS teleportation), use the relevant part doc as your spec.
- The two most complex parts to implement are the **Cannon** (part 18, 60 KB doc — projectile physics with angle) and the **Fish Tank** (part 15, 58 KB doc — water simulation).

**Steam-specific requirements:**
- Achievements system (Steamworks SDK or `GodotSteam` plugin)
- Cloud saves via Steam Cloud
- Resolution scaling (the game must work at 1080p, 1440p, 4K)
- Controller support (Steam Deck!)
- Build for Windows, Linux, macOS via Godot export presets

---

## Part 4: Milestone Gates Before Steam Submission

Use these as your "go/no-go" gates:

| Gate | Criteria |
|------|----------|
| **G1: Physics Complete** | Bowling ball dropped from 100px height = same trajectory in Python and Godot for 200 ticks |
| **G2: All Levels Load** | 206/206 YAML levels load without crash in Godot |
| **G3: All Parts Render** | All 149 parts display their idle animation correctly |
| **G4: Game Flow Works** | New player can go from launch → menu → select level → play → solve → return to menu |
| **G5: Conformance Tests Pass** | 296/296 `validate_spec.py` equivalent GUT tests pass |
| **G6: Determinism Confirmed** | Same level + same input = identical final state across 10 runs |
| **G7: All 206 Puzzles Solvable** | Known solution replays solve each level without bugs |
| **G8: Steam Submission Ready** | Achievements, cloud saves, controller support, all platform builds tested |

---

## Part 5: The Two Open Spec Gaps to Resolve

From `questions.md`, two questions remain partially open. Address these before Steam:

### Q-023: Exact State Machine Limits
The exact `limit_lower/upper/reset/sub_a/sub_b` values are runtime-loaded from a TB-format resource. The current code uses ANM state count as proxy for `limit_upper`.

**How to fix**: Set a DOSBox breakpoint at EXE 0x3AE71 (`FUN_31f7_3bd2`) and dump the values from the BSS segment after game startup. This gives you exact limits for all 149 parts. One afternoon of work.

### Q-024: RAW PCM Sound ID → Part Type Mapping
The mapping from the 113 RAW sound IDs (3001–3754) to specific part types is only partially decoded.

**How to fix**: Play-test each part, note which sounds trigger, cross-reference with `build/phase-6/raw-wav/` filenames. The `sandbox.py` interactive part viewer is designed exactly for this. Needs playtesting, not RE work.

---

## Part 6: The Fastest Path to a Shippable Build

If you want to ship something fast:

1. **Implement Option A (ScummVM model)** — require the player's TIM2 install directory
2. **Ship 20 original levels** (recreate or use yours) + the full 206 via original game files
3. **Release as Early Access** once Gate G5 (conformance tests) is cleared
4. **Gate G7 (all 206 solvable)** can be a 1.0 requirement

The original TIM2 is already on Steam (Sierra On-Line listing). You can legitimately say in your Steam description: *"Requires a copy of The Incredible Machine 2 — available separately on Steam."* This is exactly the ScummVM model.

---

## Summary Checklist

```
[ ] Phase G1: Port world.py + part.py + behaviors.py to GDScript backend
[ ] Phase G2: Load all 206 YAML levels in Godot
[ ] Phase G3: ANMPlayer.gd rendering all 149 parts correctly
[ ] Phase G4: Full game flow (menu → play → solve)
[ ] Phase G5: 296 conformance tests passing in GUT
[ ] Phase G6: Per-part behavior polish (use docs/parts/ docs)
[ ] Resolve Q-023 (DOSBox breakpoint for state limits)
[ ] Resolve Q-024 (playtest RAW sound → part mapping)
[ ] Legal: Choose Option A (require original) or Option B (new art)
[ ] Steam: Steamworks integration, cloud saves, controller support
[ ] Steam: 3 platform builds tested (Windows/Linux/macOS)
[ ] Steam: Early Access submission
```

---

*The database in `09_project_file_database.md` is your map. This document is your compass. The Python engine is your oracle. Ship it.*
