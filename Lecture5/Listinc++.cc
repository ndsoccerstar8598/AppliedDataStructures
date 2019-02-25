#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
	vector<int> a;
	const int n = 10;
	for (int i = 0; i <n;i++){
		a.push_back(i);
	}
	for (int i = 0;i<a.size();i++){
		cout << a[i] << ' ';
	}
	cout << "\n";
	for(vector<int>::iterator i = a.begin(); i != a.end;++i){//O(n) no matter what
		cout << *i->val << ' ';
	}
	for(auto x : a) {
		//internally it is calling an iterator and finding what it is best by itself
		cout << x << ' ';
	}
	
}


/*
Java way

public Class JavaIterators{
	public static void main(String[] args){
		ArrayList<integer> a = new ArrayList<>();
		final int n = 10;
		for(int i = 0;i < n; i++)
			a.add(i)
		for(ListIterator<Integer> i = a.listIterator(); i.hasNext();){
			Integer v = i.next();
			System.out.println(v);
		}
		//Kruger's way for an API
		for (ListIterator i = a.start();i.hasNext();i.next()){
			Integer v = i.get();
		}
	}
}







*/










