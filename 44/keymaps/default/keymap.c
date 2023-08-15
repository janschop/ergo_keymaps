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

// test 2

#include QMK_KEYBOARD_H

enum {
    LSFT_CAPS,
    RSFT_ENTER,
};

enum custom_keycodes {
    ralt2 = SAFE_RANGE,
    ralt3,
    ralt4,
    ralt5,
    ralt7,
    ralt8,
    ralt9,
    ralt0,
    print,
    kiwi, 
    rema,
    bunnpris,
    mail,
    first_name,
    last_name,
    number,
    // raltfslash,
    // ralttilde,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ralt2:
        if (record->event.pressed) {
            SEND_STRING(SS_RALT("2"));
        } else {
            // when keycode ralt2 is released
        }
        break;

    case ralt3:
        if (record->event.pressed) {
            SEND_STRING(SS_RALT("3"));
        } else {
            // when keycode ralt3 is released
        }
        break;

    case ralt4:
        if (record->event.pressed) {
            SEND_STRING(SS_RALT("4"));
        } else {
            // when keycode ralt4 is released
        }
        break;

    case ralt5:
        if (record->event.pressed) {
            SEND_STRING(SS_RALT("5"));
        } else {
            // when keycode ralt5 is released
        }
        break;

    case ralt7:
        if (record->event.pressed) {
            SEND_STRING(SS_RALT("7"));
        } else {
            // when keycode ralt7 is released
        }
        break;

    case ralt8:
        if (record->event.pressed) {
            SEND_STRING(SS_RALT("8"));
        } else {
            // when keycode ralt8 is released
        }
        break;

    case ralt9:
        if (record->event.pressed) {
            SEND_STRING(SS_RALT("9"));
        } else {
            // when keycode ralt9 is released
        }
        break;

        case ralt0:
        if (record->event.pressed) {
            SEND_STRING(SS_RALT("0"));
        } else {
            // when keycode ralt0 is released
        }
        break;

        case bunnpris:
        if (record->event.pressed) {
            SEND_STRING("bunnpris");
        } else {
            // when keycode is released
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
            SEND_STRING("jan.erik@schopmeier.com");
        }
        break;
        
        case first_name:
        if (record->event.pressed) {
            SEND_STRING("Jan Erik");
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
        
        
        // both do not work..
        // case raltfslash:
        // if (record->event.pressed) {
        //     SEND_STRING(SS_RALT("\\"));
        // } else {
        //     // when keycode ralt0 is released
        // }
        // break;
        // 
        // case ralttilde:
        // if (record->event.pressed) {
        //     SEND_STRING(SS_RALT("¨"));
        // } else {
        //     // when keycode ralt0 is released
        // }
        // break;
    }
    return true;

};

tap_dance_action_t tap_dance_actions[] = {
    [LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [RSFT_ENTER] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,KC_LEFT_BRACKET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
TD(LSFT_CAPS),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,KC_SLSH,TD(RSFT_ENTER),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LGUI ,KC_LALT, KC_BSPC,   OSL(1),                        OSL(2),  KC_SPC, MO(5), KC_ENT,XXXXXXX,XXXXXXX
                      //`---------------------------------'                     `----------------------------------'

  ),

    [1] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL,  KC_BTN4, KC_BTN1, KC_WH_U, KC_BTN2, KC_BTN5,                       KC_EQL, XXXXXXX, XXXXXXX, XXXXXXX, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
TD(LSFT_CAPS),KC_ESCAPE,KC_WH_L,KC_WH_D,KC_WH_R,  TO(0),                      XXXXXXX, XXXXXXX, _______, _______, _______,TD(RSFT_ENTER),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT,KC_DELETE,_______,                       OSL(3),  KC_SPC, KC_RALT,  KC_ENT, XXXXXXX, XXXXXXX
                      //`---------------------------------'                     `----------------------------------'
  ),

    [2] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,   KC_F4,                      KC_PLUS, KC_HOME,   KC_UP,  KC_END, KC_RCBR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
TD(LSFT_CAPS),KC_NUBS,KC_MUTE,KC_VOLD, KC_VOLU,   TO(0),                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX,  KC_ENT,
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
      QK_BOOT, XXXXXXX,    kiwi,bunnpris,    rema, XXXXXXX,                       KC_NUM,   KC_P7,   KC_P8,   KC_P9, KC_PSLS, KC_PAST,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX,                       KC_TAB,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PMNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT,   TO(0),                      XXXXXXX,   KC_P1,   KC_P2,   KC_P3, XXXXXXX, KC_PENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_BSPC,_______,                       _______,   KC_P0, KC_PDOT,  KC_ENT ,XXXXXXX, XXXXXXX
                      //`---------------------------------'                     `----------------------------------'
    ),

      [5] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,   ralt2,   ralt3,   ralt4,   ralt5,                      XXXXXXX,   ralt7,   ralt8,   ralt9,   ralt0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,first_name,XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,last_name,XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,   print, XXXXXXX,   TO(0),                       number,    mail, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                       XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
                      //`---------------------------------'                     `----------------------------------'
    )
};