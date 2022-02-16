#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FIVE,
  _NAVIP,
  _NUML,
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
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_TAB,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_GRV,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
  KC_LALT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, LRC_NUM,     KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  BSL_RAL,
                 LRC_NUM, KC_LGUI, TAB_RSE, SPC_LSH,    ESC_LWR,                     ENT_LWR,  BSP_RSH,  DEL_RSE, KC_RGUI, KC_RBRC \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_MINS, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,\
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, MIN_RCT, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,  KC_MINS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, \
                        _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV, _______, _______, _______, _______, _______,                     _______, _______, _______,_______, _______, _______,\
  KC_NLCK, KC_PSLS, KC_7,   KC_8,   KC_9,    KC_MINS,                      KC_VOLU, KC_HOME, KC_INS,  KC_PGUP, KC_SLCK, _______, \
  EQL_LCT, KC_PAST, KC_4,   KC_5,   KC_6,    KC_PPLS,                      KC_MUTE, KC_LEFT, KC_UP,   KC_RGHT, KC_PSCR, XXXXXXX, \
  _______, KC_0,    KC_1,   KC_2,   KC_3,    KC_PCMM,   _______, _______,  KC_VOLD, KC_END,  KC_DOWN, KC_PGDN, KC_PAUS, KC_BSLS, \
                        _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  RESET,   TG_FIVE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_U, KC_MS_R, KC_WH_U,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_D, XXXXXXX, KC_WH_D, TG_NAVP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
  ),

  [_FIVE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
                             TG_FIVE, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
  ),

  [_NAVIP] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______,                   _______, KC_HOME, KC_INS,  KC_PGUP, KC_SLCK, _______, \
  _______, _______, KC_MS_L, KC_MS_U, KC_MS_R, KC_WH_U,                   _______, KC_LEFT, KC_UP,   KC_RGHT, KC_PSCR, _______, \
  _______, _______, _______, KC_MS_D, _______, KC_WH_D, TG_NAVP, _______, _______, KC_END,  KC_DOWN, KC_PGDN, KC_PAUS, _______,\
                             _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
  ),

  [_NUML] = LAYOUT( \
  KC_GRV, _______, _______, _______, _______, _______,                     _______, _______, _______,_______, _______, _______,\
  KC_NLCK, KC_PSLS, KC_7,   KC_8,   KC_9,    KC_MINS,                      KC_PSLS, KC_7,    KC_8,   KC_9,    KC_MINS, _______, \
  EQL_LCT, KC_PAST, KC_4,   KC_5,   KC_6,    KC_PPLS,                      KC_PAST, KC_4,    KC_5,   KC_6,    KC_PPLS, _______, \
  _______, KC_0,    KC_1,   KC_2,   KC_3,    KC_PCMM,   _______, _______,  KC_0,    KC_1,    KC_2,   KC_3,    KC_PCMM, _______, \
                             _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
  )
};

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
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}
bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        render_logo();
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
        case _NAVIP:
            oled_write_P(PSTR(" NVE\n"), false);
            break;
        case _NUML:
            oled_write_P(PSTR(" NUM\n"), false);
            break;
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
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
