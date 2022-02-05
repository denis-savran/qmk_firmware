#include QMK_KEYBOARD_H
#include "version.h"

#define XXXX KC_NO  // Key is not present.
#define U_NA KC_NO  // Present but not available for use.
#define U_NU KC_NO  // Available but not used.

// Layers.
#define T_BASE TO(BASE)
#define T_MOU TO(MOU)
#define T_RMOU TO(RMOU)
#define BUT_Z LT(BUT, KC_Z)
#define BUT_SLSH LT(BUT, KC_SLSH)

// Left-hand thumb cluster.
#define SYM_TAB LT(SYM, KC_TAB)
#define NUM_SPC LT(NUM, KC_SPC)
#define FUN_ESC LT(FUN, KC_ESC)

// Right-hand thumb cluster.
#define MED_DEL LT(MED, KC_DEL)
#define NAV_BSPC LT(NAV, KC_BSPC)
#define MOU_ENT LT(MOU, KC_ENT)

// History and clipboard.
#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)

extern rgb_config_t rgb_matrix_config;

enum layers { BASE, SYM, NUM, FUN, MED, NAV, MOU, RMOU, BUT };

// See `g_led_config` in `keyboards/moonlander/moonlander.c`.
enum rgb_matrix_keycode_indexes {
    RGB_LEFT_CAPS = 29,

    RGB_LEFT_LGUI = 7,
    RGB_LEFT_LALT = 12,
    RGB_LEFT_LCTL = 17,
    RGB_LEFT_LSFT = 22,

    RGB_LEFT_BUT = 8,
    RGB_LEFT_ALGR = 13,

    RGB_LEFT_T_RMOU = 35,

    RGB_LEFT_FUN = 34,
    RGB_LEFT_NUM = 33,
    RGB_LEFT_SYM = 32,

    RGB_RIGHT_LSFT = 58,
    RGB_RIGHT_LCTL = 53,
    RGB_RIGHT_LALT = 48,
    RGB_RIGHT_LGUI = 43,

    RGB_RIGHT_ALGR = 49,
    RGB_RIGHT_BUT = 44,

    RGB_RIGHT_T_MOU = 71,

    RGB_RIGHT_MED = 70,
    RGB_RIGHT_NAV = 69,
    RGB_RIGHT_MOU = 68,
};

