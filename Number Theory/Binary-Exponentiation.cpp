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

const int MOD = 1e9+7;

int power(int a, int n) {

  a = a % MOD;  // to bring down to a < MOD if a is greater

  int ans = 1;
  while(n>0){
    if(n & 1)
        ans = (ans * a) % MOD;
      a = (a * a) % MOD;
      n = n >> 1;
  }
  return ans;
}

int powerRecursive(int a, int n) {
  if(n == 0) return 1;

  int p = powerRecursive(a, n/2) % MOD;
  
  if(n & 1)   // if n is odd
  {   
    return ((p * p) % MOD) * a;
  }
  else  // if n is even
  {
    return (p * p) % MOD;
  }
}

int main(){
  int a, n; cin >> a >> n;
  cout<< power(a,n); endline;

  cout<< powerRecursive(a, n); endline;
  return 0;
}

// use : g++ -std=c++11 