// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}



//layout: {ortho_layout: {split: true, rows: 3, columns: 5, thumbs: 2}}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_split_3x6_4(//colemak dh
            XXXXXXX,KC_Q,        KC_W,    KC_F,    KC_P,   KC_B,    KC_J  ,        KC_L,    KC_U,    KC_Y,        KC_SCLN,          MI_A2,
     XXXXXXX,CTL_T(KC_A),        KC_R,    KC_S,    KC_T,   KC_G,    KC_K  ,        KC_N,    KC_E,    KC_I, CTL_T(KC_O), MI_A1,
     XXXXXXX,SFT_T(KC_Z), ALT_T(KC_X),    KC_C,    KC_D,   KC_V,    KC_M  ,        KC_H, KC_COMM,  KC_DOT, SFT_T(KC_SLSH),XXXXXXX,
                 QK_RBT, QK_BOOT,                 OSM(MOD_LSFT), OSL(1),    LT(2, KC_SPC), OSL(3), QK_BOOT, QK_RBT
    ),

    [6] = LAYOUT_ortho_split_3x6_4(//base
            XXXXXXX,KC_Q,        KC_W,    KC_E,    KC_R,   KC_T,    KC_Y  ,        KC_U,    KC_I,    KC_O,           KC_P,          XXXXXXX,
     XXXXXXX,CTL_T(KC_A),        KC_S,    KC_D,    KC_F,   KC_G,    KC_H  ,        KC_J,    KC_K,    KC_L, CTL_T(KC_SCLN), XXXXXXX,
     XXXXXXX,SFT_T(KC_Z), ALT_T(KC_X),    KC_C,    KC_V,   KC_B,    KC_N  ,        KC_M, KC_COMM,  KC_DOT, SFT_T(KC_SLSH),XXXXXXX,
                                  XXXXXXX,     XXXXXXX,OSM(MOD_LSFT), OSL(1),    LT(2, KC_SPC), OSL(3), XXXXXXX, XXXXXXX
    ),

   


    [5] = LAYOUT_ortho_split_3x6_4(// mouse
    XXXXXXX,XXXXXXX, XXXXXXX, G(KC_D), XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, G(KC_TAB), XXXXXXX, XXXXXXX,XXXXXXX,
    XXXXXXX,XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   KC_MS_U, XXXXXXX, XXXXXXX,   XXXXXXX,
    XXXXXXX,XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R,   TG(5),    XXXXXXX, KC_MS_L,   KC_MS_D, KC_MS_R, XXXXXXX,           XXXXXXX, 
                                 XXXXXXX,     XXXXXXX,TG(5),   TG(5),    TG(5)  ,     TG(5), XXXXXXX, XXXXXXX
    ),

};

