/*
 Direct servo control by turning hardcoded PWM signal using delayMicroseconds().
 This is to control the SMD component flipper.
*/

const uint16_t servo1_pin = 0;
const uint16_t servo2_pin = 1;
const uint16_t button_pin = 2;

// Theoretical values
/*
#define MICROSECONDS_FOR_180 2000
#define MICROSECONDS_FOR_0 1000
#define MICROSECONDS_FOR_CYCLE 20000
*/
// Practical values
#define MICROSECONDS_FOR_180 2400
#define MICROSECONDS_FOR_0 500
#define MICROSECONDS_FOR_CYCLE 20600

void setup() {
  pinMode(servo1_pin, OUTPUT);
  pinMode(servo2_pin, OUTPUT);
  pinMode(button_pin, INPUT_PULLUP);
  digitalWrite(servo1_pin, LOW);
  digitalWrite(servo2_pin, LOW);
}

void loop() {
  if (digitalRead(button_pin) == LOW) {
    servoApply(MICROSECONDS_FOR_0,MICROSECONDS_FOR_180,600);
    servoApply(MICROSECONDS_FOR_180,MICROSECONDS_FOR_0,600);
    servoApply(MICROSECONDS_FOR_0,MICROSECONDS_FOR_0,800);
  }
}

void servoApply(uint32_t servoOnTime1, uint32_t servoOnTime2, uint32_t durationMS) {
  const uint32_t cycles = durationMS * 1000UL / MICROSECONDS_FOR_CYCLE;
  const uint32_t filltime = MICROSECONDS_FOR_CYCLE - servoOnTime1 - servoOnTime2;
  for(uint32_t i=0; i<cycles; i++) {
    digitalWrite(servo1_pin, HIGH);
    delayMicroseconds(servoOnTime1);
    digitalWrite(servo1_pin, LOW);
    digitalWrite(servo2_pin, HIGH);
    delayMicroseconds(servoOnTime2);
    digitalWrite(servo2_pin, LOW);
    delay(filltime/1000);
    delayMicroseconds(filltime%1000);
  }
}
