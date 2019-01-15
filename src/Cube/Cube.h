#ifndef CUBE_H
#define CUBE_H

#include <Arduino.h>
#include <vector>

#include "utils.h"
#include "consts.h"
#include "Animation.h"
#include "Button.h"
#include "Frame.h"

class Cube {
public:
  void init();
  void loop();

private:
  void displayAnimation();
  void nextAnimation();
  void calculateAnimation(bool animationHasChanged);
  void turnOff();
  void displayFrame(Frame);

private:
  Button button;
  long lastFrameStartTime;
  Animation animation;
  int animationIndex;
};

#endif