#include <stdio.h>
#include <stdint.h>
void project( double *x, double *y, double *z, int32_t a, int32_t b, int32_t c, int32_t d ){
    double x_val = *x;
    double y_val = *y;
    double z_val = *z;
    double t;
    t = (-(a * x_val + b * y_val + c * z_val + d))/(a * a + b * b + c * c);
    *x = x_val + a*t;
    *y = y_val + b*t;
    *z = z_val + c*t;
    
}