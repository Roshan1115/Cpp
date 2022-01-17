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

const int N = 1e5 + 2;
int tree[4*N], a[N];

void build(int node, int start, int end){
  if(start == end){
    tree[node] = a[start];
    return;
  }
  int mid = (start+end)/2;
  build(2*node, start, mid);
  build(2*node +1, mid+1, end);

  tree[node] = max(tree[2*node], tree[2*node+1]);
  return;
}

int querry(int node, int st, int en, int l, int r) {
  if(st >r || en < l){
    return INT_MIN;
  }
  if(l <= st && en <= r){
    return tree[node];
  }
  int mid = (st+en)/2;
  int q1 = querry(2*node, st, mid, l, r);
  int q2 = querry(2*node+1, mid+1, en, l, r);

  return max(q1, q2);
}

void update(int node, int st, int en, int idx, int val) {
  if(st == en){
    a[st] = val;
    tree[node] = val;
    return;
  }
  int mid = (st+en)/2;
  
  if(idx <= mid) {
    update(2*node, st, mid, idx, val);
  }
  else{
    update(2*node+1, mid+1, en, idx, val);
  }
  tree[node] = max(tree[2*node], tree[2*node+1]);
}

int main(){
  int n; cin >> n;

  for(int i=0; i<n; i++)
    cin >> a[i];

  build(1,0,n-1);

  while(true){
    int type; cin>> type;
    if(type == -1)
      break;
    else if(type == 1){
      int l,r; cin >> l>> r;
      int ans = querry(1,0,n-1,l,r);
      cout<< ans<<endl;
    }
    else if(type == 2){
      int idx, val; cin >> idx >> val;
      update(1,0,n-1,idx,val);
      cout<< querry(1,0,n-1,0,n-1)<<endl;
    }
  }
  return 0;
}

// use : g++ -std=c++11 

/*
input
9
6 8 -1 2 17 1 3 2 4
1
2 6
2
7 18
-1

output
17
18
*/