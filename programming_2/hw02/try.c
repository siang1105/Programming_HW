#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define _toINT -'0'
#define _toASCII +'0'

typedef struct _sBigNum{
    char val[1025];
    int32_t digit;
    int32_t pn;
} sBigNum;

void print( const sBigNum num ){
    if(num.pn == -1) printf("-");
    for(int32_t i = num.digit - 1;i >= 0;i--) printf("%c",num.val[i]);
    printf("\n");
    return;
}

int32_t set( sBigNum *pNum, char *str ){
    int32_t len = strlen(str);
    int32_t idx = 0;
    
    for(int32_t i = 0;i < len;i++){
        if((str[i] < '0' || str[i] > '9') && str[0] != '-' ) return 0;
        if(i != 0 && str[i] == '-') return 0;
        if(len == 1 && str[0] == '-') return 0;
    }

    if(str[0] != '-'){
        memset(pNum->val,0,sizeof(pNum->val));
        for(int32_t i = 0;i < len;i++) pNum->val[i] = str[len - 1 - i];
        pNum->digit = len;
        pNum->pn = 1;
    }
    if(str[0] == '-'){
        memset(pNum->val,0,sizeof(pNum->val));
        for(int32_t i = 0;i < len - 1;i++) pNum->val[i] = str[len - 1 - i];
        pNum->digit = len - 1;
        pNum->pn = -1;
    }

    return 1;
}

int32_t compare( const sBigNum num01 , const sBigNum num02 ){
    if(num01.pn == 1 && num02.pn == -1) return 1;
    if(num01.pn == -1 && num02.pn == 1) return -1;
    if(num01.pn == 1 && num01.digit > num02.digit) return 1;
    if(num01.pn == -1 && num01.digit > num02.digit) return -1;
    if(num01.pn == 1 && num01.digit < num02.digit) return -1;
    if(num01.pn == -1 && num01.digit < num02.digit) return 1;
 
    for(int32_t i = num01.digit - 1;i >= 0;i--){
        if(num01.val[i] == num02.val[i]) continue;
        else if(num01.val[i] > num02.val[i]) return 1 * num01.pn;
        else if(num01.val[i] < num02.val[i]) return -1 * num01.pn;
    }
    return 0;
}

int32_t digits( const sBigNum num ){
    return num.digit;
}

void add( sBigNum *pResult ,const sBigNum num01 , const sBigNum num02 ){
    sBigNum num01tmp = num01;
    sBigNum num02tmp = num02;
    int32_t max_digit = 0;
    int32_t carry = 0;

    if(num01tmp.pn == 1 && num02tmp.pn == -1){
        num02tmp.pn = 1;
        // return subtract(pResult,num01tmp,num02tmp);
    }
    if(num01tmp.pn == -1 && num02tmp.pn == 1){
        num01tmp.pn = 1;
        // return subtract(pResult,num02tmp,num01tmp);
    }

    //Initialize

    memset(pResult->val,0,1025);
    
    //align(&num01tmp,&num02tmp);
    if(num01tmp.digit >= num02tmp.digit) max_digit = num01tmp.digit;
    if(num01tmp.digit < num02tmp.digit) max_digit = num02tmp.digit;
    for(int32_t i = num01tmp.digit;i < max_digit;i++) num01tmp.val[i] = '0';
    for(int32_t i = num02tmp.digit;i < max_digit;i++) num02tmp.val[i] = '0';

    for(int32_t i = 0;i < max_digit;i++){
        pResult->val[i] = (num01tmp.val[i]_toINT + num02tmp.val[i]_toINT + carry) % 10 _toASCII;
        carry = (num01tmp.val[i]_toINT + num02tmp.val[i]_toINT + carry) / 10;
    }

    if(carry) pResult->val[max_digit] = carry _toASCII;

    pResult->digit = strlen(pResult->val);
    pResult->pn = num01tmp.pn;

    return;
}

