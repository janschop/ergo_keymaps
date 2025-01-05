// Copyright 2023 Jan Erik Schopmeier (@janschop)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

bool is_alt_tab_active = false; 
uint16_t alt_tab_timer = 0;     
uint16_t alt_tab_timeout = 0;
uint16_t alt_tab_timeout_short = 800;
uint16_t alt_tab_timeout_long = 1200;

bool is_win_active = false;
uint16_t win_timer = 0;
uint16_t win_timeout = 1500;

void keyboard_post_init_user(void) {
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   debug_mouse=true;
}

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_A, // reads as C(ustom) + KC_A, but you may give any name here
    CKC_R,
    CKC_I,
    CKC_O,
    CKC_Z,
    CKC_SL,
    CKC_SPC,
    cmsemi,
    dshund,
    dotcol,
    SMTD_KEYCODES_END,
    ALT_TAB,
    LLOCK,
    kiwi,
    rema,
    bunnpris,
    meny,
    mail,
    first_name,
    last_name,
    number,
    lft_dsktp,
    rght_dsktp,
    tsk_view,
    print,
    frac,
    double_click,
    M_S_BT3,
    alt_tab,
    ctl_tab,
    ctl_s_tab,
    win_left,
    win_right,
    win_1,
    win_2,
    win_3,
    win_4,
    win_5,
    win_6,
    win_7,
    win_8,
    win_9,
    win_0,
    param,
};

#include "g/keymap_combo.h"
#include "sm_td.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) { return false; }
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    switch (keycode) {
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT); 
                    SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_TAB)SS_UP(X_LSFT));
                    alt_tab_timeout = alt_tab_timeout_long;
                } else {
                    alt_tab_timeout = alt_tab_timeout_short;
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case C(KC_W):
            if (record->event.pressed) {
                if (is_alt_tab_active) {
                    alt_tab_timer = timer_read();
                }
            }
            break;
        case bunnpris:
            if (record->event.pressed) {
                SEND_STRING("bunnpris");
            }
            break;
        case kiwi:
            if (record->event.pressed) {
                SEND_STRING("kiwi");
            }
            break;
        case rema:
            if (record->event.pressed) {
                SEND_STRING("rema");
            } 
            break;    
        case meny:
            if (record->event.pressed) {
                SEND_STRING("meny");
            } 
            break;     
        case mail:
            if (record->event.pressed) {
                SEND_STRING("jan.erik"SS_RALT("2")"schopmeier.com");
            }
            break;
        case first_name:
            if (record->event.pressed) {
                SEND_STRING("Jan Erik ");
            }
            break;
        case last_name:
            if (record->event.pressed) {
                SEND_STRING("Schopmeier");
            }
            break;
        case number:
            if (record->event.pressed) {
                SEND_STRING("46360691");
            }
            break;
        case print:
            if (record->event.pressed) {
                SEND_STRING("printf"SS_DOWN(X_LSFT)"82"SS_UP(X_LSFT));
                SEND_STRING("=r=n"SS_DOWN(X_LSFT)"29,"SS_UP(X_LSFT));
                SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
                // SEND_STRING("print"SS_DOWN(X_LSFT)"8229"SS_UP(X_LSFT));
                // SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT));
            }
            break;
        case frac: //\frac{}{}
            if (record->event.pressed) {
                SEND_STRING("=frac"SS_ALGR("7")SS_ALGR("0")SS_ALGR("7")SS_ALGR("0"));
                SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
            }
            break;
        case lft_dsktp:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_LEFT)SS_UP(X_LCTL)SS_UP(X_LGUI));
            }
            break;
        case rght_dsktp:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_RIGHT)SS_UP(X_LCTL)SS_UP(X_LGUI));
            }
            break;
        case double_click:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_BTN1) SS_DELAY(15) SS_TAP(X_BTN1));
            }
            break;
        case M_S_BT3:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSFT) SS_DELAY(15) SS_DOWN(X_BTN3));
            } else {
                SEND_STRING(SS_UP(X_LSFT) SS_UP(X_BTN3));
            }
            break;
        case alt_tab:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_TAB)SS_TAP(X_LEFT));
            }
            break;
        case ctl_tab:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_TAB));
            }
            break;
        case ctl_s_tab:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_TAB)SS_UP(X_LSFT));
            }
            break;
        case win_left:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(15) SS_DOWN(X_LEFT));
            } else {
                SEND_STRING(SS_UP(X_LEFT) SS_UP(X_LGUI));
            }
            break;
        case win_right:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(15) SS_DOWN(X_RIGHT));
            } else {
                SEND_STRING(SS_UP(X_RIGHT) SS_UP(X_LGUI));
            }
            break;
        case win_1:
            if (record->event.pressed) {
                if (!is_win_active) {
                        is_win_active = true;
                        register_code(KC_LGUI); 
                    }
                win_timer = timer_read();
                SEND_STRING(SS_TAP(X_1));
            }
            break;
        case win_2:
            if (record->event.pressed) {
                if (!is_win_active) {
                        is_win_active = true;
                        register_code(KC_LGUI); 
                    }
                win_timer = timer_read();
                SEND_STRING(SS_TAP(X_2));
            }
            break;
        case win_3:
            if (record->event.pressed) {
                if (!is_win_active) {
                        is_win_active = true;
                        register_code(KC_LGUI); 
                    }
                win_timer = timer_read();
                SEND_STRING(SS_TAP(X_3));
            }
            break;
        case win_4:
            if (record->event.pressed) {
                if (!is_win_active) {
                        is_win_active = true;
                        register_code(KC_LGUI); 
                    }
                win_timer = timer_read();
                SEND_STRING(SS_TAP(X_4));
            }
            break;
        case win_5:
            if (record->event.pressed) {
                if (!is_win_active) {
                        is_win_active = true;
                        register_code(KC_LGUI); 
                    }
                win_timer = timer_read();
                SEND_STRING(SS_TAP(X_5));
            }
            break;
        case win_6:
            if (record->event.pressed) {
                if (!is_win_active) {
                        is_win_active = true;
                        register_code(KC_LGUI); 
                    }
                win_timer = timer_read();
                SEND_STRING(SS_TAP(X_6));
            }
            break;
        case win_7:
            if (record->event.pressed) {
                if (!is_win_active) {
                        is_win_active = true;
                        register_code(KC_LGUI); 
                    }
                win_timer = timer_read();
                SEND_STRING(SS_TAP(X_7));
            }
            break;
        case win_8:
            if (record->event.pressed) {
                if (!is_win_active) {
                        is_win_active = true;
                        register_code(KC_LGUI); 
                    }
                win_timer = timer_read();
                SEND_STRING(SS_TAP(X_8));
            }
            break;
        case win_9:
            if (record->event.pressed) {
                if (!is_win_active) {
                        is_win_active = true;
                        register_code(KC_LGUI); 
                    }
                win_timer = timer_read();
                SEND_STRING(SS_TAP(X_9));
            }
            break;
        case win_0:
            if (record->event.pressed) {
                if (!is_win_active) {
                        is_win_active = true;
                        register_code(KC_LGUI); 
                    }
                win_timer = timer_read();
                SEND_STRING(SS_TAP(X_0));
            }
            break;
        case param:
            if (record->event.pressed) {
                SEND_STRING("sparam");
                SEND_STRING(SS_TAP(X_ENTER));
            }
        default:
            if (is_win_active) {
                unregister_code(KC_LGUI);
                is_win_active = false;
            }
            break;
    }
    return true;    
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, 0)) {
        SEND_STRING(SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LGUI));
    }
    return state;
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case combo_tab:
            return 35;
        case combo_ae:
            return 70;
        case combo_r_click_r:
            return 60;
    }
    return COMBO_TERM;
};

// https://github.com/stasmarkin/sm_td
void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_A, KC_A, KC_LEFT_CTRL)
        SMTD_MT(CKC_R, KC_R, KC_LEFT_ALT)
        SMTD_MT(CKC_I, KC_I, KC_LEFT_ALT)
        SMTD_MT(CKC_O, KC_O, KC_LEFT_CTRL)
        SMTD_MT(CKC_Z, KC_Z, KC_LSFT)
        SMTD_MT(CKC_SL, KC_SLSH, KC_LSFT)
        SMTD_LT(CKC_SPC, KC_SPC, 2)
        case cmsemi: {                                           
            switch (action) {                                     
                case SMTD_ACTION_TOUCH: 
                    if (tap_count > 0) {
                        tap_code16(KC_BSPC);
                    }                         
                    switch (tap_count % 2) { 
                        case 0: tap_code16(KC_COMM); break;
                        case 1: tap_code16(S(KC_COMM)); break;
                        default: break;
                    }
                default: break;
                break;
            } 
            break;
        }
        case dshund: {                                           
            switch (action) {                                     
                case SMTD_ACTION_TOUCH: 
                    if (tap_count > 0) {
                        tap_code16(KC_BSPC);
                    }                         
                    switch (tap_count % 2) { 
                        case 0: tap_code16(KC_SLSH); break;
                        case 1: tap_code16(S(KC_SLSH)); break; 
                        default: break;
                    }
                default: break;
                break;
            }
            break;
        }
    }
}

