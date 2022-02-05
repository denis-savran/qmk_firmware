#pragma once

#define MOONLANDER_USER_LEDS  // Disable LED layer indication.

#define NO_ACTION_ONESHOT  // Disable one-shot modifiers.

// https://docs.qmk.fm/#/config_options
#undef USB_SUSPEND_WAKEUP_DELAY
#define USB_SUSPEND_WAKEUP_DELAY 0

// https://docs.qmk.fm/#/feature_rgb_matrix
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#undef RGB_MATRIX_STARTUP_SPD
#define RGB_MATRIX_STARTUP_SPD 50

// https://docs.qmk.fm/#/config_options?id=behaviors-that-can-be-configured
// Recommended for heavy chording.
#undef QMK_KEYS_PER_SCAN
#define QMK_KEYS_PER_SCAN 4

// https://docs.qmk.fm/#/tap_hold
#undef TAPPING_TERM
#define TAPPING_TERM 150

// If you press a dual-role key, tap another key and then release the dual-role key, all within the tapping term,
// the dual-role key will perform its hold action.
#define PERMISSIVE_HOLD

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

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

#define LAYOUT_blaxpy(\
    K00, K01, K02, K03, K04, K05, K06,     K07, K08, K09, K10, K11, K12, K13,\
    K14, K15, K16, K17, K18, K19, K20,     K21, K22, K23, K24, K25, K26, K27,\
    K28, K29, K30, K31, K32, K33, K34,     K35, K36, K37, K38, K39, K40, K41,\
    K42, K43, K44, K45, K46, K47, K48,     K49, K50, K51, K52, K53, K54, K55,\
    K56, K57, K58, K59, K60, K61, K62,     K63, K64, K65, K66, K67, K68, K69,\
    K70, K71, K72, K73, K74, K75, K76,     K77, K78, K79, K80, K81, K82, K83\
)\
LAYOUT_moonlander(\
    K00, K01, K02, K03, K04, K05, K06,     K07, K08, K09, K10, K11, K12, K13,\
    K14, K15, K16, K17, K18, K19, K20,     K21, K22, K23, K24, K25, K26, K27,\
    K28, K29, K30, K31, K32, K33, K34,     K35, K36, K37, K38, K39, K40, K41,\
    K42, K43, K44, K45, K46, K47,               K50, K51, K52, K53, K54, K55,\
    K56, K57, K58, K59, K60,      K62,     K63,      K65, K66, K67, K68, K69,\
                        K74, K75, K76,     K77, K78, K79\
)
