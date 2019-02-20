#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

const double phi = (sqrt(5)+1)/2;

int goldenMeanSearch(int data[], int n){
    int l=0, r =n-1;
    int s = (r-l) / phi;
    int x = r-s, y =l+s;

    while (x<y){
        if(data[x] < data[y]){
            r=y;
            y=x;
            s=(r-l)/phi;
            x = r-s;
        }
        else {
            l = x;
            x = y;
            s = ceil((r - l) / phi);
            y = l + s;
        }
    }
    if(data[x] > data[x+1])
        return x+1;
    else if(data[x-1] <data[x])
        return x-1;
    else
        return x;
}

int main(){
    const int n=20;
    int data[n] = {20,19,18,17,15,16,8,7,0,1,2,5,14,13,12,13,20,21,22,23};
    cout << goldenMeanSearch(data,n) << '\n';
}
