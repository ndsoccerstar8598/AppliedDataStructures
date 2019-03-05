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
    if (length >= capacity)
      grow();
    data[len++] = v;
  }
};

int main(){ //O(n^2)
  GrowArray a;
  for (int i =0; i < n; i++)//O(n)
    a.addEnd(n); //O(1)
  for (int i = 0; i < n; i++) //O(n^2)
    a.addStart(n); //O(n)
}
