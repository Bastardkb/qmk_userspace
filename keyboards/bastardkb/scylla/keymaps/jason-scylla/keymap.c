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
    SYM_PLUS,
};

enum tap_dances {
    TD_NAV_SYM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_4x6_5(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TG(1),
        KC_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_TAB, LCTL_T(KC_A),    LALT_T(KC_S),    LGUI_T(KC_D),    LSFT_T(KC_F),    KC_G,             KC_H, LSFT_T(KC_J),    LGUI_T(KC_K),    LALT_T(KC_L),    LCTL_T(KC_SCLN),    KC_QUOT,
        KC_F4, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N, KC_M,  KC_COMM, KC_DOT, KC_SLSH,  KC_F4,
                             MO(2), MO(3), KC_ESC, KC_ENT, KC_SPC, KC_BSPC, KC_DEL, KC_ESC, CW_TOGG, TD(TD_NAV_SYM)
    ),

    [1] = LAYOUT_split_4x6_5(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT_split_4x6_5(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, C(S(KC_TAB)), OS_APPP, C(KC_TAB), OS_APPN, KC_PGUP,   KC_TRNS, KC_F12,  KC_UP,   KC_F13,  KC_PGUP, KC_TRNS,
        KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_PGDN,          SEL_LINE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, EE_CLR,
        KC_TRNS, OS_UNDO, OS_CUT,  OS_COPY, OS_PASTE, OS_REDO,         OS_WRDL, KC_MS_BTN4, A(KC_DEL), KC_MS_BTN5, KC_DEL, QK_BOOT,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [3] = LAYOUT_split_4x6_5(
        KC_TRNS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),          S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_TRNS,
        KC_TRNS, S(KC_LBRC), S(KC_LBRC), S(KC_BSLS), S(KC_RBRC), KC_GRV,      S(KC_GRV), S(KC_COMM), S(KC_QUOT), S(KC_DOT), KC_BSLS, KC_TRNS,
        KC_TRNS, KC_F4, S(KC_9), S(KC_SCLN), S(KC_0), KC_SCLN,    S(KC_SLSH), KC_MINS, KC_EQL, SYM_PLUS, S(KC_8), KC_TRNS,
        KC_BSLS, S(KC_1), KC_LBRC, S(KC_3), KC_RBRC, S(KC_5),          S(KC_6), S(KC_7), KC_COMM, S(KC_MINS), KC_SLSH, KC_TRNS,
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

static bool process_os_shortcut(
    keyrecord_t *record,
    uint16_t mac_keycode,
    uint16_t other_keycode
) {
    uint16_t keycode = is_mac() ? mac_keycode : other_keycode;
    if (record->event.pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }
    return false;
}

static bool is_pinky_home_row_mod(uint16_t keycode) {
    switch (keycode) {
        case LCTL_T(KC_L):
        case LCTL_T(KC_X):
        case LCTL_T(KC_A):
        case LCTL_T(KC_SCLN):
            return true;
        default:
            return false;
    }
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
            return process_os_shortcut(record, G(KC_Z), C(KC_Z));
        case OS_REDO:
            return process_os_shortcut(record, G(S(KC_Z)), C(KC_Y));
        case OS_CUT:
            return process_os_shortcut(record, G(KC_X), C(KC_X));
        case OS_COPY:
            return process_os_shortcut(record, G(KC_C), C(KC_C));
        case OS_PASTE:
            return process_os_shortcut(record, G(KC_V), C(KC_V));
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
            return process_os_shortcut(record, A(KC_LEFT), C(KC_LEFT));
        case OS_WRDR:
            return process_os_shortcut(record, A(KC_RIGHT), C(KC_RIGHT));
        case OS_SWDL:
            return process_os_shortcut(record, A(S(KC_LEFT)), C(S(KC_LEFT)));
        case OS_SWDR:
            return process_os_shortcut(record, A(S(KC_RIGHT)), C(S(KC_RIGHT)));
        case SYM_PLUS:
            if (record->event.pressed) {
                tap_code16(S(KC_EQL));
            }
            return false;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (is_pinky_home_row_mod(keycode)) {
        return TAPPING_TERM + 25;
    }
    return TAPPING_TERM;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    if (is_pinky_home_row_mod(keycode)) {
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
