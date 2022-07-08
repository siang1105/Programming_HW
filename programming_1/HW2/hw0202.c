#include <stdio.h>
#include <stdint.h>
int main()
{
    float x11 = 0;
    float y11 = 0;
    float x12 = 0;
    float y12 = 0;
    float x21 = 0;
    float y21 = 0;
    float x22 = 0;
    float y22 = 0;
    float m1 = 0;
    float m2 = 0;
    float yans = 0;
    float yans2 = 0;
    printf("Please enter the first line:\n");
    scanf(" (%f,%f),(%f,%f)" ,&x11,&y11,&x12,&y12);
    printf("Please enter the second line:\n");
    scanf(" (%f,%f),(%f,%f)" ,&x21,&y21,&x22,&y22);
    if( x11-x12 == 0 && x21-x22 != 0 )
    {
        m2 = (y22-y21)/(x22-x21);
        yans = (m2*x11)+(y22-m2*x22);
        printf("Intersection:(%.2f,%.2f)\n",x11,yans);
    }
    else if( x21-x22 == 0 && x11-x12 != 0 )
    {
        m1 = (y12-y11)/(x12-x11);
        yans2 = (m1*x21)+(y12-m1*x12);
        printf("Intersection:(%.2f,%.2f)\n",x21,yans2);
    }
    else{
    m1 =(y12-y11)/(x12-x11);

    m2 =(y22-y21)/(x22-x21);
    if(m1==m2)
    {
        if(y11-(m1*x11)==y21-(m2*x21))
        {
            printf("the intersection does not exist,two lines overlap\n");
        }
        else
        {
            printf("the intersection does not exist,two lines parallel\n");
        }
    }
    if(m1!=m2)
    {
        float X = (y21-(m2*x21)-y11+(m1*x11))/(m1-m2);
        float Y = (m1*X)+y11-(m1*x11);
        printf("Intersection:(%.2f,%.2f)\n",X,Y);

    }
    }
}
    
    
    
 
    
    