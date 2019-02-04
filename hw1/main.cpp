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

static double memo[501][501] = {0};

double choose(int n, int r){

    if (r==0)
        return 1;
    else if (n==0)
        return 0;
    else if(n==r)
        return 1;
    else if(r==1)
        return n;
    //this should allow it to only store half of the numbers due to symmetry
    else if(n/r < 2.0 && memo[n][n-r]!=0)
        return memo[n][n-r];
    else if (memo[n][r]!=0)
        return memo[n][r];
    else
        return memo[n][r]=choose(n-1,r-1) + choose(n-1,r);
}

int main() {
    //cout << choose(n, r) << '\n'; //nCr // O(n/2) =O(n)
    //choose(52,1), choose(52,26), choose(52,26), //
    //n<500, r<n 500 x 500 = 25,000

    //choose(52,10),  choose (52,15), choose (52,20)
    //choose (52,12)

    int n=0;
    int r=0;
    for(n=0; n<=500;n++){
        for(r=0; r<=n;r++){
            choose(n,r);
        }
    }

    int chooseN, chooseR;
    cout << "What number would you like N to be: ";
    cin >> chooseN;

    cout << "What number would you like R to be: ";
    cin >> chooseR;

    cout << "This is what is actually stored in the array " << memo[chooseN][chooseR] << endl;
    cout << "This is what is spit out choose(" << chooseN << "," << chooseR << ")" << "\t" <<  choose(chooseN,chooseR) << '\n';
}
