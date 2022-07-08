#include <stdio.h>
#include <stdint.h>
#include"resistance.h"
int main()
{
    int32_t num;
    int32_t n;
    printf("Please enter the resistance (1-100):");
    scanf("%d",&num);
    if( num < 1 || num > 100 )
    {
        printf("Invalid Input!\n");
    }
    printf("Please enter n (1-100):");
    scanf("%d",&n);
    if( n < 1 || n > 100 )
    {
        printf("Invalid Input!\n");
    }
    printf("Ans: %f\n",resistance(num,n));
    return 0;
}