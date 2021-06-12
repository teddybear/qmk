#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#    include "lufa.h"
#    include "split_util.h"
#endif
#ifdef SSD1306OLED
#    include "ssd1306.h"
#endif

#undef LAYOUT
#undef LAYOUT_kc

#define LAYOUT( \
L33,  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, R33, \
      L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
      L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                          L30, L31, L32, R30, R31, R32 \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L33, KC_NO,  KC_NO, L30, L31, L32 }, \
    { R05, R04, R03, R02, R01, R00 }, \
    { R15, R14, R13, R12, R11, R10 }, \
    { R25, R24, R23, R22, R21, R20 }, \
    { R33, KC_NO,  KC_NO, R32, R31, R30 } \
  }

#define LAYOUT_kc( \
L33, L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, R33, \
     L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
     L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                         L30, L31, L32, R30, R31, R32 \
  ) \
  LAYOUT( \
KC_##L33, KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05,                     KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, KC_##R33, \
          KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15,                     KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
          KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25,                     KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
                                                  KC_##L30, KC_##L31, KC_##L32, KC_##R30, KC_##R31, KC_##R32 \
  )

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

enum custom_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE, ADJUST, BACKLIT, RGBRST, KC_SAMPLEMACRO, PLOVER, EXT_PLV };

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

#define RBR_RGU MT(MOD_RGUI, KC_RBRC)
#define F12_RGU MT(MOD_RGUI, KC_F12)
#define PLS_LCT MT(MOD_LCTL, KC_PPLS)
#define EQL_LCT MT(MOD_LCTL, KC_PEQL)
#define APP_LCT MT(MOD_LCTL, KC_APP)
#define EQL_RCT MT(MOD_RCTL, KC_PEQL)
#define QUO_RCT MT(MOD_RCTL, KC_QUOT)
#define APP_RCT MT(MOD_RCTL, KC_APP)
#define MIN_RCT MT(MOD_RCTL, KC_MINS)
#define EQL_LAL MT(MOD_LALT, KC_EQL)
#define BSL_RAL MT(MOD_RALT, KC_BSLS)

#define NBS_LCT MT(MOD_LCTL, KC_NUBS)
#define BSH_LAL MT(MOD_LALT, KC_BSLS)
#define APP_RAL MT(MOD_RALT, KC_APP)

#define BSP_RSH MT(MOD_RSFT, KC_BSPC)
#define SPC_LSH MT(MOD_LSFT, KC_SPC)
#define SPC_RSH MT(MOD_RSFT, KC_SPC)
#define SPC_LWR LT(_LOWER, KC_SPC)
#define BSP_LWR LT(_LOWER, KC_BSPC)
#define DEL_RSE LT(_RAISE, KC_DEL)
#define TAB_RSE LT(_RAISE, KC_TAB)
#define ENT_LWR LT(_LOWER, KC_ENT)
#define ESC_LWR LT(_LOWER, KC_ESC)
#define ESC_LGUI MT(MOD_LGUI, KC_ESC)
#define ENT_LCPS TD(ENT_LWR_CAPS)
#define LCTL_CPS TD(TD_LCTL_CAPS)

enum combos {
//   UIOP_MENU,
//   YUIO_WMENU,
  CPSL,
  CPSLL,
  EQL,
  SMNS,
  MNS,
  PLS,
  LBC,
  RBC,
  LCB,
  RCB,
  LPN,
  RPN,
  QUO,
  SPCC,
  BKSP,
  BKSL,
  LALTC,
  RALTC,
};


