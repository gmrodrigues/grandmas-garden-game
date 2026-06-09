# Gap Analysis: GDD vs mvp_rube_goldberg

> Generated from `re_crd_gdd/docs/clean_room_gdd/compiled.html` and `mvp.md` vs current `mvp_rube_goldberg/` codebase.

## Status Legend

| Mark | Meaning |
|---|---|
| ✅ | Implemented & aligned |
| ⚠️✓ | Partially implemented / simplified |
| ❌ | Missing entirely |

---

## 1. Physics Engine (`02_core_mechanics.md`)

| Aspect | GDD Requirement | MVP Reality | Gap |
|---|---|---|---|
| Tick Rate | 60Hz fixed | Runs at Godot framerate (`_process(delta)`) | ❌ |
| Fixed-point math | Zig with `>> 9` conversion | GDScript integers (same shift) | ⚠️✓ same semantics, wrong language |
| 7 passes (strict order) | State → Gravity → Behavior → Clamp → Collide → Proximity → Constraints | Same 7 passes, named P0-P6 | ⚠️✓ order matches, but runs at variable rate |
| GDExtension/Zig core | "Zig via GDExtension" per `mvp.md` | 100% GDScript, no GDExtension | ❌ |
| Gravity table | Acceleration table lookup | Simple additive per frame | ⚠️✓ simplified |
| Global level vars (gravity, pressure) | Per-level gravity/pressure | Not parameterized; hardcoded in `_setup_board` | ❌ |

## 2. Code Architecture (`mvp.md` §3)

| Aspect | GDD / mvp.md Requirement | MVP Reality | Gap |
|---|---|---|---|
| "Compiler" phase (Godot @tool) | Reads Node2D, exports `.bin/.json` | None | ❌ |
| Core engine (Zig GDExtension) | SoA pre-allocated, 32-part limit | None | ❌ |
| "Puppet Master" renderer | Pulls PackedArray, updates sprites | `_sync_sprites()` inline in Main.gd | ⚠️✓ pattern exists but not decoupled |
| Separation of concerns | Physics / UI / Chain separate | 960-line `Main.gd` monolith | ❌ |
| SoA (Struct of Arrays) | Zig SoA for cache efficiency | AoS (`Part extends RefCounted`) | ❌ |

## 3. Part System (`03_part_catalog.md`, `08_detailed_parts_catalog.md`)

| Aspect | GDD Requirement | MVP Reality | Gap |
|---|---|---|---|
| Total playable parts | 149 | ~75 in catalog JSON, 13 in chain | ❌ |
| Scenery parts | 116 | Some but not tracked | ❌ |
| 6 archetypes | Static, Kinetic, Driver, Link, Emitter, Consumer | All 6 defined | ✅ |
| Per-part physics props | mass, damping, cor_q8, radius | All present in Part class | ✅ |
| Category rules | 15 categories, shared logic | `_get_part_category()` maps ~60 types | ⚠️✓ partial |
| SOLVE.RES table | Collision state transitions | Not implemented; hardcoded chain | ❌ |
| State machine (counter, sub_counter, limits) | Per-part state machine | Implemented in `advance_state()` | ✅ |
| Deterministic RNG | LCG with 0x343FD/0x269EC3 | Implemented | ✅ |

## 4. Level Format & Persistence (`05_level_design.md`)

| Aspect | GDD Requirement | MVP Reality | Gap |
|---|---|---|---|
| YAML level files | Serialized with metadata, fixed_parts, moving_parts | None | ❌ |
| Level loader (LevelLoader.gd) | Parses YAML → part instances | None | ❌ |
| Save/Load | Persist player progress + levels | None | ❌ |
| Level editor | Full tool modes (select, place, connect, etc.) | None | ❌ |

## 5. UI/UX (`04_ui_ux_and_controls.md`)

