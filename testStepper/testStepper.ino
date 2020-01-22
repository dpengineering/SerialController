#include "SpeedyStepper.h"
// #include "SpeedyStepper.cpp"

SpeedyStepper stepper1;
SpeedyStepper stepper2;
SpeedyStepper stepper3;
SpeedyStepper stepper4;
SpeedyStepper stepper5;
SpeedyStepper stepper6;

void setup() {
  Serial.begin(9600);

  pinMode(23, INPUT);

  stepper1.connectToPort(1) ;
  stepper1.setSpeedInStepsPerSecond(500);
  stepper1.setAccelerationInStepsPerSecondPerSecond(500);
  stepper2.connectToPort(2);
  stepper2.setSpeedInStepsPerSecond(500);
  stepper2.setAccelerationInStepsPerSecondPerSecond(500);
  stepper3.connectToPort(3);
  stepper3.setSpeedInStepsPerSecond(500);
  stepper3.setAccelerationInStepsPerSecondPerSecond(500);
  stepper4.connectToPort(4);
  stepper4.setSpeedInStepsPerSecond(500);
  stepper4.setAccelerationInStepsPerSecondPerSecond(500);
  stepper5.connectToPort(5);
  stepper5.setSpeedInStepsPerSecond(500);
  stepper5.setAccelerationInStepsPerSecondPerSecond(500);
  stepper6.connectToPort(6);
  stepper6.setSpeedInStepsPerSecond(500);
  stepper6.setAccelerationInStepsPerSecondPerSecond(500);
  
 // testStepper();
 //delay(10000);
  moveStepperHome();
  delay(10000 * 2);
  disable();

}

void loop() {

}


void testStepper() {
  
  stepper1.setupRelativeMoveInSteps(1000);
  stepper2.setupRelativeMoveInSteps(1000);
  stepper3.setupRelativeMoveInSteps(1000);
  stepper4.setupRelativeMoveInSteps(1000);
  stepper5.setupRelativeMoveInSteps(1000);
  stepper6.setupRelativeMoveInSteps(1000);
  while((!stepper1.motionComplete()) || (!stepper2.motionComplete()) || (!stepper3.motionComplete()) || (!stepper4.motionComplete()) || (!stepper5.motionComplete()) || (!stepper6.motionComplete()))
 {
  stepper1.processMovement();
  stepper2.processMovement();
  stepper3.processMovement();
  stepper4.processMovement();
  stepper5.processMovement();
  stepper6.processMovement();
 }

}

void moveStepperHome() {
  Serial.print("running moveStepperHome");
  
  int switchPin = 23;
  byte stepper = 1;
  long maxDistance = 100000;
  long dir = 1;
  float spd = 500;
  if (dir = 0)
    dir = -1;

 /* do{
   testStepper();
  }while (digitalRead(23) == LOW);
  
  while(true) {

  while (digitalRead(23) == LOW) {
    testStepper();
  }
  
*/
  
  
  switch (stepper) {
    case 1:
      stepper1.moveToHomeInSteps(dir, spd, maxDistance, switchPin);
      Serial.print("stepper one");
      break;
    case 2:
      stepper2.moveToHomeInSteps(dir, spd, maxDistance, switchPin);
      break;
    case 3:
      stepper3.moveToHomeInSteps(dir, spd, maxDistance, switchPin);
      break;
    case 4:
      stepper4.moveToHomeInSteps(dir, spd, maxDistance, switchPin);
      break;
    case 5:
      stepper5.moveToHomeInSteps(dir, spd, maxDistance, switchPin);
      break;
    case 6:
      stepper6.moveToHomeInSteps(dir, spd, maxDistance, switchPin);
      break;
  }
  
}

void function() {


}

void disable() {

  stepper1.disableStepper();
  stepper2.disableStepper();
  stepper3.disableStepper();
  stepper4.disableStepper();
  stepper5.disableStepper();
  stepper6.disableStepper();
  
}
