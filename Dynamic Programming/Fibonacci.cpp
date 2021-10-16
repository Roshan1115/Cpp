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

const int N = 1e5+2;
int dp[N];

int fib(int n)
{
  if (n == 0) return 0;
  if(n == 1) return 0;
  if(n == 2) return 1;

  if(dp[n] != -1){
    return dp[n];
  }

  ;

  return ( dp[n] = fib(n-1) + fib(n-2) );
}

int main(){
  int n;
  cin >> n;
  
  vi dp(n+1);
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 1;

  // cout<< fib(n) << endl;   // top-bottom approach

  for(int i=3; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2];    // button-up approach
  }

  cout<< dp[n] << endl;
  return 0;
}

// use : g++ -std=c++11 