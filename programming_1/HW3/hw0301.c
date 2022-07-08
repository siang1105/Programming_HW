#include<stdio.h>
#include<stdint.h>
int main()
{
    int32_t m = 0;
    int32_t n = 0;
    int32_t direction = 0;
    int32_t i = 0;
    int32_t j = 0;
    printf("Please enter the width :");
    scanf("%d",&m);
    printf("Please enter the height:");
    scanf("%d",&n);
    int32_t tornado[n][m];
    int32_t num = m*n;
    int32_t up = -1;
    int32_t right = m;
    int32_t down = n;
    int32_t left = -1;
    int32_t input = 1;
    while ( input != num + 1)
    {
        if( direction == 0 )
        {
            if( j == right )
            {
                direction = 1;
                up = up + 1;
                j--;
                i++;
            } 
            else
            {
                tornado[i][j] = input;
                input++;
                j++;
            }
        }
        if( direction == 1 )
        {
            if( i == down )
            {
                direction = 2;
                right = right - 1;
                i--;
                j--;
            }
            else
            {
                tornado[i][j] = input;
                input++;
                i++;
            }
        }
        if( direction == 2 )
        {
            if( j == left )
            {
                direction = 3;
                down = down - 1;
                j++;
                i--;
            }
            else
            {
                tornado[i][j] = input;
                input++;
                j--;
            }
        }
        if( direction == 3 )
        {
            if( i == up )
            {
                direction = 0;
                left = left + 1;
                i++;
                j++;
            }
            else
            {
                tornado[i][j] = input;
                input++;
                i--;
            }
        }
    }
    int32_t k = 0;
    int32_t mn = m*n;
    while( mn != 0 )
    {
        mn = mn / 10;
        k++;
    }
    for( i = 0; i < n; i++ )
    {
        for( j = 0; j < m; j++)
        {
        printf("%*d ",k,tornado[i][j]);
        }
        printf("\n");
    }
    return 0;
}