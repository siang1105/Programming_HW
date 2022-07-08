#include <stdio.h>
#include <stdint.h>
int main()
{
    int32_t a = 0;
    int32_t b = 0;
    int32_t c = 0;
    
    printf("Please enter a quadratic polynomial (a,b,c):\n");

    if(scanf("%d %d %d" , &a,&b,&c )!=3)
    {
      printf( "Wrong Input!\n" );
       return 0;
    }
    
    int sum = (b*b)-4*a*c;
    if(sum>0)
    {
        printf("Two distinct real roots.\n");
    }
    else if(sum==0)
    {
        printf("One real root.\n");
    }
    else if(sum<0)
    {
        printf("No real roots.\n");
    }
   
   
    return 0;
}