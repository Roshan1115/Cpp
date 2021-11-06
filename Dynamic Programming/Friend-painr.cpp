#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>
#include<limits>
using namespace std;

#define endline cout<<endl
#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)

int friendPair(int n, vi &dp){
  if(n == 1) return dp[n];
  if(n == 0) return dp[n];

  if(dp[n] != -1) return dp[n];

  dp[n] = friendPair(n-1, dp) + friendPair(n-2, dp) * (n-1);
  return dp[n];
}

int main(){
  int n; cin >> n;
  vi dp(n+1, -1);
  dp[0] = 1;
  dp[1] = 1;

  cout<< friendPair(n, dp); endline;
  return 0;
}

// use : g++ -std=c++11 