| Aspect | GDD Requirement | MVP Reality | Gap |
|---|---|---|---|
| Parts bin / catalog | Lateral panel with icons, counts | None | ❌ |
| Simulation controls | Play / Stop / Fast Forward | Simulation auto-starts; no controls | ❌ |
| Goal display | View objective + hints | None | ❌ |
| Drag & Drop | Left-click to place parts | None | ❌ |
| Rotate / Delete | Space / Del hotkeys | None | ❌ |
| Undo / Redo | History stack | None | ❌ |
| Magnetic grid | 16px snap with visual feedback | None | ❌ |
| Hint system | Progressive layers from YAML | None | ❌ |
| Gamepad / Touch support | Radial menus, pinch-to-zoom | None | ❌ |
| Zoom / Pan | Free zoom, middle-click pan | None (640x480 fixed) | ❌ |

## 6. Solution Conditions (`05_level_design.md` §5.3)

| Aspect | GDD Requirement | MVP Reality | Gap |
|---|---|---|---|
| state_match | Part state reaches target ID | Not used | ❌ |
| AABB_overlap | Bounding box trigger volume | Not used | ❌ |
| multi_condition | AND/OR of conditions | Not used | ❌ |
| Win check | Generic evaluator | Hardcoded: `balloon.y < 80 && balloon.x > 420` | ❌ |

## 7. Constraint Systems (`02_core_mechanics.md` §2.4)

| Aspect | GDD Requirement | MVP Reality | Gap |
|---|---|---|---|
| Rope distance solver | Single-pass, limit-based correction | 3-iteration constraint | ⚠️✓ more iterations than spec |
| Belt angular sync | Same angular velocity for all connected | `_process_belts()` exists | ⚠️✓ basic |
| Pulley physics | Pendulum/balance effect | Not implemented | ❌ |
| Gear trains | Torque distribution | Not implemented | ❌ |

## 8. Audio (`06_art_and_audio.md` §6.2)

| Aspect | GDD Requirement | MVP Reality | Gap |
|---|---|---|---|
| AudioDispatcher | Reactive side-effect from state changes | `AudioManager.gd` stub (no-op) | ❌ |
| FM / PCM patches | 14 FM + 113 PCM | None | ❌ |
| Sound triggers | Per-part sound on state transition | None | ❌ |
| Music system | Background music | None | ❌ |

## 9. Animation / ANM Rendering (`03_part_catalog.md` §3.2)

| Aspect | GDD Requirement | MVP Reality | Gap |
|---|---|---|---|
| ANM bytecode interpreter | 6 opcodes (A, B, C, D) | 5 opcodes (DRAW_BMP, DRAW_RECT, DRAW_LINE, PLAY_SFX, END_FRAME, END_ANM) | ⚠️✓ |
| Section A/B/C/D parsing | Full 4-section format | Decoded in JSON | ✅ |
| State-driven rendering | `.play("state_" + str(state_counter))` | `_sync_sprites()` maps state to frame | ⚠️✓ works but not via AnimationPlayer |
| Palette (256-color) | PARTTEMP.json | Loaded, used in renderer | ✅ |
| Wall tiling | Stretchable walls | `render_wall()` tiles 16x16 | ✅ |

## 10. User Journeys (`10_user_journeys.md`)

| ID | Journey | MVP Status |
|---|---|---|
| J01 | Sign-In Window | ❌ |
| J02 | Main Menu | ❌ |
| J03 | Puzzle Select | ❌ |
| J04 | Parts Bin — Browse & Place | ❌ |
| J05 | Part Handles — Flip/Stretch/Program/Delete | ❌ |
| J06 | Connections — Rope/Belt/Electrical | ❌ |
| J07 | Programmable Parts | ❌ |
| J08 | Simulation — Start/Observe/Pause/Reset | ❌ |
| J09 | Simulation — Solve Conditions | ❌ |
| J10 | Save & Load | ❌ |
| J11 | Player Preferences | ❌ |
| J12 | Music & Sound | ❌ |
| J13 | Hints & Info Dialogs | ❌ |
| J14 | Head-to-Head | ❌ |

## 11. Editor Tool Modes (`11_godot_editor_specification.md`)

