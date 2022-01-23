#include QMK_KEYBOARD_H
#include "version.h"

#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

extern rgb_config_t rgb_matrix_config;

enum layers {
    DEFAULT,
    MEDIA,
    MOUSE,
    SYMBOLS,
};

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT]        =                    LAYOUT_moonlander(
    KC_GRAVE,      KC_1,                KC_2,                KC_3,            KC_4,                KC_5,        KC_DELETE, KC_PSCREEN,         KC_6,            KC_7,                KC_8,          KC_9,                KC_0,                KC_RBRACKET,
    KC_TAB,        KC_Q,                KC_W,                KC_E,            KC_R,                KC_T,        KC_LEFT,   KC_UP,              KC_Y,            KC_U,                KC_I,          KC_O,                KC_P,                KC_LBRACKET,
    KC_BSPACE,     KC_A,                KC_S,                KC_D,            KC_F,                KC_G,        KC_RIGHT,  KC_DOWN,            KC_H,            KC_J,                KC_K,          KC_L,                KC_SCOLON,           KC_QUOTE,
    OSM(MOD_LSFT), KC_Z,                KC_X,                KC_C,            KC_V,                KC_B,        KC_N,      KC_M,               KC_COMMA,        KC_DOT,              KC_SLASH,      OSM(MOD_LSFT),
    KC_PAUSE,      KC_HOME,             OSM(MOD_LALT),       OSM(MOD_LGUI),   OSM(MOD_LCTL),       TT(MEDIA),   TT(MOUSE), OSM(MOD_LCTL),      OSM(MOD_LGUI),   OSM(MOD_LALT),       KC_END,        KC_SCROLLLOCK,
    KC_SPACE,      KC_ESCAPE,           OSL(SYMBOLS),        OSL(SYMBOLS),    KC_ENTER,            KC_SPACE
  ),
  [MEDIA]          =                    LAYOUT_moonlander(
    XXXXXXX,       XXXXXXX,             XXXXXXX,             XXXXXXX,         XXXXXXX,             XXXXXXX,     MU_TOG,    AU_TOG,             XXXXXXX,         XXXXXXX,             XXXXXXX,       XXXXXXX,             XXXXXXX,             XXXXXXX,
    _______,       XXXXXXX,             KC_MEDIA_PREV_TRACK, KC_UP,           KC_MEDIA_NEXT_TRACK, XXXXXXX,     RGB_SLD,   RGB_TOG,            XXXXXXX,         KC_MEDIA_NEXT_TRACK, KC_UP,         KC_MEDIA_PREV_TRACK, XXXXXXX,             XXXXXXX,
    _______,       KC_MEDIA_PLAY_PAUSE, KC_LEFT,             KC_DOWN,         KC_RIGHT,            XXXXXXX,     RGB_MOD,   TOGGLE_LAYER_COLOR, XXXXXXX,         KC_LEFT,             KC_DOWN,       KC_RIGHT,            KC_MEDIA_PLAY_PAUSE, XXXXXXX,
    _______,       KC_MEDIA_STOP,       KC_AUDIO_MUTE,       KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN,   XXXXXXX,     XXXXXXX,   KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP, KC_AUDIO_MUTE,       KC_MEDIA_STOP, _______,
    _______,       _______,             _______,             _______,         _______,             _______,     XXXXXXX,   _______,            _______,         _______,             _______,       _______,
    _______,       _______,             XXXXXXX,             XXXXXXX,         _______,             _______
  ),
  [MOUSE]          =                    LAYOUT_moonlander(
    XXXXXXX,       XXXXXXX,             XXXXXXX,             XXXXXXX,         XXXXXXX,             XXXXXXX,     _______,   _______,            XXXXXXX,         XXXXXXX,             XXXXXXX,       XXXXXXX,             XXXXXXX,             XXXXXXX,
    _______,       XXXXXXX,             KC_MS_BTN2,          KC_MS_UP,        KC_MS_BTN1,          KC_PC_PASTE, _______,   _______,            KC_PC_PASTE,     KC_MS_BTN1,          KC_MS_UP,      KC_MS_BTN2,          XXXXXXX,             XXXXXXX,
    _______,       KC_MS_BTN3,          KC_MS_LEFT,          KC_MS_DOWN,      KC_MS_RIGHT,         KC_PC_COPY,  _______,   _______,            KC_PC_COPY,      KC_MS_LEFT,          KC_MS_DOWN,    KC_MS_RIGHT,         KC_MS_BTN3,          XXXXXXX,
    _______,       KC_MS_WH_LEFT,       KC_MS_WH_RIGHT,      KC_MS_WH_UP,     KC_MS_WH_DOWN,       KC_PC_CUT,   KC_PC_CUT, KC_MS_WH_DOWN,      KC_MS_WH_UP,     KC_MS_WH_RIGHT,      KC_MS_WH_LEFT, _______,
    _______,       _______,             _______,             _______,         _______,             XXXXXXX,     _______,   _______,            _______,         _______,             _______,       _______,
    _______,       _______,             XXXXXXX,             XXXXXXX,         _______,             _______
  ),
  [SYMBOLS]        =                    LAYOUT_moonlander(
    XXXXXXX,       KC_F1,               KC_F2,               KC_F3,           KC_F4,               KC_F5,       KC_F11,    KC_F12,             KC_F6,           KC_F7,               KC_F8,         KC_F9,               KC_F10,              XXXXXXX,
    XXXXXXX,       KC_PLUS,             KC_ASTR,             KC_LCBR,         KC_RCBR,             KC_AT,       KC_HOME,   KC_PGUP,            KC_AMPR,         KC_7,                KC_8,          KC_9,                KC_CIRC,             XXXXXXX,
    KC_GRAVE,      KC_UNDS,             KC_MINUS,            KC_LPRN,         KC_RPRN,             KC_PERC,     KC_END,    KC_PGDOWN,          KC_EXLM,         KC_4,                KC_5,          KC_6,                KC_0,                KC_BSLASH,
    _______,       KC_HASH,             KC_EQUAL,            KC_LBRACKET,     KC_RBRACKET,         KC_TILD,     KC_PIPE,   KC_1,               KC_2,            KC_3,                KC_DLR,        _______,
    _______,       _______,             _______,             _______,         _______,             XXXXXXX,     XXXXXXX,   _______,            _______,         _______,             _______,       WEBUSB_PAIR,
    _______,       _______,             _______,             _______,         _______,             _______
  ),
};

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [MEDIA] = {{152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}},
    [MOUSE] = {{74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}},
    [SYMBOLS] = {{0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}},
};


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
    case RGB_SLD:
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    default:
        return true;
    }
}
