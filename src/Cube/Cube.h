#ifndef CUBE_H
#define CUBE_H

#include <Arduino.h>
#include <vector>

#include "consts.h"
#include "Frame.h"

class Cube {
public:
  Cube();
  void init();
  void loop();

private:
  void turnOff();
  void displayFrame(Frame);

private:
  long lastFrameStartTime;
  std::vector<Frame> frameBuffer;
};

#endif