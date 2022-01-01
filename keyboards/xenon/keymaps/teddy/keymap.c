/* Copyright 2020 Kyrre Havik Eriksen
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

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

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

// #define M_LWR MO(_LOWER)
// #define M_RSE MO(_RAISE)
// #define L(kc) (LSFT(kc))
// #define R(kc) (RALT(kc))U

#include "taps.c"
#include "hld.c"
#include "cmbs.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
      KC_GRV,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                         KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,
      KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                         KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,RCTL_T(KC_QUOT),
      KC_LALT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                         KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,BSL_RAL,
                         KC_MUTE,ESC_LGUI,TAB_RSE,SPC_LSH, ENT_LWR,      ENT_LWR, BSP_RSH,  DEL_RSE, RGUI_T(KC_RBRC),  KC_MPLY,
                                 KC_DEL ,KC_PGDN,KC_PGUP,KC_ESC,      KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT
    ),
    [_LOWER] = LAYOUT(
      KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,    KC_F12,
      PLS_LCT,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,   KC_RPRN,   MIN_RCT,
      EQL_LAL,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,      KC_0,    _______,
                          KC_TRNS,KC_UNDS,KC_TRNS,KC_TRNS,KC_TRNS,         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_RAISE] = LAYOUT(
      KC_NLCK,   KC_PSLS,  KC_P7,   KC_P8,   KC_P9,  KC_PMNS,                      KC_VOLU, KC_HOME, KC_INS,   KC_PGUP, KC_SLCK, KC_CAPS,
      EQL_LCT,   KC_PAST,  KC_P4,   KC_P5,   KC_P6,  KC_PPLS,                      KC_MUTE, KC_LEFT, KC_UP,    KC_RGHT, KC_PSCR,  APP_RCT,
      _______,   KC_P0,    KC_P1,   KC_P2,   KC_P3,  KC_PCMM,                      KC_VOLD, KC_END,  KC_DOWN,  KC_PGDN, KC_PAUS, _______,
                         KC_TRNS,KC_UNDS,KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [_ADJUST] = LAYOUT(
      KC_P0,   KC_PSLS,  KC_P7,   KC_P8,   KC_P9,  KC_PMNS,                      KC_VOLU, KC_HOME, KC_INS,   KC_PGUP, KC_SLCK, KC_CAPS,
      RESET,   KC_PAST,  KC_P4,   KC_P5,   KC_P6,  KC_PPLS,                      KC_MUTE, KC_LEFT, KC_UP,    KC_RGHT, KC_PSCR, RESET,
      _______,   KC_P0,    KC_P1,   KC_P2,   KC_P3,  KC_PCMM,                      KC_VOLD, KC_END,  KC_DOWN,  KC_PGDN, KC_PAUS, _______,
                         KC_TRNS,KC_UNDS,KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return OLED_ROTATION_270;
}

static void render_named_logo(void) {
  static const char PROGMEM raw_logo[] = {
    12, 60,252,252,252,236,236,140, 12, 28,248,192,  0,192,248,252,252,252,108, 12, 12,140,236, 60, 12,  0,  0,  0,248,252,252,252,236,204,204,204,204,204,204,204,204,204,204,204,204,140, 12,252,248,  0,  0,  0,252,252,252,252,236,236,236,204, 12, 60,240,192,  0,  0,  0,252,252,252,236,236, 12, 12, 12,252,248,  0,  0,192,224, 96, 48, 24, 24,140,140,132,196,196,196,196,132,140,140, 12, 24, 48, 48, 96,192,128,  0,  0,252,252,252,236,236,236,236,140, 28,120,224,128,  0,  0,252,252,252,252,236,236, 12, 12, 12,252,
    0,  0,  0,  3, 15,255,255,255,254,248,192,195,223,255,255, 63, 15,  1,224,248, 30,  7,  1,  0,  0,  0,  0,  0,255,255,255,255,255,255,  0,  0,  1, 63, 63, 51, 51, 51, 51, 51, 51, 51,243,  3,  1,  0,  0,  0,255,255,255,255,255,  1, 15,127,255,252,240,195, 15, 60,240,255,255,255,255,255,  0,  0,  0,255,255,254,255,255,255,127, 14,  2,195,247, 63, 31, 15, 15, 15, 15, 31, 63,255,255,254,252,248,224,  1,  3, 30,252,255,255,255,255,255,  3, 31,255,254,248,225,135, 30,120,255,255,255,255,255,255,  0,  0,  0,255,
    0,  0,128,240,252,255,255,255, 63,  7,  1,227,127,255,255,255,248,224,  1,  7, 62,240,192,  0,  0,  0,  0,  0,255,255,255,255,255,255,  1,  3,  7,255,255,207,207,207,207,207,206,204,207,192,128,  0,  0,  0,255,255,255,255,255,  0,  0,  0,255,255, 15,127,255,252,240,227,143,127,255,255,  0,  0,  0,255,255, 63,255,255,255,254,240,192,131,135, 12, 24, 48, 48, 48, 48, 24, 28, 15,159,255, 63, 31,  7,128,192,120, 31,255,255,255,255,255,  0,  0,  0,255,255, 31,127,255,252,241,199, 31,127,255,255,  0,  0,  0,255,
    48, 62, 63, 63, 63, 63, 63, 56, 48, 60, 31,  3,  0,  3, 31, 63, 63, 63, 63, 60, 60, 56, 59, 63, 56,  0,  0,  0, 31, 63, 63, 63, 63, 63, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 56, 63, 31,  0,  0,  0, 63, 63, 63, 63, 63, 60, 56, 48, 63, 63,  0,  0,  0,  3, 31, 63, 63, 62, 61, 63, 60, 56, 48, 63, 31,  0,  0,  1,  7,  7, 15, 31, 31, 63, 63, 63, 62, 62, 62, 62, 63, 63, 63, 31, 31, 15, 14,  6,  3,  1,  0,  0, 63, 63, 63, 63, 63, 60, 56, 56, 63, 31,  0,  0,  1,  7, 31, 63, 63, 60, 63, 63, 60, 56, 48, 63
  };
  oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void render_logo(void) {
      static const char PROGMEM raw_logo[] = {
        255,  1, 93, 85,117,  1, 49, 41, 37,125, 33,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,255,255,  0,  0,  7, 63,255,254,240,128,192,240,254,255, 63,  7,  0,  0,  0,  0,192,192,224,224,224,224,224,224,192,128,  0,  0,255,255,  0,  0,192,240,254,255, 63,  7,  7, 63,255,254,240,192,  0,  0,  0,127,255,255,239,206,206,206,206,207,207,207, 14,  0,255,255,128,129,129,129,129,128,156,128,128,148,140,133,149,129,128,128,128,144,148,133,145,137,129,157,129,129,129,128,128,128,255
    };
      oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void render_status(void) {
  render_logo();
  //  oled_write_P(PSTR("Xenon by Narinari\n\n"), false);
  //
  //  // Host Keyboard Layer Status
  //  oled_write_P(PSTR("Layer: "), false);
  //  switch (get_highest_layer(layer_state)) {
  //      case _QWERTY:
  //          oled_write_P(PSTR("Default\n"), false);
  //          break;
  //      case _LOWER:
  //          oled_write_P(PSTR("Lower\n"), false);
  //          break;
  //      case _RAISE:
  //          oled_write_P(PSTR("Raise\n"), false);
  //          break;
  //      default:
  //          oled_write_P(PSTR("Undefined\n"), false);
  //  }
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_named_logo();
  }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
	    tap_code(KC_VOLU);
        } else {
	    tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
	    tap_code(KC_PGDN);
        } else {
	    tap_code(KC_PGUP);
        }
    }
}
#endif
