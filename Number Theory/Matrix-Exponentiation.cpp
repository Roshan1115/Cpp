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
#define int long long

vector<vi> multiply(vector<vi> &a, vector<vi> &b) {
  int n = a.size();
  vector<vi> ans(n, vi(n, 0));

  rep(i,0,n){
    rep(j,0,n){
      rep(k,0,n){
        ans[i][j] += a[i][k] * a[k][j];
      }
    }
  }
  return ans;
}

vector<vi> matrixEcponentiate(vector<vi> &a, int n) {
  if(n == 0) {
    int sz = a.size();
    vector<vi> ans(sz, vi(sz, 0));
    rep(i,0,sz){
      ans[i][i] = 1;
    }
    return ans;
  }
  if(n == 1){
    return a;
  }
  vector<vi> temp = matrixEcponentiate(a,n/2);
  vector<vi> ans = multiply(temp, temp);

  if(n & 1) {   // if n is odd
    ans = multiply(ans, a);
  }
  return ans;
}

int32_t main(){
  int n; cin >> n;

  vector<vi> a = {{1,1}, {1,0}};

  vector<vi> ans = matrixEcponentiate(a,n);

  int sz= ans.size();
  rep(i,0,sz) {
    rep(j,0,sz){
      cout<<ans[i][j]<<" ";
    }
    endline;
  }
}

// use : g++ -std=c++11 