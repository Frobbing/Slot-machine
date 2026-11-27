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
    int currentResult; // Stores the latest result of a spin.
    String currentSymText; // Stores a text based description of the latest spin.
    enum ScreenState state; // Stores the current state of the screen.
    enum ScreenState lastState; // Stores the state of the screen on previous loop. Used to detect a change of state.
    void drawIdle(); // Renders the idle visual.
    void drawSpinning(); // Renders the spinning visual.
    void drawResult(); // Renders the resut visual.

  public:
    Screen(); // Initilizes variables.
    void begin(); // Calls necessary initialization functions of the LiquidCrystal_I2C class.
    void changeState(ScreenState newState, int newResult, String symText); // Changes state and stores new result values. Called when starting a new spin.
    void changeState(ScreenState newState); // Only changes the current state of the screen.
    void updateScreen(); // Updates the rendered visual if a change in state occurs.
    ScreenState getState(); // Returns the current state of the screen.
};
