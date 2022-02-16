
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
MUSIC_ENABLE = no
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
# SPACE_CADET_ENABLE = no
# GRAVE_ESC_ENABLE = no
# MAGIC_ENABLE = no

MOUSEKEY_ENABLE = yes        # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
LTO_ENABLE = yes
RGBLIGHT_ENABLE = no      # Enable WS2812 RGB underlight.

OLED_ENABLE = yes
# OLED_DRIVER = SSD1306
COMBO_ENABLE = yes
LEADER_ENABLE = yes

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

# # If you want to change the display of OLED, you need to change here
# SRC +=  ./keymaps/teddy/lib/rgb_state_reader.c \
#         ./keymaps/teddy/lib/layer_state_reader.c \
# 		./keymaps/teddy/lib/logo_reader.c \
# 		# ./keymaps/teddy/lib/keylogger.c \
#         # ./keymaps/teddy/lib/mode_icon_reader.c \
#         # ./keymaps/teddy/lib/host_led_state_reader.c \
#         # ./keymaps/teddy/lib/timelogger.c \
