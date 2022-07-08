#include <stdio.h>
#include <stdint.h>
#include "test.h"
#include "sorting.h"
int main()
{
    printf("Before:\n");
    for(int32_t i = 0; i < array_size; i++ )
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("After:\n");
    sorting(array,array_size);
    return 0;
}