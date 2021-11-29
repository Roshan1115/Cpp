/*
Given a prime number p and an integer n close to p/
find (n !) % p.
*/

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

int power(int x, int y, int p) {
  int res = 1;
  x = x % p;
  while(y > 0) {
    if(y & 1)
      res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

int modInverse(int a, int p){
  return power(a, p-2, p);
}

int modfact(int n, int p) {
  if( p<= n)
    return 0;

  int res = p-1;
  for(int i=n+1; i<p; i++) {
    res = (res * modInverse(i,p)) % p;
  }
  return res;
}

int32_t main(){
  int n,p; cin >> n >> p;

  cout<< modfact(n,p); endline;

}

// use : g++ -std=c++11 