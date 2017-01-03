// modified following file.
// https://github.com/msc654/qmk_firmware/blob/master/keyboard%2Fergodox_ez%2Fkeymaps%2Fdefault%2Fkeymap.c

#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

// Layer
#define WINDOWS     0  // default layer for windows
#define MACOS       1  // default layer for macOS
#define FN          2  // functions
#define TENKEY      3  // ten key
#define MOUSE       4  // mouse mode
#define MOUSE       4  // mouse mode

// Aliases
#define JA_CLON KC_QUOT  // : and +
#define JA_AT   KC_LBRC  // @ and `
#define JA_HAT  KC_EQL   // ^ and ~
#define JA_ENUN KC_RO    // \ and _ (EN mark and UNder score)
#define JA_ENVL KC_JYEN  // \ and | (EN mark and Vertical Line)
#define JA_LBRC KC_RBRC  // [ and {
#define JA_RBRC KC_BSLS  // ] and }
#define CAPSLOCK LSFT(KC_CAPS)  //CapsLock

#define TGL_WIN TG(WINDOWS)  // Toggle Layer
#define TGL_MAC TG(MACOS)      // Toggle Layer


// Aliases for Windows
#define WIN_CUT LCTL(KC_X)     // Cut
#define WIN_COPY LCTL(KC_C)    // Copy
#define WIN_PASTE LCTL(KC_V)   // Paste
#define WIN_KANA KC_GRV

// Aliases for macOS
#define MAC_CUT LGUI(KC_X)     // Cut
#define MAC_COPY LGUI(KC_C)    // Copy
#define MAC_PASTE LGUI(KC_V)   // Paste
#define MAC_KANA  LCTL(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | LTKy |           |  ^~  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |LMouse|           |  [{  |   Y  |   U  |   I  |   O  |   P  |   `@   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;+  |   :*   |
 * |--------+------+------+------+------+------| LFn  |           |  ]}  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /  |   \_    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAlt | LGui | Left | Right| LMac |                                       |  ←   |   ↓  |   ↑  |  →   | Sft/\ |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Kana | cut  |       | CAPS | Kana   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | copy |       | Home |        |      |
 *                                 |Backsp|Delete|------|       |------| Enter  |Space |
 *                                 |ace   |      | paste|       | End  |        |      |
 *                                 `--------------------'       `----------------------'
 */
[WINDOWS] = KEYMAP(
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   MO(TENKEY),
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(MOUSE),
        KC_LCTL,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   MO(FN),
        KC_LALT,     M(1),      TGL_WIN,TGL_MAC, KC_LGUI,
                                               WIN_KANA,             KC_CUT,
                                                                    KC_COPY,
                                               KC_BSPC,KC_DELT,    KC_PASTE,
        // right hand
        KC_EQL,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,      KC_MINS,
        JA_LBRC,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,      KC_LBRC,
                    KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_QUOT,
        JA_RBRC,      KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,  KC_RO,
                            KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  SFT_T(KC_JYEN),
        CAPSLOCK,       WIN_KANA,
        KC_HOME,
        KC_END, KC_ENT, KC_SPC
    ),

/* Keymap 1: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | LTKy |           |  ^~  |   6  |   7  |   8  |   9  |   0  |   -=    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |LMouse|           |  [{  |   Y  |   U  |   I  |   O  |   P  |   `@   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Command |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;+  |   :*   |
 * |--------+------+------+------+------+------| LFn  |           |  ]}  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /  |   \_    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAlt | CTRL | Left | Right| LWin |                                       |  ←   |   ↓  |   ↑  |  →   | Sft/\  |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | kana | cut  |       | CAPS | Kana   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | copy |       | Home |        |      |
 *                                 |Backsp|Delete|------|       |------| Enter  |Space |
 *                                 |ace   |      | paste|       | End  |        |      |
 *                                 `--------------------'       `----------------------'
 */
[MACOS] = KEYMAP(
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   MO(TENKEY),
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(MOUSE),
        KC_LGUI,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   MO(FN),
        KC_LALT,     M(1),      TGL_WIN,TGL_MAC,   KC_LCTL,
                                               MAC_KANA,          KC_CUT,
                                                                  KC_COPY,
                                               KC_BSPC,KC_DELT,   KC_PASTE,
        // right hand
        KC_EQL,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,      KC_MINS,
        JA_LBRC,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,      KC_LBRC,
                    KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_QUOT,
        JA_RBRC,      KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,  KC_RO,
                            KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  SFT_T(KC_JYEN),
        CAPSLOCK,       MAC_KANA,
        KC_HOME,
        KC_END, KC_ENT, KC_SPC
    ),

/* Keymap 2: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |   |    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |  ↑  |      |   [{   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      | ←   |  ↓  |  →  |   }]   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | RESET|      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Fnctions
[FN] = KEYMAP(
       // left hand
       M(1),       KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       M(2),     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                            KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,
                                                   KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_F7,     KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  LSFT(KC_JYEN),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,  KC_TRNS, KC_RBRC,
                KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN,  KC_RIGHT, KC_BSLS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
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
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FN)                // FN1 - Momentary Layer 1 (functions)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{

    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            // if (record->event.pressed) {
            //     SEND_STRING(s.sysname);
            // }
            break;

        // check layer  
        case 1:
          // matrix_scan_user();
          // _delay_ms(3000);
          // ergodox_board_led_off();
          // ergodox_right_led_1_off();
          // ergodox_right_led_2_off();
          // ergodox_right_led_3_off();
          break;
        // led off
        case 2:
          // ergodox_board_led_off();
          // ergodox_right_led_1_off();
          // ergodox_right_led_2_off();
          // ergodox_right_led_3_off();
          break;

    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    ergodox_board_led_off();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    ergodox_board_led_off();    
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
            ergodox_right_led_1_on();
            break;
        case MACOS:
            //ergodox_right_led_2_on();
            break;
        case FN:
            ergodox_right_led_3_on();
            ergodox_right_led_1_on();
            break;
        case TENKEY:
            ergodox_right_led_3_on();
            ergodox_right_led_2_on();
            break;
        case MOUSE:
            ergodox_led_all_on();
            break;
        default:
            // none
            break;
    }

};
