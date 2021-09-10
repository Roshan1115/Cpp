/*
you are given n files with their computation time in an array.
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

int main(){
  int n; cin >> n;

  //min heap
  priority_queue<int, vi, greater<int>> pq;

  rep(i,0,n){
    int input; cin >> input;
    pq.push(input);
  }

  int ans = 0;
  while( pq.size() > 1){
    int e1 = pq.top();
    pq.pop();
    int e2 = pq.top();
    pq.pop();

    int cost = e1 + e2;
    ans += cost;
    pq.push(cost);
  }

  cout<< ans << endl;
  return 0;
}

// use : g++ -std=c++11 

/*
input
4
5 2 4 7

output : 35
*/