#include "Button.h"

void Button::init(int pin) {
  pinMode(pin, INPUT);
  
  this->pin = pin;
  lastState = false;
}

bool Button::click() {
  bool buttonClick = false;
  bool buttonPressed = digitalRead(pin);

  if(buttonPressed != lastState && buttonPressed) {
    buttonClick = true;
  }
  else {
    buttonClick = false;
  }

  lastState = buttonPressed;

  return buttonClick;
}