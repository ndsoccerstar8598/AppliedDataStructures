/*
    Nicholas DiMaria
    I pledge my honor that I have abided by the Stevens Honor System
*/

#include <iostream>
#include <fstream>

using namespace std;

int* sort(int x[], int n){
    int *a = new int[n];

    for (int i=0; i<=n; i++){
        a[i] = x[i];
    }

    for(int i=1; i<=n; i++){
        if(a[i]<a[i-1]){
            int temp = a[i];
            for(int j=i-1;j>=0;j--){
                if (temp <a[j] && j !=0){
                    a[j+1]=a[j];
                }
                else if (temp < a[j]){
                    a[j+1]=a[j];
                    a[j] = temp;
                }
                else{
                    a[j+1]=temp;
                    break;
                }
            }
        }
    }
    return a;
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
    cout << length << endl;
    cout << endl;

    int* hello = new int[length];
    int count=0;

    while(infile >> hello[count]){
        count++;
    }

    int* arr = new int[length];
    arr = sort(hello,length);
    for(int i = 0; i < length; i++){
        cout << arr[i] << endl;
    }
}
