#pragma once

#include "Slots.h"
#include "Screen.h"

class Game {
  private:
    Slots slots; 
    Screen screen;
    int buttonState; // Describes the state of the button. It is pulled up, so HIGH is off and LOW is on.
    int calculateScore(); // Called when starting a spin. Returns a total score based on multipliers defined in constants.h.
    String getSymText(); // Returns a string describing the result of a spin.
    String toSymbol(int symId); // Returns a text version of a result based on a given symbol id.
    void sort(int (&array)[3]); // Naively sorts an array of three integers.
    void spin(); // Calculates new result, updates the screen and starts the spinning sequence.

  public:
    Game();
    void beginScreen(); // Runs screen initializer.
    void run(); // Called in the main loop. Handles button input and timed screen updates.
};

