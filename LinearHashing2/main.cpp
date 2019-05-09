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
  string hash functions.

  --Besnik Balaj: General Discussion of code
  --Max Parisi: Helped me with the grow() function
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdint.h> /* Replace with <stdint.h> if appropriate */

using namespace std;

#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
  || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const uint16_t *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
                       +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif

uint32_t SuperFastHash (const char * data, int len) {
    uint32_t hash = len, tmp;
    int rem;
    //cout << len << endl;
    if (len <= 0 || data == NULL) return 0;

    rem = len & 3;
    len >>= 2;

    /* Main loop */
    for (;len > 0; len--) {
        hash  += get16bits (data);
        tmp    = (get16bits (data+2) << 11) ^ hash;
        hash   = (hash << 16) ^ tmp;
        data  += 2*sizeof (uint16_t);
        hash  += hash >> 11;
    }

    /* Handle end cases */
    switch (rem) {
        case 3: hash += get16bits (data);
            hash ^= hash << 16;
            hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
            hash += hash >> 11;
            break;
        case 2: hash += get16bits (data);
            hash ^= hash << 11;
            hash += hash >> 17;
            break;
        case 1: hash += (signed char)*data;
            hash ^= hash << 10;
            hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}

class Node{
private:

public:
    int key;
    string value;
    Node* next;
    Node(int k, string v): key(k), value(v), next(nullptr) {}

    int getKey(){ //getter for the key
        return key;
    }

    string getValue(){ //getter for the value. Needs to be a string
        return value;
    }

    void setValue(string v){ //setter for the value. Needs to be a string
        value = v;
    }

    Node *getNext(){ //getter for the next Node. Returns a Node
        return next;
    }

    void setNext(Node *n){ //setter for the next Node. Neeeds to take in a pointer
        next=n;
    }
};


class HashTable{
private:
    Node **table; //create a double pointer to a node called table
    int *histogram = new int[10]; //create an integer array called histogram
    int capacity; //this will keep track of the current total size of the table.
    int fullness; //this will keep track of how many items in the array are full
    bool reinsert;
    void grow(){
        int len = capacity; //save the capacity in a variable called length
        capacity = capacity * 2 + 1;
        Node** old =table; //save the spot where table is currently stored
        reinsert = true;
        table = new Node*[capacity]; //table now points to a large chunk
        for(int i =0; i < capacity; i++)
           table[i] = nullptr; //set everything in the chunk to nullptr
        for(int i=0; i<len;i++) {
          Node *p, *q;
          p=old[i];
          while(p){
            put(p->value);
            q = p->next;
            delete p;
            p=q;
          }
        }
        reinsert = false;
        delete[] old;
    }
public:
    HashTable(){
        capacity = 100; //set the initial capacity to 100
        table = new Node*[capacity];
        for(int i=0; i < capacity; i++){
          table[i] = nullptr; //initialize everything to null
        }
        for(int i=0; i<10;i++) {
          histogram[i] = 0; //initialize the histogram array to 0
        }
        fullness = 0;
        reinsert =false;
    }

    void put(string value){
        uint32_t key = SuperFastHash(value.c_str(),value.length());
        int count = 0; //initialize this to 0 everytime
        if(fullness * 2 >= capacity) { //check if the number of points is > 1/4 of the overall capacity
            grow();
        }
        int hash = (key % capacity); //take the key and mod the current length of the table
        if(table[hash] == nullptr){
            table[hash] = new Node(key, value);
            if(reinsert == false){
              histogram[0]++;
            }
            fullness++;
        }
        else{
            Node* entry;
            entry = table[hash];
            while(entry->getNext() != nullptr){
                count++;
                entry = entry->getNext();
            }
            if(reinsert == false){
              if(count < 9)
                  histogram[count]++;
              else
                  histogram[9]++;
            }
            entry->setNext(new Node(key, value));
        }
    }

    bool check(string value){
        uint32_t key = SuperFastHash(value.c_str(),value.length());
        int hash = (key % capacity);
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
        a.put(s);
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
        if(a.check(words[i])){
            cout << "true" << endl;
        }
        else
            cout << "false" << endl;
    }

    int* histogram = new int[100];
    histogram = a.getHistogram();

    for(int i= 0; i<10;i++){
        cout << i << " " << histogram[i] <<endl;
    }
}
