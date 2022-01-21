#include <iostream>
#include <string>
#define N 40
using namespace std;

//geometry = 2 1 -2.835E-06 -2.52E-06 -4E-06 4E-06 8.9E-07 1E-06

int main(int argc, const char *argv[]){

    string s="geometry = 2 1 ";
    float x1, x2, y1, y2, z1, z2;
    float pitch;

    pitch = atof(argv[1]);

    for(int i=-N;i<N;i++){
        x1 = i*pitch*1E-6;
        x2 = x1 + pitch/2.0*1E-6;
        y1 = -2E-5;
        y2 =  2E-5;
        z1 = 2.2E-7;
        z2 = 3.3E-7;
        cout << s;
        cout << x1 << " " << x2 << " ";
        cout << y1 << " " << y2 << " ";
        cout << z1 << " " << z2 << endl;
    }
    return 0;
}