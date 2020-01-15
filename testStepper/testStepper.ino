#include "SpeedyStepper.h"

SpeedyStepper stepper1;
SpeedyStepper stepper2;
SpeedyStepper stepper3;
SpeedyStepper stepper4;
SpeedyStepper stepper5;
SpeedyStepper stepper6;

void setup() {
  Serial.begin(9600);

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

  testStepper();
  delay(10000);
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

void disable() {

  stepper1.disableStepper();
  stepper2.disableStepper();
  stepper3.disableStepper();
  stepper4.disableStepper();
  stepper5.disableStepper();
  stepper6.disableStepper();
  
}
