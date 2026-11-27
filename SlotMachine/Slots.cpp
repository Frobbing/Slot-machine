#include "Arduino.h"
#include "Slots.h"


Slots::Slots(const uint8_t (&pinsL)[2], const uint8_t (&pinsM)[2], const uint8_t (&pinsR)[2], const uint8_t &enable) 
    : leftMotor(pinsL), 
      middleMotor(pinsM), 
      rightMotor(pinsR), 
      enablePin(enable)
{
  initArrays();
  disableMotors();
}

void Slots::initArrays() {
  initTargets();
  initMotorArray();
  initResults();
}

void Slots::initTargets() {
  for(int i = 0; i < 3; i++) {
    targets[i] = 0;
  }
}

void Slots::initMotorArray() {
  motorArray[0] = &leftMotor;
  motorArray[1] = &middleMotor;
  motorArray[2] = &rightMotor;
}

void Slots::initResults() {
  for(int i = 0; i < 3; i++) {
    results[i] = 0;
  }
}

void Slots::resetMotors() {
  for(int i = 0; i < 3; i++) {
    motorArray[i]->resetPosition();
  }
}

void Slots::enableMotors() {
  digitalWrite(enablePin, LOW);
}

void Slots::disableMotors() {
  digitalWrite(enablePin, HIGH);
}

void Slots::startSpin() {
  initTargets();
  initResults();
  resetMotors();
  genNewTargets();
  setTargets();
  enableMotors();
  delay(100);
  run();
}

void Slots::genNewTargets() {
  for(int i = 0; i < 3; i++) {
    int target = random(8);
    results[i] = target;
    long finalPosition = stepsPerRev*(6 + i*2) + target * (stepsPerRev/8);
    targets[i] = finalPosition;
  }
}

void Slots::setTargets() {
  for(int i = 0; i < 3; i++) {
    Serial.println(targets[i]);
    motorArray[i]->moveTo(targets[i]);
  }
}

bool Slots::runMotors() {
  bool isRunning = false;
  for(int i = 0; i < 3; i++) {
    if(motorArray[i]->stepper.run()) {
      isRunning = true;
    }
  }
  return isRunning;
}

void Slots::run() {
  bool allFinished = false;
  while(!allFinished) {
    allFinished = !runMotors();
  }
  lastResultTime = millis();
  delay(100);
  disableMotors();
}

