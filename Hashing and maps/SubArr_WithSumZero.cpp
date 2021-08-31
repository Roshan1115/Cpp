/*
given an array of integer, return the number of subarray whose sum is zero
*/

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define rep(i,a,b) for(int i=a; i<b; i++)

int main(){
  int n; cin >> n;
  vi a(n);
  rep(i,0,n)
    cin>> a[i];

  map<int, int> count;

  int prefSum = 0;
  rep(i,0,n){
    prefSum += a[i];
    count[prefSum]++;
  }
  int ans = 0;

  map<int, int> :: iterator it;
  for(it = count.begin(); it != count.end(); it++){

    int c = it->second;

    ans += c*(c-1)/2;
    
    if(it->first == 0){
      ans += it->second;
    }
  }
  cout<< ans<< endl;
  return 0;
}

/*
input : 
4
1 -1 1 -1

output : 4
*/