// #define ALT_TAPPING_TERM 175

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // case ENT_LCPS:
//             // return 150;
//         // case BSP_RSH:
//         // case SPC_LSH:
//         // case RCTL_T(KC_QUOT):
//         //     return ALT_TAPPING_TERM;
//         default:
//             return TAPPING_TERM;
//     }
// }

// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // case ENT_LCPS:
//         // case BSP_RSH:
//         // case SPC_LSH:
//         // case RCTL_T(KC_QUOT):
//         //     return true;
//         default:
//             return false;
//     }
// }

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LG_A:
            return true;
        case LA_S:
            return true;
        case LS_D:
            return true;
        case LC_F:
            return true;
        case GR_X:
            return true;
        default:
            return false;
    }
}
