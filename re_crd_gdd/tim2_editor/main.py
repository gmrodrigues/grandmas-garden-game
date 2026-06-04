"""TIM2 Level Editor — main entry point."""
import logging
import math
import sys, json, os, tempfile
from pathlib import Path
from typing import Optional, List, Tuple
from collections import defaultdict

logger = logging.getLogger(__name__)

try:
    import tkinter as tk
    from tkinter import filedialog
    TKINTER_AVAILABLE = True
except ImportError:
    TKINTER_AVAILABLE = False

# Ensure pygame runs headlessly if needed
os.environ.setdefault("SDL_VIDEODRIVER", "x11")

import pygame

ROOT = Path(__file__).resolve().parent.parent
DATA_DIR = ROOT / "tim2_editor" / "data"
sys.path.insert(0, str(ROOT))

from tim2_editor.engine.part import Part
from tim2_editor.engine.world import PhysicsWorld
from tim2_editor.engine.behavior import get_registry
from tim2_editor.engine.level import LevelData, load_yaml, save_yaml, SolutionCondition
from tim2_editor.engine.solver import SolutionChecker
from tim2_editor.sprites.anm_renderer import AnmRenderer
from tim2_editor.editor.config import (
    WINDOW_WIDTH, WINDOW_HEIGHT, FPS, VIEWPORT_X, VIEWPORT_Y,
    VIEWPORT_WIDTH, VIEWPORT_HEIGHT, SNAP_GRID, COLORS, YAML_DIR,
    PART_CATALOG_PATH, PART_PROPS_PATH,
    CATALOG_X, CATALOG_Y, CATALOG_WIDTH, CATALOG_HEIGHT,
)

# States
MODE_SELECT = 0
MODE_PLACE = 1
MODE_DELETE = 2
MODE_PREVIEW = 3
MODE_CONNECT = 4
MODE_LEVEL_INFO = 5


