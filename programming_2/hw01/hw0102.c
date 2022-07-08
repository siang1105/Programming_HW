#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    printf("Please enter the original text:\n");
    char original[1024];
    char keyword[128];
    char newWord[128];
    char before[1024];
    fgets( original, 1024, stdin );
    printf("Keyword:\n");
    fgets( keyword, 128, stdin );
    printf("New word:\n");
    fgets( newWord, 128,stdin );
    int32_t original_len = strlen(original);
    int32_t keyword_len = strlen(keyword);
    int32_t newWord_len = strlen(newWord);
    int32_t keyword_location[1024];
    original[original_len - 1] = '\0';
    keyword[keyword_len - 1] = '\0';
    newWord[newWord_len - 1] = '\0';
    original_len -= 1;
    keyword_len -= 1;
    newWord_len -= 1;
    char buf1[150];
    
    snprintf(buf1, sizeof(buf1), "%s%s%s", "\033[0;31m",newWord, "\033[0m");
    
    // int32_t keyword_location = strpbrk( original, keyword ) - original;
    char *ptr;
    ptr = strstr( original, keyword );
    int32_t count01 = 0;
    while( ptr != NULL ){
        keyword_location[count01] = ptr - original;
        // printf("ptr = %s",ptr);
        // printf("ptr+1 = %s",ptr + keyword_len);
        ptr = strstr( ptr + keyword_len - 1, keyword );
        // printf("ptr = %s",ptr);
        // printf("ptr = %s",ptr);
        count01++;
    }
    // for( int32_t i = 0; i < count01; i++ )
    // {
    //     printf("%d\n",keyword_location[i]);
    // }
    // for( int32_t i =  0; i < )
    // {
    //     keyword_location[i] = strpbrk( original, keyword ) - original;
        //    i++;


    // }
    
    for( int32_t i = 0; i < original_len; i++ )
    {
        before[i] = original[i];
    }
    // original[original_len] = '\0';
    // keyword[keyword_len] = '\0';
    // newWord[newWord_len] = '\0';
    // keyword[strlen(keyword) - 1] = '\0';
    
    char *tmp = strstr( original, keyword );
    int32_t count = 0;
    while (tmp){
        *tmp = '\0';
        count++;        
        tmp = strstr(tmp + keyword_len, keyword);
    };
    int32_t answer_len = original_len + count * (strlen(buf1) - keyword_len);
    char *answer = (char*) malloc(answer_len + 1);
    tmp = original;
    answer[0] = '\0';
    while (count > 0){
        strcat(answer, tmp);
        strcat(answer, buf1);
        tmp = tmp + strlen(tmp) + keyword_len;
        count--;
    }
    strcat(answer, tmp);//顯示結果printf("result is:%s\n", e);return(0);}
    printf("Before:\n");
    // printf("%s",before);
    int32_t j = 0;
    for(int32_t i = 0; i < original_len; i++)
    {
        if( j != 0 && i == keyword_location[j - 1] + keyword_len){
            printf("\033[0m");
        }
        if( i == keyword_location[j] ){
                printf("\033[34m");
                j++;
            }
    
        printf("%c",before[i]);
        
    }
    printf("\033[0m");
        // if( i >= keyword_location && i <= keyword_location + keyword_len - 1 ){
        //     printf("\033[34m%c\033[0m",before[i]);
        // }
        // else{
        //     printf("%c",before[i]);
        // }
    printf("\n");
    // printf("%s\n",before);
    printf("After:\n");
    printf("%s\n",answer);
    return 0;
}
