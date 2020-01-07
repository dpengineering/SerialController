//      ******************************************************************
//      *                                                                *
//      *                 Header file for Slave.ino                      *
//      *                                                                *
//      *           Copyright (c) Josh Benson and Pratik Gupta           *
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
  {"blinkLED", blinkLED},
  {"toggleLED", toggleLED},
  {"moveStepperPosition", moveStepperPosition}
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
//setupRelativeMoveInSteps
  running1 = true;
  running2 = true;

  return("Moving Stepper");

//setupRelativeMoveInSteps
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


void disable(byte dataLength, byte *dataArray) {
  stepper1.disableStepper();
  stepper2.disableStepper();
}


void moveMultiSteppers(byte dataLength, byte *dataArray) {

  byte stepper = dataArray[0];
  int steps = ((int *) (dataArray + 2))[0];

  
  
}
