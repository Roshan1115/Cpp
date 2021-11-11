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
  Trie* next[2];
  Trie(){
    next[0] = NULL;
    next[1] = NULL;
   }

};

Trie* buildTrie(vi &a) {
  Trie* root = new Trie();
  int s = a.size();

  for(int i=0; i<s; i++){
    int num = a[i];
    Trie* cur = root;

    for(int j=31; j>=0; j--) {
      int bit = (num >> j) & 1;
      if(cur->next[bit] == NULL) cur->next[bit] = new Trie();
      cur = cur->next[bit];
    }
  }
  return root;
}

int helper(Trie* root, vi &a) {
  int res = 0;
  int n= a.size();

  for(int i=0; i<n; i++) {
    int num = a[i];
    Trie* it = root;
    int cur_max = 0;

    for(int j=31; j>=0; j--) {
      int bit = ((num >> j) & 1) ? 0 : 1;
      if(it->next[bit] != NULL) {
        cur_max = cur_max << 1;
        cur_max = cur_max | 1;
        it = it->next[bit];
      }
      else{
        cur_max = cur_max << 1;
        it = it->next[bit ^ 1];
      }
    }
    res = max(res, cur_max);
  }
  return res;
}

int main(){
  vi a = {3,10,5,15,2};

  Trie* root = buildTrie(a);
  int ans = helper(root, a);

  cout<<ans; endline;
  return 0;
}

// use : g++ -std=c++11 