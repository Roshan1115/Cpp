// for every pair of vertices {u,v}, it gives the shortest path

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
  vector<vi> graph = {
                        {0,5,INF,10},
                        {INF,0,3,INF},
                        {INF,INF,0,1},
                        {INF,INF,INF,0}
                      };
  int n = graph.size();
  vector<vi> dist = graph;
  rep(k,0,n){
    rep(i,0,n){
      rep(j,0,n){
        if(dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
  rep(i,0,n){
    rep(j,0,n){
      if(dist[i][j] == INF)
        cout<< "INF ";
      else
        cout<< dist[i][j]<<" ";
    }cout<< endl;
  }
  return 0;
}

// use : g++ -std=c++11 