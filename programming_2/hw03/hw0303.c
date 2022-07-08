#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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
    int32_t angle = 0;
    int32_t bytes = 0;
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
    pfile_in = fopen(filename_in, "r");
    if( pfile_in == NULL ){
        printf("File could not be opened!\n");
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
    printf("Angle (0-90): ");
    scanf("%d",&angle);
    if( angle < 0 || angle > 90 ){
        printf("Error!\n");
        return 0;
    }
    pfile_ou = fopen(filename_ou, "w");
    if( pfile_ou == NULL ){
        printf("File could not be opened!\n");
        return 0;
    }
    // fread(&_bmpheader, sizeof(BMPheader), 1, pfile_in);
    if( angle == 0 ){
        fread(&_bmpheader, sizeof(BMPheader), 1, pfile_in);
        _bmpheader.width = _bmpheader.width * 2;
        _bmpheader.height = 1;
        fwrite(&_bmpheader, sizeof(BMPheader), 1, pfile_ou);
        uint8_t * x_modified = NULL;
        int32_t y_modified = 0;
        y_modified = _bmpheader.width * 3 + _bmpheader.width % 4;
        x_modified = (uint8_t*)malloc(sizeof(uint8_t) * y_modified);
        for( int32_t i = 0; i < y_modified; i++ ){
            x_modified[i] = 0;
        }
        fwrite(x_modified, 1, y_modified, pfile_ou);
        return 0 ;
    }
    if( angle == 90 ){
        fread(&_bmpheader, sizeof(BMPheader), 1, pfile_in);
        fwrite(&_bmpheader, sizeof(BMPheader), 1, pfile_ou);
        while(!feof(pfile_in)){
            uint8_t buffer[1024] = {0};
            int32_t count = fread(buffer, 1, 1024, pfile_in);
            fwrite(buffer, count, 1, pfile_ou);
        }
        return 0;
    }
    double slope = 0;
    int32_t change_width;
    uint8_t * x_origin = NULL;
    uint8_t * x_modified = NULL;
    int32_t y_origin = 0;
    int32_t y_modified = 0;
    slope = tan(angle * M_PI / 180.0);
    fread(&_bmpheader, sizeof(BMPheader), 1, pfile_in);
    change_width =(int32_t)(_bmpheader.height * (1.0 / slope));
    _bmpheader.width = _bmpheader.width + change_width;
    fwrite(&_bmpheader, sizeof(BMPheader), 1, pfile_ou);
    y_origin = (_bmpheader.width - change_width) * 3 + (_bmpheader.width - change_width) % 4;
    y_modified = (_bmpheader.width) * 3 + (_bmpheader.width) % 4;
    x_origin = (uint8_t*)malloc(sizeof(uint8_t) * y_origin);
    x_modified = (uint8_t*)malloc(sizeof(uint8_t) * y_modified);
    for(int32_t y = 0; y < _bmpheader.height; y++){
        fread(x_origin, 1, y_origin, pfile_in);
        for( int32_t x = 0; x < y_modified; x++ ){
            x_modified[x] = 255;
        }
        for( int32_t pixel = 0; pixel < y_modified; pixel = pixel + 3 ){
            if( slope * pixel / 3 - y >= 0.0 ){
                for( int32_t w = 0; w < y_origin; w++ ){
                    x_modified[pixel+w] = x_origin[w];
                }
                fwrite(x_modified, 1, y_modified, pfile_ou);
                break;
            }
        }
    }
    fclose(pfile_in);
    fclose(pfile_ou);
    return 0;
}