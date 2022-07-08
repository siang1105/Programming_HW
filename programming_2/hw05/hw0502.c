#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

int main(){
    
    FILE* pFile = NULL;
    int64_t pre_sum = 0;
    int64_t pre_idle = 0;
    while(1){

        char buf[128] = {0};
        int64_t time_sum = 0;
        int64_t time[10] = {0};
	    int64_t user = 0;
	    int64_t nice = 0;
	    int64_t system = 0;
	    int64_t idle = 0;
	    int64_t iowait = 0;
	    int64_t irq = 0;
	    int64_t softirq = 0;
	    int64_t last = 0;
	    int64_t x = 0;
	    int64_t y = 0;
        if((pFile = popen("head -n 1 /proc/stat", "r")) == NULL){
                printf("Error\n");
                return 0;
        }
        fgets(buf, 128, pFile);
        sscanf(buf, "%*s %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &last, &x, &y);
        time_sum = user + nice + system + idle + iowait + irq + softirq + last + x + y;
        printf("CPU usage: %.2lf%%\n", 100.0 - 100.0 * (idle - pre_idle) / (time_sum - pre_sum));
        pre_sum = time_sum;
        pre_idle = idle;
        pclose(pFile);
        sleep(1);
    }

    return 0;
}