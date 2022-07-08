#include<stdio.h>
#include<stdint.h>

int32_t factorial(int32_t input2)
{
    int32_t num;
    int32_t sum = 1;
    int32_t i;
    num = input2;
    for(i=1;i<=num;i++)
    {
        sum *= i;
    }
        return sum;
}

int32_t taylor(int32_t k)
{
    int32_t sum = 2;

    for (int32_t i = 2; i < k + 1; i++) {
        sum += 1 / factorial(i);
    }

    return sum;
}