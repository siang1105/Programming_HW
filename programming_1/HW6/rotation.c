#include <stdio.h>
#include <stdint.h>
#include <math.h>
void rotate( double *x, double *y, double theta ){
    double x_tmp = *x;
    double y_tmp = *y;
    *x = x_tmp * cos(theta*(M_PI/180)) + y_tmp * sin(theta*(M_PI/180));
    *y = y_tmp * cos(theta*(M_PI/180)) + x_tmp * sin(theta*(M_PI/180));

}