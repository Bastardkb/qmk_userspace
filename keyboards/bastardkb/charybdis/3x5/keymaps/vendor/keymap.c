/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Personal Charybdis Nano (3x5) keymap.
 *
 * Reconstructed from an Argos configurator export
 * (input/argos_config-export.json).  Same 7-layer scheme as the stock
 * vendor keymap, but with a personalised base layer:
 *   - Home row holds LAYER-taps (not mods): the ten home keys each drop
 *     into a layer when held.
 *   - Bottom row holds MOD-taps (GACS split across both hands).
 *   - Mouse buttons live on the thumbs / navigation layer.
 */
#include QMK_KEYBOARD_H

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_FUNCTION,
    LAYER_NAVIGATION,
    LAYER_MEDIA,
    LAYER_POINTER,
    LAYER_NUMERAL,
    LAYER_SYMBOLS,
};

// Automatically enable sniping-mode on the pointer layer.
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DRG_TOG KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// Home-row layer-taps (tap = letter, hold = layer).
#define HR_A LT(LAYER_FUNCTION,   KC_A)
#define HR_S LT(LAYER_NUMERAL,    KC_S)
#define HR_D LT(LAYER_SYMBOLS,    KC_D)
#define HR_F LT(LAYER_NAVIGATION, KC_F)
#define HR_G LT(LAYER_POINTER,    KC_G)
#define HR_H LT(LAYER_POINTER,    KC_H)
#define HR_J LT(LAYER_NAVIGATION, KC_J)
#define HR_K LT(LAYER_SYMBOLS,    KC_K)
#define HR_L LT(LAYER_NUMERAL,    KC_L)
#define HR_P LT(LAYER_FUNCTION,   KC_P)
// Right pinky top: tap = Esc, hold = media layer.
#define ESC_MED LT(LAYER_MEDIA, KC_ESC)
// Right inner thumb: hold = Left Alt, tap = Gui+F12.
// The placeholder tap (F12) is remapped to Gui+F12 in process_record_user,
// since a mod-tap can only carry a basic keycode.
#define ALT_F12 LALT_T(KC_F12)
// Hold to drag-scroll the trackball; tap types the letter/symbol. LT(0, ...) is
// just a tap/hold carrier: layer 0 is base, so its "hold" is a no-op that we
// override in process_record_user to toggle drag-scroll instead.
#define Z_SCR LT(0, KC_Z)
#define SLSH_SCR LT(0, KC_SLSH)

// Bottom-row mod-taps (tap = letter, hold = modifier).
#define MT_X LGUI_T(KC_X)
#define MT_C LALT_T(KC_C)
#define MT_V LSFT_T(KC_V)
// Right-hand mods use the RIGHT-hand modifiers for clean cross-hand chording
// (the export used left-hand mods here; switched to R* variants).
#define MT_M RCTL_T(KC_M)
#define MT_COMM RALT_T(KC_COMM)
#define MT_DOT RGUI_T(KC_DOT)

// clang-format off
/**
 * \brief Base layer.
 *
 *   Q     W     E     R     T          Y     U     I     O   Esc/media
 *   A     S     D     F     G          H     J     K     L     P        (home-row layer-taps)
 *   Z     X     C     V     B          N     M     ,     .     /        (bottom-row mod-taps)
 *            Ctl  Gui/Spc Btn1     Alt/Gui+F12  Sft
 *
 * Z and / drag-scroll the trackball when held (tap still types z / '/').
 */
#define LAYOUT_LAYER_BASE                                                             \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O, ESC_MED, \
       HR_A,    HR_S,    HR_D,    HR_F,    HR_G,    HR_H,    HR_J,    HR_K,    HR_L,    HR_P, \
      Z_SCR,    MT_X,    MT_C,    MT_V,    KC_B,    KC_N,    MT_M, MT_COMM,  MT_DOT, SLSH_SCR, \
                     OSM(MOD_LCTL), LGUI_T(KC_SPC), KC_BTN1, ALT_F12, OSM(MOD_LSFT)

/**
 * \brief Function layer (mostly unused for now — extend as needed).
 */
#define LAYOUT_LAYER_FUNCTION                                                                 \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_LLCK, \
                      _______, RM_PREV, _______, TO(LAYER_BASE), _______

/**
 * \brief Navigation layer.
 *
 * Arrows form an inverted-T on the right home cluster; editing/clipboard extras
 * around them.  Left-hand thumbs expose sniping / drag-scroll / right-click.
 */
#define LAYOUT_LAYER_NAVIGATION                                                               \
    _______,  KC_ESC, LCTL(LGUI(KC_SPC)), _______, _______, _______, _______,   KC_UP, KC_BSPC, _______, \
     KC_TAB, KC_LCTL, KC_LALT, KC_PSCR, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT, \
    _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______, QK_LLCK, \
                      SNIPING, DRG_TOG, KC_BTN2, TO(LAYER_BASE), _______

/**
 * \brief Media / RGB layer (left-hand cluster, for the right-hand trackball).
 */
#define LAYOUT_LAYER_MEDIA                                                                    \
    _______, RM_HUED, RM_PREV, RM_HUEU, _______, _______, _______, _______, _______, _______, \
    _______, KC_MPLY, KC_MPRV, KC_MSTP, _______, _______, _______, _______, _______, _______, \
    XXXXXXX, XXXXXXX, KC_MUTE, KC_MNXT, _______, _______, _______, _______, _______, _______, \
                      _______, _______, _______, _______, _______

/**
 * \brief Pointer layer (reset keys in the corners; mouse keys live elsewhere).
 */
