#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "mixed.h"

int gcd(int32_t a, int32_t b){
    int32_t ans = 1;
    int32_t i = 2;
    if( a == 1 || b == 1 ){
        ans = 1;
    }
    if( a == 0 || b == 0 ){
        ans = 0;
    }
    else if( a >= i && b >= i ){
        while( a >= i && b >= i ){
            while( a%i == 0 && b%i == 0 ){
                ans = ans * i;
                a = a / i;
                b = b / i;
            }
            i++;
        }
    }
    return ans;
}

void simplify(sMixedNumber* pNumber){

    int32_t isNeg = 0;
    int32_t Gcd = 0;
    int32_t a = pNumber->a;
    int32_t b = pNumber->b;
    int32_t c = pNumber->c;

    if(b != 0 && c != 0){
        if(a > 0){
            pNumber->a = pNumber->a + b / c;
        }
        else if(a == 0){
            pNumber->a = pNumber->a + b / c;
            if(b < 0){
                isNeg = 1;
            }
        }
        else{
            pNumber->a = pNumber->a - b / c;
        }

        b = b % c;
        b = abs(b);
        if(b == 0){
            pNumber->b = 0;
            pNumber->c = 0;
        }
        else{
            Gcd = gcd(c,b);
            if(Gcd != 1){
                b = b / Gcd;
                c = c / Gcd;
            }
            if(isNeg == 1 && pNumber->a == 0){
                pNumber->b = -b;
            }
            else{
                pNumber->b = b;
            }
            pNumber->c = c;
        }
    }
    else{
        pNumber->b = 0;
        pNumber->c = 0;
    }
}


int mixed_set( sMixedNumber *pNumber , int32_t a, int32_t b,int32_t c){
    if(b != 0 && c == 0){
        return -1;
    }
    if(b < 0 && a != 0){
        return -1;
    }
    if(c < 0){
        return -1;
    }
    if(pNumber == NULL){
        return -1;
    }
    return 0;
}
// return -1 if invalid; otherwise , return 0.

