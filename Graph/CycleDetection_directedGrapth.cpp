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



bool isCycle(int src, vector<vi> &adj, vector<bool> &visited, vector<int> &stackk)
{
  stackk[src] = 1;

  if(!visited[src]){
    visited[src] = true;
    for(auto i : adj[src]){
      if(!visited[i] && isCycle(i,adj,visited,stackk)){
        return true;
      }
      if(stackk[i]){
        return true;
      }
    }
  }

  stackk[src] = 0;
  return true;
}

int main(){
  cout<<"Cycle Detection Directed Graph.\n";
  int vertices, edges;
  cin >> vertices >> edges;
  vector<vector<int>> adj_list(vertices+1);

  rep(i,0,edges){
    int u,v;
    cin >> u >> v;
    // u --> v
    adj_list[u].push_back(v);
  }
  bool cycle = false;
  vector<bool> visited(vertices+1, 0);
  vector<int> stackk(vertices+1,0);

  rep(i,1,vertices+1){
    if(!visited[i] && isCycle(i,adj_list,visited,stackk)){
      cycle = true;
      break;
    }
  }

  if(cycle) cout<<"There is a cycle.\n";
  else cout<< "There is no cycle.\n";
  return 0;
}

// use : g++ -std=c++11 

/*
input 
7 7
1 2
2 4
2 5
2 6
2 7
7 3
3 1

*/

/*
  directed toward downward onle 7 --> 3  and 3 --> 7 upward

                  1
                /   \            
              /       \
             2______   3
           / | \     \ |   
          4  5  6      7

*/