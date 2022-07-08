#include <stdio.h>
#include <stdint.h>
#include "bullsAndCows.h"


int main()
{
    int32_t answer[4];
    printf("Bulls and Cows Game\n");
    bullsAndCows(answer);
    
    return 0;
}