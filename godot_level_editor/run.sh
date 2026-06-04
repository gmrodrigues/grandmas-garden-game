#!/usr/bin/env bash
set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
GODOT="$PROJECT_DIR/../Godot_v4.6.3-stable_linux.x86_64"

if [ ! -f "$GODOT" ]; then
  echo "Error: Godot binary not found at $GODOT" >&2
  exit 1
fi

if [ $# -eq 0 ]; then
  exec "$GODOT" --path "$PROJECT_DIR"
fi

LEVEL="$1"
if [[ "$LEVEL" != res://* && "$LEVEL" != /* ]]; then
  LEVEL="res://build/$LEVEL"
fi

exec "$GODOT" --path "$PROJECT_DIR" --level "$LEVEL"