// used to find the shortest distance from source vertix to last vertix

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
  vi dist(n+1, INF);
  vector<vii> graph(n+1);
  rep(i,0,m){
    int u,v,w;
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v,w));
    graph[v].push_back(make_pair(u,w));
  }
  int source; cin >> source;
  dist[source] = 0;
  set<pii> s;
  s.insert({0,source}); // {wt, vertix}
  while(!s.empty()){
    pii x = *(s.begin());
    s.erase(x);
    for(pii it : graph[x.second]){
      if(dist[it.first] > dist[x.second] + it.second){
        s.erase({dist[it.first], it.first});
        dist[it.first] = dist[x.second] + it.second;
        s.insert({dist[it.first], it.first});
      }
    }
  }
  rep(i,0,n+1){
    if(dist[i] < INF)
      cout<< dist[i]<<" ";
    else
      cout<< -1 <<" ";
  }

  return 0;
}

// use : g++ -std=c++11 

/*
inptut
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

output
-1 0 24 3 15
*/