/*
find the number of connected component and its size in a undircted graph
*/

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


int get_component(int src, vector<vi> &adj, vector<bool> &vis){
  if(vis[src]) return 0;

  vis[src] = true;
  int cnt = 1;
  for(int i : adj[src]){
    if(!vis[i])
      cnt += get_component(i,adj,vis);
  }
  return cnt;
}

int main(){
  int node, edge;
  cin >> node >> edge;

  auto adj = vector< vi >(node);
  auto visited = vector<bool> (node, 0);
  auto component = vector<int>();

  rep(i,0,edge){
    int x,y;
    cin >> x >> y;

    // x --> y and y --> x
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  rep(i,0,node){
    if(!visited[i]){
      component.push_back(get_component(i, adj, visited));
    }
  }

  for(auto i : component)
    cout<< i<< " ";
  cout<< endl;
  return 0;
}

// use : g++ -std=c++11 

/*
input 
5 3
0 1
2 3
0 4

output : 3 2
*/