const uint16_t PROGMEM caps_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM capsl_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM mns_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM pls_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM ji_combo[] = {KC_J, KC_I, COMBO_END};
const uint16_t PROGMEM fe_combo[] = {KC_F, KC_E, COMBO_END};
const uint16_t PROGMEM uiop_combo[] = {KC_U, KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM yuio_combo[] = {KC_Y, KC_U, KC_I, KC_O, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [CPSL] = COMBO(caps_combo, KC_CAPS),
  [CPSLL] = COMBO(capsl_combo, KC_CAPS),
  [EQL] = COMBO(eql_combo, KC_EQL),
  [SMNS] = COMBO(mns_combo, KC_MINS),
  [MNS] = COMBO(kl_combo, KC_MINS),
  [PLS] = COMBO(pls_combo, KC_PPLS),
  [LBC] = COMBO(rt_combo, KC_LBRC),
  [RBC] = COMBO(yu_combo, KC_RBRC),
  [LCB] = COMBO(fg_combo, KC_LPRN),
  [RCB] = COMBO(hj_combo, KC_RPRN),
  [LPN] = COMBO(vb_combo, KC_LCBR),
  [RPN] = COMBO(nm_combo, KC_RCBR),
  [QUO] = COMBO(cv_combo, KC_QUOT),
  [SPCC] = COMBO(io_combo, KC_SPC),
  [BKSP] = COMBO(er_combo, KC_BSPC),
  [BKSL] = COMBO(commdot_combo, KC_BSLS),
  [LALTC] = COMBO(ji_combo, KC_LALT),
  [RALTC] = COMBO(fe_combo, KC_LALT),
//   [UIOP_MENU] = COMBO_ACTION(uiop_combo),
//   [YUIO_WMENU] = COMBO_ACTION(yuio_combo),
};

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case UIOP_MENU:
//       if (pressed) {
//         tap_code16(LALT(KC_P));
//       }
//       break;
//     case YUIO_WMENU:
//       if (pressed) {
//         tap_code16(LGUI(KC_P));
//       }
//       break;
//     case EQL:
//        if (pressed) {
//         register_code16(KC_EQL);
//       } else {
//           unregister_code16(KC_EQL);
//       }
//       break;
//     case SPCC:
//        if (pressed) {
//         register_code16(KC_SPC);
//       } else {
//           unregister_code16(KC_SPC);
//       }
//       break;
//   }
// }

enum {
    ENT_LWR_CAPS, // Our custom tap dance key; add any other tap dance keys to this enum
    TD_LCTL_CAPS,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(\
    ESC_LGUI, KC_GRV,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,       KC_O,    KC_P,    KC_LBRC, RGUI_T(KC_RBRC), \
              KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,       KC_L,    KC_SCLN, RCTL_T(KC_QUOT), \
              KC_LALT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM,    KC_DOT,  KC_SLSH, BSL_RAL, \
                                          TAB_RSE, SPC_LSH, ENT_LWR,     ENT_LWR, BSP_RSH, DEL_RSE \
    ),

    [_LOWER] = LAYOUT(\
    _______, KC_UNDS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  F12_RGU, \
            PLS_LCT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, MIN_RCT, \
            EQL_LAL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
                                        _______, _______, _______,      _______, _______, _______\
    ),

    [_RAISE] = LAYOUT(\
    _______, KC_NLCK, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,      KC_VOLU, KC_HOME, KC_INS,   KC_PGUP, KC_SLCK, KC_CAPS, _______, \
            EQL_LCT, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,      KC_MUTE, KC_LEFT, KC_UP,    KC_RGHT, KC_PSCR,  APP_RCT, \
            _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PCMM,      KC_VOLD, KC_END,  KC_DOWN,  KC_PGDN, KC_PAUS, _______, \
                                        _______, _______, _______,      _______, _______, _______\
    ),

    [_ADJUST] = LAYOUT(\
    RESET,  CMB_ON,  KC_ASUP, KC_BTN1, KC_BTN3, KC_BTN2, PLOVER,      PLOVER, QWERTY,  KC_ASDN, KC_ASTG, KC_ASUP, CMB_ON,   RESET, \
            CMB_TOG, RGB_HUI, KC_MS_L, KC_MS_U, KC_MS_R, KC_WH_U,       KC_LEFT,  KC_DOWN,  KC_UP, KC_RGHT, RGB_HUI, CMB_TOG, \
            CMB_OFF, TG_FIVE, RGB_SAD, KC_MS_D, TG_ISO,  KC_WH_D,      TG_THMB, TG_ISO,  RGB_VAD, RGB_SAD, TG_FIVE, CMB_OFF, \
                                        _______, SH_TG,   _______,      _______, SH_TG,   _______\
    ),


    [_THUMB_ALT] = LAYOUT(\
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, \
            _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
            _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
                                        DEL_RSE, BSP_RSH, ENT_LCPS,      ENT_LWR, SPC_LSH, TAB_RSE \
    ),

    [_ISO] = LAYOUT(\
    _______, _______,         _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, \
            LCTL_T(KC_NUBS), _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
            LALT_T(KC_NUHS), _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, KC_RALT, \
                                                _______, _______, _______,      _______, _______, _______\
    ),

    [_FIVE] = LAYOUT(\
    _______, _______,         _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, \
            LCTL_T(KC_NUBS), _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
            LALT_T(KC_NUHS), _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, KC_RALT, \
                                                _______, KC_SPC, _______,      _______, KC_SPC, _______\
    ),

};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_UNKNOWN,
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void ent_lw_finished(qk_tap_dance_state_t *state, void *user_data);
void ent_lw_reset(qk_tap_dance_state_t *state, void *user_data);

// Determine the tapdance state to return
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    // bool is_new_dance = QK_TAP_DANCE <= state->interrupting_keycode && state->interrupting_keycode <= QK_TAP_DANCE_MAX;

    // if (state->count == 1) {
    //     if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
    //     else return TD_SINGLE_HOLD;
    // }
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        return TD_SINGLE_HOLD;
    }
    else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    } else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// td_state_t cur_dance(qk_tap_dance_state_t *state) {
