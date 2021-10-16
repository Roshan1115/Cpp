// minimum squares whose sum equals to given number n.

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

int MOD = 1e9+7;
const int N = 1e5+2;
int dp[N];

int MinSquare(int n) {
  if(n>=0 && n<=3){
    return n;
  }
  if(dp[n] != MOD)
    return dp[n];

  for(int i=1; i*i<=n; i++) {
    dp[n] = min(dp[n], 1 + MinSquare(n-i*i));
  }
  return dp[n];
}

int main(){
  int n; cin >> n;

  rep(i,0,N){
    dp[i] = MOD;
  }

  cout << MinSquare(n) << endl;
  return 0;
}

// use : g++ -std=c++11 