#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

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

}

int main(){

    static int x[5];
    x[0]=1;
    x[1]=2;
    x[2]=2;
    x[3]=2;
    x[4]=5;

    quicksort(x,0,4);
    for (int i =0; i < 5; i++)
        cout << x[i] <<endl;
}
