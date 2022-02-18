#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#    include "lufa.h"
#    include "split_util.h"
#endif

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


#undef LAYOUT
#define LAYOUT LAYOUT_split_3x5_3

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_number {
    _QWERTY = 0,
    _SYM,
    _NUM,
    _NAV,
    _FUN,
    _MOUSE,
    _SYMA,
};

enum custom_keycodes { QWERTY = SAFE_RANGE, SYM, NUM, NAV, FUN, MOUSE, SYMA};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_RST RESET

#define KC_CTLTB CTL_T(KC_TAB)


#define SYM MO(_SYM)
#define SYMA MO(_SYMA)
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

#define TAB_FUN LT(_FUN, KC_TAB)
#define SPC_NAV LT(_NAV, KC_SPC)
#define ESC_MOS LT(_MOUSE, KC_ESC)
#define ENT_NUM LT(_NUM, KC_ENT)
#define BSP_SYM LT(_SYM, KC_BSPC)
#define DEL_NAV LT(_NAV, KC_DEL)

#include "taps.c"
#include "hld.c"
#include "cmbs.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(\
            KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                       KC_Y,    KC_U,    KC_I,       KC_O,    KC_P,  \
            LG_A,    LA_S,    LS_D,    LC_F,     KC_G,                       KC_H,    RC_J,    RS_K,       RA_L,    RG_SC,  \
            KC_Z,    GR_X,    KC_C,    KC_V,     KC_B,                       KC_N,    KC_M,    KC_COMM,    GR_DOT,  GR_SL, \
                                    TAB_FUN,  SPC_NAV, ESC_MOS,           ENT_NUM, BSP_SYM, DEL_NAV \
    ),

    [_SYM] = LAYOUT(\
            KC_TILD,   KC_AMPR,  KC_ASTR,    KC_LPRN,   KC_RPRN,                    _______,  _______,   _______, _______, _______, \
            KC_COLN,   KC_DLR,   KC_PERC,    KC_CIRC,   KC_PPLS,                    _______,  _______,   _______, _______, _______,  \
            KC_LCBR,   KC_EXLM,  KC_AT,      KC_HASH,   KC_PIPE,                    _______,  _______,   _______, _______, _______,   \
                                    KC_LPRN,    KC_RPRN,   KC_UNDS,          _______, _______, _______\
    ),

    [_NUM] = LAYOUT(\
            KC_GRV,   KC_7,  KC_8,  KC_9,  KC_BSLS,                    _______,  _______,   _______, _______, _______, \
            KC_SCLN,  KC_4,  KC_5,  KC_6,  KC_EQL,                     _______,  _______,   _______, _______, _______,  \
            KC_LBRC,  KC_1,  KC_2,  KC_3,  KC_RBRC,                    _______,  _______,   _______, _______, _______,   \
                                    _______,    KC_0,   KC_MINS,          _______, _______, _______\
    ),

    [_NAV] = LAYOUT(\
            _______,  _______,   _______, _______, _______,                  KC_VOLU,   KC_HOME,   KC_INS,  KC_PGUP,   KC_DQT,       \
            _______,  _______,   _______, _______, _______,                  KC_MUTE,   KC_LEFT,   KC_UP,   KC_RGHT,   KC_QUOT,        \
            _______,  _______,   _______, _______, _______,                  KC_VOLD,   KC_END,    KC_DOWN, KC_PGDN,   KC_BSLS,       \
                                    _______, _______, _______,            _______, _______,  _______ \
    ),

    [_FUN] = LAYOUT(\
            KC_F12,   KC_F7,    KC_F8,    KC_F9,   KC_PSCR,                 _______,  _______,   _______, _______, _______, \
            KC_F11,   KC_F4,    KC_F5,    KC_F6,   KC_SLCK,                 _______,  _______,   _______, _______, _______,  \
            KC_F10,   KC_F1,    KC_F2,    KC_F3,   KC_PAUS,                 _______,  _______,   _______, _______, _______,   \
                                    _______,    _______,   _______,       _______, _______, KC_APP\
    ),

    [_MOUSE] = LAYOUT(\
            _______,  _______,   _______, _______, _______,                  KC_BTN1,   KC_WH_R,   _______, KC_WH_U,  _______,       \
            _______,  _______,   _______, _______, _______,                  KC_BTN3,   KC_MS_L,   KC_MS_U, KC_MS_R,  _______,        \
            _______,  _______,   _______, _______, _______,                  KC_BTN2,   KC_WH_L,   KC_MS_D, KC_WH_D,  _______,       \
                                    _______, _______, _______,            _______, _______,  _______ \
    ),

    [_SYMA] = LAYOUT(\
            KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,                     KC_F7,   KC_F8,      KC_F9,   KC_F10,  KC_F11, \
            KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,                   KC_CIRC, KC_AMPR,    KC_ASTR, KC_LPRN, KC_RPRN, \
            KC_1,    KC_2,    KC_3,     KC_4,     KC_5,                      KC_6,    KC_7,       KC_8,    KC_9,    KC_0,     \
                                    _______, _______,  _______,          _______, _______, _______\
    )
};


uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _SYMA);
}

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
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
        case _SYM:
            oled_write_P(PSTR(" SYM\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR(" NUM\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR(" NAV\n"), false);
            break;
        case _FUN:
            oled_write_P(PSTR(" FUN\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR(" MSE\n"), false);
            break;
        case _SYMA:
            oled_write_P(PSTR(" SYA\n"), false);
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
