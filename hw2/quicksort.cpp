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

using namespace std;

<<<<<<< HEAD
int* quicksort (int x[], int L, int R){
      srand (time(NULL));

      int *a = new int[R+1];

      for (int i=0; i<=R; i++){
          a[i] = x[i];
      }

      int *L = new int[(R+1)];
      int *R = new int[(R+1)];

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
=======
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
