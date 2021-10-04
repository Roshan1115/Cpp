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

  int n, m; cin >> n >> m;
  vector<vi> edge;
  rep(i,0,m){
    int w,u,v;
    cin >> w >> u >> v;
    edge.push_back({w,u,v});
  }

  // sort according to weight w
  sort(edge.begin(), edge.end());
  
  int cost = 0;
  for(auto i : edge){
    int w = i[0];
    int u = i[1];
    int v = i[2];
    int x = find_set(u);
    int y = find_set(v);
    if(x == y)
      continue;
    else{
      cout<< u <<" " << v << endl;
      cost += w;
      union_set(u,v);
    }
  }
  cout<< cost << endl;
  return 0;
}

// use : g++ -std=c++11 

/*
input 
8 9
1 2 5
2 3 6
4 3 2
1 4 9
3 5 5
5 6 10
6 7 7 
7 8 1
8 5 1

output
2 5
4 9
3 6
3 2
6 10
8 1
5 1
28
*/