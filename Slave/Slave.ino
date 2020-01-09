//      ******************************************************************
//      *                                                                *
//      *                 Header file for Slave.ino                      *
//      *                                                                *
//      *                 Copyright (c) Josh Benson                      *
//      *                                                                *
//      ******************************************************************

#include "SerialSlave.h"
#include "SpeedyStepper.h"

#define ADDRESS 17

SpeedyStepper stepper1;
SpeedyStepper stepper2;

bool LED = false;
bool running1 = false;
bool running2 = false;
double stepperSetting = .25;

void setup() {
  serialSlave.open(115200, ADDRESS, 40);
  Serial.begin(9600);

  stepper1.connectToPort(1);
  stepper1.setSpeedInStepsPerSecond(500);
  stepper1.setAccelerationInStepsPerSecondPerSecond(500);

  stepper2.connectToPort(2);
  stepper2.setSpeedInStepsPerSecond(500);
  stepper2.setAccelerationInStepsPerSecondPerSecond(500);

}

void loop() {

  if (stepper1.processMovement() && running1) {
    stepper1.disableStepper();
    running1 = false;
  }

  if (stepper2.processMovement() && running1) {
    stepper2.disableStepper();
    running2 = false;
  }


}

  Func moveStepper;
  Func stopStepper;


Callable callables[] = {
  {"moveStepper", moveStepper},
  {"disable", disable},
  {"disableWhenDone", disableWhenDone},
  {"blinkLED", blinkLED},
  {"toggleLED", toggleLED},
  {"moveStepperToPos", moveStepperToPos},
  {"moveStepperDeg", moveStepperDeg},
  {"moveStepperRev", moveStepperRev},
  {"setStepperSpeed", setStepperSpeed}
};

byte numberOfExternalCallables = sizeof(callables) / sizeof(Callable);

void moveStepper(byte dataLength, byte *dataArray) {

  byte stepper = dataArray[0];
  int steps = ((int *) (dataArray + 2))[0];
  if (dataArray[1] == 1) {
    steps *= -1;
  }

  switch (stepper) {
    case 1:
      stepper1.enableStepper();
      stepper1.setupRelativeMoveInSteps(steps);
      break;
    case 2:
      stepper2.enableStepper();
      stepper2.setupRelativeMoveInSteps(steps);
      break;
  }
  running1 = true;
  running2 = true;

  return("Moving Stepper");

}

void blinkLED(byte dataLength, byte *dataArray) {

  byte LEDPin = dataArray[0];
  byte waitTime = dataArray[1];

  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, HIGH);
  Serial.print("LED On");
  delay(waitTime * 30);
  digitalWrite(LEDPin, LOW);
  Serial.print("LED Off");
  delay(waitTime);

  LED = true;

}

void toggleLED(byte dataLength, byte *dataArray) {

  byte LEDPin = dataArray[0];
  byte switchState = dataArray[1];

  pinMode(LEDPin, OUTPUT);
  if (switchState == 0)
  {
    digitalWrite(LEDPin, LOW);
  }
  else if (switchState == 1)
  {
    digitalWrite(LEDPin, LOW);
  }
  else
  {
    Serial.print("LED switch state must be 0 or 1. This is the second value in dataArray");
  }

}


void disable() {
  stepper1.disableStepper();
  stepper2.disableStepper();
}

void disableWhenDone() {
  
  if (running1==false && running2==false)
  {
  stepper1.disableStepper();
  stepper2.disableStepper();
  }
  else
  {
    disableWhenDone();
  }
}


void moveStepperDeg(byte dataLength, byte *dataArray) {
  
  byte stepper = dataArray[0];
  int deg = ((int *) (dataArray + 2))[0];
  double stepsPerDeg = (200*(1/stepperSetting))/(360);
  int steps = (int) (stepsPerDeg*deg);
  if (dataArray[1] == 1) {
    steps *= -1;
  }

  
  switch (stepper) {
    case 1:
      stepper1.enableStepper();
      stepper1.setupRelativeMoveInSteps(steps);
      break;
    case 2:
      stepper2.enableStepper();
      stepper2.setupRelativeMoveInSteps(steps);
      break;
  }
  running1 = true;
  running2 = true;

  return("Moving Stepper Degrees");

}

void moveStepperRev(byte dataLength, byte *dataArray) {
  
  byte stepper = dataArray[0];
  int rev = ((int *) (dataArray + 2))[0];
  double stepsPerRev = 200*(1/stepperSetting);
  int steps = (int) (stepsPerRev*rev);
  if (dataArray[1] == 1) {
    steps *= -1;
  }

  
  switch (stepper) {
    case 1:
      stepper1.enableStepper();
      stepper1.setupRelativeMoveInSteps(steps);
      break;
    case 2:
      stepper2.enableStepper();
      stepper2.setupRelativeMoveInSteps(steps);
      break;
  }
  running1 = true;
  running2 = true;

  return("Moving Stepper Revolutions");

}

void setStepperSpeed(byte dataLength, byte *dataArray) {
  int speedStepper = ((int *) (dataArray + 2))[0];
  byte stepper = dataArray[0];
  
  switch (stepper) {
    case 1:
      stepper1.setSpeedInStepsPerSecond(speedStepper);
      break;
    case 2:
      stepper1.setSpeedInStepsPerSecond(speedStepper);
      break;
  }
}

void moveStepperToPos(byte dataLength, byte *dataArray) {

  byte stepper = dataArray[0];
  int steps1;
  int steps2;
  int steps;
  int currentPosSteps = ((int *) (dataArray + 2))[0];
  int finalPosSteps = ((int *) (dataArray + 3))[0];
  bool longways = false;
  if (dataArray[1] == 1) {
    longways = true;
  }

  steps1 = currentPosSteps-finalPosSteps;
  steps2 = finalPosSteps-currentPosSteps;
  if(longways = true)
  {
      if((abs(steps1))>(abs(steps2)))
      {
        steps = steps1;
      }
      else
      {
        steps = steps2;
      }
  }
  else
  {
    if((abs(steps1))>(abs(steps2)))
      {
        steps = steps2;
      }
      else
      {
        steps = steps1;
      }
  }

  switch (stepper) {
    case 1:
      stepper1.enableStepper();
      stepper1.setupRelativeMoveInSteps(steps);
      break;
    case 2:
      stepper2.enableStepper();
      stepper2.setupRelativeMoveInSteps(steps);
      break;
  }
  running1 = true;
  running2 = true;

  return("Moving Stepper Position");

}
  
