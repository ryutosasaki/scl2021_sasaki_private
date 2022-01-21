#include <iostream>
#include <string>
#include <cmath>
#define N 50
using namespace std;

int main(int argc, const char *argv[]){

    string s="geometry = 3 33 ";
    float x1, x2, x3, x4, y1, y2, y3, z1, z2;
    float pitch;

    pitch = atof(argv[1]);

    x1 = -2.0E-5;
    for(int i=0;i<N;i++){
        x1 = x1 + sqrt(2)/2.0*pitch*1E-6;
        x2 = x1 + pitch/sqrt(2)/2.0*1E-6;
        x3 = x1 + pitch/sqrt(2)/2.0*1E-6;
        x4 = x1 + pitch/sqrt(2)*1E-6;
        if (i%2==0) y1 = -2.0E-5 + sqrt(2)/2.0*pitch*1E-6;
        if (i%2==1) y1 = -2.0E-5 ;
       for(int j=0; j<N;j++){
            y1 = y1 + sqrt(2)*pitch*1E-6;
            y2 = y1 + pitch/sqrt(2)/2.0*1E-6;
            y3 = y1 - pitch/sqrt(2)/2.0*1E-6;
            z1 = 2.2E-7;
            z2 = 3.3E-7;
            if((x1 > -2E-5) && (x4 < 2E-5) && (y1 > -2E-5) && (y1 < 2E-5)){
                cout << s;
                cout << z1 << " " << z2 << " ";
                cout << x1 << " " << x2 << " " << x3 << " ";
                cout << y1 << " " << y2 << " " << y3 << endl;
                cout << s;
                cout << z1 << " " << z2 << " ";
                cout << x4 << " " << x2 << " " << x3 << " ";
                cout << y1 << " " << y2 << " " << y3 << endl;
            }
        }
        //x1 = x1 + sqrt(2)/2.0*pitch*1E-6;
    }
    return 0;
}