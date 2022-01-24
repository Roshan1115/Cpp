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
long a[N];

class group{
  public:
  long pref, suff, sum, ans;
  group(long pref, long suff, long sum, long ans){
    this->pref = pref;
    this->suff = suff;
    this->sum = sum;
    this->ans = ans;
  }
  group(){}
};
group tree[4*N];



void build(int node, int start, int end){
  if(start == end){
    if(a[start] <= 0){
      tree[node] = group(0,0,a[start],0);
    } 
    else{
      tree[node] = group(a[start],a[start],a[start],a[start]);
    }
    return;
  }

  int mid = (start+end)/2;
  build(2*node, start, mid);
  build(2*node+1, mid+1, end);

  long sum = tree[2*node].sum + tree[2*node+1].sum;
  long pref = max(tree[2*node].pref, tree[2*node].sum + tree[2*node+1].pref);
  long suff = max(tree[2*node+1].suff, tree[2*node+1].sum + tree[2*node].suff);
  long ans = max(tree[2*node].suff + tree[2*node+1].pref, max(tree[2*node].ans, tree[2*node+1].ans));

  tree[node] = group(pref, suff, sum, ans);
}


void update(int node, int start, int end, int idx, int val) {
  if(start == end){
    a[start] = val;
    if(a[start] <= 0){
      tree[node] = group(0,0,a[start],0);
    } 
    else{
      tree[node] = group(a[start],a[start],a[start],a[start]);
    }
    return;
  }
  int mid = (start+end)/2;
  
  if(idx <= mid) {
    update(2*node, start, mid, idx, val);
  }
  else{
    update(2*node+1, mid+1, end, idx, val);
  }

  long sum = tree[2*node].sum + tree[2*node+1].sum;
  long pref = max(tree[2*node].pref, tree[2*node].sum + tree[2*node+1].pref);
  long suff = max(tree[2*node+1].suff, tree[2*node+1].sum + tree[2*node].suff);
  long ans = max(tree[2*node].suff + tree[2*node+1].pref, max(tree[2*node].ans, tree[2*node+1].ans));

  tree[node] = group(pref, suff, sum, ans);
}


int main(){
  int n,m; cin >> n >> m;

  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  build(1,0,n-1);
  cout<< tree[1].ans<< endl;

  for(int i=0; i<m; i++){
    int idx; cin >> idx;
    long val; cin >> val;

    update(1,0,n-1,idx, val);

    cout<< tree[1].ans<<endl;
  }
  cout<<endl;
  return 0;
}

// use : g++ -std=c++11 

/*
5 2
5 -4 4 3 -5
4 3
3 -1

output : 
8
11
7
*/