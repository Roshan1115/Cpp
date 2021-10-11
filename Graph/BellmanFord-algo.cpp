// from a source vertix, find the shortest distance for all the other nodes in graph

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)

const int INF = 1e9;
int main(){
  int n,m; cin >> n >> m;
  vector<vector<int>> edge;
  rep(i,0,m){
    int u,v,w;
    cin >> u >> v >> w;
    edge.push_back({u,v,w});
  }
  int src; cin >> src;
  vi dist(n, INF);
  dist[src] = 0;

  rep(iter,0,n-1){
    for(vi e : edge){
      int u = e[0];
      int v = e[1];
      int w = e[2];
      dist[v] = min(dist[v], w+dist[u]);
    }
  }
  for(auto i : dist){
    cout<< i <<" ";
  }cout<< endl;
  return 0;
}

// use : g++ -std=c++11 

/*
input
5 8
1 2 3
3 2 5
1 3 2
3 1 1
1 4 2
0 2 4
4 3 -3
0 1 -1
0

output : 0 -1 2 -2 1 
*/