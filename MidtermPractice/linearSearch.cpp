#include <iostream>

using namespace std;

int linearSearch(int x[], int n, int target){
  for(int i=0; i<n; i++){
    if(x[i]==target)
      return i;
  }
  return -1;
}

int main(){
  int x[] = {0,1,2,3,4,5,6};

  cout << linearSearch(x,7,5) << endl;
  cout << linearSearch(x,7,8);
}
