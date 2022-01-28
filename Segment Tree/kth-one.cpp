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

const int N = 1e5+2;
int a[N], tree[4*N];

void build(int node, int st, int en) {
  if(st== en){
    tree[node] = a[st];
    return;
  }
  int mid = (st+en)/2;
  build(2*node,st,mid);
  build(2*node+1,mid+1,en);

  tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int node,int st,int en, int idx) {
  if(st==en){
    if(a[st] == 0){
      tree[node] = 1;
      a[node] = 1;
    } 
    else {
      tree[node] = 0;
      a[node] = 0;
    } 
    return;
  }

  int mid = (st+en)/2;
  if(idx <= mid)
    update(2*node, st, mid, idx);
  else
    update(2*node+1, mid+1, en, idx);

  tree[node] = tree[2*node] + tree[2*node+1];
}

int querry(int node,int st,int en,int k){
  if(st == en) return st;

  int mid = (st+en)/2;
  if(k < tree[2*node])
    return querry(2*node,st,mid,k);
  else
    return querry(2*node+1,mid+1,en,k-tree[2*node]);
}

int main(){
  int n,m;
  cin >> n >> m;

  for(int i=0;i<n; i++) 
    cin >>a[i];

  build(1,0,n-1);
  cout<<endl;

  for(int i=0; i<m; i++ ){
    int type; cin >> type;
    if(type == 1){
      int idx; cin >> idx;
      update(1,0,n-1,idx);
    }
    else{
      int k; cin >> k;
      int ans = querry(1,0,n-1,k);
      cout<<ans<<endl;
    }
  }
  return 0;
}

// use : g++ -std=c++11 

/*
input: 
5 7
1 1 0 1 0
2 0
2 1
2 2
1 2
2 3
1 0
2 0

*/