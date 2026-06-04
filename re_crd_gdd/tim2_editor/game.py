#!/usr/bin/env python3
"""TIM2 Game Mode — full game with Main Menu → Puzzle Select → Play → Solve.

Usage:
    python3 tim2_editor/game.py
    python3 tim2_editor/game.py ELEV1  # start at specific level
"""

import json
import logging
import math
import subprocess
import sys
import os
from pathlib import Path

logger = logging.getLogger(__name__)
os.environ.setdefault("SDL_VIDEODRIVER", "x11")

import pygame

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from tim2_editor.engine.part import Part
from tim2_editor.engine.world import PhysicsWorld
from tim2_editor.engine.level import LevelData, load_yaml, SolutionCondition
from tim2_editor.engine.solver import SolutionChecker
from tim2_editor.engine.behavior import PartBehaviorRegistry
from tim2_editor.sprites.anm_renderer import AnmRenderer

# ── Constants ──
WINDOW_W, WINDOW_H = 1280, 720
VIEWPORT_X, VIEWPORT_Y = 10, 60
VIEWPORT_W, VIEWPORT_H = 560, 377
FPS = 60
SNAP = 16

# Save data location
SAVE_DIR = Path.home() / ".tim2"
SAVE_FILE = SAVE_DIR / "saves.json"

# Editor subprocess command (for Workshop button)
EDITOR_PATH = ROOT / "tim2_editor" / "main.py"
EDITOR_CMD = [sys.executable, str(EDITOR_PATH)]


def load_solved_states() -> dict:
    """Load solved state dict from save file. Returns {level_name: True}."""
    if not SAVE_FILE.exists():
        return {}
    try:
        return json.loads(SAVE_FILE.read_text())
    except (json.JSONDecodeError, IOError) as e:
        logger.warning("Failed to load save file: %s", e)
        return {}


def save_solved_state(level_name: str):
    """Mark a level as solved in the save file."""
    SAVE_DIR.mkdir(parents=True, exist_ok=True)
    states = load_solved_states()
    states[level_name] = True
    try:
        SAVE_FILE.write_text(json.dumps(states, indent=2))
    except IOError as e:
        logger.warning("Failed to save solved state: %s", e)

COLORS = {
    "bg": (20, 22, 28),
    "menu_bg": (30, 30, 60),
    "btn": (60, 120, 60),
    "btn_hover": (100, 180, 100),
    "text": (220, 220, 220),
    "text_dim": (140, 140, 140),
    "text_bright": (255, 200, 100),
    "grid": (40, 70, 120),
    "canvas_bg": (30, 90, 150),
    "selected": (255, 200, 0),
    "success": (80, 200, 80),
    "failure": (220, 60, 60),
    "rope": (150, 100, 50),
    "panel": (40, 42, 48),
    "category_tab": (50, 100, 50),
    "category_tab_active": (100, 180, 100),
    "solved": (200, 200, 0),
    "hint": (255, 255, 0),
    "h2h_p1": (100, 150, 255),
    "h2h_p2": (255, 100, 100),
    "h2h_bg": (30, 30, 60),
}

# ── Puzzle categories ──
CATEGORIES = [
    ("Tutorial", "TLEV", "Tutorial puzzles"),
    ("Easy", "ELEV", "Easy puzzles (1-26)"),
    ("Medium", "MLEV", "Medium puzzles (1-30)"),
    ("Hard", "HLEV", "Hard puzzles (1-31)"),
    ("Really Hard", "RLEV", "Really hard puzzles (1-29)"),
    ("Head-to-Head", "HH", "Two-player puzzles (1-50)"),
]


