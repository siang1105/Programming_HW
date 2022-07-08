#include <stdio.h> 
#include <stdint.h>
#include <string.h>
#include <ctype.h>
int hex_to_int(char c){ 
     int32_t first = c/16 - 3; 
     int32_t second = c % 16; 
     int32_t result = first*10 + second; 
     
     if(result > 9){
         result--; 
     }
     return result; 
} 

int hex_to_ascii(char c, char d){ 
     int32_t high = hex_to_int(c) * 16; 
     int32_t low = hex_to_int(d); 
     return high+low; 
} 

int main()
{ 
    char input[100];
    printf("Please enter the hex string: ");
    fgets( input, 100, stdin);
    int32_t length = strlen(input); 
    char buf = 0; 
    for(int32_t i = 0; i < length; i++)
    { 
        if( islower(input[i]) == 1 ){
            input[i] = toupper(input[i]);
        }
        if(i % 2 != 0){ 
            printf("%c", hex_to_ascii(buf, input[i])); 
        }
       else{ 
         buf = input[i]; 
       } 
     } 
     printf("\n");
} 
