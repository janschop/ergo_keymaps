// Copyright 2023 Jan Erik Schopmeier (@janschop)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

// bool set_scrolling = false;
// // Modify these values to adjust the scrolling speed
// #define SCROLL_DIVISOR_H 15.0
// #define SCROLL_DIVISOR_V 15.0
// #define ZOOM_DIVISOR 5
//
// // Variables to store accumulated scroll values
// float scroll_accumulated_h = 0;
// float scroll_accumulated_v = 0;
// uint8_t zoom_in = 0;
// uint8_t zoom_out = 0;
//
// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     // Check if drag scrolling is active
//     // Calculate and accumulate scroll values based on mouse movement and divisors
//     scroll_accumulated_h += (float)mouse_report.h / SCROLL_DIVISOR_H;
//     scroll_accumulated_v += (float)mouse_report.v / SCROLL_DIVISOR_V;
//
//     // Assign integer parts of accumulated scroll values to the mouse report
//     mouse_report.v = -(int8_t)scroll_accumulated_h;
//     mouse_report.h = -(int8_t)scroll_accumulated_v;
//
//     // Update accumulated scroll values by subtracting the integer parts
//     scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
//     scroll_accumulated_v -= (int8_t)scroll_accumulated_v;
//     if (mouse_report.buttons & (1 << 7)) {
//         zoom_in ++;
//     } 
//     if (mouse_report.buttons & (1 << 6)) {
//         zoom_out ++;
//     }
//
//     if (zoom_in == ZOOM_DIVISOR) {
//         SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_MINS)SS_UP(X_LCTL));
//         zoom_in = 0;
//     }
//     if (zoom_out == ZOOM_DIVISOR) {
//         SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SLSH)SS_UP(X_LCTL));
//         zoom_out = 0;
//     }
//     return mouse_report;
// }

void keyboard_post_init_user(void) {
  debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
  debug_mouse=true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   
    [0] = LAYOUT_split_3x5_3u4(//base
                 QK_BOOT, _______,_______, _______,
                 QK_BOOT  ,        KC_U,    KC_I,    KC_O,           KC_P,          
                 KC_H  ,        KC_J,    KC_K,    KC_L, CTL_T(KC_SCLN), 
                 KC_N  ,        KC_M, KC_COMM,  KC_DOT, SFT_T(KC_SLSH),
        KC_BTN1, LT(2, KC_SPC), OSL(3)
    ),
};

