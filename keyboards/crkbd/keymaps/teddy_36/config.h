/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

//#define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS
#define USE_SERIAL_PD2

#define SPLIT_USB_DETECT

#pragma once

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 160
#define TAPPING_TERM_PER_KEY
// Configure the global tapping term (default: 200ms)
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD_PER_KEY
// #define PERMISSIVE_HOLD_PER_KEY
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// #define RETRO_TAPPING_PER_KEY

// #define COMBO_COUNT 30
#define COMBO_TERM 17
#define LEADER_TIMEOUT 500
