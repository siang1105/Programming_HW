#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "redoAndUndo.h"
int32_t save[10] = {0};
int32_t undo[10] = {0};
int32_t save_index = 0;
int32_t undo_index = 0;
void full()
{
    if( save_index == 10 )
    {
        for( int32_t i = 0; i < 10; i++ )
        {
            save[i] = save[i+1];
        }
        save_index--;
    }
    
}

void redoAndundo (int32_t input)
{
    if( input == 0 )
    {
        printf("Result: ");
        for(int32_t i = 0; i < save_index; i++ )
        {
            printf("%d ",save[i]);
        }
        printf("\n");
        return;
    }
    else if( input == -1 && save_index > 0 )
    {
        undo[undo_index] = save[save_index - 1];
        save_index--;
        undo_index++;
    }
    else if ( input == -2 && undo_index != 0 )
    {
        save[save_index] = undo[undo_index - 1];
        save_index++;
        undo_index--;
    }
    else if( input != -1 && input != -2 )
    {
        full();
        if( undo_index > 0 )
        {
            for(int32_t i = 0; i < 10; i++ )
            {
                undo[i] = 0;
                undo_index = 0;
            }
        }
        save[save_index] = input;
        save_index++;
    }
    
}

// void printArr()
// {
//     // printf("Result: ");
//     for(int32_t i = 0; i < save_index; i++ )
//     {
//         printf("%d ",save[i]);
//     }
//     // printf("\n");
// }