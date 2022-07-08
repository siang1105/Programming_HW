#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
void  myperror(char * str){
     extern int errno;
     char *error = strerror(errno);
     printf("%s: %s\n",str,error);
}
int main(){
    FILE *fp;
    fp = fopen("~/aaa.txt","r+");
    if(NULL==fp){
        myperror("openerror");
    }
    return 0;
}
