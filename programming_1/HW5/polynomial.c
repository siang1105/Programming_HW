#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void printPoly (int32_t coefficients[], int32_t size) {
    int32_t degree = size - 1;
    int32_t i = 0;

    do {
        if (coefficients[i] == 0) {
            i++;
            degree--;
            continue;
        }

        if (i == 0) {
            if (coefficients[i] < 0) {
                printf("-");
            }
        } else {
            if (coefficients[i] < 0) {
                printf("- ");
            } else {
                printf("+ ");
            }
        }

        if (degree == 0) {
            printf("%d ", abs(coefficients[i]));
        } else if (degree == 1) {
            printf("%dx ", abs(coefficients[i]));
        } else {
            printf("%dx^%d ", abs(coefficients[i]), degree);
        }

        i++;
        degree--;
    } while (degree != -1);

    printf("\n");
}

void addition (int32_t pol01[],int32_t pol02[],int32_t p1,int32_t p2)
{
    if(p1 > p2)
    {
        int32_t add_pol[p1];
        for(int32_t i = 0; i < p1; i++)
        {
            add_pol[i] = 0;//初始化
        }
        int32_t j = 0;
        for(int32_t i = p1-p2; i < p1; i++)
        {
            add_pol[i] = pol01[i] + pol02[j];
            j++;
        }
        for(int32_t i = 0; i < p1-p2; i++ )
        {
            add_pol[i] = pol01[i];
        }
        
        
        printPoly(add_pol, p1);
    }
    if(p1 < p2)
    {
        int32_t add_pol[p2];
        for(int32_t i = 0; i < p2; i++)
        {
            add_pol[i] = 0;//初始化
        }
        int32_t j = 0;
        for(int32_t i = p2-p1; i < p2; i++ )
        {
            add_pol[i] = pol01[j] + pol02[i];
            j++;
        }
        for(int32_t i = 0; i < p2-p1; i++)
        {
            add_pol[i] = pol02[i];
        }
        printPoly(add_pol, p2);

    }
    if(p1 == p2)
    {
        int32_t add_pol[p1];
        for(int32_t i = 0; i < p1; i++ )
        {
            add_pol[i] = pol01[i] + pol02[i];
        }
        
        printPoly(add_pol, p1);
    }
}

void subtraction (int32_t pol01[],int32_t pol02[],int32_t p1,int32_t p2)
{
    if(p1 > p2)
    {
        int32_t sub_pol[p1];
        for(int32_t i = 0; i < p1; i++)
        {
            sub_pol[i] = 0;//初始化
        }
        int32_t j = 0;
        for(int32_t i = p1-p2; i < p1; i++)
        {
            sub_pol[i] = pol01[i] - pol02[j];
            j++;
        }
        for(int32_t i = 0; i < p1-p2; i++ )
        {
            sub_pol[i] = pol01[i];
        }

        printPoly(sub_pol, p1);
    }
    if(p1 < p2)
    {
        int32_t sub_pol[p2];
        for(int32_t i = 0; i < p2; i++)
        {
            sub_pol[i] = 0;//初始化
        }
        int32_t j = 0;
        for(int32_t i = p2-p1; i < p2; i++ )
        {
            sub_pol[i] = pol01[j] - pol02[i];
            j++;
        }
        for(int32_t i = 0; i < p2-p1; i++)
        {
            sub_pol[i] = pol02[i];
        }
        printPoly(sub_pol, p2);
    }
    if(p1 == p2)
    {
        int32_t sub_pol[p1];
        for(int32_t i = 0; i < p1; i++ )
        {
            sub_pol[i] = pol01[i] - pol02[i];
        }
        
        printPoly(sub_pol, p1);
        
    }
}
void multiplication (int32_t pol01[],int32_t pol02[],int32_t p1,int32_t p2)
{
    if(p1 > p2)
    {
        int32_t mul_pol[p1+p2-1];
        for(int32_t i = 0; i < p1+p2-1; i++ )
        {
            mul_pol[i] = 0;
        }
        for(int32_t i = 0; i < p2; i++ )
        {
            for(int32_t j = 0; j < p1; j++ )
            {
                mul_pol[i+j] += pol02[i]*pol01[j];
            }
        }
        printPoly(mul_pol, p1+p2-1);
        
    }
    if(p2 > p1)
    {
        int32_t mul_pol[p1+p2-1];
        for(int32_t i = 0; i < p1+p2-1; i++ )
        {
            mul_pol[i] = 0;
        }
        for(int32_t i = 0; i < p1; i++ )
        {
            for(int32_t j = 0; j < p2; j++ )
            {
                mul_pol[i+j] += pol02[j]*pol01[i];
            }
        }
        printPoly(mul_pol, p1+p2-1);
        
    }
    if(p1 == p2)
    {
        int32_t mul_pol[p1+p2-1];
        for(int32_t i = 0; i < p1+p2-1; i++ )
        {
            mul_pol[i] = 0;
        }
       
        for(int32_t i = 0; i < p2; i++ )
        {
            for(int32_t j = 0; j < p1; j++ )
            {
                mul_pol[i+j] += pol02[i]*pol01[j];
            }
        }
        
        printPoly(mul_pol, p1+p2-1);
        
    }
}