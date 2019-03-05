#include <iostream>
using namespace std;

template<typename T>
class LinkList2019{
	private:
		class Node {
		public:
			int val;
			Node* next;
			Node(int v, Node* n) : val(v), next(n){}
		};
		Node* head;
	public:
	  LinkList2019() {
			head = nullptr; // O(1)
		}
	void addStart(int v) { //O(1)
		head = new Node(v,head);
	}
	void addEnd(int v){
		Node* temp = new Node(v,nullptr);
		Node* p;
		if (head == nullptr){
			head = temp;
			return;
		}
		//invariant : head is not nullptr, list has at least 1 element
		for (p = head;p->next != nullptr;p=p->next){
			//want to stop when next node pointer is nullptr
			p->next = temp;
		}

	}
	void insert(int pos, int v) {//O(n)
		//can ask for a pos out of length of list and cant really stop it
		Node* p = head;
		while (pos > 0){
			p = p->next;
			pos--;
		}
		//p = location + 1 which is his definition of it
		Node* temp = new Node(v,p->next);
		p->next = temp;
	}

	int removeStart() {
		//remove first element and return it
		Node* temp = head;
		head = head->next;
		return temp->val;
	}

	int removeEnd(){
		Node* p = head;
		Node* q = p->next;
		if (q == nullptr){
			int v = head->val;
			head = nullptr;
			return v;
		}
		//now we can know for sure there are 2 stuff in here
		for ( q->next != nullptr; p = q; q = q->next){
		;}
		p->next = nullptr;
		return q->val;

	}
	friend ostream& operator <<(ostream& s, const LinkList2019& list){//always make this const
		for (Node* p = list.head; p!=nullptr ;p = p->next){
			s << p->val << ' ';
		}
		return s;
	}
};

int main() {
	LinkList2019<int> a;
	for (int i = 0; i < 10; i++)
		a.addStart(i);
	for (int i = 0; i<10;i++)
		a.addEnd(i);
	a.removeStart();
	a.removeEnd();
	cout << a << '\n';

}
