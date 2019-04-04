#include <iostream>
using namespace std;


double choose(int n, int r){
  static int memo[501][501]={0};
  if (r==0 || n==r)
    return 1;
  else if(n<r)
     return 0;
  if(memo[n][r]!=0)
    return memo[n][r];
  return memo[n][r]=choose(n-1,r-1) + choose(n-1,r);
}

int main(){
  cout << choose(4,2);
}
