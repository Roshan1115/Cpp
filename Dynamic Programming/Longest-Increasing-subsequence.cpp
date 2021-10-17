/*
you are given an array, find the length of longest increasing subsequence.
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

const int N= 1e5+2, MOD = 1e9;
vi dp(N, -1);


// memorization technique
int lis(vi &a, int n){
  if(n < 0) return 0;
  if(n == 0) return 1;

  if(dp[n] != -1)
    return dp[n];
  
  dp[n] = 1;   // single element is also a lis
  rep(i,0,n){
    if(a[i] < a[n]) {
      dp[n] = max(dp[n], lis(a,i) + 1);
    }
  }
  return dp[n];
}


// tabulation technique
int lisTable(vi &a, int n){
  vi dp(n, 1);
  int ans = 0;

  rep(i,0,n){
    rep(j,0,i){
      if(a[i] > a[j]){
        dp[i] = max(dp[i], 1+dp[j]);
      }
    }
    ans = max(ans, dp[i]);
  }

  return ans;
}

int main(){
  int n; cin >> n;
  vi a(n);

  rep(i,0,n)
    cin >> a[i];

  cout<< lis(a, n-1) << endl;

  cout<< lisTable(a, n)<< endl;
  return 0;
}

// use : g++ -std=c++11 

/*
input
5
1 4 2 5 3

output : 
3
3
*/