#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "minesweeper.h"
int main()
{
    // int32_t width = 10;
    // int32_t height = 10;
    // int32_t mineNumber = 2;
    int32_t width = 0;
    int32_t height = 0;
    int32_t mineNumber = 0;
    do{
        printf("Please enter the width (10-16): ");
        scanf("%d",&width);
    }while(width < 10 || width > 16);
    do{
        printf("Please enter the height (10-16): ");
        scanf("%d",&height);
    }while(height < 10 || height > 16);
    do{
        printf("Please enter the mine number (30-90): ");
        scanf("%d",&mineNumber);
    }while(mineNumber < 30 || mineNumber > 90);
    printf("\n");

    srand(time(0));

    int32_t** numberMine = initaliseNumbers(width, height, mineNumber);
    int32_t** isMine = initaliseMine(numberMine, width, height, mineNumber);
    int32_t** isFlagged = initaliseFlags(width, height, mineNumber);
    int32_t** isOpen = initaliseOpens(width, height, mineNumber);

    int32_t flagged = 0;

    // printMap(isMine, isFlagged, numberMine, isOpen, width, height, mineNumber, 1, 0);
    // printf("\n");
    while(1)
    {
        printMap(isMine, isFlagged, numberMine, isOpen, width, height, mineNumber, 0, 0);
        int32_t option;
        int32_t row, col;
        printf("Your Option (1: Open, 2: Flag): ");
        scanf("%d",&option);
        printf("Position (row column): ");
        scanf("%d %d",&row, &col);
        printf("\n");
        if( option == 2 )
        {
            if(isFlagged[row][col] == 0)
            {
                isFlagged[row][col] = 1;
                if(isMine[row][col]) flagged++;
            }
            else
            {
                isFlagged[row][col] = 0;
                if(isMine[row][col]) flagged--;
            }
            if (flagged == mineNumber) {
                printf("YOU WIN !!!\n");
                printMap(isMine, isFlagged, numberMine, isOpen, width, height, mineNumber, 1, 0);
                break;
            }

        }
        if( option == 1 )
        {
            if(isMine[row][col] == 1)
            {
                printf("YOU LOSE !!!!\n");
                printMap(isMine, isFlagged, numberMine, isOpen, width, height, mineNumber, 0, 1);
                break;
            }
            open(row, col, numberMine, isOpen, width, height, mineNumber);
        }

    }
}