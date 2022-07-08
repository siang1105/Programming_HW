#include <stdio.h>
int main()
{
    int numsSize = 4;
    int nums[4] = {1, 1, 2, 3};
    int output[numsSize];
    int count = 0;
    for( int i = 0; i < numsSize/2; i++ )
    {
        
        int freq;
        int val;
        freq = nums[2*i];
        val = nums[2*i+1];
        printf("%d",freq);
        printf("%d",val);
        printf("\n");
        for( int j = 0; j < freq; j++ )
        {
            output[count] = val;
            count++;
        }

        freq = 0;
        val = 0;
    }
    for(int i = 0; i < 4; i++)
    {
        printf("%d",output[i]);
    }
    return 0;
}