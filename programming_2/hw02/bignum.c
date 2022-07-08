#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "bignum.h"
// #include "bignum.h"


#define MAX 300

// typedef struct _sBigNum
// {
//     char str[MAX];
//     int32_t length;
//     bool isNegative;
// } sBigNum;

void print( const sBigNum num );
int32_t set( sBigNum *pNum, char *str );
int32_t compare( const sBigNum num01 , const sBigNum num02 );
int32_t digits( const sBigNum num );
void add( sBigNum *pResult ,const sBigNum num01 , const sBigNum num02 );
void subtract( sBigNum *pResult , const sBigNum num01 , const sBigNum num02 );
void multiply( sBigNum *pResult , const sBigNum num01 , const sBigNum num02 );
void divide( sBigNum *pQuotient , sBigNum *pRemainder , const sBigNum num01 , const sBigNum num02 );
int32_t power( sBigNum *pResult , int32_t n, int32_t k );
int32_t combine( sBigNum *pResult , int32_t n, int32_t k );

void print(const sBigNum num)
{
    if (num.isNegative)
    {
        printf("-");
    }
    // for( int32_t i = MAX - 1; i > 0; i-- )
    // {
    //     if( num.str[i] != 0 ){
    //         break;
    //     }
    // }
    for (int32_t i = num.length - 1; i >= 0; i--)
    {
        printf("%c", num.str[i]);
    }
    printf("\n");
}

