#include <iostream>
#include <cmath>

using namespace std;

double f(double x){ return x*x;}
double g(double x){ return x*x*x*x;}

typedef double (*FuncOneVar)(double x);

constexpr double x2 = 1/sqrt(3);
double gauss2(FuncOneVar f, double a, double b){ //h^4 accurate
    double mid = (a+b)/2;
    double h = (b-a)/2;
    double x0 = mid - x2 * h;
    double x1 = mid + x2 * h;
    double y0 = f(x0);
    double y1 = f(x1);
    return y0+y1;
}

int main(){
  cout << gauss2(f,0,2) << '\n'; //8/3 = 2.666
  cout << gauss2(g,0,2) << '\n';

}
