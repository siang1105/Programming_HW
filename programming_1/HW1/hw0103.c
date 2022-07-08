#include <stdio.h>
#include <stdint.h>
int main ()
{
    float g = 0;
    float t = 0;
    printf("Please enter the acceleration due to gravity: ");
    scanf("%f", &g);
    printf("Please enter the time (s): ");
    scanf("%f", &t);
    float v = g*t;
    float h = g*t*t/2;
    printf("Final velocity: %f m/s\n", v);
    printf("The altitude: %f m",h);

    return 0;
}