/*
Given n matrices, find the minimum operations to multiply them
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

const int N = 102, MOD= 1e9+7;
int dimentions[N];
vector<vi> dp(N, vi(N, -1));

int MinOperationMultiply(int i, int j) {
  if(i==j) return 0;

  if(dp[i][j] != -1)
    return dp[i][j];
  
  dp[i][j] = MOD;

  for(int k=i; k<=j; k++) {
    dp[i][j] = min(dp[i][j], MinOperationMultiply(i,k)+MinOperationMultiply(k+1,j)+ dimentions[i-1]* dimentions[k]* dimentions[j] );
  }
  return dp[i][j];
}

int mcmTable(int n, int *a) {
  vector<vi> dp(n, vi(n, -1));
  rep(i,1,n){
    dp[i][i] = 0;
  }
  for(int l=2; l<n; l++) {
    for(int i=1; i<n-l+1; i++) {
      int j= i+l-1;
      dp[i][j] = MOD;
      for(int k=i; k<j; k++) {
        dp[i][j] = min( dp[i][j], dp[i][k] + dp[k+1][j] + a[i-1]*a[k]*a[j] );
      }
    }
  }
  return dp[1][n-1];
}

int main(){
  int n; cin >> n;
  rep(i,0,n)
    cin  >> dimentions[i];

  cout<< MinOperationMultiply(1,n-1) << endl;

  cout << mcmTable(n, dimentions) << endl;
  return 0;
}

// use : g++ -std=c++11 

/*
input 
5
10 20 30 20 30

output : 18000
*/