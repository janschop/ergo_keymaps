#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

void keyboard_post_init_user(void) {
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   debug_mouse=true;
}

enum my_keycodes {
    test = SAFE_RANGE,
    lft_dsktp,
    rght_dsktp,
    print,
    frac
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case print:
            if (record->event.pressed) {
                SEND_STRING("printf"SS_DOWN(X_LSFT)"82"SS_UP(X_LSFT));
                SEND_STRING("=r=n"SS_DOWN(X_LSFT)"29,"SS_UP(X_LSFT));
                SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
                // SEND_STRING("print"SS_DOWN(X_LSFT)"8229"SS_UP(X_LSFT));
                // SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT));
            }
            return false;
        case frac: //\frac{}{}
            if (record->event.pressed) {
                SEND_STRING("=frac"SS_ALGR("7")SS_ALGR("0")SS_ALGR("7")SS_ALGR("0"));
                SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
            }
            return false;
        case lft_dsktp:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_LEFT)SS_UP(X_LCTL)SS_UP(X_LGUI));
            }
            return false;
        case rght_dsktp:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_RIGHT)SS_UP(X_LCTL)SS_UP(X_LGUI));
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_macro_3x3(
        KC_SLEP, KC_MAIL, KC_CALC,
        KC_MPRV, KC_MPLY, KC_MNXT,
        KC_MUTE, KC_VOLD, KC_VOLU    
    ),
    

    [1] = LAYOUT_macro_3x3(
        KC_7, KC_8, KC_9,
        KC_4, KC_5, KC_6,
        KC_1, KC_2, KC_3
    ),
};