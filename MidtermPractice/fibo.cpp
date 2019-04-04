#include <iostream>
using namespace std;

int fibo_recurs(int n){
  static int memo[500] ={0};
  if(n<=2)
    return 1;
  if(memo[n]!=0)
    return memo[n];
  return memo[n] = fibo_recurs(n-1)+fibo_recurs(n-2);
}

int fibo(int n){
  int a=1,b=1,c=1;
  for(int i=3; i<=n;i++){
    c=a+b;
    a=b;
    b=c;
  }
  return c;
}

int main(){
  cout << fibo(8);
}
