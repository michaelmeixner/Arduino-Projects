// Basic audio testing
// Generate a tone and see how it sounds on the output
int frequency = 300, duration = 1000;
const int tonePin = 8, pot = A5;

int freqVal() {
  int v;
  v = analogRead(pot);
  v /= 4;
  return v;
}
void setup() {
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(tonePin, frequency, duration);
  noTone(tonePin);
  delay(1000);
}
