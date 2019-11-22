#include "SerialSlave.h"

#define ADDRESS 15

waitTime = 100

void setup() {
  serialSlave.open(9600, ADDRESS, 40);
    stepper1.connectToPort(6);
  stepper1.setSpeedInStepsPerSecond(500);
  stepper1.setAccelerationInStepsPerSecondPerSecond(500);
}

void loop() {
    moveStepper(dLegnth, dArray)
}

Func sayHi;

Callable callables[] = {
  {"say_hi", sayHi},
  {"add", add},
  {"blinkLED", functionThatTurnsOnLED}
};

//Callable callables[] = {
//Your callables Here
//{"short_name", functiontoRunOnTheArduino}
//};

byte numberOfExternalCallables = sizeof(callables) / sizeof(Callable);

void moveStepper(byte dataLength, byte *dataArray) {

  byte stepper = dataArray[0];
  int steps = ((int *) (dataArray + 2))[0];

  if (dataArray[1] == 1) {
    steps *= -1;
  }

//Example that returns the sum of some data (%256)
void add(byte dataLength, byte *dataArray) {
  byte sum = 0;
  for(byte i = 0; i < dataLength; i++){
    sum += dataArray[i];
  }
  returns(sum);
}

//Example that returns a string
void sayHi(byte dataLength, byte *dataArray) {
  returns("I can say hi!"); n
}


void functionThatTurnsOnLED(int blinkCount) {
    for (byte count = 0; count< blinkCount; count++) {

        digitalWrite(8, HIGH)
        print("LED On")
        delay(waitTime)
        digitalWrite(8, LOW)
        print("LED Off")
        delay(waitTime)
    }

}
