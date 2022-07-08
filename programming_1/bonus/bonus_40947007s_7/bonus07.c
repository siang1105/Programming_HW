#include <stdio.h>
int main()
{
    int n = 234;
    int nn = n;
    int count = 0;
    do{
        n = n / 10;
        count++;
    }while( n != 0 );
    printf("%d\n",count);
    int arr[count];
    for( int i = 0; i < count; i++ )
    {
        arr[i] = 0;
    }
    for( int i = 0; i < count; i++ )
    {
        arr[i] = nn % 10;
        nn = nn/10;
        if( nn == 0)
        {
            arr[i] = nn % ( count * 10 );
        }
    }
    for( int i = 0; i < count; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int product = 1;
    for( int i = 0; i < count; i++ )
    {
        product = product * arr[i];
    }
    int sum = 0;
    for( int i = 0; i < count; i++ )
    {
        sum = sum + arr[i];
    }
    printf("%d\n", product - sum);
    return 0;
}
