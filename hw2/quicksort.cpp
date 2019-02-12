/*
    Nicholas DiMaria
    I pledge my honor that I have abided by the Stevens Honor System.

    Citations
    --Max Parisi: Helped me come up with the idea for having a static array
    --Besnik Balaj: Consulted about the rand() function as well as reading in files
    --http://www.cplusplus.com/forum/beginner/18457/: adding the if statments with
    i<=j, l<j, and r>i came from this website. I was getting errors of being off
    by one or going out of the bounds of the array and this helped fixed those
    problems.
    --https://www.uow.edu.au/~lukes/TEXTBOOK/notes-cpp/io/readtextfile.html:
    This website also helped me with reading in files
*/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

  void quicksort (int x[], int l, int r){
    srand (time(NULL));

    int i=l;
    int j=r;

    int pivot =x[(rand() % (r-l))+l];
    while(i<=j){
      while(x[i]<pivot)
      i++;
      while(x[j]>pivot)
      j--;
      if(i<=j){
        int temp = x[i];
        x[i] = x[j];
        x[j] = temp;
        i++;
        j--;
      }
using namespace std;

    }
    if(l <j)
        quicksort(x,l,j);
    if(r >i)
        quicksort(x,i,r);
    return;
>>>>>>> 8b186d0fa8d6d1918fa25e0feafc7e4444f2db7d
}

int main(){

    fstream infile;
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

    quicksort(hello,0,length-1);
    for (int i =0; i < length; i++)
        cout << hello[i] <<endl;
}
