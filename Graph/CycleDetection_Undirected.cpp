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




bool isCycle(int src, vector< vi> &adj, vector<bool> &visited, int parent){
  visited[src] = true;
  for(int i : adj[src]){
    if(i != parent){
      if(visited[i])
        return true;

      if(isCycle(i,adj,visited,src)){
        return true;
      }
    }

  }
  return false;
}

int main(){
  int node, edge;
  cin >> node >> edge;
  vector< vi > adj(node+1);

  rep(i,0,edge){
    int x,y;
    cin >> x >> y;

    // x --> y and y --> x
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  bool cycle = false;
  vector<bool> visited(node+1, false);

  cycle = isCycle(1,adj,visited,-1);

  if(cycle) cout<<"There is a cycle.\n";
  else cout<<"There is no cycle.\n";
  return 0;
}

// use : g++ -std=c++11 

/*
input 
7 7
1 2
1 3
2 4
2 5
2 6
3 7
2 7


*/

/*
                  1
                /   \            
              /       \
             2______   3
           / | \     \ |   
          4  5  6      7

*/