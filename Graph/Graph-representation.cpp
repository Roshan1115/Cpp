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

int main(){
  // n = number of node, m = number of edges
  int n, m;
  cin >> n >> m;

  // 2D vector, matrix refers to adjencesy matrix
  vector< vi> matrix(n+1, vi(n+1, 0));

  // 2D matrix for adjencensy list
  vector< vi > list(n+1);

  rep(i,0,m){

    // this will be undirected edge
    int x, y;
    cin >> x >> y;

    matrix[x][y] = 1;
    matrix[y][x] = 1;

    // for list
    list[x].push_back(y);
    list[y].push_back(x);
  }

  cout << "adjencensy matrix of graph : \n";
  rep(i,1,n){
    rep(j,1,n){
      cout<< matrix[i][j]<<" ";
    }cout<< endl;
  }

  // to know if there is a edge from x to y
  if(matrix[3][7]){
    cout<< "There is an edge from 3 to 7.\n";
  }
  

  // adjencensy list display
  cout<<"\nAdjencensy list of the graph \n";
  rep(i,1,n+1){
    cout<< i <<" -> ";
    for(int x : list[i])
      cout<< x <<" ";
    cout<< endl;
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