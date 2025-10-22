// Copyright 2023 Jan Erik Schopmeier (@janschop)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

bool is_alt_tab_active = false; 
uint16_t alt_tab_timer = 0;     
uint16_t alt_tab_timeout = 0;
uint16_t alt_tab_timeout_short = 800;
uint16_t alt_tab_timeout_long = 1200;

bool is_win_active = false;
uint16_t win_timer = 0;
uint16_t win_timeout = 1500;

bool alt_tab_mode = false;
bool arrow_key_mode = false;

uint16_t default_cpi = 512;
uint16_t scrolling_cpi = 32;
uint16_t alt_tab_cpi = 4;
uint16_t arrow_cpi = 32;

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 128
#define SCROLL_DIVISOR_V 50

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

// #define ARROW_DIVISOR_H 128.0
// #define ARROW_DIVISOR_V 128.0
// float arrow_accumulated_h = 0;
// float arrow_accumulated_v = 0;

void keyboard_post_init_user(void) {
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   debug_mouse=true;
  pointing_device_set_cpi_on_side(false, default_cpi); //right
  pointing_device_set_cpi_on_side(true, default_cpi); //left
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
    M_ATAB,
    param,
    hed,
};

#include "g/keymap_combo.h"

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {     
    if (left_report.x != 0 || left_report.y != 0) {
        left_report.y = -left_report.y;
        if ((abs(left_report.x) / abs(left_report.y)) > 1) {
            scroll_accumulated_h += (float)left_report.x / SCROLL_DIVISOR_H;
        } else {
            scroll_accumulated_v += (float)left_report.y / SCROLL_DIVISOR_V;
        }
        
        // Assign integer parts of accumulated scroll values to the mouse report
        left_report.h = (int8_t)scroll_accumulated_h;
        left_report.v = (int8_t)scroll_accumulated_v;
    
        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;
        left_report.x = 0;
        left_report.y = 0;
    }
    return pointing_device_combine_reports(left_report, right_report);
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

        case M_ATAB:
            if (record->event.pressed) {
                pointing_device_set_cpi_on_side(true, alt_tab_cpi); //left
                register_code(KC_LALT); 
                SEND_STRING(SS_TAP(X_TAB)SS_DOWN(X_LSFT)SS_TAP(X_TAB)SS_UP(X_LSFT));
                alt_tab_mode = true;
            } else {
                pointing_device_set_cpi_on_side(true, default_cpi); //left
                unregister_code(KC_LALT);
                alt_tab_mode = false;
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
        case hed:
            if (record->event.pressed) {
                SEND_STRING("Hva er dette");
                SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_MINS) SS_UP(X_LSFT));
                SEND_STRING(SS_TAP(X_ENTER));
            }
        default:
         
            break;
    }
    return true;    
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     if (IS_LAYER_ON_STATE(state, 0)) {
//         SEND_STRING(SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LGUI));
//     }
//      switch (get_highest_layer(state)) {
//         case 1:  // If we're on the _RAISE layer enable scrolling mode
//             pointing_device_set_cpi_on_side(false, arrow_cpi); //right
//             pointing_device_set_cpi_on_side(true, arrow_cpi/3); //left
//             arrow_key_mode = true;
//             break;
//         default:
//             if (arrow_key_mode) {
//                 pointing_device_set_cpi_on_side(false, default_cpi);
//                 pointing_device_set_cpi_on_side(true, default_cpi);
//                 arrow_key_mode = false;
//             }
//             break;
//     }
//     return state;
// }

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case combo_tab:
            return 35;
        case combo_ae:
            return 70;
    }
    return COMBO_TERM;
};


