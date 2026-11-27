#include "Arduino.h"
#include "Game.h"

Game::Game() 
    : slots(leftMotorPins, middleMotorPins, rightMotorPins, enablePin)
{
  buttonState = HIGH;
  screen.changeState(IDLE);
}

void Game::beginScreen() {
  screen.begin();
}

void Game::spin() {
  int score = calculateScore();
  String scoreText = getSymText();
  screen.changeState(SPINNING, score, scoreText);
  screen.updateScreen();
  slots.startSpin();
}

void Game::run() {
  int newButtonState = digitalRead(buttonPin);
  if(newButtonState == HIGH && buttonState == LOW) {
    spin();
  }
  screen.updateScreen();
  buttonState = newButtonState;

  switch (screen.getState()) {
    case SPINNING:
      screen.changeState(RESULT);
      break;
    case RESULT:
      if (millis() - slots.lastResultTime > screenResultTimeout) {
        screen.changeState(IDLE);
      }
      break;
  }
}

void Game::sort(int (&array)[3]) {
  if (array[0] > array[1]) {
    int t = array[0];
    array[0] = array[1];
    array[1] = t; 
  }
  if (array[1] > array[2]) {
    int t = array[1];
    array[1] = array[2];
    array[2] = t; 
  }
  if (array[0] > array[1]) {
    int t = array[0];
    array[0] = array[1];
    array[1] = t;
  }
}

int Game::calculateScore() {
  int score = 0;
  
  int bonusCount = 0;
  for(int symbol : slots.results) {
    if(symbol == bonusSymbol) {
      bonusCount++;
    }
  }

  switch (bonusCount) {
    case 3: score = baseScore * bonusTripleX; return score;
    case 2: score = baseScore * bonusDoubleX; return score;
    case 1: score += bonusPoint; break;
    default: break;
  }

  int sortedResults[3] = {slots.results[0], slots.results[1], slots.results[2]};
  sort(sortedResults);

  if(sortedResults[0] == sortedResults[2]) {
    score += baseScore * defaultTripleX;
    return score;
  }
  if(sortedResults[0] == sortedResults[1] || sortedResults[1] == sortedResults[2]) {
    score += baseScore * defaultDoubleX;
    return score;
  }
  
  return score;
}

String Game::getSymText() {
  String sym1 = toSymbol(slots.results[0]);
  String sym2 = toSymbol(slots.results[1]);
  String sym3 = toSymbol(slots.results[2]);

  return " " + sym1 + "  " + sym2 + "  " + sym3 + "  ";
}

String Game::toSymbol(int symId) {
  switch (symId) {
    case 0: return "svn";
    case 1: return "bar";
    case 2: return "bel";
    case 3: return "dia";
    case 4: return "chr";
    case 5: return "lmn";
    case 6: return "org";
    case 7: return "grp";
    default: return "err";
  }
}

