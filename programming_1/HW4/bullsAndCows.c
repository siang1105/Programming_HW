#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int generate(int answer[]){
    srand(time(0));
    int random;
    do {
        random = (rand() % 10000);
        answer[0] = (random/1000) % 10;
        answer[1] = (random/100) % 10;
        answer[2] = (random/10) % 10;
        answer[3] = random % 10;
    } while (answer[0]==answer[1]||answer[1]==answer[2]||answer[2]==answer[3]||answer[0]==answer[2]||answer[1]==answer[3]||answer[0]==answer[3]);
    return random;
}

void bullsAndCows (int answer[])
{
    
    int32_t random = generate(answer);

    /*do {
        random = (rand() % 9000) + 1000;
        answer[0] = (random/1000) % 10;
        answer[1] = (random/100) % 10;
        answer[2] = (random/10) % 10;
        answer[3] = random % 10;
    } while (answer[0]==answer[1]||answer[1]==answer[2]||answer[2]==answer[3]||answer[0]==answer[2]||answer[1]==answer[3]||answer[0]==answer[3]);*/


    int32_t counter = 0;
    int32_t guess1;
        do {
        counter++;
        printf("Round %d >>> \n", counter);
        printf("Your Guess: ");
        scanf("%d",&guess1);
        int32_t g4 = guess1 % 10;
        int32_t g3 = (guess1/10) % 10;
        int32_t g2 = (guess1/100) % 10;
        int32_t g1 = (guess1/1000) % 10;
        int32_t guess[4] = { g1, g2, g3, g4 };
        if( guess1 > 9999 )
        {
            printf("\033[33mResponse: Invalid Guess\n\033[0m");
            continue;
        }
        if(guess[0]==guess[1]||guess[1]==guess[2]||guess[2]==guess[3]||guess[0]==guess[2]||guess[1]==guess[3]||guess[0]==guess[3])
        {
            printf("\033[33mResponse: Invalid Guess\n\033[0m");
            continue;
        }
        
        if(guess[0]==answer[0]&&guess[1]==answer[1]&&guess[2]==answer[2]&&guess[3]==answer[3])
        {
            printf("\033[33mResponse: Bingo! Congratulations.\n\033[0m");
            return;
        }
        
        else if((guess[0]==answer[0]&&guess[1]==answer[1]&&guess[2]==answer[2])||(guess[1]==answer[1]&&guess[2]==answer[2]&&guess[3]==answer[3])||(guess[0]==answer[0]&&guess[2]==answer[2]&&guess[3]==answer[3])||(guess[0]==answer[0]&&guess[1]==answer[1]&&guess[3]==answer[3]))
        {
            printf("\033[33mResponse: 3 A\033[0m ");
            
        }
        else if((guess[0]==answer[0]&&guess[1]==answer[1])||(guess[1]==answer[1]&&guess[2]==answer[2])||(guess[2]==answer[2]&&guess[3]==answer[3])||(guess[0]==answer[0]&&guess[2]==answer[2])||(guess[1]==answer[1]&&guess[3]==answer[3])||(guess[0]==answer[0]&&guess[3]==answer[3]))
        {
            printf("\033[33mResponse: 2 A\033[0m");
        
        }
        else if(guess[0]==answer[0]||guess[1]==answer[1]||guess[2]==answer[2]||guess[3]==answer[3])
        {
            printf("\033[33mResponse: 1 A\033[0m ");
        }

        if((guess[0]==answer[1]||guess[0]==answer[2]||guess[0]==answer[3])&&(guess[1]==answer[0]||guess[1]==answer[2]||guess[1]==answer[3])&&(guess[2]==answer[0]||guess[2]==answer[1]||guess[2]==answer[3])&&(guess[3]==answer[0]||guess[3]==answer[1]||guess[3]==answer[2]))
        {
            printf("\033[33m 4 B\n\033[0m");
        }
        else if(((guess[0]==answer[1]||guess[0]==answer[2]||guess[0]==answer[3])&&(guess[1]==answer[0]||guess[1]==answer[2]||guess[1]==answer[3])&&(guess[2]==answer[0]||guess[2]==answer[1]||guess[2]==answer[3]))
            ||((guess[1]==answer[0]||guess[1]==answer[2]||guess[1]==answer[3])&&(guess[2]==answer[0]||guess[2]==answer[1]||guess[2]==answer[3])&&(guess[3]==answer[0]||guess[3]==answer[1]||guess[3]==answer[2]))
            ||((guess[0]==answer[1]||guess[0]==answer[2]||guess[0]==answer[3])&&(guess[2]==answer[0]||guess[2]==answer[1]||guess[2]==answer[3])&&(guess[3]==answer[0]||guess[3]==answer[1]||guess[3]==answer[2]))
            ||((guess[0]==answer[1]||guess[0]==answer[2]||guess[0]==answer[3])&&(guess[1]==answer[0]||guess[1]==answer[2]||guess[1]==answer[3])&&(guess[3]==answer[0]||guess[3]==answer[1]||guess[3]==answer[2])))
            {
                printf("\033[33m 3 B\n\033[0m");
            }
        else if(((guess[0]==answer[1]||guess[0]==answer[2]||guess[0]==answer[3])&&(guess[1]==answer[0]||guess[1]==answer[2]||guess[1]==answer[3]))
            ||((guess[1]==answer[0]||guess[1]==answer[2]||guess[1]==answer[3])&&(guess[2]==answer[0]||guess[2]==answer[1]||guess[2]==answer[3]))
            ||((guess[2]==answer[0]||guess[2]==answer[1]||guess[2]==answer[3])&&(guess[3]==answer[0]||guess[3]==answer[1]||guess[3]==answer[2]))
            ||((guess[0]==answer[1]||guess[0]==answer[2]||guess[0]==answer[3])&&(guess[2]==answer[0]||guess[2]==answer[1]||guess[2]==answer[3]))
            ||((guess[1]==answer[0]||guess[1]==answer[2]||guess[1]==answer[3])&&(guess[3]==answer[0]||guess[3]==answer[1]||guess[3]==answer[2]))
            ||((guess[0]==answer[1]||guess[0]==answer[2]||guess[0]==answer[3])&&(guess[3]==answer[0]||guess[3]==answer[1]||guess[3]==answer[2])))
            {
                printf("\033[33m 2 B\n\033[0m");
            }
        else if(guess[0]==answer[1]||guess[0]==answer[2]||guess[0]==answer[3]||guess[1]==answer[0]||guess[1]==answer[2]||guess[1]==answer[3]||guess[2]==answer[0]||guess[2]==answer[1]||guess[2]==answer[3]||guess[3]==answer[0]||guess[3]==answer[1]||guess[3]==answer[2])
        {
            printf("\033[33m 1 B\n\033[0m");
        }
        else
        {
            printf("\n");
        }
    } while (guess1 != random);

    return;
}