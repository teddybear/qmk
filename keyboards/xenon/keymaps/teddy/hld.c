#define ALT_TAPPING_TERM 175

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case ENT_LCPS:
        //     return 150;
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
        // case ENT_LCPS:
        case TAB_RSE:
        case ESC_LWR:
        case ENT_LWR:
        case DEL_RSE:
            return true;
        default:
            return false;
    }
}
