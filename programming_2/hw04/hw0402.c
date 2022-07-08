#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <math.h>

#define VAR 0
#define FUNC 1
#define NUM 2

struct option long_options[] = {
    {"help", 0, NULL, 'h'},
    {0, 0, 0, 0}
};

typedef struct {
    char origin[32];
    char modified[16];
    int32_t isOccupied;
} variable;

void get_line(char* str, FILE* pFile){  
    char data = 0;                                    
    int32_t index = 0;                                    
    // memset(str,0,sizeof(str));                                   
    do{

        fread(&data,sizeof(char),1,pFile);     
        str[index] = data;
        index++;

    }while(data != ';' && data != '}' && data != '{' && data != '>' && !feof(pFile));   

    if(str[0] == '#'){  
                        
        do{
            fread(&data,sizeof(char),1,pFile);
            if(data == '\n' || data == ' '){
                str[index] = data;
                index++;
            }
        }while(data == '\n' || data == ' ');
        fseek(pFile,-1,SEEK_CUR);   
    }
    return;
}

void set_name(char* str, variable* var, int32_t type){  

    int32_t varIdx = 0;
    char tmp[32] = "";

    for(int32_t i = 0;i < 128;i++){ 
        if(var[i].isOccupied == 0){
            varIdx = i;
            break;
        }
    }

    for(int32_t i = 0;i < strlen(str);i++){
        if(strncmp(&str[i],"int",3) == 0 || strncmp(&str[i],"char",4) == 0){   

            int32_t continueSearch = 0;
            int32_t strIdx = 0;

            memset(var[varIdx].origin,0,sizeof(var[varIdx].origin));    
            memset(tmp,0,sizeof(tmp));
            
            if(type == VAR){

                for(int32_t j = i + 4;j < strlen(str);j++){    
                    if(str[j] == ' ' || str[j] == '\n') continue;  
                    if(str[j] == ';' || str[j] == '=' || str[j] == ',' || str[j] == ')') break; 
                    if(str[j] == '('){  
                        continueSearch = 1;
                        break;
                    }

                    tmp[strIdx++] = str[j];
                }

            }
            else{   

                for(int32_t j = i + 4;j < strlen(str);j++){
                    if(str[j] == ' ' || str[j] == '\n') continue;
                    if(str[j] == '(') break;
                    if(str[j] == ';' || str[j] == '=' || str[j] == ',' || str[j] == ')'){
                        continueSearch = 1;
                        break;
                    }
                    
                    tmp[strIdx++] = str[j];
                }

            }
            

            for(int32_t j = 0;j < varIdx;j++){
                if(strncmp(tmp,var[j].origin,strlen(tmp)) == 0){    
                    continueSearch = 1;
                    break;
                }
            }
            if(strncmp(tmp,"main",4) == 0) continueSearch = 1; 

            if(continueSearch) continue;   

            strncpy(var[varIdx].origin,tmp,strlen(tmp));    

            var[varIdx].modified[0] = rand() % 26 + 'a';    

            for(int32_t j = 1;j < 16;j++){  
                int32_t choice = rand() % 62;

                if(choice < 10) var[varIdx].modified[j] = choice + '0';
                else if(choice < 36) var[varIdx].modified[j] = choice - 10 + 'A';
                else if(choice < 62) var[varIdx].modified[j] = choice - 36 + 'a';
            }

            var[varIdx].isOccupied = 1; 
            varIdx++;   
        }
    }

    return;
}

void random_space(FILE* pFile){
    
    char space = ' ';
    char nextline = '\n';
    int32_t times = 0;
    times = rand() % 5 + 1;
    for(int32_t i = 0; i < times; i++){
        int32_t choice = rand() % 10;
        if(choice < 9){
            fwrite(&space,sizeof(char),1,pFile);
        }
        else{
            fwrite(&nextline,sizeof(char),1,pFile);
        }
    }
    return;
}

