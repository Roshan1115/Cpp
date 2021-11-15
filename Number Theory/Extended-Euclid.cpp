/*
ax + by = gcd(a,b)
gcd(d,0) = d

on solving
x = y1
y = x1 - (a/b) * y1
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
  if(b == 0) {
    triplet ans;
    ans.x = 1;
    ans.gcd = a;
    ans.y = 0;
    return ans;
  }

  triplet smallAns = extendedEuclid(b, a%b);
  triplet ans;
  ans.gcd = smallAns.gcd;
  ans.x = smallAns.y;
  ans.y = smallAns.x - (a/b)*smallAns.y;
  return ans;
}

int main(){
  int a,b;
  cin >> a >> b;

  triplet ans = extendedEuclid(a,b);
  cout<< ans.gcd<<" "<<ans.x<<" "<<ans.y; endline;
  return 0;
}

// use : g++ -std=c++11 