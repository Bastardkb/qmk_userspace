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
#include QMK_KEYBOARD_H
#include "config.h"

// #ifdef RGB_MATRIX_ENABLE
#include "quantum/rgb_matrix/rgb_matrix.h"
// #endif  // RGB_MATRIX_ENABLE

/* combination keys */
enum combos {
  LCRC_MC,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM middle_click_combo[] = {KC_BTN1, KC_BTN2, COMBO_END};


combo_t key_combos[COMBO_LENGTH] = {
  [LCRC_MC] = COMBO(middle_click_combo, KC_BTN3),
};

/* keymaps */
enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_RUN,
    LAYER_WIN,
    LAYER_MEDIA,
    LAYER_MC,
    LAYER_NAV,
    LAYER_SEL,
    LAYER_AOE2_BASE,
    LAYER_AOE2_2,
    LAYER_NUM,
    LAYER_SYM,

};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        XXXXXXX,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, MO(LAYER_SEL),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_BSPC, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_BTN1,  KC_BTN2, DRGSCRL, KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                           KC_LSFT, MO(LAYER_SYM),  KC_LGUI,    MO(LAYER_NUM),  KC_SPC,
                                           KC_LALT, KC_LCTL,     LT(LAYER_NAV, KC_ENT)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_WIN] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        XXXXXXX,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, MO(LAYER_SEL),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_BSPC, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_BTN1,  KC_BTN2, DRGSCRL, KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                           KC_LSFT, MO(LAYER_SYM),  KC_LGUI,    MO(LAYER_NUM),  KC_SPC,
                                           KC_LALT, KC_LCTL,     LT(LAYER_NAV, KC_ENT)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_RUN] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        XXXXXXX,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, MO(LAYER_SEL),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_BSPC, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_BTN1,  KC_BTN2, DRGSCRL, KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                           KC_LSFT, MO(LAYER_SYM),  KC_LGUI,    MO(LAYER_NUM),  KC_SPC,
                                           KC_LALT, KC_LCTL,     LT(LAYER_NAV, KC_ENT)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_MEDIA] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        XXXXXXX,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, MO(LAYER_SEL),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_BSPC, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_BTN1,  KC_BTN2, DRGSCRL, KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                           KC_LSFT, MO(LAYER_SYM),  KC_LGUI,    MO(LAYER_NUM),  KC_SPC,
                                           KC_LALT, KC_LCTL,     LT(LAYER_NAV, KC_ENT)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_NAV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, C(KC_PLUS), C(KC_MINS), XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, XXXXXXX, KC_HOME, KC_INS, KC_END,   XXXXXXX,      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_VOLD,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,     LALT(KC_LEFT), RCS(KC_TAB),  KC_PGDN, KC_PGUP, LCTL(KC_TAB), LALT(KC_RIGHT),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LSFT, KC_TAB, XXXXXXX,    XXXXXXX, KC_SPC,
                                           KC_LALT, KC_LCTL,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_MC] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        XXXXXXX,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, MO(LAYER_SEL),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_W,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_ESC,    KC_A,    KC_A,    KC_S,    KC_D,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_BSPC, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_BTN1,  KC_BTN2, DRGSCRL, KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                           KC_LSFT, MO(LAYER_SYM),  KC_LGUI,    MO(LAYER_NUM),  KC_SPC,
                                           KC_LALT, KC_LCTL,     LT(LAYER_NAV, KC_ENT)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_AOE2_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, TG(LAYER_AOE2_BASE),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        XXXXXXX,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_BSPC, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_DEL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M, KC_BTN1,  KC_BTN2, DRGSCRL, KC_DOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                              KC_LSFT, KC_LCTL, KC_LALT,           MO(LAYER_NUM),  KC_SPC,
                              KC_LALT, MO(LAYER_AOE2_2),           KC_ENT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_AOE2_2] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, TG(LAYER_AOE2_BASE),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        XXXXXXX,  KC_H,    KC_J,    KC_K,    KC_L,  KC_LBRC,      KC_H,    KC_J,    KC_K,    KC_L, KC_BSPC, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_DEL,   KC_N,    KC_M,    KC_EQL, KC_BSLS,KC_RBRC,      KC_N,    KC_M, KC_BTN1,  KC_BTN2, DRGSCRL, KC_DOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                              KC_LSFT, KC_LCTL, KC_LALT,           MO(LAYER_NUM),  KC_SPC,
                                        XXXXXXX, XXXXXXX,          KC_ENT
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_NUM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_CIRC,   KC_SLSH,   KC_PAST,  KC_PMNS,  KC_EQL, KC_ENT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PLUS, KC_7, KC_8, KC_9, KC_LPRN, KC_RPRN,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_MINS, KC_4, KC_5, KC_6, KC_BSPC, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,    KC_0,   KC_1, KC_2, KC_3, KC_LSFT, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                            KC_LSFT, MO(LAYER_SYM), XXXXXXX,    XXXXXXX, XXXXXXX,
                                           KC_LALT, KC_LCTL,    KC_LGUI
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_SYM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_GRV, KC_CIRC, KC_LCBR, KC_AMPR, KC_RCBR, KC_MINS,     KC_PIPE,   KC_LBRC,   KC_DQT,   KC_RBRC, KC_COLN, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, KC_EXLM, KC_LPRN, KC_ASTR, KC_RPRN, KC_UNDS,    KC_EQL,   KC_LT,   KC_QUOT,   KC_GT, KC_SCLN, KC_RSFT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL, KC_PERC, KC_AT, KC_HASH, KC_DLR, KC_SLSH,       KC_BSLS,   KC_PLUS,   KC_COMM,   KC_DOT, KC_QUES, KC_RCTL,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LSFT, XXXXXXX, KC_LGUI,    MO(LAYER_NUM), KC_SPC,
                                           KC_LALT, KC_LCTL,    LT(LAYER_NAV, KC_ENT)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_SEL] = LAYOUT(
  // ╭─────────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────╮
       TG(LAYER_BASE),        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────┤
       TG(LAYER_AOE2_BASE),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────╯
                                                  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
                                                          XXXXXXX, XXXXXXX,    XXXXXXX
  //                                           ╰───────────────────────────╯ ╰──────────────────╯
  ),
};

/* rgb layers */
layer_state_t layer_state_set_user(layer_state_t state) {
   #ifdef RGB_MATRIX_ENABLE
     switch (biton32(state)) {
          case LAYER_NAV:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_nav_effect);
               break;
          case LAYER_BASE:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_base_effect);
               break;
          case LAYER_WIN:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_win_effect);
               break;
          case LAYER_RUN:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_run_effect);
               break;
          case LAYER_MEDIA:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_media_effect);
               break;
          case LAYER_MC:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_mc_effect);
               break;
          case LAYER_SYM:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_sym_effect);
               break;
          case LAYER_NUM:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_num_effect);
               break;
          case LAYER_SEL:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_sel_effect);
               break;
          case LAYER_AOE2_BASE:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_aoe2_base_effect);
               break;
          case LAYER_AOE2_2:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_aoe2_2_effect);
               break;
    }
     #endif // RGB_MATRIX_ENABLE
  return state;
}
// clang-format on
