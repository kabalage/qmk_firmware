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

// Layer shorthand
enum _layer {
  _BL,
  _WL,
  _UL, // Unicode Map
  _FL,
  _SL
};

// Defines the Enumeration for Unicode Map
//
// éÉáÁőŐúÚűŰöÜüÜóÓíÍ€
//
// BASE(AC|DC|DI)(S|C)
//   AC - acute (ó)
//   DC - double acute (ő)
//   DI - diaeresis (ö)
//   S  - small (o)
//   C  - capital (O)
enum unicode_names {
  EACS,
  EACC,
  AACS,
  AACC,
  ODCS,
  ODCC,
  UACS,
  UACC,
  UDCS,
  UDCC,
  ODIS,
  ODIC,
  UDIS,
  UDIC,
  OACS,
  OACC,
  IACS,
  IACC,
  EURO
};

const uint32_t PROGMEM unicode_map[] = {
  [EACS] = 0x00e9, // é
  [EACC] = 0x00c9, // É
  [AACS] = 0x00e1, // á
  [AACC] = 0x00c1, // Á
  [ODCS] = 0x0151, // ő
  [ODCC] = 0x0150, // Ő
  [UACS] = 0x00fa, // ú
  [UACC] = 0x00da, // Ú
  [UDCS] = 0x0171, // ű
  [UDCC] = 0x0170, // Ű
  [ODIS] = 0x00f6, // ö
  [ODIC] = 0x00d6, // Ö
  [UDIS] = 0x00fc, // ü
  [UDIC] = 0x00dc, // Ü
  [OACS] = 0x00f3, // ó
  [OACC] = 0x00d3, // Ó
  [IACS] = 0x00ed, // í
  [IACC] = 0x00cd, // Í
  [EURO] = 0x20ac  // €
};

enum custom_keycodes {
  KC_TWBL // toggle windows base layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _WBL: Windows Base Layer (Default Layer)
   * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
   * │Esc│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│Slk│Pse│
   * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
   * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│Hom│PgU│ │Num│ / │ * │ - │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
   * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │Del│End│PgD│ │ 7 │ 8 │ 9 │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
   * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │               │ 4 │ 5 │ 6 │   │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
   * │Shift   │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │     │ 1 │ 2 │ 3 │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤Ent│
   * │Ctrl│GUI │Alt │                        │ Alt│Func│ App│Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │   │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
   */
  [_BL] = LAYOUT_tkl_ansi( /* Base Layer */
      KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, KC_SLCK, KC_PAUS,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
      KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,
      KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, TT(_FL), KC_APP,  KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
  ),
  // [_WBL] = LAYOUT_tkl_ansi( /* Windows Base Layer */
  //     KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, KC_SLCK, KC_PAUS,
  //     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
  //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
  //     LT(_UL, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
  //     KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,
  //     KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, TT(_FL), KC_APP,  KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
  // ),
  [_WL] = LAYOUT_tkl_ansi( /* Windows Layer */
        _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        LT(_UL, KC_CAPS), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             _______,
        _______,          _______, _______,                            _______,                            _______, _______, _______, _______,    _______, _______, _______
  ),
  /* Keymap _UL: Unicode Layer
   * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
   * │   │   │   │   │   │   │ │   │   │   │   │ │   │   │   │   │ │   │   │   │
   * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │ Ü │ Ó │       │ │   │   │   │ │   │   │   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
   * │     │   │   │   │   │   │   │   │ Í │   │   │ Ő │ Ú │  Ű  │ │   │   │   │ │   │   │   │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤   │
   * │      │   │   │   │   │   │   │   │   │   │ É │ Á │        │               │   │   │   │   │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
   * │        │   │   │   │   │   │   │   │   │   │   │          │     │   │     │   │   │   │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤   │
   * │    │    │    │                        │    │    │    │    │ │   │   │   │ │       │   │   │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
   */
  [_UL] = LAYOUT_tkl_ansi( /* Unicode Layer */
        _______,          _______, _______, _______, _______, _______, _______, _______,        _______, _______,        _______,        _______,        _______,           _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______,        XP(UDIS, UDIC), XP(OACS, OACC), _______,           _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, XP(IACS, IACC), _______, _______,        XP(ODCS, ODCC), XP(UACS, UACC), XP(UDCS, UDCC),    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______, XP(EACS, EACC), XP(AACS, AACC),                 _______,
        _______,          _______, _______, _______, _______, _______, _______, _______,        _______, _______,        _______,                        _______,                    _______,
        _______, _______, _______,                            _______,                                   _______,        _______,        _______,        _______,           _______, _______, _______
  ),
  /* Keymap _FL: Function Layer
   * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
   * │   │   │Ply│Stp│Prv│Nxt│ │Mut│Vo-│Vo+│   │ │   │   │   │ WL│ │   │   │Mut│
   * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │ │   │   │Vo+│ │   │   │   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
   * │     │WHU│WHD│MSU│   │   │   │   │   │   │   │   │   │     │ │   │   │Vo-│ │   │   │   │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤   │
   * │      │   │MSL│MSD│MSR│   │   │MB1│MB3│   │   │   │        │               │   │   │   │   │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
   * │        │   │   │   │   │   │   │MA0│MA1│MA2│   │          │     │   │     │   │   │   │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤   │
   * │    │    │    │                        │    │Func│ Sys│    │ │   │   │   │ │       │   │   │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
   */
  [_FL] = LAYOUT_tkl_ansi( /* Function Layer */
        _______,          KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, TG(_WL),    _______, _______, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_VOLU,
        _______, KC_WH_U, KC_WH_D, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_VOLD,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______,          _______,             _______,
        _______, _______, _______,                            _______,                            _______, _______, MO(_SL), _______,    _______, _______, _______
  ),
  /* Keymap _SL: System Layer
   * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
   * │BTL│   │RBT│   │   │   │ │   │   │   │   │ │   │   │   │   │ │   │   │   │
   * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │ │   │   │   │ │   │   │   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
   * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │ │   │   │   │ │   │   │   │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤   │
   * │      │   │   │   │   │   │   │   │   │   │   │   │        │               │   │   │   │   │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
   * │        │   │   │   │   │   │   │   │   │   │   │          │     │   │     │   │   │   │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤   │
   * │    │    │    │                        │    │    │    │    │ │   │   │   │ │       │   │   │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
   */
  [_SL] = LAYOUT_tkl_ansi( /* System Layer */
        QK_BOOT,          QK_RBT,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,             _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______,    _______, _______, _______
  ),
};

