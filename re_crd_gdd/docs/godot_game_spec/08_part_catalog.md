# 8. Part Catalog

The catalog defines the 149 distinct part types available in the game. Each part is governed by property definitions defining its mass, Coefficient of Restitution (COR), and collision rects.

## 8.1 Property Sources

- **Names & UI Descriptions**: `INFO.RES`
- **Alternate Names & State Machines**: `SOLVE.RES`
- **Physics Constants**: `PART{N}.PAR` (Chunked containers holding payload arrays).
  - Contains Mass/Density.
  - Contains COR (Coefficient of Restitution) in Q8.8 fixed-point format.
  - Contains Width/Height AABB padding.

## 8.2 Category Breakdown

1. **Balls (9)**: Bowling Ball (Low COR), Super Ball (High COR), Programmable Ball.
2. **Walls/Floors (11)**: Brick, Wood, Pipe, Sand.
3. **Inclines (6)**: Variable friction slopes.
4. **Rotating Power Sources (6)**: Motors, Windmills, Gears.
5. **Electrical (9)**: Outlets, Switches, Mixers, Fans.
6. **Lasers / Optics (6)**: Red/Green/Blue Lasers, Mirrors, Detectors.
7. **Ropes / Belts / Pulleys (4)**: Distance constraint links.
8. **Cutting / Popping (3)**: Scissors, Tacks.
9. **Explosives / Projectiles (6)**: Dynamite, Rockets, Missiles.
10. **Characters (6)**: Mice, Cats, Alligators.
11. **Containers (5)**: Baskets, Buckets, Fish Tanks.
12. **Springs / Pneumatics (4)**: Springboards, Flippers.
13. **Balloons / Airships (3)**: Float upwards based on Pressure.
14. **Light / Flame Sources (5)**: Flashlights, Candles, Matches.
15. **Scenery (30)**: Background decorations.

## 8.3 Machine-Readable Data
In Godot, these are loaded from `res://data/part-properties.json` and `res://data/part-name-catalog.json`.
