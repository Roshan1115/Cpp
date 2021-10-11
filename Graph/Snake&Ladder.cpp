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

int main(){
  int ladders, snakes;
  cin >> ladders;
  map<int, int> lad;
  map<int, int> snak;
  rep(i,0,ladders){
    int u,v; cin >> u >> v;
    lad[u] = v;
  }
  cin >> snakes;
  rep(i,0,snakes){
    int u,v; cin >> u >> v;
    snak[u] = v;
  }
  int moves = 0;
  queue<int> q;
  q.push(1);
  bool found = false;
  vi vis(101,0);
  vis[1] = true;

  while(!q.empty() && !found){
    int sz = q.size();
    while(sz--){
      int t = q.front();
      q.pop();
      rep(die,1,7){
        if(t+die == 100)
          found = true;

        if(t+die <= 100 && lad[t+die] && !vis[lad[t+die]]) {
          vis[lad[t+die]] = true;
          if(lad[t+die] == 100)
            found = true;
          q.push(lad[t+die]);
        }

        else if(t+die <=100 && snak[t+die] && !vis[snak[t+die]]) {
          vis[snak[t+die]] = true;
          if(snak[t+die] == 100)
            found = true;
          q.push(snak[t+die]);
        }

        else if(t+die <=100 && !vis[t+die] && !snak[t+die] && !lad[t+die]) {
          vis[t+die] = true;
          q.push(t+die);
        }
      }
    }
    moves++;
  }

  if(found)
    cout<< moves << endl;
  else  
    cout<< "-1" << endl;

  return 0;
}

// use : g++ -std=c++11 

/*
input
2
3 90
56 76
3
99 10
30 20
20 5

output : 3
*/