// uint32_t init_delay(uint32_t trigger_time, void *cb_arg) {
//   // off_all_leds();
//   return 0;
// }

// void keyboard_post_init_user(void) {
//   // on_all_leds();
//   defer_exec(3000, init_delay, NULL);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QK_BOOT:
      if (record->event.pressed) {
        // Flash LEDs to indicate bootloader mode is enabled.
        on_all_leds();
      }
      break;
    // case KC_TWBL:
    //   if (record->event.pressed) {
    //     if (IS_LAYER_ON(_WBL)) {
    //       // default_layer_set(_BL);
    //       layer_off(_WBL);
    //       // set_unicode_input_mode(UC_LNX);
    //       writePin(LED_MR_LOCK_PIN, true);
    //     } else {
    //       // default_layer_set(_WBL);
    //       layer_on(_WBL);
    //       // layer_off(_BL);
    //       // set_unicode_input_mode(UC_WINC);
    //       writePin(LED_MR_LOCK_PIN, false);
    //     }
    //   }
    //   break;
  }
  return true;
}

/* LED indicator pins */
// #define LED_CAPS_LOCK_PIN   C9
// #define LED_SCROLL_LOCK_PIN A8
// #define LED_WIN_LOCK_PIN    A9
// #define LED_MR_LOCK_PIN     A10
// #define LED_PIN_ON_STATE    0

layer_state_t layer_state_set_user(layer_state_t state) {
  if (IS_LAYER_ON_STATE(state, _WL)) {
    writePin(LED_MR_LOCK_PIN, false);
  } else {
    writePin(LED_MR_LOCK_PIN, true);
  }

  if (IS_LAYER_ON_STATE(state, _FL) || IS_LAYER_ON_STATE(state, _UL)) {
    writePin(LED_WIN_LOCK_PIN, false);
  } else {
    writePin(LED_WIN_LOCK_PIN, true);
  }
  return state;
}

void suspend_power_down_user(void) {
  // code will run multiple times while keyboard is suspended
  writePin(LED_MR_LOCK_PIN, true);
}

void suspend_wakeup_init_user(void) {
  // code will run on keyboard wakeup
  writePin(LED_MR_LOCK_PIN, !IS_LAYER_ON(_WL));
  writePin(LED_WIN_LOCK_PIN, !IS_LAYER_ON(_FL));
}

