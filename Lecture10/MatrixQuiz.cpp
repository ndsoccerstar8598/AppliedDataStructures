class Matrix{
  int rows, cols;
  double* m;
  Matrix(int rows, int cols): rows(rows), cols(cols), m(new double[rows*cols]){ //O(1)
  }
public:
  Matrix(int rows, int cols, double v): rows(rows), cols(cols), m(new double[rows*cols]){ //O(rows*cols)
    for(int i=0; i < rows*cols; i++)
      m[i] = v;
  }

  friend Matrix operator+(const Matrix& a, const Matrix b){ //O(rows*cols)
    if(a.rows!=b.rows || a.cols != b.cols)
      throw "Bad Size";
    Matrix ans(a.rows,a.cols);
    for(i=0; i< rows*cols; i++){
      ans.m[i] = a.m[i] + b.m[i];
    }
  }
};
/*
*   *   0   0   0
*   *   *   0   0
0   *   *   *   0
0   0   *   *   *
0   0   0   *   *

n + n-1 + n-1 = 3n-2

1   2   0   0   0         2   1   0   0   0
-1  1   2   0   0         -2  3   1   0   0
0   1   0   3   0         0   2   1   2   0
0   0   -1  1   2         0   0   3   1   1
0   0   0   -3  2         0   0   0   1   4
*/

class TriDiagonalMatrix{
private:
  int n;
  double* m;
  TriDiagonalMatrix(int n, double v): n(n), m(new double[3n-2]){//O(1)
  }
public:
  TriDiagonalMatrix(int n, double v): n(n), m(new double[3n-2]){//O(3n)=O(n)
    for (int i =0; i < 3n-2; i++)
      m[i]=v;
  }
  //adding is O(n)

  friend TriDiagonalMatrix operator*(const TriDiagonalMatrix& a, const TriDiagonalMatrix& b){
    if(a.n != b.n)
      throw "bad size";
    TriDiagonalMatrix ans(a.n);
    double dot = 0;
    for(int i = j; i < j+3; i++){//O(3)=O(1)
      dot += a(?,i) * b(i,j)
    }
    //only doing middle ones
    for(int i=1; i<n-1;i++){
      ans(i,i-1) =
      ans(i,i) = a(i,i-1)* b(i-1,i) + a(i,i)*b(i,i) + a(i,i+1)*b(i+1,i); //O(1)
      ans(i,i+1) =
    }
  }
};

//this one is slower because you are writing to memory every time
for k← 0 to m-1
 for j← 0 to p-1
  dot ← 0
  for i ← 0 to n-1
    c(k,j) ← c(k,j) + a(k, i) * b(i, j)
  end
 end
end

for k← 0 to m-1
 for j← 0 to p-1
  dot ← 0
  for i ← 0 to n-1
    dot ← dot + a(k, i) * b(i, j)
  end
  c(k, j) ← dot
 end
end

//remove the element in row2 using row1
reducerow(row1, row2)

s = m(row2,row1) / m(row1,row1)

m(row2, row1)=0
for(int i=row1+1; i<n; i++)
  m(row2, i) = m(row2, i) - s * m(row1,i)
