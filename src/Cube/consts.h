#ifndef CONSTS_H
#define CONSTS_H

const int FRAME_DURATION = 1;

/* ------------ */
/* --- Pins --- */
/* ------------ */

const int BUTTON_PIN = 28;

const int ROW_PINS[5] = {
  22, 23, 24, 25, 26
};

const int COLUMN_PINS[25] = {
  29, 30, 31, 32, 33,
  34, 35, 36, 37, 38,
  39, 40, 41, 42, 43,
  44, 45, 46, 47, 48,
  49, 50, 51, 52, 53
};

const String ANIMATION_NAMES[] = {
  "blink",
  "rain"
};
const int ANIMATION_COUNT = sizeof(ANIMATION_NAMES) / sizeof(ANIMATION_NAMES[0]);


/* ------------------ */
/* --- Animations --- */
/* ------------------ */

// Blink
const int BLINK_FRAME_DURATION = 100;
const float BLINK_RATE = 1 / 4.0f;

// Rain
const int RAIN_FRAME_DURATION = 140;
const float RAIN_RATE = 1 / 3.0f;
const int RAIN_MAX_DROPS = 1;

#endif