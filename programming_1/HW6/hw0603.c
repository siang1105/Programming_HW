#include <stdio.h>
#include <stdint.h>
#include "rotation.h"
int main()
{
    double x = 0;
    double y = 0;
    double theta = 0;
    printf("Please enter a point: ");
    scanf("%lf %lf",&x,&y);
    printf("Please enter theta (0-360): ");
    scanf("%lf",&theta);
    if( theta < 0 || theta > 360)
    {
        printf("Invalid Input\n");
        return 0;
    }
    rotate( &x, &y, theta );
    printf("%.1lf %.1lf\n",x,y);
    return 0;
}