/*
Code by @HuHamster
YouTube: www.youtube.com/@HuHamster
*/

#include <AccelStepper.h>

#define STEP_PIN 3
#define DIR_PIN 2

const int MICROSTEP_DIVIDER = 1;
const int STEPS_PER_REV_MOTOR = 200;
const int STEPS_PER_REV_ACTUAL = STEPS_PER_REV_MOTOR * MICROSTEP_DIVIDER;

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  stepper.setMaxSpeed(1000.0);
  stepper.setAcceleration(500.0);
}

void loop() {
  stepper.move(STEPS_PER_REV_ACTUAL);
  stepper.runToPosition();
  delay(1000);

  stepper.move(-(STEPS_PER_REV_ACTUAL * 1.5));
  
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  delay(1000);
}