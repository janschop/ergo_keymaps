/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum {
    LSFT_CAPS,
    RSFT_ENTER,
    Q_TAB,
    ONE_TAB,
    CTRL_TAB,
};

tap_dance_action_t tap_dance_actions[] = {
    [LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [Q_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB),
    [ONE_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_TAB),
    [CTRL_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_TAB),
};

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
    kiwi = SAFE_RANGE,
    rema,
    bunnpris,
    mail,
    first_name,
    last_name,
    number,
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
};

// void keyboard_pre_init_user(void) {
//     setPinOutput(D3);  // initialize D3 for LED
//     writePinHigh(D3);  // turn on LED for testing
// }
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

        case print:
        if (record->event.pressed) {
            SEND_STRING("printf"SS_DOWN(X_LSFT)"82"SS_UP(X_LSFT));
            SEND_STRING("=n"SS_DOWN(X_LSFT)"29,"SS_UP(X_LSFT));
            SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
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
    }
    return true;    
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // Use `static` variable to remember the previous status.
    static bool home_on = false;

    if (home_on != IS_LAYER_ON_STATE(state, 0)) {
        home_on = !home_on;

        if (home_on) {
         SEND_STRING(SS_UP(X_LALT)SS_UP(X_LCTL));
        }
    }
    return state;
}

