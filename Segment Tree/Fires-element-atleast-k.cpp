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

void build(int node, int start, int end){
  if(start == end){
    tree[node] = a[start];  return;
  }
  int mid = (start+end)/2;
  build(2*node, start, mid);
  build(2*node+1, mid+1, end);

  tree[node] = max(tree[2*node], tree[2*node+1]);
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

int main(){
  int n,m; cin >> n >> m;

  for(int i=0; i<n; i++)  cin >> a[i];

  build(1,0,n-1);
  cout<<endl;

  while(m--){
    int type; cin >> type;
    if(type==1){
      int idx,val; cin >> idx >> val;
      update(1,0,n-1,idx,val);
    }
    else{
      //binary search
      int x; cin >> x;
      int low=0,high=n-1;
      int ans = n;
      while(low<=high){
        int mid = (low+high)/2;
        if(querry(1,0,n-1,low,mid) < x)
          low = mid+1;
        else{
          high = mid-1;
          ans = min(ans, mid); 
        }
      }
      if(ans == n) ans = -1;
      cout<<ans<<endl;
    }
  }
  return 0;
}

// use : g++ -std=c++11 

/*
input
5 7
1 3 2 4 6
2 2
2 5
1 2 5
2 4
2 8
1 3 7
2 6

output
1
4
2
-1
3
*/