// https://github.com/manna-harbour/qmk_firmware/blob/miryoku/users/manna-harbour_miryoku/miryoku.org
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_blaxpy(
        U_NU,    U_NU,         U_NU,         U_NU,         U_NU,         U_NU,    U_NU,    U_NU,    U_NU,     U_NU,         U_NU,         U_NU,           U_NU,            U_NU,
        U_NU,    U_NA,         KC_W,         KC_E,         KC_R,         KC_T,    U_NU,    U_NU,    KC_Y,     KC_U,         KC_I,         KC_O,           U_NA,            U_NU,
        KC_Q,    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    U_NU,    U_NU,    KC_H,     LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L),   LGUI_T(KC_SCLN), KC_P,
        U_NU,    BUT_Z,        ALGR_T(KC_X), KC_C,         KC_V,         KC_B,    XXXX,    XXXX,    KC_N,     KC_M,         KC_COMM,      ALGR_T(KC_DOT), BUT_SLSH,        U_NU,
        KC_PAUS, KC_LEFT,      KC_RIGHT,     U_NU,         U_NU,         XXXX,    T_RMOU,  T_MOU,   XXXX,     U_NU,         U_NU,         KC_MPRV,        KC_MNXT,         KC_MPLY,
        XXXX,    XXXX,         XXXX,         XXXX,         SYM_TAB,      NUM_SPC, FUN_ESC, MED_DEL, NAV_BSPC, MOU_ENT,      XXXX,         XXXX,           XXXX,            XXXX
    ),
    [SYM] = LAYOUT_blaxpy(
        U_NU, U_NU,    U_NU,    U_NU,    U_NU,    U_NU, U_NU, U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
        U_NU, U_NA,    U_NA,    U_NA,    U_NA,    U_NA, U_NU, U_NU,    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, U_NA,    U_NU,
        U_NA, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA, U_NU, U_NA,    KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_DQUO, KC_RCBR,
        U_NU, U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA, XXXX, XXXX,    KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD, U_NU,
        U_NU, U_NU,    U_NU,    U_NU,    U_NU,    XXXX, U_NA, U_NA,    XXXX,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
        XXXX, XXXX,    XXXX,    XXXX,    U_NA,    U_NA, U_NA, KC_LPRN, KC_RPRN, KC_UNDS, XXXX,    XXXX,    XXXX,    XXXX
    ),
    [NUM] = LAYOUT_blaxpy(
        U_NU, U_NU,    U_NU,    U_NU,    U_NU,    U_NU, U_NU, U_NU,   U_NU,    U_NU,    U_NU, U_NU, U_NU,    U_NU,
        U_NU, U_NA,    U_NA,    U_NA,    U_NA,    U_NA, U_NU, U_NU,   KC_LBRC, KC_7,    KC_8, KC_9, U_NA,    U_NU,
        U_NA, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA, U_NU, U_NU,   KC_EQL,  KC_4,    KC_5, KC_6, KC_QUOT, KC_RBRC,
        U_NU, U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA, XXXX, XXXX,   KC_BSLS, KC_1,    KC_2, KC_3, KC_GRV,  U_NU,
        U_NU, U_NU,    U_NU,    U_NU,    U_NU,    XXXX, U_NA, U_NA,   XXXX,    U_NU,    U_NU, U_NU, U_NU,    U_NU,
        XXXX, XXXX,    XXXX,    XXXX,    U_NA,    U_NA, U_NA, KC_DOT, KC_0,    KC_MINS, XXXX, XXXX, XXXX,    XXXX
    ),
    [FUN] = LAYOUT_blaxpy(
        U_NU, U_NU,    U_NU,    U_NU,    U_NU,    U_NU, U_NU, U_NU,   U_NU,    U_NU,   U_NU,  U_NU,  U_NU,   U_NU,
        U_NU, U_NA,    U_NA,    U_NA,    U_NA,    U_NA, U_NU, U_NU,   KC_PSCR, KC_F7,  KC_F8, KC_F9, U_NA,   U_NU,
        U_NA, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA, U_NU, U_NU,   KC_SLCK, KC_F4,  KC_F5, KC_F6, KC_F11, KC_F12,
        U_NU, U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA, XXXX, XXXX,   KC_PAUS, KC_F1,  KC_F2, KC_F3, KC_F10, U_NU,
        U_NU, U_NU,    U_NU,    U_NU,    U_NU,    XXXX, U_NA, U_NA,   XXXX,    U_NU,   U_NU,  U_NU,  U_NU,   U_NU,
        XXXX, XXXX,    XXXX,    XXXX,    U_NA,    U_NA, U_NA, KC_DEL, KC_BSPC, KC_ENT, XXXX,  XXXX,  XXXX,   XXXX
    ),
    [MED] = LAYOUT_blaxpy(
        U_NU, U_NU,    U_NU,     U_NU,    U_NU,    U_NU,    U_NU,    U_NU, U_NU, U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
        U_NU, U_NA,    RGB_RMOD, KC_VOLU, RGB_MOD, RGB_VAI, U_NU,    U_NU, U_NA, U_NA,    U_NA,    U_NA,    U_NA,    U_NU,
        U_NU, U_NU,    KC_MPRV,  KC_VOLD, KC_MNXT, RGB_VAD, U_NU,    U_NU, U_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, U_NA,
        U_NU, RGB_TOG, U_NU,     U_NU,    U_NU,    U_NU,    XXXX,    XXXX, U_NA, U_NA,    U_NA,    KC_ALGR, U_NA,    U_NU,
        U_NU, U_NU,    U_NU,     U_NU,    U_NU,    XXXX,    U_NA,    U_NA, XXXX, U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
        XXXX, XXXX,    XXXX,     XXXX,    KC_MUTE, KC_MPLY, KC_MSTP, U_NA, U_NA, U_NA,    XXXX,    XXXX,    XXXX,    XXXX
    ),                                                               
    [NAV] = LAYOUT_blaxpy(
        U_NU,   U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,   U_NU, U_NU, U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
        U_NU,   U_NA,    KC_HOME, KC_UP,   KC_END,  KC_PGUP, U_NU,   U_NU, U_NA, U_NA,    U_NA,    U_NA,    U_NA,    U_NU,
        KC_INS, KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, U_NU,   U_NU, U_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, U_NA,
        U_NU,   U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,   XXXX,   XXXX, U_NA, U_NA,    U_NA,    KC_ALGR, U_NA,    U_NU,
        U_NU,   U_NU,    U_NU,    U_NU,    U_NU,    XXXX,    U_NA,   U_NA, XXXX, U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
        XXXX,   XXXX,    XXXX,    XXXX,    KC_TAB,  KC_SPC,  KC_ESC, U_NA, U_NA, U_NA,    XXXX,    XXXX,    XXXX,    XXXX
    ),
    [MOU] = LAYOUT_blaxpy(
        U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,   U_NU, U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
        U_NU,    U_NA,    KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, U_NU,    U_NU,   U_NA, U_NA,    U_NA,    U_NA,    U_NA,    U_NU,
        U_NU,    U_NU,    KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, U_NU,    U_NU,   U_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, U_NA,
        U_NU,    U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,   XXXX,    XXXX,   U_NA, U_NA,    U_NA,    KC_ALGR, U_NA,    U_NU,
        KC_TRNS, KC_TRNS, KC_TRNS, U_NU,    U_NU,    XXXX,    T_BASE,  T_BASE, XXXX, U_NU,    U_NU,    KC_TRNS, KC_TRNS, KC_TRNS,
        XXXX,    XXXX,    XXXX,    XXXX,    KC_BTN2, KC_BTN1, KC_BTN3, U_NA,   U_NA, U_NA,    XXXX,    XXXX,    XXXX,    XXXX
    ),
    [RMOU] = LAYOUT_blaxpy(
        U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU, U_NU,   U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
        U_NU,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA, U_NU,   U_NU,    KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, U_NA,    U_NU,
        U_NA,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA, U_NU,   U_NU,    KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, U_NU,    U_NU,
        U_NU,    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA, XXXX,   XXXX,    U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   U_NU,
        KC_TRNS, KC_TRNS, KC_TRNS, U_NU,    U_NU,    XXXX, T_BASE, T_BASE,  XXXX,    U_NU,    U_NU,    KC_TRNS, KC_TRNS, KC_TRNS,
        XXXX,    XXXX,    XXXX,    XXXX,    U_NA,    U_NA, U_NA,   KC_BTN3, KC_BTN1, KC_BTN2, XXXX,    XXXX,    XXXX,    XXXX
    ),
    [BUT] = LAYOUT_blaxpy(
        U_NU,  U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
        U_NU,  U_NA,    U_CUT,   U_CPY,   U_PST,   U_RDO,   U_NU,    U_NU,    U_RDO,   U_PST,   U_CPY,   U_CUT,   U_NA,    U_NU,
        U_UND, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    U_NU,    U_NU,    U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, U_UND,
        U_NU,  U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,   XXXX,    XXXX,    U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   U_NU,
        U_NU,  U_NU,    U_NU,    U_NU,    U_NU,    XXXX,    U_NA,    U_NA,    XXXX,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
        XXXX,  XXXX,    XXXX,    XXXX,    KC_BTN2, KC_BTN1, KC_BTN3, KC_BTN3, KC_BTN1, KC_BTN2, XXXX,    XXXX,    XXXX,    XXXX
    ),
};


