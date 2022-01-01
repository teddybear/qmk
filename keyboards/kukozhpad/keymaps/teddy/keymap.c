/* Copyright 2021 Uselessful
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
    _FN,
    _ADJ
};

/*
// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    PMNS_LAYR, // Our custom tap dance key; add any other tap dance keys to this enum
    ADJ_LAYR,
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);
*/

// Defines the keycodes used by our macros in process_record_user
/* enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
}; */

enum combos {
  PPLS,
  PMNS,
  PSLS,
  PAST,
  PEQL
};

const uint16_t PROGMEM pp_combo[] = {KC_P9, KC_P8, COMBO_END};
const uint16_t PROGMEM pm_combo[] = {KC_P8, KC_P7, COMBO_END};
const uint16_t PROGMEM ps_combo[] = {KC_P5, KC_P4, COMBO_END};
const uint16_t PROGMEM pa_combo[] = {KC_P6, KC_P5, COMBO_END};
const uint16_t PROGMEM pe_combo[] = {KC_P3, KC_P2, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [PPLS] = COMBO(pp_combo, KC_PPLS),
  [PMNS] = COMBO(pm_combo, KC_PMNS),
  [PSLS] = COMBO(ps_combo, KC_PSLS),
  [PAST] = COMBO(pa_combo, KC_PAST),
  [PEQL] = COMBO(pe_combo, KC_PEQL),
};


enum {
    TD_TO_ADJ,
    TD_TO_FN,
    TD_TO_BASE,
};



// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    NL_LAYR, // Our custom tap dance key; add any other tap dance keys to this enum
    NL_BKSP
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);


// // Tap Dance definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Escape, twice for Caps Lock
//     [TD_TO_ADJ] = ACTION_TAP_DANCE_LAYER_MOVE(MO(_FN), _ADJ),
//     [TD_TO_FN] = ACTION_TAP_DANCE_LAYER_MOVE(KC_PEQL, _FN),
//     [TD_TO_BASE] = ACTION_TAP_DANCE_LAYER_MOVE(KC_PPLS, _BASE),
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_P7,    KC_P8,    KC_P9,    KC_BSPC,
        KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_P1,    KC_P2,    KC_P3,    TD(NL_LAYR),
        KC_P0,    KC_PCMM,  KC_PDOT,  KC_PENT
    ),
    [_ADJ] = LAYOUT(
        RGB_TOG,   RGB_MOD,  RGB_VAD,   KC_TRNS,
        RGB_SAI,   RGB_VAI,  RGB_HUI,   KC_CAPS,
        RGB_SAD,   KC_UP,    RGB_HUD,   KC_TRNS,
        KC_LEFT,   KC_DOWN,  KC_RIGHT,  KC_RSFT
    ),
    [_FN] = LAYOUT(
        KC_INS,    KC_HOME,  KC_PGUP,   KC_TRNS,
        KC_DEL,    KC_END,   KC_PGDN,   KC_LCTRL,
        KC_LSFT,   KC_UP,    KC_LALT,   KC_TRNS,
        KC_LEFT,   KC_DOWN,  KC_RIGHT,  KC_RSFT
    )
};


td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_NUMLOCK); break;
        case TD_SINGLE_HOLD: layer_on(_FN); break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_FN)) {
                // If already set, then switch it off
                layer_off(_FN);
            } else {
                // If not already set, then switch the layer on
                layer_on(_FN);
            }
            break;
        case TD_DOUBLE_HOLD: layer_on(_ADJ); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_PMNS); break;
        case TD_TRIPLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_ADJ)) {
                // If already set, then switch it off
                layer_off(_ADJ);
            } else {
                // If not already set, then switch the layer on
                layer_on(_ADJ);
            }
            break;
        default: break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_FN); layer_off(_ADJ);
    }
    if (ql_tap_state.state == TD_DOUBLE_HOLD) {
        layer_off(_ADJ);
    }
    ql_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [NL_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
    // [NL_BKSP] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_NUMLOCK)
};
