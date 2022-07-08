#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include "myprintf.h"
//看va_list怎麼用 齁 我不會
//va_list：要先創建一個va_list類型類型的變數
//va_start()：有兩個參數，第一個是剛剛宣告的變數( va_list 類型)，第二個是可變參數 ... 前一個的變數名
//va_arg()：用於獲得額外參數的數值，同樣有兩個參數，第一個也是剛剛宣告的變數，第二個是載入的參數類型。
//va_end()：像 fclose() 一樣把可變參數關掉。一個參數，va_list 類型的變數。

int32_t myprintf(const char *format, ...){
    va_list allarg;
    int32_t length = strlen(format);
    int32_t count = 0;
    int32_t hexlen = 0;
    int32_t strlength = 0;
    int32_t isNegtive = 0;
    va_start(allarg, format);
    for( int32_t i = 0; i < length; i++ ){
        if(format[i] == '%'){
            i++;
            if(format[i] == 'd' || format[i] == 'i'){
                int32_t intarg = va_arg(allarg, int32_t);
                int32_t intlen = 0;
                char output[20] = {0};
                if(intarg < 0){
                    isNegtive = 1;
                }
                intarg = abs(intarg);
                while(intarg != 0){
                    output[intlen] = intarg % 10 + '0';//是由後往前存！！
                    intarg = intarg / 10;
                    intlen++;
                }
                if(isNegtive == 1)
                {
                    fputc('-', stdout);
                    count++;
                }
                if(intlen == 0){
                    fputc('0', stdout);
                    count++;
                }
                intlen--;
                for(int32_t j = intlen; j >= 0; j--){
                    fputc(output[j], stdout);//是由後往前印！！
                    count++;
                }
                
            }

            else if(format[i] == 'x'){
                char output[20] = {0};
                int32_t hexarg = va_arg(allarg, int32_t);
                for(int32_t j = 0; j < 20; j++){
                    output[j] = hexarg % 16 + '0';
                    hexarg = hexarg / 16;
                    if(output[j] == 10 + '0'){
                        output[j] = 'a';
                    }
                    if(output[j] == 11 + '0'){
                        output[j] = 'b';
                    }
                    if(output[j] == 12 + '0'){
                        output[j] = 'c';
                    }
                    if(output[j] == 13 + '0'){
                        output[j] = 'd';
                    }
                    if(output[j] == 14 + '0'){
                        output[j] = 'e';
                    }
                    if(output[j] == 15 + '0'){
                        output[j] = 'f';
                    }
                    if(hexarg == 0){
                        output[j+1] = 0;
                        break;
                    }
                }
                hexlen = strlen(output);
                for(int32_t j = hexlen-1; j >= 0; j--){
                    fputc(output[j], stdout);
                    count++;
                }
                
            }
            else if(format[i] == 'X'){
                char output[20] = {0};
                int32_t hexarg = va_arg(allarg, int32_t);
                for(int32_t j = 0; j < 20; j++){
                    output[j] = hexarg % 16 + '0';
                    hexarg = hexarg / 16;
                    if(output[j] == 10 + '0'){
                        output[j] = 'A';
                    }
                    if(output[j] == 11 + '0'){
                        output[j] = 'B';
                    }
                    if(output[j] == 12 + '0'){
                        output[j] = 'C';
                    }
                    if(output[j] == 13 + '0'){
                        output[j] = 'D';
                    }
                    if(output[j] == 14 + '0'){
                        output[j] = 'E';
                    }
                    if(output[j] == 15 + '0'){
                        output[j] = 'F';
                    }
                    if(hexarg == 0){
                        output[j+1] = 0;
                        break;
                    }
                }
                hexlen = strlen(output);
                for(int32_t j = hexlen-1; j >= 0; j--){
                    fputc(output[j], stdout);
                    count++;
                }
                
            }
            else if(format[i] == 's'){
                char *output = va_arg(allarg, char*);
                strlength = strlen(output);
                for(int32_t j = 0; j < strlength; j++){
                    fputc(output[j],stdout);
                    count++;
                }
            }
        }
        else{
            fputc(format[i], stdout);
            count++;
        }
    }
    va_end(allarg);
    return count;
}
