#include "SerialSlave.h"

#define ADDRESS 15

waitTime = 100

void setup() {
  serialSlave.open(9600, ADDRESS, 40);
}

void loop() {
    functionThatTurnsOnLED(500)
}

Func sayHi;

Callable callables[] = {
  {"say_hi", sayHi},
  {"add", add},
  {"blinkLED", functionThatTurnsOnLED}
};

byte numberOfExternalCallables = sizeof(callables) / sizeof(Callable);

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
