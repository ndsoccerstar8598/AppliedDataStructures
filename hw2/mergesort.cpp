#include <iostream>
#include <fstream>

using namespace std;

void merge(int x[], int low, int high, int mid){
    int i,j,k,c[50];
    i=low;
    k=low;
    j=mid+1;
    while (i <= mid && j <= high)
    {
        if (x[i] < x[j])
        {
            c[k] = x[i];
            k++;
            i++;
        }
        else
        {
            c[k] = x[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = x[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = x[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        x[i] = c[i];
    }
}

void mergeSort(int x[], int low,int high){
    if(low <high){
        int mid = (low+high)/2;
        mergeSort(x,low,mid);
        mergeSort(x,mid+1,high);

        merge(x,low,high,mid);
    }
    return;
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

    mergeSort(hello,0,length);
    for(int i = 0; i < length; i++){
        cout << hello[i] << endl;
    }
}
