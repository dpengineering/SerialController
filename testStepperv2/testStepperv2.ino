#include "SpeedyStepper.h"
SpeedyStepper stepper1;

void setup() {
  Serial.begin(9600);
  stepper1.setAccelerationInStepsPerSecondPerSecond(500);
}


// lol this is to test git hub
void loop() {
      int steps = 100;
      stepper1.enableStepper();
      stepper1.setupRelativeMoveInSteps(steps);
      stepper1.setupRelativeMoveInSteps(steps);
      while(!stepper1.motionComplete())
     {
        stepper1.processMovement();
     }
}
