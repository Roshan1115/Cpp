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

const int N = 1e5;
vector<bool> visited(N, false);
vector< vi > adj(N);


void DFS(int node){

  // preorder
  visited[node] = true;
  cout<< node <<" ";

  //inorder
  vi :: iterator it;
  for(it = adj[node].begin(); it != adj[node].end(); it++)
  {
    if(visited[*it]) ;  // do nothing
    
    else{
      DFS(*it);
    }
  }

  // postorder
}

int main(){
  int node, edge;
  cin >> node >> edge;

  rep(i,0,edge){
    int x,y;
    cin >> x >> y;

    // since it is undirected edge (two way edge)
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  DFS(1);
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

output : 1 2 4 5 6 7 3
*/

/*
                  1
                /   \            
              /       \
             2______   3
           / | \     \ |   
          4  5  6      7

*/