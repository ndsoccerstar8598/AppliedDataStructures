#include <iostream>
#include<math.h>

using namespace std;

const int phi = (sqrt(5)+1)/2;

int goldenMeanSearch(int data[], int n){
    int l=0, r =n-1;
    int s = (r-l) / phi;
    int x = r-s, y =l+s;

    while (l<r){
        if(data[x] >data[y]){
            r=y;
            y=x;
            s=(r-l)/phi;
            x = r-s;
        }
        else{
            l=x;
            x=y;
            s = (r-l) /phi;
            y = l+s;
        }
    }
    return l;
}

int main(){
    const int n=20;
    int data[n] = {1,5,16,17,18,92,15,15,12,3,2,2,2,2,2,1,1,1,1,0};
    cout << goldenMeanSearch(data,n) << '\n';
}
