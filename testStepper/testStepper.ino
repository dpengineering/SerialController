#include "SpeedyStepper.h"

SpeedyStepper stepper1;

void setup() {
  Serial.begin(9600);

  stepper1.connectToPort(2);
  stepper1.setSpeedInStepsPerSecond(500);
  stepper1.setAccelerationInStepsPerSecondPerSecond(500);

}

void loop() {
  stepper1.moveRelativeInSteps(-2000);

}
