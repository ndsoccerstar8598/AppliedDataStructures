#include <iostream>
#include <math.h>

using namespace std;

int goldenMeanSearch(int x[], int n){
  int l =0; int r= n-1;
  const double phi = (sqrt(5)+1)/2;
  int s = (r-l)/phi;
  int a = r-s; int b = l+s;

  while(a<b){
    if(x[a] > x[b]){
      r=b;
      b=a;
      s = (r-l)/phi;
      a = (r-s);
    }
    else{
      l=a;
      a=b;
      s = ceil((r-l)/phi);
      b = l+s;
    }
  }
  return a;
}

int main(){
  int x[] = {0,1,2,3,4,2,1};
  int n = 7;

  cout << goldenMeanSearch(x, n);
}
