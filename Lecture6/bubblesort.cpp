#include<iostream>
using namespace std;

void reverse_bubble_sort(int array[], const int length){
  int len =length;
  while (len >0){
    int n=0;
    for(int i=0; i<len;++i){
      if(array[i+1]<array[i]){
        swap(array[i],array[i+1]);
        n=i;
      }
    }
    len =n;
  }
}

int main(){
  static int testArray2[] = {12, 14,4,3,10,20,2};
  reverse_bubble_sort(testArray2, 7);
  for(int i=0; i<7;i++)
    cout << testArray2[i] << ' ';
}
