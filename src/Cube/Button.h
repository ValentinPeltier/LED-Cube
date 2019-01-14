#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
  void init(int pin);
  bool click();

private:
  int pin;
  bool lastState;
};

#endif