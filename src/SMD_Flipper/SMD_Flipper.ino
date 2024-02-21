/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservoA;  // create servo object to control a servo
Servo myservoB;  // create servo object to control a servo
// twelve servo objects can be created on most boards

uint16_t posA = 0;    // variable to store the servo position
uint16_t posB = 0;    // variable to store the servo position

void setup() {
  myservoA.write(posA);              // tell servo to go to position in variable 'pos'
  myservoB.write(posB);              // tell servo to go to position in variable 'pos'
  myservoA.attach(0);  // attaches the servo on pin 9 to the servo object
  myservoB.attach(1);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  goPos(0,180);
  delay(100);
  goPos(180,0);
  delay(100);
  goPos(0,0);
  delay(1000);
}

void goPos(uint16_t a,uint16_t b) {
  while((posA!=a)||(posB!=b)) {
    if(posA>a) posA--;
    if(posA<a) posA++;
    if(posB>b) posB--;
    if(posB<b) posB++;
    myservoA.write(posA);
    myservoB.write(posB);
    delay(3);
  }
}