int32_t isVar(char* str, int32_t idx, int32_t type){

    if(type == VAR){

        for(int32_t i = idx;i < strlen(str);i++){
            if(str[i] == ' ' || str[i] == '\n') continue;
            if(str[i] == '=' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '<' || str[i] == '>') return 1;
            if(str[i] == '&' || str[i] == '^' || str[i] == '|' || str[i] == ')' || str[i] == ',' || str[i] == ';' || str[i] == ':' || str[i] == '!') return 1;
            
            return 0;
        }

    }
    else if(type == FUNC){

        for(int32_t i = idx;i < strlen(str);i++){
            if(str[i] == ' ' || str[i] == '\n') continue;
            if(str[i] == '(') return 1;            
            return 0;
        }

    }
    else{

        for(int32_t i = idx;i >= 0;i--){
            if(str[i] == ' ' || str[i] == '\n'){
                continue;
            }
            if(str[i] == '=' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '<' || str[i] == '>') return 1;
            if(str[i] == '&' || str[i] == '^' || str[i] == '|' || str[i] == '!' || str[i] == '(' || str[i] == ',') return 1;
            if(str[i] == 'e' && i - 3 >= 0){
                if(strncmp(&str[i - 3],"case",4) == 0){
                    return 1;
                }
            }
            if(str[i] == 'n' && i - 5 >= 0){
                if(strncmp(&str[i - 5],"return",6) == 0){
                    return 1;
                }
            }
            
            return 0;
        }
    }
    return 0;
}

void help(){
    printf("./hw0402 -l [options] -i [input file] -o [output file]\n");
    printf("./hw0402 -h\n");
    printf("./hw0402 --help\n");
    printf("    Display this help manual.\n");
}

