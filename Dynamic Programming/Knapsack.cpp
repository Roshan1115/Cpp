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

const int N= 1e3+2, MOD=1e9;
int wt[N], val[N];
vector<vi> dp(N, vi(N, -1));

int knapsack(int n, int w)
{
  if(w <= 0 || n<= 0) return 0;

  if(dp[n][w] != -1)
    return dp[n][w];

  if(wt[n-1] > w)
    dp[n][w] =  knapsack(n-1, w);

  else
  dp[n][w] = max( knapsack(n-1,w), knapsack(n-1,w-wt[n-1]) + val[n-1] );

  return dp[n][w];
}

int main(){

  int n; cin >> n;

  rep(i,0,n)
    cin >> wt[i];
  
  rep(i,0,n)
    cin >> val[i];
  
  int w; cin >> w;

  cout<< knapsack(n,w) << endl;
  return 0;
}

// use : g++ -std=c++11 

/*
input
3
15 30 45
60 100 150
50

output : 160
*/