/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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
#include "os_detection.h"

enum layers {
    _BASE = 0,
    _NAV = 2,
    _SYM = 3,
};

enum custom_keycodes {
    SEL_LINE = QK_USER,
    OS_UNDO,
    OS_CUT,
    OS_COPY,
    OS_PASTE,
    OS_REDO,
    OS_APPN,
    OS_APPP,
    OS_WRDL,
    OS_WRDR,
    OS_SWDL,
    OS_SWDR,
};

enum tap_dances {
    TD_NAV_SYM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_4x6_5(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TG(1),
        KC_ESC, KC_K,    KC_H,    KC_C,    KC_D,    KC_W,             S(KC_SLSH), KC_U,    KC_O,    KC_Y,    KC_Q,    KC_BSLS,
        KC_TAB, LCTL_T(KC_L),    LALT_T(KC_N),    LGUI_T(KC_S),    LSFT_T(KC_T),    KC_G,             KC_J, LSFT_T(KC_A),    LGUI_T(KC_E),    LALT_T(KC_I),    LCTL_T(KC_P),    S(KC_QUOT),
        KC_CAPS, KC_V,    KC_B,    KC_F,    KC_M,    KC_X,             KC_MINS, KC_QUOT,  KC_COMM, KC_DOT, KC_Z,  KC_TRNS,
                             MO(2), LT(3, KC_R), KC_TAB, KC_ENT, KC_SPC, KC_BSPC, KC_SPC, KC_ESC, CW_TOGG, KC_TRNS
    ),

    [1] = LAYOUT_split_4x6_5(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F,    KC_P,    KC_D,    KC_L,    KC_X,             KC_SCLN, KC_U,    KC_O,    KC_Y,    KC_B,    KC_Z,
        KC_TRNS, LCTL_T(KC_S),    LALT_T(KC_N),    LGUI_T(KC_T),    LSFT_T(KC_H),    KC_K,             KC_QUOT, LSFT_T(KC_A),    LGUI_T(KC_E),    LALT_T(KC_I),    LCTL_T(KC_C),    KC_Q,
        KC_TRNS, KC_V,    KC_W,    KC_G,    KC_M,    KC_J,             KC_EQL, KC_MINS,  KC_COMM, KC_DOT, KC_SLSH,  KC_TRNS,
                             KC_TRNS, LT(2, KC_R), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT_split_4x6_5(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, C(S(KC_TAB)), C(KC_TAB), OS_APPP, OS_APPN, KC_TRNS,   KC_TRNS, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_TRNS,
        KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TRNS,          SEL_LINE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, EE_CLR,
        KC_TRNS, OS_UNDO, OS_CUT,  OS_COPY, OS_PASTE, OS_REDO,         OS_WRDL, A(KC_BSPC), A(KC_DEL), OS_WRDR, KC_DEL, QK_BOOT,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [3] = LAYOUT_split_4x6_5(
        KC_TRNS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),          S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_TRNS,
        KC_TRNS, S(KC_6), S(KC_LBRC), S(KC_MINS), S(KC_RBRC), S(KC_SCLN), S(KC_7), S(KC_SLSH), KC_UP, S(KC_BSLS), KC_BSLS, KC_TRNS,
        KC_TRNS, KC_LCTL, LALT_T(KC_LBRC), LGUI_T(KC_EQL), LSFT_T(KC_RBRC), KC_GRV, S(KC_GRV), KC_LEFT, KC_DOWN, KC_RIGHT, KC_SCLN, KC_TRNS,
        KC_TRNS, S(KC_6), S(KC_COMM), KC_MINS, S(KC_DOT), KC_BSLS,       KC_TRNS, S(KC_9), S(KC_EQUAL), S(KC_0), KC_SLSH, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_4x6_5(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
             '*', '*', '*', '*','*','*','*','*', '*', '*'
    );


static bool is_mac(void) {
    os_variant_t os = detected_host_os();
    return os == OS_MACOS || os == OS_IOS;
}

static bool app_switcher_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SEL_LINE:
            if (record->event.pressed) {
                if (is_mac()) {
                    tap_code16(G(KC_LEFT));
                    tap_code16(G(S(KC_RIGHT)));
                } else {
                    tap_code(KC_HOME);
                    tap_code16(S(KC_END));
                }
            }
            return false;
        case OS_UNDO:
            if (record->event.pressed) {
                tap_code16(is_mac() ? G(KC_Z) : C(KC_Z));
            }
            return false;
        case OS_REDO:
            if (record->event.pressed) {
                if (is_mac()) {
                    tap_code16(G(S(KC_Z)));
                } else {
                    tap_code16(C(KC_Y));
                }
            }
            return false;
        case OS_CUT:
            if (record->event.pressed) {
                tap_code16(is_mac() ? G(KC_X) : C(KC_X));
            }
            return false;
        case OS_COPY:
            if (record->event.pressed) {
                tap_code16(is_mac() ? G(KC_C) : C(KC_C));
            }
            return false;
        case OS_PASTE:
            if (record->event.pressed) {
                tap_code16(is_mac() ? G(KC_V) : C(KC_V));
            }
            return false;
        case OS_APPN:
            if (record->event.pressed) {
                if (!app_switcher_active) {
                    app_switcher_active = true;
                    register_code(is_mac() ? KC_LGUI : KC_LALT);
                }
                tap_code(KC_TAB);
            }
            return false;
        case OS_APPP:
            if (record->event.pressed) {
                if (!app_switcher_active) {
                    app_switcher_active = true;
                    register_code(is_mac() ? KC_LGUI : KC_LALT);
                }
                tap_code16(S(KC_TAB));
            }
            return false;
        case OS_WRDL:
            if (record->event.pressed) {
                tap_code16(is_mac() ? A(KC_LEFT) : C(KC_LEFT));
            }
            return false;
        case OS_WRDR:
            if (record->event.pressed) {
                tap_code16(is_mac() ? A(KC_RIGHT) : C(KC_RIGHT));
            }
            return false;
        case OS_SWDL:
            if (record->event.pressed) {
                tap_code16(is_mac() ? A(S(KC_LEFT)) : C(S(KC_LEFT)));
            }
            return false;
        case OS_SWDR:
            if (record->event.pressed) {
                tap_code16(is_mac() ? A(S(KC_RIGHT)) : C(S(KC_RIGHT)));
            }
            return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (app_switcher_active && !layer_state_cmp(state, _NAV)) {
        unregister_code(is_mac() ? KC_LGUI : KC_LALT);
        app_switcher_active = false;
    }
    return state;
}

// Tap-dance to toggle nav when tapped and hold for symbol layer
// Track if nav is toggled
static bool nav_toggled = false;

void dance_nav_sym_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed && !state->interrupted) {
        // Hold - activate symbol layer
        layer_on(_SYM);
    } else if (state->count == 1) {
        // Single tap - toggle nav layer
        if (nav_toggled) {
            layer_off(_NAV);
            nav_toggled = false;
        } else {
            layer_on(_NAV);
            nav_toggled = true;
        }
    }
}

void dance_nav_sym_reset(tap_dance_state_t *state, void *user_data) {
    // Release hold - turn off symbol layer
    layer_off(_SYM);
}

// Register the tap dance
tap_dance_action_t tap_dance_actions[] = {
    [TD_NAV_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_nav_sym_finished, dance_nav_sym_reset),
};
