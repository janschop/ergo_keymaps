// Copyright 2023 Jan Erik Schopmeier (@janschop)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define I2C_DRIVER I2CD1
#define I2C_SDA_PIN GP2
#define I2C_SCL_PIN GP3


/* disable debug print */
//#define NO_DEBUG

/*#define SPLIT_USB_DETECT

#define MATRIX_COL_PINS_RIGHT {B4, B5, B6, C6, C7, F7}
#define MATRIX_ROW_PINS_RIGHT {F0, F1, F4, F5}
#define EE_HANDS*/
/* disable print */
//#define NO_PRINT

/* disable action features */
// #define TAPPING_TOGGLE 2
// #define ONESHOT_TAP_TOGGLE 2
// #define ONESHOT_TIMEOUT 300
//#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

// Mouse key speed and acceleration.
// #define MOUSEKEY_INERTIA
// #undef MOUSEKEY_DELAY
// #define MOUSEKEY_DELAY          150
// #undef MOUSEKEY_INTERVAL
// #define MOUSEKEY_INTERVAL       16
// #undef MOUSEKEY_MAX_SPEED 
// #define MOUSEKEY_MAX_SPEED      40
// #undef MOUSEKEY_TIME_TO_MAX
// #define MOUSEKEY_TIME_TO_MAX    40
// #undef MOUSEKEY_FRICTION
// #define MOUSEKEY_FRICTION       13
// #undef MOUSEKEY_MOVE_DELTA
// #define MOUSEKEY_MOVE_DELTA     2

// #undef MOUSEKEY_WHEEL_DELAY
// #define MOUSEKEY_WHEEL_DELAY    180
// #undef MOUSEKEY_WHEEL_INTERVAL
// #define MOUSEKEY_WHEEL_INTERVAL 60
// #undef MOUSEKEY_WHEEL_MAX_SPEED
// #define MOUSEKEY_WHEEL_MAX_SPEED 3
// #undef MOUSEKEY_WHEEL_TIME_TO_MAX
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 255