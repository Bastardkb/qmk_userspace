# Keymap visualization

Visual references for the Charybdis Nano (`bastardkb/charybdis/3x5`) `vendor` keymap.

| File | What |
|------|------|
| [`keymap.svg`](keymap.svg) | Rendered diagram of all 7 layers + combos (open in a browser) |
| [`keymap.md`](keymap.md) | ASCII-art version of every layer |
| `keymap.yaml` | [keymap-drawer](https://github.com/caksoylar/keymap-drawer) source for the SVG |
| `charybdis_3x5.info.json` | Physical layout geometry used for drawing |

## Regenerate

The SVG is produced with **keymap-drawer**:

```sh
pip install keymap-drawer
./docs/draw.sh
```

`keymap.yaml` is the hand-curated diagram source (readable layer names, the four
combos, arrow/media icons). Edit it when the layout changes, then re-run
`draw.sh`. See the comments in `draw.sh` for how to instead re-derive the layers
directly from `keymap.c` via `qmk c2json` + `keymap parse`.

The `keymap.md` ASCII view is generated from the original Argos export
(`../input/argos_config-export.json`).
