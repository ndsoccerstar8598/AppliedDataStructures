/*
	Nicholas DiMaria
	I pledge my honor that I have abided by the Stevens Honor System.
*/

#include <iostream>
#include <random>
using namespace std;

double choose(int n, int r) {
	static double memo[501][501] = {0};
    if (r==0)
        return 1;
    else if(n==r)
        return 1;
    else if(r==1)
        return n;
    //this should allow it to only store half of the numbers due to symmetry
    else if(n/r < 2.0 && memo[n][n-r]!=0){
        return memo[n][n-r];
   	}
    else if (memo[n][r]!=0)
        return memo[n][r];
    else
        return memo[n][r]=choose(n-1,r-1) + choose(n-1,r);
}

int main() {
	cout << "hello" << endl;
	int n=0;
	int r=0;
	for(n=0; n<=500;n++){
			for(r=0; r<=n;r++){
					choose(n,r);
			}
	}

	cout << "hello2" << endl;
  int numTrials = 100000000;
	//  cin >> numTrials;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0,500);

  for (int i = 0; i < numTrials; i++) {
		int n = distribution(generator);
		uniform_int_distribution<int> rdist(0,n);
		int r = rdist(generator);
    choose(n,r);
	}
}
