#include <Stepper.h>

#define STEPS 32

Stepper stepper(STEPS, 8, 10, 9, 11);
int val = 0;

void setup() {

  Serial.begin(9600);
  stepper.setSpeed(200);
  
  // put your setup code here, to run once:

}

void loop() {

  if(Serial.available() > 0)
  {
    val = Serial.parseInt();
    stepper.step(val);
    Serial.println(val); // for debugging
  }
  
  // put your main code here, to run repeatedly:

}
