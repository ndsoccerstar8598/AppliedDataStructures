#include <iostream>
using namespace std;

template<typename T>
class DoubleLinkedList{
private:
  class Node{
  public:
    T val;
    Node* next;
    Node* prev;
    Node(const T& val, Node* next, Node* prev): val(val), next(next), prev(prev){}
  };
  Node* head;
  Node* tail;
  uint32_t size_;
public:
  DoubleLinkedList() : head(nullptr), tail(nullptr), size_(0){}
  T get(int i) const{
    Node* p = head;
    for (; i>0 && p != nullptr;i--)
      p = p->next;
    return p->val;
  }

  void addFirst(const T& val){
    size_++;
    if(head != nullptr){
      Node* temp = new Node(val, head, nullptr);
      head->prev = temp;
      head = temp;
    } else {
      tail = head = new Node(val, head, nullptr);
    }
  }

  void addEnd(const T& val){
    size_++;
    if (tail != nullptr){
      Node* temp = new Node(val, nullptr, tail);
      tail->next = temp;
      tail = temp;
    } else{
      head= tail = new Node(val, tail, nullptr);
    }
  }
  uint32_t size(){
    return size_;
  }

  class ConstIterator {
  private:
    Node* current;
  public:
    ConstIterator(const DoubleLinkedList<T>& list) : current(list.head) {};
    bool hasNext() const{
      return current != nullptr;
    }
    void next(){
      current = current -> next;
    }
    T getValue() const{
      return current->val;
    }
  };

  class Iterator {
  private:
    Node* current;
  public:
    Iterator(DoubleLinkedList<T>& list) : current(list.head) {};
    bool hasNext() const{
      return current != nullptr;
    }
    void next(){
      current = current -> next;
    }
    T& getValue(){
      return current->val;
    }
  };
};

void f(const DoubleLinkedList<int>& list){
  for(DoubleLinkedList<int>::ConstIterator i = list; i.hasNext(); i.next()) //O(n)
    cout << i.getValue() << '\n';
}

int main(){
  DoubleLinkedList<int> list;
  for(int i=0; i <10;i++)
    list.addEnd(i);
  for(int i =0; i< list.size();i++)//O(n^2)
    cout << list.get(i) << '\n'; //ineffiecent traversal
  f(list);
  for(DoubleLinkedList<int>::Iterator i = list; i.hasNext(); i.next())
    i.getValue() *= 2;
  f(list);
  cout << '\n';

}
