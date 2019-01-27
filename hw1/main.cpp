/*
  Nicholas DiMaria
  I pledge my honor that I have abided by the Stevens Honor System.

  CITE: 2018F CPE 593 Lecture
*/
#include <iostream>
using namespace std;

//choose(n,r) = n!/(r!(n-r)!)
//52C6 = 52!/(6!46!) = 52*51*50*49*48*47 / 6*5*4*3*2*1 (worst this can get is O(n/2)
//Extreme cases : 52C1, 52C26
/*
        1           (0C0)
      1   1         (1C0) (1C1)
    1   2    1      (2C0) (2C1) (2C2)
  1   3    3    1   (3C0) (3C1) (3C2) (3C3)
1   4    6    4   1
 */
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
    double memo2[501][501]= {0};
    //cout << choose(n, r) << '\n'; //nCr // O(n/2) =O(n)
    //choose(52,1), choose(52,26), choose(52,26), //
    //n<500, r<n 500 x 500 = 25,000

    //choose(52,10),  choose (52,15), choose (52,20)
    //choose (52,12)
    int n=0;
    int r=0;
    for(n=0; n<=500;n++){
        for(r=0; r<=n;r++){
            memo2[n][r] = choose(n,r);
        }
    }

    cout << "choose(34,17)"<< "\t" <<  memo2[0][17] << '\n';
}
