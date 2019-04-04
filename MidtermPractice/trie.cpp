#include <iostream>
#include <string.h>

using namespace std;

class Trie{
private:
  class Node{
  public:
    Node* next[26];
    bool isWord;
    Node(){
      for(int i =0; i < 26;i++)
        next[i]==nullptr;
      isWord=false;
    }
  };
  Node* head;
public:
  void insert(string word){
    Node* temp = head;
    for(int i =0; i < word.length(); i++){
      int index = word[i]-'a';
      if(temp->next[index]==nullptr)
        temp ->next[index] = new Node();
      temp = temp -> next[index];
    }
    temp -> isWord = true;
  }
  bool containsPrefix(string word){
    Node* temp = head;
    for(int i =0; i < word.length(); i++){
      int index = word[i]-'a';
      if(temp->next[index]==nullptr)
        return false;
      temp = temp -> next[index];
    }
    return true;
  }

  bool containsWord(string word){
    Node* temp = head;
    for(int i =0; i < word.length(); i++){
      int index = word[i]-'a';
      if(temp->next[index]==nullptr)
        return false;
      temp = temp -> next[index];
    }
    return temp->isWord;
  }
};

int main(){
  Trie a;

  a.insert("bob");
  cout << a.containsWord("bo");
}
