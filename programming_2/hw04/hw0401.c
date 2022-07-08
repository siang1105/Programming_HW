#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <math.h>

struct option long_options[] = {
    {"size", 1, NULL, 'z'},//1代表選項需要參數
    {"help", 0, NULL, 'h'},
    {0, 0, 0, 0}
};
void help(){
    printf("Split:\n");
    printf("./hw0401 -s [file] --size [Small File Size]\n");
    printf("The default small file size is 1000 bytes.\n");
    printf("Recover:\n");
    printf("./hw0401 -r [output file] [small files]\n");
    printf("The input small files may not be in order.\n");
}

int main(int32_t argc, char *argv[]){
    int32_t c = 0;
    int32_t index_optind = 0;
    int32_t mode_s = 0;
    int32_t mode_r = 0;
    int32_t opt_size = 0;
    int32_t opt_help = 0;
    char filename_origin[256] = {0};
    char filename_modified[256] = {0};
    char filename_combi[256] = {0};
    char input_size[256] = {0};
    FILE* file_origin = NULL;
    FILE* file_modified = NULL;
    FILE* file_combi = NULL;
    int32_t check = 0;
    int32_t index = 0;
    while( (c = getopt_long(argc,argv,"s:r:",long_options, &index)) != -1 ){
        switch(c){
            case 's':
                mode_s = 1;
                strncpy(filename_origin,optarg,256);
                if(strlen(optarg) == 0){
                    check = 1;
                }
                break;
            case 'z':
                opt_size = 1;
                strncpy(input_size,optarg,256);
                break;
            case 'r':
                mode_r = 1;
                strncpy(filename_combi,optarg,256);
                index_optind = optind;
                if(strlen(optarg) == 0){
                    check =1;
                }
                break;
            case 'h':
                opt_help = 1;
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
    
    int64_t filesize = 0;
    uint64_t size = 1000;
    uint8_t* buffer = NULL;
    uint32_t file_num = 0;
    int32_t count = 0;
    char** ptr = NULL;
    if(opt_size == 1){
        size = (uint64_t)strtol(input_size,ptr,10);
    } 

    if(mode_s == 1){
        file_origin = fopen(filename_origin,"r");
        if(file_origin == NULL){
            printf("error\n");
            return 0;
        }
        
        fseek(file_origin,0,SEEK_END);
        filesize = ftell(file_origin);
        rewind(file_origin);
        file_num = (uint32_t)ceil(((double)filesize / size));
        buffer = (uint8_t*)malloc(sizeof(uint8_t) * size);
        for(uint32_t i = 1;i <= file_num;i++){
            strncpy(filename_modified,filename_origin,256);
            filename_modified[strlen(filename_modified)] = '.';
            snprintf(&filename_modified[strlen(filename_modified)],255 - strlen(filename_modified),"%u",i);
            file_modified = fopen(filename_modified,"w");
            fwrite(&i,sizeof(i),1,file_modified);
            fwrite(&size,sizeof(size),1,file_modified);
            count = fread(buffer,1,size,file_origin);
            fwrite(buffer,1,count,file_modified);
            printf("%s ",filename_modified);
            fclose(file_modified);
        }
        printf("\n");
        free(buffer);
        fclose(file_origin);

    }
    if(mode_r == 1){
        file_combi = fopen(filename_combi,"w");
        if(file_combi == NULL){
            printf("error\n");
            return 0;
        }
        while(index_optind < argc && argv[index_optind][0] != '-'){
            file_origin = fopen(argv[index_optind],"rb");
            if(file_origin == NULL){
                printf("error");
                return 0;
            }
            fread(&file_num,sizeof(file_num),1,file_origin);
            fread(&size,sizeof(size),1,file_origin);
            buffer = (uint8_t*)malloc(sizeof(uint8_t) * size);
            count = fread(buffer,1,size,file_origin);
            fseek(file_combi,size * (file_num - 1),SEEK_SET);
            fwrite(buffer,1,count,file_combi);
            fclose(file_origin);          
            index_optind++;
            free(buffer);
        }
        fclose(file_combi);
    }
    if(opt_help == 1){
        help();
    }
    return 0;
}