int main(int32_t argc, char* argv[]){
    int32_t index = 0;
    int32_t opt_l = 0;
    int32_t opt_i = 0;
    int32_t opt_o = 0;
    int32_t opt_h = 0;
    int32_t check = 0;
    int32_t c = 0;
    int32_t level = 0;
    char filename_in[30] = {0};
    char filename_ou[30] = {0};
    while( (c = getopt_long(argc,argv,"l:i:o:h",long_options, &index)) != -1 ){
        switch(c){
            case 'l':
                opt_l = 1;
                level = (int32_t)strtol(optarg,NULL,10);
                if(strlen(optarg) == 0){
                    check = 1;
                }
                break;
            case 'i':
                opt_i = 1;
                strncpy(filename_in, optarg, 30);
                break;
            case 'o':
                opt_o = 1;
                strncpy(filename_ou, optarg, 30);
                if(strlen(optarg) == 0){
                    check =1;
                }
                break;
            case 'h':
                opt_h = 1;
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
    if(opt_h == 1){
        help();
        return 0;
    }
    FILE *file_in = NULL;
    FILE *file_ou = NULL;
    FILE *file_tmp = NULL;
    int32_t is_string = 0;
    char str[1024] = {0};
    variable var[128] = {0};
    file_in = fopen(filename_in, "r");
    if(file_in == NULL){
        printf("file could not be opened\n");
        return 0;
    }
    file_ou = fopen(filename_ou, "w");
    if(file_ou == NULL){
        printf("file could not be opened\n");
        return 0;
    }
    file_tmp = fopen("tmp.c", "wb+");
    if(file_tmp == NULL){
        printf("file could not be opened\n");
    }
    while((c = fgetc(file_in)) != -1){
        fputc(c, file_tmp);
    }
    for(int32_t i = level; i >= 1; i--){
        rewind(file_tmp);
        rewind(file_ou);
        if(level == 1){
            memset(str, 0, sizeof(str));
            get_line(str, file_tmp);
            while(!feof(file_tmp)){
                if(str[0] == '#'){
                    fwrite(str, strlen(str), 1, file_ou);
                }
                else{
                    is_string = 0;
                    for(int32_t j = 0; j < strlen(str); j++){
                        fwrite(&str[j], sizeof(char), 1, file_ou);
                        if(str[j] == '\''){
                            is_string = !is_string; 
                        }   
                        if(str[j] == '"'){
                            is_string = !is_string;
                        }
                        if(str[j] == ' ' && !is_string){
                            random_space(file_ou);
                        }
                        if(str[j] == '(' && !is_string){
                            random_space(file_ou);
                        }
                        if(str[j] == ')' && !is_string){
                            random_space(file_ou);
                        }
                        if(str[j] == ';' && !is_string){
                            random_space(file_ou);
                        }
                        if(str[j] == ',' && !is_string){
                            random_space(file_ou);
                        }
                        if(str[j] == '\n'){
                        }random_space(file_ou);
                    }
                }
            }
            memset(str, 0, sizeof(str));
            get_line(str, file_tmp);
        }
        else if(level == 2){
            memset(str,0,sizeof(str));
            get_line(str,file_tmp);
            while(!feof(file_tmp)){
                if(str[0] == '#'){
                    fwrite(str,strlen(str),1,file_ou);
                }
                else{
                    set_name(str,var,VAR);  
                    is_string = 0;
                    for(int32_t j = 0;j < strlen(str);j++){
                        int32_t varIdx = 0;
                        int32_t foundVariable = 0;
                        if(str[j] == '\''){
                            is_string = !is_string;
                        }
                        if(str[j] == '"'){
                            is_string = !is_string;
                        } //到這裡都跟前面差不多
                        while(var[varIdx].isOccupied == 1){ //每個字都要確認有沒有可能是變數的開頭，因此要檢查struct array每個宣告過的變數名稱
                            if(strncmp(&str[j],var[varIdx].origin,strlen(var[varIdx].origin)) == 0 && isVar(str,j + strlen(var[varIdx].origin),VAR) && !is_string){
                                foundVariable = 1;      //上面的條件是分別是 1.符合先前宣告過的名稱 2.確定是一個名稱完全相符的變數 3.不是在字串裡
                                fwrite(var[varIdx].modified,sizeof(char),16,file_ou);   //寫入亂碼
                                j += strlen(var[varIdx].origin) - 1;    //跳過原先的變數，繼續尋找
                                break;
                            }
                            varIdx++;
                        }
                        if(!foundVariable){
                            fwrite(&str[j],sizeof(char),1,file_ou); 
                        } 
                    }
                }
                memset(str,0,sizeof(str));
                get_line(str,file_tmp);
            }
            break;
        }
        else if(level == 3){
            memset(str,0,sizeof(str));
            get_line(str,file_tmp);
            while(!feof(file_tmp)){
                if(str[0] == '#'){
                    fwrite(str,strlen(str),1,file_ou);
                }
                else{
                    set_name(str,var,FUNC);
                    is_string = 0;
                    for(int32_t j = 0;j < strlen(str);j++){
                        int32_t varIdx = 0;
                        int32_t foundVariable = 0;
                        if(str[j] == '\''){
                            is_string = !is_string;
                        }
                        if(str[j] == '"'){
                            is_string = !is_string;
                        }
                        while(var[varIdx].isOccupied == 1){
                        if(strncmp(&str[j],var[varIdx].origin,strlen(var[varIdx].origin)) == 0 && isVar(str,j + strlen(var[varIdx].origin),FUNC) && !is_string){
                            foundVariable = 1;
                            fwrite(var[varIdx].modified,sizeof(char),16,file_ou);
                            j += strlen(var[varIdx].origin) - 1;
                            break;
                        }
                        varIdx++;
                        }
                        if(!foundVariable){
                            fwrite(&str[j],sizeof(char),1,file_ou);
                        }
                    }
                }
                memset(str,0,sizeof(str));
                get_line(str,file_tmp);
            }
            break;
        }
        else if(level == 4){
            printf("I don't know\n");
        }
        else{
            printf("the level is not exist\n");
            return 0;
        }
        rewind(file_ou);
        file_tmp = freopen(NULL,"wb+",file_tmp);
        while((c = fgetc(file_ou)) != -1){
            fputc(c,file_tmp);
        }
    }
    fclose(file_in);
    fclose(file_ou);
    fclose(file_tmp);
    remove("tmp.c");
    return 0;
}