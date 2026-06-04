# 2. Backend-First Godot Architecture

To guarantee absolute determinism, the Godot implementation **must not** use Godot's built-in 2D physics engine. Instead, Godot acts strictly as a "Visual Shell" (a View) over a deterministic custom physics engine written in GDScript.

## 2.1 Layer Isolation

```text
res://
├─ backend/     # Pure GDScript mathematical engine (NO SceneTree Nodes)
├─ data/        # Decoded original assets (Bypassing Godot Importer)
└─ frontend/    # Visual shell (Godot Nodes reading from backend)
```

## 2.2 The Core Engine (`res://backend/`)

Implemented purely in `GDScript` using lightweight `RefCounted` objects.

| Python Prototype | Godot Backend | Purpose |
|------------------|---------------|---------|
| `engine/world.py` | `WorldState.gd` | Holds the array of all `PartData` instances, global gravity, and the tick counter. |
| `engine/part.py` | `PartData.gd` | The 48-byte memory struct representation (type, flags, position, velocity, state). |
| `engine/behaviors.py` | `BehaviorRegistry.gd` | Maps part types to specific collision/state subroutines. |
| `engine/simulation.py` | `SimulationLoop.gd` | Coordinates the 60Hz deterministic tick (Passes 0 through 6). |
| (Implicit integer math) | `PhysicsMath.gd` | Reusable fixed-point math and bit-shifting logic (e.g., `velocity >> 9`). |

## 2.3 The Asset Repository (`res://data/`)

Godot's default image/audio import pipeline is bypassed for raw game assets. Assets are loaded directly from the filesystem at runtime using `FileAccess` and `Image.load()`.
- `sprites/`: 3,054 decoded PNGs loaded into `ImageTexture` at runtime.
- `anm/`: 433 JSONs containing the frame/state timings.
- `wav/`: 119 `11025Hz` raw audio samples loaded into `AudioStreamWAV`.
- `part-name-catalog.json`: Metadata mapping part types to their ANM files.

## 2.4 The Visual Shell (`res://frontend/`)

The frontend consists of standard Godot Nodes (`Node2D`, `Sprite2D`, `AudioStreamPlayer`) that read from `backend/WorldState` every `_physics_process` and update their visual state. They contain absolutely no gameplay or physics logic.

### Recommended Scene Tree
```text
MainGame (Node2D, Script: GameRenderer.gd)
 ├─ Camera2D (Viewport zoom and scroll)
 ├─ Background (TextureRect)
 ├─ PartsContainer (Node2D)
 │  ├─ PartView_0 (Node2D, Script: ANMPlayer.gd)
 │  │  └─ Sprite2D
 │  ├─ PartView_1 (Node2D, Script: ANMPlayer.gd)
 │  │  └─ Sprite2D
 │  └─ ...
 ├─ AudioDispatcher (Node, Script: AudioDispatcher.gd)
 │  ├─ AudioStreamPlayer (Pool of channels)
 │  └─ ...
 └─ UILayer (CanvasLayer)
    └─ Control (Editor toolbar, Catalog panel, Dialogs)
```
