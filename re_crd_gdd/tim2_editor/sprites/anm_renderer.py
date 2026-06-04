"""ANM sprite renderer — loads ANM JSON, maps state→frame, renders sprites."""
import json
import logging
from pathlib import Path
from typing import Optional, List, Dict, Any, Tuple
import pygame

try:
    from PIL import Image as PILImage
    HAS_PILLOW = True
except ImportError:
    HAS_PILLOW = False

logger = logging.getLogger(__name__)


class AnmRenderer:
    """Renders ANM sprites for a part type.

    ANM Section D opcodes (from Phase 4 ANM parser):
      cmd=0: END_FRAME      — terminates current frame's bytecode
      cmd=1: END_ANM        — terminates entire ANM
      cmd=2: DRAW_BMP       — resource_id, sub_image, x, y, flags
      cmd=3: DRAW_RECT      — x, y, width, height, color, flags
      cmd=4: DRAW_LINE      — x1, y1, x2, y2, flags
      cmd=5: PLAY_SFX       — sound_id
    """

    def __init__(self, anm_dir: Path, part_name_catalog: dict = None,
                 palette_dir: Path = None, wav_dir: Path = None):
        self.anm_dir = anm_dir
        self.part_name_catalog = part_name_catalog or {}
        self.palette_dir = palette_dir
        self.wav_dir = wav_dir

        # Build reverse lookup: part_type → anm_name
        self.part_to_anm: Dict[int, str] = {}
        if isinstance(self.part_name_catalog, list):
            for entry in self.part_name_catalog:
                pt = entry.get("part_type")
                anm = entry.get("anm_name", "")
                if pt is not None and anm:
                    self.part_to_anm[pt] = anm

        # Cache: anm_name → parsed JSON
        self.anm_cache: Dict[str, dict] = {}
        # PNG sprite cache: path → Surface
        self.png_cache: Dict[str, pygame.Surface] = {}
        # Palette cache
        self._palette_cache: Optional[List[Tuple[int, int, int]]] = None

        # Sound cache
        self._sound_cache: Dict[int, pygame.mixer.Sound] = {}
        self._mixer_ready = False

    def get_anm_for_part(self, part_type: int) -> Optional[str]:
        """Look up ANM filename from part type."""
        return self.part_to_anm.get(part_type)

    def load_anm(self, anm_name: str) -> Optional[dict]:
        """Load an ANM JSON file into cache. Returns parsed data or None."""
        if anm_name in self.anm_cache:
            return self.anm_cache[anm_name]
        name = anm_name if anm_name.endswith(".json") else f"{anm_name}.json"
        path = self.anm_dir / name
        if not path.exists():
            return None
        try:
            data = json.loads(path.read_text())
            self.anm_cache[anm_name] = data
            return data
        except (json.JSONDecodeError, IOError):
            return None

    def get_default_state_id(self, anm_name: str) -> int:
        """Return the state_id with smallest first_frame_id (idle/base appearance).

        For walls, this returns state_id=2 (16x16 brick tile) instead of
        state_id=1 (40x16 join graphic). For non-walls, returns the first
        Section C entry's state_id (usually 1 or 3).
        Falls back to 1 if ANM can't be loaded or Section C is empty.
        """
        anm_data = self.load_anm(anm_name)
        if anm_data is None:
            return 1
        section_c = anm_data.get("section_c", [])
        if not section_c:
            return 1
        return min(section_c, key=lambda e: e.get("first_frame_id", 0)).get("state_id", 1)

    def get_first_frame_for_state(self, anm_data: dict, state_id: int) -> int:
        """Section C: state_id → first_frame_id."""
        for entry in anm_data.get("section_c", []):
            if entry.get("state_id") == state_id:
                return entry.get("first_frame_id", 0)
        return 0

    def get_frame_meta(self, anm_data: dict, frame_idx: int) -> Optional[dict]:
        """Section B: frame_idx → {x, y, width, height, bytecode_offset}."""
        frames = anm_data.get("section_b", [])
        if 0 <= frame_idx < len(frames):
            return frames[frame_idx]
        return None

    def get_bytecodes_for_frame(self, anm_data: dict,
                                bytecode_offset: int) -> List[dict]:
        """Section D: return all bytecode entries from offset until END_FRAME/END_ANM."""
        bytecodes = anm_data.get("section_d", [])
        start_idx = -1
        for i, entry in enumerate(bytecodes):
            if entry.get("offset") == bytecode_offset:
                start_idx = i
                break
        if start_idx < 0:
            return []

        result = []
        for entry in bytecodes[start_idx:]:
            cmd = entry.get("cmd", -1)
            result.append(entry)
            if cmd in (0, 1):  # END_FRAME or END_ANM
                break
        return result

    def render_frame(self, anm_name: str, state_id: int,
                     bmp_dir: Path,
                     state_counter: int = 0,
                     part_width: int = 0,
                     part_height: int = 0) -> Optional[pygame.Surface]:
        """Render a single ANM frame at the given state as a pygame Surface.

        Pipeline: state_id → Section C (first_frame_id) → Section A indirection
        → Section B (meta) → Section D (bytecode execution).

        Section A is a frame index sequence: section_a[first_a_idx + counter]
        gives the actual section_b frame index. This allows some states to
        have multiple animation frames driven by the state_counter.

        When part_width/part_height > 0, also scans section_b for a frame
        that exactly matches the given dimensions. If found, uses that frame
        instead of the state-driven one. This handles incline ramps which
        store pre-rendered frames at different widths (16, 32, 48, 64 px).
        """
        anm_data = self.load_anm(anm_name)
        if anm_data is None:
            return None

        # Compute standard state-driven frame index
        first_a_idx = self.get_first_frame_for_state(anm_data, state_id)
        section_a = anm_data.get("section_a", [])
        if section_a:
            a_idx = first_a_idx + state_counter
            section_b_idx = section_a[a_idx % len(section_a)]
        else:
            section_b_idx = first_a_idx

        # If dimension hints provided, scan section_b for an exact match.
        # Incline ramps (PART2, PART99-PART102, PART126) store 4 frames at
        # widths 16, 32, 48, 64 — an exact match picks the right frame.
        # Falls back to the state-driven frame if no exact match (wall tiling case).
        if part_width > 0 or part_height > 0:
            section_b = anm_data.get("section_b", [])
            for i, f in enumerate(section_b):
                fw = f.get("width", 0)
                fh = f.get("height", 0)
                if fw == part_width and fh == part_height:
                    section_b_idx = i
                    break

        return self._render_section_b_frame(anm_data, section_b_idx, anm_name, bmp_dir)

    def _render_section_b_frame(self, anm_data: dict, section_b_idx: int,
                                 anm_name: str, bmp_dir: Path) -> Optional[pygame.Surface]:
        """Render a single Section B frame directly by index (bypasses state lookup)."""
        meta = self.get_frame_meta(anm_data, section_b_idx)
        if meta is None:
            return None

        w, h = meta["width"], meta["height"]
        if w <= 0 or h <= 0:
            return None

        surface = pygame.Surface((w, h), pygame.SRCALPHA)
        surface.fill((0, 0, 0, 0))

        bytecodes = self.get_bytecodes_for_frame(anm_data, meta["bytecode_offset"])
        for entry in bytecodes:
            self._execute_bytecode(surface, entry, anm_name, bmp_dir)

        return surface

    def render_wall(self, anm_name: str, width: int, height: int,
                    bmp_dir: Path) -> Optional[pygame.Surface]:
        """Render a wall part with proper end-cap and center tiles.

        Matches timgres PartGraphicsInfo_T2_WallPipe: wall ANMs encode tile
        counts in the last two Section C entries:
          section_c[-2].first_frame_id = num_horizontal_tile_variants
          section_c[-1].first_frame_id = num_horizontal + num_vertical

        Within each orientation group (0-3 horizontal, 4-7 vertical):
          index 0 = left/top cap, indices 1..n-2 = alternating
          center tiles, index n-1 = right/bottom cap.

        Returns a single composited Surface of the full wall, or None if
        the part is not a wall-type ANM.
        """
        anm_data = self.load_anm(anm_name)
        if anm_data is None:
            return None

        section_c = anm_data.get("section_c", [])
        if len(section_c) != 2:
            return None
        if anm_data.get("section_a"):
            return None

        num_h = section_c[-2].get("first_frame_id", 0)
        num_v = section_c[-1].get("first_frame_id", 0) - num_h
        if num_h <= 0 or num_v <= 0:
            return None

        tile_size = 16

        is_horizontal = height == tile_size and width > tile_size
        is_vertical = width == tile_size and height > tile_size
        if not is_horizontal and not is_vertical:
            return None

        if is_horizontal:
            wall_len = width // tile_size
            first_sub_img = 0
            num_tiles = num_h
            surf_w, surf_h = width, tile_size
        else:
            wall_len = height // tile_size
            first_sub_img = num_h
            num_tiles = num_v
            surf_w, surf_h = tile_size, height

        surface = pygame.Surface((surf_w, surf_h), pygame.SRCALPHA)
        surface.fill((0, 0, 0, 0))

        for i in range(wall_len):
            if i == 0:
                sub_idx = first_sub_img
            elif i == wall_len - 1:
                sub_idx = first_sub_img + num_tiles - 1
            else:
                center_idx = (i - 1) % (num_tiles - 2)
                sub_idx = first_sub_img + 1 + center_idx

            # Render sub-image directly (matching timgres, bypassing ANM bytecodes)
            sprite = self._load_png(anm_name, sub_idx, bmp_dir)
            if sprite is not None:
                x = i * tile_size if is_horizontal else 0
                y = 0 if is_horizontal else i * tile_size
                surface.blit(sprite, (x, y))

        return surface

    def _execute_bytecode(self, surface: pygame.Surface,
                           entry: dict, anm_name: str, bmp_dir: Path):
        """Execute a single Section D bytecode entry."""
        cmd = entry.get("cmd", -1)

        if cmd == 2:  # DRAW_BMP
            self._draw_bmp(surface, entry, anm_name, bmp_dir)
        elif cmd == 3:  # DRAW_RECT
            self._draw_rect(surface, entry)
        elif cmd == 4:  # DRAW_LINE
            self._draw_line(surface, entry)
        elif cmd == 5:  # PLAY_SFX
            self.play_sfx(entry.get("sound_id", 0))
        # cmd 0 (END_FRAME) and 1 (END_ANM): no-op, handled by caller

    def play_sfx(self, sound_id: int):
        """Play a sound effect. Caches loaded WAVs. Silently skips if WAV is missing."""
        if self.wav_dir is None:
            return
        if sound_id in self._sound_cache:
            self._sound_cache[sound_id].play()
            return
        wav_path = self.wav_dir / f"SX_{sound_id}_11025.wav"
        if not wav_path.exists():
            return
        if not self._mixer_ready:
            try:
                pygame.mixer.init()
                self._mixer_ready = True
            except Exception as e:
                logger.warning("pygame.mixer.init failed: %s", e)
                return
        try:
            snd = pygame.mixer.Sound(str(wav_path))
            self._sound_cache[sound_id] = snd
            snd.play()
        except Exception as e:
            logger.warning("Sound %d playback failed: %s", sound_id, e)

    def _draw_bmp(self, surface: pygame.Surface, entry: dict,
                   anm_name: str, bmp_dir: Path):
        """Execute DRAW_BMP: render a BMP sub-resource from decoded PNG."""
        resource_id = entry.get("resource_id", 1)
        sub_image = entry.get("sub_image", 0)
        bx = entry.get("x", 0)
        by = entry.get("y", 0)
        flags = entry.get("flags", 0)  # bit 0 = hflip, bit 1 = vflip

        # Resolve BMP resource name:
        # resource_id=1 → {anm_name} (PART0, PART4)
        # resource_id>1 → {anm_name}{suffix} where suffix is a letter or letter pair
        bmp_name = self._resolve_resource_name(anm_name, resource_id, bmp_dir)

        # Try loading the PNG
        sprite = self._load_png(bmp_name, sub_image, bmp_dir)
        if sprite is None:
            return  # No sprite found, leave transparent

        # Apply flip flags
        if flags & 1:  # horizontal flip
            sprite = pygame.transform.flip(sprite, True, False)
        if flags & 2:  # vertical flip
            sprite = pygame.transform.flip(sprite, False, True)

        surface.blit(sprite, (bx, by))

    def _resolve_resource_name(self, anm_name: str, resource_id: int,
                                bmp_dir: Path) -> str:
        """Resolve resource_id to the actual BMP name prefix on disk."""
        if resource_id == 1:
            return anm_name

        # Build a cache keyed by (anm_name, resource_id)
        cache_key = (anm_name, resource_id)
        if not hasattr(self, '_resource_cache'):
            self._resource_cache = {}
        if cache_key in self._resource_cache:
            return self._resource_cache[cache_key]

        # Scan bitmaps dir for all files starting with anm_name followed by letters only
        all_prefixes = set()
        import re
        for f in bmp_dir.iterdir():
            stem = f.stem
            if '_f' in stem:
                prefix = stem.split('_f')[0]
            else:
                prefix = stem
            if prefix == anm_name:
                all_prefixes.add(prefix)
            else:
                # Must match {anm_name}{LETTERS} only (not digits)
                m = re.match(r'^' + re.escape(anm_name) + r'([A-Z]+)$', prefix)
                if m:
                    all_prefixes.add(prefix)

        # Sort by length (shorter first: PART4, then PART4B, PART4C, PART4ST, PART4X...)
        candidates = sorted([p for p in all_prefixes if p != anm_name],
                           key=lambda x: (len(x), x))

        # Map candidates to resource_ids 2, 3, 4, ...
        for i, prefix in enumerate(candidates, start=2):
            self._resource_cache[(anm_name, i)] = prefix

        result = self._resource_cache.get(cache_key)
        if result is None:
            result = f"{anm_name}_{resource_id}"  # fallback
        return result

    def _load_png(self, bmp_name: str, sub_image: int,
                   bmp_dir: Path) -> Optional[pygame.Surface]:
        """Load a decoded PNG sprite from build/phase-3/bitmaps/."""
        candidates = [
            f"{bmp_name}_f{sub_image:03d}.png",
            f"{bmp_name}.png",
        ]
        for fname in candidates:
            path = bmp_dir / fname
            if path in self.png_cache:
                return self.png_cache[path]
            if path.exists():
                surface = self._load_image(path)
                if surface is not None:
                    self.png_cache[path] = surface
                    return surface
        return None

    @staticmethod
    def _load_image(path: Path) -> Optional[pygame.Surface]:
        """Try pygame.image.load first, fall back to Pillow for PNGs."""
        try:
            img = pygame.image.load(str(path))
            return img.convert_alpha()
        except Exception:
            if not HAS_PILLOW:
                return None
            try:
                pil_img = PILImage.open(str(path)).convert("RGBA")
                mode = pil_img.mode
                size = pil_img.size
                data = pil_img.tobytes()
                if mode == "RGBA":
                    surface = pygame.image.fromstring(data, size, "RGBA")
                elif mode == "RGB":
                    surface = pygame.image.fromstring(data, size, "RGB").convert_alpha()
                else:
                    surface = pygame.image.fromstring(data, size, mode).convert_alpha()
                return surface
            except Exception:
                return None

    def _draw_rect(self, surface: pygame.Surface, entry: dict):
        """Execute DRAW_RECT: fill a rectangle."""
        rx = entry.get("x", 0)
        ry = entry.get("y", 0)
        rw = entry.get("width", 0)
        rh = entry.get("height", 0)
        color_val = entry.get("color", 0)
        color = self._decode_color(color_val)
        pygame.draw.rect(surface, color, (rx, ry, rw, rh))

    def _draw_line(self, surface: pygame.Surface, entry: dict):
        """Execute DRAW_LINE."""
        x1 = entry.get("x1", 0)
        y1 = entry.get("y1", 0)
        x2 = entry.get("x2", 0)
        y2 = entry.get("y2", 0)
        # DRAW_LINE color is encoded in the low byte of flags
        color_val = entry.get("color", entry.get("flags", 0) & 0xFF)
        color = self._decode_color(color_val)
        pygame.draw.line(surface, color, (x1, y1), (x2, y2))

    def _decode_color(self, color_val: int) -> Tuple[int, int, int, int]:
        """Decode TIM2 8-bit indexed color to RGBA using the game palette."""
        palette = self._load_palette()
        if 0 <= color_val < len(palette):
            return palette[color_val] + (255,)
        # Fallback: unpack as 24-bit RGB
        r = (color_val >> 0) & 0xFF
        g = (color_val >> 8) & 0xFF
        b = (color_val >> 16) & 0xFF
        return (r, g, b, 255)

    def _load_palette(self) -> List[Tuple[int, int, int]]:
        """Load the game palette from build/phase-3/palettes/."""
        if self._palette_cache is not None:
            return self._palette_cache

        # Try PARTTEMP.PAL first (the global game palette)
        palette_dir = self.palette_dir
        if palette_dir is None:
            palette_dir = Path(__file__).resolve().parent.parent / "data" / "palettes"

        candidates = [
            palette_dir / "PARTTEMP.json",
            palette_dir / "TIM2.json",
            palette_dir / "TIM.json",
        ]
        for path in candidates:
            if path.exists():
                try:
                    data = json.loads(path.read_text())
                    colors = data.get("colors", [])
                    palette = [(c.get("r", 0), c.get("g", 0), c.get("b", 0))
                              for c in colors[:256]]
                    # Pad to 256 if needed
                    while len(palette) < 256:
                        palette.append((0, 0, 0))
                    self._palette_cache = palette
                    return palette
                except Exception as e:
                    logger.warning("Palette JSON parse failed for %s: %s", path.name, e)

        # Fallback: standard VGA 16-color palette
        self._palette_cache = [
            (0, 0, 0), (0, 0, 168), (0, 168, 0), (0, 168, 168),
            (168, 0, 0), (168, 0, 168), (168, 84, 0), (168, 168, 168),
            (84, 84, 84), (84, 84, 252), (84, 252, 84), (84, 252, 252),
            (252, 84, 84), (252, 84, 252), (252, 252, 84), (252, 252, 252),
        ]
        while len(self._palette_cache) < 256:
            self._palette_cache.append((0, 0, 0))
        return self._palette_cache