| Mode | GDD Requirement | MVP Status |
|---|---|---|
| Select | Click parts to inspect/modify | ❌ |
| Place | Drop parts from catalog | ❌ |
| Connect | Draw ropes/belts/wires | ❌ |
| Stretch | Resize walls/platforms | ❌ |
| Flip | Mirror parts horizontally | ❌ |
| Delete | Remove parts | ❌ |
| Pan / Zoom | Navigate large levels | ❌ |

## 12. BDD Scenarios (`15_behavioral_specification.md`)

| Scenario Group | Count | MVP Coverage |
|---|---|---|
| Physics Simulation Loop | 14 | 0 (no tests) |
| Constraint Systems | 7 | 0 |
| State Machine Execution | 8 | 0 |
| Solution Conditions | 4 | 0 |
| Editor Tool Modes | 12 | 0 |
| Simulation Controls | 4 | 0 |
| Level Persistence | 5 | 0 |
| **Total** | **54** | **0** |

## 13. Determinism & Validation (`mvp.md` §4)

| Requirement | GDD / mvp.md | MVP Status |
|---|---|---|
| 1,000-run determinism test | Same result every run | Not tested | ❌ |
| Profiling (µs per tick) | GDExtension target | No Zig, not applicable | ❌ |
| Fixed-point arithmetic | Q8.8 integer math | GDScript integers, same shift | ⚠️✓ |

## 14. Modern Features (`07_modern_features.md`)

| Feature | GDD Requirement | MVP Status |
|---|---|---|
| Steam Workshop | Upload/download YAML levels | ❌ |
| Online matchmaking | Head-to-Head competitive | ❌ |
| Sandbox Co-op | P2P collaborative editing | ❌ |
| Hint system | Progressive textual hints | ❌ |

---

## Summary of Key Gaps by Priority

| Priority | Area | Severity |
|---|---|---|
| **P0** | No GDExtension/Zig — core engine is GDScript monolith | **Critical** to `mvp.md` spec |
| **P0** | No level serialization (YAML) — everything hardcoded | **Critical** for expandability |
| **P0** | No UI at all — no parts bin, no simulation controls | **Critical** for playability |
| **P1** | No SOLVE.RES table — chain is hardcoded, not data-driven | Blocks part expansion |
| **P1** | No level editor — can't create/arrange levels | Blocks user-generated content |
| **P1** | No separation of concerns — 960-line monolith | Hinders maintainability |
| **P2** | No audio system (stub) | Missing feedback layer |
| **P2** | No solution condition evaluator | Can't validate arbitrary win conditions |
| **P2** | No test framework — 0 BDD scenarios | No regression safety |
| **P3** | Missing Zig SoA architecture | Performance target not met |
| **P3** | No menu, no user journeys | Not a shippable product |

---

## What's Working Well (Strengths of Current MVP)

1. **ANM bytecode renderer** — faithful implementation of the original game's proprietary animation format with palette support and wall tiling. This is the most mature subsystem.

2. **7-pass simulation loop** — the correct conceptual passes exist and execute in the documented order.

3. **State machine infrastructure** — `state_counter`, `current_state`, `sub_counter`, `state_limit_upper/lower/reset` all present with deterministic LCG-based RNG.

4. **Spatial collision broadphase** — cell-based grid (64px) for efficient AABB overlap detection.

5. **Pulp-level chain works** — the Rube Goldberg sequence reaches its win condition end-to-end.

---

## Recommendations (Next Steps)

| Order | Action | Rationale |
|---|---|---|
| 1 | Refactor `Main.gd` into separate files (`PhysicsEngine.gd`, `PartsRegistry.gd`, `ChainManager.gd`, `Board.gd`) | Monolith blocks all future work |
| 2 | Implement YAML level format + loader | Unlocks data-driven levels |
| 3 | Build minimal UI (play/stop button, parts bin debug panel) | Enables interactivity beyond hardcoded chain |
| 4 | Extract SOLVE.RES from hardcoded chain into data-driven collision table | Enables arbitrary part interactions |
| 5 | Implement 60Hz fixed-tick loop (decouple from framerate) | Required for determinism guarantee |
| 6 | Add 1,000-run determinism test | Validates the core promise |
| 7 | Port physics core to Zig/GDExtension | Performance + separation per `mvp.md` spec |
