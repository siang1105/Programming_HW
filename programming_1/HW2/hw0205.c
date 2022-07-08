#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int getRank(int card) {
    if (card > 13 && card <27) {
        return card - 13;
    }
    if (card > 26 && card < 40){
        return card - 26;
    }
    if (card > 39 && card <53){
        return card - 39;
    }
    return card;
}

// 1 spades
// 2 heart
// 3 diamond
// 4 clubs
int getSuit(int card) {
    if (card < 14) return 1;
    if (card > 13 && card <27) return 2;
    if (card > 26 && card < 40) return 3;
    return 4;
}

int compare (const void *a, const void *b) {
    int card1 = *(int*)a;
    int card2 = *(int*)b;
    int result = getRank(card1) - getRank(card2);
    return result;
}



int main(){
    int32_t encoded[5] = {0, 0, 0, 0, 0};

    printf("Please enter 5 cards:");
    
    if(scanf("%d %d %d %d %d", &encoded[0], &encoded[1], &encoded[2], &encoded[3], &encoded[4]) != 5)
    {
      printf( "Wrong Input!\n" );
       return 0;
    }
    for( int i = 0 ; i<5 ; i++ )
    {
        if(encoded[i]<1||encoded[i]>52)
        {
            printf("Error: invalid card");
            return 0;
        }

        // todo: duplicate cards
    }
    
    qsort(&encoded, 5, sizeof(int32_t), compare);

    if (encoded[0]==encoded[1] || encoded[1]==encoded[2] || encoded[2]==encoded[3] || encoded[3] == encoded[4]){
        printf("Error: duplicate cards\n");
        return 0;
    }



    int32_t suits[] = {
        getSuit(encoded[0]),
        getSuit(encoded[1]),
        getSuit(encoded[2]),
        getSuit(encoded[3]),
        getSuit(encoded[4])
    };
    int32_t ranks[] = {
        getRank(encoded[0]),
        getRank(encoded[1]),
        getRank(encoded[2]),
        getRank(encoded[3]),
        getRank(encoded[4])
    };

    int isAllSameSuit; 
    int isStraight;

    if (suits[0] == suits[1] && suits[0] == suits[2] && suits[0] == suits[3] && suits[0] == suits[4]) {
        isAllSameSuit = 1;
    } else {
        isAllSameSuit = 0;
    }

    if (ranks[0] +1 == ranks[1] && ranks[1] +1 == ranks[2] && ranks[2]+1 == ranks[3] && ranks[3] +1 == ranks[4]){
        isStraight = 1;
    } else {
        isStraight = 0;
    }
    if (isAllSameSuit == 1 && isStraight == 1){
        printf("Straight flush\n");
        return 0 ;
    }
    //11112
    if (ranks[3]!= ranks[4]&& ranks[0] == ranks[1] && ranks[1] == ranks[2] && ranks[2] == ranks[3]){
        printf("Four of a kind\n");
        return 0 ;
    }
    //12222
    if (ranks[0]!= ranks[1]&& ranks[1] == ranks[2] && ranks[2] == ranks[3] && ranks[3] == ranks[4]){
        printf("Four of a kind\n");
        return 0 ;
    }
    //22233
    if (ranks[2]!= ranks[3] && ranks[0] == ranks[1] && ranks[1] == ranks[2] && ranks[3] == ranks[4]){
        printf("Full house\n");
        return 0;
    }
    //22333
    if (ranks[1]!= ranks[2] && ranks[0] == ranks[1] && ranks[2] == ranks[3] && ranks[3] == ranks[4]){
        printf("Full house\n");
        return 0;
    }       
    if (isAllSameSuit == 1){
        printf("Flush\n");
        return 0;
    }
    if (isStraight == 1){
        printf("Straight\n");
        return 0;
    }
    //22234
    if (ranks[2]!=ranks[3] && ranks[3]!=ranks[4] && ranks[0]==ranks[1] && ranks[1] == ranks[2]){
        printf("Three of a kind\n");
        return 0;
    }
    //12223
    if (ranks[0]!=ranks[1] && ranks[3]!=ranks[4] && ranks[1]==ranks[2] && ranks[2] == ranks[3]){
        printf("Three of a kind\n");
        return 0;
    }
    //12333
    if (ranks[0]!=ranks[1] && ranks[1]!=ranks[2] && ranks[2]==ranks[3] && ranks[3] == ranks[4]){
        printf("Three of a kind\n");
        return 0;
    }
    //22334
    if (ranks[1]!=ranks[2] && ranks[3]!=ranks[4] && ranks[0] == ranks[1] && ranks[2]==ranks[3]){
        printf("Two pair\n");
        return 0;
    }
    //12233
    if (ranks[0]!=ranks[1] && ranks[2]!=ranks[3] && ranks[1] == ranks[2] && ranks[3]==ranks[4]) {
        printf("Two pair\n");
        return 0;
    }
    //11233
    if (ranks[1]!=ranks[2] && ranks[2]!=ranks[3] && ranks[0] == ranks[1] && ranks[3]==ranks[4]) {
        printf("Two pair\n");
        return 0;
    }
    //11234
    if (ranks[1]!=ranks[2] && ranks[2]!=ranks[3] && ranks[3]!=ranks[4] && ranks[0]==ranks[1]){
        printf("One pair\n");
        return 0;
    }
    //12234
    if (ranks[0]!=ranks[1] && ranks[2]!=ranks[3] && ranks[3]!=ranks[4] && ranks[1]==ranks[2]){
        printf("One pair\n");
        return 0;
    }
    //12334
    if (ranks[0]!=ranks[1] && ranks[1]!=ranks[2] && ranks[3]!=ranks[4] && ranks[2]==ranks[3]){
        printf("One pair\n");
        return 0;
    }
    //12344
    if (ranks[0]!=ranks[1] && ranks[1]!=ranks[2] && ranks[2]!=ranks[3] && ranks[3]==ranks[4]){
        printf("One pair\n");
        return 0;
    }
    printf("High card\n");
    return 0;
}