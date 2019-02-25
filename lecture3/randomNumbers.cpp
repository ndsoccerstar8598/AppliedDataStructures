// basic file operations
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main () {
  srand (time(NULL));

  ofstream myfile;
  myfile.open ("numbers.txt");
  myfile << "1000000\n";
  for(int i =0; i <1000000; i++){
    myfile << rand() % 10 << " ";
  }
  myfile.close();
  return 0;
}
