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

int n,m,k;
vi a,b;
int dp[2005][2005][6];

int solve(int i, int j, int k)
{
  if(i==n || j==m)
    return 0;

  if(dp[i][j][k] != -1)
    return dp[i][j][k];

  int c1=0,c2=0,c3=0;

  if(a[i] == b[j])
    c1 = 1 + solve(i+1, j+1, k);
  
  if(k > 0)
    c2 = 1 + solve(i+1, j+1, k-1);
  
  c3 = max(solve(i+1, j, k), solve(i,j+1,k));

  return dp[i][j][k] = max({c1,c2,c3});
}

int main(){
  memset(dp,-1,sizeof(dp));
  cin >> n >> m >> k;
  a = vi(n);
  b = vi(m);
  for(int &i : a)
    cin >> i;
  for(int &i : b)
    cin >> i;

  cout<< solve(0,0,k); endline;
  return 0;
}

// use : g++ -std=c++11 

/*
input
5 5 1
1 2 3 4 5
5 3 1 4 2

output : 3
*/