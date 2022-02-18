// Copyright 2022 @filterpaper
// SPDX-License-Identifier: GPL-2.0+

#include QMK_KEYBOARD_H


enum layer_number {
    _QWERTY = 0,
    _SYM,
    _NUM,
    _NAV,
    _FUN,
    _MOUSE,
    _NAVA,
    _SYMA,
};

enum custom_keycodes { QWERTY = SAFE_RANGE, SYM, NUM, NAV, FUN, MOUSE,};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_RST RESET

#define KC_CTLTB CTL_T(KC_TAB)


#define SYM MO(_SYM)
// #define NAVA MO(_NAVA)
#define NUM MO(_NUM)
#define NAV MO(_NAV)
#define FUN MO(_FUN)
#define MOUSE MO(_MOUSE)

#define LG_A LGUI_T(KC_A)
#define LA_S LALT_T(KC_S)
#define LS_D LSFT_T(KC_D)
#define LC_F LCTL_T(KC_F)
#define GR_X RALT_T(KC_X)
#define GR_SL RALT_T(KC_SLSH)

#define RG_SC RGUI_T(KC_SCLN)
#define RA_L LALT_T(KC_L)
#define RS_K RSFT_T(KC_K)
#define RC_J RCTL_T(KC_J)
#define GR_DOT RALT_T(KC_DOT)

// #define TAB_FUN LT(_FUN, KC_TAB)
#define SPC_FUN LT(_FUN, KC_SPC)
#define ESC_NUM LT(_NUM, KC_ESC)
#define ENT_NUM LT(_NUM, KC_ENT)
#define BSP_NAV LT(_NAV, KC_BSPC)
// #define DEL_NAV LT(_NAV, KC_DEL)

#include "taps.c"
#include "hld.c"
#include "cmbs.c"

