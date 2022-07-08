#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "redoAndUndo.h"
int main()
{   
    int32_t input = 1;
    while( input != 0 )
    {
        printf("input: ");
        scanf("%d",&input);
        redoAndundo(input);
    }
    // printf("Result: ");
    // printArr();
    // printf("\n");
    return 0;
}