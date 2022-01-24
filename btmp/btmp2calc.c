#include <stdio.h>
#include <stdlib.h>

int main(){
    int value[400][400];
    FILE *fp = NULL;
    char ch;
    fp = fopen("test.txt", "r");
    printf("%d\n%d\n%d\n",sizeof(int),sizeof(value),sizeof(value[0][0]));
    /*
    printf("▼===== テキストファイルの内容 =====▼\n");
    while( ( ch = fgetc(fp) ) != EOF ) {
        printf("%c", ch);
    }*/
    for(int i=0;i<400;i++){
        for(int j=0;j<400;j++){
            fscanf(fp,"%3d ",&value[i][j]);
            printf("%3d ",value[i][j]);
            if(value==255){

            }
        }
        printf("\n");
    }

    /*
    for(int i=0;i<1024;i++){
        for(int j=0;j<1024;j++){
            if(value==255){
                
            }
        }
    }
    */
}