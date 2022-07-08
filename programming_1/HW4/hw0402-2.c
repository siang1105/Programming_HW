#include <stdio.h>
#include <stdint.h>
#include "hanoi.h"
int main()
{
    int32_t num;
    printf("Please enter the disk number (2-20): ");
    scanf("%d",&num);
    if( num > 20 || num < 2 )
    {
        printf("Invalid Input\n");
    }
    else
    {
        hanoi2(num);
    }
    return 0;
    
}