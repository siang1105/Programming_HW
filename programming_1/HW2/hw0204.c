#include <stdio.h>
#include <stdint.h>
int main()
{
    int32_t year1, month1, day1, year2, month2, day2;
    const int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Date Format: YYYY/MM/DD\n");
    printf("Start Date:\n");
    scanf("%d/%d/%d",&year1,&month1,&day1);
    if(year1<0)
    {
        printf("error year!\n");
        return 1;
    }
    if(month1>12||month1<1)
    {
        printf("error month!\n");
        return 1;
    }
    
    if((year1%4==0&&year1%100!=0)||year1%400==0)
        {
            if(month1==2)
            {
                if(day1<0||day1>29)
                {
                printf("error day!\n");
                return 1;
                }
            }
        }
    else
        {
           if(month1==2)
            {
                if(day1<0||day1>28)
                {
                printf("error day!\n"); 
                return 1;
                }
            }
        }
    if(month1==1||month1==3||month1==5||month1==7||month1==8||month1==10||month1==12) 
    {
        if(day1<0||day1>31) 
        {
        printf("error day!\n");
        return 1;
        }
        
    }
    if(month1==4||month1==6||month1==9||month1==11)
    {
        if(day1<0||day1>30) 
        {
        printf("error day!\n");
        return 1;
        }
    }
    printf("End Date:\n");
    scanf("%d/%d/%d",&year2,&month2,&day2);
    if(year2<0)
    {
        printf("error year!\n");
        return 1;
    }
    if(month2>12||month2<1)
    {
        printf("error month!\n");
        return 1;
    }
    
    if((year2%4==0&&year2%100!=0)||year2%400==0)
        {
            if(month2==2)
            {
                if(day2<0||day2>29) 
                {
                printf("error day!\n");
                return 1;
                }
            }
        }
    else
        {
           if(month2==2)
            {
                if(day2<0||day2>28) 
                {
                printf("error day!\n");
                return 1;
                } 
            }
        }
    if(month2==1||month2==3||month2==5||month2==7||month2==8||month2==10||month2==12) 
    {
        if(day2<0||day2>31) 
        {
        printf("error day!\n");
        return 1;
        }
    }
    if(month2==4||month2==6||month2==9||month2==11)
    {
        if(day2<0||day2>30) 
        {
        printf("error day!\n");
        return 1;
        }
    }

    
    
    int32_t duration1 = 365 * year1;

    if (month1 > 2) {
        duration1 += year1 / 4 - year1 / 100 + year1 / 400;
    } else {
        duration1 += (year1 - 1) / 4 - (year1 - 1) / 100 + (year1 - 1) / 400;
    }

    duration1 += day1;

    for(int i = 0 ; i < month1-1 ; i++ )
    {
        duration1 += m[i];
    }

    
    
    int32_t duration2 = 365 * year2;

    if (month2 > 2) {
        duration2 += year2 / 4 - year2 / 100 + year2 / 400;
    } else {
        duration2 += (year2 - 1) / 4 - (year2 - 1) / 100 + (year2 - 1) / 400;
    }

    duration2 += day2;

    for(int i = 0 ; i < month2-1 ; i++ )
    {
        duration2 += m[i];
    }
    printf("Duration: %d\n", duration2-duration1);
    return 0;
}
