#include <iostream>
using namespace std;

class BadGrowArray{
private:
  int size;
  int* p;
public:
  BadGrowArray() : size(0), p(nullptr) {}
  void insertEnd(int v){ //O(size) = O(n)
    int* old = p; // O(1)
    //create a temp pointer to save where the pointer was
    p = new int[size +1]; //O(1)
    //create a new array with size+1
    for (int i =0; i < size; i++ ) //O(size) copy old array to new array
      p[i] = old[i];
    p[size++]=v; //O(n) increase the size and put the new element at the end
    delete [] old; //O(n) deallocate memory
  }
  void insertStart(int v){
    int* old = p;
    p = new int[size+1];
    p[0]=v;
    for (int i = 1; i <= size; i++ ) //copy old array to new array
      p[i] = old[i-1];
    size++;
    delete [] old;
  }
  void insert(int pos,int v){ //O(n)
    int* old = p; //O(1)
    p = new int[size+1]; //O(1)

    //The complexity of both the loops below O(n)
    for (int i = 0; i < pos; i++)
      p[i] = old[i];
    p[pos]=v;
    for (int i = pos+1; i<=size;i++)
      p[i]=old[i-1];
    size++;
    delete [] old;
  }
  void removeStart(){ //O(n)
    for(int i=0;i<size-1;i++)
      p[i] = p[i+1];
    size--;
    //this leaks memory because the end memory location is not deallocated
  }
  void removeEnd(){//O(1)
    size--;
  }

  friend ostream& operator <<(ostream& s, const BadGrowArray& b){ //O(n)
    for(int i=0; i < b.size; i++)
      s << b.p[i] << ' ';
    return s;
  }
};

int main(){
  BadGrowArray b;
  for (int i = 0; i <10; i++)
    b.insertEnd(i);//1 + 2 + 3 + ... + n = O(n^2)
  for (int i = 0; i <10; i++)
    b.insertStart(i);
  for (int i = 0; i <10; i++)
    b.insert(5,99);
  cout << b;
  for(int i=0; i<20; i++)
    b.removeStart();
  cout << b << '\n';
}