int32_t judge(const sMixedNumber* pNumber){
    if(pNumber->b != 0 && pNumber->c == 0){
        return 0;
    }
    if(pNumber->b < 0 && pNumber->a != 0){
        return 0;
    }
    if(pNumber->c < 0){
        return 0;
    }
    if(pNumber == NULL){
        return 0;
    }
    if(pNumber->c == 0 && pNumber->b != 0){
        return 0;
    }

    return 1;
}
int mixed_print( const sMixedNumber number){
    if(judge(&number) == 0){
        return -1;
    }
    printf("(%d,%d,%d)",number.a,number.b,number.c);
    return 0;
}
// in the form of (a,b,c)
void mixed_add( sMixedNumber *pNumber , const sMixedNumber r1,const sMixedNumber r2){
    if(judge(&r1) == 0 || judge(&r2) == 0){
        printf("Invalid Input\n");
        return;
    }
    sMixedNumber improper_r1 = (sMixedNumber)r1;
    sMixedNumber improper_r2 = (sMixedNumber)r2;
    if( improper_r1.b == 0 && improper_r1.c == 0){
        improper_r1.b = improper_r1.a;
        improper_r1.c = 1;
        improper_r1.a = 0;
    }
    else if( improper_r1.a < 0 ){
        improper_r1.b = improper_r1.a * improper_r1.c - improper_r1.b;
    }
    else{
        improper_r1.b = improper_r1.a * improper_r1.c + improper_r1.b;
    }
    if( improper_r2.b == 0 && improper_r2.c == 0){
        improper_r2.b = improper_r2.a;
        improper_r2.c = 1;
        improper_r2.a = 0;
    }
    else if( improper_r2.a < 0 ){
        improper_r2.b = improper_r2.a * improper_r2.c - improper_r2.b;
    }
    else{
        improper_r2.b = improper_r2.a * improper_r2.c + improper_r2.b;
    }
    pNumber->a = 0;
    pNumber->b = improper_r1.b * improper_r2.c + improper_r2.b * improper_r1.c;
    pNumber->c = improper_r1.c * improper_r2.c;
    simplify(pNumber);
    return;
}
// pNumber = r1 + r2
void mixed_sub( sMixedNumber *pNumber , const sMixedNumber r1,const sMixedNumber r2){
    if(judge(&r1) == 0 || judge(&r2) == 0){
        printf("Invalid Input\n");
        return;
    }
    sMixedNumber improper_r1 = (sMixedNumber)r1;
    sMixedNumber improper_r2 = (sMixedNumber)r2;
    if( improper_r1.b == 0 && improper_r1.c == 0){
        improper_r1.b = improper_r1.a;
        improper_r1.c = 1;
        improper_r1.a = 0;
    }
    else if( improper_r1.a < 0 ){
        improper_r1.b = improper_r1.a * improper_r1.c - improper_r1.b;
    }
    else{
        improper_r1.b = improper_r1.a * improper_r1.c + improper_r1.b;
    }
    if( improper_r2.b == 0 && improper_r2.c == 0){
        improper_r2.b = improper_r2.a;
        improper_r2.c = 1;
        improper_r2.a = 0;
    }
    else if( improper_r2.a < 0 ){
        improper_r2.b = improper_r2.a * improper_r2.c - improper_r2.b;
    }
    else{
        improper_r2.b = improper_r2.a * improper_r2.c + improper_r2.b;
    }
    pNumber->a = 0;
    pNumber->c = improper_r1.c * improper_r2.c;
    pNumber->b = improper_r1.b * improper_r2.c - improper_r2.b * improper_r1.c;
    // if( pNumber->b != 0 && pNumber->c != 0 ){
    //     if( pNumber->b > 0 ){
    //         pNumber->a = pNumber->b / pNumber->c;
    //         pNumber->b = pNumber->b - (pNumber->c * pNumber->a);
    //     }
    //     else{
    //         pNumber->a = 0 - (abs(pNumber->b) / pNumber->c);
    //         pNumber->b = abs(pNumber->b) - (pNumber->c * abs(pNumber->a));
    //     }
    // }
    simplify(pNumber);
    return;

}
// pNumber = r1 - r2
void mixed_mul( sMixedNumber *pNumber , const sMixedNumber r1,const sMixedNumber r2){
    if(judge(&r1) == 0 || judge(&r2) == 0){
        printf("Invalid Input\n");
        return;
    }
    sMixedNumber improper_r1 = (sMixedNumber)r1;
    sMixedNumber improper_r2 = (sMixedNumber)r2;
    if( improper_r1.b == 0 && improper_r1.c == 0){
        improper_r1.b = improper_r1.a;
        improper_r1.c = 1;
        improper_r1.a = 0;
    }
    else if( improper_r1.a < 0 ){
        improper_r1.b = improper_r1.a * improper_r1.c - improper_r1.b;
    }
    else{
        improper_r1.b = improper_r1.a * improper_r1.c + improper_r1.b;
    }
    if( improper_r2.b == 0 && improper_r2.c == 0){
        improper_r2.b = improper_r2.a;
        improper_r2.c = 1;
        improper_r2.a = 0;
    }
    else if( improper_r2.a < 0 ){
        improper_r2.b = improper_r2.a * improper_r2.c - improper_r2.b;
    }
    else{
        improper_r2.b = improper_r2.a * improper_r2.c + improper_r2.b;
    }
    pNumber->a = 0;
    pNumber->c = improper_r1.c * improper_r2.c;
    pNumber->b = improper_r1.b * improper_r2.b;
    simplify(pNumber);
    return;
}
// pNumber = r1 * r2
void mixed_div( sMixedNumber *pNumber , const sMixedNumber r1,const sMixedNumber r2){
    if(judge(&r1) == 0 || judge(&r2) == 0){
        printf("Invalid Input\n");
        return;
    }
    sMixedNumber improper_r1 = (sMixedNumber)r1;
    sMixedNumber improper_r2 = (sMixedNumber)r2;
    if( improper_r1.b == 0 && improper_r1.c == 0){
        improper_r1.b = improper_r1.a;
        improper_r1.c = 1;
        improper_r1.a = 0;
    }
    else if( improper_r1.a < 0 ){
        improper_r1.b = improper_r1.a * improper_r1.c - improper_r1.b;
    }
    else{
        improper_r1.b = improper_r1.a * improper_r1.c + improper_r1.b;
    }
    if( improper_r2.b == 0 && improper_r2.c == 0){
        improper_r2.b = improper_r2.a;
        improper_r2.c = 1;
        improper_r2.a = 0;
    }
    else if( improper_r2.a < 0 ){
        improper_r2.b = improper_r2.a * improper_r2.c - improper_r2.b;
    }
    else{
        improper_r2.b = improper_r2.a * improper_r2.c + improper_r2.b;
    }
    pNumber->a = 0;
    pNumber->c = improper_r1.c * improper_r2.b;
    pNumber->b = improper_r1.b * improper_r2.c;
    simplify(pNumber);
    return;

}
// pNumber = r1 / r2


