void setup() {
  Serial.begin(9600);

  stepper1.connectToPort(1);
  stepper1.setSpeedInStepsPerSecond(500);
  stepper1.setAccelerationInStepsPerSecondPerSecond(500);

}

void loop() {
      int steps = 10
      stepper1.enableStepper();
      stepper1.setupRelativeMoveInSteps(steps);
}
