#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
ARQUITETURA_DIR="$SCRIPT_DIR/arquitetura"
MAIN="$ARQUITETURA_DIR/arquitetura.md"
OUTPUT="$ARQUITETURA_DIR/arquitetura.pdf"
TMP_MD="/tmp/arquitetura_for_pdf.md"

FA_DIAGRAMS="$ARQUITETURA_DIR/diagrams"

# Check prerequisites
command -v pandoc >/dev/null 2>&1 || { echo "ERROR: pandoc not found"; exit 1; }
command -v plantuml >/dev/null 2>&1 || { echo "ERROR: plantuml not found"; exit 1; }
command -v typst >/dev/null 2>&1 || { echo "ERROR: typst not found"; exit 1; }

echo "=== Gerando diagramas PNG ==="
cd "$FA_DIAGRAMS"
rm -f *.png
plantuml -DRELATIVE_INCLUDE="." -o . -png *.puml 2>&1 | grep -E "^Error" | head -5 || true
echo "  PNGs gerados: $(ls *.png | wc -l)"

echo "=== Preparando markdown ==="
cd "$ARQUITETURA_DIR"
python3 -c "
import re

with open('arquitetura.md', encoding='utf-8') as f:
    content = f.read()

# Remove plantuml code blocks
content = re.sub(r'\x60\x60\x60plantuml.*?\x60\x60\x60', '', content, flags=re.DOTALL)

# Fix em dash
content = content.replace('\u2014', '---')

# Fix fancy quotes
content = content.replace('\u2018', \"'\")
content = content.replace('\u2019', \"'\")
content = content.replace('\u201c', '\"')
content = content.replace('\u201d', '\"')

# Remove manual TOC (lines from ## Sumário to the end of the TOC list)
content = re.sub(
    r'## Sumário\n\n.*?(\n\n---\n\n)',
    r'\1',
    content,
    flags=re.DOTALL
)

# Add YAML metadata header for proper PDF formatting
header = '''---
title: \"Arquitetura do Jogo - Grandmas Garden\"
---

'''

content = header + content

with open('$TMP_MD', 'w', encoding='utf-8') as f:
    f.write(content)
print('  OK: PlantUML blocks removed, metadata added')
"

echo "=== Gerando PDF (pandoc + typst) ==="
cd "$ARQUITETURA_DIR"
pandoc "$TMP_MD" \
    --to=pdf \
    --pdf-engine=typst \
    --toc \
    --toc-depth=2 \
    --output="$OUTPUT" \
    --resource-path="$ARQUITETURA_DIR:$FA_DIAGRAMS" \
    --variable=mainfont:"DejaVu Sans Mono" \
    2>&1 || {
        echo ""
        echo "AVISO: PDF via typst falhou. Tentando alternativa (pandoc -> typst -> compilação direta)..."
        cd "$ARQUITETURA_DIR"
        pandoc "$TMP_MD" \
            --to=typst \
            --toc \
            --toc-depth=2 \
            --output="/tmp/arquitetura.typ" \
            --resource-path="$ARQUITETURA_DIR:$FA_DIAGRAMS" \
            --variable=mainfont:"DejaVu Sans Mono" \
            2>&1
        echo "Compilando typst diretamente..."
        typst compile --font-path /usr/share/fonts "/tmp/arquitetura.typ" "$OUTPUT" 2>&1
    }

echo ""
echo "=== PDF gerado ==="
ls -lh "$OUTPUT"
