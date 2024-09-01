#include QMK_KEYBOARD_H

extern MidiDevice midi_device;

// MIDI CC codes for generic on/off switches (80, 81, 82, 83)
// Off: 0-63
// On:  64-127

#define MIDI_CC_OFF 0
#define MIDI_CC_ON  127

enum custom_keycodes {
    MIDI_CC80 = SAFE_RANGE,
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case MIDI_CC80:
//             if (record->event.pressed) {
//                 midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_ON);
//             } else {
//                 midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_OFF);
//             }
//             return true;
//     }
//     return true;
// };

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_3x5_2(//colemak dh
  KC_J  ,        KC_L,    MI_A2,    MI_A1,        XXXXXXX,          
  KC_K  ,        KC_N,    KC_E,   KC_I, KC_O, 
  KC_M  ,        KC_H, KC_COMM,  KC_DOT, KC_SLSH,
  LT(2, KC_SPC),QK_BOOT
    )
};