#include QMK_KEYBOARD_H
#include "version.h"

#define XXXX KC_NO  // Non-existent key.
#define UUUU KC_NO  // Unused key.
#define ____ KC_TRANSPARENT  // Transparent key.

enum layers { BASE, FUNC };

// See `g_led_config` in `keyboards/moonlander/moonlander.c`.
// Top-to-bottom then left-to-right index order. 
enum rgb_matrix_keycode_indexes {
    RGB_LEFT_1_7 = 29,
    RGB_LEFT_4_1 = 3,
    RGB_LEFT_5_1 = 4,
    RGB_LEFT_5_4 = 19,
    RGB_LEFT_5_5 = 24,
    RGB_LEFT_RED = 35,

    RGB_RIGHT_1_1 = 65,
    RGB_RIGHT_4_7 = 39,
    RGB_RIGHT_5_3 = 60,
    RGB_RIGHT_5_4 = 55,
    RGB_RIGHT_5_7 = 40,
    RGB_RIGHT_RED = 71,
};

// https://docs.qmk.fm/#/keycodes
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE]             =        LAYOUT_blaxpy(
        KC_PAUS,       KC_1,    KC_2,    KC_3,          KC_4,          KC_5,   KC_SCRL,   KC_PSCR,   KC_6,    KC_7,          KC_8,          KC_9,     KC_0,    KC_MPLY,
        KC_GRV,        KC_Q,    KC_W,    KC_E,          KC_R,          KC_T,   KC_MINS,   KC_EQL,    KC_Y,    KC_U,          KC_I,          KC_O,     KC_P,    KC_BSLS,
        KC_CAPS,       KC_A,    KC_S,    KC_D,          KC_F,          KC_G,   KC_LBRC,   KC_RBRC,   KC_H,    KC_J,          KC_K,          KC_L,     KC_SCLN, KC_QUOT,
        OSM(MOD_LSFT), KC_Z,    KC_X,    KC_C,          KC_V,          KC_B,   XXXX,      XXXX,      KC_N,    KC_M,          KC_COMM,       KC_DOT,   KC_SLSH, OSM(MOD_RSFT),
        OSM(MOD_LCTL), KC_LEFT, KC_RGHT, OSM(MOD_LGUI), OSM(MOD_LALT), XXXX,   OSL(FUNC), OSL(FUNC), XXXX,    OSM(MOD_LALT), OSM(MOD_LGUI), KC_MPRV,  KC_MNXT, OSM(MOD_LCTL),
        XXXX,          XXXX,    XXXX,    XXXX,          KC_TAB,        KC_SPC, KC_ESC,    KC_DEL,    KC_BSPC, KC_ENT,        XXXX,          XXXX,     XXXX,    XXXX
    ),
    [FUNC]             =        LAYOUT_blaxpy(
        UUUU,          KC_F1,   KC_F2,   KC_F3,         KC_F4,         KC_F5,  UUUU,      UUUU,      KC_F6,   KC_F7,         KC_F8,         KC_F9,    KC_F10,  UUUU,
        UUUU,          UUUU,    KC_7,    KC_8,          KC_9,          UUUU,   ____,      ____,      KC_PGUP, KC_HOME,       KC_UP,         KC_END,   KC_F11,  UUUU,
        ____,          KC_0,    KC_4,    KC_5,          KC_6,          UUUU,   ____,      ____,      KC_PGDN, KC_LEFT,       KC_DOWN,       KC_RGHT,  KC_F12,  UUUU,
        ____,          UUUU,    KC_1,    KC_2,          KC_3,          UUUU,   XXXX,      XXXX,      UUUU,    UUUU,          UUUU,          UUUU,     UUUU,    ____,
        ____,          UUUU,    UUUU,    ____,          ____,          XXXX,   ____,      ____,      XXXX,    ____,          ____,          RGB_RMOD, RGB_MOD, ____,
        XXXX,          XXXX,    XXXX,    XXXX,          ____,          ____,   ____,      ____,      ____,    ____,          XXXX,          XXXX,     XXXX,    XXXX
    ),
};

uint8_t get_effective_mods(void) {
    return get_mods() | get_oneshot_mods() | get_oneshot_locked_mods();
}

// https://docs.qmk.fm/#/feature_advanced_keycodes?id=checking-modifier-state
void rgb_matrix_mods(void) {
    uint8_t effective_mods = get_effective_mods();

    if (effective_mods & MOD_MASK_SHIFT) {
        rgb_matrix_set_color(RGB_LEFT_4_1, RGB_WHITE);
        rgb_matrix_set_color(RGB_RIGHT_4_7, RGB_WHITE);
    }

    if (effective_mods & MOD_BIT(KC_LCTL)) {
        rgb_matrix_set_color(RGB_LEFT_5_1, RGB_WHITE);
        rgb_matrix_set_color(RGB_RIGHT_5_7, RGB_WHITE);
    }

    if (effective_mods & MOD_BIT(KC_LGUI)) {
        rgb_matrix_set_color(RGB_LEFT_5_4, RGB_WHITE);
        rgb_matrix_set_color(RGB_RIGHT_5_4, RGB_WHITE);
    }

    if (effective_mods & MOD_BIT(KC_LALT)) {
        rgb_matrix_set_color(RGB_LEFT_5_5, RGB_WHITE);
        rgb_matrix_set_color(RGB_RIGHT_5_3, RGB_WHITE);
    }
}

// https://docs.qmk.fm/#/feature_layers?id=functions
void rgb_matrix_layers(void) {
    if (IS_LAYER_ON(FUNC)) {
        rgb_matrix_set_color(RGB_LEFT_RED, RGB_RED);
        rgb_matrix_set_color(RGB_RIGHT_RED, RGB_RED);
    }
}

// https://docs.qmk.fm/#/feature_rgb_matrix
bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }

    if (is_caps_word_on()) {
        rgb_matrix_set_color(RGB_LEFT_1_7, RGB_WHITE);
        rgb_matrix_set_color(RGB_RIGHT_1_1, RGB_WHITE);
    }

    rgb_matrix_mods();
    rgb_matrix_layers();

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CAPS:
            // Disable Shift + CapsLock key combo.
            if (record->event.pressed && get_effective_mods() & MOD_MASK_SHIFT) {
                return false;  // Disable further processing.
            }
            break;
    }
    return true;
}
