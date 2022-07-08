#include<stdio.h>
#include<stdint.h>
int main()
{
    int32_t payment = 0;
    int32_t firstFiveYear1 = 0;
    int32_t firstFiveYear2= 0;
    int32_t firstFiveYear3= 0;
    int32_t firstFiveYear4= 0;
    int32_t firstFiveYear5= 0;
    int32_t insuranceFee = 0;
    int32_t monthlyFee = 0;
    int32_t age = 0;
    int32_t years = 0;
    int32_t rate = 0;
    int32_t firstFiveYear[5];
    printf("SIP Plan\n");
    printf("Annually payment:");
    scanf("%d",&payment);
    printf("Insurance fee in the first five years (0 is assumed afterwards):");
    scanf("%d,%d,%d,%d,%d",&firstFiveYear[0],&firstFiveYear[1],&firstFiveYear[2],&firstFiveYear[3],&firstFiveYear[4]);
    printf("Insurance fee off:");
    scanf("%d",&insuranceFee);
    printf("Monthly insurance processing fee:");
    scanf("%d",&monthlyFee);
    printf("Age:");
    scanf("%d",&age);
    if( age <= 0 )
    {
        printf("error");
        return 0;
    }
    printf("How many years of payment:");
    scanf("%d",&years);
    printf("Expected annual return on investment rate:");
    scanf("%d",&rate);
    printf("------------------------------\nYour Payment and Account Value Table\n");
    
    int32_t a = age;
    int32_t month = 1;
    int32_t firstYear = 2;
    double sunny = 1;
    int32_t paymentsum = payment;
    sunny = payment*(1-firstFiveYear[0]/100.0+insuranceFee/100.0)-(100*(age-20)+2000);//第一年第一個月
    for( month = 2; month <= 12; month++ )
    {
        sunny = (sunny-monthlyFee)*(1+(rate/100.0/12.0));
    }
    printf("%d: %d, %lf\n",age,payment,sunny);
    for( firstYear = 2; firstYear <= 5; firstYear++ )
    {
        age++;
        sunny += payment*(1-firstFiveYear[firstYear-1]/100.0+insuranceFee/100.0)-(100*(age-20)+2000);
        for( month = 1; month <= 12; month++ )
        {
            sunny = (sunny-monthlyFee)*(1+(rate/100.0/12));
        }
        paymentsum += payment;
        printf("%d: %d, %lf\n",age,paymentsum,sunny);
    }

    
    for( int32_t payYear = 6; payYear <= years; payYear++ )
    {
        age++;
        sunny += payment-(100*(age-20)+2000);
        for( month = 1; month <= 12; month++ )
        {
            sunny = (sunny-monthlyFee)*(1+(rate/100.0/12));
        }
        paymentsum += payment;
        printf("%d: %d, %lf\n",age,paymentsum,sunny);
    }
    age++;
    while( age <= 100 )
    {
        sunny -= (100*(age-20)+2000);
        for( month = 1; month <= 12; month++ )
        {
            sunny = (sunny-monthlyFee)*(1+(rate/100.0/12));
        }
        printf("%d: %d, %lf\n",age,paymentsum,sunny);
        age++;
    }
}