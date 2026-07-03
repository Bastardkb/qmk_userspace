#!/usr/bin/env bash
# Regenerate docs/keymap.svg from docs/keymap.yaml using keymap-drawer.
#
#   pip install keymap-drawer      # one-time
#   docs/draw.sh
#
# keymap.yaml is the hand-curated source for the diagram (nice layer names,
# combos, icons). To instead re-derive layers straight from keymap.c:
#   qmk c2json -kb bastardkb/charybdis/3x5 -km vendor > /tmp/km.json
#   keymap parse -q /tmp/km.json > docs/keymap.yaml   # loses code-defined combos
set -euo pipefail
cd "$(dirname "$0")/.."
keymap draw --qmk-info-json docs/charybdis_3x5.info.json docs/keymap.yaml > docs/keymap.svg
echo "wrote docs/keymap.svg"
