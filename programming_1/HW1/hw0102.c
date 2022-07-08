#include <stdio.h>
#include <stdint.h>
int main()
{
    int32_t a = 0;
    int32_t b = 0;
    int32_t c = 0;
    int32_t d = 0;
    int32_t e = 0;
    int32_t f = 0;
    printf("Please enter a 5-digits integer: ");
    scanf("%d", &a);
    b = a % 10;
    a /= 10;
    c = a % 10;
    a /= 10;
    d = a % 10;
    a /= 10;
    e = a % 10;
    a /= 10;
    f = a % 10;
    int32_t sum = b*c*d*e*f;
    printf("Result: %d", sum);
    
    return 0;
}
