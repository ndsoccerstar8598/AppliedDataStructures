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

//this is the hash function given in class
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

//this is a crappy hash function that I used to test my code at first
int hashFunction(string word){
    int sum = 0;
    for (int i =0; i< word.length();i++){
        sum += word[i] - 'a';
    }
    return sum;
}

//we are first making a class called Node
class Node{
private:
    int key; //this will represent the hashed value
    string value; //this will represent the string held here
    Node* next; //this should point to the next node
public:
    Node(int k, string v): key(k), value(v), next(nullptr) {}

    //getters for the key, value, and next Node
    int getKey(){
        return key;
    }

    string getValue(){
        return value;
    }

    Node *getNext(){
        return next;
    }

    //setters for the value and next
    void setValue(string v){
        value = v;
    }

    void setNext(Node *n){
        next=n;
    }
};

//this is our class for the HashTable
class HashTable{
private:
    Node **table; //start with a double pointer to the table
    int *histogram = new int[10]; //this will count our intersections
    int capacity; //this will count the overall size of the hashtable
    int fullness; //this will represent how many spots in the hash table are full
    bool readding; //this is a boolean that gets activated when we are readding the values to the hashTable in the grow function
    void grow(){
        int len = capacity; //save the old capacity
        readding = true; //we activate readding to make sure we don't count collisions and add to fullness
        capacity = capacity * 2 +1;
        Node** old;
        old = table;
        table = new Node*[capacity];
        for(int i =0; i < capacity; i++) //initialize everything in the new table to nullptr
            table[i] = nullptr;
        for(int i=0; i<len;i++) { //now we need to readd everything to the new table
            Node *p, *q;

            p=old[i];
            while(p){
                put(p -> getValue());
                q = p -> getNext();
                delete p;
                p=q;
            }
        }
        readding = false;
        delete[] old;
    }
public:
    HashTable(){
        capacity = 100;
        table = new Node*[capacity];
        for(int i=0; i< capacity; i++){ //initialize table to nullptr
            table[i] = nullptr;
        }
        for(int i=0; i<10;i++) { //initialize histogram to 0
            histogram[i] = 0;
        }
        fullness =0;
        readding = false;
    }

    void put(string value){
        uint32_t key = SuperFastHash(value.c_str(),value.length()); //get a hash value for the string
        //int key = hashFunction(value);
        int count =0;
        if(fullness * 2 >= capacity && !readding) { //if the number of words is greater than 1/2 of the capacity, grow
            grow();
        }
        int hash = (key % capacity); //take the key and mod the capacity of the table
        if(table[hash] == nullptr){ //if that spot in the hash table is empty
            table[hash] = new Node(key, value);
            if(!readding){ //only does this if we aren't readding
              histogram[0]++;
              fullness++;
            }
        }
        else{ //if the spot in the hash table isn't empty
            Node* entry;
            entry = table[hash];
            while(entry->getNext() != nullptr){ //loop to the end of the linear chain at this spot
                count++;
                entry = entry->getNext();
            }
            if(!readding){ //check if we are in readding
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
        //int key = hashFunction(value);
        int hash = (key % capacity);
        if(table[hash] == nullptr) //automatically return false if there is nothing at this hash value
            return false;
        else{ //we need to check the linear chain
            Node *entry = table[hash];
            while(entry != nullptr && entry->getValue().compare(value)!=0)
                entry = entry->getNext();
            if(entry == nullptr) //return false if the word was not in this chain
                return false;
            else
                return true;
        }
    }

    //getter for the histogram array
    int* getHistogram(){
        return histogram;
    }
};

int main(){
    ifstream infile;
    HashTable a;

<<<<<<< HEAD
=======
    //read in the dictionary
>>>>>>> 2439aa9e6c169dfa4e01168bae4fd2828fea1d24
    infile.open("dict.txt");
    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    string s;
    while (infile >> s){
        a.put(s); //put everything into the hash table. This is where the majority of the work happens
    }
    infile.close();

    //read in the hw8 file
    infile.open("hw8.dat");
    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    //count how many lines in hw8 file
    int count =0;
    while(infile >> s){
        count++;
    }
    infile.close();


    infile.open("hw8.dat");
    string words[count];
    count =0;
    while(infile >> s){
        if (s.find("'") == string::npos) { //ignoring words with '
            for(int i=0; i<s.length();i++){
              s[i]=tolower(s[i]); //convert everything in every string to a lower case letter
            }
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

    int* histogram = new int[10];
    histogram = a.getHistogram();

    for(int i= 0; i<10;i++){
        cout << i << " " << histogram[i] <<endl;
    }

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
