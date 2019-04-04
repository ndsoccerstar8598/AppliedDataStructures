#include <iostream>
using namespace std;

void insertionSort(int x[], int n){
  for(int i=1; i<n;i++){
    if(x[i]<x[i-1]){
      int temp = x[i];
      for(int j=i-1;j>=0;j--){
        if(temp < x[j] && j!=0)
          x[j+1]=x[j];
        else if(temp < x[j]){
          x[j+1]=x[j];
          x[0]=temp;
        }
        else{
          x[j] = temp;
        }
      }
    }
  }
}

void quickSort (int x[], int l, int r){

    int i=l;
    int j=r;

    int pivot =x[(rand() % (r-l))+l];
    while(i<=j){
      while(x[i]<pivot)
        i++;
      while(x[j]>pivot)
        j--;
      if(i<=j){
        swap(x[i],x[j]);
        i++;
        j--;
      }
    }
    if(l <j)
        quickSort(x,l,j);
    if(r >i)
        quickSort(x,i,r);
    return;
}

void merge(int x[], int low, int high, int mid){
  int i=low;int j=mid+1; int k=low; int c[50]={0};
  while(i<=mid && j<=high){
    if(x[i]<x[j]){
      c[k]=x[i];
      k++;i++;
    }
    else{
      c[k]=x[j];
      k++;j++;
    }
  }
  while(i<=mid){
    c[k]=x[i];
    k++;i++;
  }
  while(j<=high){
    c[k]=x[j];
    k++;j++;
  }
  for(i =low; i<k;i++){
    x[i]=c[i];
  }
}

void mergeSort(int x[], int low, int high){
  if(low>=high)
    return;
  int mid = (low+high)/2;
  mergeSort(x,low,mid);
  mergeSort(x,mid+1,high);
  merge(x,low,high,mid);
}

int main(){
  int x[]= {4,3,2,1};
  int n =4;
  mergeSort(x,0,n-1);

  for (int i=0; i<n;i++){
    cout << x[i];
  }
}
