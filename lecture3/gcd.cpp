#include <iostream>

using namespace std;

int gcd(int a, int b){
  if(b==0)
    return a;
  return gcd(b, a%b);
}

int lcm(int a, int b){
  return ((a*b)/gcd(a,b));
}

int power(int x, int n){
  int prod =1;
  while (n>0){
    if(n % 2 !=0)
      prod = prod *x;
    x =x *x;
    n=n/2;
  }
  return prod;
}

int powermod(int x, int n,int m){
  int prod =1;
  while (n>0){
    if(n % 2 !=0)
      prod = (prod *x) %m;
    x =(x *x)%m;
    n=n/2;
  }
  return prod;
}

bool fermat(int p, int k){
  for(int i=0;i<k;i++){
    int a = (rand()%(p-3))+2;
    if(powermod(a,p-1,p)!=1)
      return false;
  }
  return true; //probably
}

bool MillerRabin(int p, int k){
  int s=0;
  for(int i=0; i<k;i++){
    int a = (rand()%(p-4))+2;
    int d=p-1;
    int mask=1;
    if(d & mask==0){
      s++;
      d>>=1;
    }
    int x = powermod(a,d,p);
    if(x==1 || x ==-1)
      continue;
    for(int i=0; i<s-1;i++){
      x=(x*x)%p;
      if(x==p-1)
        goto nextTrial;
    }
    return false;
  nextTrial: ;
  }
  return true;
}
int main(){
  cout << MillerRabin(20,3);
}
