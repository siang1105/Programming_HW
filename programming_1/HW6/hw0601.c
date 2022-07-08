#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
int main()
{
    int64_t num = 0;
    int32_t position = 0;
    int32_t newValue = 0;
    printf("Please input an integer: ");
    scanf("%" PRIu64,&num);
    printf("The integer: %" PRIu64,num);
    printf("\n");
    uint8_t *ptr = (uint8_t *) &num;
    for( int32_t i = 0; i < 8; i++ )
    {
        printf("(%d) 0x%02X ",i+1,*(ptr + i));
    }
    printf("\n");
    while(1)
    {
        printf("Please enter the position (1-8, 0: End): ");
        scanf("%d",&position);
        if(position == 0)
        {
            break;
        }
        if( position < 0 || position > 8 )
        {
            printf("Invalid Input\n");
            return 0;
        }
        printf("Please enter the new value (0-255): ");
        scanf("%d",&newValue);
        if(newValue < 0 || newValue > 255)
        {
            printf("Invalid Input\n");
            return 0;
        }
        *(ptr + position - 1) = newValue;
        for( int32_t i = 0; i < 8; i++ )
        {
            printf("(%d) 0x%02X ",i+1,*(ptr + i));
        }
        printf("\n");
    }
    return 0;
}