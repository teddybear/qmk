bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LG_A:
        case LA_S:
        case LS_D:
        case LC_F:
        case GR_X:
        case RG_SC:
        case RA_L:
        case RS_K:
        case RC_J:
        case GR_DOT:
            return true;
        // case LS_Q:
        // case LC_A:
        // case LA_Z:
        // case RA_SL:
        // case RS_P:
        // case RC_SC:
        //     return true;
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LG_A:
        case LA_S:
        case LS_D:
        case LC_F:
        case GR_X:
        case RG_SC:
        case RA_L:
        case RS_K:
        case RC_J:
        case GR_DOT:
            return true;
        // case LS_Q:
        // case LC_A:
        // case LA_Z:
        // case RA_SL:
        // case RS_P:
        // case RC_SC:
        //     return true;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LG_A:
        case LA_S:
        case LS_D:
        case LC_F:
        case GR_X:
        case RG_SC:
        case RA_L:
        case RS_K:
        case RC_J:
        case GR_DOT:
            return true;
        // case LS_Q:
        // case LC_A:
        // case LA_Z:
        // case RA_SL:
        // case RS_P:
        // case RC_SC:
        //     return true;
        default:
            return false;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LG_A:
        case LA_S:
        case LS_D:
        case LC_F:
        case GR_X:
        case RG_SC:
        case RA_L:
        case RS_K:
        case RC_J:
        case GR_DOT:
            return true;
        // case LS_Q:
        // case LC_A:
        // case LA_Z:
        // case RA_SL:
        // case RS_P:
        // case RC_SC:
        //     return true;
        default:
            return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return false;
    // switch (keycode) {
    //     case LG_A:
    //     case LA_S:
    //     case LS_D:
    //     case LC_F:
    //     case GR_X:
    //     case GR_SL:
    //     case RG_SC:
    //     case RA_L:
    //     case RS_K:
    //     case RC_J:
    //     case GR_DOT:
    //         return true;
    //    // case LS_Q:
    //    // case LC_A:
    //    // case LA_Z:
    //    // case RA_SL:
    //    // case RS_P:
    //    // case RC_SC:
    //    //     return true;
    //     default:
    //         return false;
    // }
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LG_A:
        case LA_S:
        case LS_D:
        case LC_F:
        case GR_X:
        case RG_SC:
        case RA_L:
        case RS_K:
        case RC_J:
        case GR_DOT:
            return 200;
        // case LS_Q:
        // case LC_A:
        // case LA_Z:
        // case RA_SL:
        // case RS_P:
        // case RC_SC:
        //     return 200;
        default:
            return 150;
    }
}
