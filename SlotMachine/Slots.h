#pragma once
#include "Motor.h"
#include <MultiStepper.h>

class Slots {
  private:
    uint8_t enablePin;
    Motor leftMotor;
    Motor middleMotor;
    Motor rightMotor;
    Motor* motorArray[3];
    long targets[3];
    void initArrays();
    void initTargets();
    void initMotorArray();
    void initResults();
    void genNewTargets();
    bool runMotors();
    void updateTargets();
    void resetMotors();
    void enableMotors();
    void disableMotors();
    void setTargets();

  public:
    Slots(const uint8_t (&pinsL)[2], const uint8_t (&pinsM)[2], const uint8_t (&pinsR)[2], const uint8_t &enable);
    int results[3];
    unsigned long lastResultTime;
    bool isRunning();
    void startSpin();
    void run();

};