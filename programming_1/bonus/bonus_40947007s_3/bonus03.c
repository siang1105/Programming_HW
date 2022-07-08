#include <stdio.h>
int main()
{
    int nums[6] = {1, 2, 3, 1, 1, 3};
    int count = 0;
    for( int i = 0; i < 6; i++ )
    {
        for( int j = 0; j < 6; j++ )
        {
            if( nums[i] == nums[j])
            {
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}