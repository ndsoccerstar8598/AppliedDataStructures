#include <iostream>
using namespace std;

class DoubleLinkedList{
private:
  class Node{
  public:
    int val;
    Node* next;
    Node* prev;
    Node(int v, Node* n, Node* p):val(v),next(n), prev(p) {}
  };

  Node* head;
public:
  DoubleLinkedList() : head(nullptr){}
  ~DoubleLinkedList(){

  }
  void addStart(int v){
    if(head != nullptr){
      head = new Node(v, head, nullptr);
      head -> next -> prev = head;
      // Node* temp = new Node();
      // temp -> next = head;
      // temp -> prev = nullptr;
      // temp -> val = v;
      // head -> prev = temp;
      // head = temp;
    } else {
      // head = new Node();
      // head -> next = nullptr;
      // head -> prev = nullptr;
      // head -> val = v;
      head = new Node(v,nullptr,nullptr);
    }
  }
  void addEnd(int v){
    if (head == nullptr){
      // head = new Node();
      // head -> val =v;
      // head -> next = nullptr;
      // head -> prev = nullptr;
      head = new Node(v, nullptr,nullptr);
      return;
    }

    Node* p;
    for (p=head; p ->next != nullptr; p = p-> next)
      ;
    // p is guaranteed to point to last element
    // Node* temp = new Node();
    // temp -> next = nullptr;
    // temp -> prev = p;
    // temp -> val = v;
    Node* temp = new Node(v, nullptr, p);
    p -> next = temp;
  }

  void removeStart(){
    Node* temp = head;
    head = head ->next;
    if(head != nullptr){
      head -> prev = nullptr;
    }
    delete temp;
  }

  void removeEnd(){
    if (head -> next == nullptr){
      removeStart();
      return;
    }
    Node* p; Node* q;
    for(p=head, q=p->next; q-> next!= nullptr; p=q, q=q->next)
      ;
    delete q;
    p->next = nullptr;
  }

  void insert(int v, int pos){
    Node* p = head;
    while (pos>0){
      pos--;
      p = p->next;
    }
    Node* temp = new Node(v,p->next,p);
    p-> next = temp;
    if (temp->next != nullptr){
        temp->next->prev = temp;
    }
  }

  friend ostream& operator << (ostream& s, const DoubleLinkedList& list){
      for (Node* p = list.head; p != nullptr; p = p->next)
      s << p->val << ' ';
    return s;
  }
};
int main(){
  DoubleLinkedList a;
  for(int i=0; i<10;i++)
    a.addEnd(i);
  cout << a << endl;
  a.removeEnd();
  cout << a << endl;
  a.insert(100,9);
  cout << a;
}
