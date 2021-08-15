#include QMK_KEYBOARD_H


// Fillers to make layering more clear

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ISO,
    _THUMB_ALT,
    _FIVE,
    _MACR,
};

enum custom_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE, ADJUST, MACR, RGBRST, KC_SAMPLEMACRO, PLOVER, EXT_PLV, XKBMAP };

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST RESET
#define KC_LRST RGBRST
#define KC_LTOG RGB_TOG
#define KC_LHUI RGB_HUI
#define KC_LHUD RGB_HUD
#define KC_LSAI RGB_SAI
#define KC_LSAD RGB_SAD
#define KC_LVAI RGB_VAI
#define KC_LVAD RGB_VAD
#define KC_LMOD RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MACR MO(_MACR)

#define TG_ISO TG(_ISO)
#define TG_THMB TG(_THUMB_ALT)
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

#define NBS_LCT LCTL_T(KC_NUBS)
#define BSH_LAL LALT_T(KC_BSLS)
#define APP_RAL RALT_T(KC_APP)

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

#include "taps.c"
#include "hld.c"
#include "cmbs.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |  [   |   ]  |                                                         |      |      |
 *               +-------------+-------------+                             +-------------+-------------+
 *                             |      |      |                             |      |      |
 *                             |------+------|                             |------+------|
 *                             |      |      |                             |      |      |
 *                             +-------------+                             +-------------+
 *                                           +-------------+ +-------------+
 *                                           |      |      | |      |      |
 *                                           +-------------+ +-------------+
 */

[_QWERTY] = LAYOUT( \
    LGUI_T(KC_GRV),  KC_Q,   KC_W,  KC_E,   KC_R,    KC_T,       KC_Y,    KC_U,   KC_I,   KC_O,   KC_P,    RGUI_T(KC_LBRC),  \
    KC_LCTL,  KC_A,   KC_S,  KC_D,   KC_F,    KC_G,              KC_H,    KC_J,   KC_K,   KC_L,   KC_SCLN, RCTL_T(KC_QUOT), \
    KC_LALT, KC_Z,   KC_X,  KC_C,   KC_V,    KC_B,               KC_N,    KC_M,   KC_COMM,KC_DOT, KC_SLSH, BSL_RAL, \
    _______,_______, TAB_RSE, SPC_LSH, ESC_LWR,  LOWER,          RAISE, ENT_LWR, BSP_RSH, DEL_RSE, _______, _______,   \
                                       KC_BSPC,  MACR,           MACR, KC_LALT
),

[_LOWER] = LAYOUT(
    LGUI_T(KC_F1),   KC_F2,   KC_F3,   KC_F4,    KC_F5,          KC_F6,   KC_F7,    KC_F8,      KC_F9,   KC_F10,  KC_F11,  RGUI_T(KC_F12),\
    PLS_LCT,         KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,         KC_PERC, KC_CIRC,  KC_AMPR,    KC_ASTR, KC_LPRN, KC_RPRN, MIN_RCT, \
    LALT_T(KC_MINS), KC_1,    KC_2,    KC_3,     KC_4,           KC_5,    KC_6,     KC_7,       KC_8,    KC_9,    KC_0,    _______, \
    _______,_______,_______,_______,_______,_______,             _______, _______,  _______,    _______, _______, _______,\
                                    _______,_______,             _______, _______
),

[_RAISE] = LAYOUT(
    LGUI_T(KC_NLCK),  KC_PSLS, KC_7,    KC_8,    KC_9,     KC_MINS,          KC_VOLU, KC_HOME, KC_INS,     KC_PGUP, KC_SLCK, RGUI_T(KC_CAPS), \
    EQL_LCT,          KC_PAST, KC_4,    KC_5,    KC_6,     KC_PPLS,          KC_MUTE, KC_LEFT, KC_UP,      KC_RGHT, KC_PSCR, APP_RCT, \
    _______,          KC_0,    KC_1,    KC_2,    KC_3,     KC_PCMM,          KC_VOLD, KC_END,  KC_DOWN,    KC_PGDN, KC_PAUS, _______, \
    _______,          _______,_______,_______,_______,_______,               _______,_______,_______,_______,_______,_______,   \
                                    _______,_______,                         _______,_______                                    \
),
[_ADJUST] = LAYOUT(
    CMB_ON,     RESET,   KC_BTN1, KC_BTN3, KC_BTN2,  XKBMAP,                 _______, QWERTY,   KC_ASDN,    KC_ASTG, RESET,   CMB_ON,  \
    CMB_TOG,    RGB_HUI, KC_MS_L, KC_MS_U, KC_MS_R,  KC_WH_U,                KC_LEFT, KC_DOWN,  KC_UP,      KC_RGHT, RGB_HUI, CMB_TOG, \
    CMB_OFF,    _______, KC_WH_U, KC_MS_D, KC_WH_D,   KC_WH_D,               _______, _______,   RGB_VAD,    RGB_SAD, _______, CMB_OFF, \
    _______,          _______,_______,_______,_______,_______,               _______,_______,_______,_______,_______,_______,   \
                                    _______,_______,                         _______,_______                                    \
),
[_MACR] = LAYOUT(
    LGUI_T(KC_NLCK),  KC_PSLS, KC_7,    KC_8,    KC_9,     KC_MINS,          KC_VOLU, KC_HOME, KC_INS,     KC_PGUP, KC_SLCK, RGUI_T(KC_CAPS), \
    EQL_LCT,          KC_PAST, KC_4,    KC_5,    KC_6,     KC_PPLS,          KC_MUTE, KC_LEFT, KC_UP,      KC_RGHT, KC_PSCR, APP_RCT, \
    _______,          KC_0,    KC_1,    KC_2,    KC_3,     KC_PCMM,          KC_VOLD, KC_END,  KC_DOWN,    KC_PGDN, KC_PAUS, _______, \
    _______,          _______,_______,_______,_______,_______,               _______,_______,_______,_______,_______,_______,   \
                                    _______,_______,                         _______,_______                                    \
),
};

uint32_t layer_state_set_user(uint32_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
