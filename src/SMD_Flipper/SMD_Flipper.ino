/*
 Control servos for SMD component flipper
 */

#include <Servo.h>

const uint16_t servo1_pin = 9;
const uint16_t servo2_pin = 10;
const uint16_t button_pin = 8;

Servo myservoA;  // create servo object to control a servo
Servo myservoB;  // create servo object to control a servo

uint16_t posA = 0;    // variable to store the servo position
uint16_t posB = 0;    // variable to store the servo position

void setup() {
  myservoA.write(posA);              // tell servo to go to position in variable 'pos'
  myservoB.write(posB);              // tell servo to go to position in variable 'pos'
  myservoA.attach(servo1_pin);  // attaches the servo on pin 9 to the servo object
  myservoB.attach(servo2_pin);  // attaches the servo on pin 9 to the servo object

  pinMode(servo1_pin, INPUT_PULLUP);
  pinMode(servo2_pin, INPUT_PULLUP);
  pinMode(button_pin, INPUT_PULLUP);

  // power servos
  pinMode(servo1_pin, OUTPUT);
  pinMode(servo2_pin, OUTPUT);
  goPos(0,0,800);
  // unpower servos
  pinMode(servo1_pin, INPUT_PULLUP);
  pinMode(servo2_pin, INPUT_PULLUP);
}

void loop() {
  if (buttonPressedDebounced()) {
    // power servos
    pinMode(servo1_pin, OUTPUT);
    pinMode(servo2_pin, OUTPUT);
    // do movement
    goPos(0,0,100);
    goPos(0,180,400);
    goPos(180,0,400);
    goPos(0,0,400);
    // unpower servos
    pinMode(servo1_pin, INPUT_PULLUP);
    pinMode(servo2_pin, INPUT_PULLUP);
  }
}

bool buttonPressedDebounced() {
  bool buttonPressed = (digitalRead(button_pin) == LOW);
  for (uint8_t i=0; i<10; i++) {
    delay(1);
    buttonPressed = buttonPressed && (digitalRead(button_pin) == LOW);
  }
  return buttonPressed;
}

void goPos(uint16_t a,uint16_t b,uint16_t delayForMovement) {
  myservoA.write(a);
  myservoB.write(b);
  delay(delayForMovement);
}
