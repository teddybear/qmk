#include <stdint.h>
#include "snowfox.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _MAC_LAYER,
  _ARROW_LAYER,
  _FN_LAYER,
};

// This is ROW*MATRIX_COLS + COL
#define CAPS_LOCATION (MATRIX_COLS * 2 + 0)

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  * Layer _BASE_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | esc     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  R1   | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  * Layer HOLD in _BASE_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * | Arrow_L |     |     |     |     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       | FN_L  |       |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [_BASE_LAYER] = KEYMAP( /* Base */
    KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,   KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,  KC_BSLS,
    LT(_ARROW_LAYER, KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,         KC_ENT,
    KC_LSFT,KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
    KC_LCTL,KC_LGUI, KC_LALT,      KC_SPC,             TT(_FN_LAYER), RALT_T(KC_LEFT),  LWIN_T(KC_DOWN), RCTL_T(KC_RIGHT)
  ),
  /*
  * Layer _MAC_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  Alt  |  L1   |               space             |  Alt  |  FN1  |  R1   | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  * Layer HOLD in _MAC_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * | Arrow_L |     |     |     |     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       | FN_L  |       |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [_MAC_LAYER] = KEYMAP( /* Base */
    KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,   KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,  KC_BSLS,
    LT(_ARROW_LAYER, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,         KC_ENT,
    KC_LSFT,KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
    KC_LCTL,KC_LGUI, KC_LALT,      KC_SPC,             KC_RALT,  LT(_FN_LAYER, KC_LEFT),  LWIN_T(KC_DOWN), RCTL_T(KC_RIGHT)
  ),
  /* Layer _ARROW_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |     |     |     |     |     | Home| End |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |     |     |     |     | <-  | \/  |  ^  | ->  | PGU |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     | Ins | Del |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  */
  [_ARROW_LAYER] = KEYMAP( /* Base */
    KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SNOWFOX_LED_NEXT, SNOWFOX_LED_PDN, SNOWFOX_LED_PUP, SNOWFOX_LED_BDN, SNOWFOX_LED_BUP, SNOWFOX_LED_ON,   SNOWFOX_LED_OFF,
    KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END,  KC_TRNS,
    KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, KC_PGDN,         KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS, KC_DELETE, KC_END,  KC_PGDN, KC_DELETE, KC_UP,
    KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,             KC_TRNS, KC_LEFT,   KC_DOWN, KC_RIGHT
  ),
  /* Layer _FN_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | USB | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |           |
  * |-----------------------------------------------------------------------------------------+
  * | BT_UN  | BT1 | BT2 | BT3 | BT4 |     |     |     |     |     |     | Home| End | LED_On |
  * |-----------------------------------------------------------------------------------------+
  * | Arrow_L |     |     |     |     |     | <-  | \/  |  ^  | ->  | PGU | PGD | LED_Off     |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     | Ins | Del |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       | MAC_L | BASE_L|
  * \-----------------------------------------------------------------------------------------/
  */
 /*
   [_FN_LAYER] = KEYMAP(
    KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,   SNOWFOX_LED_OFF,
    SNOWFOX_LED_NEXT, SNOWFOX_BLE_DISCOVER, SNOWFOX_BLE_CONN, SNOWFOX_BLE_DISCONN, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, SNOWFOX_LED_BDN, SNOWFOX_LED_BUP, SNOWFOX_LED_OFF,  SNOWFOX_LED_ON,
    KC_CAPS, KC_MPLY, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_INS, KC_HOME, KC_PGUP, SNOWFOX_LED_PDN, SNOWFOX_LED_PUP,         KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_END, KC_PGDN, KC_TRNS, KC_DELETE, KC_PGUP,
    KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_PGDN, KC_PGDN
  ),*/
  [_FN_LAYER] = KEYMAP( /* Base */
    KC_ESC,   KC_F1,                KC_F2,            KC_F3,               KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DELETE,
    KC_TRNS,  KC_BTN1,              KC_MS_U,          KC_BTN2,             KC_WH_U, KC_TRNS, KC_TRNS, KC_PAUS,  KC_SLCK, KC_PSCR, KC_UP,   KC_HOME,  KC_END,  KC_INS,
    KC_TRNS,  KC_MS_L,              KC_MS_D,          KC_MS_R,             KC_WH_D, KC_TRNS, KC_TRNS, KC_TRNS,  KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT,     KC_TRNS,
    KC_TRNS,  SNOWFOX_BLE_DISCOVER, SNOWFOX_BLE_CONN, SNOWFOX_BLE_DISCONN, KC_BTN3, KC_TRNS, KC_TRNS, KC_PGDN,  KC_PGDN, KC_TRNS, KC_TRNS,       KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS,                                       KC_TRNS,                                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

const uint16_t keymaps_size = sizeof(keymaps);


void dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_MAC_LAYER);
      } else {
        layer_off(_MAC_LAYER);
      }
      break;
  }
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}

bool led_update_user(led_t leds) {
  return true;
}
