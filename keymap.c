#include QMK_KEYBOARD_H
#include "version.h"

#define CUSTOM_SAFE_RANGE ML_SAFE_RANGE
#include "lang_shift/include.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define SCREENSHOT_KEY LGUI(LSFT(KC_S))
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

#define MY_layout( \
    k00, k01, k02, k03, k04, k05, k06, \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35,      \
    k40, k41, k42, k43, k44,           \
    k53, \
    k50, k51, k52, \
    \
    k60, k61, k62, k63, k64, k65, k66, \
    k70, k71, k72, k73, k74, k75, k76, \
    k80, k81, k82, k83, k84, k85, k86, \
    k91, k92, k93, k94, k95, k96, \
    ka2, ka3, ka4, ka5, ka6, \
    kb3,\
    kb4, kb5, kb6 \
) \
LAYOUT_moonlander( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
)

enum Layers {
  L_EN = 0,
  L_EN_S,

  L_RU,
  L_RU_S,
  L_SYMBOLS,
  L_NUMBERS,
  L_GAMING,
};

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
};

enum tap_dance_codes {
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
};

#define LANG_TWO_LAYERS(\
  L_DEFAULT, L_SHIFT,\
  \
  /* Left hand */ \
       LU1, LU2, LU3, LU4, LU5, \
       LH1, LH2, LH3, LH4, LH5, \
  LD0, LD1, LD2, LD3, LD4, LD5, \
  /* Right hand */ \
  RU1, RU2, RU3, RU4, RU5, \
  RH1, RH2, RH3, RH4, RH5, RH6, \
  RD1, RD2, RD3, RD4, RD5, RD6, \
  \
  /* ---------------------------- Shift layer ---------------------------- */ \
  /* Left hand */ \
        SLU1, SLU2, SLU3, SLU4, SLU5, \
        SLH1, SLH2, SLH3, SLH4, SLH5, \
  SLD0, SLD1, SLD2, SLD3, SLD4, SLD5, \
  /* Right hand */ \
  SRU1, SRU2, SRU3, SRU4, SRU5, \
  SRH1, SRH2, SRH3, SRH4, SRH5, SRH6, \
  SRD1, SRD2, SRD3, SRD4, SRD5, SRD6 \
) \
  /*-------------------------------------------------------------------------*/ \
  [L_DEFAULT] = MY_layout( \
    /* LEFT HALF */ \
    EN_AT,  AG_EXCL, AG_PLUS, EN_CIRC, AG_SCLN, AG_DQUO, AG_SLSH, \
    AG_UNDS, LU1,     LU2,     LU3,     LU4,     LU5,     LGUI(KC_A), \
    KC_TAB, LH1,     LH2,     LH3,     LH4,     LH5,     TD(DANCE_1), \
    SFT_N_O,     LD1,     LD2,     LD3,     LD4,     LD5, \
    CTRL_0,  ALT_0, TG(L_GAMING), OSL(L_NUMBERS), OSL(L_SYMBOLS), \
    KC_TAB, /* LEFT RED THUMB KEY */ \
    SFT_N, KC_BSPACE, TD(DANCE_4), /* LEFT THUMB KEYS */ \
    \
    /* RIGHT HALF */ \
    AG_BSLS, AG_COLN, AG_EQL, AG_ASTR, AG_QUES, EN_TILD, EN_DLR, \
    EN_QUOT,    RU1,     RU2,     RU3,     RU4,     RU5,     AG_MINS, \
    AG_CMSP,    RH1,     RH2,     RH3,     RH4,     RH5,     RH6, \
             RD1,     RD2,     RD3,     RD4,     RD5,     RD6, \
                      LA_CHNG,  LA_CAPS, LA_CTSP, LA_SYNC, EN_GRV, \
                      KC_ESCAPE, /* RIGHT RED THUMB KEY */ \
                      KC_ENTER, AG_DOT, KC_SPC /* RIGHT THUMB KEYS */ \
  ), \
  \
  /*-------------------------------------------------------------------------*/ \
  [L_SHIFT] = MY_layout( \
    /* LEFT HALF */ \
    _______, _______, _______, _______, _______, _______, _______, \
    _______, SLU1,    SLU2,    SLU3,    SLU4,    SLU5,    _______, \
    _______, SLH1,    SLH2,    SLH3,    SLH4,    SLH5,    _______, \
    SLD0,    SLD1,    SLD2,    SLD3,    SLD4,    SLD5, \
    _______, _______, _______, _______, _______, \
    _______, /* LEFT RED THUMB KEY */ \
    _______, _______, _______, /* LEFT THUMB KEYS */ \
    \
    /* RIGHT HALF */ \
    _______, _______, AG_COLN, AG_COMM, _______, AG_SLSH, _______, \
    _______, SRU1,    SRU2,    SRU3,    SRU4,    SRU5,    _______, \
    _______, SRH1,    SRH2,    SRH3,    SRH4,    SRH5,    SRH6, \
             SRD1,    SRD2,    SRD3,    SRD4,    SRD5,    SRD6, \
                      _______, _______, _______, _______, _______, \
                      _______, /* RIGHT RED THUMB KEY */ \
                      _______, _______, _______ /* RIGHT THUMB KEYS */ \
  ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LANG_TWO_LAYERS(
    L_EN, L_EN_S,

    /* Left hand */
             EN_Q,    EN_W,    EN_E,    EN_R,   EN_T,
             EN_A,    EN_S,    EN_D,    EN_F,   EN_G,
    XXXXXXX, EN_Z,    EN_X,    EN_C,    EN_V,   EN_B,

    /* Right hand */
    EN_Y,    EN_U,    EN_I,    EN_O,    EN_P,
    EN_H,    EN_J,    EN_K,    EN_L,    XXXXXXX,    XXXXXXX,
    EN_N,    EN_M,    XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,

    /* ---------------------------- Shift layer ---------------------------- */
    /* Left hand */
             EN_S_Q,    EN_S_W,    EN_S_E,    EN_S_R,    EN_S_T,
             EN_S_A,    EN_S_S,    EN_S_D,    EN_S_F,    EN_S_G,
    _______, EN_S_Z,    EN_S_X,    EN_S_C,    EN_S_V,    EN_S_B,

    /* Right hand */
    EN_S_Y,    EN_S_U,    EN_S_I,    EN_S_O,  EN_S_P,
    EN_S_H,    EN_S_J,    EN_S_K,    EN_S_L,  _______, _______,
    EN_S_N,    EN_S_M,    _______,   _______, _______, _______
  )

    LANG_TWO_LAYERS(
    L_RU, L_RU_S,

    /* Left hand */
             RU_J,    RU_TS,   RU_U,    RU_K,   RU_JE,
             RU_F,    RU_Y,    RU_V,    RU_A,    RU_P,
    XXXXXXX, RU_JA,   RU_CH,   RU_S,    RU_M,    RU_I,

    /* Right hand */
    RU_N,   RU_G,    RU_SH,    RU_SC,    RU_Z,
    RU_R,   RU_O,    RU_L,     RU_D,     RU_ZH,   RU_E,
    RU_T,   RU_SF,   RU_B,     RU_JU,    RU_H,    _______,

    /* ---------------------------- Shift layer ---------------------------- */
    /* Left hand */
             RU_S_J,    RU_S_TS,   RU_S_U,    RU_S_K,   RU_S_JE,
             RU_S_F,    RU_S_Y,    RU_S_V,    RU_S_A,    RU_S_P,
    XXXXXXX, RU_S_JA,   RU_S_CH,   RU_S_S,    RU_S_M,    RU_S_I,

    /* Right hand */
    RU_S_N,   RU_S_G,    RU_S_SH,    RU_S_SC,    RU_S_Z,
    RU_S_R,   RU_S_O,    RU_S_L,     RU_S_D,     RU_S_ZH,   RU_S_E,
    RU_S_T,   RU_S_SF,   RU_S_B,     RU_S_JU,    RU_S_H,    _______
  )

  //---------------------------------------------------------------------------
  [L_SYMBOLS] = MY_layout(
    // LEFT HALF
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,
    _______, EN_HASH, AG_PERC, AG_LPRN,     AG_RPRN,     EN_PIPE, _______,
    _______, EN_LT,   EN_GT,   EN_LCBR,     EN_RCBR,     EN_AMPR, _______,
    _______, _______, _______, EN_LBRC,     EN_RBRC,     _______,
    _______, _______, _______, _______,     _______,
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, KC_F6,   KC_F7,    KC_F8,     KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______,  _______,   _______, _______, KC_F12,
    _______,  KC_LEFT,       KC_DOWN,       KC_UP,       KC_RIGHT, _______,  _______,
    LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RIGHT),  _______, _______,
    _______, _______,       _______,       _______,     _______,
    TG(L_SYMBOLS), // RIGHT RED THUMB KEY
    _______, _______, _______ // RIGHT THUMB KEYS
  ),

  [L_NUMBERS] = MY_layout(
    // LEFT HALF
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, SCREENSHOT_KEY, _______, _______, _______, _______,
    _______, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______,  _______, _______, _______, _______, _______,
    _______, _______,  AG_4,    AG_5,    AG_6,    _______, _______,
    _______, _______,  AG_0,    AG_1,    AG_2,    AG_3,    _______,
             _______,  AG_9,    AG_8,    AG_7,    _______, _______,
    _______,  _______,  _______,  _______,  _______,
    TG(L_NUMBERS), // RIGHT RED THUMB KEY
    _______, _______, _______ // RIGHT THUMB KEYS
  ),

  [L_GAMING] = MY_layout(
    // LEFT HALF
    AG_0,    KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,
    AG_1,    _______, _______, _______, _______, _______, EN_Y,
    _______, _______, _______, _______, _______, _______, EN_H,
    SFT_N,   _______, _______, _______, _______, _______,
    _______, _______, TG(L_GAMING), EN_U, EN_J,
    KC_ESCAPE, // LEFT RED THUMB KEY
    EN_I, KC_SPC, EN_K, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______,  _______, _______, _______, _______, _______,
    _______, _______,  AG_4,    AG_5,    AG_6,    _______, _______,
    _______, _______,  AG_0,    AG_1,    AG_2,    AG_3,    _______,
             _______,  AG_9,    AG_8,    AG_7,    _______, _______,
    _______,  _______,  _______,  _______,  _______,
    TG(L_NUMBERS), // RIGHT RED THUMB KEY
    _______, _______, _______ // RIGHT THUMB KEYS
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
//    debug_enable = false;
//    debug_matrix = true;
//    debug_keyboard = false;
   rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [L_EN] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },
    [L_EN_S] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [L_RU] = { {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255} },
    [L_RU_S] = { {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255} },

    [L_SYMBOLS] = { {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204}, {78,218,204} },

    [L_NUMBERS] = { {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233}, {21,236,233} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  switch (biton32(layer_state)) {
    case L_EN:
      set_layer_color(L_EN);
      break;
    case L_EN_S:
      set_layer_color(L_EN_S);
      break;
    case L_RU:
      set_layer_color(L_RU);
      break;
    case L_RU_S:
      set_layer_color(L_RU_S);
      break;
    case L_SYMBOLS:
      set_layer_color(L_SYMBOLS);
      break;
    case L_NUMBERS:
      set_layer_color(L_NUMBERS);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
   uprintf("KL: kc: 0x%04X, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);
#endif
    if (!lang_shift_process_record(keycode, record))
        return false;

    return true;
}


const uint16_t PROGMEM HARD_SIGN_COMBO[] = {RU_R, RU_T, COMBO_END};
const uint16_t PROGMEM HARD_SIGN_SHIFTED_COMBO[] = {RU_S_R, RU_S_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [0] = COMBO(HARD_SIGN_COMBO, RU_HD),
  [1] = COMBO(HARD_SIGN_SHIFTED_COMBO, RU_S_HD),
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[10];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_C));
        tap_code16(LGUI(KC_C));
        tap_code16(LGUI(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_C));
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_C)); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_V)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_C)); register_code16(LGUI(KC_C)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_C)); register_code16(LGUI(KC_C));
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_C)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_V)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_C)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_C)); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_LEFT); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(KC_LEFT); register_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT); register_code16(KC_LEFT);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
    }
    if(state->count > 3) {
        tap_code16(KC_RIGHT);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_RIGHT); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_RIGHT)); break;
        case DOUBLE_TAP: register_code16(KC_RIGHT); register_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT); register_code16(KC_RIGHT);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_RIGHT)); break;
        case DOUBLE_TAP: unregister_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LGUI);
        tap_code16(KC_LGUI);
        tap_code16(KC_LGUI);
    }
    if(state->count > 3) {
        tap_code16(KC_LGUI);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_LGUI); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LGUI); register_code16(KC_LGUI);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_LGUI); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LGUI); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_LPRN);
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_LPRN); break;
        case SINGLE_HOLD: register_code16(KC_RPRN); break;
        case DOUBLE_TAP: register_code16(KC_LPRN); register_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LPRN); register_code16(KC_LPRN);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_RPRN); break;
        case DOUBLE_TAP: unregister_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_LCBR);
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_LCBR); break;
        case SINGLE_HOLD: register_code16(KC_RCBR); break;
        case DOUBLE_TAP: register_code16(KC_LCBR); register_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LCBR); register_code16(KC_LCBR);
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_LCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_RCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSLASH);
        tap_code16(KC_BSLASH);
        tap_code16(KC_BSLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_BSLASH);
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_BSLASH); break;
        case SINGLE_HOLD: register_code16(KC_SLASH); break;
        case DOUBLE_TAP: register_code16(KC_BSLASH); register_code16(KC_BSLASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSLASH); register_code16(KC_BSLASH);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_BSLASH); break;
        case SINGLE_HOLD: unregister_code16(KC_SLASH); break;
        case DOUBLE_TAP: unregister_code16(KC_BSLASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSLASH); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case SINGLE_HOLD: register_code16(KC_PIPE); break;
        case DOUBLE_TAP: register_code16(KC_QUOTE); register_code16(KC_QUOTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case SINGLE_HOLD: unregister_code16(KC_PIPE); break;
        case DOUBLE_TAP: unregister_code16(KC_QUOTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state[8].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
};

void user_timer(void) {
  lang_shift_user_timer();
}

void matrix_scan_user(void) {
  user_timer();
}
