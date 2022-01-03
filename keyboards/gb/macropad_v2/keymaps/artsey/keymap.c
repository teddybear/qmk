//REPLACE THIS WITH YOUR KEYBOARD.h
#include "macropad_v2.h"

//MAKE SURE THESE ARE INCLUDED
#include "artsey.h"
#include "keymap_combo.h"
#include "artsey.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_A_BASE] = LAYOUT_ortho_2x4(A_BASE_A,A_BASE_R,A_BASE_T,A_BASE_S,
A_BASE_E,A_BASE_Y,A_BASE_I,A_BASE_O),

[_A_NUM] = LAYOUT_ortho_2x4(A_NUM_A,A_NUM_R,A_NUM_T,A_NUM_S,
A_NUM_E,A_NUM_Y,A_NUM_I,A_NUM_O),

[_A_NAV] = LAYOUT_ortho_2x4(A_NAV_A,A_NAV_R,A_NAV_T,A_NAV_S,
A_NAV_E,A_NAV_Y,A_NAV_I,A_NAV_O),

[_A_SYM] = LAYOUT_ortho_2x4(A_SYM_A,A_SYM_R,A_SYM_T,A_SYM_S,
A_SYM_E,A_SYM_Y,A_SYM_I,A_SYM_O),

[_A_BRAC] = LAYOUT_ortho_2x4(A_BRAC_A,A_BRAC_R,A_BRAC_T,A_BRAC_S,
A_BRAC_E,A_BRAC_Y,A_BRAC_I,A_BRAC_O),

[_A_MOU] = LAYOUT_ortho_2x4(A_MOU_A,A_MOU_R,A_MOU_T,A_MOU_S,
A_MOU_E,A_MOU_Y,A_MOU_I,A_MOU_O),

[_A_CUSTOM] = LAYOUT_ortho_2x4(A_CUSTOM_A,A_CUSTOM_R,A_CUSTOM_T,A_CUSTOM_S,
A_CUSTOM_E,A_CUSTOM_Y,A_CUSTOM_I,A_CUSTOM_O),

[_A_RGB] = LAYOUT_ortho_2x4(
    RGB_SPI, RGB_HUI, RGB_VAI, KC_TRNS,
    RGB_SPD, RGB_HUD, RGB_VAD, RGB_MOD
),

};
