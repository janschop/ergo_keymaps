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
    TD_LSFT_CAPS,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,KC_LEFT_BRACKET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
TD(TD_LSFT_CAPS),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LGUI ,KC_LALT, KC_BSPC,   OSL(1),                        OSL(2),  KC_SPC, KC_RALT, KC_ENT,XXXXXXX,XXXXXXX
                      //`---------------------------------'                     `----------------------------------'

  ),

    [1] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL,KC_ESCAPE, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                       KC_EQL, XXXXXXX, XXXXXXX, XXXXXXX, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
TD(TD_LSFT_CAPS),KC_NUBS,KC_MUTE,KC_VOLD, KC_VOLU,   TO(0),                      XXXXXXX, XXXXXXX, _______, _______, _______, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT,KC_DELETE,_______,                       OSL(3),  KC_SPC, KC_RALT,  KC_ENT, XXXXXXX, XXXXXXX
                      //`---------------------------------'                     `----------------------------------'
  ),

    [2] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL,KC_ESCAPE, XXXXXXX, XXXXXXX,   KC_F4, XXXXXXX,                      KC_PLUS, KC_HOME,   KC_UP,  KC_END, KC_RCBR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
TD(TD_LSFT_CAPS),XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,   TO(0),                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| 
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT,KC_DELETE, OSL(4),                      _______,  KC_SPC, KC_RALT,  KC_ENT, XXXXXXX, XXXXXXX
                      //`---------------------------------'                     `----------------------------------'
  ),

    [3] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_ESCAPE,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BTN4, KC_BTN1, KC_WH_U, KC_BTN2, KC_BTN5,                       KC_F12, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R,   TO(0),                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_BSPC,_______,                       _______,  KC_SPC, KC_RALT,  KC_ENT ,XXXXXXX, XXXXXXX
                      //`---------------------------------'                     `----------------------------------'
    ),
    
      [4] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_NUM,   KC_P7,   KC_P8,   KC_P9, KC_PSLS, KC_PAST,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_TAB,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PMNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   TO(0),                      XXXXXXX,   KC_P1,   KC_P2,   KC_P3, XXXXXXX, KC_PENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_BSPC,_______,                       _______,   KC_P0, KC_PDOT,  KC_ENT ,XXXXXXX, XXXXXXX
                      //`---------------------------------'                     `----------------------------------'
    )
};


uint16_t init_done = 0;

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {

//     case KC_U:
//         // Detect the activation of only Left Alt
//         if (get_mods() == MOD_BIT(KC_RALT)) {
//             if (record->event.pressed) {
//                 // No need to register KC_LALT because it's already active.
//                 // The Alt modifier will apply on this KC_TAB.
//                 register_code(LSFT(KC_7));
//             } else {
//                 unregister_code(LSFT(KC_7));
//             }
//             // Do not let QMK process the keycode further
//             return false;
//         }
//         // Else, let QMK process the KC_ESC keycode as usual
//         return true;

//     }
//     return true;
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {

//     case KC_U:
//         // Detect the activation of only Left Alt
//         if (get_mods() == MOD_BIT(KC_RALT)) {
//             if (record->event.pressed) {
//                 // No need to register KC_LALT because it's already active.
//                 // The Alt modifier will apply on this KC_TAB.
//                 unregister_code(LSFT(KC_7));
//             } else {
//                 unregister_code(LSFT(KC_7));
//             }
//             // Do not let QMK process the keycode further
//             return false;
//         }
//         // Else, let QMK process the KC_ESC keycode as usual
//         return true;

//     }
//     return true;
// };

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