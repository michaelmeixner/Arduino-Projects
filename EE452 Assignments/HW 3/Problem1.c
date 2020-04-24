// Michael Meixner, HW 3
// Problem 1
#include <stdio.h>

int mph, kph;

void setup()
{
    mph = 0;
    kph = 0;
}

void loop()
{
    scanf("%d", &mph);
    kph = mph / 1.609344;
    printf("Speed in KPH: %d", kph);
}

void main()
{

}