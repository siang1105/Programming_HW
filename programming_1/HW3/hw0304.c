#include<stdio.h>
#include<stdint.h>
#include<math.h>


int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    double s = 0;
    double t = 0;
    double integral = 0;
    double i = 0;
    double sum = 0;
    double finalSum = 0;
    int32_t n = 0;
    double x = 0;
    printf("Please enter a quadratic polynomial (ax^2+bx+c):\n");
    scanf("%lf %lf %lf",&a,&b,&c);
    if ( a == 0 )
    {
        printf("error\n");
        return 0;
    }
    if( a == 1 )
    {
        printf("x^2");
    }
    else if( a == -1 )
    {
        printf("-x^2");
    }
    else if( a == 0 )
    {
        printf("error");
    }
    else if( a != 1 || a != -1)
    {
        printf("%lfx^2",a);
    }
    if( b == 1 )
    {
        printf("+x");
    }
    else if( b == -1 )
    {
        printf("+(-x)");
    }
    else if( b != 0 )
    {
        printf("+%lfx",b);
    }
    if( c != 0 )
    printf("+%lf",c);
    printf("\n");
    printf("Please enter the interval [s,t]:\n");
    scanf("%lf,%lf",&s,&t);
    if( s>t )
    {
        printf("invalid input,t must be larger than s.\n");
        return 0;
    }
    integral = ((a/3)*t*t*t+(b/2)*t*t+c*t)-((a/3)*s*s*s+(b/2)*s*s+c*s);
    printf("The integral:%lf\n",integral);
    for( n=2; n<=65536; n=n*2)
    {
        finalSum = 0;
        for( i=0; i<n; i++)
        {
            x = (s + ((t-s)/n)*i);
            sum = (a*(s + ((t-s)/n)*i)*(s + ((t-s)/n)*i)+b*(s + ((t-s)/n)*i)+c)*((t-s)/n);
            finalSum+=sum;
        }
        printf("The Riemann sum of n= %d: %lf\n",n,finalSum);
    }


}