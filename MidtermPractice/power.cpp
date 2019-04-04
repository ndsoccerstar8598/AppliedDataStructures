#include <iostream>
#include <time.h>
using namespace std;

int power(int x, int n){
  int prod = 1;
  while(n>0){
    if(n %2 != 0)
      prod = prod *x;
    x = x*x;
    n=n/2;
  }
  return prod;
}

int powermod(int x, int n, int m){
  int prod = 1;
  while(n>0){
    if(n %2 != 0)
      prod = prod *x %m;
    x = x*x %m;
    n=n/2;
  }
  return prod;
}

bool fermat(int p, int k){
  srand(time(NULL));
  for(int i=0; i < k; i++){
    int a = (rand()%(p-3))+2;
    if (powermod(a,p-1,p)!=1)
      return false;
  }
  return true;
}

bool millerRabin(int p, int k){
  int s;
  for(int i =0; i<k;i++){

    int a = (rand()%(p-4))+2;
    int d=p-1;
    int mask =1;
    if(d&mask ==0){
      s++;
      d >>=1;
    }

    int x = powermod(a,d,p);
    if (x==1 || x==-1)
      continue;
    for(int j=0;j<s-1;j++){
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
  cout << power(4,3) << endl;
  cout << powermod(4,3,3) << endl;
  cout << fermat(17,3) << endl;
  cout << millerRabin(4,3);
}
