/*
(a * b) % m = 1
given us a and m, we find the b, here b is called multiplicative modulo inverse. To exist b, the a and m shoud be co-prime i.e gcd(a,m) should be 1.

after solving
ab + mq = 1
find b
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

struct triplet{
  int x,y,gcd;
};


triplet extendedEuclid(int a, int b) {
  if(b == 0){
    triplet ans;
    ans.x = 1;
    ans.gcd = a;
    ans.y = 0;
    return ans;
  }
  triplet smallAns = extendedEuclid(b, a%b);
  triplet ans;
  ans.x = smallAns.y;
  ans.gcd = smallAns.gcd;
  ans.y = smallAns.x - (a/b) * smallAns.y;
  return ans;
}


int MMI(int a, int m){
  return extendedEuclid(a, m).x;
}

int main(){
  int a, m; cin >> a >> m;

  cout<< MMI(a, m); endline;

  return 0;
}

// use : g++ -std=c++11 