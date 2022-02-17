#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE, ADJUST, BACKLIT, RGBRST, KC_SAMPLEMACRO, PLOVER, EXT_PLV, XKBMAP};

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
#define TG_NAVP TG(_NAVIP)

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
#define LRC_NUM LT(_NUML, KC_LBRC)
#define ESC_LGUI LGUI_T(KC_ESC)

#include "hld.c"
#include "cmbs.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    LGUI_T(KC_GRV),    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,             KC_Y,    KC_U,    KC_I,       KC_O,    KC_P,            RGUI_T(KC_LBRC),  \
    KC_LCTL,           KC_A,    KC_S,    KC_D,    KC_F,     KC_G,             KC_H,    KC_J,    KC_K,       KC_L,    KC_SCLN,         RCTL_T(KC_QUOT), \
    KC_LALT,           KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,             KC_N,    KC_M,    KC_COMM,    KC_DOT,  KC_SLSH, BSL_RAL, \
                       KC_MUTE, KC_LGUI, TAB_RSE, SPC_LSH,  ESC_LWR,      ENT_LWR,  BSP_RSH,  DEL_RSE, KC_RGUI,  KC_MPLY,
                                KC_LGUI, TAB_RSE, SPC_LSH,  ESC_LWR,      ENT_LWR,  BSP_RSH,  DEL_RSE, KC_RGUI
    ),
    [_LOWER] = LAYOUT(
    LGUI_T(KC_MINS), KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,            KC_F7,   KC_F8,      KC_F9,   KC_F10,  KC_F11,  RGUI_T(KC_F12),\
    EQL_LCT,         KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, MIN_RCT, \
    _______,         KC_1,    KC_2,    KC_3,     KC_4,     KC_5,             KC_6,    KC_7,    KC_8,       KC_9,    KC_0,    _______, \
                        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_RAISE] = LAYOUT(
    LGUI_T(KC_NLCK),  KC_PSLS,  KC_7,    KC_8,    KC_9,     KC_MINS,          KC_VOLU, KC_HOME, KC_INS,     KC_PGUP, KC_SLCK, RGUI_T(KC_CAPS), \
    EQL_LCT,          KC_PAST,  KC_4,    KC_5,    KC_6,     KC_PPLS,          KC_MUTE, KC_LEFT, KC_UP,      KC_RGHT, KC_PSCR, APP_RCT, \
    _______,          KC_0,     KC_1,    KC_2,    KC_3,     KC_PCMM,          KC_VOLD, KC_END,  KC_DOWN,    KC_PGDN, KC_PAUS, _______, \
                         KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [_ADJUST] = LAYOUT(
    _______,    RESET,   KC_BTN1, KC_BTN3, KC_BTN2,  XKBMAP,           _______, _______,  _______,   _______, RESET,   _______, \
    _______,    _______, KC_MS_L, KC_MS_U, KC_MS_R,  KC_WH_U,          KC_LEFT, KC_DOWN,  KC_UP,     KC_RGHT, RGB_HUI, _______, \
    _______,    _______, _______, KC_MS_D, _______,  KC_WH_D,          _______, _______,  _______,   _______, _______, _______, \
                         KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
    )
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
// #endif
//   return true;
// }

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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

#ifdef OLED_ENABLE
static void render_named_logo(void) {
  static const char PROGMEM raw_logo[] = {
    12, 60,252,252,252,236,236,140, 12, 28,248,192,  0,192,248,252,252,252,108, 12, 12,140,236, 60, 12,  0,  0,  0,248,252,252,252,236,204,204,204,204,204,204,204,204,204,204,204,204,140, 12,252,248,  0,  0,  0,252,252,252,252,236,236,236,204, 12, 60,240,192,  0,  0,  0,252,252,252,236,236, 12, 12, 12,252,248,  0,  0,192,224, 96, 48, 24, 24,140,140,132,196,196,196,196,132,140,140, 12, 24, 48, 48, 96,192,128,  0,  0,252,252,252,236,236,236,236,140, 28,120,224,128,  0,  0,252,252,252,252,236,236, 12, 12, 12,252,
    0,  0,  0,  3, 15,255,255,255,254,248,192,195,223,255,255, 63, 15,  1,224,248, 30,  7,  1,  0,  0,  0,  0,  0,255,255,255,255,255,255,  0,  0,  1, 63, 63, 51, 51, 51, 51, 51, 51, 51,243,  3,  1,  0,  0,  0,255,255,255,255,255,  1, 15,127,255,252,240,195, 15, 60,240,255,255,255,255,255,  0,  0,  0,255,255,254,255,255,255,127, 14,  2,195,247, 63, 31, 15, 15, 15, 15, 31, 63,255,255,254,252,248,224,  1,  3, 30,252,255,255,255,255,255,  3, 31,255,254,248,225,135, 30,120,255,255,255,255,255,255,  0,  0,  0,255,
    0,  0,128,240,252,255,255,255, 63,  7,  1,227,127,255,255,255,248,224,  1,  7, 62,240,192,  0,  0,  0,  0,  0,255,255,255,255,255,255,  1,  3,  7,255,255,207,207,207,207,207,206,204,207,192,128,  0,  0,  0,255,255,255,255,255,  0,  0,  0,255,255, 15,127,255,252,240,227,143,127,255,255,  0,  0,  0,255,255, 63,255,255,255,254,240,192,131,135, 12, 24, 48, 48, 48, 48, 24, 28, 15,159,255, 63, 31,  7,128,192,120, 31,255,255,255,255,255,  0,  0,  0,255,255, 31,127,255,252,241,199, 31,127,255,255,  0,  0,  0,255,
    48, 62, 63, 63, 63, 63, 63, 56, 48, 60, 31,  3,  0,  3, 31, 63, 63, 63, 63, 60, 60, 56, 59, 63, 56,  0,  0,  0, 31, 63, 63, 63, 63, 63, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 56, 63, 31,  0,  0,  0, 63, 63, 63, 63, 63, 60, 56, 48, 63, 63,  0,  0,  0,  3, 31, 63, 63, 62, 61, 63, 60, 56, 48, 63, 31,  0,  0,  1,  7,  7, 15, 31, 31, 63, 63, 63, 62, 62, 62, 62, 63, 63, 63, 31, 31, 15, 14,  6,  3,  1,  0,  0, 63, 63, 63, 63, 63, 60, 56, 56, 63, 31,  0,  0,  1,  7, 31, 63, 63, 60, 63, 63, 60, 56, 48, 63
  };
  oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

// static void render_logo(void) {
//       static const char PROGMEM raw_logo[] = {
//         255,  1, 93, 85,117,  1, 49, 41, 37,125, 33,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,255,255,  0,  0,  7, 63,255,254,240,128,192,240,254,255, 63,  7,  0,  0,  0,  0,192,192,224,224,224,224,224,224,192,128,  0,  0,255,255,  0,  0,192,240,254,255, 63,  7,  7, 63,255,254,240,192,  0,  0,  0,127,255,255,239,206,206,206,206,207,207,207, 14,  0,255,255,128,129,129,129,129,128,156,128,128,148,140,133,149,129,128,128,128,144,148,133,145,137,129,157,129,129,129,128,128,128,255
//     };
//       oled_write_raw_P(raw_logo, sizeof(raw_logo));
// }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}
bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        render_named_logo();
        return false;
    }
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer\n"), false);
    oled_write_P(PSTR("-----\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR(" QWE\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR(" LWR\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR(" RSE\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR(" ADJ\n"), false);
            break;
        // case _FIVE:
        //     oled_write_P(PSTR(" FVE\n"), false);
        //     break;
        // case _NAVIP:
        //     oled_write_P(PSTR(" NVE\n"), false);
        //     break;
        // case _NUML:
        //     oled_write_P(PSTR(" NUM\n"), false);
        //     break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("UNDEF\n"), false);
            break;
    }
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("-----\n"), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR(" NUM \n") : PSTR("    \n"), false);
    // oled_write_P(led_state.caps_lock ? PSTR(" CAP \n") : PSTR("    \n"), false);
    // oled_write_P(led_state.scroll_lock ? PSTR(" SCR \n") : PSTR("    \n"), false);
    oled_write_P(led_state.num_lock ? PSTR(" N") : PSTR("  "), false);
    oled_write_P(led_state.caps_lock ? PSTR("C") : PSTR(" "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("S \n") : PSTR("  \n"), false);

    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
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
    return true;
}
#endif
