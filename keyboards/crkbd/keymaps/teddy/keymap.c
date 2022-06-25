#include QMK_KEYBOARD_H
#include "bootloader.h"

extern keymap_config_t keymap_config;

#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}},
  {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}},
  {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}},
  {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}},
  {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}},
  {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}},
  {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}},
  {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}},
};
#else
#define SH_TG KC_TRNS
#endif

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ISO,
    _THUMB_ALT,
    _FIVE,
};

enum custom_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE, ADJUST, BACKLIT, RGBRST, KC_SAMPLEMACRO, PLOVER, EXT_PLV, XKBMAP };

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
#define EQL_RCT RCTL_T(KC_EQL)
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
    [_QWERTY] = LAYOUT(\
            LGUI_T(KC_GRV),    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,             KC_Y,    KC_U,    KC_I,       KC_O,    KC_P,            RGUI_T(KC_LBRC),  \
            KC_LCTL,           KC_A,    KC_S,    KC_D,    KC_F,     KC_G,             KC_H,    KC_J,    KC_K,       KC_L,    KC_SCLN,         RCTL_T(KC_QUOT), \
            KC_LALT,           KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,             KC_N,    KC_M,    KC_COMM,    KC_DOT,  KC_SLSH, BSL_RAL, \
                                                 TAB_RSE, SPC_LSH, ESC_LWR,           ENT_LWR, BSP_RSH, DEL_RSE \
    ),

    [_LOWER] = LAYOUT(\
    // F1 is on combo...
            LGUI_T(KC_MINS), KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,            KC_F7,   KC_F8,      KC_F9,   KC_F10,  KC_F11,  RGUI_T(KC_F12),\
            EQL_LCT,         KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, MIN_RCT, \
            _______,         KC_1,    KC_2,    KC_3,     KC_4,     KC_5,             KC_6,    KC_7,    KC_8,       KC_9,    KC_0,    _______, \
                                            _______, _______,  _______,          _______, _______, _______\
    ),

    [_RAISE] = LAYOUT(\
              LGUI_T(KC_NLCK),  KC_PSLS,  KC_7,    KC_8,    KC_9,     KC_MINS,          KC_VOLU, KC_HOME, KC_INS,     KC_PGUP, KC_SLCK, RGUI_T(KC_CAPS), \
              EQL_LCT,          KC_PAST,  KC_4,    KC_5,    KC_6,     KC_PPLS,          KC_MUTE, KC_LEFT, KC_UP,      KC_RGHT, KC_PSCR, APP_RCT, \
              _______,          KC_0,     KC_1,    KC_2,    KC_3,     KC_PCMM,          KC_VOLD, KC_END,  KC_DOWN,    KC_PGDN, KC_PAUS, _______, \
                                          _______, _______,       _______,          _______, _______, _______\
    ),

    /*[_ADJUST] = LAYOUT(\
            CMB_ON,     RESET,   KC_BTN1, KC_BTN3, KC_BTN2,  XKBMAP,           _______, QWERTY,   KC_ASDN,    KC_ASTG, RESET,   CMB_ON,  \
            CMB_TOG,    RGB_HUI, KC_MS_L, KC_MS_U, KC_MS_R,  KC_WH_U,          KC_LEFT, KC_DOWN,  KC_UP,      KC_RGHT, RGB_HUI, CMB_TOG, \
            CMB_OFF,    TG_FIVE, RGB_SAD, KC_MS_D, TG_ISO,   KC_WH_D,          TG_THMB, TG_ISO,   RGB_VAD,    RGB_SAD, TG_FIVE, CMB_OFF, \
                                           _______, SH_TG,   _______,          _______, SH_TG,   _______\
    ),*/

    [_ADJUST] = LAYOUT(\
            _______,    RESET,   KC_BTN1, KC_BTN3, KC_BTN2,  XKBMAP,           KC_BTN2, KC_WH_U,  _______,   KC_WH_R, _______, RESET,   \
            _______,    _______, KC_MS_L, KC_MS_U, KC_MS_R,  KC_WH_U,          KC_BTN3, KC_MS_L,  KC_MS_U,   KC_MS_R, _______, RGB_HUI, \
            _______,    TG_FIVE, KC_WH_L, KC_MS_D, KC_WH_R,  KC_WH_D,          KC_BTN1, KC_WH_D,  KC_MS_D,   KC_WH_L, _______, TG_FIVE, \
                                           _______, SH_TG,   _______,          _______, SH_TG,    _______\
    ),

/*
    [_THUMB_ALT] = LAYOUT(\
             _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, \
             _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, \
                                       DEL_RSE, BSP_RSH,  ENT_LWR,             ESC_LWR, SPC_LSH, TAB_RSE \
    ),

    [_ISO] = LAYOUT(\
            _______,         _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
            LCTL_T(KC_NUBS), _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
            LALT_T(KC_NUHS), _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, KC_RALT, \
                                               _______, _______, _______,      _______, _______, _______\
    ),

    // [_FIVE] = LAYOUT(\
    // _______, _______,         _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, \
    //         LCTL_T(KC_NUBS), _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
    //         LALT_T(KC_NUHS), _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, KC_RALT, \
    //                                             _______, KC_SPC, _______,      _______, KC_SPC, _______\
    // ),
*/
    [_FIVE] = LAYOUT(\
             RGBRST,  RESET,   KC_ASTG, KC_ASDN, _______, _______,             _______, _______,  KC_ASDN, KC_ASTG, RESET, RGBRST, \
             RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, QWERTY,  _______,             _______,  QWERTY,  RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG, \
             RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, TG_FIVE,  TG_THMB,            TG_THMB, TG_ISO,   RGB_VAD, RGB_SAD, RGB_HUD, RGB_MOD, \
                                         _______, SH_TG,   _______,            _______, SH_TG,   _______\
    ),

};


uint32_t layer_state_set_user(uint32_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
    if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
        layer_on(layer3);
    } else {
        layer_off(layer3);
    }
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
    rgblight_step();
#endif
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
// #ifdef SSD1306OLED
//         set_keylog(keycode, record);
// #endif
        // set_timelog();
    }

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << _QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        case RGBRST:
#ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
                RGB_current_mode = rgblight_config.mode;
            }
#endif
            break;
    }
    return true;
}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        // reset_keyboard(); // reset keyboard on capslock (for debugging)
    }
}


#ifdef OLED_ENABLE
const char *read_logo(void);
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}
bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        oled_write(read_logo(), false);
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
        case _FIVE:
            oled_write_P(PSTR(" FVE\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("UNDEF\n"), false);
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
