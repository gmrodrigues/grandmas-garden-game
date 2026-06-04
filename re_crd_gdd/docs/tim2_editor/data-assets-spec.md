# TIM2 Editor — Bundled Asset Structure

## Purpose

The editor reads all assets from `tim2_editor/data/`, making it fully
self-contained with no dependency on the `build/` output directory.

## Directory Layout

```
tim2_editor/data/
  sprites/                # 3,054 PNG files — decoded sprite frames
    PART0_f000.png         (from build/phase-3/bitmaps/)
    PART0_f001.png
    ...
  anm/                    # 433 JSON files — ANM animation descriptors
    PART0.json             (from build/phase-4/anm/)
    PART1.json
    ...
  wav/                    # 119 WAV files — sound effects
    SX_0_11025.wav         (from build/phase-6/raw-wav/)
    SX_1_11025.wav
    ...
  palettes/               # 56 JSON files — game palettes
    PARTTEMP.json          (from build/phase-3/palettes/)
    TIM2.json
    ...
  part-name-catalog.json  # Part metadata (names, categories, ANM mapping)
                           (from build/phase-9/part-name-catalog.json)
```

## Path Resolution at Runtime

All paths are constructed relative to `DATA_DIR`, which is:

```python
DATA_DIR = ROOT / "tim2_editor" / "data"
ROOT = Path(__file__).resolve().parent.parent
# ROOT = tim2_editor/../ = project root
```

| Constant / Variable | Resolved path |
|---|---|
| `DATA_DIR` | `$PROJECT/tim2_editor/data/` |
| `self.bmp_dir` | `$DATA_DIR/sprites/` |
| `anm_dir` | `$DATA_DIR/anm/` |
| `wav_dir` | `$DATA_DIR/wav/` |
| `palette_dir` | `$DATA_DIR/palettes/` |
| `part_name_path` | `$DATA_DIR/part-name-catalog.json` |
| `PART_CATALOG_PATH` | `$DATA_DIR/part-name-catalog.json` |

The `AnmRenderer._load_palette()` fallback (when `palette_dir` is not passed)
resolves relative to its own `__file__`:

```python
Path(__file__).resolve().parent.parent / "data" / "palettes"
# = tim2_editor/data/palettes/
```

## Origin of Assets

All assets are copied from the reverse-engineering build pipeline outputs:

| Data directory | Source | Files |
|---|---|---|
| `sprites/` | `build/phase-3/bitmaps/` | Decoded BMP sprites as PNG |
| `anm/` | `build/phase-4/anm/` | ANM animation bytecode parsed to JSON |
| `wav/` | `build/phase-6/raw-wav/` | Raw audio samples converted to WAV |
| `palettes/` | `build/phase-3/palettes/` | VGA palette JSON files |
| `part-name-catalog.json` | `build/phase-9/part-name-catalog.json` | Part type metadata |

## Regeneration

To refresh the bundled assets after the build pipeline produces updated files:

```bash
cp -a build/phase-3/bitmaps/. tim2_editor/data/sprites/
cp -a build/phase-4/anm/.     tim2_editor/data/anm/
cp -a build/phase-6/raw-wav/. tim2_editor/data/wav/
cp -a build/phase-3/palettes/. tim2_editor/data/palettes/
cp build/phase-9/part-name-catalog.json tim2_editor/data/
```

## Versioning

`tim2_editor/data/` is versioned in the repository. This ensures the editor
starts up without any external build step.
