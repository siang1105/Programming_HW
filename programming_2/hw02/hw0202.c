#include <stdio.h> 
#include <stdint.h>
int64_t tmp[53];
typedef union { 
    double d; 
    struct
    { 
        uint64_t fraction : 52; 
        uint64_t exponent : 11; 
        uint64_t sign : 1; 
  
    } raw; 
} mydouble;
void printBinary_exp(int64_t n, int64_t i) 
{
    int64_t exp[12];
    int64_t k; 
    int32_t j = 0;
    for (k = i - 1; k >= 0; k--) 
    { 
        if ((n >> k) & 1){
            exp[j] = 1;
            j++;
            // printf("1"); 
        }
        else{
            exp[j] = 0;
            j++;
            // printf("0"); 
        }
    } 
    for( int32_t i = 0; i < 11; i++)
    {
        printf("%ld",exp[i]);
    }
    
} 
void printBinary_fra(int64_t n, int64_t i) 
{
    int64_t fra[53];
    int64_t k; 
    int32_t w = 0;
    for (k = i - 1; k >= 0; k--) 
    { 
        if ((n >> k) & 1){
            fra[w] = 1;
            w++;
            // printf("1"); 
        }
        else{
            fra[w] = 0;
            w++;
            // printf("0"); 
        }
    } 
    for( int32_t i = 0; i < 52; i++ )
    {
        tmp[i] = fra[i];
    }
    for( int32_t i = 0; i < 52; i++ )
    {
        printf("%ld",fra[i]);
    }
} 
  
 

void printIEEE(mydouble var) 
{ 
    printf("Sign: %d \n", var.raw.sign); 
    printf("Exponent: ");
    printBinary_exp(var.raw.exponent, 11); 
    
    printf("\n");
    printf("fraction: ");
    printBinary_fra(var.raw.fraction, 52); 
    
    printf("\n"); 
    

} 
long long convertDecimalToBinary(int32_t n)
{
    long long binaryNumber = 0;
    int32_t remainder;
    int32_t i = 1;
    while (n!=0)
    {
        remainder = n % 2;
        // printf("Step %d: %d/2, 餘數 = %d, 商 = %d\n", step++, n, remainder, n/2);
        n  = n / 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}

int main() 
{  
    mydouble var; 
    printf("Please enter a floating -point number (double precision): ");
    scanf("%lf",&var.d);
    printIEEE(var); 
    printf("%lf = (-1)^%d * (1",var.d,var.raw.sign);
    int32_t num = 52;
    int32_t count = -1;
    int32_t t = 0;
    while(num >= 0){
        if( tmp[t] == 1 ){
            printf(" + 2^%d",count);
        }
        count--;
        t++;
        num--;
    }
    printf(") * 2^(");
    int32_t power = convertDecimalToBinary(var.d);
    int32_t digits = 0;
    while( power != 0 ){
        power = power / 10;
        digits++;
    }
    digits = digits - 1;
    printf("%d-1023)",var.raw.exponent);
    printf("\n");
    return 0; 
} 