// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  debug_mouse=true;
}
//Function to handle mouse reports and perform drag scrolling
// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     // Check if drag scrolling is active
//     // Calculate and accumulate scroll values based on mouse movement and divisors
//     scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
//     scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;
//     // Assign integer parts of accumulated scroll values to the mouse report
//     mouse_report.h = (int8_t)scroll_accumulated_h;
//     mouse_report.v = (int8_t)scroll_accumulated_v;
//     // Update accumulated scroll values by subtracting the integer parts
//     scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
//     scroll_accumulated_v -= (int8_t)scroll_accumulated_v;
//     // Clear the X and Y values of the mouse report
//     mouse_report.x = 0;
//     mouse_report.y = 0;
//     return mouse_report;
// }
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

const uint16_t PROGMEM sd_esc[] = {KC_S, KC_D, COMBO_END};

combo_t key_combos[] = {
    COMBO(sd_esc, KC_ESC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_LGUI, KC_BSPC,      KC_ENT,  KC_SPC
    )
};