int32_t set(sBigNum *pNum, char *str){
    int32_t len = strlen(str);
    memset(pNum->str, 0, sizeof(char)*MAX);
    if( str[0] != '-' ){
        for( int32_t i = len - 1; i >= 0; i-- ){
            pNum->str[len - i - 1] = str[i];
        }
        pNum->length = len;
        pNum->isNegative = false;
    }
    else{
        for( int32_t i = len - 1; i > 0; i--){
            pNum->str[len - i - 1] = str[i];
        }
        pNum->length = len - 1;
        pNum->isNegative = true;
    }
    for( int32_t i = len - 1; i >= 0; i--){
        if( pNum->str[i] == '0' ){
            pNum->str[i] = '\0';
        }
        else{
            break;
        }
    }
    return 0;
}

 int32_t compare( const sBigNum num01 , const sBigNum num02 ){
    sBigNum num01_ = num01;
    sBigNum num02_ = num02;
    int32_t same = 0;
    if(num01_.isNegative && !num02_.isNegative){
        return -1;
    }
    if (!num01_.isNegative && num02_.isNegative){
        return 1;
    }
    if (!num01_.isNegative && !num02_.isNegative){
        if(num01_.length == num02_.length){
            for(int32_t i = num01_.length - 1; i >= 0; i--){
                if(num01_.str[i] > num02_.str[i]) {
                    return 1;
                }
                if (num01_.str[i] < num02_.str[i]) {
                    return -1;
                }
            }
            return 0;
        }
        else if(num01_.length > num02_.length){
            return 1;
        }
        else{
            return -1;
        }
    }
    
    if (num01_.isNegative && num02_.isNegative){
        if(num01_.length == num02_.length){
            for(int32_t i = num01_.length; i >= 0; i--){
                if(num01_.str[i] > num02_.str[i]) {
                    return -1;
                }
                if (num01_.str[i] < num02_.str[i]) {
                    return 1;
                }
            }
            return 0;
        }
        else if(num01_.length > num02_.length){
            return -1;
        }
        else{
            return 1;
        }
    }
    return 0;
 }
 

 int32_t digits( const sBigNum num ){
     return num.length;
 }

 void add( sBigNum *pResult ,const sBigNum num01 , const sBigNum num02 ){
    sBigNum num01_ = num01;
    sBigNum num02_ = num02;
    int32_t max_length = 0;
    int32_t carry = 0;//進位

    if(num01_.isNegative == false && num02_.isNegative == true){
        num02_.isNegative = false;
         subtract(pResult,num01_,num02_);
          return;
    }
    if(num01_.isNegative == true && num02_.isNegative == false){
        num01_.isNegative = 1;
         subtract(pResult,num02_,num01_);
          return;
    }

    //Initialize

    memset(pResult->str,0,MAX);
    
    //align(&num01_,&num02_);
    if(num01_.length >= num02_.length){
        max_length = num01_.length;
    }
    if(num01_.length < num02_.length){
        max_length = num02_.length;
    }
    for(int32_t i = num01_.length; i < max_length; i++){
        num01_.str[i] = '0';
    }
    for(int32_t i = num02_.length;i < max_length;i++){
        num02_.str[i] = '0';
    }

    for(int32_t i = 0; i < max_length; i++){
        pResult->str[i] = (num01_.str[i] - '0' + num02_.str[i] - '0' + carry) % 10 + '0';
        carry = (num01_.str[i] - '0' + num02_.str[i] - '0' + carry) / 10;
    }

    if(carry == 1){
        pResult->str[max_length] = carry + '0';//若最後一位需進位
    }
    pResult->length = strlen(pResult->str);
    pResult->isNegative = num01_.isNegative;

    return;
 }

 void subtract( sBigNum *pResult , const sBigNum num01 , const sBigNum num02 ){
    sBigNum num01_ = num01;
    sBigNum num02_ = num02;
    int32_t max_length = 0;
    int32_t idx = 0;
    char tmp[MAX] = "";
    
    if(num01_.isNegative == false && num02_.isNegative == true){
        num02_.isNegative = false;
        return add(pResult,num01_,num02_);
    }
    if(num01_.isNegative == true && num02_.isNegative == false){
        num02_.isNegative = true;
        return add(pResult,num01_,num02_);
    }

    //Initialize

    memset(pResult->str,0,MAX);

    if(num01_.isNegative == false && num02_.isNegative == false){//兩個都是正的
        if(compare(num01_,num02_) == -1){//2比較大
            pResult->isNegative = true;
            return subtract(pResult,num02_,num01_);
        }
    }
    else if(num01_.isNegative == true && num02_.isNegative == true){
        num01_.isNegative = false;
        num02_.isNegative = true;
        return subtract(pResult,num02_,num01_);
    }

    //align(&num01tmp,&num02tmp);
    if(num01_.length >= num02_.length){
        max_length = num01_.length;
    } 
    if(num01_.length < num02_.length){
        max_length = num02_.length;
    }
    for(int32_t i = num01_.length; i < max_length; i++){
        num01_.str[i] = '0';
    }
    for(int32_t i = num02_.length; i < max_length; i++){
        num02_.str[i] = '0';
    }
    for(int32_t i = 0; i < max_length; i++){
        pResult->str[i] = num01_.str[i] - num02_.str[i] + '0';
        if(pResult->str[i] < '0'){
            pResult->str[i] += 10;
            num01_.str[i+1]--;
        }
    }

    while(pResult->str[idx] != '\0'){
        idx++;
    }
    while(pResult->str[--idx] == '0'){
        pResult->str[idx] = 0;
    }

    pResult->length = strlen(pResult->str);
    if(pResult->isNegative != true){
        pResult->isNegative = num01_.isNegative;
    }

    return;
 }

 void multiply( sBigNum *pResult , const sBigNum num01 , const sBigNum num02 ){
     
    sBigNum num01_ = num01;
    sBigNum num02_ = num02;
    sBigNum nowSum = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    sBigNum preSum = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    int32_t max_length = 0;
    int32_t carry = 0;
    int32_t shift = 0;
    int32_t idx = 0;
    char _[1025] = "";

    //Initialize

    memset(pResult->str,0,1025);

    if(num01_.length >= num02_.length) max_length = num01_.length;
    if(num01_.length < num02_.length) max_length = num02_.length;
    for(int32_t i = num01_.length;i < max_length;i++) num01_.str[i] = '0';
    for(int32_t i = num02_.length;i < max_length;i++) num02_.str[i] = '0';

    for(int32_t i = 0;i < num01_.length;i++){
        preSum = nowSum;
        memset(nowSum.str,0,sizeof(nowSum.str));
        memset(nowSum.str,'0',shift);
        for(int32_t j = 0;j < num02_.length;j++){
            nowSum.str[j + shift] = ((num01_.str[i] - '0') * (num02_.str[j] - '0') + carry) % 10  + '0';
            carry = ((num01_.str[i] - '0') * (num02_.str[j] - '0') + carry) / 10;
        }
        if(carry) nowSum.str[num02_.length + shift] = carry  + '0';

        nowSum.length = strlen(nowSum.str);
        add(&nowSum,nowSum,preSum);
        
        carry = 0;
        shift++;
    }

    //output

    *(pResult) = nowSum;
    pResult->isNegative = num01_.isNegative | num02_.isNegative;
    pResult->length = strlen(&pResult->str[idx]);

    return;
 }

 void divide( sBigNum *pQuotient , sBigNum *pRemainder , const sBigNum num01 , const sBigNum num02 ){
    sBigNum num01_ = num01;
    sBigNum num02_ = num02;
    sBigNum multi_10 = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    sBigNum count = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    sBigNum countUnit = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    sBigNum one = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    sBigNum nowUnit = {
        .str = "",
        .length = 0,
        .isNegative = false
    };

    //Initialize

    memset(pQuotient->str,0,1025);
    memset(pRemainder->str,0,1025);
    num01_.isNegative = false;
    num02_.isNegative = false;
    one.str[0] = '1';

    memset(multi_10.str,'0',num01_.length);
    multi_10.str[num01_.length - 1] = '1';
    multi_10.length = num01_.length;

    do{
        multiply(&nowUnit,num02_,multi_10);

        if(compare(num01_,nowUnit) != -1){
            multiply(&countUnit,one,multi_10);
            while(compare(num01_,nowUnit) != -1){
                subtract(&num01_,num01_,nowUnit);
                add(&count,count,countUnit);
            }
        }
        
        if(multi_10.length > 1){
            multi_10.str[multi_10.length - 1] = 0;
            multi_10.str[multi_10.length - 2] = '1';
            multi_10.length--;
        }

    }while(compare(nowUnit,num02_) != 0);

    *(pQuotient) = count;
    *(pRemainder) = num01_;

    if(num01.isNegative == false && num02.isNegative == false){
        pQuotient->isNegative = false;
        pRemainder->isNegative = false;
    }
    if(num01.isNegative == false && num02.isNegative == true){
        pQuotient->isNegative = false;
        pRemainder->isNegative = false;
    }
    if(num01.isNegative == true && num02.isNegative == false){
        pQuotient->isNegative = true;
        pRemainder->isNegative = true;
    }
    if(num01.isNegative == true && num02.isNegative == true){
        pQuotient->isNegative = false;
        pRemainder->isNegative = true;
    }

    return;
 }

 int32_t power( sBigNum *pResult , int32_t n, int32_t k ){
     sBigNum p = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    char string[12] = "";
    int32_t isOdd = 0;

    if(k < 0) return 0;

    //Initialize

    memset(pResult->str,0,1025);
    pResult->str[0] = 1  + '0';
    pResult->length = 1;
    pResult->isNegative = false;
    if(k == 0) return 1;

    snprintf(string,12,"%d",n);
    set(&p,string);
    if(n < 0) p.isNegative = false;

    if(k % 2 == 1) isOdd = 1;


    while(k != 0){
        if(k & 1){
            multiply(pResult,*pResult,p);
        }
        multiply(&p,p,p);
        k >>= 1;
    }

    pResult->length = strlen(pResult->str);
    if(n < 0 && isOdd) pResult->isNegative = true;

    return 1;
 }

 int32_t combine( sBigNum *pResult , int32_t n, int32_t k ){
     if(n == 0) return 0;
    if(k < 0 || n < 0) return 0;
    if(k > n) return 0;
    
    sBigNum numerator = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    sBigNum denominator = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    sBigNum multi = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    sBigNum factorial_n = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    sBigNum factorial_nk = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    sBigNum factorial_k = {
        .str = "",
        .length = 0,
        .isNegative = false
    };
    sBigNum one = {
        .str = "",
        .length = 1,
        .isNegative = false
    };
    char string[12] = "";

    //Initialize

    memset(pResult->str,0,1025);
    set(&numerator,"1");
    set(&denominator,"1");
    set(&multi,"1");
    set(&one,"1");

    if(k > (n / 2)) k = n - k;
    
    if(k == 0){
        *(pResult) = one;
        return 1;
    }

    snprintf(string,11,"%d",n);
    set(&factorial_n,string);
    snprintf(string,11,"%d",k);
    set(&factorial_k,string);
    snprintf(string,11,"%d",n-k);
    set(&factorial_nk,string);

    while(compare(multi,factorial_k) <= 0){
        multiply(&denominator,denominator,multi);
        add(&multi,multi,one);
    }
    multi = factorial_n;
    while(compare(multi,factorial_nk) > 0){
        multiply(&numerator,numerator,multi);
        subtract(&multi,multi,one);
    }
    divide(pResult,&one,numerator,denominator);

    return 1;
 }

// int main()
// {
//     sBigNum a, b;
//     set(&a, "123");
//     set( &b, "-99" );

//      print( a );
//      print( b );

//      if( compare( a, b ) == 1 )
//      {
//      printf( "Comparison Pass.\n" );
//      }
//      else
//      {
//      printf( "Comparison Fail.\n" );
//      }

//      if( digits( b ) == 3 )
//      {
//     printf( "Digits Pass.\n" );
//     }
//      else
//      {
//      printf( "Digits Fail.\n" );
//      }

//      sBigNum ans, q, r;

//      add( &ans, a, b );
//      print( ans );
//      subtract( &ans, a, b );
//      print( ans );
//      multiply( &ans, a, b );
//      print( ans );

//     //  divide( &q, &r, a, b );
//     //  print( q );
//     //  print( r );

//     power( &ans, 20, 10 );
//     print( ans );

//     combine( &ans, 20, 10 );
//     print( ans );

//     return 0;
// }