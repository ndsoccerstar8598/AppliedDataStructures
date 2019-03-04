class Stack{//LIFO
private:
	LinkedList impl; //addFirst O(1) addLast O(n) removeFirst O(1) removeLast O(n)
	GrowArray impl; //addFirst O(n) addLast (1) removeFirst O(n) removeLast O(1) 
public:
	void push(int v) {impl.addFirst(v);} //can use a linked list to efficiently do stack
	int pop() {return impl.removeFirst()} //for GrowArray need to just say addLast and removeLast
	bool isEmpty() const{return impl1.isEmpty();}
	int size() const {}
	
};

class Queue {//FIFO, use this for fairness
private:
	LinkedList2 impl: //has head and tail
public:
	void enqueue(int v) {impl.addLast(v)}//O(1)
	int dequeue(int v) {impl.removeFirst()}//O(1) time in 3 out of 4, only one it gets cucked is removeLast
	bool isEmpty() const {return impl.isEmpty() == null;)
	
};