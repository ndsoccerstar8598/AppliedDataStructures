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
  Matrix(int r, int c, double val) : rows(r), cols(c), m(new double[r*c]) {
    for (int i = 0; i < r*c; i++)
      m[i] = val;
  }

  ~Matrix() {
    delete [] m; //O(1)
  }

  Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols), m(new double[rows*cols]) {
    for (int i = 0; i < rows*cols; i++)
      m[i] = orig.m[i]; //O(r*c)
  }

  int getRows(){
      return rows;
  }

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
  friend Matrix operator +(const Matrix& a, const Matrix& b) {
    if (a.rows != b.rows || a.cols != b.cols)
      throw "Bad matrix size";
    Matrix ans(a.rows,a.cols); //O(1)
    for (int i = 0; i < a.rows*a.cols; ++i)
      ans[i] = a[i] + b[i];
    return ans; //O(1)
  }

  double  operator()(int i, int j) const {
    return m[i*cols+j];
  }

  double&  operator()(int i, int j) {
    return m[i*cols+j];
  }

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

  static Matrix read(istream& s) {
    int n;
    s >> n;
    Matrix m(n,n);
    for (int i = 0; i < n*n; i++){
      s >> m[i];
    }
    return m;
  }

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
    static vector<double> backSubstitute(Matrix& m, vector<double>& x, vector<double>& B) {
        for (int n = m.rows; n > 0; n--) {
            x[n-1] = B[n-1] / m(n-1,n-1);
            for (int j = n-2; j >= 0; j--)
                B[j] -= m(j,n-1) *x[n-1];
        }
        return x;
    }

    static vector<double> backSubstitute(Matrix& m, int pos, vector<double>& x, vector<double>& B) {
        for (int n = m.rows; n > 0; n--) {
            x[n-1] = B[n-1] / m(n-1,n-1);
            for (int j = n-2; j >= 0; j--)
                B[j] -= m(j,n-1) *x[n-1];
        }
        if(pos != 0){
            swap(x[0],x[pos]);
        }
        return x;
    }

   static void partialPivot(Matrix& m, int i, vector<double>& B) {
     int biggestPos = i;
     double biggest = abs(m(i,i));
     // partial pivoting
     for (int j = 0; j < m.rows; j++) {
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

   static int fullPivot(Matrix& m, vector<double>& B){
      int biggestPosi =0;
      int biggestPosj =0;
      double biggest = abs(m(0,0));
      for(int i =0; i < m.rows; i++){
          for(int j=0; j < m.cols; j++){
              if(abs(m(i,j)) > biggest){
                  biggest = m(i,j);
                  biggestPosi=i;
                  biggestPosj=j;
              }
          }
      }
      if(biggestPosj != 0){
          for(int i=0; i<m.rows; i++){
              swap(m(i,0),m(i,biggestPosj));
          }
      }
      return biggestPosj;
  }
   friend vector<double> solve(Matrix& m, vector<double>& B) {
     vector<double> x;
     // rows = cols or we are DEAD
     x.reserve(m.rows);
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

    friend vector<double> solveFull(Matrix& m, vector<double>& B) {
        vector<double> x;
        // rows = cols or we are DEAD
        x.reserve(m.rows);
        for(int i=0; i< m.rows;i++) {
            x.push_back(0);
        }
        int pos = fullPivot(m,B);
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
        return backSubstitute(m,pos,x,B);
    }

   static void print(std::vector<double> const &input)
   {
      for (int i = 0; i < input.size(); i++) {
          std::cout << input.at(i) << ' ';
      }
   }
};
