#include <iostream>
#include <fstream>

using namespace std;

//void makesubheap(int x[], int i,int n){
//    if(x[(2*i)+1] > x[(2*i)+2]){
//        if(x[i] < x[(2*i)+1]){
//            swap(x[i],x[(2*i)+1]);
//            if ((2*(2*i+1)+2)<n)
//                makesubheap(x, (2*i)+1,n);
//        }
//    }
//    else{
//        if(x[i] < x[(2*i)+2]){
//            swap(x[i],x[(2*i)+2]);
//            if ((2*(2*i+1)+2)<n)
//                makesubheap(x, (2*i)+2,n);
//        }
//    }
//}
//
//void makeheap(int x[], int n){
//    for(int i = (n/2)-1; i > 0; i--)
//        if(((2*i)+2)<n)
//            makesubheap(x,i,n);
//}
//
//void heapsort(int x[], int n){
//    makeheap(x, n);
//    for(int i =n-1; i >=1; i++){
//        swap(x[0],x[i]);
//        makesubheap(x,0,n);
//    }
//}

void buildHeap(int x[], int n){
    for(int i =(n/2)-1; i>=0; i--){
        if (x[i] < x[(i+1)*2-1]){
            swap(x[i],x[(i+1)*2-1]);
        }
        if (x[i] < x[(i+1)*2]){
            swap(x[i], x[(i+1)*2]);
        }
    }
}

void heapSort(int x[], int n){
    buildHeap(x, n);
    do {
        swap(x[0], x[n - 1]);
        n = n-1;
        int i =0;
        int j =0;
        while (i<n-1){
            if (x[(i+1)*2-1] > x[(i+1)*2] && x[i] < x[(i+1)*2-1] && ((i+1)*2)<n){
                j = 1;
            }
            else if  (x[(i+1)*2-1] <= x[(i+1)*2] && x[i] < x[(i+1)*2] && ((i+1)*2)<n) {
                j = 2;
            }
            else {
                j = 3;
            }

            if (j == 1){
                swap(x[i], x[(i+1)*2-1]);
                i =( i + 1) * 2 - 1;
            }
            else if (j==2){
                swap(x[i], x[(i+1)*2]);
                i =( i + 1) * 2;
            }
            else
                break;
        }
    }while (n > 0);
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

    heapSort(hello,length);
    for(int i = 0; i < length; i++){
        cout << hello[i] << endl;
    }
}
