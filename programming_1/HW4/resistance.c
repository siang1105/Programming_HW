#include<stdio.h>
#include<stdint.h>
double resistance (int32_t r, int32_t n)
{
    if (n == 1) return 2 * (double) r;
    int32_t numberOfR = n;
    double sum = r;
    for( int32_t i = 0; i < numberOfR; i++ )
    {
        if (i != 0) sum = (sum * r) / (sum + r);
        sum += r;
    }
    return sum;
}
