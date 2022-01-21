#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.1415926

int main(int argc, const char *argv[]){

    char cdummy[401];
    int n[4]={1200,1200,1200,1200};
    int m[4]={220,220,220,220};
    float fdummy, famp1, famp2, fdeg1, fdeg2, fcalc;
    float x, y, z;
    int idummy;
    FILE *fp1,*fp2;

    fp1 = fopen(argv[1],"r");   // data-log
    fp2 = fopen(argv[2],"r");   // reference-log

    fprintf(stderr,"%d\n",atoi(argv[3]));   // data-No.
    for(int itemNo=0;itemNo<4;itemNo++){
        fgets(cdummy, sizeof(cdummy), fp1); if(itemNo == atoi(argv[3])) fprintf(stderr,"%s\n",cdummy);
        fgets(cdummy, sizeof(cdummy), fp1); if(itemNo == atoi(argv[3])) fprintf(stderr,"%s\n",cdummy);
        fgets(cdummy, sizeof(cdummy), fp2); if(itemNo == atoi(argv[3])) fprintf(stderr,"%s\n",cdummy);
        fgets(cdummy, sizeof(cdummy), fp2); if(itemNo == atoi(argv[3])) fprintf(stderr,"%s\n",cdummy);
        for(int i=0;i<n[itemNo]+1;i++){
            for(int j=0;j<m[itemNo]+1;j++){
                // data read
                
                fscanf(fp1,"%d",&idummy); fscanf(fp1,"%d",&idummy);
                fscanf(fp1,"%f",&x); fscanf(fp1,"%f",&y); fscanf(fp1,"%f",&z);
                fscanf(fp1,"%f",&fdummy); 
                fscanf(fp1,"%f",&famp1); fscanf(fp1,"%f",&fdeg1);
                fscanf(fp1,"%f",&fdummy); fscanf(fp1,"%f",&fdummy); 
                fscanf(fp1,"%f",&fdummy); fscanf(fp1,"%f",&fdummy); //fscanf(fp1,"%f",&fdummy);

                fscanf(fp2,"%d",&idummy); fscanf(fp2,"%d",&idummy);
                fscanf(fp2,"%f",&x); fscanf(fp2,"%f",&y); fscanf(fp2,"%f",&z);
                fscanf(fp2,"%f",&fdummy); 
                fscanf(fp2,"%f",&famp2); fscanf(fp2,"%f",&fdeg2);
                fscanf(fp2,"%f",&fdummy); fscanf(fp2,"%f",&fdummy); 
                fscanf(fp2,"%f",&fdummy); fscanf(fp2,"%f",&fdummy); //fscanf(fp2,"%f",&fdummy);
                if(itemNo==atoi(argv[3])){
                    fcalc = pow((famp1-famp2),2);
                    //printf("%3.2e\t%3.2e\t%3.2e\t%f\t%f\t%f\t%f\t%f\n", 
                    //x,y,z,famp1, fdeg1, famp2, fdeg2, fcalc);   // data-output
                    printf("%d\t%d\t%3.2e\t%f\t%f\t%f\t%f\t%f\n", 
                    i,j,z,famp1, fdeg1, famp2, fdeg2, fcalc);   // data-output
                }
            }
            if(itemNo==atoi(argv[3])) printf("\n"); // CRLF for gnuplot
        }
        fprintf(stderr,"%d ",itemNo);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}