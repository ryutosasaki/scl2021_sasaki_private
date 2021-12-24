#include <stdio.h>
#include <stdlib.h>
#define WIDTH 400
#define HEIGHT 160
int main(void){
    FILE *fp = NULL;
    unsigned char bitmap[WIDTH*HEIGHT*3+53] = { 0 };
    int i = 0, j=0;
    fp = fopen("ev2d_5.bmp", "rb");
    fread(bitmap, sizeof(unsigned char), sizeof(bitmap) / sizeof(bitmap[0]), fp);
    for (i=0 ; i < sizeof(bitmap) / sizeof(bitmap[0]); i++){
        if (i>53){
            if (j%3==1) printf("%d\t", bitmap [i]);
            if (j%(WIDTH*3)==0) printf("\n");
            j++;
        }
    }
    fclose(fp);
    return 0;
}