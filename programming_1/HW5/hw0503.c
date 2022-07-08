#include <stdio.h> 
#include <stdint.h>
#include "polynomial.h"
int main()
{
    int32_t p1 = 0;
    int32_t p2 = 0;
    printf("Please enter p1 degree: ");
    scanf("%d",&p1);
    int32_t coefficients1[p1+1];
    printf("Please enter p1 coefficients: ");
    for(int32_t i = 0; i < p1+1; i++ )
    {
    scanf("%d",&coefficients1[i]);
    }
    printf("Please enter p2 degree: ");
    scanf("%d",&p2);
    int32_t coefficients2[p2+1];
    printf("Please enter p2 coefficients: ");
    for(int32_t i = 0; i < p2+1; i++ )
    {
    scanf("%d",&coefficients2[i]);
    }
    
    printf("p1: ");
    printPoly(coefficients1, p1 + 1);
    
    printf("p2: ");
    printPoly(coefficients2, p2 + 1);
    
    printf("p1 + p2: ");
    addition(coefficients1,coefficients2,p1+1,p2+1);
    printf("p1 - p2: ");
    subtraction(coefficients1,coefficients2,p1+1,p2+1);
    printf("p1 * p2: ");
    multiplication (coefficients1,coefficients2,p1+1,p2+1);
   return 0;
    

}