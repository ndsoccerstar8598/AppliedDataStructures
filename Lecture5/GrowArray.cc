class GrowArray{
private:
  int capacity; //the size of the block of memory
  int size;     //how many are used
  int* p;       //pointer to the block
public:
  GrowArray() {}
  GrowArray(int initialSize){}
  void insertEnd(int v){ //O(1)

  }
  void insertStart(int v){

  }
  void insert(int pos,int v){ //O(n)

  }
  void removeStart(){ //O(n)

  }
  void removeEnd(){//O(1)

  }
  friend ostream& operatror <<(ostream& s, const BadGrowArray& b){ //O(n)
    for(int i=0; i < b.size; i++)
      s << b.p[i] << ' ';
    return s;
  }
};

int main(){
  GrowArray b;
  for (int i = 0; i <10; i++)
    b.insertEnd(i);
  for (int i = 0; i <10; i++)
    b.insertStart(i);
  cout << b;
  for (int i = 0; i <10; i++)
    b.removeStart();
  b.removeEnd();
  cout << b << '\n';
}
