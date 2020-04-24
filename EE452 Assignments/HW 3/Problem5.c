// Michael Meixner, HW 3
// Problem 5
#include <stdio.h>
#include <stdint.h>

uint8_t N;
uint8_t mask;

void setup()
{
    N = 0;
    mask = 0x0F;
}

void loop()
{
    printf("Enter a number.");
    scanf("%hhd", &N);
    printf("Number with mask: %hhd", N & mask);
}

void main() {}