class SafeFont:
    """Font wrapper with fallback for environments without pygame.font."""
    def __init__(self, size: int = 16):
        self.size = size
        self._font = None
        try:
            self._font = pygame.font.Font(None, size)
        except Exception as e:
            logger.warning("Font init (pygame.font) failed: %s", e)
            try:
                import pygame.freetype
                self._font = pygame.freetype.SysFont("monospace", size)
            except Exception as e2:
                logger.warning("Font init (pygame.freetype) also failed: %s", e2)

    def render(self, text: str, antialias: bool, color) -> pygame.Surface:
        if self._font is None:
            # Minimal fallback: draw colored rect with text size hint
            w = len(text) * self.size // 2 + 4
            h = self.size + 4
            surf = pygame.Surface((w, h), pygame.SRCALPHA)
            surf.fill(color)
            return surf
        try:
            return self._font.render(text, antialias, color)
        except Exception:
            w = len(text) * self.size // 2 + 4
            h = self.size + 4
            surf = pygame.Surface((w, h), pygame.SRCALPHA)
            surf.fill(color)
            return surf

    def get_height(self) -> int:
        if hasattr(self._font, 'get_height'):
            return self._font.get_height()
        return self.size + 4


class Game:
    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode((WINDOW_W, WINDOW_H))
        pygame.display.set_caption("The Incredible Machine 2")
        self.clock = pygame.time.Clock()
        self.font = SafeFont(16)
        self.font_big = SafeFont(24)
        self.font_title = SafeFont(32)

        # Data
        self.registry = PartBehaviorRegistry()
        self.renderer = AnmRenderer(
            ROOT / "build" / "phase-4" / "anm",
            self.registry.name_catalog,
            wav_dir=ROOT / "build" / "phase-6" / "raw-wav",
        )

        # Load catalog for puzzle select
        cat_path = ROOT / "build" / "phase-9" / "part-name-catalog.json"
        if cat_path.exists():
            self.catalog = json.loads(cat_path.read_text())
        else:
            self.catalog = []

        # YAML levels directory
        self.yaml_dir = ROOT / "build" / "phase-5" / "yaml"

        # Game state
        self.screen_mode = "menu"  # menu, select, play, solved
        self.current_level_file: Path | None = None
        self.level: LevelData | None = None
        self.world: PhysicsWorld | None = None
        self.checker: SolutionChecker | None = None

        self.tick_count = 0
        self.running = False
        self.solved = False
        self.solve_timer = 0
        self.message = ""
        self.message_timer = 0
        self.h2h_mode = False

        # Rendering preferences
        self.prefs = {"show_scenery": True}

        # Puzzle select
        self.selected_category = "Easy"
        self.level_list = []
        self.select_scroll = 0
        self.select_hover = -1
        self.select_index = 0  # keyboard cursor position

        self.load_level_list()

    def load_level_list(self):
        """Build list of available YAML level files."""
        self.level_list = []
        solved_states = load_solved_states()
        if not self.yaml_dir.is_dir():
            return
        for cat_name, prefix, _ in CATEGORIES:
            files = sorted(
                [f for f in self.yaml_dir.glob(f"{prefix}*.yaml")],
                key=lambda f: (len(f.stem), f.stem)
            )
            for f in files:
                self.level_list.append({
                    "file": f,
                    "category": cat_name,
                    "name": f.stem,
                    "solved": solved_states.get(f.stem, False),
                })

    def run(self):
        """Main game loop."""
        clock = pygame.time.Clock()
        running = True
        while running:
            dt = clock.tick(FPS)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                self.handle_event(event)

            if self.running and not self.solved:
                self.update_simulation()

            self.draw()
            pygame.display.flip()

        pygame.quit()
        sys.exit(0)

    # ── Event handling ──
    def handle_event(self, event):
        mx, my = pygame.mouse.get_pos()

        if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
            if self.screen_mode == "menu":
                self._menu_click(mx, my)
            elif self.screen_mode == "select":
                self._select_click(mx, my)
            elif self.screen_mode == "h2h":
                self._h2h_click(mx, my)
            elif self.screen_mode == "play":
                self._play_click(mx, my)
            elif self.screen_mode == "solved":
                self._solved_click(mx, my)

        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                if self.screen_mode in ("play", "solved"):
                    self.stop_simulation()
                    if self.h2h_mode:
                        self.screen_mode = "h2h"
                    else:
                        self.screen_mode = "select"
                elif self.screen_mode == "select":
                    self.screen_mode = "menu"
                elif self.screen_mode == "h2h":
                    self.h2h_mode = False
                    self.screen_mode = "menu"
            elif event.key == pygame.K_SPACE and self.screen_mode == "play":
                self.toggle_simulation()
            elif event.key == pygame.K_n and self.screen_mode in ("play", "solved"):
                self.next_level()
            elif event.key == pygame.K_DOWN and self.screen_mode in ("select", "h2h"):
                levels = [l for l in self.level_list
                         if l["category"] == self.selected_category]
                self.select_index = min(len(levels) - 1, self.select_index + 1)
                if self.select_index >= self.select_scroll + 28:
                    self.select_scroll = self.select_index - 27
                self.select_hover = -1
            elif event.key == pygame.K_UP and self.screen_mode in ("select", "h2h"):
                self.select_index = max(0, self.select_index - 1)
                if self.select_index < self.select_scroll:
                    self.select_scroll = self.select_index
                self.select_hover = -1
            elif event.key == pygame.K_RETURN and self.screen_mode in ("select", "h2h"):
                levels = [l for l in self.level_list
                         if l["category"] == self.selected_category]
                if 0 <= self.select_index < len(levels):
                    self.load_and_start(levels[self.select_index])

    def _menu_click(self, mx, my):
        """Handle clicks on Main Menu."""
        buttons = [
            ("Puzzle Play", 460, 200, 360, 60, "select"),
            ("Head-to-Head", 460, 280, 360, 60, "h2h"),
            ("Edit Puzzles (Workshop)", 460, 360, 360, 60, "workshop"),
            ("Quit", 460, 440, 360, 60, "quit"),
        ]
        for label, bx, by, bw, bh, target in buttons:
            if bx <= mx <= bx + bw and by <= my <= by + bh:
                if target == "select":
                    self.screen_mode = "select"
                    self.selected_category = "Easy"
                elif target == "h2h":
                    self.h2h_mode = True
                    self.screen_mode = "h2h"
                    self.selected_category = "Head-to-Head"
                    self.select_index = 0
                    self.select_scroll = 0
                    self.message = ""
                elif target == "workshop":
                    try:
                        subprocess.Popen(EDITOR_CMD)
                        self.message = "Editor launched!"
                    except Exception as e:
                        self.message = f"Error launching editor: {e}"
                    self.message_timer = FPS * 3
                elif target == "quit":
                    pygame.quit()
                    sys.exit(0)

    def _select_click(self, mx, my):
        """Handle clicks on Puzzle Select screen."""
        # Category tabs
        tab_y = 100
        for i, (cat_name, _, _) in enumerate(CATEGORIES):
            tx = 50 + i * 200
            if mx >= tx and mx <= tx + 190 and my >= tab_y and my <= tab_y + 30:
                self.selected_category = cat_name
                self.select_scroll = 0
                self.select_hover = -1
                return

        # Level list
        list_y = 150
        levels = [l for l in self.level_list if l["category"] == self.selected_category]
        for i in range(self.select_scroll, min(self.select_scroll + 30, len(levels))):
            ly = list_y + (i - self.select_scroll) * 24
            if mx >= 100 and mx <= 750 and my >= ly and my <= ly + 22:
                level = levels[i]
                self.load_and_start(level)
                return

    def _h2h_click(self, mx, my):
        """Handle clicks on Head-to-Head level select."""
        list_y = 150
        levels = [l for l in self.level_list if l["category"] == self.selected_category]
        if not levels:
            return
        for i in range(self.select_scroll, min(self.select_scroll + 30, len(levels))):
            ly = list_y + (i - self.select_scroll) * 24
            if mx >= 100 and mx <= 750 and my >= ly and my <= ly + 22:
                level = levels[i]
                self.load_and_start(level)
                return

    def _play_click(self, mx, my):
        """Handle clicks during gameplay."""
        if mx >= VIEWPORT_X + VIEWPORT_W + 10 and mx <= WINDOW_W - 10:
            ry = VIEWPORT_Y
            # Debug buttons
            pass

    def _solved_click(self, mx, my):
        """Handle clicks on solved overlay."""
        bw, bh = 200, 40
        bx = WINDOW_W // 2 - bw // 2

        # Next puzzle
        if mx >= bx and mx <= bx + bw and my >= 340 and my <= 340 + bh:
            self.next_level()
        # Back to select
        if mx >= bx and mx <= bx + bw and my >= 400 and my <= 400 + bh:
            if self.h2h_mode:
                self.screen_mode = "h2h"
            else:
                self.screen_mode = "select"

    # ── Simulation ──
    def _on_part_state_change(self, part):
        """Callback: play per-part sound on state change."""
        sounds = self.registry.get_sounds_for_part(part.part_type)
        if sounds:
            idx = min(part.state_counter, len(sounds) - 1)
            self.renderer.play_sfx(sounds[idx])

    def _on_part_collision(self, a, b):
        """Callback: play per-part impact sound on collision. AU4."""
        sounds = self.registry.get_sounds_for_part(a.part_type)
        if sounds:
            self.renderer.play_sfx(sounds[0])

    def load_and_start(self, entry: dict):
        """Load a level and start simulation."""
        self.h2h_mode = (entry.get("category", "") == "Head-to-Head")
        yf = entry["file"]
        try:
            self.level = load_yaml(yf)
        except Exception as e:
            print(f"Error loading {yf.name}: {e}")
            return

        self.world = PhysicsWorld(viewport=(VIEWPORT_X, VIEWPORT_Y, VIEWPORT_W, VIEWPORT_H))
        self.world.pressure = self.level.pressure  # PH7
        self.world.on_state_change = self._on_part_state_change
        self.world.on_collision = self._on_part_collision  # AU4
        for p in self.level.parts:
            anm_name = self.registry.name_catalog.get(p.part_type, {}).get("anm_name", "")
            if not anm_name:
                anm_name = f"PART{p.part_type}"
            p.anm_name = anm_name

            # Apply physics properties from PAR file data
            phys = self.registry.get_physics_props(p.part_type)
            p.mass = phys["mass"]
            p.cor_q8 = phys["cor_q8"]
            p.friction_q8 = phys["friction_q8"]
            p.collision_radius = phys["collision_radius"]
            if phys["collision_w"] > 0:
                p.collision_w = phys["collision_w"]
            if phys["collision_h"] > 0:
                p.collision_h = phys["collision_h"]

            self.world.add_part(p)

        self.checker = SolutionChecker(self.level.solution_conditions)
        self.current_level_file = yf
        self.tick_count = 0
        self.running = True
        self.solved = False
        self.solve_timer = 0
        self.message = f"{self.level.title} — {self.level.goal}"
        self.message_timer = FPS * 3
        self.screen_mode = "play"

    def toggle_simulation(self):
        """Start/stop simulation."""
        if not self.world:
            return
        if self.running:
            self.running = False
            self.message = "PAUSED — Press SPACE to resume"
            self.message_timer = FPS * 2
        else:
            self.running = True

    def stop_simulation(self):
        """Stop and reset simulation."""
        self.running = False
        if self.world:
            self.world.reset()
            self.tick_count = 0

    def update_simulation(self):
        """Run one tick of simulation."""
        if not self.world or self.solved:
            return

        if self.tick_count >= 10000:
            self.running = False
            self.message = "Timeout — puzzle not solved"
            self.message_timer = FPS * 3
            return

        self.world.step()
        self.tick_count += 1

        if self.checker:
            solved, failed = self.checker.check(self.world)
            if solved:
                self.solved = True
                self.running = False
                self.solve_timer = 0
                self.screen_mode = "solved"
                if self.current_level_file:
                    save_solved_state(self.current_level_file.stem)
                    for lv in self.level_list:
                        if lv["file"] == self.current_level_file:
                            lv["solved"] = True
                            break

    def next_level(self):
        """Load the next level in the current category."""
        if not self.current_level_file:
            return
        levels = [l for l in self.level_list if l["category"] == self.selected_category]
        for i, l in enumerate(levels):
            if l["file"] == self.current_level_file:
                if i + 1 < len(levels):
                    self.load_and_start(levels[i + 1])
                return

    # ── Drawing ──
    def draw(self):
        self.screen.fill(COLORS["bg"])
        if self.screen_mode == "menu":
            self.draw_menu()
        elif self.screen_mode in ("select", "h2h"):
            if self.screen_mode == "h2h":
                self.draw_h2h()
            else:
                self.draw_select()
        elif self.screen_mode in ("play", "solved"):
            self.draw_playfield()
            if self.screen_mode == "solved":
                self.draw_solved_overlay()

    def draw_menu(self):
        """Draw Main Menu screen."""
        # Title
        title = self.font_title.render("THE INCREDIBLE MACHINE 2", True, COLORS["text_bright"])
        self.screen.blit(title, (WINDOW_W // 2 - title.get_width() // 2, 60))

        subtitle = self.font.render("Clean Room Reimplementation", True, COLORS["text_dim"])
        self.screen.blit(subtitle, (WINDOW_W // 2 - subtitle.get_width() // 2, 100))

        mx, my = pygame.mouse.get_pos()
        buttons = [
            ("Puzzle Play", 460, 200, 360, 60),
            ("Head-to-Head", 460, 280, 360, 60),
            ("Edit Puzzles (Workshop)", 460, 360, 360, 60),
            ("Quit", 460, 440, 360, 60),
        ]
        for label, bx, by, bw, bh in buttons:
            hover = bx <= mx <= bx + bw and by <= my <= by + bh
            color = COLORS["btn_hover"] if hover else COLORS["btn"]
            pygame.draw.rect(self.screen, color, (bx, by, bw, bh))
            pygame.draw.rect(self.screen, (150, 200, 150), (bx, by, bw, bh), 2)
            txt = self.font_big.render(label, True, COLORS["text"])
            self.screen.blit(txt, (bx + (bw - txt.get_width()) // 2, by + 15))

        # Side info
        info = [
            "150+ puzzles across 6 difficulty levels",
            "Build your own machines in the Workshop",
            "Compete with a friend in Head-to-Head mode",
        ]
        y = 560
        for line in info:
            t = self.font.render(line, True, COLORS["text_dim"])
            self.screen.blit(t, (100, y))
            y += 24

    def draw_select(self):
        """Draw Puzzle Select screen."""
        title = self.font_title.render("Select Puzzle", True, COLORS["text_bright"])
        self.screen.blit(title, (50, 30))

        instructions = self.font.render("Click a puzzle to start. ESC to return to menu.", True,
                                         COLORS["text_dim"])
        self.screen.blit(instructions, (50, 65))

        # Category tabs
        mx, my = pygame.mouse.get_pos()
        tab_y = 100
        for i, (cat_name, _, desc) in enumerate(CATEGORIES):
            tx = 50 + i * 200
            active = cat_name == self.selected_category
            color = COLORS["category_tab_active"] if active else COLORS["category_tab"]
            hover = tx <= mx <= tx + 190 and tab_y <= my <= tab_y + 30
            if hover:
                color = (120, 200, 120)
            pygame.draw.rect(self.screen, color, (tx, tab_y, 190, 30))
            pygame.draw.rect(self.screen, (100, 150, 100), (tx, tab_y, 190, 30), 1)
            txt = self.font.render(cat_name, True, COLORS["text"])
            self.screen.blit(txt, (tx + 10, tab_y + 7))

        # Level list
        levels = [l for l in self.level_list if l["category"] == self.selected_category]
        list_y = 150
        header = self.font_big.render(f"{self.selected_category} Puzzles ({len(levels)})",
                                       True, COLORS["text"])
        self.screen.blit(header, (100, list_y - 24))

        for i in range(self.select_scroll, min(self.select_scroll + 30, len(levels))):
            ly = list_y + (i - self.select_scroll) * 24
            lv = levels[i]

            hover = (mx >= 100 and mx <= 750 and my >= ly and my <= ly + 22)
            kbd_selected = (i == self.select_index)
            if hover:
                self.select_hover = i

            solved_mark = "*" if lv["solved"] else " "
            txt = self.font.render(
                f"  [{solved_mark}]  {lv['name']}",
                True,
                COLORS["solved"] if lv["solved"] else COLORS["text"]
            )
            self.screen.blit(txt, (105, ly + 2))

        # Scroll indicators
        if self.select_scroll > 0:
            self.screen.blit(self.font.render("▲ More above", True, COLORS["text_dim"]),
                            (100, list_y - 20))
        if self.select_scroll + 30 < len(levels):
            ly = list_y + 30 * 24
            self.screen.blit(self.font.render("▼ More below", True, COLORS["text_dim"]),
                            (100, ly))

    def draw_h2h(self):
        """Draw Head-to-Head puzzle selection screen."""
        # Header
        title = self.font_title.render("HEAD-TO-HEAD", True, COLORS["h2h_p1"])
        self.screen.blit(title, (WINDOW_W // 2 - title.get_width() // 2, 50))

        subtitle = self.font.render(
            "Two-player puzzles — alternate turns. First to solve wins!",
            True, COLORS["text_dim"]
        )
        self.screen.blit(subtitle, (WINDOW_W // 2 - subtitle.get_width() // 2, 90))

        # Instructions
        instr = self.font.render(
            "ESC: Return to menu  |  ↑↓: Navigate  |  ENTER: Select", True, COLORS["text_dim"]
        )
        self.screen.blit(instr, (WINDOW_W // 2 - instr.get_width() // 2, 120))

        # Level list
        levels = [l for l in self.level_list if l["category"] == self.selected_category]
        list_y = 170
        mx, my = pygame.mouse.get_pos()
        count_header = self.font_big.render(
            f"Head-to-Head Puzzles ({len(levels)})", True, COLORS["h2h_p1"]
        )
        self.screen.blit(count_header, (WINDOW_W // 2 - count_header.get_width() // 2, list_y - 24))

        if not levels:
            empty = self.font.render("No head-to-head levels found.", True, COLORS["text_dim"])
            self.screen.blit(empty, (WINDOW_W // 2 - empty.get_width() // 2, list_y + 40))
            return

        for i in range(self.select_scroll, min(self.select_scroll + 24, len(levels))):
            ly = list_y + (i - self.select_scroll) * 26
            lv = levels[i]
            hover = (mx >= 200 and mx <= 1080 and my >= ly and my <= ly + 24)
            kbd_selected = (i == self.select_index)

            if hover:
                self.select_hover = i

            solved_mark = "*" if lv["solved"] else " "
            row_color = COLORS["h2h_p1"] if i % 2 == 0 else COLORS["h2h_p2"]
            text_color = COLORS["text"]

            if kbd_selected:
                highlight = pygame.Rect(190, ly - 1, 900, 26)
                pygame.draw.rect(self.screen, (60, 60, 100), highlight)
                pygame.draw.rect(self.screen, COLORS["selected"], highlight, 1)
                text_color = COLORS["selected"]

            txt = self.font.render(
                f"  [{solved_mark}]  {lv['name']}",
                True, COLORS["solved"] if lv["solved"] else text_color
            )
            self.screen.blit(txt, (200, ly + 3))

        # Scroll indicators
        if self.select_scroll > 0:
            self.screen.blit(self.font.render("▲ More above", True, COLORS["text_dim"]),
                            (WINDOW_W // 2 - 50, list_y - 20))
        if self.select_scroll + 24 < len(levels):
            ly = list_y + 24 * 26
            self.screen.blit(self.font.render("▼ More below", True, COLORS["text_dim"]),
                            (WINDOW_W // 2 - 50, ly))

    def draw_playfield(self):
        """Draw the game simulation canvas."""
        # Canvas background — use level's bg_color from game palette
        canvas = pygame.Rect(VIEWPORT_X, VIEWPORT_Y, VIEWPORT_W, VIEWPORT_H)
        bg_rgb = COLORS["canvas_bg"]
        if self.level and self.renderer:
            palette = self.renderer._load_palette()
            bg_index = self.level.bg_color
            if 0 <= bg_index < len(palette):
                bg_rgb = palette[bg_index]
        pygame.draw.rect(self.screen, bg_rgb, canvas)

        # Grid
        for x in range(0, VIEWPORT_W, SNAP):
            pygame.draw.line(self.screen, COLORS["grid"],
                           (VIEWPORT_X + x, VIEWPORT_Y),
                           (VIEWPORT_X + x, VIEWPORT_Y + VIEWPORT_H))
        for y in range(0, VIEWPORT_H, SNAP):
            pygame.draw.line(self.screen, COLORS["grid"],
                           (VIEWPORT_X, VIEWPORT_Y + y),
                           (VIEWPORT_X + VIEWPORT_W, VIEWPORT_Y + y))

        # Draw parts with ANM sprites
        if self.world:
            bmp_dir = ROOT / "build" / "phase-3" / "bitmaps"
            interactive = [p for p in self.world.parts
                           if getattr(p, 'collision_cat', 'DYNAMIC') != 'SCENERY']
            scenery = [p for p in self.world.parts
                       if getattr(p, 'collision_cat', 'DYNAMIC') == 'SCENERY']

            def render_part(p):
                sx = VIEWPORT_X + p.x
                sy = VIEWPORT_Y + p.y
                if sx > VIEWPORT_X + VIEWPORT_W or sy > VIEWPORT_Y + VIEWPORT_H:
                    return
                sprite = None
                is_wall = False
                if p.anm_name and self.renderer:
                    sprite = self.renderer.render_wall(
                        p.anm_name, p.width_1, p.height_1, bmp_dir)
                    if sprite is not None:
                        is_wall = True
                    else:
                        state = p.current_state if p.current_state > 0 else self.renderer.get_default_state_id(p.anm_name)
                        sprite = self.renderer.render_frame(
                            p.anm_name, state, bmp_dir,
                            state_counter=p.state_counter,
                            part_width=p.width_1,
                            part_height=p.height_1,
                        )
                if sprite:
                    flip_h = bool(p.appearance & 0x8000) or bool(p.flags_2 & 0x0010)
                    draw_sprite = pygame.transform.flip(sprite, True, False) if flip_h else sprite
                    if is_wall:
                        self.screen.blit(draw_sprite, (sx, sy))
                    else:
                        tile_w = sprite.get_width()
                        tile_h = sprite.get_height()
                        tiles_x = max(1, math.ceil(p.width_1 / tile_w)) if tile_w > 0 else 1
                        tiles_y = max(1, math.ceil(p.height_1 / tile_h)) if tile_h > 0 else 1
                        for ty in range(tiles_y):
                            for tx in range(tiles_x):
                                self.screen.blit(draw_sprite, (sx + tx * tile_w, sy + ty * tile_h))
                else:
                    color = COLORS["selected"] if p.is_moving else (120, 120, 120)
                    rect = pygame.Rect(sx, sy, p.width_1, p.height_1)
                    pygame.draw.rect(self.screen, color, rect, 1)
                # Rope/belt connection lines
                if p.connected_1 >= 0 and p.connected_1 < len(self.world.parts):
                    target = self.world.parts[p.connected_1]
                    cx = sx + p.width_1 // 2
                    cy = sy + p.height_1 // 2
                    tx = VIEWPORT_X + target.x + target.width_1 // 2
                    ty = VIEWPORT_Y + target.y + target.height_1 // 2
                    pygame.draw.line(self.screen, COLORS["rope"], (cx, cy), (tx, ty), 1)

            for p in interactive:
                render_part(p)
            if self.prefs.get("show_scenery", True):
                for p in scenery:
                    render_part(p)

        # Solution rectangles
        if self.level:
            for sc in self.level.solution_conditions:
                if sc.has_position and not sc.is_off_screen:
                    rx, ry, rw, rh = sc.rect
                    rect = pygame.Rect(
                        VIEWPORT_X + rx, VIEWPORT_Y + ry, rw, rh
                    )
                    pygame.draw.rect(self.screen, (0, 200, 0, 80), rect, 2)

        # Sidebar — Part list
        sidebar_x = VIEWPORT_X + VIEWPORT_W + 15
        self.screen.blit(self.font_big.render("Parts", True, COLORS["text"]),
                        (sidebar_x, VIEWPORT_Y))

        if self.world:
            y = VIEWPORT_Y + 25
            for i, p in enumerate(self.world.parts[:40]):
                if y > VIEWPORT_Y + VIEWPORT_H:
                    break
                color = (100, 200, 255) if p.is_moving else COLORS["text"]
                txt = self.font.render(
                    f"#{p.part_type} {p.name[:20] if p.name else '?'} s{p.current_state}",
                    True, color
                )
                self.screen.blit(txt, (sidebar_x, y))
                y += 14
            if len(self.world.parts) > 40:
                self.screen.blit(
                    self.font.render(f"... +{len(self.world.parts) - 40} more", True,
                                    COLORS["text_dim"]),
                    (sidebar_x, y)
                )

        # Status bar
        y = VIEWPORT_Y + VIEWPORT_H + 10
        if self.message and self.message_timer > 0:
            txt = self.font_big.render(self.message, True, COLORS["success"])
            self.screen.blit(txt, (VIEWPORT_X + 10, y))
            self.message_timer -= 1

        tick_txt = self.font.render(
            f"Tick: {self.tick_count}  |  "
            f"Parts: {len(self.world.parts) if self.world else 0}  |  "
            f"SPACE: {'Pause' if self.running else 'Start'}  |  "
            f"ESC: Back  |  N: Next",
            True, COLORS["text_dim"]
        )
        self.screen.blit(tick_txt, (VIEWPORT_X, y + 25))

        # Level info
        if self.level:
            lvl_txt = self.font.render(
                f"{self.level.title} — {self.level.goal}",
                True, COLORS["text"]
            )
            self.screen.blit(lvl_txt, (VIEWPORT_X, y + 45))

        # Head-to-Head indicator
        if self.h2h_mode:
            self.screen.blit(
                self.font_big.render("HEAD-TO-HEAD", True, COLORS["h2h_p1"]),
                (VIEWPORT_X + 10, VIEWPORT_Y + 8)
            )

    def draw_solved_overlay(self):
        """Draw puzzle solved overlay."""
        overlay = pygame.Surface((WINDOW_W, WINDOW_H), pygame.SRCALPHA)
        overlay.fill((0, 0, 0, 180))
        self.screen.blit(overlay, (0, 0))

        cx = WINDOW_W // 2
        if self.h2h_mode:
            winner_color = COLORS["h2h_p1"]
            winner_label = "PLAYER 1 WINS!"
            txt = self.font_title.render(winner_label, True, winner_color)
            self.screen.blit(txt, (cx - txt.get_width() // 2, 160))
            sub_win = self.font_big.render("Head-to-Head Challenge Complete!", True, COLORS["text"])
            self.screen.blit(sub_win, (cx - sub_win.get_width() // 2, 200))
        else:
            txt = self.font_title.render("PUZZLE SOLVED!", True, COLORS["success"])
            self.screen.blit(txt, (cx - txt.get_width() // 2, 180))

        if self.level:
            lvl_txt = self.font_big.render(
                f"{self.current_level_file.stem if self.current_level_file else '?'} — "
                f"{self.level.title}",
                True, COLORS["text"]
            )
            self.screen.blit(lvl_txt, (cx - lvl_txt.get_width() // 2, 240))

        tick_txt = self.font.render(f"Solved in {self.tick_count} ticks", True,
                                     COLORS["text_dim"])
        self.screen.blit(tick_txt, (cx - tick_txt.get_width() // 2, 275))

        # Buttons
        bw, bh = 200, 40
        bx = cx - bw // 2
        buttons = [
            ("Next Puzzle (N)", 340, "next"),
            ("Back to Select (ESC)", 400, "back"),
        ]
        mx, my = pygame.mouse.get_pos()
        for label, by, action in buttons:
            hover = bx <= mx <= bx + bw and by <= my <= by + bh
            color = COLORS["btn_hover"] if hover else COLORS["btn"]
            pygame.draw.rect(self.screen, color, (bx, by, bw, bh))
            pygame.draw.rect(self.screen, (150, 200, 150), (bx, by, bw, bh), 2)
            txt = self.font.render(label, True, COLORS["text"])
            self.screen.blit(txt, (bx + (bw - txt.get_width()) // 2, by + 10))


def main():
    game = Game()

    # If level name passed on command line, start it directly
    if len(sys.argv) > 1:
        level_name = sys.argv[1]
        path = game.yaml_dir / f"{level_name}.yaml"
        if not path.exists():
            # Try without extension
            path = game.yaml_dir / f"{level_name}"
        if path.exists():
            # FIXME: Check save file for solved state instead of hardcoding False
            entry = {"file": path, "category": "Custom", "name": path.stem, "solved": False}
            game.load_and_start(entry)
            game.running = True

    game.run()


if __name__ == "__main__":
    main()
