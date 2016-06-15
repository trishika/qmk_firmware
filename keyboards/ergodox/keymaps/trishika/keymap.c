#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"
#include "mousekey.h"

#define BASE 0 // default layer
#define ALT  1 // alt layer

#define Caps 10 // left caps-shift key

#define MUL   20 // mouse up left
#define MUR   21 // mouse up right
#define MDL   22 // mouse down left
#define MDR   23 // mouse down right

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.         ,--------------------------------------------------.
 * |   `~   |  1!  |  2@  |  3#  |  4$  |  5%  |  -_  |         |  +=  |  6^  |  7&  |  8*  |  9(  |  0)  | Vol Up |
 * |--------+------+------+------+------+-------------|         |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  {   |         |   }  |   Y  |   U  |   I  |   O  |   P  |Vol Down|
 * |--------+------+------+------+------+------|  [   |         |   ]  |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|         |------|   H  |   J  |   K  |   L  |  :;  |  '"    |
 * |--------+------+------+------+------+------| Del  |         | BkSp |------+------+------+------+------+--------|
 * | M(Caps)|Z/Alt |   X  |   C  |   V  |   B  |      |         |      |   N  |   M  |   ,  |   .  |  /?  |  |\    |
 * `--------+------+------+------+------+-------------'         `-------------+------+------+------+------+--------'
 *   |LCtrl | COPY | PASTE| Super| LAlt |                                     | Left |  Up  | Right| Down | RAlt |
 *   `----------------------------------'                                     `----------------------------------'
 *                                        ,-------------.     ,-------------.
 *                                        | Esc  | Play |     | Prev | Next |
 *                                 ,------|------|------|     |------+------+------.
 *                                 |      |      | Home |     | PgUp |      |      |
 *                                 | Space| Super|------|     |------| ~L1  |Enter |
 *                                 |      |      | End  |     | PgDn |      |      |
 *                                 `--------------------'     `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,   KC_1,       KC_2,      KC_3,    KC_4,    KC_5,     KC_MINS,
        KC_TAB,   KC_Q,       KC_W,      KC_E,    KC_R,    KC_T,     KC_LBRC,
        KC_ESC,   KC_A,       KC_S,      KC_D,    KC_F,    KC_G,
        KC_LSFT,  ALT_T(KC_Z),KC_X,      KC_C,    KC_V,    KC_B,     KC_DELT,
        KC_LCTRL, LCTL(KC_INSERT),LSFT(KC_INSERT),KC_LGUI, KC_LALT,
                                                            KC_ESC,  KC_MPLY,
                                                                     KC_HOME,
                                                     KC_SPC,KC_LGUI, KC_END,
        // right hand
        KC_EQL,   KC_6,       KC_7,      KC_8,    KC_9,    KC_0,      KC_VOLU,
        KC_RBRC,  KC_Y,       KC_U,      KC_I,    KC_O,    KC_P,      KC_VOLD,
                  KC_H,       KC_J,      KC_K,    KC_L,    KC_SCLN,   KC_QUOT,
        KC_BSPC,  KC_N,       KC_M,      KC_COMM, KC_DOT,  KC_SLSH,   KC_BSLS,
                              KC_LEFT,   KC_UP,   KC_DOWN, KC_RGHT,   KC_RALT,
        KC_MPRV,   KC_MNXT,
        KC_PGUP,
        KC_PGDN,  KC_FN1, KC_ENT
    ),
/* Keymap 1: Alt Layer
 *
 * ,--------------------------------------------------.         ,--------------------------------------------------.
 * | TEENSY |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |         |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Mute   |
 * |--------+------+------+------+------+-------------|         |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |Scroll|         |      |      |      |      |      |      | Mute   |
 * |--------+------+------+------+------+------|  Up  |         |      |------+------+------+------+------+--------|
 * |        |      |      | MsU  |      |      |------|         |------|      |      |      |      |      |PrintScr|
 * |--------+------+------+------+------+------|Scroll|         |      |------+------+------+------+------+--------|
 * |        |      | MsL  | MsD  | MsR  |      | Down |         |      | LClk | MClk | RClk |      |      | Sleep  |
 * `--------+------+------+------+------+-------------'         `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                     |      |      |      |      |      |
 *   `----------------------------------'                                     `----------------------------------'
 *                                        ,-------------.     ,-------------.
 *                                        |      |      |     |      |      |
 *                                 ,------|------|------|     |------+------+------.
 *                                 |      |      |      |     |      |      |      |
 *                                 |      |      |------|     |------|      |      |
 *                                 |      |      |      |     |      |      |      |
 *                                 `--------------------'     `--------------------'
 */
// ALT
[ALT] = KEYMAP(
       // left hand
       RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_WH_D,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MUTE,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR,
       KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS, KC_SLEP,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    )
};


const uint16_t PROGMEM fn_actions[] = {
    [1]    = ACTION_LAYER_TAP_TOGGLE(ALT),  // FN1 - Momentary Layer 1
    [Caps] = ACTION_MACRO_TAP(Caps)
};

uint16_t caps_shift = 0;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        // Shift/Caps
        case Caps:
        if (record->event.pressed && !record->tap.count) {
            if(++caps_shift > 2) caps_shift = 2;
            if(caps_shift == 2)  {
                register_code(KC_CAPS);
                unregister_code(KC_CAPS);
            } else if(caps_shift == 1) {
                register_code(KC_LSFT);
            }
        } else {
            if(--caps_shift < 0) caps_shift = 0;
            if(caps_shift == 0) unregister_code(KC_LSFT);
        }
        break;

        default:
        // none
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
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
