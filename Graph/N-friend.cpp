/*
 you are given n friends from 0 to n-1. You are supposed to choose two friends which do not have any relation at all. You are given M pairs (x,y) Such that There is a link between x and y. find out the number of ways such that two persons from different groups can be chosen
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



int componentSize(int src, vector<vi> &adj, vector<bool> &vis){
  if(vis[src]) return 0;

  vis[src] = 1;
  int cnt = 1;

  for(int child : adj[src]){
    if(!vis[child])
      cnt += componentSize(child,adj,vis);
  }
  return cnt;
}

vector<int> get_components(int n, vector<vi> &adj, vector<bool> &vis){
  vector<int> components;
  rep(i,0,n){
    if(!vis[i]){
      components.push_back(componentSize(i,adj,vis));
    }
  }
  return components;
}

int main(){
  int n,m; cin >> n >> m;
  vector<vi> adj_list(n);
  vector<bool> visited(n, 0);

  rep(i,0,m)
  {
    int x,y;
    cin >> x >> y;
    adj_list[x].push_back(y);
    adj_list[y].push_back(x);
  }

  // this will have components with their size
  vector<int> components = get_components(n,adj_list, visited);

  int ans = 0;
  for(int i : components)
    // permutation combination
    ans += i * (n-i);

  // to avoud repeatation like 2 3 and 3 2
  cout<< ans/2 << endl;
  return 0;
}

// use : g++ -std=c++11 

/*
input 
5 3
0 1
2 3
0 4

output : 6
*/