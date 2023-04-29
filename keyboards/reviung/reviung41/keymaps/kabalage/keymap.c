/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _ACCENT,
    _LOWER,
    _RAISE,
    _NUMBERS,
    _ADJUST
};

enum custom_keycodes {
  KC_EAC = SAFE_RANGE, // é
  KC_AAC, // á
  KC_UAC, // ú
  KC_ODI, // ö
  KC_UDI, // ü
  KC_OAC, // ó
  KC_IAC, // í
  KC_IDI, // ï
  KC_EDI, // ë
  KC_ADI, // ä
  KC_ODA, // ő
  KC_UDA, // ű,
  KC_EGR, // è
  KC_AGR, // à
  ARROW_FUN // () => {}
};

const uint16_t custom_keycodes_map[] = {
  KC_E, // KC_EAC
  KC_A, // KC_AAC
  KC_U, // KC_UAC
  KC_P, // KC_ODI
  KC_Y, // KC_UDI
  KC_O, // KC_OAC
  KC_I, // KC_IAC
  KC_J, // KC_IDI
  KC_R, // KC_EDI
  KC_Q, // KC_ADI
  KC_O, // KC_ODA
  KC_U, // KC_UDA
  KC_E, // KC_EGR
  KC_A // KC_AGR
};

#define ACCENT  MO(_ACCENT)
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NUMBERS MO(_NUMBERS)
#define ADJUST MO(_ADJUST)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J    RSFT_T(KC_J)
#define HOME_K    RCTL_T(KC_K)
#define HOME_L    LALT_T(KC_L)
#define HOME_F12  RGUI_T(KC_F12)

#define WS_PREV LGUI(KC_PGUP)
#define WS_NEXT LGUI(KC_PGDN)
#define ALT_TAB LALT(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
  // │Cmp│ Q │ W │ E │ R │ T │   │ Y │ U │ I │ O │ P │F12│
  // ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
  // │ACC│ A │ S │ D │ F │ G │   │ H │ J │ K │ L │   │CW │
  // ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
  // │Esc│ Z │ X │ C │ V │ B │   │ N │ M │ ,<│ .>│ /?│   │
  // └───┴───┴───┼───┴┬──┴─┬─┴───┴─┬─┴──┬┴───┼───┴───┴───┘
  //             │    │LOWR│ Space │RAIS│NMBR│
  //             └────┴────┴───────┴────┴────┘
  [_BASE] = LAYOUT_reviung41(
    KC_APP,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_F12,
    ACCENT,   HOME_A,   HOME_S,   HOME_D,   HOME_F,    KC_G,               KC_H,     HOME_J,   HOME_K,   HOME_L,   KC_RGUI,  CAPSWRD,
    KC_ESC,   KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  _______,
                                            _______,   LOWER,    KC_SPC,   RAISE,    NUMBERS
  ),

  // ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
  // │   │   │   │   │   │   │   │   │ Ö │ Ü │ Ó │ Ï │ È │
  // ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
  // │   │   │   │   │   │   │   │   │ É │ Á │ Ő │ Ú │IJ │
  // ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
  // │   │   │   │   │   │   │   │   │ Ű │ Í │ Ë │ Ä │ À │
  // └───┴───┴───┼───┴┬──┴─┬─┴───┴─┬─┴──┬┴───┼───┴───┴───┘
  //             │    │    │       │    │    │
  //             └────┴────┴───────┴────┴────┘
  [_ACCENT] = LAYOUT_reviung41(
    _______,  _______,     _______,     _______,     _______,      _______,               _______,     KC_ODI,      KC_UDI,      KC_OAC,      KC_IDI,      KC_EGR,
    _______,  _______,     _______,     _______,     _______,      _______,               _______,     KC_EAC,      KC_AAC,      KC_ODA,      KC_UAC,      _______,
    _______,  _______,     _______,     _______,     _______,      _______,               _______,     KC_UDA,      KC_IAC,      KC_EDI,      KC_ADI,      KC_AGR,
                                                     _______,      _______,    _______,   _______,     _______
  ),
  // [_ACCENT] = LAYOUT_reviung41(
  //   _______,  _______,     _______,     _______,     _______,      _______,               _______,     _______,     _______,     _______,     _______,     _______,
  //   _______,  _______,     _______,     _______,     _______,      _______,               _______,     _______,     _______,     _______,     _______,     _______,
  //   _______,  _______,     _______,     _______,     _______,      _______,               _______,     _______,     _______,     _______,     _______,     _______,
  //                                                    _______,      _______,    _______,   _______,     _______
  // ),

  // ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
  // │   │ ~ │ % │ ( │ ) │ @ │   │ " │ - │ < │ > │ ^ │   │
  // ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
  // │   │ / │ ? │ { │ } │ = │   │ + │ ; │ ' │ ! │ ` │=> │
  // ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
  // │   │ # │ & │ [ │ ] │ \ │   │ _ │ : │ * │ | │ $ │   │
  // └───┴───┴───┼───┴┬──┴─┬─┴───┴─┬─┴──┬┴───┼───┴───┴───┘
  //             │    │____│ Enter │ L3 │    │
  //             └────┴────┴───────┴────┴────┘
  [_LOWER] = LAYOUT_reviung41(
    _______,  KC_TILD,     KC_PERC,     KC_LPRN,     KC_RPRN,      KC_AT,                 KC_DQUO,     KC_MINS,     KC_LT,       KC_GT,       KC_CIRC,     _______,
    _______,  KC_SLSH,     KC_QUES,     KC_LCBR,     KC_RCBR,      KC_EQL,                KC_PLUS,     KC_SCLN,     KC_QUOT,     KC_EXLM,     KC_GRV,      ARROW_FUN,
    _______,  KC_HASH,     KC_AMPR,     KC_LBRC,     KC_RBRC,      KC_BSLS,               KC_UNDS,     KC_COLN,     KC_ASTR,     KC_PIPE,     KC_DLR,      _______,
                                                     _______,      _______,    KC_ENT,    _______,     _______
  ),
  // [_LOWER] = LAYOUT_reviung41(
  //   _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
  //   _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_GRV,   KC_TILD,
  //   _______,  KC_ESC,   KC_LGUI,  KC_LALT,  KC_CAPS,   KC_DQUO,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_PSCR,  RSFT_T(KC_SPC),
  //                                           _______,   _______,  KC_ENT,   _______,  _______
  // ),

  // ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
  // │ScL│Ins│TGM│WS-│WS+│   │   │PSc│PgU│ ↑ │PgD│Vo-│Vo+│ toggle mouse
  // ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
  // │   │Sup│Alt│Ctl│Sft│ATa│   │Hom│ ← │ ↓ │ → │End│Pla│ alt+tab
  // ├───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┤
  // │   │Mr4│Mr3│Mr2│Mr1│   │   │Tab│Del│Bsp│Prv|Nxt│Mut│ goto/mark/unmark
  // └───┴───┴───┼───┴┬──┴─┬─┴───┴─┬─┴──┬┴───┼───┴───┴───┘
  //             │    │ L3 │ Enter │____│    │
  //             └────┴────┴───────┴────┴────┘
  [_RAISE] = LAYOUT_reviung41(
    KC_SLCK,  KC_INS,      _______,     WS_PREV,     WS_NEXT,      _______,               KC_PSCR,     KC_PGUP,    KC_UP,       KC_PGDN,     KC_VOLD,     KC_VOLU,
    _______,  KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT,      ALT_TAB,               KC_HOME,     KC_LEFT,    KC_DOWN,     KC_RGHT,     KC_END,      KC_MPLY,
    _______,  _______,     _______,     _______,     _______,      _______,               KC_TAB,      KC_DEL,      KC_BSPC,    KC_MPRV,     KC_MNXT,     KC_MUTE,
                                                     _______,      _______,    KC_ENT,    _______,     _______
  ),

  // [_RAISE] = LAYOUT_reviung41(
  //   _______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
  //   _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
  //   _______,  KC_ESC,   KC_RGUI,  KC_RALT,  KC_CAPS,   KC_QUOT,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
  //                                           _______,   _______,  KC_BSPC,  _______,  _______
  // ),

  [_NUMBERS] = LAYOUT_reviung41(
    _______,  KC_F8,       KC_F7,       KC_F6,       KC_F5,        _______,               _______,     KC_7,        KC_8,        KC_9,        _______,     _______,
    _______,  KC_F4,       KC_F3,       KC_F2,       KC_F1,        KC_GRV,                KC_0,        KC_4,        KC_5,        KC_6,        KC_RGUI,     _______,
    _______,  KC_F12,      KC_F11,      KC_F10,      KC_F9,        _______,               _______,     KC_1,        KC_2,        KC_3,        _______,     _______,
                                                     _______,      _______,    _______,   _______,     _______
  ),

  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


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

    case KC_EAC ... KC_ADI: // é, á, ú, ö, ü, ó, í, ï, ë, ä
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
    case KC_EGR ... KC_AGR: // è, à
      if (record->event.pressed) {
        // register grave
        modState = get_mods();
        clear_mods();
        register_code(KC_RALT);
        tap_code(KC_GRV);
        unregister_code(KC_RALT);
        set_mods(modState);

        tap_code(get_custom_keycode_mapping(keycode));
        return false;
      }
      break;
    case ARROW_FUN:
      if (record->event.pressed) {
        modState = get_mods();
        clear_mods();
        send_string("=>");
        set_mods(modState);
        return false;
      }
      break;
  }
  return true;
}