#include <stdio.h>
#include <stdint.h>
int main()
{
    int32_t Gross = 0;
    int32_t Married = 0;
    int32_t people = 0;
    int32_t income = 0;
    int32_t Savings = 0;
    int32_t Tuition = 0;
    int32_t preschool = 0;
    int32_t disable = 0;
    int32_t Total = 0;
    printf("Gross salary:\n");
    scanf("%d", &Gross);
    printf("Married? (0/1):\n");
    scanf("%d", &Married);
    if(Married != 0 && Married != 1)
    {
        printf("error\n");
        return 0;
    }
    printf("How many people are there in your family:\n");
    scanf("%d", &people);

    printf("How many people in your family have income:\n");
    scanf("%d", &income);

    printf("Special Deduction for Savings and Investment:\n");
    scanf("%d", &Savings);
    printf("Special Deduction for Tuition:\n");
    scanf("%d", &Tuition);
    printf("How many preschool children:\n");
    scanf("%d", &preschool);
    printf("How many disable people:\n");
    scanf("%d", &disable);
    if(Married==0)
    {
        int X =Gross-(88000*people+200000*income+120000+270000*Savings+25000*Tuition+120000*preschool+200000*disable);
        if(X>=0&&X<=540000)
        {
            Total=X*5/100;
            printf("Total tax: %d\n", Total);
        }
        if(X>=540001&&X<=1210000)
        {
            Total=(X*12/100)-37800;
            printf("Total tax: %d\n", Total);
        }
        if(X>=1210001&&X<=2420000)
        {
            Total=(X*20/100)-134600;
            printf("Total tax: %d\n", Total);
        }
        if(X>=2420001&&X<=4530000)
        {
            Total=(X*30/100)-376600;
            printf("Total tax: %d\n", Total);
        }
        if(X>=4530001)
        {
            Total=(X*40/100)-829600;
            printf("Total tax: %d\n", Total);
        }
    }
    if(Married==1)
    {
        int Y =Gross-(88000*people+200000*income+240000+270000*Savings+25000*Tuition+120000*preschool+200000*disable);
        if(Y>=0&&Y<=540000)
        {
            Total=Y*5/100;
            printf("Total tax: %d\n", Total);
        }
        if(Y>=540001&&Y<=1210000)
        {
            Total=(Y*12/100)-37800;
            printf("Total tax: %d\n", Total);
        }
        if(Y>=1210001&&Y<=2420000)
        {
            Total=(Y*20/100)-134600;
            printf("Total tax: %d\n", Total);
        }
        if(Y>=2420001&&Y<=4530000)
        {
            Total=(Y*30/100)-376600;
            printf("Total tax: %d\n", Total);
        }
        if(Y>=4530001)
        {
            Total=(Y*40/100)-829600;
            printf("Total tax: %d\n", Total);
        }
    }
    return 0;
}