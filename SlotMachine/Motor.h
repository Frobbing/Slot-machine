#pragma once
#include "Constants.h"
#include <AccelStepper.h>

class Motor {
  private:

  public:
    long offset;
    AccelStepper stepper;
    Motor(const uint8_t (&pins)[2]);
    void resetPosition();
    void moveTo(long distance);
};