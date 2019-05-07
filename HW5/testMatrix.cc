#include "Matrix.cc"

int main() {
  Matrix a(3,4,2.0);  // O(mn) = O(3*4)
  cout << a;
  cout << endl;

  Matrix b(4,2,1.0); //O(n*p) = O(4*2);
  cout << b;
  cout << endl;

  Matrix c = b; // make a copy O(np)
  cout << c;
  cout << endl;

  Matrix d = a + a;  //O(mn)
  cout << d;
  cout << endl;

  Matrix e = a * b;  //O(mnp)    O(n^3)
  cout << e;
  cout << endl;

  b(1,1) = 5.2; // calls operator()(int,int)
  cout << b;
  cout << endl;

  cout << b(1,2); // calls operator()(int,int)const
  cout << endl;

  b[3] = 2.0; // calls operator [](int)
  cout << b;
  cout << endl;

  cout << b[0];
  cout << endl;

  e = b;
  cout << e;
  cout << endl;
	/*
		a11 a12 a13      x           B1
		a21 a22 a23      y    =     B2
       a31 a32 a33      z           B3
	 */
  ifstream f("hw5.dat");
  Matrix z = Matrix::read(f);
  Matrix z2=z;
  cout << z << endl;

  vector<double> B = Matrix::read(z.getRows(), f);
  vector<double> B2 = B;
  Matrix::print(B);
  cout << endl;

  vector<double> x = solve(z, B);
  cout <<endl;
  cout << "Solution (x y z...): ";
  Matrix::print(x);
  cout << endl;

  Matrix::print(B2);
  cout << endl;

  cout << z2;
  vector<double> y = solveFull(z2,B2);
  cout << endl;
  cout << "Solution (x y z...): ";
  Matrix::print(y);
}