void subtract( sBigNum *pResult , const sBigNum num01 , const sBigNum num02 ){
    sBigNum num01tmp = num01;
    sBigNum num02tmp = num02;
    int32_t max_digit = 0;
    int32_t idx = 0;
    char tmp[1025] = "";
    
    if(num01tmp.pn == 1 && num02tmp.pn == -1){
        num02tmp.pn = 1;
        return add(pResult,num01tmp,num02tmp);
    }
    if(num01tmp.pn == -1 && num02tmp.pn == 1){
        num02tmp.pn = -1;
        return add(pResult,num01tmp,num02tmp);
    }

    //Initialize

    memset(pResult->val,0,1025);

    if(num01tmp.pn == 1 && num02tmp.pn == 1){
        if(compare(num01tmp,num02tmp) == -1){
            pResult->pn = -1;
            return subtract(pResult,num02tmp,num01tmp);
        }
    }else if(num01tmp.pn == -1 && num02tmp.pn == -1){
        num01tmp.pn = 1;
        num02tmp.pn = 1;
        return subtract(pResult,num02tmp,num01tmp);
    }

    //align(&num01tmp,&num02tmp);
    if(num01tmp.digit >= num02tmp.digit) max_digit = num01tmp.digit;
    if(num01tmp.digit < num02tmp.digit) max_digit = num02tmp.digit;
    for(int32_t i = num01tmp.digit;i < max_digit;i++) num01tmp.val[i] = '0';
    for(int32_t i = num02tmp.digit;i < max_digit;i++) num02tmp.val[i] = '0';

    for(int32_t i = 0;i < max_digit;i++){
        pResult->val[i] = num01tmp.val[i] - num02tmp.val[i] _toASCII;
        if(pResult->val[i] < '0'){
            pResult->val[i] += 10;
            num01tmp.val[i+1]--;
        }
    }

    while(pResult->val[idx] != 0) idx++;
    while(pResult->val[--idx] == '0') pResult->val[idx] = 0;

    pResult->digit = strlen(pResult->val);
    if(pResult->pn != -1) pResult->pn = num01tmp.pn;

    return;
}

void multiply( sBigNum *pResult , const sBigNum num01 , const sBigNum num02 ){

    sBigNum num01tmp = num01;
    sBigNum num02tmp = num02;
    sBigNum nowSum = {
        .val = "",
        .digit = 0,
        .pn = 1
    };
    sBigNum preSum = {
        .val = "",
        .digit = 0,
        .pn = 1
    };
    int32_t max_digit = 0;
    int32_t carry = 0;
    int32_t shift = 0;
    int32_t idx = 0;
    char tmp[1025] = "";

    //Initialize

    memset(pResult->val,0,1025);

    if(num01tmp.digit >= num02tmp.digit) max_digit = num01tmp.digit;
    if(num01tmp.digit < num02tmp.digit) max_digit = num02tmp.digit;
    for(int32_t i = num01tmp.digit;i < max_digit;i++) num01tmp.val[i] = '0';
    for(int32_t i = num02tmp.digit;i < max_digit;i++) num02tmp.val[i] = '0';

    for(int32_t i = 0;i < num01tmp.digit;i++){
        preSum = nowSum;
        memset(nowSum.val,0,sizeof(nowSum.val));
        memset(nowSum.val,'0',shift);
        for(int32_t j = 0;j < num02tmp.digit;j++){
            nowSum.val[j + shift] = ((num01tmp.val[i]_toINT) * (num02tmp.val[j]_toINT) + carry) % 10 _toASCII;
            carry = ((num01tmp.val[i]_toINT) * (num02tmp.val[j]_toINT) + carry) / 10;
        }
        if(carry) nowSum.val[num02tmp.digit + shift] = carry _toASCII;

        nowSum.digit = strlen(nowSum.val);
        add(&nowSum,nowSum,preSum);
        
        carry = 0;
        shift++;
    }

    //output

    *(pResult) = nowSum;
    pResult->pn = num01tmp.pn * num02tmp.pn;
    pResult->digit = strlen(&pResult->val[idx]);

    return;
}

