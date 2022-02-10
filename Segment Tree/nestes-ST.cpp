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


struct triplet{
  int l,r,idx;
};

bool compare(triplet t1, triplet t2){
  return t1.r < t2.r;
}


const int N = 1e7+2;
int tree[4*N];



// l to r is the range
int querry(int node, int start, int end, int l, int r) {
  if(start > r || end < l) {
    return 0;
  }
  else if(start >= l && end <= r) {
    return tree[node];
  }
  
  int mid = (start + end)/2;

  int q1 = querry(2*node, start, mid, l, r);
  int q2 = querry(2*node+1, mid+1, end, l,r);

  return q1 + q2;
}

// Update
void update(int node, int st, int en, int idx, int val) {
  if(st == en){
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
  tree[node] = tree[2*node] + tree[2*node+1];
}



int main(){
  int n; cin >>n;
  triplet t1;
  t1.l=t1.r=-1;

  vector<triplet> t(n, t1);
  int x;

  for(int i=0; i<2*n; i++){
    cin >> x;
    if(t[x-1].l == -1){
      t[x-1].l =  i;
    }
    else{
      t[x-1].r = i;
    }
    t[x-1].idx = x;
  }
  
  sort(t.begin(), t.end(), compare);

  vector<int> ans(n);

  for(int i=0; i<n; i++){
    ans[t[i].idx-1] = querry(1,0,2*n-1,t[i].l,t[i].r);
    update(1,0,2*n-1,t[i].l, 1);
  }

  for(auto a : ans)
    cout<<a<<" ";
  endline;
  return 0;
}

// use : g++ -std=c++11 

/*
5
5 1 2 2 3 1 3 4 5 4
*/