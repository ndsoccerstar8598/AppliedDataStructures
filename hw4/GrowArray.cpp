#include <iostream>
#include <fstream>
using namespace std;

// Class to represent points.
class Point {
private:
  double xval, yval;
public:
  // Constructor uses default arguments to allow calling with zero, one,
  // or two values.
  Point(double x = 0.0, double y = 0.0) {
          xval = x;
          yval = y;
  }

  // Extractors.
  double x() { return xval; }
  double y() { return yval; }

	//this will allow us to reset the values after they are initialized
	void move(double a, double b)
	{
				 xval = a;
				 yval = b;
 	}

	//this allows us to use cout << point
	//this was from 2018F lecutre
  friend ostream& operator <<(ostream& s, const Point& b){ //O(n)
    s << '(' << b.xval << ',' << b.yval << ')' ;
    return s;
  }
};

class GrowArray {
	private:
		//we now need to make data an array of Points rather than ints
		//this need to the same throughout all of grow array
		Point* data;
		uint32_t len;
		uint32_t capacity; //this is a thing for homework
		//void grow() {
			//double the size is best way, only called logn times
			//int* duo = data;
			//data = new int[len * 2];
		//}
	public:
		GrowArray():data(nullptr),len(0){}
		void addEnd(Point v) {//O(len) 
			//if (len >= capacity)
				//grow();
			Point* old = data; //O(1)
			data = new Point[len+1]; //O(1)
			for(int i = 0; i<len;i++){ //O(len) 
				data[i] = old[i];
			}
	
			delete [] old;
			data[len] = v;
			len++;
		}

		void addStart(int v) { //O(len)
			Point* old = data;
			data = new Point[len+1];
			data[0] = v;
			for (int i =1; i <= len; i++){
				data[i] = old[i-1];
			}
			len++;
			delete [] old;
		}

		void removeEnd(){
			Point* old = data;
			data = new Point[--len];
			for(int i = 0; i< len; i++)
				data[i] = old[i];
			delete [] old;
		}

		void cheatremoveEnd(){
			len--;
		}

		void removeStart() { //O(n)
			Point* old = data;
			data = new Point[--len];
			for(int i = 0; i< len; i++)
				data[i] = old[i+1];
			delete [] old;
		}

		uint32_t size() const {
			return len;
		}
		
		//same as before this allows us to use cout << GrowArray object
    friend ostream& operator <<(ostream& s, const GrowArray& b){ //O(n)
      for(int i=0; i < b.size(); i++)
        s << b.data[i] << ' ';
      return s;
    }
};

int main() {

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

	//create an array of points with the same amount of points we have in the file
	Point points[length];

	//here we are initializing the points to the correct x and y values 
	//this uses that move function we talked about before
	//really more of setter 
	for (int i =0; i < length; i++){
		points[i].move(xValue[i], yValue[i]);
	}

  infile.close();
	
	//calculate the appropriate X and Y perbox
	double Xperbox = (double)(15)/(maxX-minX);
	double Yperbox = (double)(15)/(maxY-minY);

	//here a 16x16 array of grow arrays is created 
	GrowArray box[16][16];
	int i,j;
	i=j=0;

	//now we loop through all the points
	//we calculate the appropriate i and j values
	//then we add the point to the appropriate grow array at cell (i,j)
	//then to check we are going to print out what is at the cell (i,j)
	for(int q=0;q<length; q++){
		i = (yValue[q]-minY)*Yperbox;
		j = (xValue[q]-minX)*Xperbox;
		box[i][j].addEnd(points[q]);
		cout << box[i][j] << endl;
	}


}