class Editor:
    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
        pygame.display.set_caption("TIM2 Level Editor")
        self.clock = pygame.time.Clock()
        self.font = pygame.font.Font(None, 14)
        self.font_small = pygame.font.Font(None, 11)
        self.font_title = pygame.font.Font(None, 17)
        
        # Level data
        self.level = LevelData()
        self.world = PhysicsWorld()
        self.checker: Optional[SolutionChecker] = None
        
        # Selection & editing
        self.selected_idx: Optional[int] = None
        self.mode = MODE_SELECT
        self.tool_place_type = 0
        
        # Scroll / camera
        self.scroll_x = 0
        self.scroll_y = 0
        self.zoom = 1.0
        self.zoom_min = 0.25
        self.zoom_max = 4.0
        
        # Dragging
        self.dragging = False
        self.drag_start_x = 0
        self.drag_start_y = 0
        self.drag_part_start_x = 0
        self.drag_part_start_y = 0
        self.panning = False
        self.pan_start_x = 0
        self.pan_start_y = 0
        
        # Connection tool state
        self.connect_source_idx: Optional[int] = None
        self.connect_preview_line: Optional[Tuple[int, int, int, int]] = None
        self.selected_handle: Optional[str] = None
        self.dragging_handle = False
        self.drag_start_x = 0
        self.drag_start_y = 0
        self.handle_drag_start_w = 0
        self.handle_drag_start_h = 0
        self.preview_running = False
        self.preview_ticks = 0
        self.preview_solved = False
        self.preview_message = ""
        self.preview_message_timer = 0
        self.mouse_pos = (0, 0)
        self.dialog_fields: list = []
        self.dialog_focus = 0
        self.dialog_bufs: dict = {}
        self.dialog_cursor_timer = 0.0
        
        # Part catalog data
        self.catalog: List[dict] = []
        self.catalog_scroll = 0
        self.catalog_categories: List[str] = []
        self.catalog_parts_by_cat: dict = {}
        self.part_name_map: dict = {}
        self.thumbnail_cache: Dict[int, pygame.Surface] = {}
        self._catalog_entry_rects: List[Tuple[pygame.Rect, int]] = []
        self.load_catalog()

        # Sprite resources (bundled editor assets)
        self.bmp_dir = DATA_DIR / "sprites"
        self.editor_tick = 0
        
        # Sprite renderer
        anm_dir = DATA_DIR / "anm"
        part_name_catalog = []
        part_name_path = DATA_DIR / "part-name-catalog.json"
        if part_name_path.exists():
            try:
                part_name_catalog = json.loads(part_name_path.read_text())
            except (json.JSONDecodeError, IOError) as e:
                logger.warning("Failed to load part-name-catalog.json: %s", e)
        self.anm_renderer = AnmRenderer(
            anm_dir, part_name_catalog,
            palette_dir=DATA_DIR / "palettes",
            wav_dir=DATA_DIR / "wav",
        ) if anm_dir.exists() else None

        # Default level
        self.new_level()

    def load_catalog(self):
        """Load part names and organize by category."""
        if not PART_CATALOG_PATH.exists():
            print(f"WARNING: {PART_CATALOG_PATH} not found")
            return
        data = json.loads(PART_CATALOG_PATH.read_text())
        cats = defaultdict(list)
        for entry in data:
            if isinstance(entry, dict):
                cat = entry.get("category", "Uncategorized")
                cats[cat].append(entry)
                pt = entry.get("part_type")
                if pt is not None:
                    self.part_name_map[pt] = entry.get("name", f"Part {pt}")
        self.catalog_categories = sorted(cats.keys())
        self.catalog_parts_by_cat = dict(cats)
    
    def _wire_world_callbacks(self):
        """Wire .world callbacks (state change + collision) to play sounds through the renderer."""
        if not self.anm_renderer:
            return
        registry = get_registry()
        def _on_state_change(part):
            sounds = registry.get_sounds_for_part(part.part_type)
            if sounds:
                idx = min(part.state_counter, len(sounds) - 1)
                self.anm_renderer.play_sfx(sounds[idx])
        self.world.on_state_change = _on_state_change

        def _on_collision(a, b):
            sounds = registry.get_sounds_for_part(a.part_type)
            if sounds:
                self.anm_renderer.play_sfx(sounds[0])
        self.world.on_collision = _on_collision  # AU4

    def new_level(self):
        """Create a new empty level."""
        self.level = LevelData()
        self.level.title = "Untitled"
        self.level.goal = "Solve the puzzle!"
        self.world = PhysicsWorld()
        self._wire_world_callbacks()
        self.selected_idx = None
        self.preview_running = False
        self.preview_solved = False
        self.checker = None
        self.thumbnail_cache.clear()
    
    def load_level(self, yaml_path: Path):
        """Load a level from YAML."""
        self.level = load_yaml(yaml_path)
        self.world = PhysicsWorld()
        self.world.pressure = self.level.pressure  # PH7
        self._wire_world_callbacks()
        self.thumbnail_cache.clear()
        for p in self.level.parts:
            # Set ANM name from part type
            if self.anm_renderer:
                p.anm_name = self.anm_renderer.get_anm_for_part(p.part_type) or ""
            self.world.add_part(p)
        self.selected_idx = None
        self.preview_running = False
        self.checker = SolutionChecker(self.level.solution_conditions)
    
    def save_level(self, path: Path):
        """Save level to YAML."""
        save_yaml(path, self.level)

    def _save_with_dialog(self):
        """Open save dialog and save level."""
        if not TKINTER_AVAILABLE:
            print(f"tkinter not available. Enter save path (or Enter to cancel):")
            try:
                path_str = input("> ").strip()
                if path_str:
                    p = Path(path_str)
                    self.save_level(p)
                    print(f"Saved to {p}")
            except (EOFError, KeyboardInterrupt):
                print()
            return
        root = tk.Tk()
        root.withdraw()
        path = filedialog.asksaveasfilename(
            title="Save TIM2 Level",
            defaultextension=".yaml",
            filetypes=[("TIM2 Level", "*.yaml"), ("All files", "*.*")],
            initialdir=str(YAML_DIR),
        )
        root.destroy()
        if path:
            self.save_level(Path(path))
            print(f"Saved to {path}")

    def _load_with_dialog(self):
        """Open load dialog and load level."""
        if not TKINTER_AVAILABLE:
            print(f"tkinter not available. Enter path to .yaml file (or Enter to cancel):")
            try:
                path_str = input("> ").strip()
                if path_str:
                    p = Path(path_str)
                    if p.exists():
                        self.load_level(p)
                        print(f"Loaded {p}")
                    else:
                        print(f"File not found: {p}")
            except (EOFError, KeyboardInterrupt):
                print()
            return
        root = tk.Tk()
        root.withdraw()
        path = filedialog.askopenfilename(
            title="Load TIM2 Level",
            filetypes=[("TIM2 Level", "*.yaml"), ("All files", "*.*")],
            initialdir=str(YAML_DIR),
        )
        root.destroy()
        if path:
            self.load_level(Path(path))
            print(f"Loaded {path}")

    def place_part(self, x: int, y: int, part_type: int):
        """Place a part at grid-snapped position."""
        sx = (x // SNAP_GRID) * SNAP_GRID
        sy = (y // SNAP_GRID) * SNAP_GRID
        part = Part(part_type=part_type)
        part.x = sx
        part.y = sy
        part.is_moving = True
        if self.anm_renderer:
            part.anm_name = self.anm_renderer.get_anm_for_part(part_type) or ""
        self.level.parts.append(part)
        self.world.add_part(part)
        return len(self.level.parts) - 1
    
    def delete_part(self, idx: int):
        """Delete a part by index."""
        if 0 <= idx < len(self.level.parts):
            self.world.remove_part(idx)
            del self.level.parts[idx]
            if self.selected_idx == idx:
                self.selected_idx = None
            elif self.selected_idx is not None and self.selected_idx > idx:
                self.selected_idx -= 1
    
    def move_part(self, idx: int, x: int, y: int):
        """Move a part to new grid-snapped position."""
        if 0 <= idx < len(self.level.parts):
            part = self.level.parts[idx]
            part.x = (x // SNAP_GRID) * SNAP_GRID
            part.y = (y // SNAP_GRID) * SNAP_GRID

    def screen_to_level(self, sx: int, sy: int) -> Tuple[int, int]:
        """Convert screen coordinates to level coordinates with zoom."""
        lx = (sx - VIEWPORT_X) / self.zoom + self.scroll_x
        ly = (sy - VIEWPORT_Y) / self.zoom + self.scroll_y
        return int(lx), int(ly)

    def level_to_screen(self, lx: int, ly: int) -> Tuple[int, int]:
        """Convert level coordinates to screen coordinates with zoom."""
        sx = (lx - self.scroll_x) * self.zoom + VIEWPORT_X
        sy = (ly - self.scroll_y) * self.zoom + VIEWPORT_Y
        return int(sx), int(sy)

    def find_part_at(self, mx: int, my: int) -> Optional[int]:
        """Find the topmost (last drawn) part at screen coordinates."""
        # Convert screen coords to level coords
        lx, ly = self.screen_to_level(mx, my)
        # Iterate in reverse (topmost parts first)
        for i in range(len(self.level.parts) - 1, -1, -1):
            p = self.level.parts[i]
            if p.x <= lx <= p.x + p.width_1 and p.y <= ly <= p.y + p.height_1:
                return i
        return None
    
    def _save_preview_snapshot(self) -> Path:
        """Save current level state to a temp YAML file before simulation."""
        tmp = Path(tempfile.mkstemp(suffix=".yaml")[1])
        save_yaml(tmp, self.level)
        return tmp

    def _restore_preview_snapshot(self, path: Path):
        """Reload level from temp snapshot, restoring initial state."""
        if path.exists():
            self.load_level(path)
            path.unlink(missing_ok=True)

    def toggle_preview(self):
        """Start or stop simulation preview."""
        if self.preview_running:
            self.preview_running = False
            self.preview_solved = False
            self.preview_message = ""
            self._restore_preview_snapshot(self._preview_snapshot_path)
            return

        self._preview_snapshot_path = self._save_preview_snapshot()
        self.preview_running = True
        self.preview_solved = False
        self.preview_ticks = 0
        self.world.reset()
        self.checker = SolutionChecker(self.level.solution_conditions)
        self.preview_message = "RUNNING..."

    def update_preview(self):
        """Run one tick of simulation preview."""
        if not self.preview_running or self.preview_solved:
            return

        self.world.step()
        self.preview_ticks += 1

        if self.checker:
            solved, failed = self.checker.check(self.world)
            if solved:
                self.preview_solved = True
                self.preview_message = "✅ LEVEL SOLVED!"
                self.preview_message_timer = FPS * 3
            elif self.preview_ticks > 10000:
                self.preview_running = False
                self.preview_message = "❌ Timeout — conditions not met"
                self.preview_message_timer = FPS * 3
                self._restore_preview_snapshot(self._preview_snapshot_path)
    
    # ---- DRAWING ----
    
    def draw(self):
        self.screen.fill(COLORS["bg"])
        
        # Draw viewport background — use level's bg_color from game palette
        view_rect = pygame.Rect(VIEWPORT_X, VIEWPORT_Y, VIEWPORT_WIDTH, VIEWPORT_HEIGHT)
        bg_rgb = COLORS["canvas_bg"]
        if self.level and self.anm_renderer:
            palette = self.anm_renderer._load_palette()
            bg_index = self.level.bg_color
            if 0 <= bg_index < len(palette):
                bg_rgb = palette[bg_index]
        pygame.draw.rect(self.screen, bg_rgb, view_rect)
        
        # Draw grid
        self.draw_grid()
        
        # Draw parts
        for i, p in enumerate(self.level.parts):
            self.draw_part(p, i == self.selected_idx)
        
        # Draw solution rectangles
        if self.level.solution_conditions:
            for sc in self.level.solution_conditions:
                if sc.has_position and not sc.is_off_screen:
                    rx, ry, rw, rh = sc.rect
                    sx = (rx - self.scroll_x) * self.zoom + VIEWPORT_X
                    sy = (ry - self.scroll_y) * self.zoom + VIEWPORT_Y
                    sw = rw * self.zoom
                    sh = rh * self.zoom
                    rect = pygame.Rect(int(sx), int(sy), int(sw), int(sh))
                    pygame.draw.rect(self.screen, (0, 200, 0, 80), rect, max(1, int(self.zoom)))
        
        # Draw connection preview line
        if self.connect_preview_line and self.mode == MODE_CONNECT:
            sx1, sy1, sx2, sy2 = self.connect_preview_line
            pygame.draw.line(self.screen, (255, 200, 0), (int(sx1), int(sy1)), (int(sx2), int(sy2)), 2)
            pygame.draw.circle(self.screen, (255, 200, 0), (int(sx2), int(sy2)), 6, 2)

        # Highlight connection source part
        if self.connect_source_idx is not None and self.mode == MODE_CONNECT:
            p = self.level.parts[self.connect_source_idx]
            sx = (p.x - self.scroll_x) * self.zoom + VIEWPORT_X
            sy = (p.y - self.scroll_y) * self.zoom + VIEWPORT_Y
            sw = p.width_1 * self.zoom
            sh = p.height_1 * self.zoom
            pygame.draw.rect(self.screen, (255, 200, 0), (int(sx), int(sy), int(sw), int(sh)), max(1, int(self.zoom)))

# Draw selection handles when a part is selected in SELECT mode
        if self.selected_idx is not None and self.mode == MODE_SELECT:
            self.draw_selection_handles()

        # Catalog panel
        self.draw_catalog()

        # Tooltip: part name on hover
        if not self.preview_running and VIEWPORT_X <= self.mouse_pos[0] <= VIEWPORT_X + VIEWPORT_WIDTH \
                and VIEWPORT_Y <= self.mouse_pos[1] <= VIEWPORT_Y + VIEWPORT_HEIGHT:
            idx = self.find_part_at(self.mouse_pos[0], self.mouse_pos[1])
            if idx is not None:
                pt = self.level.parts[idx].part_type
                name = self.part_name_map.get(pt, f"Part {pt}")
                self._draw_tooltip(name, self.mouse_pos[0], self.mouse_pos[1])

        # Level info dialog overlay
        if self.mode == MODE_LEVEL_INFO:
            self._draw_level_dialog()

    def handle_hit_test(self, mx: int, my: int) -> Optional[str]:
        """Test if mouse is over a resize handle. Returns handle name or None."""
        if self.selected_idx is None or self.selected_idx >= len(self.level.parts):
            return None
        part = self.level.parts[self.selected_idx]
        sx = (part.x - self.scroll_x) * self.zoom + VIEWPORT_X
        sy = (part.y - self.scroll_y) * self.zoom + VIEWPORT_Y
        sw = part.width_1 * self.zoom
        sh = part.height_1 * self.zoom
        handle_size = max(6, int(8 * self.zoom))
        half = handle_size // 2
        hit_radius = handle_size

        positions = {
            "tl": (sx - half, sy - half),
            "tr": (sx + sw - half, sy - half),
            "bl": (sx - half, sy + sh - half),
            "br": (sx + sw - half, sy + sh - half),
            "tc": (sx + sw // 2 - half, sy - half),
            "bc": (sx + sw // 2 - half, sy + sh - half),
            "lc": (sx - half, sy + sh // 2 - half),
            "rc": (sx + sw - half, sy + sh // 2 - half),
        }
        for name, (hx, hy) in positions.items():
            if hx <= mx <= hx + handle_size and hy <= my <= hy + handle_size:
                return name
        return None

    def draw_selection_handles(self):
        """Draw resize/flip handles around selected part."""
        if self.selected_idx is None or self.selected_idx >= len(self.level.parts):
            return
        part = self.level.parts[self.selected_idx]
        sx = (part.x - self.scroll_x) * self.zoom + VIEWPORT_X
        sy = (part.y - self.scroll_y) * self.zoom + VIEWPORT_Y
        sw = part.width_1 * self.zoom
        sh = part.height_1 * self.zoom
        handle_size = max(6, int(8 * self.zoom))
        half = handle_size // 2

        # Corners + midpoints
        positions = [
            (sx - half, sy - half),          # top-left
            (sx + sw - half, sy - half),     # top-right
            (sx - half, sy + sh - half),     # bottom-left
            (sx + sw - half, sy + sh - half),# bottom-right
            (sx + sw // 2 - half, sy - half),    # top-center
            (sx + sw // 2 - half, sy + sh - half),# bottom-center
            (sx - half, sy + sh // 2 - half),     # left-center
            (sx + sw - half, sy + sh // 2 - half),# right-center
        ]
        for px, py in positions:
            pygame.draw.rect(self.screen, (255, 200, 0), (int(px), int(py), handle_size, handle_size), 1)

        # Draw action labels
        label_y = sy + sh + 4
        labels = [
            ("[F]lip", sx),
            ("[Del]", sx + sw + 4),
        ]
        for text, lx_pos in labels:
            txt = self.font_small.render(text, True, (180, 180, 180))
            self.screen.blit(txt, (lx_pos, label_y))

    def draw_grid(self):
        """Draw viewport grid lines snapped to SNAP_GRID."""
        grid_color = COLORS["grid"]
        step = SNAP_GRID
        start_x = int(self.scroll_x // step) * step
        start_y = int(self.scroll_y // step) * step
        vp_right = VIEWPORT_X + VIEWPORT_WIDTH
        vp_bottom = VIEWPORT_Y + VIEWPORT_HEIGHT
        gx = start_x
        while True:
            sx = (gx - self.scroll_x) * self.zoom + VIEWPORT_X
            if sx > vp_right:
                break
            if sx >= VIEWPORT_X:
                pygame.draw.line(self.screen, grid_color, (int(sx), VIEWPORT_Y), (int(sx), vp_bottom))
            gx += step
        gy = start_y
        while True:
            sy = (gy - self.scroll_y) * self.zoom + VIEWPORT_Y
            if sy > vp_bottom:
                break
            if sy >= VIEWPORT_Y:
                pygame.draw.line(self.screen, grid_color, (VIEWPORT_X, int(sy)), (vp_right, int(sy)))
            gy += step

    def draw_catalog(self):
        """Draw the part catalog panel on the right side of the viewport."""
        panel_rect = pygame.Rect(CATALOG_X, CATALOG_Y, CATALOG_WIDTH, CATALOG_HEIGHT)
        pygame.draw.rect(self.screen, COLORS["panel_bg"], panel_rect)
        pygame.draw.rect(self.screen, COLORS["text_dim"], panel_rect, 1)

        # Mode indicator
        mode_names = {0: "SELECT", 1: "PLACE", 2: "DELETE", 3: "PREVIEW", 4: "CONNECT", 5: "LEVEL INFO"}
        mode_str = mode_names.get(self.mode, f"MODE {self.mode}")
        if self.mode == MODE_PLACE:
            name = self.part_name_map.get(self.tool_place_type, f"Part {self.tool_place_type}")
            mode_str += f" [{self.tool_place_type}] {name}"
        mode_label = self.font_small.render(mode_str, True, COLORS["selected"] if self.mode != MODE_SELECT else COLORS["text"])
        self.screen.blit(mode_label, (CATALOG_X + 4, CATALOG_Y + 4))
        panel_top = CATALOG_Y + 20

        self._catalog_entry_rects = []
        y = panel_top - self.catalog_scroll

        for cat_name in self.catalog_categories:
            header = self.font_small.render(cat_name, True, COLORS["hint"])
            self.screen.blit(header, (CATALOG_X + 4, y))
            y += 18

            for entry in self.catalog_parts_by_cat.get(cat_name, []):
                pt = entry.get("part_type", 0)
                name = entry.get("name", f"Part {pt}")
                entry_h = 36
                is_active = self.mode == MODE_PLACE and self.tool_place_type == pt

                if y + entry_h > CATALOG_Y and y < CATALOG_Y + CATALOG_HEIGHT:
                    if is_active:
                        highlight = pygame.Rect(CATALOG_X, int(y), CATALOG_WIDTH, entry_h)
                        pygame.draw.rect(self.screen, (60, 65, 40), highlight)

                    thumb = self._render_icon_thumbnail(pt)
                    tx = CATALOG_X + 4
                    ty = y + (entry_h - 32) // 2
                    if thumb:
                        self.screen.blit(thumb, (tx, ty))

                    label_color = COLORS["selected"] if is_active else COLORS["text"]
                    label = self.font_small.render(name, True, label_color)
                    label_x = tx + 36
                    label_y = y + (entry_h - label.get_height()) // 2
                    self.screen.blit(label, (label_x, label_y))

                entry_rect = pygame.Rect(CATALOG_X, int(y), CATALOG_WIDTH, entry_h)
                self._catalog_entry_rects.append((entry_rect, pt))

                y += entry_h

    def _render_icon_thumbnail(self, part_type: int) -> Optional[pygame.Surface]:
        """Render a 32×32 icon thumbnail for the catalog panel."""
        cached = self.thumbnail_cache.get(part_type)
        if cached is not None:
            return cached
        if not self.anm_renderer:
            return None
        anm_name = self.anm_renderer.get_anm_for_part(part_type)
        if not anm_name:
            return None
        sprite = self.anm_renderer.render_frame(anm_name, 1, self.bmp_dir, state_counter=0)
        if sprite is None:
            return None
        ow, oh = sprite.get_size()
        if ow <= 0 or oh <= 0:
            return None
        scale = min(32 / ow, 32 / oh)
        nw = max(1, int(ow * scale))
        nh = max(1, int(oh * scale))
        thumb = pygame.transform.scale(sprite, (nw, nh))
        self.thumbnail_cache[part_type] = thumb
        return thumb

    def draw_part(self, part, is_selected: bool):
        """Draw a single part in the viewport, using ANM sprite when available."""
        sx = (part.x - self.scroll_x) * self.zoom + VIEWPORT_X
        sy = (part.y - self.scroll_y) * self.zoom + VIEWPORT_Y
        sprite = None
        is_wall = False
        if self.anm_renderer and part.anm_name:
            sprite = self.anm_renderer.render_wall(
                part.anm_name, part.width_1, part.height_1, self.bmp_dir)
            if sprite is not None:
                is_wall = True
            else:
                state = part.current_state if part.current_state > 0 else self.anm_renderer.get_default_state_id(part.anm_name)
                sprite = self.anm_renderer.render_frame(
                    part.anm_name, state, self.bmp_dir,
                    state_counter=self.editor_tick,
                    part_width=part.width_1,
                    part_height=part.height_1,
                )
        if sprite:
            flip_h = bool(part.appearance & 0x8000) or bool(part.flags_2 & 0x0010)
            draw_sprite = pygame.transform.flip(sprite, True, False) if flip_h else sprite
            if is_wall:
                sw = int(sprite.get_width() * self.zoom)
                sh = int(sprite.get_height() * self.zoom)
                if sw > 0 and sh > 0:
                    scaled = pygame.transform.scale(draw_sprite, (sw, sh))
                    self.screen.blit(scaled, (int(sx), int(sy)))
            else:
                tile_w = sprite.get_width()
                tile_h = sprite.get_height()
                tiles_x = max(1, math.ceil(part.width_1 / tile_w)) if tile_w > 0 else 1
                tiles_y = max(1, math.ceil(part.height_1 / tile_h)) if tile_h > 0 else 1
                tiled_w = int(tile_w * self.zoom)
                tiled_h = int(tile_h * self.zoom)
                if tiled_w > 0 and tiled_h > 0:
                    scaled = pygame.transform.scale(draw_sprite, (tiled_w, tiled_h))
                    for ty in range(tiles_y):
                        for tx in range(tiles_x):
                            tsx = int(sx + tx * tiled_w)
                            tsy = int(sy + ty * tiled_h)
                            self.screen.blit(scaled, (tsx, tsy))
            if is_selected:
                total_w = int(part.width_1 * self.zoom)
                total_h = int(part.height_1 * self.zoom)
                pygame.draw.rect(self.screen, COLORS["selected"],
                                 (int(sx), int(sy), total_w, total_h), max(1, int(self.zoom)))
        else:
            sw = max(1, part.width_1 * self.zoom)
            sh = max(1, part.height_1 * self.zoom)
            rect = pygame.Rect(int(sx), int(sy), int(sw), int(sh))
            if is_selected:
                outline = COLORS["selected"]
                fill = (180, 140, 0, 80)
            else:
                outline = COLORS["part_outline"]
                fill = COLORS["part_fill"]
            pygame.draw.rect(self.screen, fill, rect)
            pygame.draw.rect(self.screen, outline, rect, max(1, int(self.zoom)))

    def _draw_tooltip(self, text: str, mx: int, my: int):
        """Draw a small tooltip box near the given screen position."""
        label = self.font_small.render(text, True, (255, 255, 255))
        pad = 3
        tw = label.get_width() + pad * 2
        th = label.get_height() + pad * 2
        tx = min(mx + 12, WINDOW_WIDTH - tw - 4)
        ty = my - th - 8
        if ty < 0:
            ty = my + 12
        bg = pygame.Surface((tw, th))
        bg.set_alpha(200)
        bg.fill((20, 20, 30))
        self.screen.blit(bg, (tx, ty))
        self.screen.blit(label, (tx + pad, ty + pad))

    # ── Level Info Dialog ──

    def _open_level_dialog(self):
        self.mode = MODE_LEVEL_INFO
        self.dialog_fields = [
            ("title", "Title", str),
            ("goal", "Goal", str),
            ("bg_color", "BG Color", int),
            ("pressure", "Pressure", int),
            ("gravity", "Gravity", int),
            ("music_track", "Music Track", int),
        ]
        self.dialog_bufs = {
            "title": str(self.level.title),
            "goal": str(self.level.goal),
            "bg_color": str(self.level.bg_color),
            "pressure": str(self.level.pressure),
            "gravity": str(self.level.gravity),
            "music_track": str(self.level.music_track),
        }
        self.dialog_focus = 0
        self.dialog_cursor_timer = 0.0

    def _commit_level_dialog(self):
        try:
            self.level.title = self.dialog_bufs["title"]
            self.level.goal = self.dialog_bufs["goal"]
            self.level.bg_color = int(self.dialog_bufs["bg_color"])
            self.level.pressure = int(self.dialog_bufs["pressure"])
            self.level.gravity = int(self.dialog_bufs["gravity"])
            self.level.music_track = int(self.dialog_bufs["music_track"])
        except (ValueError, KeyError):
            pass
        self.mode = MODE_SELECT

    def _cancel_level_dialog(self):
        self.mode = MODE_SELECT

    def _dialog_box_rect(self):
        w, h = 440, 320
        x = (WINDOW_WIDTH - w) // 2
        y = (WINDOW_HEIGHT - h) // 2
        return pygame.Rect(x, y, w, h)

    def _dialog_field_rect(self, index: int) -> pygame.Rect:
        box = self._dialog_box_rect()
        row_h = 28
        gap = 6
        field_top = box.y + 38 + index * (row_h + gap)
        label_w = 120
        input_w = box.w - label_w - 30
        return pygame.Rect(box.x + label_w + 16, field_top, input_w, row_h)

    def _draw_level_dialog(self):
        overlay = pygame.Surface((WINDOW_WIDTH, WINDOW_HEIGHT))
        overlay.set_alpha(160)
        overlay.fill((0, 0, 0))
        self.screen.blit(overlay, (0, 0))

        box = self._dialog_box_rect()
        pygame.draw.rect(self.screen, (50, 52, 58), box)
        pygame.draw.rect(self.screen, (100, 100, 120), box, 2)

        title = self.font_title.render("Level Info", True, (255, 255, 255))
        self.screen.blit(title, (box.x + 12, box.y + 8))

        row_h = 28
        gap = 6
        import time
        show_cursor = int(time.time() * 2) % 2 == 0

        for i, (key, label_text, field_type) in enumerate(self.dialog_fields):
            fy = box.y + 38 + i * (row_h + gap)
            label_surf = self.font.render(label_text + ":", True, (180, 180, 180))
            self.screen.blit(label_surf, (box.x + 12, fy + 4))

            input_rect = self._dialog_field_rect(i)
            if i == self.dialog_focus:
                input_color = (60, 70, 90)
                border_color = (200, 200, 80)
            else:
                input_color = (40, 42, 48)
                border_color = (70, 72, 78)
            pygame.draw.rect(self.screen, input_color, input_rect)
            pygame.draw.rect(self.screen, border_color, input_rect, 1)

            buf = self.dialog_bufs.get(key, "")
            if i == self.dialog_focus and show_cursor:
                display_text = buf + "|"
            else:
                display_text = buf
            text_surf = self.font.render(display_text, True, (220, 220, 220))
            self.screen.blit(text_surf, (input_rect.x + 4, input_rect.y + 4))

        btn_y = box.y + box.h - 40
        ok_rect = pygame.Rect(box.x + box.w - 180, btn_y, 70, 28)
        cancel_rect = pygame.Rect(box.x + box.w - 90, btn_y, 70, 28)
        for rect, label, color in [(ok_rect, "OK", (60, 140, 60)),
                                    (cancel_rect, "Cancel", (140, 60, 60))]:
            pygame.draw.rect(self.screen, color, rect)
            pygame.draw.rect(self.screen, (180, 180, 180), rect, 1)
            s = self.font.render(label, True, (255, 255, 255))
            self.screen.blit(s, (rect.x + (rect.w - s.get_width()) // 2,
                                 rect.y + (rect.h - s.get_height()) // 2))

        self._dlg_ok_rect = ok_rect
        self._dlg_cancel_rect = cancel_rect

    def _level_dialog_handle_key(self, event):
        key = event.key
        field_key = self.dialog_fields[self.dialog_focus][0]
        field_type = self.dialog_fields[self.dialog_focus][2]
        buf = self.dialog_bufs.get(field_key, "")

        if key == pygame.K_RETURN or key == pygame.K_KP_ENTER:
            self._commit_level_dialog()
        elif key == pygame.K_ESCAPE:
            self._cancel_level_dialog()
        elif key == pygame.K_TAB:
            mods = pygame.key.get_mods()
            delta = -1 if mods & pygame.KMOD_SHIFT else 1
            self.dialog_focus = (self.dialog_focus + delta) % len(self.dialog_fields)
        elif key == pygame.K_BACKSPACE:
            self.dialog_bufs[field_key] = buf[:-1]
        elif key == pygame.K_DELETE:
            self.dialog_bufs[field_key] = ""
        else:
            char = event.unicode
            if char:
                if field_type is int:
                    if char.isdigit() or (char == '-' and len(buf) == 0):
                        self.dialog_bufs[field_key] = buf + char
                else:
                    if 32 <= ord(char) < 127:
                        self.dialog_bufs[field_key] = buf + char

    def _level_dialog_handle_click(self, mx: int, my: int):
        for i in range(len(self.dialog_fields)):
            if self._dialog_field_rect(i).collidepoint(mx, my):
                self.dialog_focus = i
                return
        if hasattr(self, '_dlg_ok_rect') and self._dlg_ok_rect.collidepoint(mx, my):
            self._commit_level_dialog()
        elif hasattr(self, '_dlg_cancel_rect') and self._dlg_cancel_rect.collidepoint(mx, my):
            self._cancel_level_dialog()

    def handle_key(self, event):
        if event.key == pygame.K_s:
            self.mode = MODE_SELECT
        elif event.key == pygame.K_p:
            self.mode = MODE_PLACE
        elif event.key == pygame.K_d:
            self.mode = MODE_DELETE
        elif event.key == pygame.K_c:
            self.mode = MODE_CONNECT
            self.connect_source_idx = None
            self.connect_preview_line = None
        elif event.key == pygame.K_SPACE:
            self.toggle_preview()
        elif event.key == pygame.K_DELETE or event.key == pygame.K_BACKSPACE:
            if self.selected_idx is not None and not self.preview_running:
                self.delete_part(self.selected_idx)
        elif event.key == pygame.K_n:
            if not self.preview_running:
                self.new_level()
        elif event.key == pygame.K_s and pygame.key.get_mods() & pygame.KMOD_CTRL:
            # Ctrl+S: Save with file dialog
            self._save_with_dialog()
        elif event.key == pygame.K_l and pygame.key.get_mods() & pygame.KMOD_CTRL:
            # Ctrl+L: Load with file dialog
            self._load_with_dialog()
        elif event.key == pygame.K_z and not (pygame.key.get_mods() & pygame.KMOD_CTRL):
            # Z: Reset zoom to 1x
            self.zoom = 1.0
        elif event.key == pygame.K_EQUALS or event.key == pygame.K_PLUS:
            # +: Zoom in
            self.zoom = min(self.zoom * 1.5, self.zoom_max)
        elif event.key == pygame.K_MINUS:
            # -: Zoom out
            self.zoom = max(self.zoom / 1.5, self.zoom_min)
        elif event.key == pygame.K_0:
            # 0: Reset scroll to origin
            self.scroll_x = 0
            self.scroll_y = 0
        elif event.key == pygame.K_f:
            # F: Flip selected part (toggle facing direction for asymmetric parts)
            self.flip_selected()
        elif event.key == pygame.K_l and not (pygame.key.get_mods() & pygame.KMOD_CTRL):
            # L: Lock/unlock selected part (toggle is_moving flag)
            self.toggle_lock_selected()
        elif event.key == pygame.K_i:
            if not self.preview_running:
                self._open_level_dialog()

    def flip_selected(self):
        """Flip the selected part horizontally (toggle appearance bit)."""
        if self.selected_idx is not None and self.selected_idx < len(self.level.parts):
            part = self.level.parts[self.selected_idx]
            part.appearance ^= 0x8000  # Toggle horizontal flip flag
            print(f"Flipped part #{self.selected_idx}")

    def toggle_lock_selected(self):
        """Lock/unlock selected part (toggle is_moving flag)."""
        if self.selected_idx is not None and self.selected_idx < len(self.level.parts):
            part = self.level.parts[self.selected_idx]
            part.is_moving = not part.is_moving
            if part.is_moving:
                part.flags_1 |= 0x1000
            else:
                part.flags_1 &= ~0x1000
            locked_str = "LOCKED" if not part.is_moving else "UNLOCKED"
            print(f"Part #{self.selected_idx} {locked_str}")

    def handle_mouse_down(self, event):
        if self.preview_running:
            self.toggle_preview()
            return

        mx, my = event.pos

        # Middle mouse button for panning
        if event.button == 2:
            self.panning = True
            self.pan_start_x = mx
            self.pan_start_y = my
            return

        # Check catalog panel click
        if CATALOG_X <= mx <= CATALOG_X + CATALOG_WIDTH and \
           CATALOG_Y <= my <= CATALOG_Y + CATALOG_HEIGHT:
            for rect, pt in getattr(self, '_catalog_entry_rects', []):
                if rect.collidepoint(mx, my):
                    self.tool_place_type = pt
                    self.mode = MODE_PLACE
                    return
            return

        # Check canvas area
        if VIEWPORT_X <= mx <= VIEWPORT_X + VIEWPORT_WIDTH and \
           VIEWPORT_Y <= my <= VIEWPORT_Y + VIEWPORT_HEIGHT:
            lx, ly = self.screen_to_level(mx, my)

            if self.mode == MODE_SELECT:
                # Check if clicking on a resize handle first
                handle_hit = self.handle_hit_test(mx, my)
                if handle_hit is not None:
                    self.selected_handle = handle_hit
                    self.dragging_handle = True
                    self.drag_start_x = mx
                    self.drag_start_y = my
                    if self.selected_idx is not None:
                        p = self.level.parts[self.selected_idx]
                        self.handle_drag_start_w = p.width_1
                        self.handle_drag_start_h = p.height_1
                    return

                idx = self.find_part_at(mx, my)
                if idx is not None:
                    self.selected_idx = idx
                    self.dragging = True
                    self.drag_start_x = mx
                    self.drag_start_y = my
                    part = self.level.parts[idx]
                    self.drag_part_start_x = part.x
                    self.drag_part_start_y = part.y
                else:
                    self.selected_idx = None

            elif self.mode == MODE_PLACE:
                idx = self.place_part(lx, ly, self.tool_place_type)
                if self.tool_place_type == 0:
                    self.tool_place_type += 1
                self.selected_idx = idx

            elif self.mode == MODE_DELETE:
                idx = self.find_part_at(mx, my)
                if idx is not None:
                    self.delete_part(idx)

            elif self.mode == MODE_CONNECT:
                idx = self.find_part_at(mx, my)
                if idx is not None:
                    if self.connect_source_idx is None:
                        # First click: set source
                        self.connect_source_idx = idx
                    else:
                        # Second click: create connection
                        source_part = self.level.parts[self.connect_source_idx]
                        target_part = self.level.parts[idx]
                        source_part.connected_1 = idx
                        # Update world to reflect new connection
                        if idx < len(self.world.parts):
                            self.world.parts[self.connect_source_idx].connected_1 = idx
                        self.connect_source_idx = None
                        self.connect_preview_line = None
    
    def handle_mouse_up(self, event):
        if self.dragging:
            self.dragging = False
            self.drag_part_start_x = 0
            self.drag_part_start_y = 0
        if self.dragging_handle:
            self.dragging_handle = False
            self.selected_handle = None
        if self.panning:
            self.panning = False

    def handle_mouse_motion(self, event):
        mx, my = event.pos
        self.mouse_pos = (mx, my)
        if self.panning:
            dx = mx - self.pan_start_x
            dy = my - self.pan_start_y
            self.scroll_x -= dx / self.zoom
            self.scroll_y -= dy / self.zoom
            self.pan_start_x = mx
            self.pan_start_y = my
        elif self.dragging_handle and self.selected_idx is not None and not self.preview_running:
            dx = (mx - self.drag_start_x) / self.zoom
            dy = (my - self.drag_start_y) / self.zoom
            part = self.level.parts[self.selected_idx]
            new_w = max(16, self.handle_drag_start_w + dx)
            new_h = max(16, self.handle_drag_start_h + dy)
            part.width_1 = int(new_w // SNAP_GRID) * SNAP_GRID
            part.height_1 = int(new_h // SNAP_GRID) * SNAP_GRID
            part.width_2 = part.width_1
            part.height_2 = part.height_1
        elif self.dragging and self.selected_idx is not None and not self.preview_running:
            dx = (mx - self.drag_start_x) / self.zoom
            dy = (my - self.drag_start_y) / self.zoom
            new_x = self.drag_part_start_x + dx
            new_y = self.drag_part_start_y + dy
            self.move_part(self.selected_idx, new_x, new_y)
        elif self.connect_source_idx is not None and self.mode == MODE_CONNECT:
            # Update preview line while dragging
            source_part = self.level.parts[self.connect_source_idx]
            sx1 = (source_part.x + source_part.width_1 // 2 - self.scroll_x) * self.zoom + VIEWPORT_X
            sy1 = (source_part.y + source_part.height_1 // 2 - self.scroll_y) * self.zoom + VIEWPORT_Y
            self.connect_preview_line = (sx1, sy1, mx, my)

    def handle_mouse_wheel(self, event):
        if self.preview_running:
            return
        if CATALOG_X <= self.mouse_pos[0] <= CATALOG_X + CATALOG_WIDTH and \
           CATALOG_Y <= self.mouse_pos[1] <= CATALOG_Y + CATALOG_HEIGHT:
            delta = -30 if event.y > 0 else 30
            self.catalog_scroll = max(0, self.catalog_scroll + delta)
            return
        if event.y > 0:
            self.zoom = min(self.zoom * 1.25, self.zoom_max)
        elif event.y < 0:
            self.zoom = max(self.zoom / 1.25, self.zoom_min)

    def handle_event(self, event):
        if self.mode == MODE_LEVEL_INFO:
            if event.type == pygame.KEYDOWN:
                self._level_dialog_handle_key(event)
            elif event.type == pygame.MOUSEBUTTONDOWN:
                self._level_dialog_handle_click(event.pos[0], event.pos[1])
            return
        if event.type == pygame.KEYDOWN:
            self.handle_key(event)
        elif event.type == pygame.MOUSEBUTTONDOWN:
            self.handle_mouse_down(event)
        elif event.type == pygame.MOUSEBUTTONUP:
            self.handle_mouse_up(event)
        elif event.type == pygame.MOUSEMOTION:
            self.handle_mouse_motion(event)
        elif event.type == pygame.MOUSEWHEEL:
            self.handle_mouse_wheel(event)

    def run(self):
        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                else:
                    self.handle_event(event)
            
            if self.preview_running:
                self.update_preview()
            
            self.editor_tick += 1
            self.draw()
            pygame.display.flip()
            self.clock.tick(FPS)
        
        pygame.quit()
        sys.exit()


if __name__ == "__main__":
    editor = Editor()
    
    # Load command-line level if provided
    if len(sys.argv) > 1:
        path = Path(sys.argv[1])
        if path.exists():
            print(f"Loading {path}...")
            try:
                editor.load_level(path)
            except Exception as e:
                print(f"Error loading {path}: {e}")
    
    editor.run()
