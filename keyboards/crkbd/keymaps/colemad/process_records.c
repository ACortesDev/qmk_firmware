#include "layers.h"
#include "keycodes.h"

#ifdef OLED_DRIVER_ENABLE
    __attribute__((weak))
    bool process_record_oled(uint16_t keycode, keyrecord_t *record) { return true; }
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* Macros */
    // switch (keycode) {
    //     case MACRO:
    //         if (record->event.pressed) {
    //             // Do whatever
    //         }
    //         return false;
    // }

    #if defined(OLED_DRIVER_ENABLE)
        return process_record_oled(keycode, record);
    #else
        return true;
    #endif
}
