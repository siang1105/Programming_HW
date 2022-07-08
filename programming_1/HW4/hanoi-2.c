#include <stdio.h>
#include <stdint.h>
void hanoi2 (int32_t n)
{
        int32_t A[21]={21,0};
        int32_t B[21]={21,0};
        int32_t C[21]={21,0};
        int32_t A_top = n;
        int32_t B_top = 0;
        int32_t C_top = 0;
        for(int32_t i = 1; i <= n; i++ )
        {
            A[i] = n - i + 1;
        }
        if( n % 2 == 0) //偶數
        {
            while(1)
            {
                //A<=>c
                if(A[A_top]<C[C_top])
                {
                    C[C_top+1]=A[A_top];
                    printf("move disk %d to rod 3\n",A[A_top]);
                    A[A_top]=0;
                    A_top--;
                    C_top++;
                }
                else //A<=C
                {
                    A[A_top+1]=C[C_top];
                    printf("move disk %d to rod 1\n",C[C_top]);
                    C[C_top] = 0;
                    C_top--;
                    A_top++;
                }
                //break condition
                if(B[n] == 1)
                {
                    break;
                }
                //A<=>B
                if(A[A_top]<B[B_top])
                {
                    B[B_top+1] = A[A_top];
                    printf("move disk %d to rod 2\n",A[A_top]);
                    A[A_top] = 0;
                    A_top--;
                    B_top++;
                }
                else //A<=B
                {
                    A[A_top+1] = B[B_top];
                    printf("move disk %d to rod 1\n",B[B_top]);
                    B[B_top] = 0;
                    B_top--;
                    A_top++;
                }
                //break condition
                if(B[n] == 1)
                {
                    break;
                }
                //B<=>C
                if(C[C_top]<B[B_top])
                {
                    B[B_top+1] = C[C_top];
                    printf("move disk %d to rod 2\n",C[C_top]);
                    C[C_top] = 0;
                    C_top--;
                    B_top++;
                }
                else //B=>C
                {
                    C[C_top+1] = B[B_top];
                    printf("move disk %d to rod 3\n",B[B_top]);
                    B[C_top] = 0;
                    B_top--;
                    C_top++;
                }
                //break condition
                if(B[n] == 1)
                {
                    break;
                }
            }
        }
        
    
    else
    {
        while(1)
        {
            //A<=>B
            if(A[A_top]<B[B_top])//A=>B
            {
                B[B_top+1]=A[A_top];
                printf("move disk %d to rod 2\n",A[A_top]);
                A[A_top] = 0;
                A_top--;
                B_top++;
            }
            else //A<=B
            {
                A[A_top+1] = B[B_top];
                printf("move disk %d to rod 1\n",B[B_top]);
                B[B_top] = 0;
                B_top--;
                A_top++;
            }
            //break condition
            if(B[n] == 1)
            {
                break;
            }
            //A<=>C
            if(A[A_top]<C[C_top])
            {
                C[C_top+1] = A[A_top];
                printf("move disk %d to rod 3\n",A[A_top]);
                A[A_top] = 0;
                A_top--;
                C_top++;
            }
            else //A<=C
            {
                A[A_top+1] = C[C_top];
                printf("move disk %d to rod 1\n",C[C_top]);
                C[C_top] = 0;
                C_top--;
                A_top++;
            }
            //break condition
            if(B[n] == 1)
            {
                break;
            }
            //B<=>C
            if(C[C_top]<B[B_top])
            {
                B[B_top+1] = C[C_top];
                printf("move disk %d to rod 2\n",C[C_top]);
                C[C_top] = 0;
                C_top--;
                B_top++;
            }
            else //B=>C
            {
                C[C_top+1] = B[B_top];
                printf("move disk %d to rod 3\n",B[B_top]);
                B[B_top] = 0;
                B_top--;
                C_top++;
            }
            //break condition
            if(B[n] == 1)
            {
                break;
            }
        }
    }
    
}