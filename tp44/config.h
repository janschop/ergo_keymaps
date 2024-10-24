// Copyright 2023 Jan Erik Schopmeier (@janschop)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U


#define DYNAMIC_MACRO_DELAY 50
#define COMBO_ONLY_FROM_LAYER 6
#define TAPPING_TOGGLE 3
#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 250
#define TAPPING_TERM 250
#define COMBO_TERM 45
#define COMBO_TERM_PER_COMBO

// sm_td
#define MAX_DEFERRED_EXECUTORS 10


// Mouse key speed and acceleration.
#define MOUSEKEY_INERTIA
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          150
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_MAX_SPEED 
#define MOUSEKEY_MAX_SPEED      40
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    40
#undef MOUSEKEY_FRICTION
#define MOUSEKEY_FRICTION       10
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA     2

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    151
#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 60
#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 3
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 255

#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP12
#define I2C1_SCL_PIN GP9

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT

 #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE 