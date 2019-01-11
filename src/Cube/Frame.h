#ifndef FRAME_H
#define FRAME_H

#include "consts.h"

struct Frame {
  bool state[ROW_COUNT][COLUMN_COUNT] = { { false } };
  unsigned long duration = 0L;
};

#endif