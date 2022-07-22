#include QMK_KEYBOARD_H


enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FIVE,
};

enum custom_keycodes { RGBRST = SAFE_RANGE, KC_SAMPLEMACRO, XKBMAP};

// #define LOWER MO(_LOWER)
// #define RAISE MO(_RAISE)
#define TG_FIVE TG(_FIVE)

#define RBR_RGU RGUI_T(KC_RBRC)
#define F12_RGU RGUI_T(KC_F12)
#define PLS_LCT LCTL_T(KC_PPLS)
#define EQL_LCT LCTL_T(KC_PEQL)
#define APP_LCT LCTL_T(KC_APP)
#define EQL_RCT RCTL_T(KC_PEQL)
#define QUO_RCT RCTL_T(KC_QUOT)
#define APP_RCT RCTL_T(KC_APP)
#define MIN_RCT RCTL_T(KC_MINS)
#define EQL_LAL LALT_T(KC_EQL)
#define BSL_RAL RALT_T(KC_BSLS)

#define BSP_RSH RSFT_T(KC_BSPC)
#define SPC_LSH LSFT_T(KC_SPC)
#define SPC_RSH RSFT_T(KC_SPC)
#define SPC_LWR LT(_LOWER, KC_SPC)
#define BSP_LWR LT(_LOWER, KC_BSPC)
#define DEL_RSE LT(_RAISE, KC_DEL)
#define TAB_RSE LT(_RAISE, KC_TAB)
#define ENT_LWR LT(_LOWER, KC_ENT)
#define ESC_LWR LT(_LOWER, KC_ESC)
#define ESC_LGUI LGUI_T(KC_ESC)

#include "hld.c"

#ifdef COMBO_ENABLE
#include "cmbs.c"
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(\
    _______,  LGUI_T(KC_GRV),   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,             KC_Y,    KC_U,    KC_I,       KC_O,    KC_P,    KC_LBRC, RGUI_T(KC_RBRC), \
              KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,             KC_H,    KC_J,    KC_K,       KC_L,    KC_SCLN, RCTL_T(KC_QUOT), \
              KC_LALT,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,             KC_N,    KC_M,    KC_COMM,    KC_DOT,  KC_SLSH, BSL_RAL, \
                                        TAB_RSE, SPC_LSH, ESC_LWR,             ENT_LWR, BSP_RSH, DEL_RSE \
    ),

    [_LOWER] = LAYOUT(\
    _______,  LGUI_T(KC_MINS),   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,            KC_F6,   KC_F7,   KC_F8,      KC_F9,   KC_F10,  KC_F11,  F12_RGU, \
              PLS_LCT,           KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, MIN_RCT, \
              _______,           KC_1,    KC_2,    KC_3,    KC_4,     KC_5,             KC_6,    KC_7,    KC_8,       KC_9,    KC_0,    _______, \
                                          _______, _______,  _______,          _______, _______, _______\
    ),

    [_RAISE] = LAYOUT(\
    _______,  KC_NLCK,  KC_PSLS, KC_7,    KC_8,    KC_9,     KC_MINS,          KC_VOLU, KC_HOME, KC_INS,     KC_PGUP, KC_SLCK, KC_CAPS, _______, \
              EQL_LCT,  KC_PAST, KC_4,    KC_5,    KC_6,     KC_PPLS,          KC_MUTE, KC_LEFT, KC_UP,      KC_RGHT, KC_PSCR, APP_RCT, \
              _______,  KC_0,    KC_1,    KC_2,    KC_3,     KC_PCMM,          KC_VOLD, KC_END,  KC_DOWN,    KC_PGDN, KC_PAUS, _______, \
                                          _______, _______,  _______,          _______, _______, _______\
    ),

     [_ADJUST] = LAYOUT(\
    _______, _______,    RESET,   KC_BTN1, KC_BTN3, KC_BTN2,  XKBMAP,           KC_BTN2, KC_WH_U,  _______,   KC_WH_R, _______, _______, RESET,\
             _______,    _______, KC_MS_L, KC_MS_U, KC_MS_R,  KC_WH_U,          KC_BTN3, KC_MS_L,  KC_MS_U,   KC_MS_R, _______, RGB_HUI, \
             _______,    TG_FIVE, KC_WH_L, KC_MS_D, KC_WH_R,  KC_WH_D,          KC_BTN1, KC_WH_D,  KC_MS_D,   KC_WH_L, _______, TG_FIVE, \
                                           _______, SH_TG,   _______,          _______, SH_TG,    _______\
    ),

    [_FIVE] = LAYOUT(\
    _______,   RGBRST,  KC_ASUP, KC_ASTG, KC_ASDN, _______, _______,             _______, _______,  KC_ASDN, KC_ASTG, KC_ASUP, RGBRST,   RESET, \
             RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,  _______,            _______,  _______,  RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG, \
             RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, TG_FIVE,  _______,            _______, _______,   RGB_VAD, RGB_SAD, RGB_HUD, RGB_MOD, \
                                         _______, SH_TG,   _______,            _______, SH_TG,   _______\
    ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}


#ifdef OLED_ENABLE
#include "oled.c"
#endif

#ifdef LEADER_ENABLE
#include "ldr.c"
#endif
