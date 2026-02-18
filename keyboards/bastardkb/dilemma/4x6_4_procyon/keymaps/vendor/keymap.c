/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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
#include QMK_KEYBOARD_H

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
};

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#define LOWER   MO(LAYER_LOWER)
#define RAISE   MO(LAYER_RAISE)
#define PT_Z    MT(MOD_LALT, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)
#define RAISE_N LT(LAYER_RAISE, KC_N)

enum tap_dance_ids { TD_SHIFT_CAPS };

static void shift_caps_tap_each(qk_tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        register_code(KC_LSFT);
    }
}

static void shift_caps_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code(KC_CAPS);
    }
}

static void shift_caps_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LSFT);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(shift_caps_tap_each, shift_caps_finished, shift_caps_reset),
};

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
     TD(TD_SHIFT_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL,    PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,     RAISE_N,   KC_M, KC_COMM,  KC_DOT, PT_SLSH, KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                          KC_SPC,   LOWER, KC_LGUI,   RAISE,    KC_BSPC,  KC_ENT, KC_RGUI,   RAISE
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RALT(KC_LBRC), RALT(KC_RBRC),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RALT(KC_QUOT), RALT(KC_BSLS),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUBS,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX, _______,    XXXXXXX, XXXXXXX, XXXXXXX, _______
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LEFT,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_PAST, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
     TD(TD_SHIFT_CAPS), XXXXXXX, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,   KC_MUTE, KC_PPLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_LALT, KC_LGUI, KC_LCTL, KC_BSPC,    _______, KC_RCTL, KC_RGUI, KC_RALT
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_RALT, KC_RGUI, XXXXXXX, S_D_MOD, DPI_MOD, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD,   SNIPING, _______, XXXXXXX, XXXXXXX, KC_RSFT, KC_RCTL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       S_D_MOD, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   MS_BTN1, MS_BTN2, XXXXXXX, QK_BOOT, EE_CLR,  DRGSCRL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, SNIPING, DRGSCRL, EE_CLR,  QK_BOOT,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN3, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, MS_BTN2, MS_BTN1, MS_BTN3,    XXXXXXX, _______, SNIPING, DRGSCRL
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
#    ifdef POINTING_DEVICE_SPEED_DIVISOR
    mouse_report.x = (int8_t)((int16_t)mouse_report.x / POINTING_DEVICE_SPEED_DIVISOR);
    mouse_report.y = (int8_t)((int16_t)mouse_report.y / POINTING_DEVICE_SPEED_DIVISOR);
#    endif
#    ifdef POINTING_DEVICE_SCROLL_INVERT
    mouse_report.v = -mouse_report.v;
    mouse_report.h = -mouse_report.h;
#    endif
    return mouse_report;
}
#endif // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif // RGB_MATRIX_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]    = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [LAYER_LOWER]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_RAISE]   = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_POINTER] = {ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE
