#include <iostream>

using namespace std;

int binarySearch(int x[], int low, int high, int target){

  if (low >= high)
    return -1;
  int mid = (low+high)/2;

  if(target >x[mid])
    return binarySearch(x,mid+1,high, target);
  else if (target < x[mid])
    return binarySearch(x,low,mid-1,target);
  else
    return mid;
}

int binarysearch(int x[], int n, int target){
  int i =0; int j=n-1;
  while(i<j){
    int mid = (i+j)/2;
    if(target < x[mid])
      j = mid-1;
    else if(target > x[mid])
      i = mid + 1;
    else
      return mid;
  }
  return -1;
}

int main(){
  int x[] = {1,2,3,4};
  int n =4;

  cout << binarysearch(x,n,3);
}
