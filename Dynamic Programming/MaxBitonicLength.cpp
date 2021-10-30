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
  int n = 8;
  int a[8] = {1,11,2,10,4,5,2,1};

  vi forward(n,1), backward(n,1);

  rep(i,0,n){
    rep(j,i,n){
      if(a[i] > a[j]){
        forward[i] = max(forward[i], forward[j] + 1);
      }
    }
  }

  for(int i=n-1; i>=0; i--){
    for(int j=n-1; j>i; j--){
      if(a[i] > a[j])
        backward[i] = max(backward[i], backward[j]+1);
    }
  }

  int ans = 0;
  for(int i=0; i<n; i++){
    ans = max(ans, forward[i]+backward[i]-1);
  }

  cout<< ans; endline;
  return 0;
}

// use : g++ -std=c++11 
