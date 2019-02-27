#include <iostream>
#include <fstream>
#include <tuple>
using namespace std;

class GrowArray {
	private:
		int* data;
		uint32_t len;
		uint32_t capacity; //this is a thing for homework
		//void grow() {
			//double the size is best way, only called logn times
			//int* duo = data;
			//data = new int[len * 2];
		//}
	public:
		GrowArray():data(nullptr),len(0){}
		void addEnd(int v) {//O(len) which is pretty bad since complexity will yeet this out of window
			//if (len >= capacity)
				//grow();
			int* old = data; //O(1)
			data = new int[len+1]; //O(1) in C++ but Java is O(n)
			for(int i = 0; i<len;i++){ //O(len) but Java is O(2len)
				data[i] = old[i];
			}
			//bottom portion frees old memory which is O(1)
			delete [] old; //this will be required for exams since Java does it for you and C++ needs it
			data[len] = v;
			len++;
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
	ifstream infile;

  infile.open("convexhullpoints.dat");
  if (!infile) {
      cout << "Unable to open file";
      exit(1); // terminate with error
  }

	//we are getting how many data points are in the file
	int num;
	int length=0;
	while(infile >> num){
		length ++;
	}
	infile.close();

	//divide the number of data points by 2
	length = length /2;

	infile.open("convexhullpoints.dat");
	if (!infile) {
			cout << "Unable to open file";
			exit(1); // terminate with error
	}

	//this is all we need to find min and max X
	int xValue[length];
	int maxX;
	infile >> maxX;
	int minX = maxX;
	xValue[0] = maxX;
	int xCount = 1;

	//this is all we need to find min and max Y
	int yValue[length];
	int maxY;
	infile >> maxY;
	int minY = maxY;
	yValue[0] = maxY;
	int yCount = 1;

	//go through the file and set x and y values to their correct arrays
	//at the same time we are going to try to find the max and min X and Y
	for (int i = 2; i<length*2; i++){
		if (i % 2 == 0){
			infile >> xValue[xCount];
			if(xValue[xCount] > maxX)
				maxX = xValue[xCount];
			else if(xValue[xCount] < minX){
				minX = xValue[xCount];
			}
			xCount++;
		}
		else{
			infile >> yValue[yCount];
			if(yValue[yCount] > maxY)
				maxY = yValue[yCount];
			else if(yValue[yCount] < minY){
				minY = yValue[yCount];
			}
			yCount++;
		}
	}

  infile.close();

	double Xperbox = (double)(15)/(maxX-minX);
	double Yperbox = (double)(15)/(maxY-minY);

	GrowArray box[16][16];
	int i,j;
	i=j=0;

	for(int q=0;q<length; q++){
		i = (yValue[q]-minY)*Yperbox;
		j = (xValue[q]-minX)*Xperbox;
		box[i][j].addEnd(xValue[q]);
		box[i][j].addEnd(yValue[q]);
	}

}
