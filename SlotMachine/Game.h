#pragma once

#include "Slots.h"
#include "Screen.h"

class Game {
  private:
    Slots slots; 
    Screen screen;
    int buttonState;
    int handleInput();
    int calculateScore();
    String getSymText();
    String toSymbol(int symId);
    void sort(int (&array)[3]);

  public:
    Game();
    void beginScreen();
    bool isRunning();
    void spin();
    void run();

};

