# `re_crd_gdd` Directory Inventory

This document provides a full inventory and quick summary of each file found in the `/home/glauber/gmrodrigues.github.com/grandmas-garden-game/re_crd_gdd` directory, which appears to be a Clean Room Design environment for reverse-engineering "The Incredible Machine 2" (TIM2).

## Root Directory
- **`Clean_Room_GDD.pdf`**: The primary Clean Room Game Design Document detailing the overall architecture and rules for the reverse-engineering project.

---

## `docs/`
A collection of markdown files containing in-depth reverse engineering notes, engine specifications, and milestone trackers.

- **`anm-parse-methodology.md`**: Redirects to lab notebooks and reports documenting the parsing of the custom ANM animation format.
- **`code-reference.md`**: Comprehensive reference to the original `TIM2.EXE` codebase, cataloging GHIDRA addresses, physics integration, sound dispatch loops, and data structures.
- **`hash-crack-session-methodology.md`**: Notes or methodologies related to cracking hashes or analyzing unknown binary data fields.
- **`state-machine-specification.md`**: A complete specification of the game's state machine, trigger chains, collision state propagation, and `SOLVE.RES` behavior mapping.
- **`tim2-backend-milestone.md`**: Tracks progress, gaps, and test coverage for the Python backend engine (physics, solver, data).
- **`tim2-editor-validation-milestone.md`**: Tracks validation efforts for the level editor tools and interactions.
- **`tim2-frontend-milestone.md`**: Tracks progress and gaps in the Python frontend, covering Pygame UI rendering, game flow, menus, and audio wiring.
- **`unknown-parts-visual-catalog.md`**: A visual reference for documenting undiscovered or undocumented game parts.
- **`user-journey-levels.md`**: Extensive documentation (over 230KB) detailing the intended user flow through game levels.
- **`user-journey-report.md`**: Summary report of the player experience and level progression paths.
- **`user-journey-specification.md`**: Technical specification of how user journey progression is tracked.
- **`validation-directives.md`**: Guidelines and testing plans for ensuring the new engine behaves identically to the original.

---

## `godot_toy/`
A testbed or prototype built using the Godot Engine.

- **`project.godot`**: The Godot Engine (v4.3) configuration file, naming the project "TIM2 Clean Room Toy".
- **`frontend/`**: Directory for Godot frontend scenes and UI.
- **`backend/`**: Directory for Godot backend logic.

---

## `scenery-review/`
Contains image assets for undocumented scenery parts.

- **`name-reference.txt`**: A text file mapping reference names or IDs to the extracted scenery parts.
- **`PART150.png` through `PART280.png`** (132 files): Individual extracted sprites containing the visual data for scenery parts 150 to 280. 

---

## `tim2_editor/`
A complete Python implementation of the TIM2 level editor, game engine, and validation tools.

- **`game.py`**: Handles the main game loop, level selection, Head-to-Head mode, and puzzle solving interactions.
- **`load_all_levels.py`**: A test utility script that loads all 206 original levels and simulates them for 10 ticks to check for crashes.
- **`main.py`**: The primary entry point for the Pygame-based level editor. Implements viewport rendering, toolbars, part selection, and level saving/loading.
- **`sandbox.py`**: An interactive debugging environment to spawn and test specific part interactions.
- **`test_all_part_types.py`**: Unit test that instantiates every single game part (149 total) and simulates them to ensure stability.
- **`test_deterministic.py`**: Test suite ensuring that the physics engine is fully deterministic and bit-identical across runs.
- **`test_error_handling.py`**: Test suite verifying edge cases and error handling across backend modules.
- **`test_level.py`**: Validates the loading of level YAML files and checking win conditions.
- **`validate_spec.py`**: The main validation suite testing core mechanics like gravity, collisions, state machines, trigger chains, and rope/belt constraints against the specification.

---

## `timgres/`
A standalone Python package for viewing and converting level, image, and animation resources from the DOS game files.

- **`README.md`**: Documentation on how to install and use the `timgres` package, noting dependencies like `t1pinfo.py`.
- **`LICENSE`**: Open-source license (Creative Commons Zero) and fair use disclaimers regarding game assets.
- **`fformat.txt`**: Detailed specification of the proprietary file formats extracted from the game.
- **`readme.txt`**: Further detailed documentation on the program's usage and features.
- **`tres_cli.py`**: Command-line interface for extracting and converting resources.
- **`tres_dbg.py`**: Debugging utility for inspecting resource files.
- **`tres_gui.py` / `tres_gui.pyw`**: Tkinter-based graphical interface for viewing extracted animations and sprites.
