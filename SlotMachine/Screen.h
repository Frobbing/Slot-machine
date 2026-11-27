#pragma once

#include "Constants.h"
#include <stdint.h>
#include "LiquidCrystal_I2C.h"

enum ScreenState {
  IDLE,
  SPINNING,
  RESULT
};

class Screen {
  private:
    LiquidCrystal_I2C lcd;
    int currentResult;
    String currentSymText;
    enum ScreenState state;
    enum ScreenState lastState;
    void drawIdle();
    void drawSpinning();
    void drawResult();

  public:
    Screen();
    void begin();
    void changeState(ScreenState newState, int newResult, String symText);
    void changeState(ScreenState newState);
    void updateScreen();
    ScreenState getState();
};