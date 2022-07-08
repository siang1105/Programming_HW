#include <stdio.h>
int main()
{
    int n = 3;
    int numsSize = 6;
    int nums[6] = {2, 5, 1, 3, 4, 7};
    int arr_x[n];
    int arr_y[n];
    int output[numsSize];
    int count = n;
    for( int i = 0; i < n; i++ )
    {
        arr_x[i] = nums[i];
        arr_y[i] = nums[count];
        count++;
    }
    for( int i = 0; i < n; i++ )
    {
        printf("%d",*(arr_x + i));
    }
    printf("\n");
    for( int i = 0; i < n; i++ )
    {
        printf("%d",*(arr_y + i));
    }
    printf("\n");
    int i = 0;
    int j = 0;
    for( i = 0; i < n; i++ )
    {
        output[j] = arr_x[i];
        j++;
        output[j] = arr_y[i];
        j++;
    }
    
   for( int i = 0; i < numsSize; i++ )
   {
       printf("%d",*(output+i));
   }
   printf("\n");
   return 0;
}