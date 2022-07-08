#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <getopt.h>

struct option long_options[] =
    {
        {"help", 0, NULL, 'h'},
        {"angle", 1, NULL, 'a'},
        {"input", 1, NULL, 'i'},
        {"output", 1, NULL, 'o'},
        {0, 0, 0, 0},
}; 

struct _sBmpHeader
{
    char		bm[2];
    uint32_t	size;
    uint32_t	reserve;
    uint32_t	offset;
    uint32_t	header_size;
    uint32_t	width;
    uint32_t	height;
    uint16_t	planes;
    uint16_t	bpp;
    uint32_t	compression;
    uint32_t	bitmap_size;
    uint32_t	hres;
    uint32_t	vres;
    uint32_t	used;
    uint32_t	important;
}__attribute__ ((__packed__));

typedef struct _sBmpHeader sBmpHeader;

// void print_bmp_header( sBmpHeader *pHeader )
// {
//     printf( "ID: %c%c\n", pHeader -> bm[0], pHeader -> bm[1] );
//     printf( "Size: %u\n", pHeader -> size );
//     printf( "Reserve: %u\n", pHeader -> reserve );
//     printf( "Offset: %u\n", pHeader -> offset );
//     printf( "Header Size: %u\n", pHeader -> header_size );
//     printf( "Width: %u\n", pHeader -> width );
//     printf( "Height: %u\n", pHeader -> height );
//     printf( "Planes: %u\n", pHeader -> planes );
//     printf( "Bits Per Pixel: %u\n", pHeader -> bpp );
//     printf( "Compression: %u\n", pHeader -> compression );
//     printf( "Bitmap Data Size: %u\n", pHeader -> bitmap_size );
//     printf( "H-Resolution: %u\n", pHeader -> hres );
//     printf( "V-Resolution: %u\n", pHeader -> vres );
//     printf( "Used Colors: %u\n", pHeader -> used );
//     printf( "Important Colors: %u\n", pHeader -> important );
    
//     return;
// }


