import os
import re

input_files = [
    "index.md", "01_pitch_and_vision.md", "02_core_mechanics.md", "03_part_catalog.md",
    "04_ui_ux_and_controls.md", "05_level_design.md", "06_art_and_audio.md", "07_modern_features.md",
    "08_detailed_parts_catalog.md", "09_detailed_level_catalog.md", "10_user_journeys.md",
    "11_godot_editor_specification.md", "12_asset_production_guide.md"
]

content = ""
for f in input_files:
    if os.path.exists(f):
        with open(f, 'r') as fp:
            content += fp.read() + "\n\n"

def replace_image(match):
    alt = match.group(1)
    path = match.group(2)
    # resolve relative to docs/clean_room_gdd/
    abs_path = os.path.abspath(path)
    if not os.path.exists(abs_path):
        return f"![{alt}](../../build/phase-3/bitmaps/BLANK.png)"
    return match.group(0)

# Replace images
content = re.sub(r'!\[([^\]]*)\]\(([^)]+)\)', replace_image, content)

with open('compiled.md', 'w') as fp:
    fp.write(content)

os.system('pandoc compiled.md -o ../Clean_Room_GDD.pdf --pdf-engine=typst --pdf-engine-opt=--root=/home/glauber/gmrodrigues.github.com/the-incredible-machine-2-reverse-engineering')
