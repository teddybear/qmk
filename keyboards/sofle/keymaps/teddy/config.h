#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#define SPLIT_USB_DETECT
#define EE_HANDS

#undef TAPPING_TERM
#define TAPPING_TERM 135
#define TAPPING_TERM_PER_KEY

#define COMBO_COUNT 25
#define COMBO_TERM 17
#define PERMISSIVE_HOLD_PER_KEY
#define LEADER_TIMEOUT 500
