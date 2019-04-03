/*Nicholas DiMaria
  I pledge my honor that I have abided by the Stevens Honor System

  Citations:
  --Check if a word is contained in another: https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
  --Convert string to lower case: https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

class Trie {
private:
  class Node {
  public:
    Node* next[26];
    bool isWord;
    Node(){
      for(int i=0;i <26; i++)
        next[i]=nullptr;
      isWord =false;
    }
  };
  void deleteNode(Node* p){
    for(int i =0; i<26;i++){
      if(p->next[i]!=nullptr)
        deleteNode(p->next[i]);
    }
  }
  Node* root;
public:
  Trie() {
    root = new Node();
  }
  ~Trie(){
    Node* p = root;
    for(int i=0; i<26;i++){
      if(p->next[i] != nullptr)
        deleteNode(p->next[i]);
    }
  }
  void insert(string word){ //O(k) where k is the length of the word
    Node* p = root;
    for (int i =0; i<word.length(); i++){
      if (p -> next[word[i]-'a'] == nullptr){
        p -> next[word[i]-'a'] = new Node();
      }
      p = p -> next[word[i]-'a'];
      p->isWord = true;
    }
  }

  bool contains(string word) {
    Node* p = root;
    for (int i = 0; i<word.length();i++){
      if (p->next[word[i]-'a'] == nullptr)
        return false;
      p=p->next[word[i]-'a'];
    }
    return p->isWord;
  }

  bool containsPrefix(string word){
    Node* p = root;
    for (int i = 0; i<word.length();i++){
      if (p->next[word[i]-'a'] == nullptr)
        return false;
      p=p->next[word[i]-'a'];
    }
    return true;
  }
};

int main(){
  ifstream infile;
  Trie dictionary;

  infile.open("dict.txt");
  if (!infile) {
      cout << "Unable to open file";
      exit(1); // terminate with error
  }

  string s;
  while (infile >> s){
    dictionary.insert(s);
  }
  infile.close();

  infile.open("hw5.txt");
  if (!infile) {
      cout << "Unable to open file";
      exit(1); // terminate with error
  }

  int count =0;
  while(infile >> s){
    count++;
  }
  infile.close();

  infile.open("hw5.txt");
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
    if(dictionary.contains(words[i])){
      cout << "true" << endl;
    }
    else
      cout << "false" << endl;
  }
}
