/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

// Save some space
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define DISABLE_LEADER

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |                | Knob 2: Page Dn/Up |
        | Press: Mute       | Toggle Layer 1 | Press: Play/Pause  |
        | Print Screen      | Up             | Right OS           |
        | Left              | Down           | Right              |
     */
    [0] = LAYOUT(
        KC_MUTE, MO(1), KC_MPLY,
        KC_PSCR   , KC_UP  , KC_RGUI,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /*
        | N/A             | N/A            | N/A    |
        | Mouse Button 1  | Mouse Button 1 | Escape |
        | Mouse Button 1  | Mouse Button 1 | Escape |
     */
    [1] = LAYOUT(
        KC_TRNS  , KC_TRNS, KC_TRNS,
        KC_BTN1, KC_BTN1, KC_ESC,
        KC_BTN1, KC_BTN1 , KC_ESC
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
