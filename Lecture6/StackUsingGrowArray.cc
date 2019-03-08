#include <iostream>
using namespace std;

class GrowArray{
private:
  int * data;
  int len;
  int capacity;
  void grow(){
    capacity = capacity * 2 + 1; //not actually doubling every time but close enough
    int* old = data;
    data = new int[capacity];
    for(int i =0; i < len; i++)
      data[i] = old[i];
  }
public:
  GrowArray(int initialCapacity) : capacity(initialCapacity), len(0), data(new int[capacity]){}
  GrowArray() : len(0), capacity(0), data(nullptr) {}

  void addStart(int v){//O(len)
    if(len >= capacity) //Java: len>= data.length
      grow();
    for (int i = len-1; i >=0; i--)
      data[i+1] = data[i];
    data[0]=v;
  }

  void removeStart(){ //O(len)
    for (int i =0; i < len-1; i++)
      data[i] = data[i+1];
    len--;
  }

  int removeEnd(){ // O(1)
    return data[--len];
  }

  void addEnd(int v){ // O(1,1,1,1,n,1,1,1,1,1,1,1,1,n)
    if (len >= capacity)
      grow();
    data[len++] = v;
  }
  bool isEmpty(){
    if(len == 0)
      return true;
    return false;
  }

  friend ostream& operator <<(ostream& s, const GrowArray& b){ //O(n)
    for(int i=0; i < b.len; i++)
      s << b.data[i] << ' ';
    return s;
  }
};

class Stack{
private:
  GrowArray a;
public:
  void push(int v){
    a.addEnd(v);
  }
  int pop(){
    return a.removeEnd();
  }
  bool isEmpty(){
    return a.isEmpty(); // in GrowArray bool isEmpty() {return used == 0}
  }
  void print(){
    cout << a;
  }
};

int main(){
  Stack a;
  for (int i =0; i < 10; i++)
    a.push(i);
  a.print();
  cout << endl;
  a.pop();
  a.print();
}
