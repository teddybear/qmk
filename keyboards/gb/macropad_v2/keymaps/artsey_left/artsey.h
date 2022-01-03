#pragma once
#include "quantum.h"



enum layers {
  _A_BASE = 0,
  _A_NUM,
  _A_SYM,
  _A_BRAC,
  _A_NAV,
  _A_MOU,
  _A_CUSTOM,
  _A_RGB,
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOCK_SHIFT,
A_BASE_AR,
A_BASE_AT,
A_BASE_AS,
A_BASE_RT,
A_BASE_RS,
A_BASE_TS,
A_BASE_ART,
A_BASE_ARS,
A_BASE_ATS,
A_BASE_RTS,
A_BASE_EY,
A_BASE_EI,
A_BASE_EO,
A_BASE_YI,
A_BASE_YO,
A_BASE_IO,
A_BASE_EYI,
A_BASE_EYO,
A_BASE_EIO,
A_BASE_YIO,
A_BASE_ARTS,
A_BASE_AYI,
A_BASE_AY,
A_BASE_AI,
A_BASE_TI,
A_BASE_AO,
A_BASE_RE,
A_NUM_RE,
A_SYM_RE,
A_BRAC_RE,
A_NAV_RE,
A_MOU_RE,
A_CUSTOM_RE,
A_BASE_RTSE,
A_NUM_RTSE,
A_SYM_RTSE,
A_BRAC_RTSE,
A_NAV_RTSE,
A_MOU_RTSE,
A_CUSTOM_RTSE,
A_BASE_AE,
A_NUM_AE,
A_SYM_AE,
A_BRAC_AE,
A_NAV_AE,
A_MOU_AE,
A_CUSTOM_AE,
A_BASE_ARO,
A_NUM_ARO,
A_SYM_ARO,
A_BRAC_ARO,
A_NAV_ARO,
A_MOU_ARO,
A_CUSTOM_ARO,
A_BASE_SE,
A_NUM_SE,
A_SYM_SE,
A_BRAC_SE,
A_NAV_SE,
A_MOU_SE,
A_CUSTOM_SE,
A_BASE_SY,
A_NUM_SY,
A_SYM_SY,
A_BRAC_SY,
A_NAV_SY,
A_MOU_SY,
A_CUSTOM_SY,
A_BASE_SI,
A_NUM_SI,
A_SYM_SI,
A_BRAC_SI,
A_NAV_SI,
A_MOU_SI,
A_CUSTOM_SI,
A_BASE_EYIO,
A_NUM_EYIO,
A_SYM_EYIO,
A_BRAC_EYIO,
A_NAV_EYIO,
A_MOU_EYIO,
A_CUSTOM_EYIO,
A_BASE_ARTO,
A_NUM_ARTO,
A_SYM_ARTO,
A_BRAC_ARTO,
A_NAV_ARTO,
A_MOU_ARTO,
A_CUSTOM_ARTO,
A_BASE_RY,
A_NUM_RY,
A_SYM_RY,
A_BRAC_RY,
A_NAV_RY,
A_MOU_RY,
A_CUSTOM_RY,
A_NUM_AR,
A_NUM_RT,
A_NUM_EY,
A_NUM_YI,
A_BASE_ATY,
A_NUM_ATY,
A_SYM_ATY,
A_BRAC_ATY,
A_NAV_ATY,
A_CUSTOM_ATY,
A_MOU_ATY,
A_BASE_REI,
A_NUM_REI,
A_SYM_REI,
A_BRAC_REI,
A_MOU_REI,
A_CUSTOM_REI,
A_NAV_REI,
A_BASE_SO,
A_CUSTOM_SO,
A_BASE_AYIO,
A_BASE_A = LT(_A_BRAC,KC_A),
A_BASE_R = KC_R,
A_BASE_T = KC_T,
A_BASE_S = LT(_A_NUM,KC_S),
A_BASE_E = LT(_A_SYM,KC_E),
A_BASE_Y = KC_Y,
A_BASE_I = KC_I,
A_BASE_O = LT(_A_CUSTOM,KC_O),
A_NUM_A = KC_1,
A_NUM_R = KC_2,
A_NUM_T = KC_3,
A_NUM_S,
A_NUM_E = KC_4,
A_NUM_Y = KC_5,
A_NUM_I = KC_6,
A_NUM_O,
A_NAV_A = KC_END,
A_NAV_R = KC_UP,
A_NAV_T = KC_HOME,
A_NAV_S = KC_PGUP,
A_NAV_E = KC_RIGHT,
A_NAV_Y = KC_DOWN,
A_NAV_I = KC_LEFT,
A_NAV_O = KC_PGDOWN,
A_BRAC_A,
A_BRAC_R = KC_RPRN,
A_BRAC_T = KC_LPRN,
A_BRAC_S = KC_RCBR,
A_BRAC_E,
A_BRAC_Y = KC_RBRC,
A_BRAC_I = KC_LBRC,
A_BRAC_O = KC_LCBR,
A_SYM_A = KC_EXLM,
A_SYM_R = KC_BSLS,
A_SYM_T = KC_SCLN,
A_SYM_S = KC_GRAVE,
A_SYM_E,
A_SYM_Y = KC_QUES,
A_SYM_I = KC_MINS,
A_SYM_O = KC_EQL,
A_MOU_A = KC_MS_BTN1,
A_MOU_R = KC_MS_UP,
A_MOU_T = KC_MS_BTN2,
A_MOU_S = KC_WH_U,
A_MOU_E = KC_MS_RIGHT,
A_MOU_Y = KC_MS_DOWN,
A_MOU_I = KC_MS_LEFT,
A_MOU_O = KC_WH_D,
A_CUSTOM_A = KC__MUTE,
A_CUSTOM_R = KC_INS,
A_CUSTOM_T = KC__VOLUP,
A_CUSTOM_S = LT(_A_RGB, KC_DEL),
A_CUSTOM_E = KC_RSFT,
A_CUSTOM_Y = KC_PSCR,
A_CUSTOM_I = KC__VOLDOWN,
A_CUSTOM_O,
 };
