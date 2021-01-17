MOUSEKEY_ENABLE = no
OLED_DRIVER_ENABLE = yes 
RGB_MATRIX_ENABLE = yes
TAP_DANCE_ENABLE = yes


# Link Time Optimization (Reduces compiled size)
LTO_ENABLE = yes

SRC += ./process_records.c

ifeq ($(TAP_DANCE_ENABLE),yes)
	SRC += ./tap_dances.c
endif

ifeq ($(OLED_DRIVER_ENABLE),yes)
	SRC += ./oled.c
endif
