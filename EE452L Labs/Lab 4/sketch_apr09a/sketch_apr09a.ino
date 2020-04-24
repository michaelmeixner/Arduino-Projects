#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float ctemp, ftemp;
int sensorRead;
const int sensorPin = A5, button = 8;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  analogReference(INTERNAL);
  pinMode(sensorPin, INPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(button) != HIGH){
    sensorRead = analogRead(sensorPin);
    delayMicroseconds(105);
    ctemp = (sensorRead*500)/1023;
    ftemp = (ctemp * 1.8) + 32;
    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
    lcd.setCursor(0,1);
    lcd.print(ftemp);
    delay(1000);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Set time:");
  delay(1000);
  lcd.clear();
}
