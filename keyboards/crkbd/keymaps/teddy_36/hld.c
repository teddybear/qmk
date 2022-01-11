bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LG_A:
        case LA_S:
        case LS_D:
        case LC_F:
        case GR_X:
        case GR_SL:
        case RG_SC:
        case RA_L:
        case RS_K:
        case RC_J:
        case GR_DOT:
            return true;
        default:
            return false;
    }
}
