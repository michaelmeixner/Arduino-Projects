//Servo + Stepper Motor Control
//Michael Meixner

#include <Servo.h>
#include <AccelStepper.h>
#define HALFSTEP 8

// Motor pin definitions
#define motorPin1  3     // IN1 on the ULN2003 driver 1
#define motorPin2  4     // IN2 on the ULN2003 driver 1
#define motorPin3  5     // IN3 on the ULN2003 driver 1
#define motorPin4  6     // IN4 on the ULN2003 driver 1

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);


Servo myServo; //create servo object to control a servo; 12 servo objects can be created on most boards
int position = 0; //variable to store servo position

void setup() {
  // put your setup code here, to run once:
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(100.0);
  stepper1.setSpeed(200);
  stepper1.moveTo(20000);
  myServo.attach(10); //attaches servo on pin 10 to the servo object
  Serial.begin(9600);
}

void loop() {
  for (position = 0; position <= 180; position += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myServo.write(position);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (position = 180; position >= 0; position -= 1) { // goes from 180 degrees to 0 degrees
    myServo.write(position);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(-stepper1.currentPosition());
  }
  stepper1.run();
}
