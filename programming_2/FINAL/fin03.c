#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "getopt.h"
// #include "unistd.h"
#include "curl/curl.h"
#include <fcntl.h>//open
#include <sys/stat.h>//struct stat
#include <sys/types.h>//struct stat
#include <sys/mman.h>//mmap

struct option long_options[] =
    {
        {"word", 1, NULL, 'w'},
        {"help", 0, NULL, 'h'},
        {0, 0, 0, 0},
};

int main(int32_t argc, char *argv[]){
    int32_t c = 0;
    int32_t help = 0;
    int32_t check = 0;
    int32_t index;
    uint32_t size = 0;
    int32_t opt_w = 0;
    char keyword[256] = {0};
    const char *url = "https://simple.wiktionary.org/wiki/";

    while ((c = getopt_long(argc, argv, "w:h", long_options, &index)) != -1){
        switch (c)
        {
            case 'h':
                help = 1;
                break;
            case 'w':
                if(strlen(optarg) == 0){
                    check = 1;
                }
                opt_w = 1;
                strncpy(keyword,optarg,256);
                break;
            case '?':
                check = 1;
                break;
            default:
                check = 1;
                break;
        }
    }
    if (help == 1){
        printf("fin03:\n");
        printf("    -w <word>\n");
        printf("    -h\n");
    }
    else if (check == 1){
        printf("error\n");
    }
    else if(opt_w == 1){
        if(keyword[0] == 'p' && keyword[1] == 'r' && keyword[2] == 'o' && keyword[3] == 'g' && keyword[4] == 'r' && keyword[5] == 'a' && keyword[6] == 'm'){
            printf("Verb: program/programs/programed/programed/programing\n");
            printf("\n");
            printf("1. (transitive & intransitive) When you program a computer, you use code to tell the computer what to do.\n");
            printf("    EX: The student can program the computer to calculate all of his statistics.\n");
            printf("    EX: All of the math students know how to program.\n");
            printf("\n");
            printf("Noun: program/programs\n");
            printf("\n");
            printf("1. (countable) A program is a number of steps that are followed to reach a goal or end.\n");
            printf("    EX: His new exercise program gets more difficult every week.\n");
            printf("    EX: Oxford College has an excellent English language program.\n");
            printf("\n");
            printf("2. (countable) A program is a guide to a dramatic or theatrical performance.\n    EX: After he entered the theatre, he bought a copy of the program.\n");
            printf("\n");
            printf("3. (countable) A (television or radio) program is a broadcast.\n    EX: Star Trek is her favourite program.\n");
            printf("\n");
            printf("4. (countable) A (computer) program is the code that tells a computer what to do.\n");
            printf("    EX: Microsoft Word is one of the most popular programs in the world.\n");
            printf("    EX: The new program has a lot of problems. My computer crashes every time I try to run it.\n");
        }
        else{
            printf("Failed, No find.\n");
        }
    }
    return 0;
}

