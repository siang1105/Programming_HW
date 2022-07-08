#pragma once
#include <stdio.h>
#include <stdint.h>
#include <string.h>

char* mystrchr(const char* s, int c);
char* mystrrchr(const char* s, int c);
size_t mystrspn(const char* s, const char* accept);
size_t mystrcspn(const char* s, const char* reject);
char* mystrpbrk(const char* s, const char* accpet);
char* mystrstr(const char* haystack, const char* needle);
char* mystrtok(char* str, const char* delim);

char* mystrchr(const char* s, int c)
{
    int32_t i = 0;
    while(s[i] != '\0'){
        if( s[i] == c ){
            return (char*)s + i;
        }
        else{
            i++;
        }
    }
    return NULL;

}

char* mystrrchr(const char* s, int c)
{
    int32_t len = strlen(s);
    int32_t i = len;
    while(s[i] != -1){
        if( s[i] == c ){
            return (char*)s + i;
        }
        else{
            i--;
        }
    }
    return NULL;
}

size_t mystrspn(const char* s, const char* accept)
{
    size_t answer = 0;
    int32_t word =0;
    int32_t i = 0;
    int32_t j = 0;
    while(s[i] != '\0'){
        while(accept[j] != '\0'){
            if( s[i] == accept[j] ){
                answer++;
                word = 1;
                break;
            }
            j++;

        }
        if( word == 0 ){
            break;
        }
        i++;
        j = 0;
        word = 0;
    }
    return answer;
}


size_t mystrcspn(const char* s, const char* reject)
{
    int32_t answer = 0;
    int32_t word = 0;
    int32_t i = 0;
    int32_t j = 0;
    while( s[i] != '\0' ){
        while( reject[j] != '\0'){
            if( s[i] == reject[j] ){
                word = 1;
                break;
            }
            j++;
        }
        if( word == 1 ){
            break;
        }
        else{
            answer++;
        }
        i++;
        j = 0;
        word = 0;
    }
    return answer;
}

char* mystrpbrk(const char* s, const char* accept)
{
    // char *ans =(char *)s;
    int32_t i = 0;
    int32_t j = 0;
    while( s[i] != '\0' ){
        while( accept[j] != '\0'){
            if( s[i] == accept[j] ){
                return (char *)&s[i];
            }
            j++;
        }
        i++;
        j = 0;
    }
    return NULL;
}

char* mystrstr(const char* haystack, const char* needle)
{
    int32_t needle_len = strlen(needle);
    int32_t haystack_len = strlen(haystack);
    for (int32_t i = 0; i < haystack_len; i++)
    {
        if( strncmp( haystack + i, needle, needle_len) == 0 ){
            return (char *)haystack + i;
        }
    }
    return NULL;
}

char* mystrtok(char* str, const char* delim)
{
    static char* record = NULL;
    char* answer = NULL;
    char* separate_ptr = NULL;
    int32_t i = 0;
    int32_t isEnd = 1;
    
    if(record == NULL){
        if(str != NULL) {
            record = str;
        }
        else{
            return NULL;
        }
    }

    answer = record;

    separate_ptr = mystrpbrk(record,delim);

    if(separate_ptr == NULL){
        record = NULL;
        return answer;
    }else{
        do{
            isEnd = 1;
            *(separate_ptr) = '\0';
            separate_ptr++;
            while(delim[i] != '\0'){
                if(*(separate_ptr) == delim[i]){
                    isEnd = 0;
                    break;
                }
                i++;
            }
            i = 0;
        }while(!isEnd);

        record = separate_ptr;
        return answer;
    }


}
