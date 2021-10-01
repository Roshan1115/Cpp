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

vector<vi> adj;
vector<bool> vis;
vector<int> colr;
bool bipart = true;

void color(int u, int curr)
{
  if(colr[u] != -1 && colr[u] != curr){
    bipart = false;
    return;
  }
  colr[u] = curr;
  if(vis[u])
    return;
  vis[u] = true;
  for(auto i : adj[u])
    color(i, curr ^ 1); // xor operator for alternating 0 and 1

    // 0 ^ 1 = 1
    // 1 ^ 1 = 0
}

int main(){
  int node,edges; cin>> node >> edges;
  adj = vector<vi>(node);
  vis = vector<bool>(node, false);
  colr = vector<int>(node, -1);

  for(int i=0; i<edges; i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i=0; i<node; i++){
    if(!vis[i])
      color(i,0);
  }
  if(bipart)
    cout<< "Graph is bipart.\n";
  else
    cout << "Graph is not bipart.\n";

  
  return 0;
}

// use : g++ -std=c++11 

/*
input : 
3 3
0 1
1 2
2 0

output : Graph is not bipart.

input :
4 4
0 1
1 2
2 3
3 0

output : Graph is bipart.
*/