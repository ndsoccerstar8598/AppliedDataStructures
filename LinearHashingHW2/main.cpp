/*
  Nicholas DiMaria
  I pledge my honor that I have abided by the Stevens Honor System.
  Citations:
  --http://www.algolist.net/Data_structures/Hash_table/Chaining: General structure
  came from this website. Had to make modifications for strings and also had to
  add the ability to count collisions. In addition had to fix the put method.
  --https://www.geeksforgeeks.org/double-pointer-pointer-pointer-c/: Helped me
  understand what double pointers are
  --http://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec16/lec16-13.html: Some different
  string has functions. The first one was very basic but works well (according to
  this website for arrays under length 100). \
  --Besnik Balaj: General Discussion of code
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Node{
private:
    int key;
    string v;
    Node* next;
public:
    Node(int k, string v): key(k), v(v), next(nullptr) {}

    int getKey(){
        return key;
    }

    string getValue(){
        return v;
    }

    void setValue(string value){
        v = value;
    }

    Node *getNext(){
        return next;
    }

    void setNext(Node *n){
        next=n;
    }
};

const int TABLE_SIZE = 100;
class HashTable{
private:
    Node **table;
    int *histogram = new int[100];
public:
    HashTable(){
        table = new Node*[TABLE_SIZE];
        for(int i=0; i< TABLE_SIZE; i++){
            histogram[i] =0;
            table[i] = nullptr;
        }
    }

    void put(int key, string value){
        int hash = (key % TABLE_SIZE);
        if(table[hash] == nullptr){
            table[hash] = new Node(key, value);
        }
        else{
            histogram[hash]++;
            Node *entry = table[hash];
            while(entry->getNext() != nullptr){
                entry = entry->getNext();
            }
            entry->setNext(new Node(key, value));
        }
    }

    bool check(int key, string value){
        int hash = (key % TABLE_SIZE);
        if(table[hash] == nullptr)
            return false;
        else{
            Node *entry = table[hash];
            while(entry != nullptr && entry->getValue().compare(value)!=0)
                entry = entry->getNext();
            if(entry == nullptr)
                return false;
            else
                return true;
        }
    }

    int* getHistogram(){
        return histogram;
    }
};

int hashFunction(string word){
    int sum = 0;
    for (int i =0; i< word.length();i++){
        sum += word[i] - 'a';
    }
    return sum;
}

int main(){
    ifstream infile;
    HashTable a;
    infile.open("dict.txt");
    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    string s;
    while (infile >> s){
        a.put(hashFunction(s),s);
    }
    infile.close();

    infile.open("hw8.dat");
    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    int count =0;
    while(infile >> s){
        count++;
    }
    infile.close();

    infile.open("hw8.dat");
    string words[count];
    count =0;
    while(infile >> s){
        if (s.find("'") == string::npos) {
            words[count]=s;
            count++;
        }
    }
    infile.close();

    for(int i=0; i< count; i++){
        if(a.check(hashFunction(words[i]),words[i])){
            cout << "true" << endl;
        }
        else
            cout << "false" << endl;
    }

    int* histogram = new int[100];
    histogram = a.getHistogram();

    for(int i= 0; i<100;i++){
        cout << i << " " << histogram[i] <<endl;
    }

}