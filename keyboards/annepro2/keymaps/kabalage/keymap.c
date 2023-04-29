 /* Copyright 2021 kabalage
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H

enum _layer {
  _BL, // Base layer
  _F1, // Function layer 1
  _F2, // Function layer 2
  _F3, // Function layer 3
  _F4  // Function layer 4
};

enum custom_keycodes {
  KC_EAC = SAFE_RANGE, // é
  KC_AAC, // á
  KC_UAC, // ú
  KC_ODI, // ö
  KC_UDI, // ü
  KC_OAC, // ó
  KC_IAC, // í
  KC_ODA, // ő
  KC_UDA  // ű
};

const uint16_t custom_keycodes_map[] = {
  KC_E, // KC_EAC
  KC_A, // KC_AAC
  KC_U, // KC_UAC
  KC_P, // KC_ODI
  KC_Y, // KC_UDI
  KC_O, // KC_OAC
  KC_I, // KC_IAC
  KC_O, // KC_ODA
  KC_U  // KC_UDA
};

#define ESC_F1  LT(_F1, KC_ESC)
// #define UP_SFT  RSFT_T(KC_UP)
// #define DWN_F2  LT(_F2, KC_DOWN)
// #define LFT_F2  LT(_F2, KC_LEFT)
// #define RGT_CTL RCTL_T(KC_RGHT)
#define F12_ALT RALT_T(KC_F12)
#define AP2_BT1 KC_AP2_BT1
#define AP2_BT2 KC_AP2_BT2
#define AP2_BT3 KC_AP2_BT3
#define AP2_BT4 KC_AP2_BT4
#define AP2_USB KC_AP2_USB

#define CTL_PGU RCTL(KC_PGUP)
#define CTL_PGD RCTL(KC_PGDN)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _WBL: Base Layer (Default Layer)
   * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐
   * │Esc│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│
   * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │ESC_F1│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │Shift   │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │Ctrl│GUI │Alt │                        │ _F2│ _F3│ _F4│Ctrl│
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   *
   * Tap:
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │ Esc  │   │   │   │   │   │   │   │   │   │   │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │        │   │   │   │   │   │   │   │   │   │   │          │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │    │    │    │                        │    │    │    │    │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  [_BL] = LAYOUT_60_ansi(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    ESC_F1,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,        KC_ENT,
    // ESC_F1,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,    KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,        KC_ENT,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             MO(_F2), MO(_F3), MO(_F4), KC_RCTL
  ),

  // [_BL] = LAYOUT_60_ansi(
  //   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
  //   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
  //   ESC_F1,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
  //   KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
  //   KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             MO(_F2), MO(_F3), MO(_F4), KC_RCTL
  // ),
  /* Keymap _F1: Function Layer 1
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │ Ö │ Ü │ Ó │  Del  │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │TG_F3│   │   │_F3│   │   │Psc│PgU│ ↑ │PgD│End│ Ő │ Ú │  Ű  │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │Ctl│Sft│Del│Bsp│   │Hom│ ← │ ↓ │ → │ É │ Á │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │        │   │   │   │   │   │Tab│Del│Bsp│ Ű │ Í │          │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │    │    │    │         Enter          │    │    │ App│    │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  [_F1] = LAYOUT_60_ansi(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_ODI, KC_UDI,  KC_OAC,  KC_DEL,
    TG(_F3), _______, _______, MO(_F3), _______, _______, KC_PSCR,  KC_PGUP, KC_UP,   KC_PGDN, KC_END, KC_ODA,  KC_UAC,  KC_UDA,
    _______, KC_LCTL, KC_LSFT, KC_DEL,  KC_BSPC, _______, KC_HOME,  KC_LEFT, KC_DOWN, KC_RGHT, KC_EAC, KC_AAC,           _______,
    _______,          _______, _______, _______, _______, _______,  KC_TAB,  KC_DEL,  KC_BSPC, KC_UDA, KC_IAC,           _______,
    _______, _______, _______,                            KC_ENT,                             _______, _______, KC_APP,  _______
  ),
  /* Keymap _F1: Function Layer 1
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │ Ö │ Ü │ Ó │  Del  │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │TG_F3│   │   │_F3│   │   │Psc│PgU│ ↑ │PgD│End│ Ő │ Ú │  Ű  │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │Alt│Ctl│Sft│   │   │Hom│ ← │ ↓ │ → │ É │ Á │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │        │   │   │   │   │   │Tab│Del│Bsp│ Ű │ Í │          │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │    │    │    │         Enter          │    │    │ App│    │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  // [_F1] = LAYOUT_60_ansi(
  //   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_ODI, KC_UDI,  KC_OAC,  KC_DEL,
  //   TG(_F3), _______, _______, MO(_F3), _______, _______, KC_PSCR,  KC_PGUP, KC_UP,   KC_PGDN, KC_END, KC_ODA,  KC_UAC,  KC_UDA,
  //   _______, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, KC_HOME,  KC_LEFT, KC_DOWN, KC_RGHT, KC_EAC, KC_AAC,           _______,
  //   _______,          _______, _______, _______, _______, _______,  KC_TAB,  KC_DEL,  KC_BSPC, KC_UDA, KC_IAC,           _______,
  //   _______, _______, _______,                            KC_ENT,                             _______, _______, KC_APP,  _______
  // ),

  /* Keymap _F2: Function Layer 2 (Easy one hand combos)
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │   │   │   │   │   │   │   │Prv│Nxt│Mut│Vo-│Vo+│PlayPau│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │   │   │   │   │   │   │   │Hom│PgU│ ↑ │PgD│   │ PSc │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │ Caps │   │   │   │   │   │   │   │End│ ← │ ↓ │ → │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │        │   │   │   │   │   │   │   │CUP│CDN│F12│          │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │    │    │    │                        │    │    │    │    │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  [_F2] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, _______, KC_PSCR,
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_END,  KC_LEFT, KC_DOWN, KC_RGHT,          _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, CTL_PGU, CTL_PGD,  KC_F12,          _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
  ),

  /* Keymap _F3: Function Layer 3
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│  Del  │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │TG_F3│   │Ac2│Ac1│Ac0│   │MB2│WhU│MsU│WhD│   │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │ Caps │   │MB2│MB3│MB1│   │MB1│MsL│MsD│MsR│MB3│   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │        │   │   │   │   │   │   │   │   │   │   │          │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │    │    │    │           Acl0         │    │    │ _F4│    │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  [_F3] = LAYOUT_60_ansi(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    TG(_F3), _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, KC_BTN2, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______, _______, _______,
    KC_CAPS, _______, KC_BTN2, KC_BTN3, KC_BTN1, _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN3, _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______,                            KC_ACL0,                            _______, _______, MO(_F4), _______
  ),

  /* Keymap _F4: Function Layer 4
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │USB│BT1│BT2│BT3│   │   │   │   │   │   │   │   │   │       │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │   │   │   │   │   │   │   │   │   │   │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │        │BTL│RBT│   │   │   │   │   │   │   │   │          │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │    │    │    │                        │    │    │    │    │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  [_F4] = LAYOUT_60_ansi(
    AP2_USB, AP2_BT1, AP2_BT2, AP2_BT3, AP2_BT4, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______,          QK_BOOT, QK_RBT,  _______, _______, _______, _______, _______, DT_DOWN, DT_UP,   DT_PRNT,          _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
  ),
  // KC_AP_RGB_MOD, KC_AP_RGB_TOG, KC_AP_RGB_VAD, KC_AP_RGB_VAI
};

uint8_t modState;

uint16_t get_custom_keycode_mapping(uint16_t keycode) {
  return custom_keycodes_map[keycode - SAFE_RANGE];
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case QK_BOOT:
    //   if (record->event.pressed) {
    //     // Flash LEDs to indicate bootloader mode is enabled.
    //     on_all_leds();
    //   }
    //   break;

    case KC_EAC ... KC_IAC: // é, á, ú, ö, ü, ó, í
      if (record->event.pressed) {
        register_code(KC_RALT);
        tap_code(get_custom_keycode_mapping(keycode));
        unregister_code(KC_RALT);
        return false;
      }
      break;
    case KC_ODA ... KC_UDA: // ő, ű
      if (record->event.pressed) {
        // register double acute
        modState = get_mods();
        clear_mods();
        register_code(KC_RALT);
        register_code(KC_RSFT);
        tap_code(KC_2);
        unregister_code(KC_RSFT);
        unregister_code(KC_RALT);
        set_mods(modState);

        tap_code(get_custom_keycode_mapping(keycode));
        return false;
      }
      break;
  }
  return true;
}

void keyboard_post_init_user(void) {
    ap2_led_enable();
    // ap2_led_set_profile(7);
    // ap2_led_set_all_color(0x00, 0x00, 0x00);
    // ap2_led_reset_foreground_color();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _F3:
      ap2_led_set_foreground_color(0xFF, 0xFF, 0xFF);
      break;
    case _F4:
      ap2_led_set_foreground_color(0xFF, 0x00, 0x00);
      break;
    default:
      ap2_led_set_foreground_color(0x00, 0x00, 0x00);
      break;
  }
  return state;
}

// bool led_update_user(led_t leds) {
//   if (leds.caps_lock) {
//     // Set the leds to orange
//     const ap2_led_t color = {.p.red = 0xff, .p.green = 0xff, .p.blue = 0x00, .p.alpha = 0xff};
//     ap2_led_mask_set_mono(color);
//   } else {
//     const ap2_led_t color = {.p.red = 0x00, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0x00};
//     ap2_led_mask_set_mono(color);
//   }

//   return true;
// }
