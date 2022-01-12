static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 192, 224, 240, 240, 240, 240, 240, 240, 240, 224,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 112, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 192, 224, 240, 0, 0, 240, 252, 254, 255, 255, 255, 1, 240, 252, 255,
        255, 255, 255, 255, 255, 255, 255, 127, 31, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 254, 254, 254, 0, 0, 240,
        248, 252, 30, 14, 14, 14, 14, 14, 14, 30, 252, 248, 240, 0, 0, 254, 254, 252, 28, 14, 14, 14, 14, 0, 0, 254, 254, 252, 28, 14, 14,
        14, 14, 30, 252, 248, 240, 0, 0, 240, 248, 252, 222, 206, 206, 206, 206, 206, 206, 222, 252, 248, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255, 255, 254, 240, 255, 255, 255, 255, 255, 255, 248, 255, 255, 255, 255,
        255, 255, 255, 255, 255, 193, 128, 128, 128, 192, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 255, 255, 255, 0, 0,
        15, 31, 63, 120, 112, 112, 112, 112, 112, 112, 120, 63, 31, 15, 0, 0, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 127, 127, 127, 0, 0, 0,
        0, 0, 0, 127, 127, 127, 0, 0, 15, 31, 63, 121, 113, 113, 113, 113, 113, 113, 121, 61, 29, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 1, 1, 3, 3, 7, 7, 7, 3, 3, 1, 3, 7, 7, 7, 7, 7, 7, 7, 3, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}
bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        render_logo();
        return false;
    }
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer\n"), false);
    oled_write_P(PSTR("-----\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR(" QWE\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR(" LWR\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR(" RSE\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR(" ADJ\n"), false);
            break;
        case _FIVE:
            oled_write_P(PSTR(" FVE\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("UNDEF\n"), false);
    }
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("-----\n"), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR(" NUM \n") : PSTR("    \n"), false);
    // oled_write_P(led_state.caps_lock ? PSTR(" CAP \n") : PSTR("    \n"), false);
    // oled_write_P(led_state.scroll_lock ? PSTR(" SCR \n") : PSTR("    \n"), false);
    oled_write_P(led_state.num_lock ? PSTR(" N") : PSTR("  "), false);
    oled_write_P(led_state.caps_lock ? PSTR("C") : PSTR(" "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("S \n") : PSTR("  \n"), false);

    return false;
}
