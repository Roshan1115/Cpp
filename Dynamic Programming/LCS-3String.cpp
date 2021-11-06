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

int dp[205][205][205];

int lcs(string &s1, string &s2, string &s3, int m, int n, int o) {

  if(m==0 || n==0 || o==0) return 0;

  if(dp[m][n][o] != -1) return dp[m][n][o];

  if(s1[m-1] == s2[n-1] && s2[n-1] == s3[o-1])
    return dp[m][n][o] = 1+ lcs(s1,s2,s3, m-1, n-1, o-1);
  
  else{
    int i = lcs(s1,s2,s3, m-1,n,o);
    int j = lcs(s1,s2,s3, m, n-1, o);
    int k = lcs(s1,s2,s3, m, n, o-1);

    return dp[m][n][o] = max({i,j,k});
  }
}

int main(){
  memset(dp,-1,sizeof(dp));
  string s1 = "apna";
  string s2 = "collageap";
  string s3 = "annap";

  cout<< lcs(s1,s2,s3,s1.size(), s2.size(), s3.size());endline;
  return 0;
}

// use : g++ -std=c++11 