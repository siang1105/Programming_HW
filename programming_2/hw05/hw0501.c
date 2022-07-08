#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

char * base64_encode(char *str)  
{ 
    int32_t  len = 0;  
    int32_t str_len = 0;  
    char *res;  
    int32_t i = 0;
    int32_t j = 0;
//定義base64編碼表  
    char base64_table[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";  
  
//計算經過base64編碼後的字串長度  
    str_len=strlen(str);  
    if(str_len % 3 == 0){
        len = str_len / 3 * 4;  
    }
    else {
        len = (str_len / 3 + 1 ) * 4;  
    }
    res = malloc(sizeof(char) * len+1);  
    res[len] = '\0';  
  
//以3個8位元字元爲一組進行編碼  
    for(i = 0, j = 0; i < len-2; j += 3, i += 4)  
    {  
        res[i] = base64_table[str[j] >> 2]; //取出第一個字元的前6位並找出對應的結果字元  
        res[i+1] = base64_table[(str[j] & 0x3) << 4 | (str[j+1] >> 4)]; //將第一個字元的後位與第二個字元的前4位元進行組合並找到對應的結果字元  
        res[i+2] = base64_table[(str[j+1] & 0xf) << 2 | (str[j+2] >> 6)]; //將第二個字元的後4位元與第三個字元的前2位組合並找出對應的結果字元  
        res[i+3] = base64_table[str[j+2] & 0x3f]; //取出第三個字元的後6位並找出結果字元  
    }  
  
    switch(str_len % 3)  
    {  
        case 1:  
            res[i-2] = '=';  
            res[i-1] = '=';  
            break;  
        case 2:  
            res[i-1] = '=';  
            break;  
    }  
    // printf("%s",res);
    return res;  
} 
char *base64_decode(char *code)  
{  
//根據base64表，以字元找到對應的十進制數據 
    // printf("---%s",code);
    // printf("\n");
    int32_t table[] = {0,0,0,0,0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,62,0,0,0,
             63,52,53,54,55,56,57,58,
             59,60,61,0,0,0,0,0,0,0,0,
             1,2,3,4,5,6,7,8,9,10,11,12,
             13,14,15,16,17,18,19,20,21,
             22,23,24,25,0,0,0,0,0,0,26,
             27,28,29,30,31,32,33,34,35,
             36,37,38,39,40,41,42,43,44,
             45,46,47,48,49,50,51
               };  
    int32_t len = 0;  
    int32_t str_len = 0;  
    char *res;  
    int32_t i = 0;
    int32_t j = 0; 
  
//計算解碼後的字串長度  
    len = strlen(code);  
//判斷編碼後的字串後是否有=  
    if(strstr(code,"==")){
        str_len = len / 4 * 3 - 2; 
        // printf("---\n"); 

    } 
    else if(strstr(code,"=")){
        str_len = len / 4 * 3 - 1;  
    }
    else{
        str_len = len / 4 * 3;  
    } 
    res = malloc(sizeof(char) * str_len+1);  
    res[str_len] = '\0';  
  
//以4個字元爲一位進行解碼  
    for(i = 0, j = 0; i < len-2; j += 3, i += 4)  
    {  
        res[j] = ((char)table[code[i]]) << 2 | (((char)table[code[i+1]]) >> 4); //取出第一個字元對應base64表的十進制數的前6位與第二個字元對應base64表的十進制數的後2位進行組合  
        res[j+1] = (((char)table[code[i+1]]) << 4) | (((char)table[code[i+2]]) >> 2); //取出第二個字元對應base64表的十進制數的後4位元與第三個字元對應bas464表的十進制數的後4位元進行組合  
        res[j+2] = (((char)table[code[i+2]]) << 6) | ((char)table[code[i+3]]); //取出第三個字元對應base64表的十進制數的後2位與第4個字元進行組合  
    }  
//   printf("%s",res);
//         printf("\n");
    return res;  
  
}

struct option long_options[] = {
    {"enc", 1, NULL, 'e'},//1代表選項需要參數
    {"dec", 1, NULL, 'd'},
    {"output", 1, NULL, 'o'},
    {0, 0, 0, 0}
};

int main(int32_t argc, char *argv[]){
    char dec_filename[256] = {0};
    char output_filename[256] = {0};
    char enc_filename[256] = {0};
    FILE *dec_file = NULL;
    FILE *output_file = NULL;
    FILE *enc_file = NULL;
    int32_t opt_e = 0;
    int32_t opt_d = 0;
    int32_t opt_o = 0;
    int32_t c = 0;
    int32_t index = 0;
    int32_t check = 0;
    while( (c = getopt_long(argc,argv,"e:d:o:",long_options, &index)) != -1 ){
        switch(c){
            case 'e':
                opt_e = 1;
                strncpy(enc_filename,optarg,256);
                if(strlen(optarg) == 0){
                    check = 1;
                }
                break;
            case 'd':
                opt_d = 1;
                strncpy(dec_filename,optarg,256);
                break;
            case 'o':
                opt_o = 1;
                strncpy(output_filename,optarg,256);
                if(strlen(optarg) == 0){
                    check =1;
                }
                break;
            case '?':
                check = 1;
                break;
        }
        if(check == 1){
            printf("error\n");
            break;
        }
    }

    if(opt_e == 1 && opt_d == 1){
        printf("erroe\n");
        return 0;
    }
    if(opt_e == 1 && opt_o == 1){
        enc_file = fopen(enc_filename, "r");
        if(enc_file == NULL){
            printf("file could not be opened\n");
            return 0;
        }
        output_file = fopen(output_filename, "w");
        if(output_file == NULL){
            printf("file could not be opened\n");
            return 0;
        }
        int32_t count = 0;
        char buffer[1024];
        char *en_buffer = NULL;
        fseek(enc_file,0,SEEK_END);
        int32_t file_size = ftell(enc_file);
        rewind(enc_file);
        char *buf;
        buf = (char*)malloc(sizeof(char) * file_size);
        count = fread(buf, 1, file_size, enc_file);
        en_buffer = base64_encode(buf);
        // printf("%s", en_buffer);
        // printf("\n");
        int32_t length = strlen(en_buffer);
        fwrite(en_buffer, 1, length, output_file);
        fclose(enc_file);
        fclose(output_file);
    }

    if(opt_d == 1 && opt_o == 1){
        dec_file = fopen(dec_filename, "rb+");
        if(dec_file == NULL){
            printf("file could not be opened\n");
            return 0;
        }
        output_file = fopen(output_filename, "wb+");
        if(output_file == NULL){
            printf("file could not be opened\n");
            return 0;
        }
        int32_t count = 0;
        // char buffer[1024];
        char *de_buffer = NULL;
        fseek(dec_file,0,SEEK_END);
        int32_t file_size = ftell(dec_file);
        rewind(dec_file);
        char *buf;
        buf = (char*)malloc(sizeof(char) * file_size);
        // int32_t ssize = sizeof(dec_file);
        // printf("%d\n",ssize);
        count = fread(buf, 1, file_size, dec_file);
        // printf("buffer = %s",buffer);
        // printf("\n");
        de_buffer = base64_decode(buf);
        // printf("%s",de_buffer);
        // printf("\n");
        int32_t length = strlen(de_buffer);
        fwrite(de_buffer, length, 1, output_file);
        fclose(dec_file);
        fclose(output_file);
    }
    return 0;
}