int main(int32_t argc, char* argv[])
{
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    int32_t index = 0;
    int32_t c = 0;
    int32_t opt_h = 0;
    char filename_in[256] = {0};
    char filename_ou[256] = {0};
    char in_angle[256] = {0};
    int32_t angle = 0;
    int32_t check = 0;
    int32_t opt_a = 0;
    int32_t opt_i = 0;
    int32_t opt_o = 0;
    while( (c = getopt_long(argc,argv,"a:i:o:h",long_options, &index)) != -1 ){
        switch(c){
            case 'h':
                opt_h = 1;
                break;
            case 'i':
                strncpy(filename_in,optarg,256);
                opt_i = 1;
                if(strlen(optarg) == 0){
                    check =1;
                }
                break;
            case 'o':
                strncpy(filename_ou,optarg,256);
                opt_o = 1;
                if(strlen(optarg) == 0){
                    check =1;
                }
                break;
            case 'a':
                opt_a = 1;
                strncpy(in_angle,optarg,256);
                if(strlen(optarg) == 0){
                    check =1;
                }
                break;
            case '?':
                check = 1;
                break;
        }
        if(check == 1){
            printf("error\n");
            break;
        }
    }
    char** ptr = NULL;
    if(opt_a == 1){
        angle = (int32_t)strtol(in_angle,ptr,10);
    } 
    if(opt_h == 1){
        printf("fin02:\n");
        printf("    -a, --angle: angle for clockwise rotation\n");
        printf("    -i, --input: input file\n");
        printf("    -o, --output: output file\n");
        printf("    -h, --help: This description\n");
        return 0;
    }
    if(opt_i == 1 && opt_o == 1){
        input_file = fopen( filename_in, "rb" );
        if( input_file == NULL ){
            printf( "File could not be opened!\n" );
            return 0;
        }
        output_file = fopen( filename_ou, "wb" );
	    if( output_file == NULL ){
            printf( "File could not be opened!\n" );
            return 0;
        }
    }
    
    if(opt_a == 1 && opt_i == 1 && opt_o == 1){
        if(angle == 0.0 || angle == 360.0){ 
        sBmpHeader	header;
        fread( &header, sizeof( header ), 1, input_file );
        // print_bmp_header(&header);
        fwrite( &header, sizeof( header ), 1, output_file );
        
        
        while( !feof( input_file ) )
        {
            uint8_t	original[1024] = {0};
            uint8_t modified[1024] = {0};
        
            size_t count = fread( original, 1, 1024, input_file );

            for( size_t i = 0 ; i < count ; i++ )
            {
                modified[i] = original[i];
            }
        
            fwrite( modified, count, 1, output_file );
        
        }
        
    }
    else if(angle == 180.0){    

        sBmpHeader	header;
        fread( &header, sizeof( header ), 1, input_file );
        header.height *= -1;
        fwrite( &header, sizeof( header ), 1, output_file );

        while( !feof( input_file ) )
        {
            uint8_t	original[1024] = {0};
            uint8_t modified[1024] = {0};
        
            size_t count = fread( original, 1, 1024, input_file );

            for( size_t i = 0 ; i < count ; i++ )
            {
                modified[i] = original[i];
            }
        
            fwrite( modified, count, 1, output_file );
        
        }
    }
    
    else{
        angle = 360 - angle;
        sBmpHeader	header;
        fread( &header, sizeof( header ), 1, input_file );
        
        uint8_t **ini = calloc(header.height,sizeof(uint8_t *));
        for(int i = 0; i < header.height; i++){
        	ini[i] = calloc(header.width * 3,sizeof(uint8_t));
        	for(int j = 0; j < header.width * 3; j++){
        		ini[i][j] = 0;
        	}
        }
        uint8_t trash[header.width % 4 * 3];
        for(int i = 0; i < header.height; i++)
        {
        
			fread(ini[i], 1, (header.width - header.width % 4) * 3, input_file );
			fread(trash, 1, header.width % 4 * 3, input_file );
        	
        }
        uint32_t side = (uint32_t)sqrt(pow(header.width,2) + pow(header.height,2));
        if(side % 4 != 0){
        	side += 4 - (side % 4);
        }
        uint32_t newSize = side * side * 3;
        uint32_t oldH = header.height;
        uint32_t oldW = header.width;
        double x0 = 0.5 * header.width;
        double y0 = 0.5 * header.height;
        header.size = newSize;
        header.height = side;
        header.width = side;
        int32_t mid = side / 2;
        
        fwrite( &header, sizeof( header ), 1, output_file );
        double theta = angle * M_PI / 180.0;
        double sinV =  sin(theta);
        double cosV =  cos(theta);
        
        
        
        uint8_t **result = calloc(header.height,sizeof(uint8_t *));
        for(int i = 0; i < header.height; i++){
        	result[i] = calloc(header.width * 3,sizeof(uint8_t));
        	for(int j = 0; j < header.width * 3; j++){
        		result[i][j] = 255;
        	}
        }
        int32_t fixedX = 0;
        int32_t fixedY = 0;
 	
        for(int i = 0; i < oldH; i++){
        	double y = i - y0;
        	for(int j = 0; j < oldW * 3; j += 3){
        	    double x = j / 3 - x0;
        	    
        	    
        	    fixedX = (int32_t) ((x * cosV - y * sinV) + mid) * 3;
        	    fixedY = (int32_t) ((y * cosV + x * sinV) + mid);
        	   

        	    if(result[fixedY][fixedX] == 255 && result[fixedY][fixedX + 1] == 255 && result[fixedY][fixedX + 2] == 255){
        	    result[fixedY][fixedX] = ini[i][j];
        	    result[fixedY][fixedX + 1] = ini[i][j + 1];
        	    result[fixedY][fixedX + 2] = ini[i][j + 2];
        	    }
        	    else{
        	    	result[fixedY][fixedX + 3] = ini[i][j];
        	    	result[fixedY][fixedX + 4] = ini[i][j + 1];
        	    	result[fixedY][fixedX + 5] = ini[i][j + 2];
        	    }

        	    
        	}
        }
        //*/
        for(int i = 0; i < header.height; i++)
        {
            fwrite(result[i], header.width * 3, 1, output_file );
        	
        }
        
	for(int i = 0; i < oldH; i++){
        	free(ini[i]);
        }

        for(int i = 0; i < header.height; i++){
        	free(result[i]);
        }
	free(ini);
        free(result);
    }
    }
    else{
        printf("please use --help\n");
    }
      
    fclose( input_file );
    fclose( output_file );
    
	return 0;
}