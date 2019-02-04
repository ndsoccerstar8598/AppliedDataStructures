#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int* quicksort (int x[], int L, int R){
      srand (time(NULL));

      int *a = new int[R+1];

      for (int i=0; i<=R; i++){
          a[i] = x[i];
      }

      int *L = new int[(R+1)/2];
      int *R = new int[(R+1)/2];

      int num = a[rand() % R + 1];

      int i = L;
      int j = R;
      int lCount = 0;
      int rCount =0;

      while(i<j){
          if(x[i] < num){
              L[lCount] = x[i];
              lCount++;
              i++;
          }
          else{
              R[rCount] = x[i];
              rCount++;
              i++;
          }
          if(x[j] < num){
              L[lCount] = x[i];
              lCount++;
              i++;
          }
          else{
              R[rCount] = x[i];
              rCount++;
              i++;
          }

      }

}

int main(){

      int x[8] = {0};

}
