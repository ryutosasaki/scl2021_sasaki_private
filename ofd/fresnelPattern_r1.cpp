#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#define N 100
#define lambda 0.630

using namespace std;

//geometry = 2 1 -2.835E-06 -2.52E-06 -4E-06 4E-06 8.9E-07 1E-06

float frs(int n, float f){
    return sqrt(n*f*lambda+n*n*lambda*lambda/4.0)*1e-6;
}

int main(int argc, const char *argv[]){

    string s="geometry = 2 1 ";
    float f=0.0;
    f = atof(argv[1]);
    for(int i=0;i<N;i=i+2){
        if(frs(i+1,f)<2E-5){
            cout << s << " ";
            printf("%4.3E %4.3E",frs(i,f), frs(i+1,f));
            printf(" -2E-05 2E-05 2.2E-07 3.3E-7\n");
            cout << s << " ";
            printf("%4.3E %4.3E",-frs(i,f), -frs(i+1,f));
            printf(" -2E-05 2E-05 2.2E-07 3.3E-7\n");
        }
        /*
        cout << s << " ";
        cout << setprecision(3) << frs(i) << " ";
        cout << setprecision(3) << frs(i+1) << " ";
        cout << "-2E-05 2E-05 2.2E-07 3.3E-7" << endl;
        cout << s << " ";
        cout << setprecision(3) << -frs(i) << " ";
        cout << setprecision(3) << -frs(i+1) << " ";
        cout << "-2E-05 2E-05 2.2E-07 3.3E-07" << endl;
        */
    }
    return 0;
}