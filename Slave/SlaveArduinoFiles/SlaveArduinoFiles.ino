#include "SerialSlave.h"
#include "SpeedyStepper.h"

#define ADDRESS 17

SpeedyStepper stepper1;
SpeedyStepper stepper2;

bool running1;
bool running2;

void setup() {
  serialSlave.open(115200, ADDRESS, 40);

  stepper1.connectToPort(2);
  stepper1.setSpeedInStepsPerSecond(500);
  stepper1.setAccelerationInStepsPerSecondPerSecond(500);
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
  if (running2 == false && running1 == false) {

    blinkLED(0, 0);
  }
}

Func moveStepper;
Func stopStepper;

Callable callables[] = {
  {"move_stepper", moveStepper},
  {"disable", disable},
  {"blinkLED", blinkLED}
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

  returns("Moving Stepper");

//setupRelativeMoveInSteps
}

void blinkLED(byte dataLength, byte *dataArray) {
  
  pinMode(23, OUTPUT);
  digitalWrite(23, HIGH);
  delay(200);
  digitalWrite(23, LOW);
  
}

void disable(byte dataLength, byte *dataArray) {
  stepper1.disableStepper();
}
