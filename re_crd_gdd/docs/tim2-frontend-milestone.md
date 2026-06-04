# TIM2 Frontend — UI + Rendering Milestone

**Covers**: `main.py` (editor), `game.py` (game mode), `sandbox.py` (viewer), `sprites/anm_renderer.py` (rendering), `editor/config.py` (constants)
**Date**: 2026-05-27
**Purpose**: Catalogue every gap in the TIM2 Python frontend — editor UI, game screens, ANM rendering, audio wiring, and user-facing interactions.

---

## 1. Overall Completeness

| Module | LOC | Status | Notes |
|--------|-----|--------|-------|
| `main.py` | 646 | ✅ Complete | Editor: zoom, handles, connections, hotkeys, file dialogs |
| `game.py` | 849 | ✅ Complete | Game flow: menu, select, play, solve, H2H, Workshop |
| `sandbox.py` | 723 | ✅ Complete | Interactive part viewer/debugger |
| `sprites/anm_renderer.py` | 344 | ✅ Complete | ANM pipeline with WAV playback |
| `editor/config.py` | 52 | ✅ Complete | Constants |
| **Total** | **2,614** | **~85%** | Remaining: ANM-rendered menus, editor dialogs, undo/redo |

---

## 2. Editor Mode Gaps

### Open

| ID | Gap | Spec Reference | Current State |
|----|-----|---------------|---------------|
| ED4 | **No connection color feedback** | J06 — red/green for valid/invalid | All connections drawn in single color. |
| ED7 | **No programmable part dialogs** | J07 — 14 dialog types | Programmable ball, laser mixer, etc. cannot be configured. |
| ED8 | **No info dialogs** (INFO0-INFO148) | J13 — 149 info screens | 119 INFO ANM files exist but never displayed. |
| ED9 | **No hints system** | J13 — hand icon → hint points | No hint UI. |
| ED10 | **No preferences panel** | J11 — volume, categories, etc. | No preferences UI. |
| ED12 | **No undo/redo** | Editor convention | No Ctrl+Z/Ctrl+Y. |
| ED14 | **Toolbar uses text buttons** | G18 — toolbar icon→function map resolved | Draws pygame text, not ICONS1-10 ANM sprites (280+ frames exist). |
| ED17 | **No solution condition editing UI** | `main.py:248-258` | Solution rects drawn but no click-to-edit. |

### Done

| ID | Feature | Implementation |
|----|---------|----------------|
| ED1 | Part handles (flip, stretch, program, lock, delete) | ✅ F=flip, drag handles=resize, L=lock, Delete=remove |
| ED2 | Horizontal/vertical flip controls | ✅ `flip_selected()` — toggles `appearance ^= 0x8000` |
| ED3 | Interactive connection tool | ✅ `MODE_CONNECT` — click source, drag to target |
| ED6 | Part name tooltip on hover | ✅ `_draw_tooltip()` — shows name from catalog near cursor |
| ED5 | Keyboard hotkeys | ✅ S/P/D/C/Z/F/L/+/-/Delete/Ctrl+S/Ctrl+L |
| ED11 | Zoom (in/out/reset) | ✅ Scroll zoom (1.25×), Z=reset, pan with alt+drag |
| ED13 | File dialog for save/load | ✅ `tkinter.filedialog` (asksaveasfilename / askopenfilename) |
| ED15 | Part stretching/resizing | ✅ Handle drag with snap, min 16px |
| ED16 | Lock/unlock UI | ✅ `toggle_lock_selected()` — toggles `is_moving` flag |
| ED18 | Level info editing dialog | ✅ Press `I` — pygame inline dialog, 6 editable fields, Tab/Enter/Esc navigation |

---

## 3. Game Flow / Screen Gaps

### Open

