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
  _SP, // Space layer
  _MS, // Mouse layer
  _FL, // Function layer
  _SL  // System layer
};

enum custom_keycodes {
  KC_EAC = SAFE_RANGE,
  KC_AAC,
  KC_UAC,
  KC_ODI,
  KC_UDI,
  KC_OAC,
  KC_IAC,
  KC_ODA,
  KC_UDA
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
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
   * │Ctrl│GUI │Alt │                        │ GUI│Func│ App│Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │   │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
   */
  [_BL] = LAYOUT_tkl_ansi(
      KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, KC_SLCK, KC_PAUS,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
      KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,
      KC_LCTL, KC_LGUI, KC_LALT,                            LT(_SP, KC_SPC),                    KC_LGUI, MO(_FL), KC_APP,  KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
  ),
  /* Keymap _SP: Space Layer
   * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
   * │   │   │   │   │   │   │ │   │   │   │   │ │   │   │   │   │ │   │   │   │
   * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │ Ü │ Ó │       │ │   │   │   │ │   │   │   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
   * │     │_MS│   │   │   │   │PgU│Hom│ ↑ │End│   │ Ő │ Ú │  Ű  │ │   │   │   │ │   │   │   │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤   │
   * │      │   │   │Del│Bsp│   │PgD│ ← │ ↓ │ → │ É │ Á │        │               │   │   │   │   │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
   * │        │   │   │   │   │   │Ent│   │   │ Ű │ Í │          │     │   │     │   │   │   │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤   │
   * │    │    │    │                        │    │    │    │    │ │   │   │   │ │       │   │   │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
   */
  [_SP] = LAYOUT_tkl_ansi(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ODI,  KC_UDI,  KC_OAC,  _______,           _______, _______, _______,
        _______, TO(_MS), _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END, _______,  KC_ODA,  KC_UAC,  KC_UDA,            _______, _______, _______,
        _______, _______, _______, KC_DEL,  KC_BSPC, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_EAC,  KC_AAC,           _______,
        _______,          _______, _______, _______, _______, _______, KC_ENT,  _______, _______, KC_UDA,  KC_IAC,           _______,                    _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______,           _______, _______, _______
  ),
  /* Keymap _MS: Mouse Layer
   * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
   * │   │   │   │   │   │   │ │   │   │   │   │ │   │   │   │   │ │   │   │   │
   * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │ │   │   │   │ │   │   │   │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
   * │     │   │   │MSU│   │   │   │WHU│   │WHD│   │   │   │     │ │   │   │   │ │   │   │   │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤   │
   * │      │   │MSL│MSD│MSR│   │   │MB1│MB3│MB2│   │   │        │               │   │   │   │   │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
   * │        │   │   │   │   │   │   │MA0│MA1│MA2│   │          │     │   │     │   │   │   │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤   │
   * │    │    │    │           _MS off      │    │    │    │    │ │   │   │   │ │       │   │   │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
   */
  [_MS] = LAYOUT_tkl_ansi(
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,          XXXXXXX,             XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            TG(_MS),                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
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
  [_FL] = LAYOUT_tkl_ansi(
        _______,          KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______,    _______, _______, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_VOLU,
        _______, KC_WH_U, KC_WH_D, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_VOLD,
        KC_CAPS, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,          _______,
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

uint8_t modState;

uint16_t get_custom_keycode_mapping(uint16_t keycode) {
  return custom_keycodes_map[keycode - SAFE_RANGE];
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QK_BOOT:
      if (record->event.pressed) {
        // Flash LEDs to indicate bootloader mode is enabled.
        on_all_leds();
      }
      break;

    case KC_EAC ... KC_IAC: //
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

/* LED indicator pins */
// #define LED_CAPS_LOCK_PIN   C9
// #define LED_SCROLL_LOCK_PIN A8
// #define LED_WIN_LOCK_PIN    A9
// #define LED_MR_LOCK_PIN     A10
// #define LED_PIN_ON_STATE    0

layer_state_t layer_state_set_user(layer_state_t state) {
  if (IS_LAYER_ON_STATE(state, _MS)) {
    writePin(LED_MR_LOCK_PIN, false);
  } else {
    writePin(LED_MR_LOCK_PIN, true);
  }

  // if (IS_LAYER_ON_STATE(state, _FL)) {
  //   writePin(LED_WIN_LOCK_PIN, false);
  // } else {
  //   writePin(LED_WIN_LOCK_PIN, true);
  // }
  return state;
}

void suspend_power_down_user(void) {
  // code will run multiple times while keyboard is suspended
  writePin(LED_MR_LOCK_PIN, true);
}

void suspend_wakeup_init_user(void) {
  // code will run on keyboard wakeup
  writePin(LED_MR_LOCK_PIN, !IS_LAYER_ON(_MS));
  // writePin(LED_WIN_LOCK_PIN, !IS_LAYER_ON(_FL));
}

