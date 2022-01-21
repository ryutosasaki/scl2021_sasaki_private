#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#define N 100
#define lambda 0.630

using namespace std;

float zebra(float p, int i){
    //return sqrt(n*f*lambda+n*n*lambda*lambda/4.0)*1e-6;
    return p*i*1e-9;
}

int main(int argc, const char *argv[]){

    string s="geometry = 2 1 ";
    float p=0.0;
    p = atof(argv[1]);
    for(int i=-N;i<N;i=i+2){
        if((zebra(p,i+1)<2E-5)&&(zebra(p,i)>-2E-5)){
            cout << s << " ";
            printf(" -2E-05 2E-05 ");
            printf("%4.3E %4.3E",zebra(p,i), zebra(p,i+1));
            printf(" 2.2E-07 3.3E-7\n");
        }
    }
    return 0;
}