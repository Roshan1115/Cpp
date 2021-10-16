/*
given a set of coin and int v. find number of ways to make change of v.
*/

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

const int N = 1e3+2;
int dp[N][N];

int CoinChange(vi &a, int n, int x)
{
  if( x== 0) return 1;
  if( x<0 ) return 0;
  if(n <=0 ) return 0;

  if(dp[n][x] != -1)
    return dp[n][x];

  return dp[n][x] = CoinChange(a, n, x-a[n-1]) + CoinChange(a, n-1, x);
}


int CoinChangeTebulation(vi &a, int n, int x) {
  vector<vi> dp(n+1, vi(x+1, 0));
  dp[0][0] = 1;

  rep(i,0,n+1){
    rep(j,0,x+1){
      if(j-a[i-1] >= 0)
        dp[i][j] += dp[i][j-a[i-1]];
      dp[i][j] += dp[i-1][j];
    }
  }
  return dp[n][x];
}

int main(){
  rep(i,0,N){
    rep(j,0,N)
      dp[i][j] = -1;
  }

  int n;
  cin >> n;

  vi a(n);

  rep(i,0,n){
    cin >> a[i];
  }

  int x; cin >> x;

  cout<<"Hello.\n";

  cout<< CoinChange(a,n,x) << endl;   // memorization technique

  // cout << CoinChangeTebulation(a,n,x) << endl;    // tabulation
  return 0;
}

// use : g++ -std=c++11 

/*
input 
3
1 2 3
6

output : 7
*/