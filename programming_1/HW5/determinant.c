#include <stdio.h>
#include <stdint.h>
int32_t determinant (int32_t matrix[4][4])
{
    int32_t A = (matrix[2][2])*(matrix[3][3])-(matrix[2][3])*(matrix[3][2]);
    int32_t B = (matrix[2][1])*(matrix[3][3])-(matrix[2][3])*(matrix[3][1]);
    int32_t C = (matrix[2][1])*(matrix[3][2])-(matrix[2][2])*(matrix[3][1]);
    int32_t D = (matrix[2][2])*(matrix[3][3])-(matrix[2][3])*(matrix[3][2]);
    int32_t E = (matrix[2][0])*(matrix[3][3])-(matrix[2][3])*(matrix[3][0]);
    int32_t F = (matrix[2][0])*(matrix[3][2])-(matrix[2][2])*(matrix[3][0]);
    int32_t G = (matrix[2][1])*(matrix[3][3])-(matrix[2][3])*(matrix[3][1]);
    int32_t H = (matrix[2][0])*(matrix[3][3])-(matrix[2][3])*(matrix[3][0]);
    int32_t I = (matrix[2][0])*(matrix[3][1])-(matrix[3][0])*(matrix[2][1]);
    int32_t J = (matrix[2][1])*(matrix[3][2])-(matrix[2][2])*(matrix[3][1]);
    int32_t K = (matrix[2][0])*(matrix[3][2])-(matrix[2][2])*(matrix[3][0]);
    int32_t L = (matrix[2][0])*(matrix[3][1])-(matrix[3][0])*(matrix[2][1]);
    int32_t one = (matrix[1][1])*A - (matrix[1][2])*B + (matrix[1][3])*C;
    int32_t two = (matrix[1][0])*D - (matrix[1][2])*E + (matrix[1][3])*F;
    int32_t three = (matrix[1][0])*G - (matrix[1][1])*H + (matrix[1][3])*I;
    int32_t four = (matrix[1][0])*J - (matrix[1][1])*K + (matrix[1][2])*L;
    int32_t answer = (matrix[0][0])*one - (matrix[0][1])*two + (matrix[0][2])*three - (matrix[0][3])*four;
    return answer;


    
    
    
}