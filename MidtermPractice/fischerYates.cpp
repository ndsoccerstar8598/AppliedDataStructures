#include <iostream>
#include <time.h>

using namespace std;

void fischerYates(int x[], int n){

  for(int i=n-1; i>0;i--){
    srand(time(NULL));
    int r = rand()%(i+1);
    swap(x[i],x[r]);
  }
}

int main(){
  int x[]={1,2,3,4,5};
  int n =5;

  fischerYates(x,n);
  for(int i=0;i<n;i++)
    cout << x[i];

}
