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
  int n; cin >> n;
  int arr[n];
  rep(i,0,n){
    cin >> arr[i];
  }

  int jumps[n];
  rep(i,0,n){
    jumps[i] = INT_MAX;
  }
  jumps[0] = 0;

  rep(i,0,n){
    rep(j,0,i){
      if( i <= (j+arr[j]) ){
        jumps[i] = min(jumps[i], jumps[j]+1);
      }
    }
  }
  cout<< jumps[n-1]; endline;
  return 0;
}

// use : g++ -std=c++11 

/*
11
1 3 5 8 9 2 6 7 6 8 9

ouput : 3
*/