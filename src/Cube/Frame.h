#ifndef FRAME_H
#define FRAME_H

#include "consts.h"

struct Frame {
  bool state[5][25] = { { false } };
  unsigned long duration = 0L;
};

#endif