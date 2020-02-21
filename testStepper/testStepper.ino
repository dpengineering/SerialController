#include "SpeedyStepper.h"
//#include "SerialDebug.h"



SpeedyStepper stepper1;
SpeedyStepper stepper2;
SpeedyStepper stepper3;
SpeedyStepper stepper4;
SpeedyStepper stepper5;
SpeedyStepper stepper6;

void setup() {
  Serial.begin(9600);

  pinMode(23, INPUT);

 // Debug.println("Debug print statements are working");


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

  //testStepper();
  //delay(10000);
  moveStepperHome();
  delay(10000 * 2);
  disable();

}

void loop() {

 // moveStepperHome();
 // stepper1.processMovement();
 //delay(10000);

}

void testStepper() {

  stepper1.setupRelativeMoveInSteps(2000);
  stepper2.setupRelativeMoveInSteps(2000);
  stepper3.setupRelativeMoveInSteps(2000);
  stepper4.setupRelativeMoveInSteps(2000);
  stepper5.setupRelativeMoveInSteps(2000);
  stepper6.setupRelativeMoveInSteps(2000);
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

  Serial.println("running moveStepperHome");

  int switchPin = 29;
  byte stepper = 1;
  long maxDistance = 100000;
  long dir = 1;
  float spd = 500;
  if (dir == 0)
    dir = -1;
    
  
  switch (stepper) {
    case 1:
    //  stepper1.enableStepper();
   //   stepper1.setupMoveInSteps(maxDistance);
    //  char buff[100];
    //  sprintf(buff, "This is stepper1.getTargetPos...%lu", stepper1.getTargetPositionInSteps());
   //   Serial.println(buff);
   //   Serial.print("This is stepper1.getTargetPos..." );
   //   Serial.println(stepper1.getTargetPositionInSteps());
    //  stepper1.setCurrentPositionInSteps(1);
      stepper2.moveToHomeInSteps(dir, spd, maxDistance, switchPin);
     // stepper2.moveToHomeInSteps(dir, spd, maxDistance, switchPin);
    //  stepper3.moveToHomeInSteps(dir, spd, maxDistance, switchPin);
    //  stepper4.moveToHomeInSteps(dir, spd, maxDistance, switchPin);
      Serial.println("stepper one");
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
  
  // Switching x and y!

  /*
  int x = 5;
  int y = 10;

  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
  Serial.println(x);
  Serial.println(y);

  bool T = 5;
  Serial.println(T);
  T -= 1;
  Serial.println(T);
*/
  
}
