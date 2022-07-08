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

typedef char string[300];
struct option long_options[] =
    {
        {"query", 1, NULL, 'q'},
        {"help", 0, NULL, 'h'},
        {0, 0, 0, 0},
};
void get_query();
uint64_t get_file_size(int32_t fd);

const char *buf_file = "AFH5334B998C123AFF.buf";

void get_query() //<cite class="data" itemprop="headline">
{
    const char *parser = "<cite class=\"data\" itemprop=\"headline\">";
    const char *authorParser = "<span itemprop=\"name\" title=\"";
    const char *titleParser = "<span class=\"title\" itemprop=\"name\">";
    const char *dateParser = "<span itemprop=\"datePublished\">";
    const char *sourceParser = "<span itemprop=\"name\">";
    int32_t pfile = 0;
    pfile = open(buf_file, O_RDWR);
    uint64_t file_size = get_file_size(pfile);
    char *ptr_m = NULL;
    ptr_m = mmap(0, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, pfile, 0);
    char *str = NULL;

    str = strstr(ptr_m, parser);
    int32_t paper_num = 0; //article number
    if (str == NULL){
        printf("No find.\n");
    }
    else{
        while (str != NULL){
            if (paper_num >= 10){
                break;
            }
            str = str + strlen(parser);
            char *end = strstr(str, parser);

            if (end != NULL){
                *(end - 1) = 0;
            }
            //authors
            string author[100] = {0};
            int32_t author_index = 0;
            char *ptr = strstr(str, authorParser);
            char *token = NULL;
            if (ptr == NULL){
                strncpy(author[0], "No author was found.", sizeof(string) - 5);
                author_index = 1;
            }
            else{
                while (ptr != NULL){
                    ptr += strlen(authorParser);
                    token = strtok(ptr, "\"");
                    strncpy(author[author_index], token, sizeof(string) - 5);
                    ptr = token + 1 + strlen(token);
                    *(ptr - 1) = '\"';
                    ptr = strstr(ptr, authorParser);
                    author_index++;
                }
            }
            ptr = NULL;
            token = NULL;
            //title
            string title = {0};
            ptr = strstr(str, titleParser);
            if (ptr == NULL){
                strncpy(title, "No title was found.", sizeof(string) - 5);
            }
            else{
                ptr += strlen(titleParser);
                token = strtok(ptr, "<");
                strncpy(title, token, sizeof(string) - 5);
                *(token + strlen(token)) = '<';
                ptr = NULL;
                token = NULL;
            }
            //date
            string date = {0};
            ptr = strstr(str, dateParser);
            if (ptr == NULL){
                strncpy(date, "No date was found.", sizeof(string) - 5);
            }
            else{
                *(ptr - 1) = 0;
                ptr += strlen(dateParser);
                token = strtok(ptr, "<");
                strncpy(date, token, sizeof(string) - 5);
            }
            //source
            string source = {0};
            ptr = strstr(str, sourceParser);
            if (ptr == NULL){
                strncpy(source, "No source was found.", sizeof(string) - 5);
            }
            else{
                ptr += strlen(sourceParser);
                token = strtok(ptr, "<");
                while (token != NULL){
                    strncat(source, token, sizeof(string) - 5);
                    token = strtok(NULL, "<");
                    if (token == NULL){
                        break;
                    }
                    token = strchr(token, '>');
                    if (token != NULL){
                        token++;
                    }
                }
            }
            //print;
            if(paper_num < 9){
                printf("Paper 0%d\n", paper_num + 1);
            }
            else{
                printf("Paper %d\n", paper_num + 1);
            }
            printf("    Title : %s\n", title);
            printf("    Author : ");
            for (int32_t i = 0; i < author_index; i++){
                printf("%s", author[i]);
                if (i != author_index - 1){
                    printf(", ");
                }
            }
            printf("\n    Source : %s\n", source);
            printf("    Date : %s\n", date);
            //printf("%s\n", str);
            paper_num++;
            if (end == NULL){
                break;
            }
            else{
                str = strstr(end, parser);
            }
        }
    }
    munmap(ptr_m, file_size);
    close(pfile);
    return;
}

/*
struct stat { 儲存檔案狀態資訊的結構體
    mode_t st_mode; //檔案對應的模式，檔案，目錄等
    ino_t st_ino; //inode節點號
    dev_t st_dev; //裝置號碼
    dev_t st_rdev; //特殊裝置號碼
    nlink_t st_nlink; //檔案的連線數
    uid_t st_uid; //檔案所有者
    gid_t st_gid; //檔案所有者對應的組
    off_t st_size; //普通檔案，對應的檔案位元組數
    time_t st_atime; //檔案最後被訪問的時間
    time_t st_mtime; //檔案內容最後被修改的時間
    time_t st_ctime; //檔案狀態改變時間
    blksize_t st_blksize; //檔案內容對應的塊大小
    blkcnt_t st_blocks; //偉建內容對應的塊數量
};
*/

uint64_t get_file_size(int32_t pfile)
{
    struct stat buf;
    if (fstat(pfile, &buf) < 0){//正確回傳0
        return -1;
    }
    return buf.st_size;
}

int main(int32_t argc, char *argv[]){
    int32_t c = 0;
    int32_t help = 0;
    int32_t check = 0;
    int32_t index;
    uint32_t size = 0;
    char *keyword = NULL;
    const char *url = "https://dblp.org/search?q=";

    while ((c = getopt_long(argc, argv, "q:h", long_options, &index)) != -1){
        switch (c)
        {
            case 'h':
                help = 1;
                break;
            case 'q':
                if(strlen(optarg) == 0){
                    check = 1;
                }
                else{
                    size = strlen(optarg) + strlen("https://dblp.org/search?q=") + 3;
                    keyword = (char *)calloc(size, sizeof(char));
                    strncpy(keyword, "https://dblp.org/search?q=", strlen(url));
                    strncat(keyword, optarg, strlen(optarg));
                }
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
        printf("./hw0503 -q keyword\n");
    }
    else if (check == 1){
        printf("error\n");
    }
    else{
        CURL *curl = curl_easy_init();
        CURLcode res;
        if (curl){
            curl_easy_setopt(curl, CURLOPT_URL, keyword);
            FILE *buf = fopen(buf_file, "w");
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, buf);

            res = curl_easy_perform(curl);
            if (res != CURLE_OK){
                printf("curL_easy_perform() failed.\n");
            }
            fclose(buf);
            get_query();
        }
        else{
            printf("Something went wrong with libcurl.\nExiting...\n");
        }
        curl_easy_cleanup(curl);

        remove(buf_file);
    }
    free(keyword);
    return 0;
}

