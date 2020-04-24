// Michael Meixner, EE452 Lab 2
#include <Arduino.h>
int N1, N2, result, choice;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(50000);
  Serial.println("Enter first integer: ");
  N1 = Serial.parseInt();
  Serial.println(N1);
  Serial.setTimeout(50000);
  Serial.println("Enter second integer: ");
  N2 = Serial.parseInt();
  Serial.println(N2);
  Serial.setTimeout(50000);
  Serial.println("Which operation would you like performed?");
  Serial.println("Add: enter '1'");
  Serial.println("Subract: enter '2'");
  Serial.println("Multiply: enter '3'");
  Serial.println("Divide: enter '4'");
  Serial.println("AND: enter '5'");
  Serial.println("OR: enter '6'");
  Serial.println("XOR: enter '7'");
  choice = Serial.parseInt();
  Serial.setTimeout(50000);
  switch(choice)
  {
    case 1:
      result = N1 + N2;
      Serial.println("Sum:");
      Serial.println(result);
      break;
    case 2:
      result = N2 - N1;
      Serial.println("Difference:");
      Serial.println(result);
      break;
    case 3:
      result = N1 * N2;
      Serial.println("Product:");
      Serial.println(result);
      break;
    case 4:
      result = N2 / N1;
      Serial.println("Quotient:");
      Serial.println(result);
      break;
    case 5:
      result = N1 && N2;
      Serial.println("AND result:");
      Serial.println(result);
      break;
    case 6:
      result = N1 || N2;
      Serial.println("OR result:");
      Serial.println(result);
      break;
    case 7:
      result = N1 ^ N2;
      Serial.println("XOR result:");
      Serial.println(result);
      break;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
