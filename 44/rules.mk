SRC += features/layer_lock.c
VPATH += keyboards/gboards

CONSOLE_ENABLE = yes
RGBLIGHT_SUPPORTED = no
RGB_MATRIX_SUPPORTED = no
CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = bitbang
COMBO_ENABLE = yes # disable for midi
DYNAMIC_MACRO_ENABLE = yes
# MIDI_ENABLE = yes
# TAP_DANCE_ENABLE = yes

# sm_td
DEFERRED_EXEC_ENABLE = yes