void matrix_scan_user(void) {
    if (is_win_active) {
        if (timer_elapsed(win_timer) > win_timeout) {
            unregister_code(KC_LGUI);
            is_win_active = false;
        }
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x5_2_u2(//colemak dh
    KC_BSPC, KC_Q,          KC_W,        KC_F,         KC_P,    KC_B,                  KC_J,          KC_L,    KC_U,    KC_Y, KC_SCLN, KC_DEL,      
    KC_BSPC, CTL_T(KC_A),   KC_R,        KC_S,         KC_T,    KC_G,                  KC_K,          KC_N,    KC_E,    KC_I, CTL_T(KC_O),KC_DEL,
     SFT_T(KC_Z),   ALT_T(KC_X), KC_C,         KC_D,    KC_V,                  KC_M,          KC_H,  cmsemi,  KC_DOT, dshund,
                                      OSM(MOD_LSFT),  OSL(1), LT(2, KC_SPC), OSL(3)
    ),

    [1] = LAYOUT_split_3x5_2_u2(//numbers and symbols
   C(KC_BSPC), S(KC_1),   S(KC_2), S(KC_3), ALGR(KC_4), S(KC_5),    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),C(KC_DEL),
  XXXXXXX,     KC_1,      KC_2,    KC_3,       KC_4,    KC_5,    KC_6   ,    KC_7,    KC_8,    KC_9,    KC_0,XXXXXXX,
    KC_LSFT, ctl_s_tab, KC_RBRC,    ctl_tab, KC_BSLS,    KC_EQL , KC_MINS, _______, _______, _______,
                                     KC_DEL, _______,    _______, _______
    ),
   
    [2] = LAYOUT_split_3x5_2_u2(//navigation 
  XXXXXXX,  _______, KC_MPRV,    KC_MPLY,KC_MNXT, _______,                   _______, ALGR(KC_7), S(KC_8),     S(KC_9), ALGR(KC_0), XXXXXXX,
   XXXXXXX, _______, KC_MUTE,   KC_VOLD, KC_VOLU, _______,                   KC_HOME, C(KC_LEFT),   KC_UP, C(KC_RIGHT),     KC_END, XXXXXXX,
    KC_LSFT, KC_LALT, _______,   _______,   LLOCK,                   alt_tab,    KC_LEFT, KC_DOWN,    KC_RIGHT,    _______,
                                 KC_BSPC,  KC_DEL,    _______, TG(4)
    ),

    [3] = LAYOUT_split_3x5_2_u2(// function and algr
 XXXXXXX, KC_GRV, ALGR(KC_2), ALGR(KC_3),   S(KC_4),    ALGR(KC_5),    KC_PSCR, DM_REC1, ALGR(KC_8), ALGR(KC_9),    S(KC_RBRC),XXXXXXX,
 XXXXXXX,  KC_F1,      KC_F2,      KC_F3,     KC_F4,         KC_F5,    KC_F6  , DM_PLY1,    KC_NUBS, S(KC_NUBS),    S(KC_BSLS),XXXXXXX,
   KC_F7,      KC_F8,      KC_F9,    KC_F10,        KC_F11,    KC_F12,    print,    KC_BSLS, S(KC_MINS), ALGR(KC_RBRC),      
                                  C(KC_BSPC), C(KC_DELETE),    XXXXXXX, _______
    ),

    [5] = LAYOUT_split_3x5_2_u2(// mouse
   XXXXXXX, XXXXXXX, XXXXXXX, G(KC_D), XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, G(KC_TAB), XXXXXXX, XXXXXXX,XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   KC_MS_U, XXXXXXX, XXXXXXX,   XXXXXXX,
    XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R,   TG(5),    XXXXXXX, KC_MS_L,   KC_MS_D, KC_MS_R, XXXXXXX,          
                                 TG(5),   TG(5),    TG(5)  ,    TG(5)
    ),

    [4] = LAYOUT_split_3x5_2_u2(//numpad
  XXXXXXX,  QK_BOOT,    kiwi, bunnpris,     rema,    meny,    KC_NUM , KC_P7,   KC_P8,   KC_P9, XXXXXXX,XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX,    KC_UP,  XXXXXXX, XXXXXXX,    KC_LEFT, KC_P4,   KC_P5,   KC_P6, KC_RIGHT,XXXXXXX,
    XXXXXXX, KC_LEFT,  KC_DOWN, KC_RIGHT,   TG(4),    KC_BSPC, KC_P1,   KC_P2,   KC_P3, KC_DOWN,
                                 KC_BSPC, _______,    KC_P0,   KC_DOT
    ),

    [6] = LAYOUT_split_3x5_2_u2(//base
XXXXXXX,        KC_Q,        KC_W,    KC_E,    KC_R,   KC_T,    KC_Y  ,        KC_U,    KC_I,    KC_O,           KC_P, XXXXXXX,
XXXXXXX,   CTL_T(KC_A),        KC_S,    KC_D,    KC_F,   KC_G,    KC_H  ,        KC_J,    KC_K,    KC_L, CTL_T(KC_SCLN), XXXXXXX,
     SFT_T(KC_Z), ALT_T(KC_X),    KC_C,    KC_V,   KC_B,    KC_N  ,        KC_M, KC_COMM,  KC_DOT, SFT_T(KC_SLSH),
                                  OSM(MOD_LSFT), OSL(1),    LT(2, KC_SPC), OSL(3)
    ),
};