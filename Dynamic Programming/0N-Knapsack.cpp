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



int knapsack(int *wt, int *val, int n, int w, int i) {
  if(w == 0 || i >= n){
    return 0;
  }

  if(wt[i] > w)
    return knapsack(wt, val, n, w, i+1);

  int picked = knapsack(wt, val, n, w-wt[i], i) + val[i];
  int notPicked = knapsack(wt, val, n, w, i+1);
  return max(picked, notPicked);

}


int knapsack_betterVersion(int *wt, int *val, int n, int w){
  vi dp(w+1, 0);

  rep(j,0,w+1){
    rep(i,0,n){
      if(j-wt[i] >= 0)
        dp[j] = max(dp[j], dp[j-wt[i]] + val[i]);
    }
  }
  return dp[w];
}

int main(){
  int n; cin >> n;
  int w; cin >> w;

  int wt[n], val[n];
  rep(i,0,n)
    cin >> wt[i];
  rep(i,0,n)
    cin >> val[i];

  cout<< knapsack(wt, val, n, w, 0); endline;

  cout<< knapsack_betterVersion(wt,val,n,w); endline;
  return 0;
}

// use : g++ -std=c++11 

/*
5 11
3 2 4 5 1
4 3 5 6 1


*/