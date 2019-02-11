#include <iostream>
#include <iomanip>

using namespace std;

double f1(double x){
    return x*x -2;
}

typedef double (*FuncOneVar)(double x); //creates a pointer to a function

double bisection(FuncOneVar f, double a, double b, double eps){
    double ya = f(a);
    double yb = f(b);
    if (ya * yb > 0)
        throw "Error! The function does not apper to cross zero here!\n";
    double mid;
    do{
        mid = (a+b)/2;
        double y = f(mid);
        if (y>0)
            b = mid;
        else if (y < 0)
            a = mid;
        else
            return mid;
    } while ( b-a > eps);
    return mid;
}

int main(){
    cout << bisection(f1,0,3,0.01) << '\n';
    cout << bisection(f1,0,3,0.0001) << '\n';
    cout << bisection(f1,0,3,0.000001) << '\n';
    cout << setprecision(15) << bisection(f1,0,3,0.00000000000001) << '\n';
}
