// Michael Meixner, EE452 Lab 4
float temp, fTemp;
int sensorRead;
int sensorPin = A5;
const int heat = 9, fan = 8, AC = 10;
void setup() {
  // put your setup code here, to run once:
  analogReference(INTERNAL);
  Serial.begin(9600);
  pinMode(heat, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(AC, OUTPUT);
  digitalWrite(AC, LOW);
  digitalWrite(fan, LOW);
  digitalWrite(heat, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorRead = analogRead(sensorPin);
  delayMicroseconds(104);
  temp = sensorRead / 9.3; //9.3 bits per 10 mV
  Serial.println(temp);
  fTemp = (temp * 9/5) + 32;
  if(fTemp > 75){
    digitalWrite(AC, HIGH);
  } else if(fTemp > 65 && fTemp < 75) {
    digitalWrite(fan, HIGH);
  } else {
    digitalWrite(heat, HIGH);
  }
  delay(20000);
  digitalWrite(AC, LOW);
  digitalWrite(fan, LOW);
  digitalWrite(heat, LOW);
}
