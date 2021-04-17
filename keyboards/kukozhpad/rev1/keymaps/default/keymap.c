/* Copyright %YEAR% %YOUR_NAME%
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
/* enum custom_keycodes {
    
}; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_P7,    KC_P8,    KC_P9,    KC_BSPC,  
        KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  
        KC_P1,    KC_P2,    KC_P3,    KC_RSFT,  
        KC_P0,    KC_PCMM,  KC_PDOT,  KC_PENT
    ),

    [_FN] = LAYOUT(
        KC_INS,    KC_HOME,  KC_PGUP,   KC_UNDO,   
        KC_DEL,    KC_END,   KC_PGDN,   KC_LGUI,   
        KC_LSFT,   KC_UP,    KC_LALT,   KC_LCTRL,  
        KC_LEFT,   KC_DOWN,  KC_RIGHT,  KC_RSFT
    )
};


/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
