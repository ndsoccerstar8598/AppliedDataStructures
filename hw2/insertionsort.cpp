#include <iostream>

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
    int length = 10;
    int hello[length];
    hello[0]=10;
    hello[1]=9;
    hello[2]=8;
    hello[3]=7;
    hello[4]=2;
    hello[5]=2;
    hello[6]=2;
    hello[7]=2;
    hello[8]=2;
    hello[9]=2;

    int* arr = new int[length];
    arr = sort(hello,length);
    for(int i = 0; i < length; i++){
      cout << arr[i] << endl;
    }
}
