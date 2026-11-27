#include "Motor.h"

Motor::Motor(const uint8_t (&pins)[2])
      : stepper(1, pins[0], pins[1])
{
  stepper.setMaxSpeed(stepsPerRev);
  stepper.setAcceleration(stepsPerRev/4.0f);
  stepper.setCurrentPosition(0);
  offset = 0;
}

void Motor::resetPosition() {
  offset = stepper.targetPosition() % stepsPerRev;
  stepper.setCurrentPosition(0);
  stepper.moveTo(0);
}

void Motor::moveTo(long distance) {
  stepper.moveTo(distance + offset);
}