void matrix_scan_user(void) {
    if (is_win_active) {
        if (timer_elapsed(win_timer) > win_timeout) {
            unregister_code(KC_LGUI);
            is_win_active = false;
        }
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x5_3u4(//colemak dh
                  KC_MPRV,     KC_MPLY,            KC_MNXT, KC_PSCR,                  KC_MUTE,    KC_VOLD, KC_VOLU, _______,
     KC_Q,          KC_W,        KC_F,               KC_P,    KC_B,                  KC_J,          KC_L,    KC_U,    KC_Y, KC_SCLN,          
     CMD_T(KC_A),   OPT_T(KC_R), CTL_T(KC_S),         KC_T,    KC_G,                  KC_K,          KC_N,    CTL_T(KC_E),    OPT_T(KC_I), CMD_T(KC_O),
     KC_Z,          OPT_T(KC_X), CTL_T(KC_C),         KC_D,    KC_V,                  KC_M,          KC_H, CTL_T(KC_COMM), OPT_T(KC_DOT), KC_SLSH,
                                      OSM(MOD_LSFT),  OSL(1),C(KC_UP), KC_BTN1, LT(2, KC_SPC), OSL(3)
    ),

    [1] = LAYOUT_split_3x5_3u4(//numbers and symbols
                  _______, _______, _______, _______,                        _______, _______, _______, _______,
    S(KC_1),   S(KC_2), S(KC_3), S(KC_4), S(KC_5),                        S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),
       KC_1,      KC_2,    KC_3,       KC_4,    KC_5,                        KC_6   ,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LSFT, C(S(KC_TAB)), KC_RBRC,    C(KC_TAB), KC_BSLS,                        KC_EQL , KC_MINS, _______, _______, _______,
                                     KC_DEL, _______, _______, double_click, KC_BTN2, _______
    ),
   
    [2] = LAYOUT_split_3x5_3u4(//navigation 
             _______, _______,   _______, _______,                   _______,    _______, _______,     _______,
    KC_VOLD, KC_MPRV, KC_MPLY,   KC_MNXT, KC_VOLU,                   KC_MUTE, A(S(KC_8)), S(KC_8),     S(KC_9), A(S(KC_9)), 
    _______, _______, _______,   _______, _______,                   G(KC_LEFT), A(KC_LEFT), KC_UP, A(KC_RIGHT), G(KC_RIGHT), 
    KC_LSFT, KC_LALT, _______,   _______,   LLOCK,                   alt_tab,    KC_LEFT, KC_DOWN,    KC_RIGHT,   hed,
                                 KC_BSPC,  KC_DEL,   LLOCK, _______, _______, TG(4)
    ),

    [3] = LAYOUT_split_3x5_3u4(// function and algr
             _______,    _______,   _______,    _______,                   _______, _______,    _______,    _______,
  ALGR(KC_7), KC_BSLS, ALGR(KC_3),   ALGR(KC_4), ALGR(KC_5),               C(S(G(KC_4))), DM_REC1,    ALGR(KC_8), ALGR(KC_9), S(KC_RBRC),
   KC_F1,      KC_F2,      KC_F3,     KC_F4,      KC_F5,                   KC_F6  , DM_PLY1,    KC_NUBS, S(KC_NUBS),       S(KC_BSLS),
   KC_F7,      KC_F8,      KC_F9,    KC_F10,     KC_F11,                   KC_F12, S(KC_EQL),    KC_GRV, S(KC_MINS), ALGR(KC_RBRC),      
                                 A(KC_BSPC),  A(KC_DEL), _______, _______, _______, _______
    ),

    [4] = LAYOUT_split_3x5_3u4(//numpad
             _______,  _______,  _______, _______,                   _______, _______,   KC_UP, _______,
    QK_BOOT,    kiwi, bunnpris,     rema,    meny,                   KC_NUM ,   KC_P7,   KC_P8,   KC_P9, XXXXXXX,
    XXXXXXX, XXXXXXX,    KC_UP,  XXXXXXX, XXXXXXX,                   KC_LEFT,   KC_P4,   KC_P5,   KC_P6, KC_RIGHT,
    XXXXXXX, KC_LEFT,  KC_DOWN, KC_RIGHT,   TG(4),                   KC_BSPC,   KC_P1,   KC_P2,   KC_P3, KC_DOWN,
                                 KC_BSPC, _______, _______, _______, KC_P0,    KC_DOT
    ),

    [6] = LAYOUT_split_3x5_3u4(//base
                      _______, _______, _______,_______,                   _______, _______,_______, _______,
            KC_Q,        KC_W,    KC_E,    KC_R,   KC_T,                   KC_Y  ,        KC_U,    KC_I,    KC_O,           KC_P,          
     CTL_T(KC_A),        KC_S,    KC_D,    KC_F,   KC_G,                   KC_H  ,        KC_J,    KC_K,    KC_L, CTL_T(KC_SCLN), 
     SFT_T(KC_Z), ALT_T(KC_X),    KC_C,    KC_V,   KC_B,                   KC_N  ,        KC_M, KC_COMM,  KC_DOT, SFT_T(KC_SLSH),
                                  OSM(MOD_LSFT), OSL(1), _______, KC_BTN1, LT(2, KC_SPC), OSL(3)
    ),
    
    [7] = LAYOUT_split_3x5_3u4(//colemak dh
                 KC_MPRV,     KC_MPLY,      KC_MNXT, KC_PSCR,                  KC_MUTE,    KC_VOLD, KC_VOLU, _______,
     KC_Q,          KC_W,        KC_F,         KC_P,    KC_B,                  KC_J,          KC_L,    KC_U,    KC_Y, KC_SCLN,          
     CMD_T(KC_A),   KC_R,        KC_S,         KC_T,    KC_G,                  KC_K,          KC_N,    KC_E,    KC_I, CMD_T(KC_O),
     KC_Z,          OPT_T(KC_X), CTL_T(KC_C),         KC_D,    KC_V,                  KC_M,          KC_H,  KC_COMM,  KC_DOT, KC_SLSH,
                                      OSM(MOD_LSFT),  OSL(1), M_ATAB, KC_BTN1, LT(2, KC_SPC), OSL(3)
    ),

    [8] = LAYOUT_split_3x5_3u4(//numbers and symbols
                  _______, _______, _______, _______,                        _______, _______, _______, _______,
    S(KC_1),   S(KC_2), S(KC_3), ALGR(KC_4), S(KC_5),                        S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),
       KC_1,      KC_2,    KC_3,       KC_4,    KC_5,                        KC_6   ,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LSFT, ctl_s_tab, KC_RBRC,    ctl_tab, KC_BSLS,                        KC_EQL , KC_MINS, _______, _______, _______,
                                     KC_DEL, _______, _______, double_click, KC_BTN2, _______
    ),
   
    [9] = LAYOUT_split_3x5_3u4(//navigation 
             _______, _______,   _______, _______,                   _______,    _______, _______,     _______,
    _______, _______, _______,   _______, _______,                   _______, ALGR(KC_7), S(KC_8),     S(KC_9), ALGR(KC_0), 
    _______, _______, _______,   _______, _______,                   KC_HOME, C(KC_LEFT),   KC_UP, C(KC_RIGHT),     KC_END, 
    KC_LSFT, KC_LALT, _______,   _______,   LLOCK,                   alt_tab,    KC_LEFT, KC_DOWN,    KC_RIGHT,    _______,
                                 KC_BSPC,  KC_DEL,   LLOCK, _______, _______, TG(4)
    ),

    [10] = LAYOUT_split_3x5_3u4(// function and algr
             _______,    _______,   _______,    _______,                   _______, _______,    _______,    _______,
  KC_GRV, ALGR(KC_2), ALGR(KC_3),   S(KC_4), ALGR(KC_5),                   KC_PSCR, DM_REC1,    ALGR(KC_8), ALGR(KC_9), S(KC_RBRC),
   KC_F1,      KC_F2,      KC_F3,     KC_F4,      KC_F5,                   KC_F6  , DM_PLY1,    KC_NUBS, S(KC_NUBS),       S(KC_BSLS),
   KC_F7,      KC_F8,      KC_F9,    KC_F10,     KC_F11,                   KC_F12,    print,    KC_BSLS, S(KC_MINS), ALGR(KC_RBRC),      
                                 C(KC_BSPC),  C(KC_DEL), _______, _______, _______, _______
    ),
};