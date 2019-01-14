#ifndef CUBE_H
#define CUBE_H

#include <Arduino.h>
#include <vector>

#include "consts.h"
#include "Button.h"
#include "Frame.h"

class Cube {
public:
  void init();
  void loop();

private:
  void turnOff();
  void displayFrame(Frame);

private:
  Button button;
  long lastFrameStartTime;
  std::vector<Frame> frameBuffer;
};

#endif