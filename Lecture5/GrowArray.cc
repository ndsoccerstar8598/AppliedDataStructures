#include <iostream>

using namespace std;

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
			len++;
			}
		}

		void addStart(int v) { //O(len)
			int* old = data;
			data = new int[len+1];
			data[0] = v;
			for (int i =1; i <= len; i++){
				data[i] = old[i-1];
			}
			len++;
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
	a.addEnd(5);
}
