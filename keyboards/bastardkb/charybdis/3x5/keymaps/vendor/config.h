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
#pragma once

#ifdef VIA_ENABLE
/* VIA configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 7
#endif // VIA_ENABLE

/* Tap-hold tuning (from Argos export). */
#define TAPPING_TERM 200

/* Combo tuning (from Argos export). */
#ifdef COMBO_ENABLE
#    define COMBO_TERM 50
#endif // COMBO_ENABLE

/* Trackball DPI steps (from Argos export). */
#ifdef POINTING_DEVICE_ENABLE
#    define CHARYBDIS_MINIMUM_DEFAULT_DPI 400
#    define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 200
#    define CHARYBDIS_MINIMUM_SNIPING_DPI 200
#    define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100
#endif // POINTING_DEVICE_ENABLE

/* RGB matrix defaults (from Argos export). The board already defines these, so
 * undef first to avoid -Werror redefinition warnings. */
#ifdef RGB_MATRIX_ENABLE
#    undef RGB_MATRIX_DEFAULT_HUE
#    define RGB_MATRIX_DEFAULT_HUE 0
#    undef RGB_MATRIX_DEFAULT_SAT
#    define RGB_MATRIX_DEFAULT_SAT 255
#    undef RGB_MATRIX_DEFAULT_VAL
#    define RGB_MATRIX_DEFAULT_VAL 40
#    undef RGB_MATRIX_DEFAULT_SPD
#    define RGB_MATRIX_DEFAULT_SPD 40
#endif // RGB_MATRIX_ENABLE

#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE
