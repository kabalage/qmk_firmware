#pragma once

// #define HOLD_ON_OTHER_KEY_PRESS
#define IGNORE_MOD_TAP_INTERRUPT
#ifdef RGB_DI_PIN
  #undef RGBLIGHT_HUE_STEP
  #define RGBLIGHT_HUE_STEP 8
#endif