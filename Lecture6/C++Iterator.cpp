#include <iostream>
using namespace std;

template<typename T>
class GrowArray {
private:
	int len;
	int capacity;
	T* data;
public:
	GrowArray(int capacity) : //capacity(capacity), len(0), data(new char[sizeof(T)*capacity]) {}
	capacity(capacity), len(0), data(new T[capacity]){}
	~GrowArray() {
		for (int i = 0; i< len; i++){
			//call destructor on only elements that exist!;
		}
	}
	GrowArray(const GrowArray& orig) : capacity(orig.capacity), len(orig.len) {
		data = new T[capacity];
		for(int i = 0; i < len; i++){
			data[i] = orig.data[i];}
	}
	
	void operator = (const GrowArray& orig) = delete;
	void addEnd(int v){
		if (len >= capacity){
			T* old = data;
			data = new T[capacity *= 2];
			for(int i = 0; i< len; i++){
				data[i] = old[i];
			}
		}
		data[len++] = v;
		
	}
	class iterator {
		private:
			int pos;
			GrowArray<T> list;
		public:
			iterator(GrowArray<T>& list):list(list), pos(0){} //this has to have a reference 
			bool operator !() const;{return pos < list.len;}
			void operator ++() {pos++;} //this cannot be const, it changes iterator 
			T& operator *(){ return list.data[pos];}
	
	};
	
};



int main(){
	GrowArray<int> a(3);
	a.addEnd(5);
	a.addEnd(4);
	GrowArray<int> b = a;
	for (GrowArray<int>::iterator i = a; !i; ++i){ //O(n)
		*i *= 2;
	}
	for (GrowArray<int>::iterator i = a; !i; ++i){
		cout << *i << '\t';	
		cout << '\n';}	
}