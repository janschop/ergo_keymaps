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
};

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
};

void keyboard_pre_init_user(void) {
    setPinOutput(D3);  // initialize D3 for LED
    writePinHigh(D3);  // turn on LED for testing
}
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

        case print:
        if (record->event.pressed) {
            SEND_STRING("printf"SS_DOWN(X_LSFT)"82"SS_UP(X_LSFT));
            SEND_STRING("=n"SS_DOWN(X_LSFT)"29,"SS_UP(X_LSFT));
            SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        }
        break;
        case frac: //\frac{}{}
        if (record->event.pressed) {
            // SEND_STRING("\\frac"(X_RALT)"70"SS_UP(X_RALT));
            // SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        }
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
            SEND_STRING("<3");
        }
  
    }
    return true;    

};
tap_dance_action_t tap_dance_actions[] = {
    [LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [RSFT_ENTER] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.          
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          
  //|--------+--------+--------+--------+--------+--------|          
      KC_LCTL,    SFT_T(KC_A),    KC_S,    KC_D,    KC_F,    KC_G,          
  //|--------+--------+--------+--------+--------+--------|          
TD(LSFT_CAPS),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          
  //|--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LGUI ,KC_LALT, KC_BSPC,  OSL(1),          
// -----------------------------------------------------
// -----------------------------------------------------
         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,KC_LEFT_BRACKET,
//  |--------+--------+--------+--------+--------+--------|
         KC_H,    KC_J,    KC_K,    KC_L, SFT_T(KC_SCLN), KC_QUOT,
//  |--------+--------+--------+--------+--------+--------|
         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,SC_SENT,
 // |--------+--------+--------+--------+--------+--------|
        OSL(2),  KC_SPC,  OSL(5),  KC_LGUI, XXXXXXX, XXXXXXX
  ),

    [1] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.          
    KC_ESCAPE,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          
  //|--------+--------+--------+--------+--------+--------|          
      KC_LCTL, KC_BTN4, KC_BTN1, KC_WH_U, KC_BTN2, KC_BTN5,          
  //|--------+--------+--------+--------+--------+--------|          
TD(LSFT_CAPS), KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_R,   TO(0),          
  //|--------+--------+--------+--------+--------+--------+--------| 
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT,KC_DELETE,_______,          
                      //`---------------------------------'    
        //      ,-----------------------------------------------------.
               KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
         // |--------+--------+--------+--------+--------+--------|
             KC_EQL,lft_dsktp,G(KC_TAB),rght_dsktp,KC_RBRC,KC_BSLS,
        //  |--------+--------+--------+--------+--------+--------|
                dplct, XXXXXXX, _______, _______, _______,SC_SENT,
 //|--------+--------+--------+--------+--------+--------+--------|
             OSL(3),  KC_SPC, KC_RALT,  _______, XXXXXXX, XXXXXXX
   //        `----------------------------------'      
  ),

    [2] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.          
    KC_GRV,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),   
  //|--------+--------+--------+--------+--------+--------|          
      KC_LCTL, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT,   KC_F4,          
  //|--------+--------+--------+--------+--------+--------|          
TD(LSFT_CAPS),KC_NUBS,LSFT(KC_NUBS),KC_VOLD,KC_VOLU, TO(0),             
  //|--------+--------+--------+--------+--------+--------+--------| 
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT,KC_DELETE, TO(4),          
        //`---------------------------------'   
        //    ,-----------------------------------------------------.
  LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0),LSFT(KC_MINS),
        //    |--------+--------+--------+--------+--------+--------|
        LSFT(KC_EQL), KC_HOME,   KC_UP,  KC_END,LSFT(KC_RBRC),LSFT(KC_BSLS),
        //    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX,  KC_ENT,
//   |--------+--------+--------+--------+--------+--------+--------| 
             _______,  KC_SPC, KC_RALT,_______, XXXXXXX, XXXXXXX
            // `----------------------------------'                
  ),

    [3] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.          
    KC_ESCAPE,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          
  //|--------+--------+--------+--------+--------+--------|          
      XXXXXXX, KC_BTN4, KC_BTN1, KC_WH_U, KC_BTN2, KC_BTN5,          
  //|--------+--------+--------+--------+--------+--------|          
      XXXXXXX, KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_R,   TO(0),          
  //|--------+--------+--------+--------+--------+--------+--------| 
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_BSPC,_______,           
                      //`---------------------------------'   
              KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
        //   |--------+--------+--------+--------+--------+--------|
             KC_F12, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, KC_PSCR,
        //   |--------+--------+--------+--------+--------+--------|
            XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------+--------|
            _______,  KC_SPC, KC_RALT,  _______ ,XXXXXXX, XXXXXXX
        //    `----------------------------------'
           
    ),
    
      [4] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.          
      QK_BOOT, XXXXXXX,    kiwi,bunnpris,    rema, XXXXXXX,          
  //|--------+--------+--------+--------+--------+--------|          
      XXXXXXX, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX,          
  //|--------+--------+--------+--------+--------+--------|          
      XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT,   TO(0),          
  //|--------+--------+--------+--------+--------+--------+--------| 
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_BSPC,_______,           
                      //`---------------------------------'          
             KC_NUM,   KC_P7,   KC_P8,   KC_P9, KC_PSLS, KC_PAST,
        //   |--------+--------+--------+--------+--------+--------|
             KC_TAB,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PMNS,
        //   |--------+--------+--------+--------+--------+--------|
            XXXXXXX,   KC_P1,   KC_P2,   KC_P3, XXXXXXX, KC_PENT,
//  |--------+--------+--------+--------+--------+--------+--------|
            _______,   KC_P0, KC_PDOT,  _______ ,XXXXXXX, XXXXXXX
        //    `----------------------------------'
    ),

      [5] = LAYOUT_ortho_split_3x6_4(
  //,-----------------------------------------------------.          
      XXXXXXX, XXXXXXX,ALGR(KC_2),ALGR(KC_3),ALGR(KC_4),ALGR(KC_5), 
  //|--------+--------+--------+--------+--------+--------|          
      XXXXXXX, XXXXXXX, XXXXXXX,   dplct,first_name,XXXXXXX,         
  //|--------+--------+--------+--------+--------+--------|          
      XXXXXXX,   heart, XXXXXXX,   print, XXXXXXX,   TO(0),          
  //|--------+--------+--------+--------+--------+--------+--------| 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           
                    //`---------------------------------'            
      XXXXXXX,ALGR(KC_7),ALGR(KC_8),ALGR(KC_9),ALGR(KC_0),XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,XXXXXXX,last_name,ALGR(KC_RBRC),XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|
       number,    mail, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
        //  `----------------------------------'   
    )
};