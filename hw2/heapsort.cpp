#include <iostream>
#include <fstream>

using namespace std;

void makesubheap(int x[], int i){
  if(x[(2*i)+1] > x[(2*i)+2]){
    if(x[i] < x[(2*i)+1]){
      swap(x[i],x[(2*i)+1]);
      makesubheap(x, (2*i)+1);
    }
  }
  else{
    if(x[i] < x[(2*i)+2]){
      swap(x[i],x[(2*i)+2]);
      makesubheap(x, (2*i)+2);
    }
  }
}

void makeheap(int x[], int n){
  for(int i = n/2; i > 0; i--)
    makesubheap(x,i);
}

void heapsort(int x[], int n){
  makeheap(x, n);
  for(int i =n-1; i >=1; i++){
    swap(x[0],x[i]);
    makesubheap(x,0);
  }
}

int main(){
    ifstream infile;
    int length =0;

    infile.open("hw3.dat");
    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    infile >> length;

    static int* hello = new int[length];
    int count=0;

    while(infile >> hello[count]){
        count++;
    }
    infile.close();

    heapsort(hello,length);
    for(int i = 0; i < length; i++){
        cout << hello[i] << endl;
    }
}
