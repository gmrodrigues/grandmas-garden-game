# TIM2 Clean Room — Project File Database

> **Purpose**: A comprehensive, flat-indexed database of every file and directory in this project with its role, content summary, and relevance to the Godot clean-room reimplementation of *The Incredible Machine 2*.
>
> **Clean-Room Principle**: No original game *source code* was referenced. All specifications derive from binary analysis and reproducible experiments documented in `docs/experiments/`.

---

## Table of Contents

1. [Root Project Files](#1-root-project-files)
2. [Original Game Binaries](#2-original-game-binaries)
3. [Python Reference Engine (`tim2_editor/engine/`)](#3-python-reference-engine)
4. [Python Editor & Game (`tim2_editor/`)](#4-python-editor--game)
5. [Build Pipeline Outputs (`build/`)](#5-build-pipeline-outputs)
6. [Reverse Engineering Scripts (`scripts/`)](#6-reverse-engineering-scripts)
7. [Experiments & Results (`docs/experiments/`)](#7-experiments--results)
8. [Core Specifications (`docs/`)](#8-core-specifications)
9. [Per-Part Documentation (`docs/parts/`)](#9-per-part-documentation)
10. [Godot Game Spec (`docs/godot_game_spec/`)](#10-godot-game-spec)
11. [timgres RE Tool (`timgres/`)](#11-timgres-re-tool)
12. [Godot Toy Project (`godot_toy/`)](#12-godot-toy-project)

---

## 1. Root Project Files

| File | Size | Role | Godot Relevance |
|------|------|------|-----------------|
| `MILESTONES.md` | 16 KB | Master progress tracker for all two eras (RE + Clean Room). Lists every deliverable with its file path, phase number, and completion status. Embeds the hash algorithm parameters and the full experiment lab journal index (E-001–E-014). | **High** — Authoritative index of what data exists and where. Start here when onboarding the Godot track. |
| `AGENTS.md` | 10 KB | Session state and recovery hub. Contains the priority queue of open tasks, the ERA 2 track status, build/run commands, and key data source paths. | **Medium** — Session recovery and task tracking for contributors. |
| `reverse-enginnering-tim2.md` | 43 KB | The most complete single-document narrative of all discovered binary formats (written in Brazilian Portuguese). Covers RESOURCE.MAP/001, SCN: RLE format, ANM sections A/B/C/D, the 48-byte LEV part struct, SX audio, and a layered reimplementation architecture. | **High** — Primary RE narrative. The recommended first-read for understanding the full technical scope before reading the modular experiment reports. |
| `reverse_engineering_manual.md` | 19 KB | Step-by-step lab manual for the hash-crack process. Documents the exact weight table `"RichRayl@JTP\0RES"`, MAP header index override `[0,1,4,7]` vs EXE default `[0,1,6,7]`, and verifies 1,467/1,467 entries. | **Medium** — Required for any Godot resource-loading code that resolves assets by filename. |
| `reverse_engineering_technical_doc.md` | 14 KB | Formal C-struct definitions for RESOURCE.MAP (19-byte header + 8-byte entries), RESOURCE.001 (17-byte records), BMP chunk hierarchy (`BMP: > INF:/SCN:/OFF:`), and the full LEV level format. The most machine-readable format reference. | **High** — Ground-truth reference for the Godot data pipeline when loading level assets. |
| `reverse_engineering_techniques_and_tools.md` | 8 KB | Methodology overview: DOSBox/Spice86 dynamic debugging, Ghidra 16-bit MZ static analysis, ScummVM source cross-references, empirical byte distribution analysis. | **Low** — Context for interpreting the experiment results; not needed for implementation. |
| `tim2-reverse-engineering-plan.md` | 20 KB | Original phased plan (Phases 0–21) for the RE project. | **Low** — Historical planning document. |
| `phase-2-hash-recovery-plan.md` | 3 KB | Focused plan for the hash-crack work. | **Low** — Superseded by R-001. |
| `level_prompt.md` | 6 KB | Structured prompt template for analyzing level content. | **Low** — Tooling aid, not spec data. |
| `README.md` | 94 B | Minimal project README. | **Low** — Placeholder. |
| `ENGLISH.DAT` | 35 KB | Original game text strings (English). | **Medium** — Source for all in-game text, puzzle titles, and goal descriptions. |
| `FRENCH.DAT` / `GERMAN.DAT` / `SPANISH.DAT` | 244–272 KB ea. | Localized text strings. | **Low** — Only relevant for future localization. |

---

## 2. Original Game Binaries

These files are the ground-truth source for all RE work. They are **not** used directly in the Godot implementation but are the authoritative origin of all data in `build/`.

| File | Size | Content |
|------|------|---------|
| `TIM2.EXE` | 450 KB | The original DOS 16-bit game executable. Contains the physics loop (0x54EAB), gravity table (0x2794B), AABB collision (0x54459), state machine (0x3AE71), sound dispatch (0x3DB2E), resource hash, and all compiled game logic. The Ghidra-decompiled pseudo-C from this file is the primary source for all physics constants and algorithm specs. |
| `RESOURCE.MAP` | 12 KB | Index file for the Sierra resource archive. 19-byte header + 8-byte records (name_hash, resource_type, volume_id, file_offset). The hash function cracked in E-001/R-001 maps filenames to their records. Contains references to all 1,467 resources. |
| `RESOURCE.001` | 3.7 MB | The main Sierra resource volume containing all game assets: BMP sprites, ANM animations, PAR physics files, SX audio, LEV levels, and more. Resources are retrieved by offset from RESOURCE.MAP. |
| `RESOURCE.CFG` | 196 B | Configuration mapping volumes to filenames. |
| `TIM2/` | dir | Sub-directory containing the 206 `.LEV` level binary files and other in-game resources accessible as individual files for some game editions. |
| `TIM2.SX` | (in RESOURCE.001) | Sierra SND chunked container. 38 audio patches: 14 OPL2 FM sound effects (IDs 5–205) + 24 waveform music tracks (IDs 1000–1023). Fully decoded in E-003/R-003. |
| `INSTALL.EXE` / `INSTALL.HLP` | — | DOS installer. No spec relevance. |
| `SIGNIN.RES` | 16 B | Minimal resource. |
| `TIM.SAV` / `TIM01.SAV` | 348 B ea. | Original save game files. |
| `The-Incredible-Machine-2_Manual_DOS_EN.pdf` | 8.7 MB | Full original game manual in PDF. Primary reference for game rules, puzzle intent, and editor controls documented from the player perspective. |
| `Engenharia Reversa The Incredible Machine 2.pdf` | 382 KB | Project presentation PDF (Portuguese). |

---

## 3. Python Reference Engine

**Location**: `tim2_editor/engine/`
**Purpose**: The deterministic physics simulation — the canonical spec vehicle for Track A. All Godot backend code must produce results identical to this Python engine.

| File | Size | Content | Godot Port Notes |
|------|------|---------|------------------|
| `world.py` | 23 KB | **The physics loop orchestrator.** `PhysicsWorld.step()` executes 7 ordered passes per tick: (0) state counters → (1) gravity → (2) behaviors → (3) viewport clamp → (4) collision detection/response → (5) proximity + electrical propagation → (6) rope/pulley constraint enforcement. Implements a 7-category collision matrix (STATIC, DYNAMIC, EXPLOSIVE, TOOL, ROPE, SCENERY, CREATED). Boundary clamping reflects velocity using Q8.8 COR. Electrical propagation wires outlets to consumers via `outlet_plugged_1/2` indices. | Maps to `SimulationLoop.gd`. The 7-pass order is **critical and must be preserved exactly**. The collision matrix and electrical wiring are the two most complex systems to port. |
| `part.py` | 17 KB | **Physics entity data class.** Holds all state: fixed-point pos/velocity (pixels via `>> 9`), Q8.8 COR and friction, collision shape, three flag words, connection indices, and `state_counter`. `tick()` integrates gravity using a category-based lookup table. `advance_state()` reimplements EXE `FUN_31f7_3bd2` with a deterministic LCG for idle-state random delays. Rope types (7, 10, 76) use the `behavior` field as `rope_segment_length`. | Maps to `PartData.gd`. All numeric values are fixed-point integers; `>> 9` is the pixel conversion factor. The `Part` dataclass maps 1:1 to a Godot `RefCounted` resource. |
| `behaviors.py` | 20 KB | **Per-tick special part handlers.** `BehaviorExecutor` implements 12 active game mechanics: conveyor belt (slides overlapping parts at 60px/s), mouse motor (sets angular_velocity on pulleys/belts), pulley (rotates, constrains rope anchors), belt (averages angular velocity), cannon (spawns projectile Part), explosives (2-sec countdown → radial force + destroy), flashlight (proximity electrical activation), anti-gravity pad (upward vel_y impulse), Newton mouse (moves to nearest cheese), laser (pops balloons), magnifying glass (ignites explosives), pipe system (BFS traversal + teleport). | Maps to `BehaviorRegistry.gd`. Each handler maps to a `_physics_process()` override. The pipe BFS is the most complex — requires a network graph of connected pipe segments. |
| `behavior.py` | 18 KB | **Data-driven rule engine.** Singleton loading behavior rules from three JSON sources: `solve-decoded.json` (SOLVE.RES state transitions), `part-name-catalog.json` (names/categories), `part-properties.json` (PAR physics: mass, COR, friction, radii). Maps 19 game categories to behavior profiles. `get_state_limits_for_part()` uses ANM state count as proxy for `limit_upper`. Validates orphan ANM states (SM4) and broken trigger chains (SM5) at level load. Handles three PAR format variants (`par_80b_40w`, `par_56b_28w`, `par_236b_118w`). | Becomes a Godot `AutoLoad` singleton. The three PAR formats must be handled during data import. |
| `level.py` | 12 KB | **YAML ↔ World loader/saver.** Loads 206 YAML level files into `LevelData` (title, goal, pressure, gravity, music, hints, parts, solution conditions). Splits parts into `fixed` (static) and `moving` (dynamic via `flags_1 & 0x1000`). `SolutionCondition` encodes win conditions as state match or AABB rect overlap, with sentinel rects for off-screen. `save_yaml()` round-trips for editor use. | Each YAML becomes a Godot `Resource`. `SolutionCondition` maps to a goal node. The `fixed`/`moving` distinction maps to static vs. dynamic simulation. |
| `sx_parser.py` | 12 KB | **Audio container decoder.** Parses `TIM2.SX` Sierra SND container: 38 patches (14 OPL2 FM + 24 waveform). Decodes 28-byte SCI28 FM instruments to OPL2 registers. `get_raw_path()` resolves sound IDs to pre-converted WAVs in `build/phase-6/raw-wav/`. | The 113 pre-converted WAVs can be imported directly as `AudioStreamWAV`. FM patches only matter if OPL2 music synthesis is desired (would require a GDNative extension). |
| `solver.py` | 1 KB | **Win condition evaluator.** Wraps a list of `SolutionCondition` objects and evaluates them all each tick. `check()` returns `(all_met: bool, failed: List[str])`. | Maps to a `GameManager` node that calls check after each physics step and emits `level_solved`. The `solution_delay` field must be honored as a timer before the win screen. |

---

## 4. Python Editor & Game

**Location**: `tim2_editor/`

| File | Size | Content | Godot Relevance |
|------|------|---------|-----------------|
| `main.py` | 44 KB | **Level editor UI (Pygame).** The canonical reference implementation of all editor modes (SELECT, PLACE, DELETE, CONNECT, PREVIEW, LEVEL INFO). Manages ANM sprite rendering, zoom/scroll/pan, the catalog panel with icon thumbnails, and live simulation preview with save/restore via YAML snapshots. | **High** — Defines the canonical editor UI layout, coordinate systems (screen↔level transforms), snap grid (16px), viewport dimensions (560×377), and how the physics world integrates with the renderer. The Godot editor must replicate all these interactions. |
| `game.py` | 35 KB | **Full game-mode runner.** Implements Main Menu → Puzzle Select → Play → Solved flow, including Head-to-Head. Loads all 206 YAML levels by category (Tutorial, Easy, Medium, Hard, Really Hard, H2H). Wires physics world with per-part sound callbacks (AU4). Applies mass/COR/friction/collision_radius from PAR data at load time. Persists solved state to `~/.tim2/saves.json`. | **High** — Defines the complete game-mode state machine, screen transitions, level loading lifecycle, and the physics-property-binding logic that Godot's `GameManager` must replicate. |
| `validate_spec.py` | 47 KB | **Authoritative conformance test bed.** ~977-line headless test suite validating gravity (Q8 fixed-point), AABB collision, state machine cycling, ANM Section A/B/C frame indirection, solution conditions, collision matrix symmetry (T3), rope constraints (T1), belt angular velocity sync (T2), electrical propagation (SM3), and simulation determinism. | **Critical** — Any Godot physics/state-machine implementation must produce results consistent with these test expectations. Port the test logic to GUT (Godot Unit Tests). |
| `test_deterministic.py` | 10 KB | **Determinism test suite.** Validates simulation determinism: runs identical simulations multiple times, asserts bit-identical results. Tests integer-vs-float divergence (< 10 discrepancies over 10,000 ticks). Validates save/restore continuity (midpoint snapshot + resume = continuous run). | **Critical** — Proves that fixed-point integer physics is reproducible. The Godot port must pass equivalent tests before being considered spec-compliant. |
| `test_all_part_types.py` | 4 KB | Creates and simulates one instance of every one of the 149 part types and asserts no crash occurs. | **Medium** — Smoke test for the behavior registry. Port to Godot to verify all 149 types are registered. |
| `load_all_levels.py` | 5 KB | Loads all 206 YAML levels and runs 10 ticks on each, asserting no crash or parse error. | **Medium** — Integration test for the level loader. |
| `sandbox.py` | 27 KB | **Interactive part viewer.** Lets you spawn any part by type number and watch it simulate. Useful for manual verification of individual part physics. | **Medium** — Reference for manual Godot scene testing. |
| `test_level.py` | 5 KB | Tests the level loader round-trip (load → save YAML → reload → assert identical). | **Medium** — Validates level serialization fidelity. |
| `test_error_handling.py` | 11 KB | Tests that invalid/malformed level data is handled gracefully without crashes. | **Low** — Edge-case hardening. |
| `editor/config.py` | 1 KB | **Single source of truth for all spatial constants**: window (1280×720), viewport (560×377 at 10,60), catalog panel layout, snap grid (16px), color palette, and data file paths. | **High** — All Godot viewport and layout constants must match these values exactly. The 560×377 playfield and 16px snap grid are verified against the original game. |
| `data/` | dir | Self-contained asset bundle: `sprites/` (3,054 PNGs), `anm/` (433 JSONs), `wav/` (119 WAVs), `palettes/` (56 JSONs), `part-name-catalog.json`. These are **the canonical assets** for the Godot port's `res://data/` directory. | **Critical** — Copy this directory to `res://data/` in the Godot project. Do not re-import through Godot's asset pipeline. |

---

## 5. Build Pipeline Outputs

**Location**: `build/`
These are **generated data files** — the machine-readable RE outputs consumed by the Python engine and the future Godot implementation.

### `build/phase-3/` — Graphics
| Path | Content |
|------|---------|
| `bitmaps/` | **3,054 PNG sprite frames** decoded from SCN: RLE format using the 256-color VGA palette. Named `PART{N}_f{frame}.png`. This is the complete sprite atlas for the game. |
| `palettes/` | 56 JSON files with 256-color VGA palette arrays. `PARTTEMP.json` is the primary palette for part sprites. |

### `build/phase-4/` — Animations
| Path | Content |
|------|---------|
| `anm/` | **433 JSON files** decoded from `.ANM` binary files. Each JSON contains: Section A (frame index sequence), Section B (frame metadata: x, y, w, h, bytecode_offset), Section C (state_id → first_frame_id mappings), Section D (bytecode commands). This is the complete animation database. |

### `build/phase-5/` — Levels
| Path | Content |
|------|---------|
| `yaml/` | **206 YAML level files** — the complete puzzle database parsed from the binary `.LEV` files. Each YAML encodes: title, goal_desc, pressure, gravity, music_track, hints, fixed parts, moving parts, and solution conditions. |

### `build/phase-6/` — Audio
| Path | Content |
|------|---------|
| `raw-wav/` | **119 WAV files** converted from unsigned 8-bit PCM RAW sources at 11025 Hz mono. Named `SX_{id}_11025.wav`. IDs 3001–3754. Ready for direct import into Godot as `AudioStreamWAV`. |
| `sx-report.json` | Full parse of TIM2.SX: 38 patches with IDs, types, names, sizes, and decoded FM registers. |
| `fm-patch-report.json` | Per-patch OPL2 register dump (all 14 FM patches decoded from SCI28). |

### `build/phase-9/` — Part Metadata
| File | Size | Content |
|------|------|---------|
| `part-name-catalog.json` | 151 KB | **Master part type registry.** 149 entries: part_type, name, category, anm_name, states list, description, SOLVE.RES alternate name. The primary lookup table for the Godot data layer. |
| `part-properties.json` | 987 KB | **Physics constants from PART{N}.PAR files.** Per-part mass, COR (Q8.8 fixed-point), friction, collision width/height, AABB offset, bitmap size. Three format variants (80b, 56b, 28b payloads). The authoritative source for all physics values. |
| `state-part-matrix.json` | 40 KB | **89 unique state IDs × 433 ANM files matrix.** Maps which states each part type can be in. |
| `part-anm-catalog.json` | 752 KB | **ANM metadata for all 433 files.** Frame counts, state IDs, state→frame mappings, opcode histograms, per-frame bounding boxes. |
| `part-state-summary.md` | 143 KB | Human-readable per-part state machine reference. |
| `part-name-catalog.md` | 26 KB | Human-readable grouped markdown tables of all 149 parts by category. |
| `flag-distribution-report.json` | 49 KB | Statistical analysis of flags_1/2/3 bit distributions across all 206 levels. |
| `instance-flag-analysis.json` | 128 KB | Per-instance flag analysis for all parts across all levels. |

### `build/phase-12/` — Symbol Database
| File | Content |
|------|---------|
| `symbol-database.json` | 23 functions, 11 data addresses, 3 structs, 12 ADL.DRV symbols with EXE file offsets, Ghidra addresses, and descriptions. |

### `build/phase-16/` — Godot-Ready Data
| File | Size | Content |
|------|------|---------|
| `solve-decoded.json` | 57 KB | SOLVE.RES fully decoded: state transition tables for all 149 parts. Maps `{self_state, other_state}` trigger pairs to actions (advance, reset, spawn). |
| `part-assets.json` | 257 KB | Complete cross-reference: part_type → ANM file name → sprite frames → sound IDs. |
| `godot/behaviors.json` | 232 KB | Godot-targeted behavior registry: per-part behavior profiles (trigger types, response rules, destructible flag, spawn type) with ANM state counts used as `limit_upper` approximations. |
| `godot/categories.json` | 3 KB | 19 game categories with member part type lists. |

---

## 6. Reverse Engineering Scripts

**Location**: `scripts/`

| File/Dir | Content | Godot Relevance |
|----------|---------|-----------------|
| `scripts/lib/common.py` | Shared utilities: resource archive reader, RESOURCE.MAP parser, RESOURCE.001 extractor, hash verification. | **High** — Contains the Python resource loader that the Godot `res://backend/ResourceLoader.gd` must replicate in GDScript. |
| `scripts/lib/flags_dictionary.py` | Canonical Python definitions for all flags_1/flags_2/flags_3 bit meanings with docstrings and EXE evidence. | **High** — Source of truth for all flag semantics used in `PartData.gd`. |
| `scripts/lib/common.sh` | Shell utilities for build pipeline. | **Low** |
| `scripts/phase-9/02-build-part-anm-catalog.py` | Builds `part-anm-catalog.json` from decoded ANM JSONs. | **Medium** — Reference for how ANM metadata was extracted. |
| `scripts/phase-9/03-build-part-name-catalog.py` | Builds `part-name-catalog.json` from INFO.RES + SOLVE.RES + ANM catalog. | **Medium** — Reference for the part registry build process. |
| `scripts/phase-9/04-decode-par-properties.py` | Decodes all PART{N}.PAR files into `part-properties.json`. Handles three format variants. | **High** — Documents exactly how physics constants (mass, COR, friction) are extracted. |

---

## 7. Experiments & Results

**Location**: `docs/experiments/`
Each `E-NNN` is a lab journal (observations + hypotheses). Each `R-NNN` is the final definitive result. Results supersede the lab journals for spec purposes.

### Results (Authoritative Specs)

| File | Size | Discovery | Godot Relevance |
|------|------|-----------|-----------------|
| `R-001-hash-crack.md` | 5 KB | **RESOURCE.MAP hash algorithm** — 4-phase: weighted-sum+XOR → pad to 13 bytes → ROL8 over positions `[0,1,4,7]` → combine with IMUL/CWD. Weight table: `"RichRayl@JTP\0RES"`. Verified 1467/1467. | **High** — Required for any Godot code that looks up assets by filename. |
| `R-002-anm-format.md` | 6 KB | **ANM binary format** — Sierra `ANM:`→`TB` wrapper, four sections (A: frame index sequence, B: 10-byte frame metadata, C: state→frame map, D: 6 opcodes). Section A is an indirection array into Section B, NOT tick durations. DRAW_BMP: bit 0=hflip, bit 1=vflip. DRAW_RECT: bit 15=absolute coords, bits 0-3=draw mode. | **Critical** — The complete rendering spec. The Godot `ANMPlayer.gd` must implement all 6 opcodes and the A→B→D indirection chain. |
| `R-003-sx-audio.md` | 6 KB | **Audio asset catalog** — TIM2.SX: `SND:/INF:/DAT:/TAG:` structure, 38 patches (14 FM + 24 waveform), 113 RAW PCM files (IDs 3001–3754, unsigned 8-bit, 11025 Hz, center=128). | **Critical** — Complete audio asset inventory. `PLAY_SFX` opcode sound_ids index this table directly. |
| `R-015-state-limit-init.md` | 7 KB | **State machine limits** — Three-function call chain loads 6 runtime limit values (`limit_lower/upper/reset`, `sub_limit_a/b`) from a TB-format resource at runtime. Cannot be statically extracted from EXE. Recommended defaults: lower=0, upper=8 (use ANM state count as proxy), reset=0, sub_A=5, sub_B=5. | **High** — The `PartData.gd` state machine must use ANM state count as `limit_upper` until exact values are captured via DOSBox memory dump (Q-027). |
| `R-016-sound-param-table.md` | 8 KB | **Sound dispatch table** — Decodes the packed table at seg 0x554C:0x3A30. Key finding: for 14 FM-patch parts, FM sound ID = part type number exactly (e.g., part 5 → SID 5 "convey", part 91 → SID 91 "LASER1"). | **High** — Direct mapping from part type to FM patch for the `AudioDispatcher.gd`. |

### Lab Journals (Primary Evidence)

| File | Size | Key Findings |
|------|------|-------------|
| `E-001-hash-crack-lab.md` | 4 KB | Hash algorithm discovery process; weight table `"RichRayl@JTP\0RES"`; MAP header index override. |
| `E-002-anm-format-lab.md` | 5 KB | ANM binary format decoding from all 433 files; zero parsing errors across 28,100 commands. |
| `E-003-sx-audio-lab.md` | 5 KB | TIM2.SX container decoding; 38 patches catalogued; 113 RAW files confirmed. |
| `E-005-opl2-register-decode-lab.md` | 16 KB | OPL2 FM patch decoding via SCI28 Sierra format (confirmed via ScummVM). 3-byte init `[0x10, 0xC6, 0x46]` = unused padding. All 14 patches decode cleanly. |
| `E-006-fm-sequence-hypothesis-tests.md` | 10 KB | 10 format hypotheses tested for the variable-length FM sequence data. Raw OPL2 `(register, value)` streaming strongest survivor; definitive confirmation via E-007. |
| `E-007-adl-drv-disassembly.md` | 8 KB | Full disassembly of ADL.DRV (9,295 bytes). 12-function API via FAR CALL + BP index. Confirms 9-voice OPL2 management, SCI28 format, and that FM sequence data is parsed by TIM2.EXE (not ADL.DRV). |
| `E-009-physics-gravity-analysis.md` | 7 KB | **60 Hz VBL-synchronized tick rate**. Gravity integration: `velocity_y += gravity_y; pos_y += velocity_y >> 9`. Gravity table by part category (balls: 7168 base, scenery: 4096 base). `velocity_y` confirmed at physics struct offset 0x1A. |
| `E-010-collision-algorithm.md` | 6 KB | **AABB collision**: 7-pass frame update at 0x54EAB; overlap detection at 0x54459; position corrected by `overlap/2`; velocity impulse applied. Connected parts skip mutual collision. |
| `E-011-rope-belt-constraints.md` | 5 KB | **Single-pass distance constraint solver** (1 iteration/tick). Three frame passes (init at 0x550DC, enforce at 0x5514A, alt at 0x551A4). Rope length from `behavior` field. Belts transmit angular velocity. |
| `E-012-fm-sequence-format-definitive.md` | 6 KB | FM sequence = channel state parameter block. Flat array of 2-byte values copied into 30-byte-per-channel structures (25 channels at seg 0x43C6) that drive ADL.DRV calls. |
| `E-013-state-machine-execution.md` | 15 KB | 9 write sites for state field (4 init, 4 sound-coupled, 1 collision). "Dispatch table at 0x32DA" = FM sound playback system — every state transition triggers FM sound via `CALL FAR 0x4000:5880`. Init value 0x6315 = packed bitfield, not ANM state. |
| `E-014-animation-pipeline.md` | 9 KB | Section A = frame index indirection array (NOT durations). Pipeline: `state_id → Section C → first_frame_id → Section A[first_frame_id + counter % len] → Section B → Section D bytecode`. Screen pos = `part.pos + frame.xy`. |
| `E-015-state-limit-init-table.md` | 7 KB | State limits live in BSS (zero in EXE), loaded from runtime TB-format resource. Cannot be statically extracted. ANM state count is best available proxy for `limit_upper`. |
| `questions.md` | 12 KB | Master Q&A tracking table. 25+ questions (Q-001–Q-027). All marked ✅ except: Q-023 (exact state limit values — needs DOSBox breakpoint), Q-024 (RAW PCM sound ID→part_type lookup partially decoded). |

---

## 8. Core Specifications

**Location**: `docs/`

| File | Size | Content | Godot Relevance |
|------|------|---------|-----------------|
| `code-reference.md` | 16 KB | **Structured index of TIM2.EXE functions by subsystem** with file offsets, Ghidra addresses, and pseudocode. Physics engine (gravity at 0x5361E, AABB at 0x54459, 7-pass loop at 0x54EAB, rope solver at 0x550DC), sound system (ADL.DRV jump table, OPL2 port writes, SCI28 format), level loader, physics struct field offsets (velocity_x/y at 0x1A/0x1E, gravity_y at 0x3A), all flag bit meanings. | **Critical** — Ground-truth cross-reference between binary addresses and reimplementation behavior. Every algorithmic decision in `world.py` traces back to an offset documented here. |
| `state-machine-specification.md` | 8 KB | **Four-layer state system**: `state_counter` (struct offset 0x18), `current_state` (runtime copy), ANM `state_id` (Section C), SOLVE.RES trigger pairs. State execution pseudocode (advance_state() with sub-counter, random idle delay). 146 orphan ANM states across 29 parts. Collision+state integration loop. 11 validation checks passed; 152 SOLVE refs resolve; 201 trigger chains link across 89 unique state IDs. | **Critical** — The authoritative state machine spec. `SimulationLoop._update_state_machines()` must implement this exactly. |
| `validation-directives.md` | 17 KB | **Project epistemology and testing methodology.** 5-layer validation pyramid (L1 sentinel → L2 unit → L3 cross-reference → L4 integration → L5 play-test). 23 numbered scripts. Collision matrix specification (category pair interaction table, surface-clamping formula). The testing contract for spec compliance. | **Critical** — The Godot test suite must satisfy all L1–L4 checks. Port the collision matrix table to `PhysicsMath.gd`. |
| `user-journey-specification.md` | 17 KB | **All 14 user-facing interaction flows** (J01 Sign-In through J14 Head-to-Head) with screen specs (ANM filenames, canvas sizes, state counts), button/hotkey layouts, part struct field mappings for connections, solution condition types, save/load YAML fidelity, and sound IDs per journey. Implementation status for each in the Python editor. | **High** — Defines the complete UI and gameplay flow for the Godot port. Screen transitions, dialog flows, and the 60 Hz simulation loop pass order all come from here. |
| `tim2-backend-milestone.md` | 12 KB | Gap-audit of the Python engine. All P0–P2 items resolved (296 tests passing, 206/206 levels load, all 149 part types simulate). Two large gaps remain: belt-constraint solver integration (PH6) and pulley rope logic (PH11). | **High** — Definitive checklist of what the Godot physics engine must replicate. |
| `tim2-frontend-milestone.md` | 7 KB | Gap-audit of the Python editor UI. ~85% complete. Open items: connection color feedback (ED4), undo/redo (ED12), icon toolbar (ED14), ANM-rendered menus, 116 unknown scenery parts (D1). | **Medium** — Roadmap for which Godot editor UI elements need implementation. |
| `tim2-editor-validation-milestone.md` | 19 KB | Legacy combined audit (now superseded by the two separate milestone docs above). Historical baseline showing pre-fix gap states. | **Low** — Historical reference only. |
| `unknown-parts-visual-catalog.md` | 23 KB | Visual catalog of 116 scenery-only part types (IDs 150–280) with no INFO.RES entry: inferred names, pixel dimensions (W×H), level usage counts, and PNG thumbnails. | **Medium** — These 116 types are pure sprite-rendering tasks (no physics/behavior needed). Their dimensions and sprites are the only data required for Godot implementation. |
| `anm-parse-methodology.md` | 284 B | Brief methodology note for ANM parsing. | **Low** |
| `hash-crack-session-methodology.md` | 271 B | Brief methodology note for the hash-crack session. | **Low** |
| `user-journey-levels.md` | 230 KB | Detailed per-level user journey data for all 206 levels. | **Medium** — Level-by-level content reference. |
| `user-journey-report.md` | 5 KB | Summary report of the user journey analysis. | **Low** |

### `docs/tim2_editor/` — Editor Design Specs

| File | Size | Content |
|------|------|---------|
| `animation-sprite-spec.md` | 2 KB | **ANM rendering pipeline spec** for the editor: Section C→A→B→D chain, state resolution (default to state 1 if `current_state == 0`), zoom scaling, BMP PNG file naming convention, fallback rectangle rendering. |
| `data-assets-spec.md` | 3 KB | **Asset directory layout** for `tim2_editor/data/`: sprites/, anm/, wav/, palettes/ subdirectories; path resolution via `DATA_DIR = ROOT / "tim2_editor" / "data"`; origin of each asset from build pipeline phase. Exactly mirrors what `res://data/` must contain in Godot. |
| `editor-layout-spec.md` | 3 KB | **Editor layout constants**: window 1280×720, viewport 560×377 at (10,60), catalog panel at (580,60) width 200, snap grid 16px, zoom range 0.25–4.0. All 6 editor mode keys (S, P, D, Space, C, I). Grid color, scroll controls. |

---

## 9. Per-Part Documentation

**Location**: `docs/parts/`
**148 files** (one per playable part type, IDs 0–148 + scenery types 150–280).

Each file follows a standardized template containing:
- Part name, category, ID
- Physics properties (mass, COR, friction from PAR file)
- State machine (all states with ANM state IDs and descriptions)
- Behavior description (what it does during simulation)
- Connection types (belt, rope, electrical)
- Solution condition codes (how it appears in SOLVE.RES)
- DRAW_BMP sprite frames

**Selected high-detail entries** (>30 KB — indicating complex behavior):
| File | Notes |
|------|-------|
| `part-015-fish-tank.md` | 58 KB — Complex container with water physics |
| `part-018-cannon.md` | 60 KB — Projectile spawner with trajectory |
| `part-031-mandrill-motor.md` | 48 KB — Belt output motor with rope-pulled shade |
| `part-012-curie-cat.md` | 37 KB — AI behavior (chases Newton Mouse) |
| `part-058-mels-house.md` | 38 KB — Solution trigger container |
| `part-095-laser-mixer.md` | 31 KB — Color mixing with 3 laser inputs |
| `part-080-fireworks.md` | 32 KB — Multi-state explosion sequence |

**Registry file**: `docs/parts/README.md` (7 KB) — Master index of all 148 part docs with categories.

---

## 10. Godot Game Spec

**Location**: `docs/godot_game_spec/`
The **single source of truth** for the Godot 4.6 reimplementation. 9 modular chapters.

| File | Content |
|------|---------|
| `00_master_index.md` | Table of contents and clean-room principles. |
| `01_game_overview.md` | Core loop (Briefing→Construction→Simulation→Resolution), game modes, mechanics overview, editor tools. |
| `02_godot_architecture.md` | Layer isolation (`res://backend/`, `res://data/`, `res://frontend/`), class mapping (Python→GDScript), scene tree blueprint. |
| `03_data_structures.md` | 48-byte part struct (field-by-field), all flag semantics (flags_1/2/3), level binary format header, solution block layout. |
| `04_physics_engine.md` | 7-pass physics tick pipeline, gravity formula (`velocity >> 9`), gravity table by category, AABB collision, single-pass constraint solver (in GDScript). |
| `05_state_machine.md` | State storage, execution engine (GDScript pseudocode), state limits, transition triggers (timer/collision/activation). |
| `06_animation_system.md` | ANM binary format, Section C→A→B→D rendering pipeline, all 6 bytecode opcodes, DRAW_BMP/DRAW_RECT flag decoding. |
| `07_audio_system.md` | SX container architecture, RAW PCM specs (11025Hz unsigned 8-bit), Godot `AudioDispatcher.gd` pool design. |
| `08_part_catalog.md` | Category breakdown (15 categories, 149 types), property file sources, machine-readable data paths. |

---

## 11. timgres RE Tool

**Location**: `timgres/`
The original community reverse-engineering tool (CC0 license, knt47) that bootstrapped the data pipeline.

| File | Size | Content |
|------|------|---------|
| `fformat.txt` | 44 KB | **The ground-truth binary format specification.** ~994 lines covering: TIM/TIM2 `.LEV` puzzle file (magic numbers, all header fields, ALL part entry layouts with variable-size variants — default 48B, belt 52B, rope 54B, pulley 56B, prog ball 60B), the 8-condition solution block with special-case rect values, and the complete `.ANM` format with all 4 sections and 6 bytecode opcodes. Every field in `Part` dataclass traces back to this file. | **Critical** — Primary format reference. The Python `level.py` and the Godot `LevelLoader.gd` must implement this exactly. |
| `readme.txt` | 20 KB | `timgres` package docs: CLI interface, viewer objects for `.ANM/.LEV/.TIM`, PNG/CSV exporters. Documents its limitations (no sound, no physics) — exactly what the Godot port must add. | **Medium** — Historical context for the data pipeline origin. |
| `timgres/decoder/d_puzzle.py` | — | The original Python level decoder (namedtuples, field docs). Reference implementation for the 48-byte part struct parser. | **High** — Cross-reference for validating Godot level loading. |
| `timgres/puzzle/t2pgraph.py` | — | Puzzle graph + part info display. Reference for part interconnection topology. | **Medium** |

---

## 12. Godot Toy Project

**Location**: `godot_toy/`
A proof-of-concept scaffolding that demonstrates the backend-first architecture pattern.

| File | Content |
|------|---------|
| `project.godot` | Godot 4.x project config. Window: 1280×720. Main scene: `res://frontend/GameScene.tscn`. |
| `backend/PartData.gd` | Minimal `RefCounted` data class with all physics fields (type, flags, pos_x/y, vel_x/y, current_state, state_counter). Template for the full port. |
| `backend/WorldState.gd` | `RefCounted` holding `parts: Array[PartData]`, gravity, and tick_count. Template for `WorldState.gd`. |
| `backend/SimulationLoop.gd` | Skeleton 60Hz tick loop demonstrating the pass structure and gravity integration (`velocity_y >> 9`). Shows how integer math works in GDScript without Godot's physics engine. |
| `frontend/GameRenderer.gd` | Demonstrates the canonical pattern: `_physics_process()` → `simulation.tick()` → iterate parts → update `Sprite2D.position`. No physics logic in the Node. |
| `frontend/GameScene.tscn` | Root scene attaching `GameRenderer.gd` to a `Node2D`. |

---

## Summary Index by Relevance

### Critical (Must implement in Godot)
- `docs/godot_game_spec/` — Master implementation spec
- `timgres/fformat.txt` — Binary format ground truth
- `docs/experiments/R-002-anm-format.md` — ANM rendering spec
- `docs/code-reference.md` — EXE function cross-reference
- `docs/state-machine-specification.md` — State machine spec
- `tim2_editor/engine/world.py` — Physics loop (port to GDScript)
- `tim2_editor/engine/part.py` — Part data class (port to GDScript)
- `build/phase-9/part-name-catalog.json` — Part registry
- `build/phase-9/part-properties.json` — Physics constants
- `build/phase-16/solve-decoded.json` — Behavior rules
- `tim2_editor/data/` → `res://data/` in Godot project
- `tim2_editor/validate_spec.py` — Conformance tests (port to GUT)

### High (Strongly informs implementation)
- `docs/experiments/E-009` — Gravity formula and tick rate
- `docs/experiments/E-010` — Collision algorithm
- `docs/experiments/E-011` — Rope/belt constraints
- `docs/experiments/E-013` — State machine + sound coupling
- `docs/experiments/E-014` — Animation pipeline
- `tim2_editor/engine/behaviors.py` — Special part mechanics
- `tim2_editor/engine/behavior.py` — Behavior registry
- `tim2_editor/game.py` — Game flow state machine
- `tim2_editor/main.py` — Editor layout reference
- `tim2_editor/editor/config.py` — Layout constants
- `docs/user-journey-specification.md` — UI flow specs
- `MILESTONES.md` — Data location index
- `reverse-enginnering-tim2.md` — RE narrative
- `docs/tim2-backend-milestone.md` — Physics gap checklist

### Medium (Supporting reference)
- `docs/parts/*.md` — Per-part behavior details (148 files)
- `docs/unknown-parts-visual-catalog.md` — Scenery parts
- `build/phase-9/part-anm-catalog.json` — ANM metadata
- `build/phase-4/anm/*.json` — Raw ANM data (433 files)
- `build/phase-3/bitmaps/*.png` — Sprite frames (3,054 files)
- `tim2_editor/engine/level.py` — Level loading
- `tim2_editor/engine/solver.py` — Win condition checker
- `tim2_editor/engine/sx_parser.py` — Audio loader
- `docs/validation-directives.md` — Testing methodology
- `docs/tim2-frontend-milestone.md` — UI gap checklist
- `timgres/timgres/decoder/d_puzzle.py` — Original decoder

### Low (Historical context)
- `docs/tim2-editor-validation-milestone.md` — Superseded milestone
- `reverse_engineering_manual.md` — Hash crack process
- `scripts/phase-*/` — Build pipeline scripts
- `docs/experiments/E-001` through `E-008` — Lab journals