const uint16_t PROGMEM sd_esc[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_tab[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM hj_ent[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM io_aa[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM kl_ae[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_enter_l[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM combo_alt_f4[] = {KC_2, KC_4, COMBO_END};
const uint16_t PROGMEM combo_lclick[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM combo_right_click[] = {KC_F, KC_R, COMBO_END};
const uint16_t PROGMEM combo_middle_click[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM combo_mouse_macro[] = {KC_F, KC_V, COMBO_END}; 
const uint16_t PROGMEM combo_double_click[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM combo_gui[] = {KC_BSPC, OSL(1), COMBO_END};
const uint16_t PROGMEM combo_caps[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {ALT_T(KC_X), KC_C, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_cut[] = {ALT_T(KC_X), KC_V, COMBO_END};
const uint16_t PROGMEM combo_dsktp_l[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo_dsktp_r[] = {KC_3, KC_4, COMBO_END};
const uint16_t PROGMEM combo_close_tab[] = {KC_3, KC_RBRC, COMBO_END};
const uint16_t PROGMEM combo_new_tab[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM combo_pwr_toys[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM combo_win_tab[] = {KC_3, S(KC_3), COMBO_END};

combo_t key_combos[] = {
    COMBO(sd_esc, KC_ESC),
    COMBO(df_tab, KC_TAB), // keycodes with modifiers are possible too!
    COMBO(hj_ent, KC_ENT),
    COMBO(io_aa, KC_LBRC),
    COMBO(kl_ae, KC_QUOT),
    COMBO(combo_enter_l, KC_ENT),
    COMBO(combo_alt_f4, LALT(KC_F4)),
    COMBO(combo_lclick, KC_BTN1),
    COMBO(combo_right_click, KC_BTN2),
    COMBO(combo_double_click, double_click),
    COMBO(combo_gui, KC_LGUI),
    COMBO(combo_middle_click, KC_BTN3),
    COMBO(combo_caps, KC_PAGE_UP),
    COMBO(combo_mouse_macro, MOUSE_MACRO),
    COMBO(combo_copy, copy),
    COMBO(combo_paste, paste),
    COMBO(combo_cut, cut),
    COMBO(combo_dsktp_l, lft_dsktp),
    COMBO(combo_dsktp_r, rght_dsktp),
    COMBO(combo_pwr_toys, LALT(KC_SPACE)),
    COMBO(combo_close_tab, LCTL(KC_W)),
    COMBO(combo_new_tab, LCTL(KC_T)),
    COMBO(combo_win_tab, G(KC_TAB)),
};

//layout: {ortho_layout: {split: true, rows: 3, columns: 6, thumbs: 6}}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_split_3x6_4(//base
    XXXXXXX,        KC_Q,        KC_W,    KC_E,    KC_R,   KC_T,    KC_Y  ,          KC_U,    KC_I,    KC_O,          KC_P, KC_BTN2,         
    KC_BTN1, CTL_T(KC_A),        KC_S,    KC_D,    KC_F,   KC_G,    KC_H  ,          KC_J,    KC_K,    KC_L,CTL_T(KC_SCLN), TO(5),
    KC_PSCR, SFT_T(KC_Z), ALT_T(KC_X),    KC_C,    KC_V,   KC_B,    KC_N  ,          KC_M, KC_COMM,  KC_DOT,SFT_T(KC_SLSH), KC_BTN3,
    XXXXXXX,     XXXXXXX,     XXXXXXX, QK_BOOT, KC_BSPC, OSL(1),    OSL(3), LT(2, KC_SPC), XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX
    ),

    [1] = LAYOUT_ortho_split_3x6_4(//numbers and symbols
    _______, S(KC_1),   S(KC_2), S(KC_3), ALGR(KC_4), S(KC_5),    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
    _______,    KC_1,      KC_2,    KC_3,       KC_4,    KC_5,    KC_6   ,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    _______, KC_LSFT, ctl_s_tab, KC_RBRC,    ctl_tab, KC_BSLS,    KC_MINS,  KC_EQL, _______, _______, _______, TO(0),      
    XXXXXXX, XXXXXXX,   _______, _______,  KC_DELETE, _______,    _______, _______, _______, _______, XXXXXXX, XXXXXXX     
    ),

    [2] = LAYOUT_ortho_split_3x6_4(//navigation
    _______     , _______, _______, _______,   _______, _______,    alt_tab   , lft_dsktp, G(KC_TAB), rght_dsktp,     alt_tab, _______, 
    double_click, KC_BTN4, _______, _______,   _______, KC_BTN5,    C(KC_LEFT),   KC_HOME,     KC_UP,     KC_END, C(KC_RIGHT), _______,   
    _______     , KC_LSFT, KC_NUBS, _______,   _______, _______,    ctl_s_tab ,   KC_LEFT,   KC_DOWN,   KC_RIGHT,     ctl_tab,   TO(0),     
    XXXXXXX     , XXXXXXX, _______, _______, KC_DELETE, _______,    TO(4)     ,    KC_SPC,   _______,    _______,     XXXXXXX, XXXXXXX              
    ),

        [3] = LAYOUT_ortho_split_3x6_4(//function and algr
    _______,  KC_GRV, ALGR(KC_2), ALGR(KC_3), S(KC_4), ALGR(KC_5),    _______,    _______,    S(KC_8),    S(KC_9),       _______,       _______, 
    _______,   KC_F1,      KC_F2,      KC_F3,   KC_F4,      KC_F5,    KC_F6  , ALGR(KC_7), ALGR(KC_8), ALGR(KC_9),    ALGR(KC_0), ALGR(KC_RBRC),        
    TO(0)  ,   KC_F7,      KC_F8,      KC_F9,  KC_F10,     KC_F11,    KC_F12,        mail,    S(KC_8),    S(KC_9), ALGR(KC_RBRC),         TO(0),                    
    XXXXXXX, XXXXXXX,    _______,    _______, _______,    _______,    XXXXXXX,    XXXXXXX,    _______,    _______,       _______,       _______                     
    ),

    [5] = LAYOUT_ortho_split_3x6_4(// mouse
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
    TO(0)  , KC_BTN4, KC_BTN1, KC_WH_U, KC_BTN2, KC_BTN5,    LGUI(KC_D), lft_dsktp, KC_MS_U, rght_dsktp, XXXXXXX,   TO(0),    
    TO(0)  , KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_R,   TO(0),    XXXXXXX,    KC_MS_L,   KC_MS_D,    KC_MS_R, XXXXXXX,   TO(0),             
    XXXXXXX, XXXXXXX,   TO(0),   TO(0),   TO(0),   TO(0),    TO(0),      TO(0),     TO(0),        TO(0), XXXXXXX, XXXXXXX                 
    ),

    [4] = LAYOUT_ortho_split_3x6_4(//numpad
    QK_BOOT, QK_BOOT,    kiwi,bunnpris,     rema, XXXXXXX,    KC_NUM,  KC_P7,   KC_P8,   KC_P9, KC_PSLS, KC_PAST,
    XXXXXXX, XXXXXXX, XXXXXXX,   KC_UP,  XXXXXXX, XXXXXXX,    KC_TAB,  KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PMNS,
    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT,   TO(0),    XXXXXXX, KC_P1,   KC_P2,   KC_P3, KC_PENT,   TO(0),
    XXXXXXX, XXXXXXX,  KC_ENT, KC_LGUI,  KC_BSPC, _______,    _______, KC_P0, KC_PDOT, _______, XXXXXXX, XXXXXXX
    ),
};