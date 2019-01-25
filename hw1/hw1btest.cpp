#include <iostream>
#include <iomanip>
using namespace std;

/**
	 Make sure your choose function works for test data
                  1
                1   1
              1   2   1
            1   3   3   1
          1   4   6   4   1
        1   5   10  10  5   1
      1   6   15  20  15  6   1
 */
// make your code work here
double choose(int n, int r){
    static double memo[501][501] = {0};
    if (r==0)
        return 1;
    else if(n==r)
        return 1;
    else if (memo[n][r]!=0)
        return memo[n][r];
    else
        return memo[n][r]=choose(n-1,r-1) + choose(n-1,r);
}

int main() {
	int testCases[][3] = {
		{0, 0, 1},
		
		{1, 0, 1},
		{1, 1, 1},

		{2, 0, 1},
		{2, 1, 2},
		{2, 2, 1},
		
		{5, 0, 1},
		{5, 1, 5},
		{5, 2, 10},

		{6, 3, 20}
	};
	const int numTestCases = 10;
	
	for (int i = 0; i < numTestCases; i++) {
		int n = testCases[i][0];
		int r = testCases[i][1];
		int result = testCases[i][2];
		
		if (choose(n, r) != result) {
			cerr << "Failed test case: choose(" << n << ", " << r << ") = " << result << '\n';
		}
	}

	cout << "Large number tests\n";
	cout << setprecision(15);
	cout << choose(52, 6) << "\n";
	cout << choose(52, 26) << "\n";
	cout << choose(150, 5) << "\n";
}
