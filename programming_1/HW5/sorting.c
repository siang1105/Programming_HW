#include <stdio.h>
#include <stdint.h>
void sorting (int32_t array[],int32_t array_size)
{
    int32_t odd = 0;
    int32_t even = 0;
    for( int32_t i = 0; i < array_size; i++ )
    {
        int32_t remainder = array[i]%2;
        if(remainder==0)
        {
        even++;
        }
        if(remainder==1)
        {
        odd++;
        }
    }

    int32_t odd_array[odd];
    for(int32_t i = 0; i < odd; i++ )
    {
        odd_array[i] = 0;
    }
    int32_t count = 0;
    for( int32_t i = 0; i < array_size; i++ )
    {
        int32_t remainder = array[i]%2;
        
        if( remainder == 1 )
        {
            odd_array[count] = array[i];
            count++;
        }
    }
    int32_t even_array[even];
    for(int32_t i = 0; i < even; i++ )
    {
        even_array[i] = 0;
    }
    count = 0;
    for( int32_t i = 0; i < array_size; i++ )
    {
        int32_t remainder = array[i]%2;
        if( remainder == 0 )
        {
            even_array[count] = array[i];
            count++;
        }
    }
    
    for( int32_t j = 0; j < odd; j++ )
        {
            for( int32_t i = j; i < odd; i++ )
            {
                if( odd_array[i] < odd_array[j] )
                    {
                        int32_t tmp = 0;
                        tmp = odd_array[j];
                        odd_array[j] = odd_array[i];
                        odd_array[i] = tmp;
                    }
            }
        }
        
    
    for( int32_t i = 0; i < odd; i++ )
    {
        printf("%d ",odd_array[i]);
    }
    

    
    for( size_t j = 0; j < even; j++ )
        {
            for( size_t i = j; i < even; i++ )
            {
                if( even_array[i] > even_array[j] )
                {
                    int32_t tmp = 0;
                    tmp = even_array[j];
                    even_array[j] = even_array[i];
                    even_array[i] = tmp;
                }
            }
        }
    
    for( int32_t i = 0; i < even; i++ )
    {
        printf("%d ",even_array[i]);
    }
    printf("\n");
}