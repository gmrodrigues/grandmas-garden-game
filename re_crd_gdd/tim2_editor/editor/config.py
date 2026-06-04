"""Editor configuration constants."""
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent.parent

# Window
WINDOW_WIDTH = 1280
WINDOW_HEIGHT = 720
FPS = 60

# Game viewport (TIM2 standard)
VIEWPORT_WIDTH = 560
VIEWPORT_HEIGHT = 377
VIEWPORT_X = 10
VIEWPORT_Y = 60

# Catalog panel (right of viewport)
CATALOG_WIDTH = 200
CATALOG_X = VIEWPORT_X + VIEWPORT_WIDTH + 10
CATALOG_Y = VIEWPORT_Y
CATALOG_HEIGHT = VIEWPORT_HEIGHT

# Grid
SNAP_GRID = 16

# Colors
COLORS = {
    "bg": (40, 42, 48),
    "panel_bg": (50, 52, 58),
    "canvas_bg": (30, 90, 150),
    "grid": (60, 100, 160),
    "part_outline": (255, 255, 255),
    "part_fill": (200, 200, 200),
    "selected": (255, 200, 0),
    "moving": (100, 200, 255),
    "button": (70, 72, 78),
    "button_hover": (90, 92, 98),
    "text": (220, 220, 220),
    "text_dim": (140, 140, 140),
    "success": (80, 200, 80),
    "failure": (220, 60, 60),
    "hint": (255, 255, 0),
    "rope": (150, 100, 50),
    "belt": (100, 100, 100),
    "solution_rect": (0, 255, 0, 30),  # rgba
}

# Data files (bundled editor assets)
DATA_DIR = PROJECT_ROOT / "tim2_editor" / "data"
PART_CATALOG_PATH = DATA_DIR / "part-name-catalog.json"
PART_PROPS_PATH = DATA_DIR / "part-properties.json"
YAML_DIR = PROJECT_ROOT / "build" / "phase-5" / "yaml"

# Tick rate
TICK_RATE = 60  # Hz
