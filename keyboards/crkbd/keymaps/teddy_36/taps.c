// #define ENT_LCPS TD(ENT_LWR_CAPS)
// #define LCTL_CPS TD(TD_LCTL_CAPS)

// enum tap_dances{
//     ENT_LWR_CAPS, // Our custom tap dance key; add any other tap dance keys to this enum
//     TD_LCTL_CAPS,
// };


// // Define a type containing as many tapdance states as you need
// typedef enum {
//     TD_NONE,
//     TD_SINGLE_TAP,
//     TD_SINGLE_HOLD,
//     TD_DOUBLE_TAP,
//     TD_DOUBLE_HOLD,
//     TD_DOUBLE_SINGLE_TAP,
//     TD_UNKNOWN,
// } td_state_t;

// // Create a global instance of the tapdance state type
// static td_state_t td_state;

// // Declare your tapdance functions:

// // Function to determine the current tapdance state
// td_state_t cur_dance(qk_tap_dance_state_t *state);

// // `finished` and `reset` functions for each tapdance keycode
// void ent_lw_finished(qk_tap_dance_state_t *state, void *user_data);
// void ent_lw_reset(qk_tap_dance_state_t *state, void *user_data);

// // Determine the tapdance state to return
// td_state_t cur_dance(qk_tap_dance_state_t *state) {
//     // bool is_new_dance = QK_TAP_DANCE <= state->interrupting_keycode && state->interrupting_keycode <= QK_TAP_DANCE_MAX;

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

// // td_state_t cur_dance(qk_tap_dance_state_t *state) {
// //     int current_state = 0;
// //     bool is_new_dance = QK_TAP_DANCE <= state->interrupting_keycode && state->interrupting_keycode <= QK_TAP_DANCE_MAX;

// //     // if (state->count == 1) {
// //     //     if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
// //     //     else return TD_SINGLE_HOLD;
// //     // }
// //     if (state->count == 1) {
// //         if (!state->pressed) return TD_SINGLE_TAP;
// //         return TD_SINGLE_HOLD;
// //     }
// //     else if (state->count == 2) {
// //         // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
// //         // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
// //         // keystrokes of the key, and not the 'double tap' action/macro.
// //         if (state->interrupted)
// //             return TD_DOUBLE_SINGLE_TAP;
// //         else if (state->pressed)
// //             return TD_DOUBLE_HOLD;
// //         else
// //             return TD_DOUBLE_TAP;
// //     } else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
// // }

// // Handle the possible states for each tapdance keycode you define:

// void ent_lw_finished(qk_tap_dance_state_t *state, void *user_data) {
//     td_state = cur_dance(state);
//     switch (td_state) {
//         case TD_SINGLE_TAP:
//             register_code16(KC_ENT);
//             break;
//         case TD_SINGLE_HOLD:
//             layer_on(_LOWER);
//             break;
//         case TD_DOUBLE_TAP:
//             tap_code16(KC_CAPS);
//             break;
//         case TD_DOUBLE_SINGLE_TAP:
//             register_code16(KC_CAPS);
//             break;
//         case TD_DOUBLE_HOLD:
//             register_code16(KC_ENT);
//             break;
//         default:
//             register_code16(KC_ENT);
//             break;
//     }
// }

// void ent_lw_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (td_state) {
//         case TD_SINGLE_HOLD:
//             layer_off(_LOWER);
//             break;
//         case TD_SINGLE_TAP:
//         case TD_DOUBLE_SINGLE_TAP:
//         case TD_DOUBLE_HOLD:
//         default:
//             unregister_code16(KC_ENT);
//             break;
//     }
// }

// // Associate our tap dance key with its functionality
// qk_tap_dance_action_t tap_dance_actions[] = {
//     [ENT_LWR_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_lw_finished, ent_lw_reset),
//     [TD_LCTL_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_CAPS),
// };
