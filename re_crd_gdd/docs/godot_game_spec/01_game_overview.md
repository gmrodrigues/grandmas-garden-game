# 1. Game Overview & Core Loop

**The Incredible Machine 2 (TIM2)** is a deterministic, 2D physics-based puzzle game where players construct Rube Goldberg machines using a variety of whimsical parts (balls, motors, lasers, animals, explosives) to achieve specific goals.

## 1.1 The Core Loop
1. **Briefing**: The player is presented with a half-built machine, a goal (e.g., "Put the basketball in the hoop"), and a limited palette of parts.
2. **Construction (Editor Mode)**: The player places, rotates, flips, and connects parts on a 16x16 grid. Gravity and physics are paused.
3. **Simulation (Play Mode)**: The player starts the simulation. The deterministic physics engine runs at a fixed 60Hz. Parts interact according to rigid physical rules.
4. **Resolution**: 
   - If the goal conditions are met, the puzzle is solved.
   - If not, the player stops the simulation, returning to the exact Construction state to tweak their design.

## 1.2 Game Modes

| Mode | Canvas Size | Description |
|------|-------------|-------------|
| **Main Menu** | 672×377 | The hub screen navigating to all game modes. |
| **Puzzle Select** | 640×400 | Categorized lists of built-in puzzles (Tutorial, Easy, Medium, Hard, Expert). |
| **Play / Editor** | 640×400 | The primary gameplay screen containing the 560x377 viewport and the side toolbars. |
| **Head-to-Head** | 639×399 | A two-player hot-seat mode where players take turns building machines to solve a puzzle faster or with fewer parts. |

## 1.3 Mechanics Overview

The entire game relies on absolute determinism. A machine must play out exactly the same way every time it is run.
- **Gravity**: Applies constant downward acceleration to "moving" parts.
- **Collisions**: Bouncing based on AABB overlaps and Coefficients of Restitution (COR).
- **Constraints**: Ropes and belts transfer force and rotation between parts.
- **States**: Every part has an internal state machine dictating its visual and physical behavior (Idle, Active, Broken, etc.).

## 1.4 Editor Flow

- **Select / Move**: Drag parts around.
- **Rotate / Flip**: Mirror parts horizontally/vertically or rotate in 90-degree increments.
- **Connect**: Draw belts between pulleys or wires between electrical nodes.
- **Delete**: Remove parts from the canvas.
- **Catalog Panel**: Located on the right side of the screen, it provides categorized tabs to browse and select parts to drag onto the playfield.
