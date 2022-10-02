// https://docs.qmk.fm/#/config_options?id=the-configh-file
#pragma once

// https://docs.qmk.fm/#/squeezing_avr
#define LAYER_STATE_8BIT  // Limit the number of layers that the firmware uses.

#define MOONLANDER_USER_LEDS  // Disable LED layer indication.

// https://docs.qmk.fm/#/feature_rgb_matrix
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#undef RGB_MATRIX_STARTUP_SPD
#define RGB_MATRIX_STARTUP_SPD 50

// https://docs.qmk.fm/#/tap_hold
#undef TAPPING_TERM
#define TAPPING_TERM 200 // How long before a key press becomes a hold.

// https://docs.qmk.fm/#/one_shot_keys
#undef ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2  // Tapping this number of times holds the key until tapped once again.
#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 2000

// https://docs.qmk.fm/#/feature_caps_word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#undef CAPS_WORD_IDLE_TIMEOUT
#define CAPS_WORD_IDLE_TIMEOUT 2000

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
