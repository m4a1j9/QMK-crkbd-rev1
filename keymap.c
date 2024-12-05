#include QMK_KEYBOARD_H
#include <stdio.h>

enum LAYERS {
    BASE,
    MEDIA,
    NAV,
    SYMBOLS,
    NUMS,
    FUN
};

enum KEYS {
    MEDIA_ESC = LT(MEDIA,KC_ESC),
    NAV_TAB = LT(NAV,KC_TAB),
    SYM_ENT = LT(SYMBOLS,KC_ENT),
    NUM_BSPC = LT(NUMS,KC_BSPC),
    FUN_DEL = LT(FUN,KC_DEL)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MEDIA_ESC:
        case NAV_TAB:
        case SYM_ENT:
        case NUM_BSPC:
        case FUN_DEL:
            return 100;
        default:
            return TAPPING_TERM;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MEDIA_ESC:
        case NAV_TAB:
        case SYM_ENT:
        case NUM_BSPC:
        case FUN_DEL:
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,            KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,                KC_Y,            KC_U,            KC_I,            KC_O,            KC_P, KC_LEFT_BRACKET,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
                KC_Q,    LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),            KC_G,                KC_H,    LSFT_T(KC_J),    LCTL_T(KC_K),    LALT_T(KC_L), LGUI_T(KC_SCLN),            KC_P,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,            KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,                KC_N,            KC_M,         KC_COMM,          KC_DOT,         KC_SLSH,KC_RIGHT_BRACKET,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
                                                              MEDIA_ESC,          KC_SPC,         NAV_TAB,             SYM_ENT,        NUM_BSPC,         FUN_DEL
                                                    //|----------------+----------------+----------------|   |----------------+----------------+----------------|
  ),

  [MEDIA] = LAYOUT_split_3x6_3(
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             QK_BOOT,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,             XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,         KC_LGUI,         KC_LALT,         KC_LCTL,         KC_LSFT,         XXXXXXX,             XXXXXXX,         KC_MPRV,         KC_VOLD,         KC_VOLU,         KC_MNXT,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,             XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
                                                                _______,         XXXXXXX,         XXXXXXX,             KC_MSTP,         KC_MPLY,         XXXXXXX
                                                    //|----------------+----------------+----------------|   |----------------+----------------+----------------|
  ),

  [NAV] = LAYOUT_split_3x6_3(
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,       KC_MS_WH_LEFT,   KC_MS_WH_DOWN,     KC_MS_WH_UP,  KC_MS_WH_RIGHT,         XXXXXXX,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,         KC_LGUI,         KC_LALT,         KC_LCTL,         KC_LSFT,         XXXXXXX,             KC_LEFT,         KC_DOWN,           KC_UP,        KC_RIGHT,         XXXXXXX,    KC_CAPS_LOCK,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,             KC_HOME,    KC_PAGE_DOWN,      KC_PAGE_UP,          KC_END,         XXXXXXX,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
                                                                XXXXXXX,         XXXXXXX,         _______,            KC_ENTER,         KC_BSPC,          KC_DEL
                                                    //|----------------+----------------+----------------|   |----------------+----------------+----------------|
  ),

  [SYMBOLS] = LAYOUT_split_3x6_3(
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,         KC_HASH,        KC_SLASH,    KC_BACKSLASH,         XXXXXXX,      KC_PERCENT,             XXXXXXX,         XXXXXXX,   KC_LEFT_PAREN,  KC_RIGHT_PAREN,         XXXXXXX,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
            KC_GRAVE,    KC_AMPERSAND,         KC_PIPE, KC_LEFT_BRACKET,KC_RIGHT_BRACKET,        KC_EQUAL,             XXXXXXX,         KC_LSFT,         KC_LCTL,         KC_LALT,         KC_LGUI,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,       KC_DOLLAR,      KC_EXCLAIM,KC_LEFT_ANGLE_BRACKET,KC_RIGHT_ANGLE_BRACKET,XXXXXXX,           XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
                                                          KC_LEFT_PAREN,  KC_RIGHT_PAREN,        KC_QUOTE,             _______,         XXXXXXX,         XXXXXXX
                                                    //|----------------+----------------+----------------|   |----------------+----------------+----------------|
  ),

  [NUMS] = LAYOUT_split_3x6_3(
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,         XXXXXXX,            KC_7,            KC_8,            KC_9,     KC_NUM_LOCK,             XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,         XXXXXXX,            KC_4,            KC_5,            KC_6,        KC_EQUAL,             XXXXXXX,         KC_LSFT,         KC_LCTL,         KC_LALT,         KC_LGUI,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,         XXXXXXX,            KC_1,            KC_2,            KC_3,    KC_BACKSLASH,             XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
                                                                 KC_DOT,            KC_0,        KC_MINUS,             XXXXXXX,         _______,         XXXXXXX
                                                    //|----------------+----------------+----------------|   |----------------+----------------+----------------|
  ),

  [FUN] = LAYOUT_split_3x6_3(
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,          KC_F12,           KC_F7,           KC_F8,           KC_F9, KC_PRINT_SCREEN,             XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,          KC_F11,           KC_F4,           KC_F5,           KC_F6,         XXXXXXX,             XXXXXXX,         KC_LSFT,         KC_LCTL,         KC_LALT,         KC_LGUI,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
             XXXXXXX,          KC_F10,           KC_F1,           KC_F2,           KC_F3,         XXXXXXX,             XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,
  //|---------------+----------------+----------------+----------------+----------------+----------------|   |----------------+----------------+----------------+----------------+----------------+----------------|
                                                                XXXXXXX,         XXXXXXX,         XXXXXXX,             XXXXXXX,         XXXXXXX,         _______
                                                    //|----------------+----------------+----------------|   |----------------+----------------+----------------|
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
