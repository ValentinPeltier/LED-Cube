#ifndef CONSTS_H
#define CONSTS_H

const int FRAME_DURATION = 3;

/* ------------ */
/* --- Pins --- */
/* ------------ */

const int BUTTON_PIN = 28;

const int ROW_PINS[] = {
  22, 23, 24, 25, 26
};

const int COLUMN_PINS[] = {
  29, 30, 31, 32, 33,
  34, 35, 36, 37, 38,
  39, 40, 41, 42, 43,
  44, 45, 46, 47, 48,
  49, 50, 51, 52, 53
};

// Calculate cube size
const int ROW_COUNT = sizeof(ROW_PINS) / sizeof(ROW_PINS[0]);
const int COLUMN_COUNT = sizeof(COLUMN_PINS) / sizeof(COLUMN_PINS[0]);

#endif