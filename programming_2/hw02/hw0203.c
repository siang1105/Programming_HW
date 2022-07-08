#include <stdio.h>
#include <stdint.h>

typedef union
{
    
    struct {
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
        unsigned char b8:1;
    } bits;
    unsigned char byte;
} uByte; //新的資料型態名稱

// void print_binary(uByte num)
// {
//     printf("%d%d%d%d%d%d%d%d\n",num.bits.b8, num.bits.b7,num.bits.b6,num.bits.b5,num.bits.b4,num.bits.b3,num.bits.b2,num.bits.b1);
// }
int main()
{
        uByte num;
        int32_t choose;
        printf("Please enter a byte (0-255): ");
        scanf("%hhd",&num.byte);//%hhd：把整数读作signed char 或 unsigned char
    do{
        printf("Data: %d ",num.byte);
        printf("%d%d%d%d%d%d%d%d\n",num.bits.b8, num.bits.b7,num.bits.b6,num.bits.b5,num.bits.b4,num.bits.b3,num.bits.b2,num.bits.b1);
        printf("Flip bit (1-8, 0: exit): ");
        scanf("%d",&choose);
        if( choose == 1){
            num.bits.b8 = !num.bits.b8;
        }
        if( choose == 2){
            num.bits.b7 = !num.bits.b7;
        }
        if( choose == 3){
            num.bits.b6 = !num.bits.b6;
        }
        if( choose == 4){
            num.bits.b5 = !num.bits.b5;
        }
        if( choose == 5){
            num.bits.b4 = !num.bits.b4;
        }
        if( choose == 6){
            num.bits.b3 = !num.bits.b3;
        }
        if( choose == 7){
            num.bits.b2 = !num.bits.b2;
        }
        if( choose == 8){
            num.bits.b1 = !num.bits.b1;
        }


    }while( choose != 0 );
    printf("Bye\n");
    return 0;
    
}

