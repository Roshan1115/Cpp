/*
trie is also a data structure
*/

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>
#include<limits>
using namespace std;

#define endline cout<<endl
#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)

class Trie{
public:
  class node{
  public:
    bool end;
    node* next[26];
    (){
      end = false;
      for(int i=0; i<26; i++)
        next[i] = NULL;
    }
  };

  node* trie;
  Trie(){node
    trie = new node();
  }

  void insert(string word){
    int i=0;
    node* it = trie;
    int n = word.size();
    while(i < n){
      if(it->next[word[i] - 'a'] == NULL)
        it->next[word[i] - 'a'] = new node();
      it = it->next[word[i] - 'a'];
      i++;
    }
    it->end = true;
  }

  bool search(string word){
    int i=0;
    node * it = trie;
    int n = word.size();
    while(i < n){
      if(it->next[word[i]-'a'] == NULL)
        return false;
      it = it->next[word[i]-'a'];
      i++;
    }
    return it->end;
  }
};

int main(){
  Trie * myTrie = new Trie();
  string s1 = "roshan";
  string s2 = "akash";
  myTrie->insert(s1);
  myTrie->insert(s2);

  if(myTrie->search("madhav"))
    cout<<"Madhav exist.\n";
  else cout<<"Madhav is not there.\n";

  if(myTrie->search("roshan"))
    cout<<"roshan exist.\n";
  else cout<<"roshan is not there.\n";

  return 0;
}

// use : g++ -std=c++11 