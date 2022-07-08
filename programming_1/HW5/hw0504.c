#include <stdio.h>
#include <stdint.h>
#include "linear.h"
int main()
{
    int32_t point;
    printf("Please enter tne point number: ");
    scanf("%d",&point);
    int32_t coordinate_x[point];
    int32_t coordinate_y[point];
    int32_t j = 0;
    for(int32_t i = 0; i < point; i++ )
    {
        coordinate_x[i] = 0;
    }
    for(int32_t i = 0; i < point; i++ )
    {
        coordinate_y[i] = 0;
    }
    
    for(int32_t i = 1; i <= point; i++ )
    {
        
        printf("Please enter point %d: ",i);
        scanf("%d %d",&coordinate_x[j],&coordinate_y[j]);
        j++;
    }
    printf("Regression Equation: ");
    linear(coordinate_x,coordinate_y,point);
    return 0;
}