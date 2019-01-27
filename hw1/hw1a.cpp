/* Nicholas DiMaria
*/

#include <iostream>
using namespace std;

double numPrime(int n){
    bool sieve[n+1];
    for(int i =2; i<=n; i++){
      //intializes array to all true
      sieve[i]=true;
    }

    for(int i=4; i<=n; i+=2){
      //sets all  even numbers to false since
      //all even numbers are not prime except 2
      sieve[i] = false;
    }

    for(int i=3; i<=n; i+=2){
      //starting at 3 we are going to start at i^2
      //and then at 2*i to get all odd numbers that arent prime
      if(sieve[i]){
        //we know that an odd number squared is odd and that
        //odd number + odd number is even
        // We know that all even numbers aren't prime so we add 2*i
        // since even + odd = odd
        for(int j=i*i; j<=n; j += 2*i){
          sieve[j] = false;
        }
      }
    }

    int sum = 0;
    //we are going to loop through the array and see how many numbers
    //are actually prime numbers. These are the numbers that are true in the
    //sieve array
    for(int i=2;i<=n;i++){
      if(sieve[i])
        sum ++;
    }
    return sum;

}

int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "The number of primes between 1 and " << number << " is " << numPrime(number) << endl;
}
