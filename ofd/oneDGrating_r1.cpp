#include <iostream>
#include <string>
#include <cmath>
#define N 50
#define PI 3.1415926
using namespace std;
//斜め45度回折格子(1次元)

int main(int argc, const char *argv[]){

    string s="geometry = 2 33 ";
    float x, x11, x12, x13, x21, x22, x23, y11, y12, y13, y21, y22, y23, z1, z2;
    float pitch, theta;

    pitch = atof(argv[1])*2.0;
    theta = atof(argv[2])/180.0*PI;

    x = 1E-5;
    for(int i=0;i<N;i++){
        x11 = x;
        x12 = x + pitch/2.0/sin(theta)*1E-9;
        x13 = 0;
        y11 = 0;
        y12 = 0;
        y13 = x*tan(theta);

        x21 = 0;
        x22 = 0;
        x23 = x + pitch/2.0/sin(theta)*1E-9;
        y21 = x*tan(theta);
        y22 = x*tan(theta) + pitch/2/cos(theta)*1E-9;
        y23 = 0;

        z1 = 2.2E-7;
        z2 = 3.3E-7;

        cout << s;
        cout << z1 << " " << z2 << " ";
        cout << x11-4e-5 << " " << x12-4e-5 << " " << x13-4e-5 << " ";
        cout << y11-2e-5 << " " << y12-2e-5 << " " << y13-2e-5 << endl;
        cout << s;
        cout << z1 << " " << z2 << " ";
        cout << x21-4e-5 << " " << x22-4e-5 << " " << x23-4e-5 << " ";
        cout << y21-2e-5 << " " << y22-2e-5 << " " << y23-2e-5 << endl;

        x += pitch/sin(theta)*1E-9;
    }
    return 0;
}