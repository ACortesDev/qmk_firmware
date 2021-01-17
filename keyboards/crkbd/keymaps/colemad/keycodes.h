#pragma once

#include QMK_KEYBOARD_H
#include "layers.h"

/* NOTE: All keycodes start with "KC_" so LAYOUT_kc()
        function can be used when defining the layer keymaps. */
#define KC________ KC_TRNS
#define KC_XXXXXXX KC_NO

/* Tap-Hold keycodes */
#define KC_LOWER LT(_LOWER, KC_SPC) /* Tap for Space, Hold for LOWER layer */
#define KC_RAISE LT(_RAISE, KC_ENT) /* Tap for Enter, Hold for RAISE layer */

/* Tap Dance keycodes */
#if defined(TAP_DANCE_ENABLE)
    #include "tap_dances.h"
    #define KC_T_SFT T_SFT /* Single tap for Shift, Double tap for CAPS Lock */
#else
    #define KC_T_SFT KC_LSFT
#endif
