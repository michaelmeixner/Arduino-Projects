// Michael Meixner, EE452 Lab 3
const int EWgreen = 8, EWyellow = 9, EWred = 10, NSgreen = 11, NSyellow = 12, NSred = 13;
const int buttonPin = 3;
int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(EWgreen, OUTPUT);
  pinMode(EWyellow, OUTPUT);
  pinMode(EWred, OUTPUT);
  pinMode(NSgreen, OUTPUT);
  pinMode(NSyellow, OUTPUT);
  pinMode(NSred, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if(buttonState == LOW)
  {
    digitalWrite(EWgreen, LOW);
    digitalWrite(EWyellow, LOW);
    digitalWrite(NSgreen, LOW);
    digitalWrite(NSyellow, LOW);
    digitalWrite(EWred, HIGH);
    digitalWrite(NSred, HIGH);
    delay(20000);
    digitalWrite(EWred, LOW);
    digitalWrite(NSred, LOW);
  } else {
    digitalWrite(EWgreen, HIGH);
    digitalWrite(NSred, HIGH);
    delay(25000);
    digitalWrite(EWgreen, LOW);
    digitalWrite(EWyellow, HIGH);
    delay(5000);
    digitalWrite(NSred, LOW);
    digitalWrite(EWyellow, LOW);
    digitalWrite(EWred, HIGH);
    digitalWrite(NSgreen, HIGH);
    delay(20000);
    digitalWrite(NSgreen, LOW);
    digitalWrite(NSyellow, HIGH);
    delay(4000);
    digitalWrite(EWred, LOW);
    digitalWrite(NSyellow, LOW);
  }
}
