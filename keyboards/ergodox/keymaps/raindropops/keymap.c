#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "led.h"

// Layer
enum { 
  WINDOWS = 0, // for Windows(default layer)
  MACOS,       // for macOS
  FN,          // functions
  TENKEY,      // ten key
  MOUSE,       // mouse mode
  LEDOFF       // LED off  
};

// LED Brightness
#define MY_LED_BRIGHTNESS_LO 15
#define MY_LED_BRIGHTNESS_HI 50

// Aliases
#define JA_CLON KC_QUOT         // : and +
#define JA_AT   KC_LBRC         // @ and `
#define JA_HAT  KC_EQL          // ^ and ~
#define JA_ENUN KC_RO           // \ and _ (EN mark and UNder score)
#define JA_ENVL KC_JYEN         // \ and | (EN mark and Vertical Line)
#define JA_LBRC KC_RBRC         // [ and {
#define JA_RBRC KC_BSLS         // ] and }
#define CAPSLOCK LSFT(KC_CAPS)  // CapsLock

#define TGL_WIN TG(WINDOWS)     // Toggle Layer
#define TGL_MAC TG(MACOS)       // Toggle Layer
#define TGL_LED TG(LEDOFF)      // Toggle Layer

// for Windows
#define WIN_CUT LCTL(KC_X)     // Cut
#define WIN_CPY LCTL(KC_C)    // Copy
#define WIN_PST LCTL(KC_V)   // Paste
#define WIN_KANA KC_GRV

// for macOS
#define MAC_CUT LGUI(KC_X)     // Cut
#define MAC_CPY LGUI(KC_C)    // Copy
#define MAC_PST LGUI(KC_V)   // Paste
#define MAC_KANA  LCTL(KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Windows layer(Base Layer)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | Pause|           | PScr |   6  |   7  |   8  |   9  |   0  |   -=   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  \|  |           |  [{  |   Y  |   U  |   I  |   O  |   P  |   `@   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;+  |   :*   |
 * |--------+------+------+------+------+------|  ^~  |           |  ]}  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /  |   \_    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAlt |LEDOFF| LWIN | LMAC | LGui |                                       | Sft/ |      |      |      | Sft/\ |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Kana | cut  |       | CAPS | Kana   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | copy |       | Home |        |      |
 *                                 |Backsp|Delete|------|       |------| Enter  |Space |
 *                                 |ace   |      | paste|       | End  | LFn    |      |
 *                                 `--------------------'       `----------------------'
 */
[WINDOWS] = KEYMAP(
        // left hand
        KC_ESC,     KC_1,    KC_2,    KC_3,     KC_4,   KC_5, KC_PAUS,
        KC_TAB,     KC_Q,    KC_W,    KC_E,     KC_R,   KC_T, JA_ENVL,
        KC_LCTL,    KC_A,    KC_S,    KC_D,     KC_F,   KC_G,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,  JA_HAT,
        KC_LALT, TGL_LED, TGL_WIN, TGL_MAC,  KC_LGUI,
                                            WIN_KANA,         WIN_CUT,
                                                              WIN_CPY,
                                             KC_BSPC,KC_DELT, WIN_PST,
        // right hand
        KC_PSCR,    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,      KC_MINS,
        JA_LBRC,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,      KC_LBRC,
                   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_QUOT,
        JA_RBRC,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RO,
                           SFT_T(KC_SLSH), KC_NO, KC_NO, KC_NO,  SFT_T(KC_JYEN),
        KC_CAPS,   WIN_KANA,
        KC_HOME,
        KC_END, LT(FN, KC_ENT), KC_SPC
    ),

/* Keymap 1: macOS Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | Pause|           | PScr |   6  |   7  |   8  |   9  |   0  |   -=   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  ^~  |           |  [{  |   Y  |   U  |   I  |   O  |   P  |   `@   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Command |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;+  |   :*   |
 * |--------+------+------+------+------+------|  ^~  |           |  ]}  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /  |   \_    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAlt |LEDOFF| LWIN | LMAC | LCtrl|                                       | Sft/ |      |      |      | Sft/\ |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | kana | cut  |       | CAPS | Kana   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | copy |       | Home |        |      |
 *                                 |Backsp|Delete|------|       |------| Enter  |Space |
 *                                 |ace   |      | paste|       | End  | LFn   |      |
 *                                 `--------------------'       `----------------------'
 */
