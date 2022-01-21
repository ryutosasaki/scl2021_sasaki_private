#include <iostream>
#include <string>
#include <cmath>

#define N 16
#define R 0.000004
#define PI 3.1415926
#define V 250000000000

using namespace std;

int main(int argc, const char *argv[]){

/*
feed = Y -7.5E-06 0 7.27450204458515E-06 1 0 377
*/

    int k=0;
    string strFeed ="feed = ";

    float theta = atof(argv[1])/180.0*PI;
    //float x_bias = -1.76e-6;
    float z_bias = 1.8e-5;
    float y_bias = 0.0;
    float x_bias = -1.0*z_bias*tan(theta);
    float v = 0.0;

    strFeed += "Y ";

    for(int i=-N;i<N+1;i++){
        float x = (float)i*2.5e-7;
        for(int j=-N;j<N+1;j++){
            float y = (float)j*2.5e-7;
            if(sqrt(x*x+y*y)<R){
                float z = x*sin(theta);
                float xx = x_bias + x*cos(theta);
                v = exp(-V*(x*x+y*y));
                cout << strFeed  << xx << ' ' << y + y_bias  << ' ' << z + z_bias << ' ' << v << " 0 377" << endl;
                k++;
            }

        }

    }
    //cout << k << endl;
    //cout << theta << endl;
    return 0;

}