void divide( sBigNum *pQuotient , sBigNum *pRemainder , const sBigNum num01 , const sBigNum num02 ){
    
    sBigNum num01tmp = num01;
    sBigNum num02tmp = num02;
    sBigNum multi_10 = {
        .val = "",
        .digit = 0,
        .pn = 1
    };
    sBigNum count = {
        .val = "",
        .digit = 0,
        .pn = 1
    };
    sBigNum countUnit = {
        .val = "",
        .digit = 0,
        .pn = 1
    };
    sBigNum one = {
        .val = "",
        .digit = 1,
        .pn = 1
    };
    sBigNum nowUnit = {
        .val = "",
        .digit = 0,
        .pn = 1
    };

    //Initialize

    memset(pQuotient->val,0,1025);
    memset(pRemainder->val,0,1025);
    num01tmp.pn = 1;
    num02tmp.pn = 1;
    one.val[0] = '1';

    memset(multi_10.val,'0',num01tmp.digit);
    multi_10.val[num01tmp.digit - 1] = '1';
    multi_10.digit = num01tmp.digit;

    do{
        multiply(&nowUnit,num02tmp,multi_10);

        if(compare(num01tmp,nowUnit) != -1){
            multiply(&countUnit,one,multi_10);
            while(compare(num01tmp,nowUnit) != -1){
                subtract(&num01tmp,num01tmp,nowUnit);
                add(&count,count,countUnit);
            }
        }
        
        if(multi_10.digit > 1){
            multi_10.val[multi_10.digit - 1] = 0;
            multi_10.val[multi_10.digit - 2] = '1';
            multi_10.digit--;
        }

    }while(compare(nowUnit,num02tmp) != 0);

    *(pQuotient) = count;
    *(pRemainder) = num01tmp;

    if(num01.pn == 1 && num02.pn == 1){
        pQuotient->pn = 1;
        pRemainder->pn = 1;
    }
    if(num01.pn == 1 && num02.pn == -1){
        pQuotient->pn = 1;
        pRemainder->pn = 1;
    }
    if(num01.pn == -1 && num02.pn == 1){
        pQuotient->pn = -1;
        pRemainder->pn = -1;
    }
    if(num01.pn == -1 && num02.pn == -1){
        pQuotient->pn = 1;
        pRemainder->pn = -1;
    }

    return;
}

int32_t power( sBigNum *pResult , int32_t n, int32_t k ){
    
    sBigNum p = {
        .val = "",
        .digit = 0,
        .pn = 1
    };
    char string[12] = "";
    int32_t isOdd = 0;

    if(k < 0) return 0;

    //Initialize

    memset(pResult->val,0,1025);
    pResult->val[0] = 1 _toASCII;
    pResult->digit = 1;
    pResult->pn = 1;
    if(k == 0) return 1;

    snprintf(string,12,"%d",n);
    set(&p,string);
    if(n < 0) p.pn = 1;

    if(k % 2 == 1) isOdd = 1;


    while(k != 0){
        if(k & 1){
            multiply(pResult,*pResult,p);
        }
        multiply(&p,p,p);
        k >>= 1;
    }

    pResult->digit = strlen(pResult->val);
    if(n < 0 && isOdd) pResult->pn = -1;

    return 1;
}

int32_t combine( sBigNum *pResult , int32_t n, int32_t k ){
    if(n == 0) return 0;
    if(k < 0 || n < 0) return 0;
    if(k > n) return 0;
    
    sBigNum numerator = {
        .val = "",
        .digit = 0,
        .pn = 1
    };
    sBigNum denominator = {
        .val = "",
        .digit = 0,
        .pn = 1
    };
    sBigNum multi = {
        .val = "",
        .digit = 0,
        .pn = 1
    };
    sBigNum factorial_n = {
        .val = "",
        .digit = 0,
        .pn = 1
    };
    sBigNum factorial_nk = {
        .val = "",
        .digit = 0,
        .pn = 1
    };
    sBigNum factorial_k = {
        .val = "",
        .digit = 0,
        .pn = 1
    };
    sBigNum one = {
        .val = "",
        .digit = 1,
        .pn = 1
    };
    char string[12] = "";

    //Initialize

    memset(pResult->val,0,1025);
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
int main()
{
    sBigNum a, b;
    set( &a, "123" );
    set( &b, "99" );

    print( a );
    print( b );

    if( compare( a, b ) == 1 )
    {
        printf( "Comparison Pass.\n" );
    }
    else
    {
        printf( "Comparison Fail.\n" );
    }

    if( digits( a ) == 7 )
    {
        printf( "Digits Pass.\n" );
    }
    else
    {
        printf( "Digits Fail.\n" );
    }

    sBigNum ans, q, r;

    add( &ans, a, b );
    print( ans );
    subtract( &ans, a, b );
    print( ans );
    multiply( &ans, a, b );
    print( ans );

    divide( &q, &r, a, b );
    print( q );
    print( r );

    power( &ans, 27, 17 );
    print( ans );

    combine( &ans, 1000, 500 );
    print( ans );

    return 0;
}