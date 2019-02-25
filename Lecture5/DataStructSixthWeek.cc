/*
Lists

List a
a.size()
a.get(i)
a.set(i,v)
a.addEnd(v)
a.addStart(v)
a.insert(i,v)
x <- a.removeEnd() //return value that will be removed
x <- a.removeStart()
x <- a.remove(i)



GrowArray
class GrowArray {
	private:
		int* data;
		uint32_t len;
		uint32_t capacity; //this is a thing for homework
		void grow() {
			//double the size is best way, only called logn times
			//int* duo = data;
			//data = new int[len * 2];
		}
	public:
		GrowArray():data(nullptr),len(0){}
		void addEnd(int v) {//O(len) which is pretty bad since complexity will yeet this out of window
			if (len >= capacity)
				grow();
			int* old = data; //O(1)
			data = new int[len+1]; //O(1) in C++ but Java is O(n)
			for(int i = 0; i<len;i++){ //O(len) but Java is O(2len)
				data[i] = old[i];
			//bottom portion frees old memory which is O(1)
			delete [] old; //this will be required for exams since Java does it for you and C++ needs it
			data[len] = v;
			len++
		}}
		void addStart(int v) { //O(len)
			int* old = data;
			data = new int[len+1];
			data[0] = v;
			for (int i =1; i <= len; i++){
				data[i] = old[i-1]
			}
			len++
			delete [] old;

		}

		void removeEnd(){
			int* old = data;
			data = new int[--len];
			for(int i = 0; i< len; i++)
				data[i] = old[i];
			delete [] old;
		}
		void cheatremoveEnd(){
			len--;
		}
		void removeStart() { //O(n)
			int* old = data;
			data = new int[--len];
			for(int i = 0; i< len; i++)
				data[i] = old[i+1];
			delete [] old;
		}


		uint32_t size() const {
			return len;
		}

		};

int main() {
	GrowArray a;
	a.addEnd(5)

}




if capacity is 1 and add 1 element in : len = capacity: double size to 2
when capacity equals length again : memory = 2*2 = 4
then 4*2 etc

1 + (1+1) + 2 + 1 + 1 + 4 + 1 + 1 + 1 + 1

n + n/2 + n/4 + n/8 + ... + 1 are places where we grow
n(1 + 1/2 + 1/4 + 1/8 +....) = 2n = O(n) where 1 is for copying stuff in and fractions move to 1

in C++
vector<int> a;
a.reserve(100000);



Linked List:
4 variations (5 kindof)
Head has only 1 pointer to a node with a value and so on

1) head points to first node
2) head points to first node and tail points to last one
3) Double linked list where head points to node and node can point to forward and back(first node has no reverse)
4) DoubleLinkedList 2 where we have tail again
#Trying to make Java look like C++ here#
public class LinkList2019{
	private class Node {// LinkedList2019s.Node
		public int val;
		public Node next;
	}
	
	private Node head;
	public LinkList2019() {
		head = nullptr; // O(1)
	}
	public void addStart(int v) { //O(1)
		Node temp = new Node();
		temp->val = v;
		temp->next = head;
		head = temp;
	}
	public void addEnd(int v){
		Node temp = new Node();
		temp->val = v;
		temp->next = nullptr;
		Node p;
		if (head == null){
			head = temp;
			return;
		}
		//invariant : head is not null, list has at least 1 element
		for (p = head;p.next != nullptr;p=p->next){
			//want to stop when next node pointer is null
			p->next = temp;
		}
		
	}
	public void insert(int pos, int v) {//O(n)
		//can ask for a pos out of length of list and cant really stop it
		Node p = head;
		while (pos > 0){
			p = p->next;
			pos--;
		}
		//p = location + 1 which is his definition of it
		Node temp = new Node();
		temp->val = v;
		temp->next = p->next;
		p.next = temp;
	}
	public int removeStart() {
		//remove first element and return it
		Node temp = head;
		head = head->next;
		return temp->val;
	}

	public int removeEnd(){
		Node p = head;
		Node q = p->next;
		if (q == nullptr){
			int v = head->value;
			head = nullptr;
			return v;
		}
		//now we can know for sure there are 2 stuff in here
		for (; q->next != nullptr; p = q; q = q->next){
		;}
		p->next = nullptr;
		return q->val;
		
	}
	public String to String(){
		StringBuilder b = new StringBuilder();//O(n)
		for (Node p = head; p != nullptr; p = p->next)
			b.append(p->value).append(' ');
		return b.toString(); //O(n)
	}


public static void maint(String[] args) {
	LinkList2019 a = new LinkList2019();
	for (int i = 0; i < 10; i++)
		a.addStart(i);
	for (int i = 0; i<10;i++)
		a.addEnd(i);
	a.removeStat();
	a.removeLast();
	
	
}






//With Constructors
public class LinkList2019{
	private class Node {// LinkedList2019s.Node
		public int val;
		public Node next;
		
		public Node(int v, Node n){
			val = v; next = n;
		}
	}
	
	private Node head;
	public LinkList2019() {
		head = nullptr; // O(1)
	}
	public void addStart(int v) { //O(1)
		head = new Node(v,head);
	}
	public void addEnd(int v){
		Node temp = new Node(v,Null);
		Node p;
		if (head == null){
			head = temp;
			return;
		}
		//invariant : head is not null, list has at least 1 element
		for (p = head;p.next != nullptr;p=p->next){
			//want to stop when next node pointer is null
			p->next = temp;
		}
		
	}
	public void insert(int pos, int v) {//O(n)
		//can ask for a pos out of length of list and cant really stop it
		Node p = head;
		while (pos > 0){
			p = p->next;
			pos--;
		}
		//p = location + 1 which is his definition of it
		p->next =Node temp = new Node(v,p->next);
	}
	public int removeStart() {
		//remove first element and return it
		Node temp = head;
		head = head->next;
		return temp->val;
	}

	public int removeEnd(){
		Node p = head;
		Node q = p->next;
		if (q == nullptr){
			int v = head->value;
			head = nullptr;
			return v;
		}
		//now we can know for sure there are 2 stuff in here
		for (; q->next != nullptr; p = q; q = q->next){
		;}
		p->next = nullptr;
		return q->val;
		
	}
	public String to String(){
		StringBuilder b = new StringBuilder();//O(n)
		for (Node p = head; p != nullptr; p = p->next)
			b.append(p->value).append(' ');
		return b.toString(); //O(n)
	}


public static void maint(String[] args) {
	LinkList2019 a = new LinkList2019();
	for (int i = 0; i < 10; i++)
		a.addStart(i);
	for (int i = 0; i<10;i++)
		a.addEnd(i);
	a.removeStat();
	a.removeLast();
	
	
}



























String s = ""
for (int i = 0; i<n; i++)
	s += 1;
String f(){}
String g(){}
String h(){return f() + g();}
 this changed to 
void f(StringBuilder b){}
void g(StringBuilder b) {}
void h(StringBuilder b){something happened here i believe f(g):g(g)}














*/