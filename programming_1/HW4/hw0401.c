#include<stdio.h>
#include<stdint.h>
#include"roman.h"
int main()
{
    int32_t input;
    printf("please enter a integer(1-3000): ");
    scanf("%d",&input);
    if( input<1 || input>3000)
    {
        printf("invalid input\n");
        return 0;
    }
    roman(input);
    return 0;
}