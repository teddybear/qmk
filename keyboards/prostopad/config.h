/* Copyright 2021 ProstoPAD
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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4443
#define PRODUCT_ID      0x6463
#define DEVICE_VER      0x0001
#define MANUFACTURER    sergzver85
#define PRODUCT         ProstoPAD

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 5

/* key matrix pins */
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F7, B1, B3, B2, B6 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTION 2

/* LED layer indicators */
#define LAYER_INDICATOR_LED_0 D3
#define LAYER_INDICATOR_LED_1 D2

/* media key slowdown for windows */
#define TAP_CODE_DELAY 20

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Underlight configuration */
#define RGB_DI_PIN F4
#define RGBLED_NUM 9
#define RGBLIGHT_ANIMATIONS

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 1
