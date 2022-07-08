#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RED "\033[1;91m"
#define GREEN "\033[1;92m"
#define YELLOW "\033[1;93m"
#define BLUE "\033[1;94m"
#define PURPLE "\033[1;95m"
#define CYAN "\033[1;96m"
#define BLUE_WHITE "\033[1;97;104m"
#define RED_WHITE "\033[1;97;101m"
#define RESET "\033[m"


typedef struct{
    char name[32];
    char* color;
    int32_t isOccupied;
} sColor;
int main()
{
FILE * pfile = NULL;
char * check = NULL;
char filename[256] = {0};
printf("Open a LRC file: ");
check = fgets(filename, sizeof(filename), stdin);
if( check == NULL ){
    printf("Error!\n");
        return 0;
}
if( filename[strlen(filename) - 1] == '\n' ){
    filename[strlen(filename) - 1] = 0;
}
pfile = fopen(filename, "r");
if( pfile == NULL ){
        printf("File could not be opened!\n");
        return 0;
    }
char name[128] = {0};
char *time;
char *lyric;
char all[256] = {0};
int32_t pre_finalTime = 0;
int32_t pre_finalTime2 = 0;
int32_t now_finalTime = 0;
int32_t now_finalTime2 = 0;
int32_t check2 = 0;
int32_t colorindex = 0;
int32_t check03;
int32_t count = 0;
char* nowColor = NULL;

sColor color[8] = {0};
    color[0].color = RED;
    color[1].color = BLUE;
    color[2].color = GREEN;
    color[3].color = CYAN;
    color[4].color = PURPLE;
    color[5].color = YELLOW;
    color[6].color = BLUE_WHITE;
    color[7].color = RED_WHITE;

while(!feof(pfile)){
    memset(all, 0, 256);
    fgets(all, 256, pfile);
    all[strlen(all) - 1] = 0;
    if(all[0] == '[' && (all[1] > '9' || all[1] < '0')){
        continue;
    }
    // if(all[strlen(all)-2] == ':' && all[0] != '['){
    //     // name[count] = all;
    //     // count++;
    //     for(int32_t i = 0; i < 8; i++){
    //         if(strncmp(all, name[i], 32) == 0){
    //             colorindex = i;
    //             break;
    //         }
    //     }
    // }
    if(strrchr(all,':') != NULL && all[0] != '['){
        for(int32_t i = 0;i < 8;i++){
            if(strncmp(all,color[i].name,64) == 0){  //already has a color
                nowColor = color[i].color;
                break;
            }
            if(color[i].isOccupied == 0){   //assign a new color
                strncpy(color[i].name,all,32);
                color[i].isOccupied = 1;
                nowColor = color[i].color;
                break;
            }
        }
    }
    if(all[0] != '['){
        continue;
    }
    else if(all[0] == '[' && all[1] == '0'){
        time = strtok(all, "]");
        lyric = strtok(NULL, "]");
        if(time[1] == '0'){
            now_finalTime = (time[2]-'0') * 60 + (time[4]-'0') * 10 + (time[5]-'0') * 1;
            now_finalTime2 = (time[7]-'0')* 10 + (time[8]-'0') * 1;
        }
        // printf("now_finalTime: %d\n",now_finalTime);
        // printf("now_finalTime2:%d\n",now_finalTime2);
        if(now_finalTime2 < pre_finalTime2){
            // printf("into\n");
            check2 = 1;
            now_finalTime = now_finalTime - 1;
            now_finalTime2 = now_finalTime2 + 100;
        }
        // printf("now_finalTime: %d\n",now_finalTime);
        // printf("now_finalTime2:%d\n",now_finalTime2);
        // printf("%d\n",now_finalTime - pre_finalTime);
        // printf("%d\n",now_finalTime2 - pre_finalTime2);
        sleep(now_finalTime - pre_finalTime);
        usleep(now_finalTime2 - pre_finalTime2);
        if(check2 == 1){
            now_finalTime = (time[2]-'0') * 60 + (time[4]-'0') * 10 + (time[5]-'0') * 1;
            now_finalTime2 = (time[7]-'0')* 10 + (time[8]-'0') * 1;
            // printf("check:%d %d\n",now_finalTime,now_finalTime2);
            check2 = 0;
        }
        // printf("bkj\n");
        printf("%s%s"RESET,nowColor,&all[10]);
        // printf("%s",lyric);
        printf("\n");
        pre_finalTime = now_finalTime;
        pre_finalTime2 = now_finalTime2;
        // printf("pre_finalTime:%d\n",pre_finalTime);
        // printf("pre_finalTime2:%d\n",pre_finalTime2);
    }
    //     if(all[strlen(all)-1] != ':'){
    //     time = strtok(all, "]");
    //     lyric = strtok(NULL, "]");
    //     if(time[1] == '0'){
    //         now_finalTime = (time[2]-'0') * 60 + (time[4]-'0') * 10 + (time[5]-'0') * 1;
    //         now_finalTime2 = (time[7]-'0')* 10 + (time[8]-'0') * 1;
    //     }
    //     // printf("now_finalTime: %d\n",now_finalTime);
    //     // printf("now_finalTime2:%d\n",now_finalTime2);
    //     if(now_finalTime2 < pre_finalTime2){
    //         // printf("into\n");
    //         check2 = 1;
    //         now_finalTime = now_finalTime - 1;
    //         now_finalTime2 = now_finalTime2 + 100;
    //     }
    //     // printf("now_finalTime: %d\n",now_finalTime);
    //     // printf("now_finalTime2:%d\n",now_finalTime2);
    //     // printf("%d\n",now_finalTime - pre_finalTime);
    //     // printf("%d\n",now_finalTime2 - pre_finalTime2);
    //     sleep(now_finalTime - pre_finalTime);
    //     usleep(now_finalTime2 - pre_finalTime2);
    //     if(check2 == 1){
    //         now_finalTime = (time[2]-'0') * 60 + (time[4]-'0') * 10 + (time[5]-'0') * 1;
    //         now_finalTime2 = (time[7]-'0')* 10 + (time[8]-'0') * 1;
    //         // printf("check:%d %d\n",now_finalTime,now_finalTime2);
    //         check2 = 0;
    //     }
    //     // printf("bkj\n");
    //     printf("%s%s"RESET,nowColor,&all[10]);
    //     // printf("%s",lyric);
    //     printf("\n");
    //     pre_finalTime = now_finalTime;
    //     pre_finalTime2 = now_finalTime2;
    //     // printf("pre_finalTime:%d\n",pre_finalTime);
    //     // printf("pre_finalTime2:%d\n",pre_finalTime2);
    //     }
    // }
    }
    fclose(pfile);
    return 0;
}