/*
    Nicholas DiMaria
    I pledge my honor that I have abided by the Stevens Honor System

    Citations:
    --Max Parisi: Helped me come up with the idea for having a static array
    --Besnik Balaj: Consulted about the rand() function as well as reading in files
    --https://www.uow.edu.au/~lukes/TEXTBOOK/notes-cpp/io/readtextfile.html:
    This website also helped me with reading in files
*/

#include <iostream>
#include <fstream>

using namespace std;

void sort(int x[], int n){

    for(int i=1; i<n; i++){
        if(x[i]<x[i-1]){
            int temp = x[i];
            for(int j=i-1;j>=0;j--){
                if (temp <x[j] && j !=0){
                    x[j+1]=x[j];
                }
                else if (temp < x[j]){
                    x[j+1]=x[j];
                    x[j] = temp;
                }
                else{
                    x[j+1]=temp;
                    break;
                }
            }
        }
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

    sort(hello,length);
    for(int i = 0; i < length; i++){
        cout << hello[i] << endl;
    }
}
