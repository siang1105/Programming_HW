#include <stdio.h>
#include <stdint.h>
#include "projection.h"
int main(){
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t d;
    double x;
    double y;
    double z;
    printf("Please enter the plane: ");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("The plane is ");
    if( a == 1 )
        {
            printf("x ");
        }
    if( a == -1 )
    {
        printf("-x ");
    }
    if( a != 0 && a != 1 && a != -1 )
    {
        printf("%dx ",a);
    }
    if( b == 1 )
        {
            if( a != 0 )
            {
                printf("+");
            }
            printf(" y ");
        }
    if( b != 0 && b > 0 && b != 1 )
        {
        if( a != 0 )
            {
                printf("+");
            }
        printf(" %dy ",b);
        }
    if( b == -1 )
    {
        printf("-y ");
    }
    if( b < 0 && b != -1 )
    {
        printf("%dy ",b);
    }
    if( c == 1 )
        {
            if( b != 0 )
            {
                printf("+");
            }
            printf(" z ");
        }
    if( c != 0 && c > 0 && c != 1 )
    {
        if( b != 0 )
            {
                printf("+");
            }
        printf(" %dz ",c);
    }
    if( c == -1 )
    {
        printf("-z ");
    }
    if( c < 0 && c != -1 )
    {
        printf("%dz ",c);
    }
    if( d != 0 && d > 0 )
    {
        if( c != 0 )
            {
                printf("+");
            }
        printf(" %d ",d);
    }
    if( d < 0 )
    {
        printf("%d ",d);
    }
    printf("= 0\n");
    printf("Please enter the point: ");
    scanf("%lf %lf %lf",&x,&y,&z);
    project( &x, &y, &z, a, b, c, d );
    printf("The projection is (%.2lf,%.2lf,%.2lf)\n",x,y,z);
    return 0;
}