// https://docs.qmk.fm/#/feature_advanced_keycodes?id=checking-modifier-state
void rgb_matrix_layers(void) {
    int layer = biton32(layer_state);

    switch (layer) {
    case SYM:
        rgb_matrix_set_color(RGB_LEFT_SYM, RGB_WHITE);
        break;
    case NUM:
        rgb_matrix_set_color(RGB_LEFT_NUM, RGB_WHITE);
        break;
    case FUN:
        rgb_matrix_set_color(RGB_LEFT_FUN, RGB_WHITE);
        break;
    case MED:
        rgb_matrix_set_color(RGB_RIGHT_MED, RGB_WHITE);
        break;
    case NAV:
        rgb_matrix_set_color(RGB_RIGHT_NAV, RGB_WHITE);
        break;
    case MOU:
        rgb_matrix_set_color(RGB_RIGHT_T_MOU, RGB_RED);
        rgb_matrix_set_color(RGB_RIGHT_MOU, RGB_WHITE);
        break;
    case RMOU:
        rgb_matrix_set_color(RGB_LEFT_T_RMOU, RGB_RED);
        break;
    case BUT:
        rgb_matrix_set_color(RGB_LEFT_BUT, RGB_WHITE);
        rgb_matrix_set_color(RGB_RIGHT_BUT, RGB_WHITE);
        break;
    }
}


// https://docs.qmk.fm/#/feature_advanced_keycodes?id=checking-modifier-state
void rgb_matrix_mods(void) {
    if (get_mods() & MOD_MASK_SHIFT) {
        rgb_matrix_set_color(RGB_LEFT_LSFT, RGB_WHITE);
        rgb_matrix_set_color(RGB_RIGHT_LSFT, RGB_WHITE);
    }

    if (get_mods() & MOD_MASK_CTRL) {
        rgb_matrix_set_color(RGB_LEFT_LCTL, RGB_WHITE);
        rgb_matrix_set_color(RGB_RIGHT_LCTL, RGB_WHITE);
    }

    if (get_mods() & MOD_BIT(KC_LALT)) {
        rgb_matrix_set_color(RGB_LEFT_LALT, RGB_WHITE);
        rgb_matrix_set_color(RGB_RIGHT_LALT, RGB_WHITE);
    }

    if (get_mods() & MOD_MASK_GUI) {
        rgb_matrix_set_color(RGB_LEFT_LGUI, RGB_WHITE);
        rgb_matrix_set_color(RGB_RIGHT_LGUI, RGB_WHITE);
    }

    if (get_mods() & MOD_BIT(KC_ALGR)) {
        rgb_matrix_set_color(RGB_LEFT_ALGR, RGB_WHITE);
        rgb_matrix_set_color(RGB_RIGHT_ALGR, RGB_WHITE);
    }
}


void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

static bool caps_lock_state = false;

bool led_update_user(led_t led_state) {
    caps_lock_state = led_state.caps_lock;
    return true;
}

// https://docs.qmk.fm/#/feature_rgb_matrix
void rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return;
    }

    rgb_matrix_layers();
    rgb_matrix_mods();

    if (caps_lock_state) {
        rgb_matrix_set_color(RGB_LEFT_CAPS, RGB_WHITE);
    }
}
