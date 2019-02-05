/*
    Nicholas DiMaria
    I pledge my honor that I have abided by the Stevens Honor System.

    People I worked with:
    Max Parisi: Helped me come up with the idea for having a static array
    Besnik Balaj: Consulted about some logic as well as the rand()
    http://www.cplusplus.com/forum/beginner/18457/: adding the if statments with
    i<=j, l<j, and r>i came from this website. I was getting errors of being off
    by one or going out of the bounds of the array and this helped fixed those
    problems. 
*/

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
