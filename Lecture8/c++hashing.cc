#include <map> //rb tree
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;
int main(){
  unordered_map<string, double> myMap;
  myMap["APPL"] = 147;
  myMap["IBM"] = 118;
  myMap["X"] = 62;
  myMap["JPM"] = 105;

  cout << myMap ["APPL"] << '\n'; //O(1)

  for (unordered_map<string,double>::iterator i = myMap.begin(); i != myMap.end(); ++i)
    cout << i -> first << "==>" << i->second << '\n';
}
