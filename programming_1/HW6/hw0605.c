#include <stdio.h>
#include <stdint.h>
#include "poker.h"
#include "test.h"
int32_t func01 ( int32_t a, int32_t b)
    {
        a = a % 13;
        b = b % 13;
        if( a == 0 )
        {
            a = 13;
        }
        if( b == 0 )
        {
            b = 13;
        }
        if( a == 1 )
        {
            a = 14;
        }
        if( b == 1 )
        {
            b = 14;
        }
        return a < b;
    }
    int32_t func02 ( int32_t a, int32_t b)
    {
        a = a % 13;
        b = b % 13;
        if( a == 0 )
        {
            a = 13;
        }
        if( b == 0 )
        {
            b = 13;
        }
        if( a == 1 )
        {
            a = 14;
        }
        if( b == 1 )
        {
            b = 14;
        }
        if( a == 2 )
        {
            a = 15;
        }
        if( b == 2 )
        {
            b = 15;
        }
        return b > a;
    }
    int32_t func03 ( int32_t a, int32_t b)
    {
        int32_t a_suit = 0;
        int32_t b_suit = 0;
        if( a > 0 && a < 14 )
        {
            a_suit = 4;
        }
        if( a > 13 && a < 27 )
        {
            a_suit = 3;
        }
        if( a > 26 && a < 40 )
        {
            a_suit = 2;
        }
        if( a > 39 && a < 53 )
        {
            a_suit = 1;
        }
        if( b > 0 && b < 14 )
        {
            b_suit = 4;
        }
        if( b > 13 && b < 27 )
        {
            b_suit = 3;
        }
        if( b > 26 && b < 40 )
        {
            b_suit = 2;
        }
        if( b > 39 && b < 53 )
        {
            b_suit = 1;
        }
        
        if( a_suit == b_suit )
        {
            a = a % 13;
            b = b % 13;
            if( a == 0 )
            {
                a = 13;
            }
            if( b == 0 )
            {
                b = 13;
            }
            if( a == 1 )
            {
                a = 14;
            }
            if( b == 1 )
            {
                b = 14;
            }
            return a < b;
        }
        return a_suit < b_suit;
    }
int main()
{
    
    printf( "Before:\n" );
    print_card( player1 );
    print_card( player2 );
    print_card( player3 );
    print_card( player4 );
    printf( "Type 01:\n" );
    sort_card( player1 , func01 );
    sort_card( player2 , func01 );
    sort_card( player3 , func01 );
    sort_card( player4 , func01 );
    print_card( player1 );
    print_card( player2 );
    print_card( player3 );
    print_card( player4 );
    printf( "Type 02:\n" );
    sort_card( player1 , func02 );
    sort_card( player2 , func02 );
    sort_card( player3 , func02 );
    sort_card( player4 , func02 );
    print_card( player1 );
    print_card( player2 );
    print_card( player3 );
    print_card( player4 );
    printf( "Type 03:\n" );
    sort_card( player1 , func03 );
    sort_card( player2 , func03 );
    sort_card( player3 , func03 );
    sort_card( player4 , func03 );
    print_card( player1 );
    print_card( player2 );
    print_card( player3 );
    print_card( player4 );
    return 0;
}