//     int current_state = 0;
//     bool is_new_dance = QK_TAP_DANCE <= state->interrupting_keycode && state->interrupting_keycode <= QK_TAP_DANCE_MAX;

//     // if (state->count == 1) {
//     //     if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//     //     else return TD_SINGLE_HOLD;
//     // }
//     if (state->count == 1) {
//         if (!state->pressed) return TD_SINGLE_TAP;
//         return TD_SINGLE_HOLD;
//     }
//     else if (state->count == 2) {
//         // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
//         // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
//         // keystrokes of the key, and not the 'double tap' action/macro.
//         if (state->interrupted)
//             return TD_DOUBLE_SINGLE_TAP;
//         else if (state->pressed)
//             return TD_DOUBLE_HOLD;
//         else
//             return TD_DOUBLE_TAP;
//     } else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
// }

// Handle the possible states for each tapdance keycode you define:

void ent_lw_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_ENT);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_LOWER);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_CAPS);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            register_code16(KC_CAPS);
            break;
        case TD_DOUBLE_HOLD:
            register_code16(KC_ENT);
            break;
        default:
            register_code16(KC_ENT);
            break;
    }
}

void ent_lw_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_HOLD:
            layer_off(_LOWER);
            break;
        case TD_SINGLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_HOLD:
        default:
            unregister_code16(KC_ENT);
            break;
    }
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [ENT_LWR_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_lw_finished, ent_lw_reset),
    [TD_LCTL_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_CAPS),
};

#define ALT_TAPPING_TERM 175

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENT_LCPS:
            return 150;
        case BSP_RSH:
        case SPC_LSH:
        case RCTL_T(KC_QUOT):
            return ALT_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENT_LCPS:
        case BSP_RSH:
        case SPC_LSH:
        case RCTL_T(KC_QUOT):
            return true;
        default:
            return false;
    }
}


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
// SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
    iota_gfx_init(!has_usb());  // turns on the display
#endif
}

// SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) { iota_gfx_task(); }

void matrix_render_user(struct CharacterMatrix *matrix) {
    // if (is_master) {
        // If you want to change the display of OLED, you need to change here
        matrix_write_ln(matrix, read_layer_state());
        matrix_write_ln(matrix, read_keylog());
        // matrix_write_ln(matrix, read_keylogs());
        // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
        // matrix_write_ln(matrix, read_host_led_state());
        // matrix_write_ln(matrix, read_timelog());
    // }
    // else {
    //     matrix_write(matrix, read_logo());
    // }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
    if (memcmp(dest->display, source->display, sizeof(dest->display))) {
        memcpy(dest->display, source->display, sizeof(dest->display));
        dest->dirty = true;
    }
}

void iota_gfx_task_user(void) {
    struct CharacterMatrix matrix;
    matrix_clear(&matrix);
    matrix_render_user(&matrix);
    matrix_update(&display, &matrix);
}
#endif  // SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef SSD1306OLED
        set_keylog(keycode, record);
#endif
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

