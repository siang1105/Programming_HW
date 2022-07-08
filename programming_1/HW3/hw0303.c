#include<stdio.h>
#include<stdint.h>
int main()
{
    int32_t n1 = 0;
    int32_t n2 = 0;
    int32_t n3 = 0;
    int32_t n4 = 0;
    int32_t n5 = 0;
    int32_t n6 = 0;
    int32_t n7 = 0;
    int32_t kind = 0;
    printf("Start\n");
    printf("Please enter an integer:\n");
    scanf( "%d", &n1);

    if( n1 == 10 || n1 == 35){
        printf("S1\n");
        kind = 1;
    }
    else if( n1 == 11 ){
        printf("S3\n");
        kind = 3;

    }
    else if( n1 == 20 || n1 == 78){
        printf("S5\n");
        kind = 5;
    }
    else{
        kind = 0;
        printf("start\n");
    }
    int check = 0;
    do
    {
    while (kind == 0)
    {
        printf("Please enter an integer:\n");
        scanf( "%d", &n1);
        if( n1 == 10 || n1 == 35){
        printf("S1\n");
        kind = 1;
        }
        else if( n1 == 11 ){
        printf("S3\n");
        kind = 3;
        }
        else if( n1 == 20 || n1 == 78){
        printf("S5\n");
        kind = 5;
        }
        else{
        kind = 0;
        printf("start\n");
        }
    }
    while (kind == 1)
    {
        printf("Please enter an integer:\n");
        scanf( "%d", &n2);

        if( n2 == 12 || n2 == 36){
        printf("S6\n");
        kind = 6;
        }
        else if( n2 == 19 ){
        printf("S2\n");
        kind = 2;
        }
        else{
        kind = 1;
        printf("S1\n");
        }
    }
    while (kind == 3)
    {
        printf("Please enter an integer:\n");
        scanf( "%d", &n3);

        printf("S4\n");
        kind = 4;
    }
    while (kind == 5)
    {
        printf("Please enter an integer:\n");
        scanf( "%d", &n4);

        if( n4 == 2){
        printf("S6\n");
        kind = 6;
        }
        else if( n4 == 1 ){
        printf("S4\n");
        kind = 4;
        }
        else{
        kind = 0;
        printf("start\n");
        }
    }
    while (kind == 4)
    {
        printf("Please enter an integer:\n");
        scanf( "%d", &n5);

        printf("S6\n");
        kind = 6;
    }
    while (kind == 2)
    {
        printf("Please enter an integer:\n");
        scanf( "%d", &n6);
        if( n6 == 43){
        printf("S2\n");
        kind = 2;
        }
        else if( n6 == 99 ){
        printf("Final\n");
        check = 1;
        return 0;
        }
        else{
        kind = 0;
        printf("start\n");
        }
    }
    while (kind == 6)
    {
        printf("Please enter an integer:\n");
        scanf( "%d", &n7);
        if( n7 == 108){
        printf("Final\n");
        check = 1;
        return 0;
        }
        else{
        kind = 0;
        printf("start\n");
        }
    }
    }while (check != 1);
    return 0;
}
 