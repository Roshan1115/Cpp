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

int int_size = 32;

class node{
  public:
  node* next[2];

  node(){
    next[0] = NULL;
    next[1] = NULL;
  }

};
node* trie;

void insert(int num) {
  node* it = trie;
  for(int i= int_size-1; i>=0; i--) {
    int cur_bit = (num >> i) & 1;
    if(it->next[cur_bit] == NULL)
      it->next[cur_bit] = new node();
    it = it->next[cur_bit];
  }
}


int querry(int num) {
  node* it = trie;
  int ans = 0;
  for(int i= int_size-1; i>=0; i--) {
    int curOppositeBit = ((num >> i) & 1) ? 0 : 1;
    if(it->next[curOppositeBit] != NULL) {
      // ans = ans | 1<<i;
      ans = ans << 1;
      ans = ans | 1;
      it = it->next[curOppositeBit];
    }
    else{
      ans = ans << 1;
      it = it->next[curOppositeBit ^ 1];
    }
  }
  return ans;
}

int main(){
  int n; cin >> n;
  vi a(n);
  for(auto &i: a)
    cin >> i;
  
  trie = new node();
  insert(0);

  vi Rmax(n+1, 0);
  int r = 0;
  for(int i=n-1; i>=0; i--) {
    r = r ^ a[i];
    if(i != n-1){
      Rmax[i] = max(Rmax[i+1], querry(r));
      insert(r);
    }
    else{
      Rmax[i] = querry(r);
      insert(r);
    }
  }
  free(trie);
  trie = new node();
  insert(0);

  int ans = 0;
  int l = 0;
  for(int i=0; i<n; i++) {
    l = l ^ a[i];
    ans = max(ans, Rmax[i+1] + querry(l));
    insert(l);
  }
  
  cout<< ans; endline;
  return 0;
}

// use : g++ -std=c++11 