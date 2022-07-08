#include<stdio.h>
#include<stdint.h>
#include"roman.h"
void roman (int32_t input)
{
    int32_t thousand;
    thousand = input/1000;
    switch (thousand)
    {
    case 1:
        printf("M");
        break;
    case 2:
        printf("MM");
        break;
    case 3:
        printf("MMM");
        break;
    default:
       break;
    }
    int32_t hundred;
    hundred = (input - (thousand*1000))/100;
    switch (hundred)
    {
    case 1:
        printf("Ⅽ");
        break;
    case 2:
        printf("ⅭⅭ");
        break;
    case 3:
        printf("ⅭⅭⅭ");
        break;
    case 4:
        printf("ⅭⅮ");
        break;
    case 5:
        printf("Ⅾ");
        break;
    case 6:
        printf("ⅮⅭ");
        break;
    case 7:
        printf("ⅮⅭⅭ");
        break;
    case 8:
        printf("ⅮⅭⅭⅭ");
        break;
    case 9:
        printf("ⅭⅯ");
        break;
    default:
       break;
    }
    int32_t tens = (input - (thousand*1000) - (hundred*100))/10;
    switch (tens)
    {
    case 1:
        printf("Ⅹ");
        break;
    case 2:
        printf("ⅩⅩ");
        break;
    case 3:
        printf("ⅩⅩⅩ");
        break;
    case 4:
        printf("ⅩⅬ");
        break;
    case 5:
        printf("Ⅼ");
        break;
    case 6:
        printf("ⅬⅩ");
        break;
    case 7:
        printf("ⅬⅩⅩ");
        break;
    case 8:
        printf("ⅬⅩⅩⅩ");
        break;
    case 9:
        printf("ⅩⅭ");
        break;
    default:
        break;
    }
    int32_t digit;
    digit = input - thousand*1000 - hundred*100 - tens*10;
    switch (digit)
    {
    case 1:
        printf("Ⅰ\n");
        break;
    case 2:
        printf("Ⅱ\n");
        break;
    case 3:
        printf("Ⅲ\n");
        break;
    case 4:
        printf("Ⅳ\n");
        break;
    case 5:
        printf("Ⅴ\n");
        break;
    case 6:
        printf("Ⅵ\n");
        break;
    case 7:
        printf("Ⅶ\n");
        break;
    case 8:
        printf("Ⅷ\n");
        break;
    case 9:
        printf("Ⅸ\n");
        break;
    default:
        printf("\n");
        break;
    }

}
