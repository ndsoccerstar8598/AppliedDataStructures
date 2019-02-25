#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

const double phi = (sqrt(5)+1)/2; //made this a double instead of an int

int goldenMeanSearch(int data[], int n){
    int l=0, r =n-1;
    int s = (r-l) / phi;
    int x = r-s, y =l+s;

    while (x<y){
        if(data[x] >data[y]){
            r=y;
            y=x;
            s=(r-l)/phi;
            x = r-s;
        }
        else {
            l = x;
            x = y;
            s = ceil((r - l) / phi); //made this a ceiling funciton
            y = l + s;
        }
    }
    //I added these if statements to make sure we are returing the correct index
    //This fixes any of the problems that may occur if the loop breaks out earlier
    //due to rounding issues of s
    if(data[x]<data[x+1])
        return x+1;
    else if(data[x-1]>data[x])
        return x-1;
    else
        return x;
}

int main(){
    const int n=20;
    int data[n] = {0,0,0,1,5,6,8,9,20,19,10,5,4,3,2,1,0,0,0,0};
    cout << goldenMeanSearch(data,n) << '\n';
}
