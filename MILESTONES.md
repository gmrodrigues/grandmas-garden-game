# Milestones

## M1: Core Gameplay Foundation (completed)
- **Phase 1 — Sprites:** Fixed ANM lookup (PartDatabase→AnmDatabase), cached AnmRenderer, removed dead `_load_anm_catalog()`, wired GameController textures
- **Phase 2 — Undo/Redo:** Full world-snapshot undo/redo (50-deep), wired into 9 mutation sites
- **Phase 3 — Solutions:** Connected on_collision/on_state_change callbacks, parsed solution_conditions from YAML, real conditions in preview
- **Phase 4 — Cleanup:** FLAG_MOVING constant, MAX_TICKS consolidation, emoji→text timeout
- **Phase 5 — Verify:** Zero errors, --level injection, run.sh, Vulkan confirmed

## M2: Editor Polish & Physics Quality (completed)
- **Phase 1 — Resize Handles:** 8 handles on selected part now draggable with MIN_PART_SIZE=8
- **Phase 2 — Condition UI:** "Conditions" toolbar button opens editor dialog for add/remove conditions
- **Phase 3 — Snapshots:** Preview saves/restores sub_counter, _countdown, connections, facing, angular_velocity
- **Phase 4 — Cleanup:** FLAG_FLIP constant across 5 files, missing PNG warning in AnmRenderer
- **Phase 5 — Verify:** Zero errors

## M3: Physics Quality & Condition UX (in progress)
- **Phase 1 — Rect Selector:** Wire SolutionRectTool into ConditionEditorDialog for POSITION conditions
- **Phase 2 — collision_w/h on Resize:** Resize handles also update collision_w/collision_h
- **Phase 3 — YAML Load Warnings:** push_warning on unknown part_type, missing flags, out-of-bounds coords
- **Phase 4 — Spatial Grid Broadphase:** Replace O(N²) with cell-based spatial hashing in PhysicsSolver
- **Phase 5 — Verify:** Load 50+ parts smoothly, rect selector works, resize updates collision box, warnings on bad YAML
