// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

bool set_scrolling = false;

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 15.0
#define SCROLL_DIVISOR_V 15.0
#define ZOOM_DIVISOR 5

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;
uint8_t zoom_in = 0;
uint8_t zoom_out = 0;

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Check if drag scrolling is active
    // Calculate and accumulate scroll values based on mouse movement and divisors
    scroll_accumulated_h += (float)mouse_report.h / SCROLL_DIVISOR_H;
    scroll_accumulated_v += (float)mouse_report.v / SCROLL_DIVISOR_V;

    // Assign integer parts of accumulated scroll values to the mouse report
    mouse_report.v = -(int8_t)scroll_accumulated_h;
    mouse_report.h = -(int8_t)scroll_accumulated_v;

    // Update accumulated scroll values by subtracting the integer parts
    scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
    scroll_accumulated_v -= (int8_t)scroll_accumulated_v;
    if (mouse_report.buttons & (1 << 7)) {
        zoom_in ++;
    } 
    if (mouse_report.buttons & (1 << 6)) {
        zoom_out ++;
    }

    if (zoom_in == ZOOM_DIVISOR) {
        SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_MINS)SS_UP(X_LCTL));
        zoom_in = 0;
    }
    if (zoom_out == ZOOM_DIVISOR) {
        SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SLSH)SS_UP(X_LCTL));
        zoom_out = 0;
    }
    return mouse_report;
}


// permissive hold for ctrl
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_T(KC_A):
            // Immediately select the hold action when another key is tapped.
            return true;
        case CTL_T(KC_SCLN):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

// hold on other keypress for shift
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_Z):
            // Immediately select the hold action when another key is pressed.
            return true;
        case SFT_T(KC_SLSH):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

enum custom_keycodes {
    LLOCK = SAFE_RANGE,
    kiwi,
    rema,
    bunnpris,
    mail,
    first_name,
    last_name,
    number,
    pwd,
    Usr,
    usr,
    dplct,
    lft_dsktp,
    rght_dsktp,
    tsk_view,
    print,
    heart,
    frac,
    double_click,
    MOUSE_MACRO,
    copy,
    paste,
    cut,
    alt_tab,
    ctl_tab,
    ctl_s_tab,
    win_1,
    win_2,
    win_3,
    win_4,
    win_5,
    win_6,
    win_7,
    // goto_mouse,
};

#include "g/keymap_combo.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    switch (keycode) {
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
        case pwd:
        if (record->event.pressed) {
            SEND_STRING("Hva i faen1");
        }
        break;
        
        case Usr:
        if (record->event.pressed) {
            SEND_STRING("M77648"); 
        }
        break;

        case usr:
        if (record->event.pressed) {
            SEND_STRING("m77648"); 
        }
        break;

        case print:
        if (record->event.pressed) {
            // SEND_STRING("printf"SS_DOWN(X_LSFT)"82"SS_UP(X_LSFT));
            // SEND_STRING("=n"SS_DOWN(X_LSFT)"29,"SS_UP(X_LSFT));
            // SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
            SEND_STRING("print"SS_DOWN(X_LSFT)"8229"SS_UP(X_LSFT));
            SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT));
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
        case heart:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(",")"3");
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
        case copy:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_C)SS_UP(X_LCTL));
            print("copy\n");
        }
        break;
        case paste:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_V)SS_UP(X_LCTL));
        }
        break;
        case cut:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL));
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
    // Use `static` variable to remember the previous status.
    static bool home_on = false;

    if (home_on != IS_LAYER_ON_STATE(state, 0)) {
        home_on = !home_on;

        if (home_on) {
         SEND_STRING(SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LGUI));
        }
    }
    return state;
}

//layout: {ortho_layout: {split: true, rows: 3, columns: 5, thumbs: 2}}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x5_2(//base
            KC_Q,        KC_W,    KC_E,    KC_R,   KC_T,    KC_Y  ,        KC_U,    KC_I,    KC_O,           KC_P,          
     CTL_T(KC_A),        KC_S,    KC_D,    KC_F,   KC_G,    KC_H  ,        KC_J,    KC_K,    KC_L, CTL_T(KC_SCLN), 
     SFT_T(KC_Z), ALT_T(KC_X),    KC_C,    KC_V,   KC_B,    KC_N  ,        KC_M, KC_COMM,  KC_DOT, SFT_T(KC_SLSH),
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
                                 KC_BSPC, KC_DELETE,    _______,      TO(4)
    ),

    [3] = LAYOUT_split_3x5_2(// function and algr
  KC_GRV, ALGR(KC_2), ALGR(KC_3), S(KC_4), ALGR(KC_5),    XXXXXXX, DM_REC1, ALGR(KC_8), ALGR(KC_9),    S(KC_RBRC),
   KC_F1,      KC_F2,      KC_F3,   KC_F4,      KC_F5,    KC_F6  , DM_PLY1,    KC_NUBS, S(KC_NUBS),    S(KC_BSLS),
   KC_F7,      KC_F8,      KC_F9,  KC_F10,     KC_F11,    KC_F12,    print,        usr,        pwd, ALGR(KC_RBRC),      
                                  KC_BSPC,  KC_DELETE,    XXXXXXX, _______
    ),

    [5] = LAYOUT_split_3x5_2(// mouse
    XXXXXXX, XXXXXXX, G(KC_D), XXXXXXX, XXXXXXX,    XXXXXXX, lft_dsktp, G(KC_TAB), rght_dsktp, XXXXXXX,
    KC_BTN4, KC_BTN1, KC_WH_U, KC_BTN2, KC_BTN5,    XXXXXXX,   XXXXXXX,   KC_MS_U,    XXXXXXX, XXXXXXX,   
    KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_R,   TO(0),    XXXXXXX,   KC_MS_L,   KC_MS_D,    KC_MS_R, XXXXXXX,            
                                 TO(0),   TO(0),    TO(0)  ,     TO(0)
    ),

    [4] = LAYOUT_split_3x5_2(//numpad
    QK_BOOT,    kiwi, bunnpris,     rema, XXXXXXX,    KC_NUM,  KC_P7,   KC_P8,   KC_P9, KC_PSLS,
    XXXXXXX, XXXXXXX,    KC_UP,  XXXXXXX, XXXXXXX,    KC_TAB,  KC_P4,   KC_P5,   KC_P6, KC_PPLS,
    XXXXXXX, KC_LEFT,  KC_DOWN, KC_RIGHT,   TO(0),    XXXXXXX, KC_P1,   KC_P2,   KC_P3, KC_PENT,
                                 KC_BSPC, _______,    _______, KC_P0
    ),
};

