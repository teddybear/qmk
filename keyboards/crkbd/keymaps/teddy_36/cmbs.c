#define LG_A LGUI_T(KC_A)
#define LA_S LALT_T(KC_S)
#define LS_D LSFT_T(KC_D)
#define LC_F LCTL_T(KC_F)
#define GR_X RALT_T(KC_X)
#define GR_SL RALT_T(KC_SLSH)

#define RG_SC RGUI_T(KC_SCLN)
#define RA_L LALT_T(KC_L)
#define RS_K RSFT_T(KC_K)
#define RC_J RCTL_T(KC_J)
#define GR_DOT RALT_T(KC_DOT)

enum combos {
    OP_MENU,
    UIOP_MENU,
    YUIO_MENU,
    CPSL,
    CPSLL,
    EQL,
    SMNS,
    MNS,
    PLS,
    LBC,
    RBC,
    LCB,
    RCB,
    LPN,
    RPN,
    QUO,
    SPCC,
    BKSP,
    BKSL,
    LALTC,
    RALTC,
    TY,
    TEH_LEAD,
    ENTT,
    SPC4,
};


const uint16_t PROGMEM jk_combo[] = {RC_J, RS_K, COMBO_END};
const uint16_t PROGMEM df_combo[] = {LS_D, LC_F, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {RA_L, RG_SC, COMBO_END};
const uint16_t PROGMEM lsemi_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {LC_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, RC_J, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {RS_K, RA_L, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, GR_DOT, COMBO_END};
const uint16_t PROGMEM ji_combo[] = {RC_J, KC_I, COMBO_END};
const uint16_t PROGMEM fe_combo[] = {LC_F, KC_E, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM uiop_combo[] = {KC_U, KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM yuio_combo[] = {KC_Y, KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM ty_combo[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM uk_combo[] = {KC_U, KC_K, COMBO_END};
const uint16_t PROGMEM rg_combo[] = {KC_R, KC_G, COMBO_END};
const uint16_t PROGMEM m4_combo[] = {KC_M, KC_COMM, GR_DOT, GR_SL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [CPSL] = COMBO(jk_combo, KC_CAPS),
    [CPSLL] = COMBO(df_combo, KC_CAPS),
    [EQL] = COMBO(ui_combo, KC_EQL),
    [SMNS] = COMBO(lsemi_combo, KC_MINS),
    [MNS] = COMBO(kl_combo, KC_MINS),
    [PLS] = COMBO(mcomm_combo, KC_PPLS),
    [LBC] = COMBO(rt_combo, KC_LBRC),
    [RBC] = COMBO(yu_combo, KC_RBRC),
    [LCB] = COMBO(fg_combo, KC_LPRN),
    [RCB] = COMBO(hj_combo, KC_RPRN),
    [LPN] = COMBO(vb_combo, KC_LCBR),
    [RPN] = COMBO(nm_combo, KC_RCBR),
    [QUO] = COMBO(cv_combo, KC_QUOT),
    [SPCC] = COMBO(io_combo, KC_SPC),
    [BKSP] = COMBO(er_combo, KC_BSPC),
    [BKSL] = COMBO(commdot_combo, KC_BSLS),
    [LALTC] = COMBO(ji_combo, KC_LALT),
    [RALTC] = COMBO(fe_combo, KC_LALT),
    [OP_MENU] = COMBO(op_combo, LALT(KC_P)),
//   [OP_MENU] = COMBO_ACTION(op_combo),
//   [UIOP_MENU] = COMBO_ACTION(uiop_combo),
//   [YUIO_MENU] = COMBO_ACTION(yuio_combo),
    [YUIO_MENU] = COMBO(uiop_combo, KC_MINS),
    [UIOP_MENU] = COMBO(yuio_combo, S(KC_MINS)),
    [TY] = COMBO(ty_combo, KC_LEAD),
    [TEH_LEAD] = COMBO(uk_combo, KC_LEAD),
    [ENTT] = COMBO(rg_combo, KC_ENT),
    [SPC4] = COMBO(m4_combo, KC_SPC),
};

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case OP_MENU:
//       if (pressed) {
//         tap_code16(LALT(KC_P));
//       }
//       break;
//   }
// }

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case UIOP_MENU:
//       if (pressed) {
//         tap_code16(LALT(KC_P));
//       }
//       break;
//     case YUIO_WMENU:
//       if (pressed) {
//         tap_code16(LGUI(KC_P));
//       }
//       break;
//     case EQL:
//        if (pressed) {
//         register_code16(KC_EQL);
//       } else {
//           unregister_code16(KC_EQL);
//       }
//       break;
//     case SPCC:
//        if (pressed) {
//         register_code16(KC_SPC);
//       } else {
//           unregister_code16(KC_SPC);
//       }
//       break;
//   }
// }
