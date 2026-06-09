import markdown
import weasyprint
import os
import re
import glob

# Ensure we are in the correct directory if run from another place
script_dir = os.path.dirname(os.path.abspath(__file__))
if script_dir:
    os.chdir(script_dir)

def slugify(text):
    text = text.lower()
    text = re.sub(r'[^\w\s-]', '', text)
    text = re.sub(r'[\s]+', '-', text.strip())
    return text

def insert_heading_anchors(markdown_content):
    lines = markdown_content.split('\n')
    result = []
    for line in lines:
        m = re.match(r'^(#{1,3})\s+(.+)$', line)
        if m:
            slug = slugify(m.group(2))
            result.append(f'<a id="{slug}"></a>')
            result.append(line)
        else:
            result.append(line)
    return '\n'.join(result)

def inject_heading_ids(html):
    def replace(m):
        level = int(m.group(1))
        text = m.group(2).strip()
        slug = slugify(text)
        return f'<h{level} id="{slug}">{text}</h{level}>'
    return re.sub(r'<h([1-6])>([^<]+)</h\1>', replace, html)

input_files = [
    "index.md", "01_pitch_and_vision.md", "02_core_mechanics.md", "03_part_catalog.md",
    "04_ui_ux_and_controls.md", "05_level_design.md", "06_art_and_audio.md", "07_modern_features.md",
    "08_detailed_parts_catalog.md", "09_detailed_level_catalog.md", "10_user_journeys.md",
    "11_godot_editor_specification.md", "12_asset_production_guide.md", "13_technical_specifications.md",
    "14_part_editor_behaviors.md",     "15_behavioral_specification.md"
]

content = ""
for f in input_files:
    if os.path.exists(f):
        with open(f, "r", encoding="utf-8") as fp:
            file_content = fp.read()
        content += f"<a id=\"{f}\"></a>\n\n"
        content += file_content + "\n\n"

# (Part specs and compliance are merged directly into chapter 8)

# Insert anchor tags before all headings
content = insert_heading_anchors(content)

# Rewrite cross-references to use anchors
for f in input_files:
    def rewrite_link(match, filename=f):
        fragment = match.group(1)
        if fragment:
            anchor = fragment[1:]
            slug = slugify(anchor)
            return f"](#{slug})"
        else:
            return f"](#{filename})"
    content = re.sub(
        r"\]\((?:\./)?" + re.escape(f) + r"(#[^\)]*)?\)",
        rewrite_link,
        content
    )

def get_best_image(alt_text, original_path):
    abs_path = os.path.abspath(original_path)
    if os.path.exists(abs_path):
        return f"![{alt_text}]({original_path})"
        
    p2 = original_path.replace("_f000", "")
    if os.path.exists(os.path.abspath(p2)):
        return f"![{alt_text}]({p2})"
        
    part_match = re.search(r"PART(\d+)", original_path)
    if part_match:
        part_id = part_match.group(1)
        p3 = f"../../scenery-review/PART{part_id}.png"
        if os.path.exists(os.path.abspath(p3)):
            return f"![{alt_text}]({p3})"
            
        matches = glob.glob(f"../../build/phase-3/bitmaps/PART{part_id}*.png")
        if matches:
            matches.sort(key=len)
            return f"![{alt_text}]({matches[0]})"
            
    return f"![{alt_text}](../../build/phase-3/bitmaps/BLANK.png)"

content = re.sub(r"\!\[([^\]]*)\]\(([^\)]+)\)", lambda m: get_best_image(m.group(1), m.group(2)), content)

html = markdown.markdown(content, extensions=["tables", "fenced_code"])
html = inject_heading_ids(html)
html = f"""
<html><head>
<meta charset="utf-8">
<style>
@page {{ margin: 1cm; }}
body {{ font-family: sans-serif; line-height: 1.3; font-size: 10pt; }}
img {{ width: 24px; height: 24px; object-fit: contain; vertical-align: middle; image-rendering: pixelated; display: inline-block; }}
table {{ border-collapse: collapse; width: 100%; font-size: 9pt; }}
th, td {{ border: 1px solid #ccc; padding: 4px; text-align: left; }}
h1, h2, h3, h4, h5 {{ color: #333; margin-top: 1em; margin-bottom: 0.5em; }}
h1 {{ font-size: 13pt; font-weight: bold; border-bottom: 1px solid #ddd; padding-bottom: 2px; }}
h2 {{ font-size: 12pt; font-weight: bold; }}
h3, h4, h5 {{ font-size: 11pt; font-weight: bold; }}
pre {{ background-color: #f4f4f4; padding: 8px; font-size: 9pt; white-space: pre-wrap; }}
code {{ font-size: 9pt; background-color: #f4f4f4; padding: 2px; }}
a {{ color: #0366d6; text-decoration: none; }}
ul, ol {{ margin-top: 0.5em; margin-bottom: 0.5em; padding-left: 20px; }}
li {{ margin-bottom: 2px; }}
</style></head>
<body>{html}</body></html>
"""

with open("compiled.html", "w", encoding="utf-8") as fp:
    fp.write(html)

try:
    weasyprint.HTML(filename="compiled.html", base_url=".").write_pdf("../Clean_Room_GDD.pdf")
    print("PDF generated successfully at ../Clean_Room_GDD.pdf")
except Exception as e:
    print(f"ERROR generating PDF: {e}")
    print("compiled.html was still generated for inspection.")
