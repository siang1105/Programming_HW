#include <stdio.h>
#include <stdint.h>
void linear (int32_t coordinate_x[],int32_t coordinate_y[],int32_t point)
{
    int32_t x_sum = 0;
    int32_t y_sum = 0;
    int32_t x_aver = 0;
    int32_t y_aver = 0;
    double mole = 0;//分子
    double deno = 0;//分母
    double b = 0;
    double a = 0;
    for(int32_t i = 0; i < point; i++ )
    {
        x_sum += coordinate_x[i];
    }
    x_aver = x_sum/point;
    for(int32_t i = 0; i < point; i++ )
    {
        y_sum += coordinate_y[i];
    }
    y_aver = y_sum/point;
    for(int32_t i = 0; i < point; i++ )
    {
        deno += (coordinate_x[i] - x_aver)*(coordinate_x[i] - x_aver);
    }
    for(int32_t i = 0; i < point; i++ )
    {
        mole += (coordinate_x[i] - x_aver)*(coordinate_y[i] - y_aver);
    }
    b = mole/deno;
    a = y_aver - (b*x_aver);
    printf("y = %.2f x + %.2f\n",b,a);

}