#include<stdio.h>
#include<stdint.h>
#include"taylor.h"
int main()
{
    int32_t k;
    printf("k-th order Taylor polynomial for e\n");
    printf("Please enter k: ");
    scanf("%d",&k);
    if( k < 1 )
    {
        printf("Invalid Input!\n");
    }
    printf("%d\n", taylor(k));
    return 0;
}