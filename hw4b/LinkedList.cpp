#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

class LinkedList{
private:
  class Node{
  public:
    int val;
    Node* next;
    Node(int val, Node* next): val(val), next(next){}
  };
  Node* head;
  Node* tail;
  uint32_t size_;
public:
  LinkedList() : head(nullptr), tail(nullptr), size_(0){}
  int get(int i) const{
    Node* p = head;
    for (; i>0 && p != nullptr;i--)
      p = p->next;
    return p->val;
  }

  void addFirst(int val){
    size_++;
    if(head != nullptr){
      Node* temp = new Node(val, head);
      head = temp;
    } else {
      tail = head = new Node(val, head);
    }
  }

  void addEnd(int val){
    size_++;
    if (tail != nullptr){
      Node* temp = new Node(val, nullptr);
      tail->next = temp;
      tail = temp;
    } else{
      head= tail = new Node(val, tail);
    }
  }

  void removeStart(){
    size_--;
    if(head->next!=nullptr){
      Node* temp = head;
      head = head -> next;
      delete temp;
    } else {
      head = nullptr;
    }
  }

  void removeEnd(){
    size_--;
    Node* p = head;
    if(head==tail){
      head = tail = nullptr;
      return;
    }
    for(; p->next != tail; p=p->next)
      ;
    Node* temp = tail;
    tail = p;
    if(tail != nullptr)
      tail->next = nullptr;
    else
      tail=head = nullptr;
    delete temp;
  }

  uint32_t size(){
    return size_;
  }

  class ConstIterator {
  private:
    Node* current;
  public:
    ConstIterator(const LinkedList& list) : current(list.head) {};
    bool hasNext() const{
      return current != nullptr;
    }
    void next(){
      current = current -> next;
    }
    int getValue() const{
      return current->val;
    }
  };

  class Iterator {
  private:
    Node* current;
  public:
    Iterator(LinkedList& list) : current(list.head) {};
    bool hasNext() const{
      return current != nullptr;
    }
    void next(){
      current = current -> next;
    }
    int getValue(){
      return current->val;
    }
  };
};

template<typename T>
class GrowArray{
private:
  T* data;
  int len;
  int capacity;
  void grow(){
    capacity = capacity * 2 + 1; //not actually doubling every time but close enough
    T* old = data;
    data = new T[capacity];
    for(int i =0; i < len; i++)
      data[i] = old[i];
    delete[] old;
  }
public:
  GrowArray(int initialCapacity) : capacity(initialCapacity), len(0), data(new T[initialCapacity]){}
  GrowArray() : len(0), capacity(0), data(nullptr) {}

  void addStart(T v){//O(len)
    if(len >= capacity) //Java: len>= data.length
      grow();
    for (int i = len-1; i >=0; i--)
      data[i+1] = data[i];
    data[0]=v;
    len++;
  }

  void removeStart(){ //O(len)
    for (int i =0; i < len-1; i++)
      data[i] = data[i+1];
    len--;
  }

  int removeEnd(){ // O(1)
    return data[--len];
  }

  void addEnd(T v){ // O(1,1,1,1,n,1,1,1,1,1,1,1,1,n)
    if (len >= capacity)
      grow();
    data[len++] = v;
  }

  T getValue(int pos){
    return data[pos];
  }

  int size(){
    return len;
  }

  friend ostream& operator << (ostream& s, const GrowArray<T>& b){ //O(n)
    for(int i=0; i < b.len; i++)
      s << b.data[i] << endl;
    return s;
  }
};

void f(const LinkedList& list){
  for(LinkedList::ConstIterator i = list; i.hasNext(); i.next()) //O(n)
    cout << i.getValue() << ',';
}

int main(){
  LinkedList a;
  GrowArray<string> b;

  ifstream infile;

  infile.open("HW4b.txt");
  if (!infile) {
      cout << "Unable to open file";
      exit(1); // terminate with error
  }

  string s;
	while(infile >> s){
		 b.addEnd(s);
	}
	infile.close();


  for(int i=0; i<b.size();i++){
    string command = b.getValue(i);

    string start = "";
    string step = "";
    string end = "";

    if (command == "ADD_FRONT"){
      i++; //we now want the numbers we need to add to the LinkedList
      string numbers = b.getValue(i);

      int j =0;

      while(numbers.at(j)!= ':'){
        start += numbers.at(j);
        j++;
      }

      j++;
      while(numbers.at(j)!= ':'){
        step += numbers.at(j);
        j++;
      }

      j++;
      while(j<numbers.length()){
        end += numbers.at(j);
        j++;
      }

      for(int k = stoi(start); k<=stoi(end); k+=stoi(step))
        a.addFirst(k);
    }

    else if (command == "ADD_BACK"){
      i++; //we now want the numbers we need to add to the LinkedList
      string numbers = b.getValue(i);

      int j =0;

      while(numbers.at(j)!= ':'){
        start += numbers.at(j);
        j++;
      }

      j++;
      while(numbers.at(j)!= ':'){
        step += numbers.at(j);
        j++;
      }

      j++;
      while(j<numbers.length()){
        end += numbers.at(j);
        j++;
      }
      for(int k = stoi(start); k<=stoi(end); k+=stoi(step))
        a.addEnd(k);
    }
    else if (command == "REMOVE_FRONT"){
      i++;
      string numToDelete = b.getValue(i);
      for(int k=0; k< stoi(numToDelete); k++)
        a.removeStart();
    }
    else if (command == "REMOVE_BACK"){
      i++;
      string numToDelete = b.getValue(i);
      for(int k=0; k< stoi(numToDelete); k++)
        a.removeEnd();
    }
    else{
      f(a);
      cout << endl;
    }
  }
}
