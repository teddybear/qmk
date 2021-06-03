#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum jiran_layers {
  _QWERTY,
  _LOWER
};

enum {
    TD_RSH_CAPS,
    TD_SPC_CAPS,
};

#define KC_RBGI  RGUI_T(KC_RBRC)
#define KC_BSCT  RCTL_T(KC_BSLS)
#define KC_QTSH  RSFT_T(KC_QUOT)
#define KC_SLSF  RSFT_T(KC_LSCR)
// #define KC_LSCL  LSFT_T(KC_CAPS)
#define KC_NLCT  RCTL_T(KC_LNUM)
#define KC_ETAL  RALT_T(KC_ENT)
#define KC_ELAL  LALT_T(KC_ENT)
#define DEL_LW LT(_LOWER, KC_DEL)
#define KC_ESGI  RGUI_T(KC_ESC)
#define LOWER  MO(_LOWER)
#define T_SHCS TD(TD_RSH_CAPS)
#define T_SPCS TD(TD_SPC_CAPS)
#define CAPS_LW LT(_LOWER, KC_CAPS)

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_RSH_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_SPC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_CAPS),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //          ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
               KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  // ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐
      KC_ESGI, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBGI,
  // └────────┼────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┘
               T_SHCS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QTSH,
  //          ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
               KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSCT,
  //          └────────┴────────┴────────┴────────┼────────┼────────┤                          ├────────┼────────┼────────┴────────┴────────┴────────┘
                                          CAPS_LW, KC_SPC,  KC_ELAL,                            KC_ETAL, KC_BSPC, DEL_LW
                                  //     └────────┴────────┴────────┘                          └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //          ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
               KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL,
  // ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐
      KC_F11,  KC_CAPS, KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS,                            KC_VOLU, KC_PGUP, KC_INS,  KC_HOME, KC_END,  KC_DEL,  KC_F12,
  // └────────┼────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┼────────┘
               KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_U, KC_MS_R, KC_WH_U,                            KC_MUTE, KC_LEFT, KC_UP,   KC_RGHT, KC_PSCR, KC_SLSF,
  //          ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
               KC_TRNS, KC_TRNS, KC_END,  KC_MS_D, KC_TRNS, KC_WH_D,                            KC_VOLD, KC_PGDN, KC_DOWN, KC_END,  KC_PAUS, KC_NLCT,
  //          └────────┴────────┴────────┴────────┼────────┼────────┤                          ├────────┼────────┴────────┴────────┴────────┴────────┘
                                          KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS
                                    //   └────────┴────────┴────────┘                          └────────┴────────┴────────┘
  ),

};
