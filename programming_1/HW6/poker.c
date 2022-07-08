#include <stdio.h>
#include <stdint.h>
void print_card( const uint8_t player[13] )
{
    for( int32_t i = 0; i < 13; i++ )
    {
        printf("%d ",player[i]);
    }
    printf("\n");
}
int32_t sort_card( uint8_t player[13], int32_t ( * compare)( int32_t a,int32_t b ) )
{
    for( int32_t i = 0; i < 13; i++ )
    {
        for( int32_t j = i; j < 13; j++ )
        {
            if( compare ( player[i], player[j] ))
            {
                int32_t tmp;
                tmp = player[j];
                player[j] = player[i];
                player[i] = tmp;
            }
        }
    }

    return 1;
}