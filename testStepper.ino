#include "SpeedyStepper.h"

SpeedyStepper stepper1;
SpeedyStepper stepper2;

void setup() {
  Serial.begin(9600);

  stepper1.connectToPort(1);
  stepper1.setSpeedInStepsPerSecond(500);
  stepper1.setAccelerationInStepsPerSecondPerSecond(500);
  stepper2.connectToPort(2);
  stepper2.setSpeedInStepsPerSecond(500);
  stepper2.setAccelerationInStepsPerSecondPerSecond(500);

}

void loop() {

  stepper1.setupRelativeMoveInSteps(1000);
  stepper2.setupRelativeMoveInSteps(1000);
  while((!stepper1.motionComplete()) || (!stepper2.motionComplete()))
 {
  stepper1.processMovement();
  stepper2.processMovement();
 }
  
}
