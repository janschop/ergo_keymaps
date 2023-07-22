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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_spit_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_LEFT_BRACKET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LGUI ,KC_LALT, KC_BSPC,   TT(1),                        TT(2),  KC_SPC, KC_RALT, KC_ENT,XXXXXXX,XXXXXXX
                      //`---------------------------------'                     `----------------------------------'

  ),

    [1] = LAYOUT_ortho_spit_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,     KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT,KC_ESCAPE, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                       KC_EQL,  XXXXXXX,  XXXXXXX,XXXXXXX, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_NUBS, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                      XXXXXXX,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT,KC_DELETE,_______,                        TT(3),  KC_SPC, KC_RALT, KC_ENT,XXXXXXX,XXXXXXX
                      //`---------------------------------'                     `----------------------------------'
  ),

    [2] = LAYOUT_ortho_spit_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT,KC_ESCAPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PLUS, KC_HOME,   KC_UP,  KC_END, KC_RCBR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| 
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT,KC_DELETE,XXXXXXX,                      _______,  KC_SPC, KC_RALT,  KC_ENT, XXXXXXX, XXXXXXX
                      //`---------------------------------'                     `----------------------------------'
  ),

    [3] = LAYOUT_ortho_spit_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_ESCAPE,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BTN4, KC_BTN1, KC_WH_U, KC_BTN2, KC_BTN5,                       KC_F12, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_BSPC,_______,                       _______,  KC_SPC, KC_RALT,  KC_ENT ,XXXXXXX, XXXXXXX
                      //`---------------------------------'                     `----------------------------------'
    )
};

uint16_t init_done = 0;

// layer_state_t layer_state_set_user(layer_state_t state) {
//   if (init_done == 0) {
//     setPinOutput(B0);
//     setPinOutput(D5);
//     writePinHigh(B0);
//     writePinHigh(D5);
//     init_done = 1;
//   }
//   else {
//     switch(get_highest_layer(state)) {
//     case 0:
//       writePinHigh(B0);
//       writePinHigh(D5); 
//     case 1:
//     writePinLow(B0);
//     //writePinHigh(D5);

//       break;
//     case 2:
//       //writePinHigh(B0);
//       writePinLow(D5);
//       break;
//     case 3:
//       writePinLow(B0);
//       writePinLow(D5);
//     default:
//       writePinHigh(B0);
//       writePinHigh(D5);
//       break;
//     }
//   }
//   return state;
// }                          