enum combos {
    CPSL2,
    CPSLL2,
    LBC,
    LCB,
    LPN,
    ENTT,
    F_ONE,
    BKSP,
    RALTC,
    CPSL,
    CPSLL,
    PLS,
    RBC,
    RCB,
    RPN,
    QUO,
    EQL,
    SMNS,
    MNS,
    BKSL,
    LALTC,
    SPCC,
    OP_MENU,
    YUIO_MENU,
    UIOP_MENU,
    TEH_LEAD,
    SPC4,
    TY,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM spcf_combo[] = {SPC_LSH, KC_F, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM rg_combo[] = {KC_R, KC_G, COMBO_END};
const uint16_t PROGMEM grvq_combo[] = {LGUI_T(KC_MINS), KC_F2, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM fe_combo[] = {KC_F, KC_E, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jbsp_combo[] = {KC_J, BSP_RSH, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM lsemi_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM ji_combo[] = {KC_J, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM uiop_combo[] = {KC_U, KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM yuio_combo[] = {KC_Y, KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM uk_combo[] = {KC_U, KC_K, COMBO_END};
const uint16_t PROGMEM m4_combo[] = {KC_M, KC_COMM, KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM ty_combo[] = {KC_T, KC_Y, COMBO_END};

combo_t key_combos[] = {
    [CPSL2] = COMBO(df_combo, KC_CAPS),
    [CPSLL2] = COMBO(spcf_combo, KC_CAPS),
    [LBC] = COMBO(rt_combo, KC_LBRC),
    [LCB] = COMBO(fg_combo, KC_LPRN),
    [LPN] = COMBO(vb_combo, KC_LCBR),
    [ENTT] = COMBO(rg_combo, KC_ENT),
    [F_ONE] = COMBO(grvq_combo, KC_F1),
    [BKSP] = COMBO(er_combo, KC_BSPC),
    [RALTC] = COMBO(fe_combo, KC_LALT),
    [CPSL] = COMBO(jk_combo, KC_CAPS),
    [CPSLL] = COMBO(jbsp_combo, KC_CAPS),
    [PLS] = COMBO(mcomm_combo, KC_PPLS),
    [RBC] = COMBO(yu_combo, KC_RBRC),
    [RCB] = COMBO(hj_combo, KC_RPRN),
    [RPN] = COMBO(nm_combo, KC_RCBR),
    [QUO] = COMBO(cv_combo, KC_QUOT),
    [EQL] = COMBO(ui_combo, KC_EQL),
    [SMNS] = COMBO(lsemi_combo, KC_MINS),
    [MNS] = COMBO(kl_combo, KC_MINS),
    [BKSL] = COMBO(commdot_combo, KC_BSLS),
    [LALTC] = COMBO(ji_combo, KC_LALT),
    [SPCC] = COMBO(io_combo, KC_SPC),
    [OP_MENU] = COMBO(op_combo, LALT(KC_P)),
    [YUIO_MENU] = COMBO(uiop_combo, KC_MINS),
    [UIOP_MENU] = COMBO(yuio_combo, S(KC_MINS)),
    [TEH_LEAD] = COMBO(uk_combo, KC_LEAD),
    [SPC4] = COMBO(m4_combo, KC_SPC),
    [TY] = COMBO(ty_combo, KC_LEAD),
};