| ID | Gap | ANM Asset | Current State |
|----|-----|-----------|---------------|
| GF1 | **No Sierra splash screen** | (none — static image) | Game skips directly to menu. |
| GF2 | **No ANM title screen** | TITLE.ANM, TITLE2.ANM | Text-only "THE INCREDIBLE MACHINE 2". |
| GF3 | **Main menu is text-only** | MAINMENU.ANM (11 states, 116 frames) | Text buttons (hover tint, no ANM sprites). H2H/Workshop wired. |
| GF4 | **Puzzle select is text list** | PUZDISP.ANM, PUZTYPE1-8.ANM | Text rows with solved stars. No BMP grid, no bulb icons. |
| GF5 | **No goal bar animation** | GOALBAR.ANM | Goal text drawn with pygame font. |
| GF6 | **Solve overlay is text-only** | SOLVE.ANM (639×399) | Pygame semi-transparent overlay + text. H2H variant exists. |
| GF7 | **No sign-in window** | SIGN_IN.ANM | Not rendered. |
| GF8 | **No load/save dialog** | LOADSAVE.ANM | Ctrl+S/L work with tkinter, no ANM dialog. |
| GF9 | **No hint lock overlay** | HINTLOCK.ANM | Not rendered. |
| GF10 | **No professor help dialog** | PROFESOR.ANM, PROFESR2.ANM | Not rendered. |
| GF11 | **No credits screen** | CREDITS.ANM | CREDITS ANM exists (5 states, 21 frames) — not rendered. |
| GF12 | **No control panel animation** | CNTRLPNL.ANM | Green flag/broom/hand icons not rendered. |
| GF14 | **No tutorial mode** | TLEV* levels exist (40) | No guided tour system. |

### Done

| ID | Feature | Implementation |
|----|---------|----------------|
| GF13 | Head-to-head screen | ✅ `draw_h2h()` — 50 HH levels, turn indicator ("HEAD-TO-HEAD" badge), winner overlay ("PLAYER 1 WINS!") |

---

## 4. Audio Wiring (Frontend)

| ID | Feature | Status | Implementation |
|----|---------|--------|----------------|
| AU3 | RAW WAV playback in main.py and game.py | ✅ Done | Both pass `wav_dir=build/phase-6/raw-wav` to `AnmRenderer`. `play_sfx()` uses `pygame.mixer.Sound`. |

---

## 5. Data Coverage — Frontend

| ID | Gap | Details | Status |
|----|-----|---------|--------|
| D1 | **116 unknown scenery part types (150-280) completely invisible** | 117 PNGs exist in `build/phase-21/unknown-parts-catalog/`. Not in `part-name-catalog.json`. No ANM files. | ❌ Open |
| D8 | **H2H/Workshop buttons** | `game.py:285-288` — both map to real handlers. | ✅ Done |

---

## 6. Code Quality — Frontend

| ID | Issue | File | Severity |
|----|-------|------|----------|
| Q10 | **`_resolve_resource_name` scans directory each call** | `anm_renderer.py:191-218` | LOW — Scans BMP directory before cache is populated. |
| Q11 | **Font loading: `SYS12.FNT` path defined but never used** | `editor/config.py:43` | LOW — `FONT_PATH` exists but `main.py` uses `pygame.font.Font(None, size)`. |
| Q12 | **`state_matrix` loaded but never referenced** | `main.py:90-103` | LOW — Loads JSON, never uses `self.state_matrix` after init. |

---

## 7. Priority Roadmap — Frontend

### ✅ Done

| Order | Task | Effort |
|-------|------|--------|
| 1 | **Q12**: Remove `STATE_MATRIX_PATH` dead constant from config.py | 2 min |
| 2 | **ED6**: Add part name tooltip on hover in editor | 30 min |
| 3 | **Q11**: Remove `FONT_PATH` dead constant from config.py | 2 min |
| 4 | **ED18**: Level info editing dialog (title, goal, bg_color, etc.) | 1.5 hr |

### Easy (30-60 min)

| Order | Task | Effort |
|-------|------|--------|
| 4 | **ED4**: Connection color feedback (red=valid, green=invalid) | 30 min |
| 5 | **ED12**: Undo/redo with command stack | 1 hr |
| 6 | **ED14**: Replace toolbar text with ICONS1-10 ANM sprites | 1 hr |
| 7 | **Q10**: Cache BMP directory scan results | 30 min |

### Moderate (1-3 hr)

| Order | Task | Effort |
|-------|------|--------|
| 8 | **ED17**: Solution condition editing UI (click rect → edit type) | 2 hr |
| 9 | **ED7**: Programmable part dialogs (laser mixer, etc.) | 3 hr |

### Large (P4)

| Order | Task | Effort |
|-------|------|--------|
| 11 | ANM-rendered game menus (title, main menu, puzzle select, solve overlay) | 2-3 weeks |
| 12 | Scenery part types (150-280) integration into editor | 1 week |
| 13 | Full IMGUI-based editor with handle system (SDL2, Dear ImGui) | 3-4 weeks |
