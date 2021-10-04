// this problem is based using DSU

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)

int N = 1e5+6;
vector<int> parent(N);
vector<int> sz(N);

void make_set(int v){
  parent[v] = v;
  sz[v] = 1;
}

int find_set(int v){
  if(v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]); // path compression
}

void union_set(int a, int b){
  a = find_set(a);
  b = find_set(b);
  if(a != b){
    if(sz[a] < sz[b])
      swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
  }
}

int main(){
  for(int i=0; i<N; i++){
    make_set(i);
  }

  int n,m; cin >> n >> m;
  vector<vector<int>> edges;
  rep(i,0,m){
    int u,v; cin >> u >> v;
    edges.push_back({u,v});
  }
  bool cycle = false;
  for(auto i : edges){
    int u = i[0];
    int v = i[1];
    int x = find_set(u);
    int y = find_set(v);
    if(x == y)
      cycle = true;
    else
      union_set(u,v);
  }
  if(cycle)
    cout<< "Cycle found.\n";
  else 
    cout<< "Cycle not found.\n";
  return 0;
}

// use : g++ -std=c++11 

/*
input
4 4
0 1
1 2
2 3
3 0

output : Cycle found.



input 
4 2
0 1
2 3

output : Cycle not found.
*/