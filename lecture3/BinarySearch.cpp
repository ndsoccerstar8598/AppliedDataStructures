#include <iostream>
using namespace std;

int binarySearch(int x[], int n, int target){  //O(log(n))
    int l = 0, r = n-1;
    if (x[l] > target || x[r] < target)
        return -1;
    while (l <= r)  {
        int mid = (l+r)/2;
        if(x[mid] < target){ //if the number we are looking for is greater than mid we need to go to the right
            l = mid + 1 ;
        }
        else if (x[mid] > target){
            r = mid - 1;
        }
        else
            return mid;
    }
    return -1;
}

int binarySearch(int x[], int l, int r, int target){ //O(log(n))
    //this is stil order log(n) because it only calls binarySearch once in each of the if statements
    if(r<l)
        return -1;
    int mid = (l+r)/2;
    if (x[mid]< target)
        return binarySearch(x, mid+1, r, target);

    else if (x[mid] > target)
        return binarySearch(x, l, mid-1, target);
    return mid;
}

int x[] = {1,2,3,4,5,6,9,10,19,20,26,31,40,99,200,221};
int main() {
    int target;
    cin >> target;
    cout << binarySearch(x, sizeof(x)/sizeof(int), target) << '\n';
}
