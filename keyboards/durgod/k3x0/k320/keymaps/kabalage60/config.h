#pragma once

// #define UNICODE_SELECTED_MODES UC_WINC, UC_LNX
// #define UNICODE_SELECTED_MODES UC_WINC
#define TAPPING_TOGGLE 2

// https://docs.qmk.fm/#/tap_hold?id=tapping-term
// #define PERMISSIVE_HOLD
// #define HOLD_ON_OTHER_KEY_PRESS
// #define IGNORE_MOD_TAP_INTERRUPT

// Accelerated defaults

// #define MOUSEKEY_DELAY 10             // Delay between pressing a movement key and cursor movement
// #define MOUSEKEY_INTERVAL 20          // Time between cursor movements in milliseconds
// #define MOUSEKEY_MOVE_DELTA 8         // Step size
// #define MOUSEKEY_MAX_SPEED 10         // Maximum cursor speed at which acceleration stops
// #define MOUSEKEY_TIME_TO_MAX 30       // Time until maximum cursor speed is reached
// #define MOUSEKEY_WHEEL_DELAY 10       // Delay between pressing a wheel key and wheel movement
// #define MOUSEKEY_WHEEL_INTERVAL 80    // Time between wheel movements
// #define MOUSEKEY_WHEEL_MAX_SPEED 8    // Maximum number of scroll steps per scroll action
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 40 // Time until maximum scroll speed is reached

// #define MOUSEKEY_DELAY 0             // Delay between pressing a movement key and cursor movement
// #define MOUSEKEY_INTERVAL 16          // Time between cursor movements in milliseconds
// #define MOUSEKEY_MOVE_DELTA 1         // Step size
// #define MOUSEKEY_MAX_SPEED 1         // Maximum cursor speed at which acceleration stops
// #define MOUSEKEY_TIME_TO_MAX 60       // Time until maximum cursor speed is reached
// #define MOUSEKEY_WHEEL_DELAY 0       // Delay between pressing a wheel key and wheel movement
// #define MOUSEKEY_WHEEL_INTERVAL 80    // Time between wheel movements
// #define MOUSEKEY_WHEEL_MAX_SPEED 8    // Maximum number of scroll steps per scroll action
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 40 // Time until maximum scroll speed is reached

// Kinetic defaults

// #define MK_KINETIC_SPEED                        // Enable kinetic mode
// #define MOUSEKEY_DELAY 5                        // Delay between pressing a movement key and cursor movement
// #define MOUSEKEY_INTERVAL 10                    // Time between cursor movements in milliseconds
// #define MOUSEKEY_MOVE_DELTA 5                   // Step size for accelerating from initial to base speed
// #define MOUSEKEY_INITIAL_SPEED 100              // Initial speed of the cursor in pixel per second
// #define MOUSEKEY_BASE_SPEED 1000                // Maximum cursor speed at which acceleration stops
// #define MOUSEKEY_DECELERATED_SPEED 400          // Decelerated cursor speed
// #define MOUSEKEY_ACCELERATED_SPEED 3000         // Accelerated cursor speed
// #define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 16     // Initial number of movements of the mouse wheel
// #define MOUSEKEY_WHEEL_BASE_MOVEMENTS 32        // Maximum number of movements at which acceleration stops
// #define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48 // Accelerated wheel movements
// #define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8  // Decelerated wheel movements

#define MK_KINETIC_SPEED                        // Enable kinetic mode
#define MOUSEKEY_DELAY 0                        // Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL 16                    // Time between cursor movements in milliseconds
#define MOUSEKEY_MOVE_DELTA 3                   // Step size for accelerating from initial to base speed
#define MOUSEKEY_INITIAL_SPEED 10               // Initial speed of the cursor in pixel per second
#define MOUSEKEY_BASE_SPEED 240                // Maximum cursor speed at which acceleration stops
#define MOUSEKEY_DECELERATED_SPEED 150          // Decelerated cursor speed
#define MOUSEKEY_ACCELERATED_SPEED 1500         // Accelerated cursor speed
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 16     // Initial number of movements of the mouse wheel
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS 32        // Maximum number of movements at which acceleration stops
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48 // Accelerated wheel movements
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8  // Decelerated wheel movements

// #define MK_COMBINED

#define MK_C_OFFSET_0    1    // Cursor offset per movement (KC_ACL0)
#define MK_C_INTERVAL_0 66    // Time between cursor movements (KC_ACL0)
#define MK_C_OFFSET_1    1    // Cursor offset per movement (KC_ACL1)
#define MK_C_INTERVAL_1 33    // Time between cursor movements (KC_ACL1)
#define MK_C_OFFSET_2    1    // Cursor offset per movement (KC_ACL2)
#define MK_C_INTERVAL_2 16    // Time between cursor movements (KC_ACL2)
