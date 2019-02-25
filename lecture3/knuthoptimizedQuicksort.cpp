//200 points and optional
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <chrono>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <direct.h>
#include <windows.h>

using namespace std;
using namespace std::chrono;

void partialQuicksort(int x[], int l, int r, int k) {

  srand (time(NULL));

  int i=l;
  int j=r;

  int pivot = x[(r+l)/2];
  //[(rand() % (r-l))+l];
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
  if (j-l > k)
      partialQuicksort(x, l, j, k);
  if (r - i >k)
      partialQuicksort(x, i, r, k);
  return;
}

void insertionSort(int x[], int n){
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

//essentially we do not want the quicksort to go all the way to the end
//we optimize this but not doing all these quicksorts at the end
//omce that happens we have the insertion take over
// but what is the number, that we want quicksort to take over at
void knuthQuicksort(int x[], int n, int k){
  partialQuicksort(x,0,n-1,k); //k = minimum size = ???

  //k =2 quicksort, k =10000 insertion sort is doing too much
  // use goldenMeanSearch in between 200 and 300
  insertionSort(x,n);
  return;
}

const double phi = (sqrt(5)+1)/2;

int goldenMeanSearch(double data[], int n){
    int l=0, r =n-1;
    int s = (r-l) / phi;
    int x = r-s, y =l+s;

    while (x<y){
        if(data[x] < data[y]){
            r=y;
            y=x;
            s=(r-l)/phi;
            x = r-s;
        }
        else {
            l = x;
            x = y;
            s = ceil((r - l) / phi);
            y = l + s;
        }
    }
    if(data[x]>data[x+1])
        return x+1;
    else if(data[x-1]>data[x])
        return x-1;
    else
        return x;
}

//we want to use a goldenMeanSearch to test what number it is best for the
//insertion sort to take over from the quicksort
//also how much faster is this than the normal quicksort algorithm
// testprocedure(){
//   int[] r = generatrandomnumbers();
//
//   foreach trial
//     int[] copy =r; //copy the array
//
//   knuthQuicksort(copy); //with k = ???
// }

int main(){
  fstream infile;
  int length =0;
  clock_t begin, end;
  LARGE_INTEGER frequency;
  LARGE_INTEGER t1,t2;
  double elapsedTime;

  QueryPerformanceFrequency(&frequency);

  double time_spent;
  infile.open("numbers.txt");
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
  int count2 =0;
  double times[10000] = {0};
  ofstream myfile;

  myfile.open ("times.txt");
  for(int i=0; i<1000000; i+=100){

    cout << "Time taken by function: " << knuthQuicksort(hello,length,i) << endl;
    //high_resolution_clock::time_point start = high_resolution_clock::now();
    QueryPerformanceCounter(&t1);
    knuthQuicksort(hello,length,i);
    QueryPerformanceCounter(&t2);

    //high_resolution_clock::time_point stop = high_resolution_clock::now();
    //duration<double> elapsed = duration_cast<duration<double>>(stop - start);
    //cout << "Time taken by function: " << elapsed.count() << endl;
    //end = clock();
    //time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
    //myfile << "Time taken by function: " << time_spent << endl;
    //times[count2] = elapsed.count();
    elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    cout << "Time taken by function: " << elapsedTime << endl;
    //times[count2] = elapsedTime;
    times[count2] = time_spent;
    count2 ++;
  }

  cout << "Now im going to check which of these is the best" << endl;
  cout << goldenMeanSearch(times,10000);

  //float seconds = (float)t / CLOCKS_PER_SEC;

  //for (int i =0; i < length; i++)
        //cout << hello[i] <<endl;
}
