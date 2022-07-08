#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

uint8_t signature[4] = {'P','K',3,4};


typedef struct zipheader{
    uint16_t version;
    uint16_t flags;
    uint16_t compression;
    uint16_t filemodtime;
    uint16_t filemoddate;
    uint32_t checksum;
    uint32_t compress_size;
    uint32_t uncompress_size;
    uint16_t filename_len;
    uint16_t extra_len;
}__attribute__ ((__packed__)) szipheader;


int main(int argc, char *argv[]){
    FILE *ptr;
    char filename[30];
    strcpy(filename,argv[1]);
    ptr = fopen(filename,"r");
    if(ptr == NULL){
        printf("file could not be opened\n");
        return 0;
    }
    int32_t count = 0;
    int32_t index = 0;
    char data[100][100]={0};
    while(!feof(ptr)){
        if(count == 4){
            szipheader *header = malloc(sizeof(szipheader));
            fread(header,sizeof(szipheader),1,ptr);
            char filenamestr[header->filename_len+1];
            fread(filenamestr,sizeof(uint8_t),header->filename_len,ptr);
            filenamestr[header->filename_len] = '\0';
            if(filenamestr[header->filename_len-1] == '/'){
                strcpy(data[index],filenamestr);
                while(strncmp(data[index-1],filenamestr,strlen(data[index-1])) != 0 && index != 0){
                    index--;
                }
                filenamestr[header->filename_len-1] = '\0';
                // printindex(index);
                if(index == 0){
                    printf("+-- ");
                    printf("%s",filenamestr);
                    printf("/");
                }
                else{
                    for(int32_t i = strlen(data[index-1]); filenamestr[i] != '\0'; i++){
                        fputc(filenamestr[i],stdout);
                        printf("index != 0\n");
                    }
                }
                index++;
            }
            else{
                while(strncmp(data[index-1],filenamestr,strlen(data[index-1])) != 0 && index != 0){
                    index--;
                }
                // printindex(index);
                if(index == 0){
                    printf("    +-- ");
                    printf("%s",filenamestr);
                    // printf("index != 0\n");
                }
                else{
                    for(int32_t i = strlen(data[index-1]); filenamestr[i] != '\0'; i++){
                        fputc(filenamestr[i],stdout);
                    }
                }
            }
            printf("\n");
            count = 0;
        }
        uint8_t *no_signature = malloc(sizeof(uint8_t));
        fread(no_signature,sizeof(uint8_t),1,ptr);
        if(*no_signature == signature[count]){
            count++;//找到signature的話
        }
        else{
            count = 0;
        }
    }
    fclose(ptr);
    return 0;
}