// Michael Meixner, HW 3
// Problem 3
#include <stdint.h>
#include <stdio.h>

uint8_t P;
uint8_t N;

void setup()
{
    P = 16;
    N = 0;
}

void loop()
{
    printf("Enter a number.");
    scanf("%hhd", &N);
    if(N == P)
    {
        printf("N equals P.");
    }
    else
    {
        printf("N does not equal P.");
    }
}

void main() {}