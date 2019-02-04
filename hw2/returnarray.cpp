#include<iostream>
using namespace std;

int* function(){
    int* arr = new int[3];
    arr[0] = 1;
    arr[1] =2;
    arr[2] =3;  
    return arr;
}

int main()
{
    int* arr = function();
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;

    return 0;
}
