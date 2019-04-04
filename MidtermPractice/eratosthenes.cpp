#include <iostream>

using namespace std;

int eratosthenes(int n){
  bool sieve[n];
  for(int i=2;i<n;i++){
    sieve[i]=true;
  }
  for(int i=4;i<n;i+=2){
    sieve[i]=false;
  }
  for(int i=3;i<n;i+=2){
    if(sieve[i])
      for(int j=i*i; j<n; j = j + (2*i))
        sieve[j]=false;
  }

  int num =0;
  for(int i =2;i<n;i++){
    if(sieve[i])
      num++;
  }
  return num;
}

int main(){
  cout << eratosthenes(1000);
}
