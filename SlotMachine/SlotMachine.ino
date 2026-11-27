#include "Game.h"

Game game;

void setup() {
  game.beginScreen();
  pinMode(enablePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  randomSeed(analogRead(A3));
}

void loop() {
  game.run();
}