// Seniply layout
// https://stevep99.github.io/seniply

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
            KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                       KC_Y,    KC_U,    KC_I,       KC_O,    KC_P,
            LG_A,    LA_S,    LS_D,    LC_F,     KC_G,                       KC_H,    RC_J,    RS_K,       RA_L,    RG_SC,
            KC_Z,    GR_X,    KC_C,    KC_V,     KC_B,                       KC_N,    KC_M,    KC_COMM,    GR_DOT,  KC_SLSH,
                                                SPC_FUN, ESC_NUM,           ENT_NUM, BSP_NAV
    ),
    [_SYM] = LAYOUT(
            KC_LCBR,   KC_AMPR,  KC_ASTR,    KC_LPRN,   KC_RPRN,                    _______,  _______,   _______, _______, _______,
            KC_COLN,   KC_DLR,   KC_PERC,    KC_CIRC,   KC_PPLS,                    _______,  _______,   _______, _______, _______,
            KC_TILD,   KC_EXLM,  KC_AT,      KC_HASH,   KC_PIPE,                    _______,  _______,   _______, _______, _______,
                                                _______, KC_UNDS,       _______, _______
    ),
    [_NUM] = LAYOUT(
            KC_LBRC,   KC_7,    KC_8,    KC_9,   KC_RBRC,                    _______,  _______,   _______, _______, _______,
            KC_SCLN,   KC_4,    KC_5,    KC_6,   KC_EQL,                     _______,  _______,   _______, _______, _______,
            KC_GRV,    KC_1,    KC_2,    KC_3,   KC_BSLS,                    _______,  _______,   _______, _______, _______,
                                                KC_0, KC_MINS,     _______, _______
    ),
    [_FUN] = LAYOUT(
            KC_F12,   KC_F7,    KC_F8,    KC_F9,   KC_PSCR,                 _______,  _______,   _______, _______, _______,
            KC_F11,   KC_F4,    KC_F5,    KC_F6,   KC_SLCK,                 _______,  _______,   _______, _______, _______,
            KC_F10,   KC_F1,    KC_F2,    KC_F3,   KC_PAUS,                 _______,  _______,   _______, _______, _______,
                                                   _______, _______,           _______, _______
    ),
    [_NAV] = LAYOUT(
            _______,  _______,   _______, _______, _______,                  KC_VOLU,   KC_HOME,   KC_INS,  KC_PGUP,   KC_DQT,
            _______,  _______,   _______, _______, _______,                  KC_MUTE,   KC_LEFT,   KC_UP,   KC_RGHT,   KC_QUOT,
            _______,  _______,   _______, _______, _______,                  KC_VOLD,   KC_END,    KC_DOWN, KC_PGDN,   KC_BSLS,
                                                _______, _______,           _______, _______
    ),
    [_NAVA] = LAYOUT(
            RESET,    _______,   _______, _______, _______,                  KC_VOLU,   KC_HOME,   KC_INS,  KC_PGUP,   KC_DQT,
            _______,  _______,   _______, _______, _______,                  KC_MUTE,   KC_LEFT,   KC_UP,   KC_RGHT,   KC_QUOT,
            _______,  _______,   _______, _______, _______,                  KC_VOLD,   KC_END,    KC_DOWN, KC_PGDN,   KC_BSLS,
                                                _______, _______,           _______, _______
    ),
    [_SYMA] = LAYOUT(
            KC_LCBR,   KC_AMPR,  KC_ASTR,    KC_LPRN,   KC_RPRN,                    _______,  _______,   _______, _______, _______,
            KC_COLN,   KC_DLR,   KC_PERC,    KC_CIRC,   KC_PPLS,                    _______,  _______,   _______, _______, _______,
            KC_TILD,   KC_EXLM,  KC_AT,      KC_HASH,   KC_PIPE,                    _______,  _______,   _______, _______, _______,
                                                _______, KC_UNDS,       _______, _______
    )
};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _NUM, _NAV, _SYMA);
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_F) {
        // Anything you can do in a macro.
            SEND_STRING("QMK is awesome.");
        }

        SEQ_ONE_KEY(KC_L) {
        // Anything you can do in a macro.
            register_code(KC_LGUI);
            register_code(KC_L);
            unregister_code(KC_L);
            unregister_code(KC_LGUI);
        }

        SEQ_TWO_KEYS(KC_D, KC_D) {
            SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
        }

        SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
            SEND_STRING("https://start.duckduckgo.com\n");
        }

        SEQ_THREE_KEYS(KC_X, KC_X, KC_X) {
            SEND_STRING("setxkbmap -model pc105 -layout us,ru -option grp:caps_toggle,lv3:ralt_switch,misc:typo -option terminate:ctrl_alt_bksp -option kpdl:dot -option grp_led:scroll\n");
        }

        SEQ_TWO_KEYS(KC_A, KC_S) {
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_Z) {
            register_code(KC_LSFT);
            register_code(KC_1);
            unregister_code(KC_1);
            unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_X) {
            register_code(KC_LSFT);
            register_code(KC_2);
            unregister_code(KC_2);
            unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_C) {
                register_code(KC_LSFT);
                register_code(KC_3);
                unregister_code(KC_3);
                unregister_code(KC_LSFT);
        }


        SEQ_TWO_KEYS(KC_SPC, KC_V) {
                register_code(KC_LSFT);
                register_code(KC_4);
                unregister_code(KC_4);
                unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_B) {
                register_code(KC_LSFT);
                register_code(KC_5);
                unregister_code(KC_5);
                unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_N) {
                register_code(KC_LSFT);
                register_code(KC_6);
                unregister_code(KC_6);
                unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_M) {
                register_code(KC_LSFT);
                register_code(KC_7);
                unregister_code(KC_7);
                unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_COMM) {
                register_code(KC_LSFT);
                register_code(KC_8);
                unregister_code(KC_8);
                unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_DOT) {
                register_code(KC_LSFT);
                register_code(KC_9);
                unregister_code(KC_9);
                unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_SLSH) {
                register_code(KC_LSFT);
                register_code(KC_0);
                unregister_code(KC_0);
                unregister_code(KC_LSFT);
        }
    }
}
