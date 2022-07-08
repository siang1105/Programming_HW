#include<stdio.h>
#include<stdint.h>
int main ()
{
    uint32_t a,r;
    printf("Please enter a natural number :");
    scanf("%d",&a);
    if( a<=0 )
    {
        printf("invalid input\n");
        return 0;
    }
    int32_t k = 0;
    int32_t arr[10];
    while ( a!=0 )
    {
        arr[k]=a%10;
        a/=10;
        k++;
    }
    printf("%d",arr[0]);
    int32_t i = 0;
    for( i = k-2; i > 0; i--)
    {
        printf("%d",arr[i]);
    }
    printf("%d",arr[k-1]);
    printf("\n");
    return 0;
}
