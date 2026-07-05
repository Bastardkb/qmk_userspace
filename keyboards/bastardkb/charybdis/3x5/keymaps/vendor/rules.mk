# VIA disabled: the compiled keymap.c is the single source of truth. With VIA
# on, the active keymap is served from EEPROM and code edits are ignored until
# an EE_CLR, which made flashed layer changes silently no-op.
VIA_ENABLE = no
COMBO_ENABLE = yes
LAYER_LOCK_ENABLE = yes
