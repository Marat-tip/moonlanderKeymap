/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 15

#define RGB_MATRIX_STARTUP_SPD 60

#define LANG_CHANGE_DEFAULT LANG_CHANGE_CTRL_SPACE
#define COMBO_COUNT 2
#define MOONLANDER_USER_LEDS
#define ONESHOT_TAP_TOGGLE 2
