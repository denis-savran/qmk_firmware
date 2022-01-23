#include QMK_KEYBOARD_H
#include "version.h"

extern rgb_config_t rgb_matrix_config;

enum layers {
    DEFAULT,
    RUSSIAN,
    MEDIA,
    MOUSE,
    SYMBOLS,
};

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
};

// https://docs.qmk.fm/#/feature_tap_dance
// Tap Dance declarations.
enum {
    TD_PAUSE_SCROLLLOCK,
};

// Tap Dance definitions.
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PAUSE_SCROLLLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_PAUSE, KC_SCROLLLOCK),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT] = LAYOUT_moonlander(
    KC_GRAVE,                KC_1,      KC_2,              KC_3,              KC_4,              KC_5,                  KC_MINUS,              KC_EQUAL,          KC_6,                  KC_7,                KC_8,           KC_9,           KC_0,      KC_PSCREEN,
    _______,                 KC_Q,      KC_W,              KC_E,              KC_R,              KC_T,                  KC_HOME,               KC_PGUP,           KC_Y,                  KC_U,                KC_I,           KC_O,           KC_P,      KC_LBRACKET,
    TO(RUSSIAN),             KC_A,      LT(MEDIA,KC_S),    LT(MOUSE,KC_D),    LT(SYMBOLS,KC_F),  KC_G,                  KC_END,                KC_PGDOWN,         KC_H,                  LT(SYMBOLS,KC_J),    LT(MOUSE,KC_K), LT(MEDIA,KC_L), KC_SCOLON, KC_QUOTE,
    _______,                 KC_Z,      MT(MOD_LGUI,KC_X), MT(MOD_LALT,KC_C), MT(MOD_LCTL,KC_V), KC_B,                  KC_N,                  MT(MOD_RCTL,KC_M), MT(MOD_RALT,KC_COMMA), MT(MOD_RGUI,KC_DOT), KC_SLASH,       KC_RBRACKET,
    TD(TD_PAUSE_SCROLLLOCK), TG(MEDIA), TG(MOUSE),         KC_LEFT,           KC_RIGHT,          MT(MOD_MEH,KC_ESCAPE), MT(MOD_MEH,KC_ESCAPE), KC_DOWN,           KC_UP,                 _______,             WEBUSB_PAIR,    _______,
    MT(MOD_LSFT,KC_SPACE),   KC_BSPACE, KC_DELETE,         KC_BSLASH,         KC_TAB,            MT(MOD_RSFT,KC_ENTER)
  ),

  [RUSSIAN] = LAYOUT_moonlander(
    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TO(DEFAULT), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,     _______, _______, _______, _______, _______
  ),

  [MEDIA] = LAYOUT_moonlander(
    XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX,       XXXXXXX,             XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, XXXXXXX, KC_MEDIA_PREV_TRACK, KC_UP,         KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE, _______, _______, KC_COMMA, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_LEFT,             KC_DOWN,       KC_RIGHT,            KC_MEDIA_STOP,       _______, _______, KC_DOT,   KC_4,    KC_5,    KC_6,    KC_0,    XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,             KC_AUDIO_MUTE, XXXXXXX,             XXXXXXX,             XXXXXXX, KC_7,    KC_8,     KC_9,    XXXXXXX, XXXXXXX,
    _______, _______, XXXXXXX,             _______,       _______,             RGB_MOD,             RGB_TOG, _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, TOGGLE_LAYER_COLOR,  RGB_SLD,       _______,             _______
  ),

  [MOUSE] = LAYOUT_moonlander(
    XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,    XXXXXXX,        XXXXXXX,       XXXXXXX, XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,     XXXXXXX, _______,
    XXXXXXX, XXXXXXX, KC_MS_BTN2,    KC_MS_UP,   KC_MS_BTN1,     KC_MS_WH_UP,   _______, _______,       KC_MS_WH_UP,   KC_MS_BTN1,     KC_MS_UP,   KC_MS_BTN2,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_MS_LEFT,    KC_MS_DOWN, KC_MS_RIGHT,    KC_MS_WH_DOWN, _______, _______,       KC_MS_WH_DOWN, KC_MS_LEFT,     KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_MS_WH_LEFT, KC_MS_BTN3, KC_MS_WH_RIGHT, XXXXXXX,       XXXXXXX, KC_MS_WH_LEFT, KC_MS_BTN3,    KC_MS_WH_RIGHT, XXXXXXX,    XXXXXXX,
    _______, XXXXXXX, _______,       _______,    _______,        _______,       _______, _______,       _______,       XXXXXXX,        XXXXXXX,    XXXXXXX,
    _______, _______, _______,       _______,    _______,        _______
  ),

  [SYMBOLS] = LAYOUT_moonlander(
    XXXXXXX, KC_F1,    KC_F2,   KC_F3,       KC_F4,       KC_F5,    KC_F11,  KC_F12,    KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,  _______,
    XXXXXXX, KC_EXLM,  KC_AT, KC_LCBR,     KC_RCBR,     KC_PERC,    _______, _______,   KC_CIRC, KC_AMPR, KC_ASTR,  KC_COLN, KC_DQUO, XXXXXXX,
    XXXXXXX, KC_PLUS, KC_MINUS, KC_LPRN,     KC_RPRN,     KC_HASH,  _______, _______,   KC_DLR, KC_UNDS, KC_EQUAL, KC_SCOLON, KC_QUOTE, XXXXXXX,
    XXXXXXX, KC_LABK,  KC_RABK,  KC_LBRACKET, KC_RBRACKET, KC_GRAVE, KC_TILD, KC_QUES,  KC_COMMA, KC_DOT,  KC_SLASH,  XXXXXXX,
    _______, XXXXXXX,  XXXXXXX, _______,     _______,     _______,  _______, _______,   _______, XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______, _______,  _______, _______,     _______,     _______
  ),
};

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [RUSSIAN] = {{0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}},

    [MEDIA] = {{152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}},

    [MOUSE] = {{74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}},

    [SYMBOLS] = {{0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}},
};

static bool is_locale_toggled = false;


void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}


void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };

        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB rgb = hsv_to_rgb(hsv);
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}


void rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return;
    }

    int layer = biton32(layer_state);

    switch (layer) {
        case RUSSIAN:
        case MEDIA:
        case MOUSE:
        case SYMBOLS:
            set_layer_color(layer);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
                rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TO(DEFAULT):
        case TO(RUSSIAN):
            // Key press event.
            if (record->event.pressed) {
                tap_code(KC_CAPSLOCK);
            }
            return true;
        case LT(SYMBOLS,KC_F):
        case LT(SYMBOLS,KC_J):
        case LT(MEDIA,KC_S):
        case LT(MEDIA,KC_L):
            // Intercept hold events.
            if (!record->tap.count) {
                // Key press event on Russian layer.
                if (IS_LAYER_ON(RUSSIAN) && record->event.pressed) {
                    tap_code(KC_CAPSLOCK);
                    is_locale_toggled = true;
                // Key release event after a locale toggle.
                } else if (is_locale_toggled && !record->event.pressed) {
                    tap_code(KC_CAPSLOCK);
                    is_locale_toggled = false;
                }
            }
            return true;
        case TG(MEDIA):
            if (record->event.pressed) {
                // Key press event on Russian layer.
                if (IS_LAYER_ON(RUSSIAN)) {
                    tap_code(KC_CAPSLOCK);
                    is_locale_toggled = true;
                // Key press event after a locale toggle.
                } else if (is_locale_toggled) {
                    tap_code(KC_CAPSLOCK);
                    is_locale_toggled = false;
                }
            }
            return true;
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        default:
            return true;
    }
}
