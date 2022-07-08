#pragma once
#include <stdint.h>
void print_card( const uint8_t * );
int32_t sort_card( uint8_t player[13], int32_t ( * compare)( int32_t a,
int32_t b ) );