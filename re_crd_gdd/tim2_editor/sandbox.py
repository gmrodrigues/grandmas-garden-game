#!/usr/bin/env python3
"""TIM2 Sandbox — interactive part viewer and debug mode.

Test every part in isolation: place on canvas, cycle states,
view frames, drop with physics, play sounds, inspect data.

Usage:
    python3 tim2_editor/sandbox.py
    python3 tim2_editor/sandbox.py 4    # start at part_type 4 (Balloon)
    python3 tim2_editor/sandbox.py 0    # start at part_type 0 (Bowling Ball)
"""

import json
import logging
import os
import sys
from pathlib import Path
from typing import Optional

logger = logging.getLogger(__name__)
os.environ.setdefault("SDL_VIDEODRIVER", "x11")

import pygame

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from tim2_editor.engine.part import Part
from tim2_editor.sprites.anm_renderer import AnmRenderer

WINDOW_W, WINDOW_H = 1280, 780
CANVAS_X, CANVAS_Y = 300, 40
CANVAS_W, CANVAS_H = 640, 500
SNAP = 16
FPS = 60

COLORS = {
    "bg": (25, 27, 33),
    "panel": (35, 37, 43),
    "grid": (50, 60, 80),
    "canvas": (30, 40, 60),
    "text": (220, 220, 220),
    "text_dim": (140, 140, 140),
    "text_highlight": (255, 200, 100),
    "btn": (60, 80, 60),
    "btn_hover": (100, 140, 100),
    "btn_active": (140, 180, 140),
    "category": (50, 70, 50),
    "selected": (40, 50, 70),
    "alert": (220, 80, 80),
    "rope": (150, 100, 50),
    "physics_fill": (100, 170, 255),
}


