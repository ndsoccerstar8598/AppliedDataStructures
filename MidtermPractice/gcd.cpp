#include <iostream>
using namespace std;

int gcd_recurs(int a, int b){
  if(b==0)
    return a;
  return gcd_recurs(b,a%b);
}

int gcd(int a, int b){
  while(b>0){
    int temp = a;
    a = b;
    b = temp%b;
  }
  return a;
}

int lcm(int a, int b){
  return (a*b)/gcd(a,b);
}

int main(){
  cout << gcd(5,25) << endl;
  cout << lcm(4,6);
}
