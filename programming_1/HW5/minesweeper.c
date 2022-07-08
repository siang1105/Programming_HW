#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
int32_t** initaliseMine (int32_t** numberMine, int32_t width,int32_t height,int32_t mineNumber)
{
    int32_t** isMine = (int32_t **) malloc(height * sizeof(int32_t*));
    for(int32_t i = 0; i < height; i++ )
    {
        isMine[i] = (int32_t *) calloc(width,sizeof(int32_t));
    }

    int32_t count = 0;
    int32_t range = width * height;
    while( count < mineNumber )
    {
        int32_t random = (rand() % range) + 1; 
        int32_t row = random / width;
        int32_t column = (random % width) - 1;
        if( column == -1 )
        {
            row = row - 1;
            column = width - 1;
        }
        if( isMine[row][column] == 1) continue;
        
        count++;

        isMine[row][column] = 1;

        if( row > 0 ) {
            numberMine[row-1][column] ++;

            if( column + 1 < width ) 
                numberMine[row-1][column+1] ++;
            if( column > 0 )
                numberMine[row-1][column-1] ++;
        }
        if( row + 1 < height )
        {
            numberMine[row+1][column] ++;
            if( column + 1 < width )
                numberMine[row+1][column+1] ++;
            if( column > 0 )
                numberMine[row+1][column-1] ++;
        }
        numberMine[row][column] ++;
        if( column + 1 < width )
            numberMine[row][column+1] ++;
        if( column > 0 )
            numberMine[row][column-1] ++;
        

        // printf("row = %d, col = %d\n", row, column);
    }

    return isMine;
}

void open (int32_t row, int32_t col, int32_t** numberMine, int32_t** isOpen, int32_t width, int32_t height, int32_t mineNumber) {
    isOpen[row][col] = 1;

    if(numberMine[row][col] > 0)
    {
        return;
    }

    if(row > 0)
    {

        if(!isOpen[row-1][col])
        {
            open(row - 1, col, numberMine, isOpen, width, height, mineNumber);
        }
        if( col + 1 < width )
        {
            if(!isOpen[row-1][col+1])
            {
                open(row - 1, col + 1, numberMine, isOpen, width, height, mineNumber);
            }
        }
        if( col > 0 )
        {
            if(!isOpen[row-1][col-1])
            {
                open(row - 1, col - 1, numberMine, isOpen, width, height, mineNumber);
            }
        }
    }
    if( col > 0 )
    {
        if(!isOpen[row][col-1])
        {
            open(row, col - 1, numberMine, isOpen, width, height, mineNumber);
        }
    }
    if( col + 1 < width )
    {
        if(!isOpen[row][col+1])
        {
            open(row, col + 1, numberMine, isOpen, width, height, mineNumber);
        }
    }
    if( row + 1 < height )
    {

        if( col > 0 )
        {
            if(!isOpen[row+1][col-1])
            {
                open(row + 1, col - 1, numberMine, isOpen, width, height, mineNumber);
            }
        }
    
        if(!isOpen[row+1][col])
        {
            open(row + 1, col, numberMine, isOpen, width, height, mineNumber);
        }  
        if( col + 1 < width )
        {
            if(!isOpen[row+1][col+1])
            {
                open(row + 1, col + 1, numberMine, isOpen, width, height, mineNumber);
            }
        }
    }

    
    
}

void printMap (int32_t** isMine, int32_t** isFlaged, int32_t** numberMine, int32_t** isOpen, int32_t width, int32_t height, int32_t mineNumber, int32_t showEverything, int32_t showAllMines)
{
    int32_t length = 4;
    printf("    ");
    for( int32_t i = 0; i < width; i++ )
    {
        if( i < 10 )
        {
            length += printf("0");
        }
        length += printf("%d ",i);
    }
    printf("\n");
    for(int32_t i = 0; i < length; i++ )
    {
        printf("-");
    }
    printf("\n");
    for( int32_t i = 0; i < height; i++ )
    {
        if( i < 10 )
        {
            printf("0");
        }
        printf("%d",i);
        for( int32_t j = 0; j < width; j++ )
        {
            if( j == 0)
            {
                printf("| ");
            }
            else
            {
                printf("  ");
            }

            // if (isMine[i][j])
            // {
            //     printf("M");
            //     continue;
            // }
            // // else
            // //     printf(" ");

            // if(numberMine[i][j] == 0)
            // {
            //     printf(" ");
            // }
            // else
            // {
            //     printf("%d", numberMine[i][j]);
            // }

            if (showAllMines && isMine[i][j]) {
                printf("M");
            }
            else if (isFlaged[i][j] == 1)
            {
                printf("F");
            }
            else
            {
                if (isOpen[i][j] || showEverything)
                {
                    if (isMine[i][j])
                    {
                        printf("M");
                    } 
                    else if(numberMine[i][j] == 0)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("%d", numberMine[i][j]);
                    }
                }
                else
                {
                    printf("*");
                }
            }
            
            
        }
        printf("\n");
    }
    printf("\n");
}
int32_t** initaliseFlags (int32_t width,int32_t height,int32_t mineNumber)
{
    int32_t** isFlaged = (int32_t **) malloc(height * sizeof(int32_t*));
    for(int32_t i = 0; i < height; i++ )
    {
        isFlaged[i] = (int32_t *) calloc(width,sizeof(int32_t));
    }
    return isFlaged;
}

int32_t** initaliseNumbers (int32_t width,int32_t height,int32_t mineNumber)
{
    int32_t** numberMine = (int32_t **) malloc(height * sizeof(int32_t*));
    for(int32_t i = 0; i < height; i++ )
    {
        numberMine[i] = (int32_t *) calloc(width,sizeof(int32_t));
    }
    return numberMine;
}


int32_t** initaliseOpens (int32_t width,int32_t height,int32_t mineNumber)
{
    int32_t** isOpen = (int32_t **) malloc(height * sizeof(int32_t*));
    for(int32_t i = 0; i < height; i++ )
    {
        isOpen[i] = (int32_t *) calloc(width,sizeof(int32_t));
    }
    return isOpen;
}

