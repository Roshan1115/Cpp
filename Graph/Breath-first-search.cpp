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

  queue<int> q;
  q.push(1);
  visited[1] = true;

  while(!q.empty()){
    int curNode = q.front();
    q.pop();
    cout<< curNode <<" ";

    vi :: iterator it;
    for(it = adj[curNode].begin(); it != adj[curNode].end(); it++)
    {
      if(!visited[*it]){
        visited[*it] = 1;
        q.push(*it);
      }
    }
  }
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
