#include <stdio.h>
#include <stdint.h>

int max( int32_t a, int32_t b )
{
    int32_t c = a > b ? a : b;
    return c;
}
int main(){
    printf("%d\n",max(5,8));
    return 0;
}