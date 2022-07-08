#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int32_t point;
    int32_t win;
    int32_t draw;
    int32_t lose;
    int32_t goalScored;
    int32_t goalAgainst;
    int32_t redCards;
    int32_t winHome;
    int32_t winAway;
    int32_t isOccupied;
} sTeam;


void menu(){
    printf("1) Who is the winner in this season?\n");
    printf("2) Which team gets the most scores?\n");
    printf("3) Which team gets the most red cards?\n");
    printf("4) Which team wins the most games at home?\n");
    printf("5) Which team wins the most games away from home?\n");
    printf("6) Which game has the most scoring gap?\n");
    printf("7) Team information.\n");
    printf("8) Exit\n");
}
void calculate(FILE* pfile, sTeam* team, char* most_gap){
    char nowall[1024] = "";
    char hometeam[32] = "";
    char awayteam[32] = "";
    int32_t FTHG = 0;
    int32_t FTAG = 0;
    char FTR = 0;
    int32_t HR = 0;
    int32_t AR = 0;
    int32_t gap = INT32_MIN;
    int32_t firstLine = 1;

    while(fgets(nowall,1024,pfile) != NULL){

        nowall[strlen(nowall) - 1] = 0;
        
        if(firstLine == 1){
            firstLine = 0;
            continue;
        }

        sscanf(nowall,"%*[^,],%[^,],%[^,],%d,%d,%c,%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%d,%d,%*s",hometeam,awayteam,&FTHG,&FTAG,&FTR,&HR,&AR);

        for(int32_t i = 0;i < 20;i++){
            if(strncmp(team[i].name,hometeam,32) == 0 || team[i].isOccupied == 0){

                if(team[i].isOccupied == 0){
                    team[i].isOccupied = 1;
                    strncpy(team[i].name,hometeam,32);
                }    

                if(FTR == 'H'){
                    team[i].point += 3;
                    team[i].win += 1;
                    team[i].winHome += 1;
                }
                else if(FTR == 'A'){
                    team[i].lose += 1;
                }
                else{
                    team[i].point += 1;
                    team[i].draw += 1;
                }
                team[i].goalScored += FTHG;
                team[i].goalAgainst += FTAG;
                team[i].redCards += HR;
                break;
            }
        }
        for(int32_t i = 0;i < 20;i++){
            if(strncmp(team[i].name,awayteam,32) == 0 || team[i].isOccupied == 0){
                if(team[i].isOccupied == 0){
                    team[i].isOccupied = 1;
                    strncpy(team[i].name,awayteam,32);
                }    

                if(FTR == 'A'){
                    team[i].point += 3;
                    team[i].win += 1;
                    team[i].winAway += 1;
                }
                else if(FTR == 'H'){
                    team[i].lose += 1;
                }
                else{
                    team[i].point += 1;
                    team[i].draw += 1;
                }

                team[i].goalScored += FTAG;
                team[i].goalAgainst += FTHG;
                team[i].redCards += AR;

                break;
            }
        }

        if(gap < abs(FTHG - FTAG)){
            snprintf(most_gap,1024,"%.10s,%s(%d) vs %s(%d)",nowall,hometeam,FTHG,awayteam,FTAG);
            gap = abs(FTHG - FTAG);
        }
    }

}
    
int main(){
    
    FILE* pfile = NULL;
    char filename[256] = {0};
    char most_gap[128] = {0};
    char * check = NULL;
    int32_t choice = 0;
    printf("Please open a season record: ");
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

    menu();

    sTeam team[20] = {0};
    calculate(pfile,team,most_gap);

    while(1){
        printf("Choice (1-7, 8:exit): ");
        scanf("%d",&choice);
        int32_t ans = INT32_MIN;
        int32_t ansIdx = 0;
        char team_search[32] = {0};
        if(choice < 1 || choice > 8){
            printf("Error!\n");
            return 0;
        }
        switch(choice){
            case 1:
                for(int32_t i = 0;i < 20;i++){
                    if(ans < team[i].point){
                        ans = team[i].point;
                        ansIdx = i;
                    }
                }
                printf("The winner is %s.\n",team[ansIdx].name);
                break;
            case 2:
                for(int32_t i = 0;i < 20;i++){
                    if(ans < team[i].goalScored){
                        ans = team[i].goalScored;
                        ansIdx = i;
                    }
                }
                printf("%s, %d\n",team[ansIdx].name,ans);
                break;
            case 3:
                for(int32_t i = 0;i < 20;i++){
                    if(ans < team[i].redCards){
                        ans = team[i].redCards;
                        ansIdx = i;
                    }
                }
                printf("%s, %d\n",team[ansIdx].name,ans);
                break;
            case 4:
                for(int32_t i = 0;i < 20;i++){
                    if(ans < team[i].winHome){
                        ans = team[i].winHome;
                        ansIdx = i;
                    }
                }
                printf("%s, %d\n",team[ansIdx].name,ans);
                break;
            case 5:
                for(int32_t i = 0;i < 20;i++){
                    if(ans < team[i].winAway){
                        ans = team[i].winAway;
                        ansIdx = i;
                    }
                }
                printf("%s, %d\n",team[ansIdx].name,ans);
                break;
            case 6:
                printf("%s\n",most_gap);
                break;
            case 7:
                fgets(team_search,32,stdin);    //Eliminate \n
                printf("Team: ");
                fgets(team_search,32,stdin);
                team_search[strlen(team_search) - 1] = 0;
                for(int32_t i = 0;i < 20;i++){
                    if(strncmp(team_search,team[i].name,32) == 0){
                        printf("Points: %d\n",team[i].point);
                        printf("Win/Draw/Lose: %d/%d/%d\n",team[i].win,team[i].draw,team[i].lose);
                        printf("Goals Scored/Goals Against: %d/%d\n",team[i].goalScored,team[i].goalAgainst);
                        break;
                    }
                    if(i == 19) printf("Error: There is no team called \"%s\".\n",team_search);
                }
                break;
            case 8:
                return 0;
        }
    }
    fclose(pfile);
    return 0;
}