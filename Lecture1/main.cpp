#include <iostream>
using namespace std;
bool isPrime(uint64_t n){
    for (uint64_t i=2;i< n; i++){ //O(n)
        if (n%i ==0)
            return false; //omega(1)
    }
    return true;
}

//sum(1000000,1000001)
uint64_t sum(uint64_t a, uint64_t b){//O(b-a)
    uint64_t s=0;
    for(uint64_t i =a; i<=b;i++){
        s+=i;
    }
    return s;
}

uint64_t sum2(uint64_t a, uint64_t b){//O(1)
    return (b*(b+1)-a*(a+1))/2;
}


//1,1,2,3,5,8,...
int fibo(int n){ //O(n)
    int a=1, b=1, c;
    for(int i=0;i<n;i++){ //O(n)
        c=a+b; //O(1)
        a=b;   //O(1)
        b=c;   //O(1)
    }
    return c;
}

uint64_t fibo_r(int n){ //O(2^n)
    if(n <=2) //termination condition O(1)
        return 1;
    return fibo(n-1)+fibo(n-2);
}

uint64_t memoized_fibo(int n){ // this turns 2^n problem into an n^2 problem
    static uint64_t sum[200]={0};
    if (n<=2)
        return 1;
    if (sum[n]>0)
        return sum[n];
    return sum[n] = fibo(n-1) + fibo(n-2);
}

//O(1)
//
double choose(int n, int r){ //choose(52,6), choose(52,5), choose(53,6), choose(53,9)
    static double ans[500][500];

    //store choose(0,0), choose(2,0), choose(4,0), choose(0,2)
    /*
        * 0 * 0 * 0 *
        0 0 0 0 0 0 0
        * 0 * 0 * 0 *
        0 0 0 0 0 0 0
        * 0 * 0 * 0 *
     */
    /*
     Store every other number rather than every number  
     */
    //see how much faster the new solution is than the old solution
}

int main(){
    uint64_t n;
    cin >> n;
    cout << memoized_fibo(n);
    return 0;
}