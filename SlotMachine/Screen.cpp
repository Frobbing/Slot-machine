#include "Arduino.h"
#include "Screen.h"

Screen::Screen()
      : lcd(screenAddress, screenWidth, screenHeight)
{
  state = IDLE;
  lastState = -1;
  currentResult = 0;
  currentSymText = "";
}

void Screen::begin() {
  lcd.init();
  lcd.backlight();
}

void Screen::changeState(ScreenState newState, int newResult, String symText) {
  state = newState;
  currentResult = newResult;
}

void Screen::changeState(ScreenState newState) {
  state = newState;
}

void Screen::updateScreen() {
  if(state == lastState) return;  // Don't continue if screen doesn't need to be updated

  lcd.clear();
  switch (state) {
    case    0: drawIdle();     break;
    case    1: drawSpinning(); break;
    case    2: drawResult();   break;
    default:   drawIdle();     break;
  }
  lastState = state;
}

void Screen::drawIdle() {
  lcd.print("  SLOT MACHINE  ");
  lcd.setCursor(0, 1);
  lcd.print("  PRESS BUTTON  ");
}

void Screen::drawSpinning() {
  lcd.print("    SPINNING    ");
  lcd.setCursor(0, 1);
  lcd.print(" Please wait... ");
}

void Screen::drawResult() {
  lcd.print(currentSymText);

  String resultText = String(currentResult);
  int offset = (16 - resultText.length()) / 2;
  if(offset < 0) {offset = 0;}
  lcd.setCursor(offset, 1);
  lcd.print(resultText);
}

ScreenState Screen::getState() {
  return state;
}