# KEMOVE_SNOWFOX
SRC = matrix.c \
	sled17341.c \
	snowfox_ble.c \
	snowfox_led.c \
	hardfault_handler.c

LAYOUTS +=

# MCU
MCU = cortex-m0
ARMV = 6
USE_FPU = no
MCU_FAMILY = LPC
MCU_SERIES = LPC11Uxx
MCU_LDSCRIPT = LPC11U35_401_KEMOVE
MCU_STARTUP = lpc11uxx

OPT_DEFS = -Wno-unused-function -fdump-rtl-dfinish -fstack-usage
#EXTRALDFLAGS = -Wl,--print-memory-usage

# Options

# Keys
CUSTOM_MATRIX = yes
NKRO_ENABLE = yes
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
KEY_LOCK_ENABLE = no

# Other featues
BOOTMAGIC_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
RAW_ENABLE = no
MIDI_ENABLE = no
VIRTSER_ENABLE = no
COMBO_ENABLE = no
