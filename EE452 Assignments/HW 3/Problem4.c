// Michael Meixner, HW 3
// Problem 4
#include <stdio.h>
#include <stdint.h>

uint8_t N1;
uint8_t N2;

void setup()
{
    N1 = 0;
    N2 = 0;
}

void loop()
{
    printf("Enter the first number: ");
    scanf("%hhd", &N1);
    printf("Enter the second number: ");
    scanf("%hhd", &N2);
    printf("Sum: %hhd", N1 + N2);
    printf("Difference: %hhd", N2 - N1);
    printf("Product: %hhd", N1 * N2);
    printf("Quotient: %hhd", N2 / N1);
}

void main() {}