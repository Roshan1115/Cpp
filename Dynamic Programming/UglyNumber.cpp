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

int main(){
  int n = 10;
  int c2 =0, c3=0, c5=0;

  vi dp(n+1);
  dp[0] = 1;

  rep(i,1,n+1){
    dp[i] = min(2*dp[c2], min(3*dp[c3], 5*dp[c5]));

    if(2*dp[c2] == dp[i]) c2++;
    if(3*dp[c3] == dp[i]) c3++;
    if(5*dp[c5] == dp[i]) c5++;
  }

  cout<< dp[n-1]; endline;
  return 0;
}

// use : g++ -std=c++11 