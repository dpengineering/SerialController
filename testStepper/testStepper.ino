#include "SpeedyStepper.h"
#include "SpeedyStepper.cpp"

SpeedyStepper stepper1;

void setup() {
  Serial.begin(9600);

  stepper1.connectToPort(1);
  stepper1.setSpeedInStepsPerSecond(500);
  stepper1.setAccelerationInStepsPerSecondPerSecond(500);

}
// lol this is to test git hub
void loop() {
  stepper1.moveRelativeInSteps(-200);

}
