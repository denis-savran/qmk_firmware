#pragma once

#define ORYX_CONFIGURATOR
#define MOONLANDER_USER_LEDS  // Disable dot indicators.

// https://docs.qmk.fm/#/config_options
#undef USB_SUSPEND_WAKEUP_DELAY
#define USB_SUSPEND_WAKEUP_DELAY 0

// https://docs.qmk.fm/#/tap_hold
#undef TAPPING_TERM
#define TAPPING_TERM 200

// https://docs.qmk.fm/#/feature_mouse_keys
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 50

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 1  // 1000 Hz

#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 1

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 100

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 100

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 100

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 1  // 1000 Hz

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 5

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100

// https://docs.qmk.fm/#/feature_rgb_matrix
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#undef RGB_MATRIX_STARTUP_SPD
#define RGB_MATRIX_STARTUP_SPD 50

