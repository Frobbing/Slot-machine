#include "Game.h"

Game game;

void setup() {
  game.beginScreen();
  pinMode(enablePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  randomSeed(analogRead(A3)); // Open input pin A3, generates random noise for seed. 
}

void loop() {
  game.run(); // Main loop. Handles input and updates screen.
}
