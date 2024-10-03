// Copyright 2023 Jan Erik Schopmeier (@janschop)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

void keyboard_post_init_user(void) {
  debug_enable=true;
//   debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.
uint16_t alt_tab_timeout = 0;
uint16_t alt_tab_timeout_short = 700;
uint16_t alt_tab_timeout_long = 1100;

enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
    LLOCK,
    dplct,
    lft_dsktp,
    rght_dsktp,
    tsk_view,
    print,
    frac,
    double_click,
    MOUSE_MACRO,
    copy,
    paste,
    cut,
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
};

#include "g/keymap_combo.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        case dplct:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("l"));
            SEND_STRING(SS_DOWN(X_LALT));
            SEND_STRING((SS_TAP(X_ENT)));
            SEND_STRING(SS_UP(X_LALT));
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
         case MOUSE_MACRO :
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
            SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_1));
        }
        break;
        case win_2:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_2));
        }
        break;
        case win_3:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_3));
        }
        break;
        case win_4:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_4));
        }
        break;
        case win_5:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_5));
        }
        break;
        case win_6:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_6));
        }
        break;
        case win_7:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_7));
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
        case combo_aa:
            return 60;
    }
    return COMBO_TERM;
};

void matrix_scan_user(void) { // The very important timer.
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > alt_tab_timeout) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
        }
    }
}
//layout: {ortho_layout: {split: true, rows: 3, columns: 5, thumbs: 2}}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // [0] = LAYOUT_split_3x5_2(//colemak dh
    //  KC_Q,        KC_W,        KC_F,   KC_P,    KC_B,    KC_J,          KC_L, KC_U, KC_Y,   KC_SCLN,          
    //  CTL_T(KC_A), KC_R,        KC_S,   KC_T,    KC_G,    KC_K,          KC_N, KC_E, KC_I,   CTL_T(KC_O), /*MT(XXXXXXX,KC_R)*//*MT(XXXXXXX,KC_I)*/
    //  SFT_T(KC_Z), ALT_T(KC_X), KC_C,   KC_D,    KC_V,    KC_M,          KC_H, cmsemi, KC_DOT, CKC_SL,
    //                            OSM(MOD_LSFT), OSL(1),    LT(2, KC_SPC), OSL(3) //LT(2, KC_SPC) CKC_SPC 
    // ),
    [0] = LAYOUT_split_3x5_2(//base
            KC_Q,        KC_W,    KC_E,    KC_R,   KC_T,    KC_Y  ,        KC_U,   KC_I,   KC_O,           KC_P,          
     CTL_T(KC_A),        KC_S,    KC_D,    KC_F,   KC_G,    KC_H  ,        KC_J,   KC_K,   KC_L, CTL_T(KC_SCLN), 
     SFT_T(KC_Z), ALT_T(KC_X),    KC_C,    KC_V,   KC_B,    KC_N  ,        KC_M, KC_COMM, KC_DOT, SFT_T(KC_SLSH),
                                  OSM(MOD_LSFT), OSL(1),    LT(2, KC_SPC), OSL(3)
    ),

    [1] = LAYOUT_split_3x5_2(//numbers and symbols
    S(KC_1),   S(KC_2), S(KC_3), ALGR(KC_4), S(KC_5),    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),
       KC_1,      KC_2,    KC_3,       KC_4,    KC_5,    KC_6   ,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LSFT, ctl_s_tab, KC_RBRC,    ctl_tab, KC_BSLS,    KC_EQL , KC_MINS, _______, _______, _______,
                                     KC_DEL, _______,    _______, _______
    ),
   
    [2] = LAYOUT_split_3x5_2(//navigation
    KC_VOLD, KC_MPRV, KC_MPLY,   KC_MNXT,   KC_VOLU,    KC_MUTE, ALGR(KC_7), S(KC_8),     S(KC_9), ALGR(KC_0), 
      win_1,   win_2,   win_3,     win_4,     win_5,    KC_HOME, C(KC_LEFT),   KC_UP, C(KC_RIGHT),     KC_END, 
    KC_LSFT, KC_LALT,   win_6,     win_7,     LLOCK,    alt_tab,    KC_LEFT, KC_DOWN,    KC_RIGHT,    KC_LGUI,
                                 KC_BSPC, KC_DELETE,    _______,      TG(4)
    ),

    [3] = LAYOUT_split_3x5_2(// function and algr
  KC_GRV, ALGR(KC_2), ALGR(KC_3),   S(KC_4),    ALGR(KC_5),    KC_PSCR, DM_REC1, ALGR(KC_8), ALGR(KC_9),    S(KC_RBRC),
   KC_F1,      KC_F2,      KC_F3,     KC_F4,         KC_F5,    KC_F6  , DM_PLY1,    KC_NUBS, S(KC_NUBS),    S(KC_BSLS),
   KC_F7,      KC_F8,      KC_F9,    KC_F10,        KC_F11,    KC_F12,    print,    KC_BSLS, S(KC_MINS), ALGR(KC_RBRC),      
                                  C(KC_BSPC), C(KC_DELETE),    XXXXXXX, _______
    ),

    [5] = LAYOUT_split_3x5_2(// mouse
    XXXXXXX, XXXXXXX, G(KC_D), XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, G(KC_TAB), XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   KC_MS_U, XXXXXXX, XXXXXXX,   
    XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R,   TG(5),    XXXXXXX, KC_MS_L,   KC_MS_D, KC_MS_R, XXXXXXX,          
                                 TG(5),   TG(5),    TG(5)  ,    TG(5)
    ),

    [4] = LAYOUT_split_3x5_2(//numpad
    QK_BOOT, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,    KC_NUM , KC_P7,   KC_P8,   KC_P9,  XXXXXXX,
    XXXXXXX, XXXXXXX,   KC_UP,  XXXXXXX, XXXXXXX,    KC_LEFT, KC_P4,   KC_P5,   KC_P6, KC_RIGHT,
    XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT,   TG(4),    KC_BSPC, KC_P1,   KC_P2,   KC_P3,  KC_DOWN,
                                KC_BSPC, _______,     KC_P0, KC_DOT
    ),


};
