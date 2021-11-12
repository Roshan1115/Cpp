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
  private:

  class node{
  public:
  node* next[26];
  bool end;

  node(){
    rep(i,0,26){
      next[i] = NULL;
    }
    end = false;
    }
  };

  node* root;

  public:
  Trie(){
    root = new node();
  }

  void insert(string s) {
    int size = s.size();
    node* it = root;

    rep(i,0,size){
      if(it->next[s[i]-'a'] == NULL)
        it->next[s[i]-'a'] = new node();
      it = it->next[s[i]-'a'];
    }
    it->end = true;
  }

  void find(string s) {
    int size = s.size();
    node* it = root;
    string res = "";

    rep(i,0,size){
      if(it->next[s[i]-'a'] != NULL){
        it = it->next[s[i]-'a'];
        res = res + s[i];
        if(it->end)
          cout<< res << endl;
      }
      else{
        this->insert(s);
        return;
      }
    }
    for(int i=0; i<26; i++){
      if(it->next[i] != NULL){
        char ch = 'a' + i;
        this->find(s + ch);
      }
    }
    return;
  }
};

int main(){
  Trie* t = new Trie();
  t->insert("roshan");
  t->insert("manish");
  t->insert("akash");
  t->insert("roshu");
  t->insert("roabcd");

  t->find("ro");
  t->find("bittu");
  t->find("bit");
  return 0;
}

// use : g++ -std=c++11 