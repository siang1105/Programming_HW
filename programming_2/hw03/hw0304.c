#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
typedef struct _sBMPheader{
    char bm[2];
    uint32_t size;
    uint32_t reserve;
    uint32_t offset;
    uint32_t header_size;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t bpp;
    uint32_t compression;
    uint32_t bitmap_size;
    uint32_t hres;
    uint32_t vres;
    uint32_t used;
    uint32_t important;
}__attribute__((packed)) BMPheader;

int main()
{
    FILE *pfile_in = NULL;
    FILE *pfile_ou = NULL;
    char *check_in = NULL;
    char *check_ou = NULL;
    char filename_in[256] = {0};
    char filename_ou[256] = {0};
    int32_t alpha = 0;
    BMPheader _bmpheader = {0};
    printf("Please input a BMP file: ");
    check_in = fgets(filename_in, sizeof(filename_in), stdin);
    if( check_in == NULL ){
        printf("Error!\n");
        return 0;
    }
    if( filename_in[strlen(filename_in) - 1] == '\n' ){
        filename_in[strlen(filename_in) - 1] = 0;
    }
    pfile_in = fopen(filename_in, "rb");
    
    if( pfile_in == NULL ){
        printf("File could not be opened!\n");
        return 0;
    }
    fread(&_bmpheader,sizeof(BMPheader), 1, pfile_in);
    if( _bmpheader.bpp != 24 ){
        printf("Error!\n");
        return 0;
    }
    printf("Please input the output BMP file name: ");
    check_ou = fgets(filename_ou, sizeof(filename_ou), stdin);
    if( check_ou == NULL ){
        printf("Error!\n");
        return 0;
    }
    if( filename_ou[strlen(filename_ou) - 1] == '\n' ){
        filename_ou[strlen(filename_ou) - 1] = 0;
    }
    pfile_ou = fopen(filename_ou,"w");
    if( pfile_ou == NULL ){
        printf("File could not be opened!\n");
        return 0;
    }
    printf("Alpha (0-31): ");
    scanf("%d",&alpha);
    if( alpha < 0 || alpha > 31 ){
        printf("Error!\n");
        return 0;
    }
   
    _bmpheader.size = 70 + _bmpheader.width * _bmpheader.height * 4;
    _bmpheader.offset = 70;
    _bmpheader.header_size = 56;
    _bmpheader.bpp = 32;
    _bmpheader.compression = 3;
    _bmpheader.bitmap_size = _bmpheader.width * _bmpheader.height * 4;
    uint32_t mask[4] = {0x00FF0000,0x0000FF00,0x000000FF,0xFF000000};
    fwrite(&_bmpheader, 1, sizeof(BMPheader), pfile_ou);
    fwrite(&mask, sizeof(uint32_t), 4, pfile_ou);
    
    uint8_t *row_ori = NULL;
    uint8_t *row_mod = NULL;
    int32_t col_ori = 0;
    int32_t col_mod = 0;
    

    col_ori = _bmpheader.width * 3 + _bmpheader.width % 4;
    col_mod = _bmpheader.width * 4;
    row_ori = (uint8_t*)malloc(sizeof(uint8_t) * col_ori);
    row_mod = (uint8_t*)malloc(sizeof(uint8_t) * col_mod);
    while(!feof(pfile_in)){
        int32_t count = 0;
        fread(row_ori, col_ori, 1, pfile_in);
        for(int32_t i = 0; i < _bmpheader.width*3; i = i + 3){
            row_mod[count] = row_ori[i];
            row_mod[count+1] = row_ori[i+1];
            row_mod[count+2] = row_ori[i+2];
            row_mod[count+3] = alpha;
            count = count + 4;
        }
        fwrite(row_mod, col_mod, 1, pfile_ou);
    }
    fclose(pfile_in);
    fclose(pfile_ou);
    return 0;
}