class SafeFont:
    def __init__(self, fn=None, size=16):
        self.size = size
        self._font = None
        try:
            self._font = pygame.font.Font(fn, size) if fn else pygame.font.SysFont("monospace", size)
        except Exception as e:
            logger.warning("SafeFont init failed: %s", e)

    def render(self, text, aa, color):
        if self._font:
            try:
                return self._font.render(text, aa, color)
            except Exception as e:
                logger.warning("SafeFont render failed for '%s': %s", text[:20], e)
        w = max(len(text) * self.size // 2 + 4, 10)
        h = self.size + 4
        s = pygame.Surface((w, h), pygame.SRCALPHA)
        s.fill((*color, 128))
        return s

    def get_height(self):
        return self.size + 4


class Sandbox:
    def __init__(self, start_part: int = 0):
        pygame.init()
        self.screen = pygame.display.set_mode((WINDOW_W, WINDOW_H))
        pygame.display.set_caption("TIM2 Sandbox — Part Viewer")
        self.clock = pygame.time.Clock()
        self.font = SafeFont(None, 14)
        self.font_small = SafeFont(None, 11)
        self.font_title = SafeFont(None, 18)
        self.font_big = SafeFont(None, 24)

        # Load data
        self._load_data()

        # Renderer
        self.renderer = AnmRenderer(
            ROOT / "build" / "phase-4" / "anm",
            self.catalog_raw,
            wav_dir=ROOT / "build" / "phase-6" / "raw-wav",
        )
        self.bmp_dir = ROOT / "build" / "phase-3" / "bitmaps"

        # Current part
        self.part_type = start_part
        self.placed_part: Optional[Part] = None
        self.current_state_idx = 0
        self.current_frame_idx = 0
        self.part_x = CANVAS_W // 2
        self.part_y = CANVAS_H // 4
        self.physics_running = False
        self.show_grid = True
        self.show_info = True
        self.show_frames = False

        # Catalog
        self.catalog_scroll = 0
        self.catalog_filter = ""
        self.catalog_selected = start_part
        self.categories = sorted(set(
            be.get("category", "?") for be in self.behaviors.values()
        ))
        self.selected_category = self._cat_for_part(start_part)

        # Message
        self.message = ""
        self.message_timer = 0

        # Place initial part
        self._place_part()

    def _cat_for_part(self, pt):
        return self.behaviors.get(str(pt), {}).get("category", self.categories[0])

    def _load_data(self):
        def jload(p):
            with open(p) as f: return json.load(f)

        self.behaviors = jload(ROOT / "build" / "phase-16" / "godot" / "behaviors.json")
        self.props = {e["part_type"]: e for e in
                       jload(ROOT / "build" / "phase-9" / "part-properties.json")}
        self.catalog_raw = jload(ROOT / "build" / "phase-9" / "part-name-catalog.json")
        self.solve = jload(ROOT / "build" / "phase-16" / "solve-decoded.json")
        self.categories_rules = jload(ROOT / "build" / "phase-16" / "godot" / "categories.json")

        # Map part_type → catalog entry
        self.catalog_map = {e["part_type"]: e for e in self.catalog_raw}

    def _place_part(self):
        """Create a Part instance for the selected part_type, with physics."""
        self.placed_part = Part(part_type=self.part_type)
        self.placed_part.x = self.part_x
        self.placed_part.y = self.part_y
        self.placed_part.is_moving = True

        be = self.behaviors.get(str(self.part_type), {})
        self.placed_part.anm_name = be.get("anm_name", f"PART{self.part_type}")

        props = self.props.get(self.part_type, {})
        fields = props.get("fields", [])
        for f in fields:
            name = f.get("name", "")
            if name == "mass":
                self.placed_part.mass = f.get("raw", 2832)
            elif name in ("cor_q8", "property_q8"):
                self.placed_part.cor_q8 = f.get("raw", 128)

        # Default dimensions from ANM if available
        anm_data = self.renderer.load_anm(self.placed_part.anm_name)
        if anm_data:
            section_b = anm_data.get("section_b", [])
            if section_b:
                first = section_b[0]
                if self.placed_part.width_1 <= 16:
                    self.placed_part.width_1 = max(first.get("width", 32), 16)
                    self.placed_part.height_1 = max(first.get("height", 32), 16)

        self.current_state_idx = 0
        self.current_frame_idx = 0
        self.physics_running = False

    def _get_available_states(self):
        """Return list of state_ids available for this part's ANM."""
        be = self.behaviors.get(str(self.part_type), {})
        states = be.get("states", [])
        return [s["state_id"] for s in states]

    def _get_available_frames(self):
        """Return list of sprite details for the current state."""
        be = self.behaviors.get(str(self.part_type), {})
        anm_data = self.renderer.load_anm(self.placed_part.anm_name if self.placed_part else "")
        if not anm_data:
            return []
        section_c = anm_data.get("section_c", [])
        section_b = anm_data.get("section_b", [])
        states = self._get_available_states()
        if not states or self.current_state_idx >= len(states):
            return []

        sid = states[self.current_state_idx]
        first_frame = 0
        for entry in section_c:
            if entry.get("state_id") == sid:
                first_frame = entry.get("first_frame_id", 0)
                break

        # Find range: this state's frames
        next_frame = len(section_b)
        for entry in section_c:
            ff = entry.get("first_frame_id", 0)
            if ff > first_frame:
                next_frame = min(next_frame, ff)
        if first_frame >= next_frame:
            next_frame = first_frame + 1

        frames = []
        for fi in range(first_frame, next_frame):
            meta = section_b[fi] if fi < len(section_b) else None
            frames.append({
                "index": fi,
                "width": meta["width"] if meta else 0,
                "height": meta["height"] if meta else 0,
                "offset": meta["bytecode_offset"] if meta else 0,
            })
        return frames

    def _get_state_for_idx(self, idx):
        states = self._get_available_states()
        if 0 <= idx < len(states):
            return states[idx]
        return 0

    def _get_current_solve_transitions(self):
        """Get SOLVE.RES transitions for current part."""
        sl = self.solve.get(str(self.part_type), {})
        return sl.get("states", [])

    def _get_sounds(self):
        """Get sound IDs for current part."""
        be = self.behaviors.get(str(self.part_type), {})
        return be.get("sounds", [])

    def run(self):
        running = True
        while running:
            dt = self.clock.tick(FPS)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                self._handle_event(event)

            if self.physics_running and self.placed_part:
                self._physics_tick()

            self._draw()
            pygame.display.flip()
        pygame.quit()

    def _handle_event(self, event):
        if event.type == pygame.KEYDOWN:
            self._key(event)
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 1:
                self._click(pygame.mouse.get_pos())
            elif event.button == 4:  # scroll up
                self.catalog_scroll = max(0, self.catalog_scroll - 3)
            elif event.button == 5:  # scroll down
                self.catalog_scroll += 3
    def _key(self, event):
        k = event.key
        if k == pygame.K_ESCAPE:
            pygame.quit(); sys.exit(0)
        elif k == pygame.K_LEFT:
            self.current_state_idx = max(0, self.current_state_idx - 1)
        elif k == pygame.K_RIGHT:
            states = self._get_available_states()
            self.current_state_idx = min(len(states) - 1, self.current_state_idx + 1)
        elif k == pygame.K_f:
            self.show_frames = not self.show_frames
        elif k == pygame.K_g:
            self.show_grid = not self.show_grid
        elif k == pygame.K_i:
            self.show_info = not self.show_info
        elif k == pygame.K_SPACE:
            self.physics_running = not self.physics_running
            if not self.physics_running:
                self._place_part()
        elif k == pygame.K_r:
            self._place_part()
        elif k == pygame.K_PAGEUP:
            next_pt = max(0, self.part_type - 1)
            self.part_type = next_pt
            self.selected_category = self._cat_for_part(self.part_type)
            self._place_part()
        elif k == pygame.K_PAGEDOWN:
            next_pt = self.part_type + 1
            if str(next_pt) in self.behaviors:
                self.part_type = next_pt
                self.selected_category = self._cat_for_part(self.part_type)
                self._place_part()
        elif k == pygame.K_s:
            sounds = self._get_sounds()
            if sounds:
                self._play_sound(sounds[0])
        elif k == pygame.K_TAB:
            # Cycle categories
            cats = list(self.categories)
            idx = cats.index(self.selected_category) if self.selected_category in cats else 0
            self.selected_category = cats[(idx + 1) % len(cats)]
            self.catalog_scroll = 0
        elif k == pygame.K_BACKSPACE:
            self.catalog_filter = self.catalog_filter[:-1]
            self.catalog_scroll = 0
        elif event.unicode and event.unicode.isprintable():
            self.catalog_filter += event.unicode
            self.catalog_scroll = 0

    def _click(self, pos):
        mx, my = pos

        # Canvas area — click to position part
        if CANVAS_X <= mx <= CANVAS_X + CANVAS_W and CANVAS_Y <= my <= CANVAS_Y + CANVAS_H:
            self.part_x = ((mx - CANVAS_X) // SNAP) * SNAP
            self.part_y = ((my - CANVAS_Y) // SNAP) * SNAP
            self._place_part()
            return

        # Catalog area
        cx = 10
        cy = 40
        cats = list(self.categories)
        if self.selected_category not in cats:
            cats.append(self.selected_category)
        for cat in cats:
            if my >= cy and my <= cy + 18:
                self.selected_category = cat
                self.catalog_scroll = 0
                return
            cy += 20

        # Part list
        parts = self._filtered_parts()
        list_y = 40 + len(self.categories) * 20 + 10
        for i, pt in enumerate(parts):
            ly = list_y + (i - self.catalog_scroll) * 16
            if my >= ly and my <= ly + 15:
                self.part_type = pt
                self.catalog_selected = pt
                self._place_part()
                self.message = f"Loaded part {pt}: {self._part_name(pt)}"
                self.message_timer = FPS * 2
                return

    def _physics_tick(self):
        if not self.placed_part:
            return
        # Simple gravity
        g = 0x1C00 // 4  # ~1792 internal units
        self.placed_part.vel_y += g
        self.placed_part.pos_y += self.placed_part.vel_y >> 9
        self.placed_part.y = self.placed_part.pos_y

        # Floor collision
        floor_y = CANVAS_H - 32
        bottom = self.placed_part.y + self.placed_part.height_1
        if bottom >= floor_y:
            self.placed_part.y = floor_y - self.placed_part.height_1
            self.placed_part.pos_y = self.placed_part.y
            self.placed_part.vel_y = -abs(self.placed_part.vel_y) // 2
            if abs(self.placed_part.vel_y) < 50:
                self.placed_part.vel_y = 0

    def _play_sound(self, sound_id: int):
        wav_path = ROOT / "build" / "phase-6" / "raw-wav" / f"SX_{sound_id}_11025.wav"
        if wav_path.exists():
            try:
                pygame.mixer.init()
                snd = pygame.mixer.Sound(str(wav_path))
                snd.play()
                self.message = f"Playing sound {sound_id}"
                self.message_timer = FPS * 2
            except Exception as e:
                self.message = f"Sound error: {e}"
                self.message_timer = FPS * 3
        else:
            self.message = f"Sound file not found: {wav_path.name}"
            self.message_timer = FPS * 3

    def _filtered_parts(self):
        """Return list of part_type values matching current category and filter."""
        pts = []
        for pt_str in sorted(self.behaviors.keys(), key=lambda k: int(k)):
            pt = int(pt_str)
            be = self.behaviors[pt_str]
            if be.get("category", "?") != self.selected_category:
                continue
            if self.catalog_filter:
                name = be.get("name", "").lower()
                if self.catalog_filter.lower() not in name:
                    continue
            pts.append(pt)
        return pts

    def _part_name(self, pt):
        return self.behaviors.get(str(pt), {}).get("name", f"Part {pt}")

    # ── Drawing ──

    def _draw(self):
        self.screen.fill(COLORS["bg"])
        self._draw_catalog()
        self._draw_canvas()
        self._draw_inspector()

        if self.message and self.message_timer > 0:
            txt = self.font_big.render(self.message, True, COLORS["text_highlight"])
            self.screen.blit(txt, (CANVAS_X + 10, CANVAS_Y + CANVAS_H + 10))
            self.message_timer -= 1

    def _draw_catalog(self):
        """Left panel: part selector with categories."""
        W = 285
        pygame.draw.rect(self.screen, COLORS["panel"], (0, 0, W, WINDOW_H))

        title = self.font_title.render("Parts", True, COLORS["text_highlight"])
        self.screen.blit(title, (8, 6))

        # Categories
        cy = 40
        mx, my = pygame.mouse.get_pos()
        cats = list(self.categories)
        if self.selected_category not in cats:
            cats.append(self.selected_category)
        for cat in cats:
            count = sum(1 for be in self.behaviors.values() if be.get("category") == cat)
            active = cat == self.selected_category
            color = COLORS["selected"] if active else COLORS["category"]
            hover = (mx > 8 and mx < W - 5 and my > cy and my < cy + 18)
            if hover:
                color = (70, 100, 70)
            pygame.draw.rect(self.screen, color, (8, cy, W - 16, 18))
            txt = self.font_small.render(f"{cat} ({count})", True, COLORS["text"])
            self.screen.blit(txt, (12, cy + 2))
            cy += 20

        # Filter
        filter_label = self.font_small.render(f"Filter: [{self.catalog_filter}]", True,
                                               COLORS["text_dim"])
        self.screen.blit(filter_label, (8, cy))
        cy += 18

        # Parts
        parts = self._filtered_parts()
        list_y = cy + 5
        end = min(self.catalog_scroll + 35, len(parts))
        for i in range(self.catalog_scroll, end):
            pt = parts[i]
            ly = list_y + (i - self.catalog_scroll) * 16
            selected = pt == self.part_type
            hover = (mx > 8 and mx < W - 5 and my > ly and my < ly + 15)

            if selected:
                pygame.draw.rect(self.screen, COLORS["selected"], (8, ly, W - 16, 15))
            elif hover:
                pygame.draw.rect(self.screen, (50, 55, 65), (8, ly, W - 16, 15))

            has_solve = str(pt) in self.solve and any(
                s.get("name", "") for s in self.solve[str(pt)].get("states", [])
            )
            marker = "*" if has_solve else " "
            txt = self.font_small.render(
                f"{pt:>3} [{marker}] {self._part_name(pt)[:25]}",
                True, COLORS["text_highlight"] if selected else COLORS["text"]
            )
            self.screen.blit(txt, (12, ly))

        # Scroll hint
        if end < len(parts):
            self.screen.blit(self.font_small.render(f"... {len(parts) - end} more below",
                                                     True, COLORS["text_dim"]),
                            (8, list_y + 35 * 16))

    def _draw_canvas(self):
        """Center: simulation canvas with grid and placed part."""
        rect = pygame.Rect(CANVAS_X, CANVAS_Y, CANVAS_W, CANVAS_H)
        pygame.draw.rect(self.screen, COLORS["canvas"], rect)
        pygame.draw.rect(self.screen, COLORS["text_dim"], rect, 1)

        # Grid
        if self.show_grid:
            for x in range(0, CANVAS_W, SNAP):
                pygame.draw.line(self.screen, COLORS["grid"],
                                (CANVAS_X + x, CANVAS_Y),
                                (CANVAS_X + x, CANVAS_Y + CANVAS_H))
            for y in range(0, CANVAS_H, SNAP):
                pygame.draw.line(self.screen, COLORS["grid"],
                                (CANVAS_X, CANVAS_Y + y),
                                (CANVAS_X + CANVAS_W, CANVAS_Y + y))

        # Floor line for physics reference
        floor_y = CANVAS_Y + CANVAS_H - 32
        pygame.draw.line(self.screen, (100, 60, 40),
                        (CANVAS_X, floor_y), (CANVAS_X + CANVAS_W, floor_y), 2)

        # Draw part
        if self.placed_part:
            sx = CANVAS_X + self.placed_part.x
            sy = CANVAS_Y + self.placed_part.y
            sid = self._get_state_for_idx(self.current_state_idx)

            # ANM sprite
            sprite = None
            anm_data = self.renderer.load_anm(self.placed_part.anm_name)
            if anm_data and sid > 0:
                sprite = self.renderer.render_frame(
                    self.placed_part.anm_name, sid, self.bmp_dir,
                    state_counter=self.placed_part.state_counter
                )

            if sprite:
                self.screen.blit(sprite, (sx, sy))
            else:
                w = max(self.placed_part.width_1, 32)
                h = max(self.placed_part.height_1, 32)
                pygame.draw.rect(self.screen, COLORS["physics_fill"], (sx, sy, w, h))
                pygame.draw.rect(self.screen, COLORS["text"], (sx, sy, w, h), 1)

            # State label
            label = self.font_small.render(
                f"#{self.part_type} s{sid} f{self.current_frame_idx}",
                True, COLORS["text"]
            )
            self.screen.blit(label, (sx + 2, sy - 14))

            # Selection outline
            pygame.draw.rect(self.screen, COLORS["text_highlight"],
                            (sx - 1, sy - 1,
                             self.placed_part.width_1 + 2, self.placed_part.height_1 + 2), 2)

        # Frame viewer overlay
        if self.show_frames and self.placed_part:
            self._draw_frame_viewer()

        # Hint text
        hints = [
            "← → cycle states | Space: physics drop | R: reset | F: frames",
            "PgUp/PgDn: prev/next part | Tab: cycle category | G: grid | I: info",
            "S: play sound | Click canvas: reposition | Type: filter catalog",
        ]
        y = CANVAS_Y + CANVAS_H + 32
        for h in hints:
            self.screen.blit(self.font_small.render(h, True, COLORS["text_dim"]),
                            (CANVAS_X + 5, y))
            y += 14

    def _draw_frame_viewer(self):
        """Overlay showing all frames for the current state."""
        frame_list = self._get_available_frames()
        if not frame_list:
            return

        F_W = min(300, len(frame_list) * 80)
        F_H = 120
        fx = CANVAS_X + (CANVAS_W - F_W) // 2
        fy = CANVAS_Y + CANVAS_H - F_H - 10
        pygame.draw.rect(self.screen, (30, 30, 40, 220), (fx, fy, F_W, F_H))
        pygame.draw.rect(self.screen, COLORS["text_dim"], (fx, fy, F_W, F_H), 1)

        sid = self._get_state_for_idx(self.current_state_idx)
        title = self.font_small.render(f"State {sid} — {len(frame_list)} frames",
                                        True, COLORS["text_highlight"])
        self.screen.blit(title, (fx + 5, fy + 3))

        for i, fr in enumerate(frame_list[:8]):
            tx = fx + 10 + i * 75
            ty = fy + 20
            pygame.draw.rect(self.screen, (50, 50, 60), (tx, ty, 70, 50), 1)
            fi_txt = self.font_small.render(f"F{fr['index']}", True, COLORS["text"])
            self.screen.blit(fi_txt, (tx + 2, ty + 2))
            dim_txt = self.font_small.render(f"{fr['width']}x{fr['height']}",
                                              True, COLORS["text_dim"])
            self.screen.blit(dim_txt, (tx + 2, ty + 35))

    def _draw_inspector(self):
        """Right panel: detailed part inspector."""
        if not self.show_info:
            return

        px = CANVAS_X + CANVAS_W + 15
        W = WINDOW_W - px - 10
        pygame.draw.rect(self.screen, COLORS["panel"], (px, 0, W, WINDOW_H))

        be = self.behaviors.get(str(self.part_type), {})
        props = self.props.get(self.part_type, {})
        cat_entry = self.catalog_map.get(self.part_type, {})
        if not self.placed_part:
            return

        y = 10
        name = be.get("name", f"Part {self.part_type}")
        t = self.font_title.render(f"Part {self.part_type}: {name}", True,
                                    COLORS["text_highlight"])
        self.screen.blit(t, (px + 5, y))
        y += 22

        cat = be.get("category", "?")
        t = self.font.render(f"Category: {cat}", True, COLORS["text"])
        self.screen.blit(t, (px + 5, y))
        y += 18

        # SOLVE states
        solve_entry = self.solve.get(str(self.part_type), {})
        sol_states = solve_entry.get("states", [])
        have_interactive = any(s.get("name", "") for s in sol_states)

        t = self.font.render(
            f"Interactive: {'Yes' if have_interactive else 'No'}   "
            f"ANM: {be.get('anm_name', '?')}   "
            f"Frames: {be.get('num_frames', 0)}   "
            f"States: {be.get('num_states', 0)}",
            True, COLORS["text"]
        )
        self.screen.blit(t, (px + 5, y))
        y += 22

        # Current state info
        states = self._get_available_states()
        sid = self._get_state_for_idx(self.current_state_idx)
        t = self.font.render(
            f"State: [{self.current_state_idx + 1}/{len(states)}]  ID={sid}  "
            f"Pos: ({self.placed_part.x}, {self.placed_part.y})  "
            f"Vel: ({self.placed_part.vel_x:.0f}, {self.placed_part.vel_y:.0f})",
            True, COLORS["text_highlight"]
        )
        self.screen.blit(t, (px + 5, y))
        y += 24

        # SOLVE.RES transitions
        if have_interactive:
            y += 6
            t = self.font.render("─ SOLVE.RES States ─", True, COLORS["text_dim"])
            self.screen.blit(t, (px + 5, y))
            y += 18
            for s in sol_states:
                name = s.get("name", "(unnamed)")
                explosive = "💥" if s.get("explosive") else ""
                anm_s = s.get("anm_state", "impl")
                triggers = ", ".join(
                    f"{tr['self']}→{tr['other']}" for tr in s.get("triggers", [])
                )
                t = self.font_small.render(
                    f"  {name} {explosive}  ANM={anm_s}  [{triggers}]",
                    True, COLORS["text"]
                )
                self.screen.blit(t, (px + 5, y))
                y += 14

        # Physics properties
        y += 6
        t = self.font.render("─ Physics ─", True, COLORS["text_dim"])
        self.screen.blit(t, (px + 5, y))
        y += 18
        fields = props.get("fields", [])
        shown = 0
        for f in fields:
            name = f.get("name", "")
            if name.startswith("pad_") or name.startswith("field_"):
                continue
            if shown >= 12:
                break
            raw = f.get("raw", 0)
            interp = f.get("interpretation", "") or ""
            t = self.font_small.render(f"  {name}: {raw}  {interp[:30]}",
                                        True, COLORS["text"])
            self.screen.blit(t, (px + 5, y))
            y += 13
            shown += 1

        # Sounds
        sounds = be.get("sounds", [])
        if sounds:
            y += 4
            t = self.font.render(f"─ Sounds ({len(sounds)}) ─", True, COLORS["text_dim"])
            self.screen.blit(t, (px + 5, y))
            y += 18
            for sid in sounds[:6]:
                wav_path = ROOT / "build" / "phase-6" / "raw-wav" / f"SX_{sid}_11025.wav"
                exists = wav_path.exists()
                t = self.font_small.render(
                    f"  {'✅' if exists else '❌'} {sid}",
                    True, COLORS["text"] if exists else COLORS["alert"]
                )
                self.screen.blit(t, (px + 5, y))
                y += 13

        # Sprites
        sprites = be.get("sprites", [])
        if sprites:
            y += 4
            t = self.font.render(f"─ Sprites ({len(sprites)}) ─", True, COLORS["text_dim"])
            self.screen.blit(t, (px + 5, y))
            y += 18
            anm_name = be.get("anm_name", "")
            for s in sprites[:8]:
                parts = s.split("_")
                png_name = ""
                if len(parts) == 2 and anm_name:
                    sid_num = int(parts[1])
                    png_name = f"{anm_name}_f{sid_num:03d}.png"
                png_path = self.bmp_dir / png_name if png_name else None
                exists = png_path and png_path.exists()
                t = self.font_small.render(
                    f"  {'✅' if exists else '❌'} {s} → {png_name}",
                    True, COLORS["text"] if exists else COLORS["alert"]
                )
                self.screen.blit(t, (px + 5, y))
                y += 13


def main():
    start = int(sys.argv[1]) if len(sys.argv) > 1 else 0
    app = Sandbox(start)
    app.run()


if __name__ == "__main__":
    main()
