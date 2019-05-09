#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Matrix {
private:
  int rows,cols;
  double* m;
  Matrix(int r, int c) : rows(r), cols(c), m(new double[r*c]) {}
public:
  //constructor to fill Matrix with a certain value
  Matrix(int r, int c, double val) : rows(r), cols(c), m(new double[r*c]) {
    for (int i = 0; i < r*c; i++)
      m[i] = val;
  }

  //destructor
  ~Matrix() {
    delete [] m; //O(1)
  }

  //copy some matrix
  Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols), m(new double[rows*cols]) {
    for (int i = 0; i < rows*cols; i++)
      m[i] = orig.m[i]; //O(r*c)
  }

  //getter for the number of rows in a matrix
  int getRows(){
      return rows;
  }

  //getter for the number of columns in a matrix
  int getCols(){
      return cols;
  }

  //copy and swap
  Matrix& operator =(const Matrix& orig) {
    Matrix copy(orig); //O(rows*cols)
    swap(m, copy.m);//O(1)
    rows = copy.rows;//O(1)
    cols = copy.cols;//O(1)
    return *this;
  }

  //operator for m[i]
  double operator[](int i) const {
    return m[i];
  }
  double& operator[](int i) {
    return m[i];
  }

  // move constructor
  Matrix(Matrix&& orig) : rows(orig.rows),  cols(orig.cols) {
    m = orig.m;
    orig.m = nullptr;
  }

  //O(rows*cols) if they are the same O(n^2)
  //Operator for matrix a + matrix b
  friend Matrix operator +(const Matrix& a, const Matrix& b) {
    if (a.rows != b.rows || a.cols != b.cols)
      throw "Bad matrix size";
    Matrix ans(a.rows,a.cols); //O(1)
    for (int i = 0; i < a.rows*a.cols; ++i)
      ans[i] = a[i] + b[i];
    return ans; //O(1)
  }

  //operator for m(i,j)
  double  operator()(int i, int j) const {
    return m[i*cols+j];
  }
  double&  operator()(int i, int j) {
    return m[i*cols+j];
  }

  //operator for matrix a * matrix b
  friend Matrix operator *(const Matrix& a, const Matrix& b) {
    if (a.cols != b.rows)
      throw "Bad matrix size";
    Matrix ans(a.rows, b.cols);
    for (int i = 0; i < a.rows; ++i)
      for (int j = 0; j < b.cols; ++j) {
	       double dot = 0;
	       for (int k = 0; k < a.cols; k++)
	        dot += a(i, k) * b(k, j);
	       ans(i,j) = dot;
      }
    return ans;
  }

  //operator to prit out the some matrix in the form cout << matrix
  friend ostream& operator <<(ostream& s, const Matrix& b){ //O(n)
    for(int i = 0; i < b.rows; i++){
      for(int j = 0; j < b.cols; j++){
        cout.precision(1);
        s << fixed << b(i,j) << ' ';
      }
      s << endl;
    }
    return s;
  }

  //reads some file into a matrix
  static Matrix read(istream& s) {
    int n;
    s >> n;
    Matrix m(n,n);
    for (int i = 0; i < n*n; i++){
      s >> m[i];
    }
    return m;
  }

  //reads some file into a matrix with a parameter for size
  static vector<double> read(int n, istream& s) {
      vector<double> B;
      B.reserve(n);
      double tmp;
      for (int i = 0; i < n; ++i) {
          s >> tmp;
          B.push_back(tmp);
      }
      return B;
  }

  //used for solving
  //this is the second method that is needed at the very end of solving
  static vector<double> backSubstitute(Matrix& m, vector<double>& x, vector<double>& B) {
      for (int n = m.rows; n > 0; n--) {
          x[n-1] = B[n-1] / m(n-1,n-1);
          for (int j = n-2; j >= 0; j--)
              B[j] -= m(j,n-1) *x[n-1];
      }
      return x;
  }

  //uses partialPivot this is the first step in solving
  static void partialPivot(Matrix& m, int i, vector<double>& B) {
   int biggestPos = i;
   double biggest = abs(m(i,i));
   // partial pivoting
   for (int j = i; j < m.rows; j++) {
     if (abs(m(j,i)) > biggest) {
        biggest = m(j,i);
        biggestPos = j;
     }
   }
   // swap rows biggestpos,i
   for(int j=0; j< m.cols; j++){
       swap(m(i,j),m(biggestPos,j));
   }
   swap(B[i],B[biggestPos]);
  }

  //method to solve
  friend vector<double> solve(Matrix& m, vector<double>& B) {
   vector<double> x;
   // rows = cols or we are DEAD
   x.reserve(m.rows);
   //need to initialize the x vector
   for(int i=0; i< m.rows;i++) {
       x.push_back(0);
   }
   for (int i = 0; i < m.rows-1; i++) {
     partialPivot(m, i, B);
     for (int k = i+1; k < m.rows; k++) {
         double s = -m(k, i) / m(i, i);
         m(k,i) = 0; // make sure this is exactly zero!
         for (int j = i + 1; j < m.cols; j++)
             m(k, j) += s * m(i, j); // modify remaining part of row
         B[k] += s * B[i];
     }
   }
   return backSubstitute(m,x,B);
  }

  //used to print out the vectors
  static void print(std::vector<double> const &input)
  {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
  }
};
