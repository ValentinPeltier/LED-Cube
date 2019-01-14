#include "Cube.h"

void Cube::init() {
  Serial.begin(9600);
  Serial.println("Initializing...");

  // Set pins mode
  for(int i = 0; i < ROW_COUNT; i++) {
    pinMode(ROW_PINS[i], OUTPUT);
  }

  for(int i = 0; i < COLUMN_COUNT; i++) {
    pinMode(COLUMN_PINS[i], OUTPUT);
  }

  button.init(BUTTON_PIN);

  Frame frame;

  // First frame : 1 LED over 2 is on
  for(int i = 0; i < ROW_COUNT; i++) {
    for(int j = 0; j < COLUMN_COUNT; j++) {
      frame.state[i][j] = (i + j) % 2 == 0;
    }
  }
  frame.duration = 1000;
  frameBuffer.push_back(frame);

  // Second frame : inverse of first frame
  for(int i = 0; i < ROW_COUNT; i++) {
    for(int j = 0; j < COLUMN_COUNT; j++) {
      frame.state[i][j] = (i + j) % 2 == 1;
    }
  }
  frame.duration = 1000;
  frameBuffer.push_back(frame);
}

void Cube::loop() {
  if(frameBuffer.size() > 0) {
    // If current frame has been displayed long enough
    if(millis() >= lastFrameStartTime + frameBuffer[0].duration) {
      // Remove it from the buffer
      lastFrameStartTime = millis();
      frameBuffer.erase(frameBuffer.begin());
    }

    displayFrame(frameBuffer[0]);
  }
  else {
    turnOff();
  }
}

void Cube::turnOff() {
  for(int i = 0; i < ROW_COUNT; i++) {
    digitalWrite(ROW_PINS[i], LOW);
  }

  for(int j = 0; j < COLUMN_COUNT; j++) {
    digitalWrite(COLUMN_PINS[j], LOW);
  }
}

void Cube::displayFrame(Frame frame) {
  for(int i = 0; i < ROW_COUNT; i++) {
    for(int j = 0; j < COLUMN_COUNT; j++) {
      // Set columns
      digitalWrite(COLUMN_PINS[j], frame.state[i][j]);
    }

    // Activate row for FRAME_DURATION
    digitalWrite(ROW_PINS[i], HIGH);

    delay(FRAME_DURATION);

    digitalWrite(ROW_PINS[i], LOW);
  }
}