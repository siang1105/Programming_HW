#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
void hanoi (int32_t m, int32_t source, int32_t target, int32_t spare)
{
    if (m == 1) 
    {
        printf("move disk 1 to rod %d\n",target);
    }
    else
    {
        hanoi(m - 1, source, spare, target);
        printf("move disk %d to rod %d\n",m,target);
        hanoi(m - 1, spare, target, source);
    }
    
}
