// this algo is also used for MST

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

int n,m;
int N = 1e5 + 3;
vi dist(N), parent(N);
vector<bool> vis(N);
int cost = 0;

void primsMST(int src,  vector<vi> *g){
  const int INF = 1e9;
  rep(i,0,n){
    dist[i] = INF;
  }
  dist[src] = 0;
  set<pii> s;
  s.insert(make_pair(0,src));   // {wt,vertix}

  while(!s.empty()){
    pii x = *(s.begin());
    s.erase(x);
    vis[x.second] = true;
    int u = x.second;
    int v = parent[x.second];
    int w = x.first;
    cout<< u <<" " << v << " "<< w << endl;
    cost += w;
    for(auto it : g[x.second]){
      if(vis[it[0]])
        continue;
      if(dist[it[0]] > it[1]){
        s.erase({dist[it[0]], it[0]});
        dist[it[0]] = it[1];
        s.insert({dist[it[0]], it[0]});
        parent[it[0]] = x.second;
      }
    }
  }
}

int main(){
  vector<vi> g[N];
  cin >> n >> m;
  rep(i,0,m){
    int u,v,w; cin >> u >> v >> w;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
  }

  primsMST(0, g);
  cout<< cost << endl;
  return 0;
}

// use : g++ -std=c++11 

/*
input 
4 5
0 1 10
1 2 15
0 2 5
3 1 2
3 2 40

output
0 0 0
2 0 5
1 0 10
3 1 2
17
*/