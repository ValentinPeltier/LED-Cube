#ifndef ANIMATION_H
#define ANIMATION_H

#include "Frame.h"

struct Animation {
  std::vector<Frame> frames;
  bool loop;
};

#endif