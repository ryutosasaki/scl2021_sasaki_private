#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.1415926

int main(int argc, const char *argv[]){

    char cdummy[401],crlf;
    int n[14]={1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600,1600};
    int m[14]={220,220,220,220,100,100,100,100,100,100,100,100,100,100};
    //int n[14]={400,400,400,400,400,400,400,400,400,400,400,400,400,400};
    //int m[14]={300,300,300,300,400,400,400,400,400,400,400,400,400,400};
    float fdummy, famp1, famp2, fdeg1, fdeg2, fcalc;
    float x, y, z, xx, yy, zz;
    int idummy;
    int idummy1, idummy2;
    float fdummy1, fdummy2, fdummy3, fdummy4, fdummy5, fdummy6;
    FILE *fp1,*fp2;

    fp1 = fopen(argv[1],"r");   // data-log
    fp2 = fopen(argv[2],"r");   // reference-log

    fprintf(stderr,"%d\n",atoi(argv[3]));   // data-No.
    for(int itemNo=0;itemNo<14;itemNo++){
        fgets(cdummy, sizeof(cdummy), fp1); if(itemNo == atoi(argv[3])) fprintf(stderr,"%s\n",cdummy);
        fgets(cdummy, sizeof(cdummy), fp1); if(itemNo == atoi(argv[3])) fprintf(stderr,"%s\n",cdummy);
        fgets(cdummy, sizeof(cdummy), fp2); if(itemNo == atoi(argv[3])) fprintf(stderr,"%s\n",cdummy);
        fgets(cdummy, sizeof(cdummy), fp2); if(itemNo == atoi(argv[3])) fprintf(stderr,"%s\n",cdummy);
        for(int i=0;i<n[itemNo]+1;i++){
            for(int j=0;j<m[itemNo]+1;j++){
                // data read
                
                fscanf(fp1,"%d",&idummy); fscanf(fp1,"%d",&idummy);
                fscanf(fp1,"%f",&x); fscanf(fp1,"%f",&y); fscanf(fp1,"%f",&z);
                fscanf(fp1,"%f",&fdummy); fscanf(fp1,"%f",&fdummy); fscanf(fp1,"%f",&fdummy); 
                fscanf(fp1,"%f",&famp1); fscanf(fp1,"%f",&fdeg1);
                fscanf(fp1,"%f",&fdummy); fscanf(fp1,"%f",&fdummy); fscanf(fp1,"%c",&crlf);

                fscanf(fp2,"%d",&idummy1); fscanf(fp2,"%d",&idummy2);
                fscanf(fp2,"%f",&xx); fscanf(fp2,"%f",&yy); fscanf(fp2,"%f",&zz);
                fscanf(fp2,"%f",&fdummy1); fscanf(fp2,"%f",&fdummy2); fscanf(fp2,"%f",&fdummy3); 
                fscanf(fp2,"%f",&famp2); fscanf(fp2,"%f",&fdeg2);
                fscanf(fp2,"%f",&fdummy4); fscanf(fp2,"%f",&fdummy5); fscanf(fp2,"%c",&crlf);
                if(itemNo==atoi(argv[3])){
                    fcalc = pow((famp1-famp2),2);
                    printf("%4.3e\t%4.3e\t%4.3e\t%4.3e\t%4.3e\t%4.3e\t%4.3e\t%4.3e\n", 
                    xx,yy,zz,famp1, fdeg1, famp2, fdeg2, fcalc);   // data-output
                    /////////////////////////////////////////////////////////////////
                    //fprintf(stderr,"i=%d j=%d ",idummy1, idummy2);
                    //fprintf(stderr,"x=%e y=%e z=%e ",xx, yy, zz);
                    //fprintf(stderr,"%4.3e %4.3e %4.3e ",fdummy1, fdummy2, fdummy3);
                    //fprintf(stderr,"%4.3e %4.3e ",famp2, fdeg2);
                    //fprintf(stderr,"%4.3e %4.3e \n",fdummy4, fdummy5);
                    /////////////////////////////////////////////////////////////////
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