#define LAYOUT_LAYER_POINTER                                                                  \
    QK_BOOT,  EE_CLR, _______, _______, _______, _______, _______, _______,  EE_CLR, QK_BOOT, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                      _______, _______, _______, _______, _______

/**
 * \brief Numeral layer.
 *
 * Numpad-style digits on the right hand; assorted symbols on the left.
 */
#define LAYOUT_LAYER_NUMERAL                                                                  \
    _______,  KC_DLR, LALT(KC_2), KC_PLUS, _______, _______,    KC_7,    KC_8,    KC_9, _______, \
     KC_TAB, KC_ASTR, KC_COLN, KC_MINS, _______,    KC_0,    KC_4,    KC_5,    KC_6, KC_PENT, \
    _______, _______, KC_PERC,  KC_EQL, _______, _______,    KC_1,    KC_2,    KC_3, QK_LLCK, \
                      _______, _______, _______, TO(LAYER_BASE), _______

/**
 * \brief Symbols layer.
 */
#define LAYOUT_LAYER_SYMBOLS                                                                  \
    _______, KC_CIRC, KC_AMPR, KC_TILD, _______, _______, KC_LBRC, KC_RBRC, KC_EXLM, _______, \
    KC_SLSH,  KC_GRV, KC_DQUO, KC_QUOT, _______, _______, KC_LPRN, KC_RPRN, KC_QUES, _______, \
    _______, KC_BSLS, KC_UNDS, KC_PIPE, _______, _______, KC_HASH,   KC_AT, KC_SCLN, QK_LLCK, \
                      _______,  KC_SPC, _______, TO(LAYER_BASE), _______

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE]       = LAYOUT_wrapper(LAYOUT_LAYER_BASE),
  [LAYER_FUNCTION]   = LAYOUT_wrapper(LAYOUT_LAYER_FUNCTION),
  [LAYER_NAVIGATION] = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION),
  [LAYER_MEDIA]      = LAYOUT_wrapper(LAYOUT_LAYER_MEDIA),
  [LAYER_POINTER]    = LAYOUT_wrapper(LAYOUT_LAYER_POINTER),
  [LAYER_NUMERAL]    = LAYOUT_wrapper(LAYOUT_LAYER_NUMERAL),
  [LAYER_SYMBOLS]    = LAYOUT_wrapper(LAYOUT_LAYER_SYMBOLS),
};
// clang-format on

#ifdef COMBO_ENABLE
// Combos, transcribed from the Argos export.  They fire on the *base* keycodes,
// so mod-tap/layer-tap wrappers must be spelled out in full.
enum combos {
    COMBO_CV_ENT,   // C + V           -> Enter
    COMBO_XC_TAB,   // X + C           -> Tab
    COMBO_QW_BSPC,  // Q + W           -> Backspace
};

const uint16_t PROGMEM combo_cv[] = {MT_C, MT_V, COMBO_END};
const uint16_t PROGMEM combo_xc[] = {MT_X, MT_C, COMBO_END};
const uint16_t PROGMEM combo_qw[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[] = {
    [COMBO_CV_ENT]  = COMBO(combo_cv, KC_ENT),
    [COMBO_XC_TAB]  = COMBO(combo_xc, KC_TAB),
    [COMBO_QW_BSPC] = COMBO(combo_qw, KC_BSPC),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);
#endif // COMBO_ENABLE

// Remap the tap of the right inner thumb (ALT_F12) to Gui+F12; hold stays Alt.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_F12:
            if (record->tap.count && record->event.pressed) {
                tap_code16(LGUI(KC_F12));
                return false;
            }
            break;
        case Z_SCR:
        case SLSH_SCR:
            if (record->tap.count == 0) {  // held -> drag-scroll
#ifdef POINTING_DEVICE_ENABLE
                charybdis_set_pointer_dragscroll_enabled(record->event.pressed);
#endif
                return false;
            }
            return true;  // tapped -> z / '/'
    }
    return true;
}

#ifdef POINTING_DEVICE_ENABLE
#    include <math.h>

// Trackball acceleration. Movement up to ACCEL_OFFSET counts/report is left 1:1
// for precision; faster motion is scaled up linearly (ACCEL_GROWTH per extra
// count) and capped at ACCEL_LIMIT x. Drag-scroll is unaffected (it already
// zeroes x/y before this runs) and sniping is skipped to stay precise.
// Requires MOUSE_EXTENDED_REPORT so scaled deltas aren't clamped to +/-127.
//
// Tuning: lower ACCEL_OFFSET to engage sooner, raise ACCEL_GROWTH for a steeper
// ramp, raise ACCEL_LIMIT for a higher top speed.
#    ifndef ACCEL_OFFSET
#        define ACCEL_OFFSET 1.5f
#    endif
#    ifndef ACCEL_GROWTH
#        define ACCEL_GROWTH 0.50f
#    endif
#    ifndef ACCEL_LIMIT
#        define ACCEL_LIMIT 15.0f
#    endif

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if ((mouse_report.x != 0 || mouse_report.y != 0) && !charybdis_get_pointer_sniping_enabled()) {
        const float x         = mouse_report.x;
        const float y         = mouse_report.y;
        const float magnitude = sqrtf(x * x + y * y);
        if (magnitude > ACCEL_OFFSET) {
            float factor = 1.0f + ACCEL_GROWTH * (magnitude - ACCEL_OFFSET);
            if (factor > ACCEL_LIMIT) {
                factor = ACCEL_LIMIT;
            }
            mouse_report.x = (mouse_xy_report_t)(x * factor);
            mouse_report.y = (mouse_xy_report_t)(y * factor);
        }
    }

#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

    return mouse_report;
}

#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in
// rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
