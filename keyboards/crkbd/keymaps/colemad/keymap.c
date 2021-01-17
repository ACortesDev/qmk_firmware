#include QMK_KEYBOARD_H

#include "layers.h"
#include "keycodes.h"
#include "process_records.h"

#if defined(OLED_DRIVER_ENABLE)
    #include "oled.c"
#endif

/* Layer keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_kc(
    //,-----------------------------------------------------.       ,-----------------------------------------------------.
            TAB,       Q,       W,       F,       P,       G,               J,       L,       U,       Y,    SCLN,    BSLS,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
           BSPC,       A,       R,       S,       T,       D,               H,       N,       E,       I,       O,    QUOT,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
          T_SFT,       Z,       X,       C,       V,       B,               K,       M,    COMM,     DOT,    SLSH,     ESC,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
                                      LGUI,   T_SFT,   LOWER,           RAISE,    LCTL,    LALT
    //                            `-------------------------'       `--------------------------'
    ),

    [_LOWER] = LAYOUT_kc(
    //,-----------------------------------------------------.       ,-----------------------------------------------------.
        _______,       0,       1,       2,       3,    MINS,            PGUP,    HOME,      UP,     END,     ESC, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        _______,    SLSH,       4,       5,       6,    PLUS,            PGDN,    LEFT,    DOWN,    RGHT,     DEL, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        _______,    ASTR,       7,       8,       9,     EQL,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
                                   _______, _______, _______,         _______, _______, _______
    //                            `-------------------------'       `--------------------------'
    ),

    [_RAISE] = LAYOUT_kc(
    //,-----------------------------------------------------.       ,-----------------------------------------------------.
        _______,    EXLM,      AT,    HASH,     DLR,    PERC,            CIRC,    AMPR,    ASTR,    LPRN,    RPRN,     F11,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        _______,      F1,      F2,      F3,      F4,      F5,             GRV,    MINS,     EQL,    LBRC,    RBRC,     F12,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        _______,      F6,      F7,      F8,      F9,     F10,            TILD,    UNDS,    PLUS,    LCBR,    RCBR, _______,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
                                   _______, _______, _______,         _______, _______, _______
    //                            `-------------------------'       `--------------------------'
    ),

    [_ADJUST] = LAYOUT(
    //,-----------------------------------------------------.       ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
                                   XXXXXXX, XXXXXXX, _______,         _______, XXXXXXX, XXXXXXX
    //                            `-------------------------'       `--------------------------'
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

/*  Set the layer 0 as the default layer in
    the Microcontroller's EEPROM data storage. */
void matrix_init_user(void) {
    persistent_default_layer_set(1UL<<_COLEMAK);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void keyboard_post_init_user() {
    layer_state_set_user(layer_state);
}