[MACOS] = KEYMAP(
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_PAUS,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   JA_ENVL,
        KC_LGUI,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   JA_HAT,
        KC_LALT,     TGL_LED,      TGL_WIN,TGL_MAC,   KC_LCTL,
                                               MAC_KANA,          MAC_CUT,
                                                                  MAC_CPY,
                                               KC_BSPC,KC_DELT,   MAC_PST,
        // right hand 
        KC_PSCR,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,      KC_MINS,
        JA_LBRC,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,      KC_LBRC,
                    KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_QUOT,
        JA_RBRC,      KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,  KC_RO,
                            SFT_T(KC_SLSH), KC_NO, KC_NO, KC_NO,  SFT_T(KC_JYEN),
        KC_CAPS,       MAC_KANA,
        KC_HOME,
        KC_END, LT(FN, KC_ENT), KC_SPC
    ),

/* Keymap 2: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |   |    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |TMouse|           |      |      |  ↑   |      |      |      |   [{   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  ←   |  ↓   |  →   |      |      |   }]   |
 * |--------+------+------+------+------+------| TTKy |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RESET |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Functions
[FN] = KEYMAP(
       // left hand
       KC_TRNS,       KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(MOUSE),
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(TENKEY),
         RESET,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                            KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,
                                                   KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_F7,     KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  LSFT(KC_JYEN),
       KC_TRNS, KC_TRNS, KC_UP,    KC_TRNS, KC_TRNS, KC_TRNS, KC_RBRC,
                KC_LEFT, KC_DOWN,  KC_RIGHT, KC_TRNS, KC_TRNS, KC_BSLS,
       KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, 
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Keymap 3: Ten key Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  7   |   8  |   9  |   0  |   .  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  4   |   5  |   6  |   +  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  1   |   2  |   3  |   -  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// TEN KEY
[TENKEY] = KEYMAP(
       // left hand
       KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS,
       KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS,
       KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
       KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS,
       KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
                                                     KC_TRNS,KC_TRNS,
                                                             KC_TRNS,
                                             KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_7,   KC_8,    KC_9,    KC_0,    KC_DOT, KC_TRNS,
                KC_4,   KC_5,    KC_6,    KC_PLUS, KC_ASTR,  KC_TRNS,
       KC_TRNS, KC_1,   KC_2,    KC_3,    KC_MINS, KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 3: Mouse Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | M-Up |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           | LWin |------+------+------+------+------+--------|
 * |        |  M-L | M-Dn | M-R  |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | LMAC |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | RESET|      |      | WH-L | WH-R |                                       | Sp+2 | Sp+1 | Sp+0 |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | M2   |MClick|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | PgUp |      |      |
 *                                 |      |      |------|       |------|RClick|LClick|
 *                                 |      |      |      |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Mouse
[MOUSE] = KEYMAP(
       // left hand
       KC_TRNS,       KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS,     KC_TRNS,    KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_MS_L,    KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       RESET,       KC_TRNS,    KC_TRNS, KC_WH_L, KC_WH_R,
                                                            KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,
                                                   KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_F7,           KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       TGL_WIN,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       TGL_MAC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                      KC_ACL2, KC_ACL1, KC_ACL0, KC_TRNS,  KC_TRNS,
       KC_BTN4, KC_BTN3,
       KC_PGUP,
       KC_PGDN, KC_BTN1, KC_BTN2
    ),

/* Keymap: Lock and LED off Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LEDOFF] = KEYMAP(
       // left hand
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
       KC_TRNS,     KC_TRNS,      KC_NO,   KC_NO, KC_TRNS,
                                                            KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,
                                                   KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, 
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FN)                // FN1 - Momentary Layer 1 (functions)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{

    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            break;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();

    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer) {
        // TODO: Make this relevant to the ErgoDox EZ.
        case WINDOWS:
            ergodox_led_all_set(MY_LED_BRIGHTNESS_LO);
            ergodox_right_led_2_on();
            break;

        case MACOS:
            ergodox_led_all_set(MY_LED_BRIGHTNESS_LO);
            ergodox_right_led_3_on();
            break;

        case LEDOFF:
        default:
            break;
    }

    switch (layer) {
        case FN:
            ergodox_led_all_set(MY_LED_BRIGHTNESS_HI);
            ergodox_right_led_2_on();
            break;

        case TENKEY:
            ergodox_led_all_set(MY_LED_BRIGHTNESS_HI);
            ergodox_right_led_3_on();
            break;

        case MOUSE:
            ergodox_led_all_set(MY_LED_BRIGHTNESS_HI);
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;

        default:
          break;
    }

    // caps lock
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
      ergodox_right_led_1_on();
    }
};