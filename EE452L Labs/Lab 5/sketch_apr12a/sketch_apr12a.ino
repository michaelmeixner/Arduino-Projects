// Michael Meixner, EE452L Lab 5
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int number = 1, window = 1;
int buttonCounter = 0, buttonState = 0, lastButtonState = 0;
const int button = 8;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  analogReference(INTERNAL);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if((buttonCounter %2) == 0) {
    window = 1;
  } else {
    window = 2;
  }
  lcd.setCursor(0, 0);
  lcd.print("Number: ");
  lcd.print(number);
  lcd.setCursor(0, 1);
  lcd.print("Window: ");
  lcd.print(window);
  buttonState = digitalRead(button);
  if(buttonState != lastButtonState) {
    if(buttonState == HIGH) {
      buttonCounter++;
      number++;
      delay(1000);
    }
    else {
      return;
    }
    delay(50);
  }
}
