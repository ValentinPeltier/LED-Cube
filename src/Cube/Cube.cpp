#include "Cube.h"

void Cube::init() {
  Serial.begin(9600);
  Serial.println("Initializing...");

  // Set pins mode
  for(int i = 0; i < 5; i++) {
    pinMode(ROW_PINS[i], OUTPUT);
  }

  for(int i = 0; i < 25; i++) {
    pinMode(COLUMN_PINS[i], OUTPUT);
  }

  button.init(BUTTON_PIN);

  calculateAnimation(true);
}

void Cube::loop() {
  if(button.click()) {
    nextAnimation();
  }

  displayAnimation();
}

void Cube::nextAnimation() {
  animationIndex = (animationIndex + 1) % ANIMATION_COUNT;

  calculateAnimation(true);
}

void Cube::calculateAnimation(bool animationHasChanged) {
  String animationName = ANIMATION_NAMES[animationIndex];
  Frame frame;

  if(animationName == "blink") {
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 25; j++) {
        frame.state[i][j] = random(1/BLINK_RATE) == 0;
      }
    }
    frame.duration = BLINK_FRAME_DURATION;

    animation.frames.push_back(frame);
    animation.loop = true;
  }
  else if(animationName == "rain") {
    if(animationHasChanged) {
      // Turn on the top LEDs
      for(int i = 0; i < 25; i++) {
        frame.state[4][i] = true;
      }
    }
    else {
      // Copy previous frame
      frame = animation.frames[0];

      // Move down all drops
      for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 25; j++) {
          if(frame.state[i][j]) {
            frame.state[i][j] = false;

            if(i - 1 >= 0) {
              // Go down
              frame.state[i - 1][j] = true;

              for(int k = i; k < 5; k++) {
                frame.state[k][j] = false;
              }
            }
            else {
              frame.state[4][j] = true;
            }
          }
        }
      }

      // Select new drops
      bool drops[25];
      int order[25];
      
      for(int i = 0; i < 25; i++) {
        drops[i] = random(1/RAIN_RATE) == 0;
        order[i] = i;
      }

      shuffle(order);

      // Turn on maximum RAIN_MAX_DROPS drops
      for(int i = 0; i < RAIN_MAX_DROPS; i++) {
        int j = order[i];

        if(!drops[j]) {
          continue;
        }

        if(j + 1 < 25 && j / 5 == (j + 1) / 5) {
          drops[j + 1] = false;
        }
        if(j - 1 >= 0 && j / 5 == (j - 1) / 5) {
          drops[j - 1] = false;
        }
        if(j + 5 < 25) {
          drops[j + 5] = false;
        }
        if(j - 5 >= 0) {
          drops[j - 5] = false;
        }
      }

      // Turn off all other LEDs
      for(int i = RAIN_MAX_DROPS; i < 25; i++) {
        drops[order[i]] = false;
      }

      // Set frame state
      for(int i = 0; i < 25; i++) {
        frame.state[3][i] = drops[i];
      }
    }

    frame.duration = RAIN_FRAME_DURATION;
    animation.frames.push_back(frame);
    animation.loop = true;
  }
}

void Cube::displayAnimation() {
  if(animation.frames.size() > 0) {
    // If current frame has been displayed long enough
    if(millis() >= lastFrameStartTime + animation.frames[0].duration) {
      if(animation.frames.size() == 1) {
        if(animation.loop) {
          calculateAnimation(false);
        }
        else {
          nextAnimation();
        }
      }

      // Remove it from the buffer
      animation.frames.erase(animation.frames.begin());
      lastFrameStartTime = millis();
    }

    displayFrame(animation.frames[0]);
  }
  else {
    lastFrameStartTime = millis();
    turnOff();
  }
}

void Cube::displayFrame(Frame frame) {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 25; j++) {
      // Set columns
      digitalWrite(COLUMN_PINS[j], frame.state[i][j]);
    }

    // Activate row for FRAME_DURATION
    digitalWrite(ROW_PINS[i], HIGH);

    delay(FRAME_DURATION);

    digitalWrite(ROW_PINS[i], LOW);
  }
}

void Cube::turnOff() {
  for(int i = 0; i < 5; i++) {
    digitalWrite(ROW_PINS[i], LOW);
  }

  for(int j = 0; j < 25; j++) {
    digitalWrite(COLUMN_PINS[j], LOW);
  }
}