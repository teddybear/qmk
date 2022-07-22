LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_F) {
            // Anything you can do in a macro.
            SEND_STRING("QMK is awesome.");
        }

        SEQ_ONE_KEY(KC_L) {
            // Anything you can do in a macro.
            register_code(KC_LGUI);
            register_code(KC_L);
            unregister_code(KC_L);
            unregister_code(KC_LGUI);
        }

        SEQ_TWO_KEYS(KC_D, KC_D) {
            SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
        }

        SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
            SEND_STRING("https://start.duckduckgo.com\n");
        }

        SEQ_THREE_KEYS(KC_X, KC_X, KC_X) {
            SEND_STRING("setxkbmap -model pc105 -layout us,ru -option grp:caps_toggle,lv3:ralt_switch,misc:typo -option terminate:ctrl_alt_bksp -option kpdl:dot -option grp_led:scroll\n");
        }

        SEQ_TWO_KEYS(KC_A, KC_S) {
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_Z) {
            register_code(KC_LSFT);
            register_code(KC_1);
            unregister_code(KC_1);
            unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_X) {
            register_code(KC_LSFT);
            register_code(KC_2);
            unregister_code(KC_2);
            unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_C) {
            register_code(KC_LSFT);
            register_code(KC_3);
            unregister_code(KC_3);
            unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_V) {
            register_code(KC_LSFT);
            register_code(KC_4);
            unregister_code(KC_4);
            unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_B) {
            register_code(KC_LSFT);
            register_code(KC_5);
            unregister_code(KC_5);
            unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_N) {
            register_code(KC_LSFT);
            register_code(KC_6);
            unregister_code(KC_6);
            unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_M) {
            register_code(KC_LSFT);
            register_code(KC_7);
            unregister_code(KC_7);
            unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_COMM) {
            register_code(KC_LSFT);
            register_code(KC_8);
            unregister_code(KC_8);
            unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_DOT) {
            register_code(KC_LSFT);
            register_code(KC_9);
            unregister_code(KC_9);
            unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_SPC, KC_SLSH) {
            register_code(KC_LSFT);
            register_code(KC_0);
            unregister_code(KC_0);
            unregister_code(KC_LSFT);
        }
    }
}
