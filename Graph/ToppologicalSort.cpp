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
  cout<<"Topological.\n";
  int vertices, edges;
  cin >> vertices >> edges;
  vector<vector<int>> adj_list(vertices+1);
  vi indeg(vertices+1, 0);

  rep(i,0,edges){
    int u,v;
    cin >> u >> v;
    // u --> v
    adj_list[u].push_back(v);
    indeg[v]++;
  }

  queue<int> q;
  rep(i,1,vertices+1){
    if(indeg[i] == 0)
      q.push(i);
  }
  while(!q.empty()){
    int x = q.front();
    q.pop();
    cout<< x <<" ";

    for(int it : adj_list[x]){
      indeg[it]--;
      if(indeg[it] == 0)
        q.push(it);
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

output : 1 2 3 4 5 6 7 
*/

/*
                  1
                /   \            
              /       \
             2______   3
           / | \     \ |   
          4  5  6      7

*/